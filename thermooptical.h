#include <math.h>
#include <stdlib.h>

#ifndef THERMO_OPTICAL_H
#define THERMO_OPTICAL_H

// Stefan-Boltzmann constant 
#define STEFAN_BOLTZMANN 5.670e-8

// Default emissivity 
#define DEFAULT_EMISSIVITY 0.41

// Default sensor surface area (m²) 
#define DEFAULT_AREA 0.0012



// Function to calculate emitted power based on temperature
double cal_thermal_radiation(double temperature, int years, double emissivity, double area,int DRIFT_RATE,int SENSOR_ERROR_THERMOOPTICAL) {
    double temp_K = temperature + 273.15;
    double drift_factor = 1 + (DRIFT_RATE * years);
    double power = STEFAN_BOLTZMANN * emissivity * area * pow(temp_K, 4) * drift_factor;
    double error = ((rand() % 3001) - 1500) / 1000.0;  
    temp_K += error;
    power = STEFAN_BOLTZMANN * emissivity * area * pow(temp_K, 4) * drift_factor;
    return power;
}

#endif
