#ifndef SENSOR_H
#define SENSOR_H

#include "main.h"

// Duru'nun isini kolaylastirmak icin verileri tek pakette topluyoruz
typedef struct {
    uint16_t raw_value;
    float voltage;
    float percentage;
    uint8_t error_flag; // 1: Zaman asimi hatasi, 0: Basarili
} SensorData_t;

// Okuma fonksiyonunun prototipi
SensorData_t Sensor_Read(ADC_HandleTypeDef *hadc);

#endif