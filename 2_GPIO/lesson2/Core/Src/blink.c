#include "gpio.h"
#include "main.h"
//void init_led(GPIO_TypeDef *port, uint16_t pin) {
//	GPIO_InitTypeDef GPIO_InitStruct = { 0 };
//
//	/* GPIO Ports Clock Enable */
//	__HAL_RCC_GPIOE_CLK_ENABLE();
//	__HAL_RCC_GPIOH_CLK_ENABLE();
//	__HAL_RCC_GPIOA_CLK_ENABLE();
//	__HAL_RCC_GPIOC_CLK_ENABLE();
//
//	HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_RESET);
//	GPIO_InitStruct.Pin = LED_Pin;
//	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
//	GPIO_InitStruct.Pull = GPIO_NOPULL;
//	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
//	HAL_GPIO_Init(LED_GPIO_Port, &GPIO_InitStruct);

void blink(void) {
	HAL_GPIO_TogglePin(LED_GPIO_Port, LED_GPIO_Port);
	HAL_Delay(300);
	HAL_GPIO_TogglePin(LED_GPIO_Port, LED_GPIO_Port);
	HAL_Delay(300);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {

	static uint16_t counter = 0;
	counter++;
	blink();
}
