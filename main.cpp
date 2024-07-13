#include "mbed.h"

// Comentario

// Definiciones de pines de sensores y leds
#define DHT22_PIN A0
#define SOIL_MOISTURE_PIN D2
#define RED_LED_PIN D5
#define GREEN_LED_PIN D4
#define BUZZER_PIN D3

// Inicialización de objetos
AnalogIn soilMoisture(SOIL_MOISTURE_PIN);
DigitalOut redLed(RED_LED_PIN);
DigitalOut greenLed(GREEN_LED_PIN);
DigitalOut buzzer(BUZZER_PIN);
BufferedSerial pc(USBTX, USBRX, 9600);

// Funciones para leer datos del DHT22
int readDHT22(float* temperature, float* humidity) {
    DigitalInOut dht_io(DHT22_PIN);
    dht_io.output();
    dht_io = 0;
    ThisThread::sleep_for(18ms);  // Espera por 18 ms
    dht_io = 1;
    wait_us(40);
    dht_io.input();

    // Esperar la respuesta del DHT22
    wait_us(80);
    if (dht_io == 0) wait_us(80);

    // Leer los 40 bits de datos
    uint8_t data[5] = {0, 0, 0, 0, 0};
    for (int i = 0; i < 40; i++) {
        while (dht_io == 0);
        wait_us(40);
        if (dht_io == 1) data[i / 8] |= (1 << (7 - (i % 8)));
        while (dht_io == 1);
    }

    // Calcular checksum
    if (data[4] != ((data[0] + data[1] + data[2] + data[3]) & 0xFF)) return -1;

    // Extraer temperatura y humedad
    *humidity = (data[0] << 8 | data[1]) * 0.1;
    *temperature = (data[2] << 8 | data[3]) * 0.1;

    return 0;
}

int main() {
    while (true) {
        float temperature = 0.0, humidity = 0.0;

        // Lectura del sensor DHT22
        if (readDHT22(&temperature, &humidity) != 0) {
            pc.write("Fallo en la lectura del sensor DHT22!\r\n", 32);
            continue;
        }

        // Lectura del sensor de humedad del suelo
        float soilMoistureValue = soilMoisture.read(); // Normaliza a un valor entre 0.0 y 1.0

        // Impresión en el monitor serial
        char buffer[128];
        int length = sprintf(buffer, "Temperatura: %.2f C, Humedad: %.2f %%, Humedad del suelo: %.2f\r\n", temperature, humidity, soilMoistureValue);
        pc.write(buffer, length);

        // Lógica de control de LEDs y buzzer
        if (soilMoistureValue < 0.3) { // Umbral para humedad baja
            redLed = 1;
            greenLed = 0;
            buzzer = 1;
            ThisThread::sleep_for(5s);
            buzzer = 0;
        } else {
            redLed = 0;
            greenLed = 1;
        }

        // Espera antes de la siguiente lectura
        ThisThread::sleep_for(2s);
    }
}
