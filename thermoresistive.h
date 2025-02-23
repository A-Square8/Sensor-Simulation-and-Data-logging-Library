#include <math.h>
#include <stdlib.h>

#ifndef SENSOR_H
#define SENSOR_H

// RTD constants for a typical PT100 sensor
#define RO 112.0
#define ALPHA 0.0094  

// Steinhart-Hart coefficients for a thermistor
#define A 1.009249522e-03
#define B 2.378405444e-04
#define C 2.019202697e-07

// Drift parameters
#define DRIFT_RATE 0.006  
#define SENSOR_ERROR_THERMORESSITIVE 1.0  

// Function to calculate resistance for RTD given a temperature
double cal_res_rtd(double temperature, int years) {
    double drift_factor = 1 + (DRIFT_RATE * years);
    double resistance = RO * (1 + ALPHA * temperature) * drift_factor;
    double error = ((rand() % 2001) - 1000) / 1000.0 * SENSOR_ERROR_THERMORESSITIVE;
    return resistance + error;
}

// Function to calculate resistance for a thermistor given a temperature
double cal_res_thermistor(double temperature, int years) {
    double inv_T = 1.0 / (temperature + 273.15); 
    double R = (inv_T - A) / (B + C * pow((inv_T - A), 2));
    double resistance = exp(R);

    double drift_factor = 1 + (DRIFT_RATE * years);
    double error = ((rand() % 2001) - 1000) / 1000.0 * SENSOR_ERROR_THERMORESSITIVE; 

    return resistance * drift_factor + error;
}

#endif
