#include "max6675.h"

/**
 * @brief Constructs a MAX6675 object with the specified chip select pin.
 * 
 * @param csPin The chip select pin for the SPI communication.
 */
MAX6675::MAX6675(int csPin) : _csPin(csPin) {
    pinMode(_csPin, OUTPUT);
    digitalWrite(_csPin, HIGH);
}

/**
 * @brief Reads raw data from the MAX6675 sensor.
 * 
 * @return uint16_t The raw data read from the sensor.
 */
uint16_t MAX6675::_readRawDataFromSensor() {
    SPI.beginTransaction(SPISettings(4000000, MSBFIRST, SPI_MODE0));
    digitalWrite(_csPin, LOW);
    delay(1); // Minimum 100 ns delay before first clock pulse
    uint16_t reading = SPI.transfer16(0);
    digitalWrite(_csPin, HIGH);
    SPI.endTransaction();
    return reading;
}

/**
 * @brief Reads the temperature from the MAX6675 sensor in Celsius.
 * 
 * @return float The temperature in Celsius, or NAN if the thermocouple is not connected.
 */
float MAX6675::readTemperatureInCelsius() {
    uint16_t rawData = _readRawDataFromSensor();
    if (rawData & 0x4) { // Check if thermocouple is not connected
        return NAN; // or any suitable error value
    }

    return (rawData >> 3) * 0.25;
}

/**
 * @brief Reads the temperature from the MAX6675 sensor in Fahrenheit.
 * 
 * @return float The temperature in Fahrenheit, or NAN if the thermocouple is not connected.
 */
float MAX6675::readTemperatureInFahrenheit() {
    float tempC = readTemperatureInCelsius();
    return isnan(tempC) ? NAN : tempC * 1.8 + 32.0;
}

/**
 * @brief Reads the temperature from the MAX6675 sensor in Kelvin.
 * 
 * @return float The temperature in Kelvin, or NAN if the thermocouple is not connected.
 */
float MAX6675::readTemperatureInKelvin() {
    float tempC = readTemperatureInCelsius();
    return isnan(tempC) ? NAN : tempC + 273.15;
}