#include "uart_log.h"
#include <stdio.h>
#include <string.h>

void UART_Print(UART_HandleTypeDef *huart, const char *msg) {
    // Mesaji byte dizisi olarak yolla, MAX_DELAY ile bekle
    HAL_UART_Transmit(huart, (uint8_t*)msg, strlen(msg), HAL_MAX_DELAY);
}

void UART_PrintFloat(UART_HandleTypeDef *huart, const char *label, float val, uint8_t decimals) {
    char buffer[64];
    
    // Ondalik hassasiyetine gore formatlama
    if (decimals == 2) {
        sprintf(buffer, "%s: %.2f\r\n", label, val);
    } else if (decimals == 1) {
        sprintf(buffer, "%s: %.1f\r\n", label, val);
    } else {
        sprintf(buffer, "%s: %f\r\n", label, val);
    }
    
    UART_Print(huart, buffer);
}