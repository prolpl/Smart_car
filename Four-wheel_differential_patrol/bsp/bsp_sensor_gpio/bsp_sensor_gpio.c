#include "bsp_sensor_gpio.h"

/*
	SENSOR0		SENSOR1		SENSOR2		SENSOR3
*/

void bsp_sensor_gpio_init()
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	
	__HAL_RCC_GPIOB_CLK_ENABLE();
	/*Configure GPIO pins : PB0 PB1 PB4 PB5 */
	GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_4|GPIO_PIN_5;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_4|GPIO_PIN_5,GPIO_PIN_RESET);
}

uint8_t bsp_sensor0_get()
{
	return HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_0);
}

uint8_t bsp_sensor1_get()
{
	return HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_1);
}

uint8_t bsp_sensor2_get()
{
	return HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_4);
}

uint8_t bsp_sensor3_get()
{
	return HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_5);
}

