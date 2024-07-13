# Trabajo Práctico N°1: Sistema de Monitoreo de Temperatura y Humedad para Plantas en Maceta

## Alumna: Joanna Alexandra Carrión Pérez
## Gmail: joannacarrion14@gmail.com

### Objetivo
Desarrollar un sistema integrado para monitorear la temperatura del ambiente y la humedad del suelo de una planta en maceta, proporcionando alertas visuales y auditivas para el cuidado óptimo de la planta.

### Descripción
El sistema medirá la temperatura del ambiente utilizando un sensor **DHT22** y la humedad del suelo utilizando un sensor capacitivo de humedad del suelo **V1.2**. Además, el sistema incluirá dos LEDs y un buzzer para notificar al usuario sobre el estado de la planta:

- **LED Rojo**: Se enciende para indicar que la planta necesita riego.
- **LED Verde**: Se enciende para indicar condiciones óptimas para la planta.
- **Buzzer**: Emite un sonido durante 5 segundos cuando el LED rojo está encendido, y luego se apaga.

### Plataforma de Desarrollo
**Núcleo F411RE**

### Periféricos a Utilizar

- **Sensor de Temperatura (DHT22)**: Mide la temperatura del ambiente.
- **Sensor Capacitativo de Humedad del Suelo V1.2**: Mide la humedad del suelo.
- **LED Rojo**: Indica que es necesario regar la planta.
- **LED Verde**: Indica condiciones óptimas para la planta.
- **Buzzer**: Emite un sonido durante 5 segundos cuando el LED rojo está encendido.
- **Microcontrolador (Núcleo F411RE)**: Gestiona las lecturas de los sensores y controla las salidas (LEDs y buzzer).

### Diagrama de Bloques
![Diagrama de Bloques](/Imagen/Diagrama.png) 

### Implementación

1. **Lectura de Sensores:**
   - Configurar y leer valores del sensor **DHT22** para la temperatura.
   - Configurar y leer valores del sensor capacitivo de humedad del suelo **V1.2**.
   - Procesar los datos para determinar si las condiciones son óptimas o si se necesita riego.

2. **Indicadores Visuales y Auditivos:**
   - Encender el **LED verde** cuando las condiciones sean óptimas.
   - Encender el **LED rojo** y activar el **buzzer** durante 5 segundos cuando se detecte la necesidad de riego.

### Conexionado de Sensores Digitales y Analógicos

1. **Sensor de Temperatura (DHT22)**: El DHT22 es un sensor digital, no analógico, y se conecta de la siguiente manera:
   - **Pin VCC**: Conectar al pin de 3.3V o 5V del Núcleo F411RE.
   - **Pin GND**: Conectar al pin GND del Núcleo F411RE.
   - **Pin DATA**: Conectar al pin D2 del Núcleo F411RE (con una resistencia de pull-up de 10kΩ entre DATA y VCC).

2. **Sensor Capacitivo de Humedad del Suelo V1.2**: Este es un sensor analógico y se conecta de la siguiente manera:
   - **Pin VCC**: Conectar al pin de 3.3V del Núcleo F411RE.
   - **Pin GND**: Conectar al pin GND del Núcleo F411RE.
   - **Pin DATA**: Conectar al pin A0 del Núcleo F411RE.

### Evaluación de Niveles de Tensión

1. **Niveles de Tensión del Sensor de Humedad del Suelo**: El sensor capacitivo de humedad del suelo V1.2 mide la humedad del suelo en términos de la capacitancia del suelo y entrega una señal analógica que varía entre 0V y 3.3V. Aquí está cómo se pueden evaluar los niveles de tensión:
   - **Voltaje de salida (0V a 3.3V)**:
     - **0V**: El suelo está completamente seco.
     - **3.3V**: El suelo está completamente húmedo.
     - **Valores intermedios**: Indican distintos niveles de humedad entre seco y completamente húmedo.

2. **Uso de un Conversor Analógico a Digital (ADC)**: El pin A0 del Núcleo F411RE está conectado a un conversor analógico a digital (ADC) interno que convierte la señal analógica del sensor de humedad del suelo a un valor digital que puede ser leído por el microcontrolador.

### Referencias y Recursos
- Sensor de temperatura DHT22: https://www.adafruit.com/product/385
- Sensor capacitivo de humedad del suelo: https://wiki.dfrobot.com/Capacitive_Soil_Moisture_Sensor_SKU_SEN0193
- Microcontrolador NUCLEO-F411RE: https://os.mbed.com/platforms/ST-Nucleo-F411RE/
