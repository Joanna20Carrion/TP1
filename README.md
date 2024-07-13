# Trabajo Práctico N°1: Sistema de Monitoreo de Temperatura y Humedad para Plantas en Maceta

## Alumna: Joanna Alexandra Carrión Pérez

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
