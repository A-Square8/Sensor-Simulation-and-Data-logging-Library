#ifndef PHOTOELECTRIC_SENSOR_H
#define PHOTOELECTRIC_SENSOR_H
#include <math.h>
#define ELECTRON_CHARGE 1.6e-19
// Function to compute photocurrent based on photon flux
static inline double compute_photoelectric_current_flux(double photon_flux, 
double quantum_efficiency) {
 return photon_flux * quantum_efficiency * ELECTRON_CHARGE;
}
// Function to compute photocurrent based on optical power
static inline double compute_photoelectric_current_power(double
optical_power, double quantum_efficiency, double responsivity) {
 return optical_power * quantum_efficiency * responsivity;
}
// Function to compute sensitivity
static inline double compute_sensitivity(double photocurrent, double
optical_power) {
 return photocurrent / optical_power;
}
// Function to compute resolution
static inline double compute_resolution(double sensitivity) {
 return 1.0 / sensitivity;
}
// Function to compute signal-to-noise ratio (SNR)
static inline double compute_snr(double photocurrent, double noise_current)
{
 return 20 * log10(photocurrent / noise_current);
}
#endif // PHOTOELECTRIC_SENSOR_H