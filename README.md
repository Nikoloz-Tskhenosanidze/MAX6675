# MAX6675 Temperature Sensor Library

This library provides an interface for the MAX6675 thermocouple temperature sensor using the SPI protocol on Arduino. It allows you to read the temperature in Celsius, Fahrenheit, and Kelvin.

## Files

- `max6675.h`: Header file for the MAX6675 class.
- `max6675.cpp`: Source file for the MAX6675 class.

## Installation

1. Download the library files and place them in a folder named `MAX6675` in your Arduino libraries directory (usually located in `~/Documents/Arduino/libraries` on Windows/Mac or `~/Arduino/libraries` on Linux).

2. Include the library in your Arduino sketch:

    ```cpp
    #include <SPI.h>
    #include "max6675.h"
    ```

## Usage

### Initialization

To use the MAX6675 sensor, create an instance of the `MAX6675` class and specify the chip select (CS) pin:

```cpp
const int csPin = 10; // Replace with your CS pin
MAX6675 thermocouple(csPin);
```

### Reading Temperature

You can read the temperature in Celsius, Fahrenheit, and Kelvin using the following methods:

- **Celsius:**

    ```cpp
    float temperatureC = thermocouple.readTemperatureInCelsius();
    ```

- **Fahrenheit:**

    ```cpp
    float temperatureF = thermocouple.readTemperatureInFahrenheit();
    ```

- **Kelvin:**

    ```cpp
    float temperatureK = thermocouple.readTemperatureInKelvin();
    ```

### Example Sketch

Here is an example Arduino sketch that reads and prints the temperature from the MAX6675 sensor in all three units:

```cpp
#include <SPI.h>
#include "max6675.h"

const int csPin = 10; // Replace with your CS pin

MAX6675 thermocouple(csPin);

void setup() {
    Serial.begin(9600);
}

void loop() {
    float tempC = thermocouple.readTemperatureInCelsius();
    float tempF = thermocouple.readTemperatureInFahrenheit();
    float tempK = thermocouple.readTemperatureInKelvin();

    if (!isnan(tempC)) {
        Serial.print("Temperature: ");
        Serial.print(tempC);
        Serial.print(" °C, ");
        Serial.print(tempF);
        Serial.print(" °F, ");
        Serial.print(tempK);
        Serial.println(" K");
    } else {
        Serial.println("Error: Thermocouple not connected.");
    }

    delay(1000);
}
```

## API Reference

### MAX6675 Class

#### Constructor

- **MAX6675(int csPin)**: Creates an instance of the MAX6675 class with the specified chip select pin.

#### Methods

- **float readTemperatureInCelsius()**: Reads the temperature in Celsius. Returns `NAN` if the thermocouple is not connected.
- **float readTemperatureInFahrenheit()**: Reads the temperature in Fahrenheit. Returns `NAN` if the thermocouple is not connected.
- **float readTemperatureInKelvin()**: Reads the temperature in Kelvin. Returns `NAN` if the thermocouple is not connected.

## Authors

- Nikoloz Tskhenosanidze - Initial work

Feel free to contribute to this library by submitting issues and pull requests on GitHub.
```

This README file includes installation instructions, usage examples, an API reference, and basic information about the library. Replace `Nikoloz Tskhenosanidze` with your actual name if you plan to distribute this library.
