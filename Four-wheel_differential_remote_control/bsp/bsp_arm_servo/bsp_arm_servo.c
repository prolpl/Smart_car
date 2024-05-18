#include "bsp_arm_servo.h"
#include "math.h"

#define ARM_SERVO_FREQ_HZ		50	
#define ARM_SERVO_COUNT_MAX 	200
#define ARM_SERVO_TIM_OFFEST    0

uint16_t	arm_left_high_tim 	= 0;
uint16_t	arm_right_high_tim 	= 0;
uint16_t	arm_up_high_tim 	= 0;
uint16_t    arm_irq_count 		= 0;
uint16_t    arm_irq_last_count  = 0;

/***************** SERVO 初始化**********************/
void bsp_arm_servo_init()
{
	bsp_arm_servo_gpio_init();
}
/***************** SERVO 初始化**********************/

/***************** SERVO占空比设置*******************/
void bsp_arm_left_high_tim_set(uint16_t high_tim)
{
	high_tim = (uint16_t)(high_tim / 100.0f);
	if (high_tim > ARM_SERVO_COUNT_MAX + ARM_SERVO_TIM_OFFEST)
	{
		high_tim = ARM_SERVO_COUNT_MAX + ARM_SERVO_TIM_OFFEST;
	}
	
	arm_left_high_tim = high_tim;
}

void bsp_arm_right_high_tim_set(uint16_t high_tim)
{
	high_tim = (uint16_t)(high_tim / 100.0f);
	if (high_tim > ARM_SERVO_COUNT_MAX + ARM_SERVO_TIM_OFFEST)
	{
		high_tim = ARM_SERVO_COUNT_MAX + ARM_SERVO_TIM_OFFEST;
	}
	
	arm_right_high_tim = high_tim;
}

void bsp_arm_up_high_tim_set(uint16_t high_tim)
{
	high_tim = (uint16_t)(high_tim / 100.0f);
	if (high_tim > ARM_SERVO_COUNT_MAX + ARM_SERVO_TIM_OFFEST)
	{
		high_tim = ARM_SERVO_COUNT_MAX + ARM_SERVO_TIM_OFFEST;
	}
	
	arm_up_high_tim = high_tim;
}
/***************** SERVO占空比设置********************/
void bsp_arm_servo_pwm_run()
{
    arm_irq_count++;
    if (arm_irq_count >= ARM_SERVO_COUNT_MAX + ARM_SERVO_TIM_OFFEST)
    {
        arm_irq_count = 0;
    }
    
    if (arm_irq_count <= arm_left_high_tim)
    {
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_SET);
    }
    else
    {
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_RESET);
    }	

    if (arm_irq_count <= arm_right_high_tim)
    {
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_SET);
    }
    else
    {
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET);
    }
    
    if (arm_irq_count <= arm_up_high_tim)
    {
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_SET);
    }
    else
    {
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_RESET);
    }
}

/***************** SERVO GPIO口初始化*****************/
void bsp_arm_servo_gpio_init()
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	
    __HAL_RCC_GPIOB_CLK_ENABLE();
    /**TIM1 GPIO Configuration
    PB13     ------> arm_left
    PB14     ------> arm_right
    PB15     ------> arm_up
    */
    GPIO_InitStruct.Pin = GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
}
/***************** SERVO GPIO口初始化*****************/

