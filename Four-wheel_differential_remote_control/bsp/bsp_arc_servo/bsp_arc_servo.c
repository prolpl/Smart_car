#include "bsp_arc_servo.h"
#include "math.h"

#define ARC_SERVO_FREQ_HZ		50	
#define ARC_SERVO_COUNT_MAX 	200
#define ARC_SERVO_TIM_OFFEST    -1

uint16_t	arc_servo_high_tim 	= 0;
uint16_t    arc_servo_count 	= 0;

void bsp_arc_servo_init()
{
	bsp_arc_servo_gpio_init();
}

void bsp_arc_servo_high_tim_set(uint16_t high_tim)
{
	high_tim = (uint16_t)(high_tim / 100.0f);
	if (high_tim > ARC_SERVO_COUNT_MAX + ARC_SERVO_TIM_OFFEST)
	{
		high_tim = ARC_SERVO_COUNT_MAX + ARC_SERVO_TIM_OFFEST;
	}
	
	arc_servo_high_tim = high_tim;
}

void bsp_arc_servo_pwm_run()
{
	arc_servo_count++;
	if (arc_servo_count >= ARC_SERVO_COUNT_MAX + ARC_SERVO_TIM_OFFEST)
	{
		arc_servo_count = 0;
	}
	
	if (arc_servo_count <= arc_servo_high_tim)
	{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_SET);
	}
	else
	{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_RESET);
	}
}

void bsp_arc_servo_gpio_init()
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	
    __HAL_RCC_GPIOB_CLK_ENABLE();

	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_RESET);
    GPIO_InitStruct.Pin = GPIO_PIN_12;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
}
