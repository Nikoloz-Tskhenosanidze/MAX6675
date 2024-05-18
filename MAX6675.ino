#include <SPI.h>
#include "max6675.h"

const int csPin = 10; // Choose your chip select pin

MAX6675 thermocouple(csPin);

void setup() {
    Serial.begin(115200);
}

void loop() {
    float temperatureC = thermocouple.readTemperatureInCelsius();
    float temperatureF = thermocouple.readTemperatureInFahrenheit();
    float temperatureK = thermocouple.readTemperatureInKelvin();

    if (!isnan(temperatureC)) {
        Serial.print("Temperature: ");
        Serial.print(temperatureC);
        Serial.print(" °C, ");
        Serial.print(temperatureF);
        Serial.print(" °F, ");
        Serial.print(temperatureK);
        Serial.println(" K");
    } else {
        Serial.println("Error: Thermocouple not connected.");
    }
    delay(1000);
}