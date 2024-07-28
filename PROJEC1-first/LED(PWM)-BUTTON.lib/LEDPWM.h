#ifndef LEDPWM_H
#define LEDPWM_H
#include "main.h"

typedef enum {
    LEDOFF,
    Status_1,
    Status_2
} LED_Status;

typedef struct {
	GPIO_TypeDef *GPIOx;
	uint16_t GPIO_Pin;
} LED_HandleTypdef;


typedef struct {
	TIM_HandleTypeDef* htimx;
	uint32_t Channel;
} htim_HandleTypdef;


void LED_init(LED_HandleTypdef* led, GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);
void hhtim_init(htim_HandleTypdef* htim_Handle, TIM_HandleTypeDef* htimx, uint32_t Channel);
__weak void LED_Handle(htim_HandleTypdef* htim_Handle, LED_HandleTypdef* ledx,LED_Status LedStatus, uint8_t Bright_Ratio);
void Bright_Handle(htim_HandleTypdef* htim_Handle, LED_HandleTypdef* ledx, uint8_t Bright_Ratio);
uint32_t Transfer_Bright_Ratio(uint8_t Bright_Ratio, uint32_t ARR);
__weak void BlinkLED(LED_HandleTypdef* ledx);


#endif

