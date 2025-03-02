#ifndef CCD_SENSOR_H
#define CCD_SENSOR_H
#include <math.h>
#define PLANCK_CONSTANT 6.626e-34
#define SPEED_OF_LIGHT 3.0e8
// Function to compute CCD output voltage
static inline double compute_ccd_output_voltage(double num_electrons, 
double capacitance) {
 return num_electrons / capacitance;
}
// Function to compute quantum efficiency
static inline double compute_ccd_qe(double num_electrons, double
photon_flux) {
 return num_electrons / photon_flux;
}
// Function to compute CCD dynamic range
static inline double compute_ccd_dynamic_range(double max_electrons, double
min_electrons) {
 return 20 * log10(max_electrons / min_electrons);
}
// Function to compute CCD sensitivity based on photon energy
static inline double compute_ccd_sensitivity_photon(double
quantum_efficiency, double wavelength) {
 return quantum_efficiency * (PLANCK_CONSTANT * SPEED_OF_LIGHT / 
wavelength);
}
// Function to compute CCD sensitivity based on power
static inline double compute_ccd_sensitivity_power(double
quantum_efficiency, double responsivity) {
 return quantum_efficiency * responsivity;
}
// Function to compute CCD sensitivity based on voltage
static inline double compute_ccd_sensitivity_voltage(double output_voltage, 
double optical_power) {
 return output_voltage / optical_power;
}
// Function to compute CCD resolution
static inline double compute_ccd_resolution(double sensitivity) {
 return 1.0 / sensitivity;
}
#endif // CCD_SENSOR_H
