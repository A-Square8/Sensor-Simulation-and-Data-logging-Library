# Multi-Sensor Library

A comprehensive library for interfacing with various sensors in embedded systems.

## Features

- Support for multiple sensor types:
  - **Temperature Sensors**
    - Thermo-optical
    - Thermoresistive (RTD and Thermistor)
    - Thermoacoustic
    - Thermoelectric
- Easy-to-use API for each sensor type
- Drift and error simulation for realistic sensor behavior
- Customizable parameters for each sensor

## Installation

1. Download the library files.
2. Include the desired sensor header files in your project.
3. Link against the library in your build system.

## Usage

```c
#include "thermooptical.h"

// Create a thermo-optical sensor instance
double temperature = 25.0;
int years = 2;
double emissivity = DEFAULT_EMISSIVITY;
double area = DEFAULT_AREA;
int drift_rate = 1;
int sensor_error = 2;

double power = cal_thermal_radiation(temperature, years, emissivity, area, drift_rate, sensor_error);
printf("Emitted power: %.6f W\n", power);
```

## API Reference

Refer to individual header files for detailed API documentation.

## Contributing

Please read `CONTRIBUTING.md` for details on our code of conduct and the process for submitting pull requests.

## License

This project is licensed under the MIT License - see the `LICENSE.md` file for details.

