#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include "thermooptical.h"
#include "thermoresistive.h"
#include "thermoacoustic.h"
#include "thermoelectric.h"
#include "afir_sensor.h"
#include "ccd_sensor.h"
#include "photoelectric_sensor.h"

#define MAX_INPUTS 100

void create_csv_header(const char* sensor_type) {
    char filename[50];
    sprintf(filename, "%s.csv", sensor_type);
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        file = fopen(filename, "w");
        if (file == NULL) {
            printf("Error creating file %s\n", filename);
            return;
        }
        fprintf(file, "SNO,Input,Output,Timestamp\n");
    }
    fclose(file);
}

void log_to_csv(const char* sensor_type, int id, double input, double output) {
    create_csv_header(sensor_type);
    char filename[50];
    sprintf(filename, "%s.csv", sensor_type);
    FILE* file = fopen(filename, "a");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return;
    }
    time_t now = time(NULL);
    struct tm* t = localtime(&now);
    fprintf(file, "%d,%f,%f,%04d-%02d-%02d %02d:%02d:%02d\n", 
            id, input, output, 
            t->tm_year + 1900, t->tm_mon + 1, t->tm_mday, 
            t->tm_hour, t->tm_min, t->tm_sec);
    fclose(file);
}

int main() {
    int choice, num_inputs, years, drift_rate, sensor_error;
    double inputs[MAX_INPUTS], outputs[MAX_INPUTS];
    
    while (1) {
        printf("\nThermal Sensor Simulator\n");
        printf("1. Thermo-optical Sensor\n");
        printf("2. Thermoresistive Sensor (RTD)\n");
        printf("3. Thermoresistive Sensor (Thermistor)\n");
        printf("4. Thermoacoustic Sensor\n");
        printf("5. Thermoelectric Sensor\n");
        printf("6. AFIR Sensor\n");
        printf("7. CCD Sensor\n");
        printf("8. Photoelectric Sensor\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 9) break;

        printf("Enter number of inputs: ");
        scanf("%d", &num_inputs);
        if (num_inputs > MAX_INPUTS) {
            printf("Error: Maximum %d inputs allowed.\n", MAX_INPUTS);
            continue;
        }

        for (int i = 0; i < num_inputs; i++) {
            printf("Enter input %d: ", i + 1);
            scanf("%lf", &inputs[i]);
        }

        switch (choice) {
            // ... (previous cases remain unchanged)

            case 6: {
                double absorption_coefficient, distance;
                printf("Enter absorption coefficient: ");
                scanf("%lf", &absorption_coefficient);
                printf("Enter distance: ");
                scanf("%lf", &distance);
                for (int i = 0; i < num_inputs; i++) {
                    outputs[i] = compute_afir_power_output(inputs[i], absorption_coefficient, distance);
                    log_to_csv("afir_sensor", i + 1, inputs[i], outputs[i]);
                    printf("Input Power: %.2f W, Output Power: %.6f W\n", inputs[i], outputs[i]);
                }
                break;
            }
            case 7: {
                double capacitance;
                printf("Enter capacitance: ");
                scanf("%lf", &capacitance);
                for (int i = 0; i < num_inputs; i++) {
                    outputs[i] = compute_ccd_output_voltage(inputs[i], capacitance);
                    log_to_csv("ccd_sensor", i + 1, inputs[i], outputs[i]);
                    printf("Number of electrons: %.2f, Output Voltage: %.6f V\n", inputs[i], outputs[i]);
                }
                break;
            }
            case 8: {
                double quantum_efficiency;
                printf("Enter quantum efficiency: ");
                scanf("%lf", &quantum_efficiency);
                for (int i = 0; i < num_inputs; i++) {
                    outputs[i] = compute_photoelectric_current_flux(inputs[i], quantum_efficiency);
                    log_to_csv("photoelectric_sensor", i + 1, inputs[i], outputs[i]);
                    printf("Photon flux: %.2f photons/s, Photocurrent: %.6f A\n", inputs[i], outputs[i]);
                }
                break;
            }
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    printf("Thank you for using the Sensor Simulator!\n");
    return 0;
}
