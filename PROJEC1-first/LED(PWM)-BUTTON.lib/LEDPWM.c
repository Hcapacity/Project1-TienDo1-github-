#include "LEDPWM.h"

void LED_init(LED_HandleTypdef* led, GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin){
	led->GPIOx = GPIOx;
	led->GPIO_Pin = GPIO_Pin;
}


void hhtim_init(htim_HandleTypdef* htim_Handle, TIM_HandleTypeDef* htimx, uint32_t Channel){
	htim_Handle->htimx = htimx;
	htim_Handle->Channel = Channel;
}


// transfer Bright Ratio to range of ARR
uint32_t Transfer_Bright_Ratio(uint8_t Bright_Ratio, uint32_t ARR){
	return (ARR + 1) * Bright_Ratio / 100;
}

// ---------------- check channel and control Bright through PWM -------------------------------------
void Bright_Handle(htim_HandleTypdef* htim_Handle, LED_HandleTypdef* ledx, uint8_t Bright_Ratio){
	HAL_TIM_PWM_Start(htim_Handle->htimx, htim_Handle->Channel);
	
	if(htim_Handle->Channel == TIM_CHANNEL_1){
     htim_Handle->htimx->Instance->CCR1 = Transfer_Bright_Ratio(Bright_Ratio, htim_Handle->htimx->Instance->ARR + 1);
     while (htim_Handle->htimx->Instance->CNT < htim_Handle->htimx->Instance->CCR1){
		   HAL_GPIO_WritePin(ledx->GPIOx, ledx->GPIO_Pin, GPIO_PIN_RESET);
	   }
     while (htim_Handle->htimx->Instance->CNT > htim_Handle->htimx->Instance->CCR1 - 1) {
		   HAL_GPIO_WritePin(ledx->GPIOx, ledx->GPIO_Pin, GPIO_PIN_SET);
     }
 }
	
	else if(htim_Handle->Channel == TIM_CHANNEL_2){
     htim_Handle->htimx->Instance->CCR2 = Transfer_Bright_Ratio(Bright_Ratio, htim_Handle->htimx->Instance->ARR + 1);
     while (htim_Handle->htimx->Instance->CNT < htim_Handle->htimx->Instance->CCR2){
		   HAL_GPIO_WritePin(ledx->GPIOx, ledx->GPIO_Pin, GPIO_PIN_RESET);
	   }
     while (htim_Handle->htimx->Instance->CNT > htim_Handle->htimx->Instance->CCR2 - 1) {
		   HAL_GPIO_WritePin(ledx->GPIOx, ledx->GPIO_Pin, GPIO_PIN_SET);
     }
 }
	
	else if(htim_Handle->Channel == TIM_CHANNEL_3){
     htim_Handle->htimx->Instance->CCR3 = Transfer_Bright_Ratio(Bright_Ratio, htim_Handle->htimx->Instance->ARR + 1);
     while (htim_Handle->htimx->Instance->CNT < htim_Handle->htimx->Instance->CCR3){
		   HAL_GPIO_WritePin(ledx->GPIOx, ledx->GPIO_Pin, GPIO_PIN_RESET);
	   }
     while (htim_Handle->htimx->Instance->CNT > htim_Handle->htimx->Instance->CCR3 - 1) {
		   HAL_GPIO_WritePin(ledx->GPIOx, ledx->GPIO_Pin, GPIO_PIN_SET);
     }
 }
	
	else if(htim_Handle->Channel == TIM_CHANNEL_4){
     htim_Handle->htimx->Instance->CCR4 = Transfer_Bright_Ratio(Bright_Ratio, htim_Handle->htimx->Instance->ARR + 1);
     while (htim_Handle->htimx->Instance->CNT < htim_Handle->htimx->Instance->CCR4){
		   HAL_GPIO_WritePin(ledx->GPIOx, ledx->GPIO_Pin, GPIO_PIN_RESET);
	   }
     while (htim_Handle->htimx->Instance->CNT > htim_Handle->htimx->Instance->CCR4 - 1) {
		   HAL_GPIO_WritePin(ledx->GPIOx, ledx->GPIO_Pin, GPIO_PIN_SET);
     }
 }
}



__weak void LED_Handle(htim_HandleTypdef* htim_Handle, LED_HandleTypdef* ledx,LED_Status LedStatus, uint8_t Bright_Ratio) {
    // do something
}

