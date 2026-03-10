#include "sensor.h"

SensorData_t Sensor_Read(ADC_HandleTypeDef *hadc) {
    SensorData_t data = {0, 0.0f, 0.0f, 1}; // Varsayilan olarak hata(1) durumunda baslat

    HAL_ADC_Start(hadc); // ADC okumasini baslat
    
    // 100 ms zaman asimi (timeout) kontrolu
    if (HAL_ADC_PollForConversion(hadc, 100) == HAL_OK) {
        data.raw_value = HAL_ADC_GetValue(hadc);
        
        // Matematiksel donusumler
        data.voltage = (data.raw_value / 4095.0f) * 3.3f;
        data.percentage = (data.raw_value / 4095.0f) * 100.0f;
        
        data.error_flag = 0; // Basarili, hatayi kaldir
    }
    
    HAL_ADC_Stop(hadc); // ADC'yi durdur
    
    return data;
}