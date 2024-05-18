#ifndef MAX6675_H
#define MAX6675_H

#include <Arduino.h>
#include "SPI.h"

class MAX6675 {
private:
    uint16_t _readRawDataFromSensor();
    int _csPin;

public:
    MAX6675(int csPin);

    float readTemperatureInCelsius();
    float readTemperatureInFahrenheit();
    float readTemperatureInKelvin();
};

#endif