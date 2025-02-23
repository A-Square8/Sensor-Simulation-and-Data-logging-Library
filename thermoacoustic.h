#include <math.h>
#include <stdlib.h>

#ifndef THERMO_ACOUSTIC_H
#define THERMO_ACOUSTIC_H

// Speed of sound constants
#define BASE_SPEED 331.3  
#define TEMP_COEFF 0.514  

// Drift parameters
#define DRIFT_RATE 0.006  
#define SENSOR_ERROR_THERMOACOUSTIC 2.0  

// Function to calculate speed of sound based on temperature
double cal_sound_speed(double temperature, int years) {
    double drift_factor = 1 + (DRIFT_RATE * years);
    double speed = (BASE_SPEED + TEMP_COEFF * temperature) * drift_factor;
    double error = ((rand() % 4001) - 2000) / 1000.0;  
    speed = (BASE_SPEED + TEMP_COEFF * (temperature + error)) * drift_factor;
    return speed;
}

#endif
