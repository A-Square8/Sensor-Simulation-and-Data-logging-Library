#include <math.h>
#include <stdlib.h>

#ifndef THERMOELECTRIC_H
#define THERMOELECTRIC_H

// Seebeck Coefficient 
#define SEEBECK_COEFF 0.064  


// Function to calculate thermoelectric voltage
double cal_thermoelectric_voltage(double hot_temp, double cold_temp, int years,int DRIFT_RATE,int  SENSOR_ERROR_THERMOELECTRIC ) {
    double delta_T = hot_temp - cold_temp;

    // Apply drift over time
    double drift_factor = 1 + (DRIFT_RATE * years);
    double voltage = SEEBECK_COEFF * delta_T * drift_factor;

    // Apply random noise (±2.5°C)
    double error = ((rand() % 5001) - 2500) / 1000.0;  
    voltage += SEEBECK_COEFF * error;

    return voltage; 
}

#endif
