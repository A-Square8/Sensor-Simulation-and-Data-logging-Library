#ifndef AFIR_SENSOR_H
#define AFIR_SENSOR_H
#include <math.h>
// Function to compute AFIR power output
static inline double compute_afir_power_output(double input_power, double
absorption_coefficient, double distance) {
 return input_power * exp(-absorption_coefficient * distance);
}
// Function to detect an object based on threshold power
static inline int detect_object(double threshold_power, double
received_power) {
 return received_power >= threshold_power ? 1 : 0;
}
// Function to compute AFIR sensitivity
static inline double compute_afir_sensitivity(double delta_power, double
delta_distance) {
 return delta_power / delta_distance;
}
// Function to compute AFIR resolution
static inline double compute_afir_resolution(double sensitivity) {
 return 1.0 / sensitivity;
}
#endif // AFIR_SENSOR_H
