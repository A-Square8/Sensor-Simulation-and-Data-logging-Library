#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "thermoresistive.h"
#include "thermoacoustic.h"
#include "thermoelectric.h"
#include "thermooptical.h"

#define NUM_READINGS 1150

void operation(double temperature, char *status) {
    if (temperature > 35) {
        strcpy(status, "Fan On");
    } else if (temperature < 6) {
        strcpy(status, "Heater On");
    } else {
        strcpy(status, "Stable");
    }
}

int main() {
    int choice, years;
    double temperature, sensor_value;
    char filename[50], status[20];
    FILE *logfile;
    
    srand(time(NULL));
    
    while (1) {
        printf("ANKIT AMBASTA 22BCT0041\n");
        printf("Select Sensor Type:\n");
        printf("1. Thermoresistive (RTD/Thermistor)\n");
        printf("2. Thermoelectric (Thermocouple)\n");
        printf("3. Thermo-Optical (Infrared Sensor)\n");
        printf("4. Thermo-Acoustic (Ultrasonic-based)\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        if (choice == 5) {
            printf("Exiting program...\n");
            break;
        }
        
        printf("Enter years of operation: ");
        scanf("%d", &years);
        
        switch (choice) {
            case 1:
                snprintf(filename, sizeof(filename), "thermoresistive_log.csv");
                logfile = fopen(filename, "w");
                fprintf(logfile, "Sensor ID, Temperature, Resistance, Status\n");
                for (int i = 0; i < NUM_READINGS; i++) {
                    temperature = (rand() % 6001) / 100.0;
                    sensor_value = cal_res_rtd(temperature, years);
                    operation(temperature, status);
                    fprintf(logfile, "RTD_%d, %.2f, %.6f, %s\n", i + 1, temperature, sensor_value, status);
                }
                fclose(logfile);
                break;
            case 2:
                snprintf(filename, sizeof(filename), "thermoelectric_log.csv");
                logfile = fopen(filename, "w");
                fprintf(logfile, "Sensor ID, Temperature, Voltage, Status\n");
                for (int i = 0; i < NUM_READINGS; i++) {
                    temperature = (rand() % 6001) / 100.0;
                    sensor_value = cal_thermoelectric_voltage(temperature, temperature - 10, years);
                    operation(temperature, status);
                    fprintf(logfile, "TC_%d, %.2f, %.6f, %s\n", i + 1, temperature, sensor_value, status);
                }
                fclose(logfile);
                break;
            case 3:
                snprintf(filename, sizeof(filename), "thermo_optical_log.csv");
                logfile = fopen(filename, "w");
                fprintf(logfile, "Sensor ID, Temperature, Power, Status\n");
                for (int i = 0; i < NUM_READINGS; i++) {
                    temperature = (rand() % 6001) / 100.0;
                    sensor_value = cal_thermal_radiation(temperature, years, DEFAULT_EMISSIVITY, DEFAULT_AREA);
                    operation(temperature, status);
                    fprintf(logfile, "IR_%d, %.2f, %.6f, %s\n", i + 1, temperature, sensor_value, status);
                }
                fclose(logfile);
                break;
            case 4:
                snprintf(filename, sizeof(filename), "thermo_acoustic_log.csv");
                logfile = fopen(filename, "w");
                fprintf(logfile, "Sensor ID, Temperature, Speed, Status\n");
                for (int i = 0; i < NUM_READINGS; i++) {
                    temperature = (rand() % 6001) / 100.0;
                    sensor_value = cal_sound_speed(temperature, years);
                    operation(temperature, status);
                    fprintf(logfile, "UA_%d, %.2f, %.6f, %s\n", i + 1, temperature, sensor_value, status);
                }
                fclose(logfile);
                break;
            default:
                printf("Invalid choice!\n");
                continue;
        }
        printf("Sensor data successfully logged in %s\n\n", filename);
    }
    return 0;
}
