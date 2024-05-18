#include "bsp_motor.h"
#include "math.h"
/*     
	   motor4(out3)   *********   motor3(out4)
		  *                           *
		  *                           *
		  *                           *
		  *						      *
       motor1(out1)   *********   motor2(out2)
*/

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

TIM_HandleTypeDef htim2;
TIM_HandleTypeDef htim4;

/***************** BSP 电机初始化***********************/
void bsp_motor_init()
{
	bsp_motor_gpio_init();
	
	bsp_motor_tim_init();
}
/***************** BSP 电机初始化***********************/

/***************** BSP 左电机占空比设置*****************
pwm: 占空比设置 范围 -100 —— 100  
*******************************************************/
void bsp_motor1_pwm_set(int8_t pwm)
{ 
	pwm = (pwm >  100)? 100 : (pwm < -100)? -100 : pwm;  
	
	TIM_OC_InitTypeDef sConfigOC = {0};
	uint32_t period = htim2.Init.Period;  
	
	sConfigOC.OCMode = TIM_OCMODE_PWM1;
	sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
	sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
	if(pwm	< 0)
	{
		sConfigOC.Pulse =(int)(fabs(pwm)/100.0f * period);	
	
		HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_2);
		TIM_CHANNEL_STATE_SET(&htim2, TIM_CHANNEL_2, HAL_TIM_CHANNEL_STATE_READY);
		HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_2); 		
		
		sConfigOC.Pulse = 0;
		HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_1);
		TIM_CHANNEL_STATE_SET(&htim2, TIM_CHANNEL_1, HAL_TIM_CHANNEL_STATE_READY);
		HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1); 
	}
	else if (pwm >= 0)
	{
		sConfigOC.Pulse = (int)(pwm / 100.0f * period);	
	
		HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_1);
		TIM_CHANNEL_STATE_SET(&htim2, TIM_CHANNEL_1, HAL_TIM_CHANNEL_STATE_READY);
		HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1); 
		
		sConfigOC.Pulse = 0;
		HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_2);
		TIM_CHANNEL_STATE_SET(&htim2, TIM_CHANNEL_2, HAL_TIM_CHANNEL_STATE_READY);
		HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_2); 
	}
}

void bsp_motor2_pwm_set(int8_t pwm)
{ 
	pwm = (pwm >  100)? 100 : (pwm < -100)? -100 : pwm;  
	
	TIM_OC_InitTypeDef sConfigOC = {0};
	uint32_t period = htim2.Init.Period;  
	
	sConfigOC.OCMode = TIM_OCMODE_PWM1;
	sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
	sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
	if(pwm	< 0)
	{
		sConfigOC.Pulse =(int)(fabs(pwm)/100.0f * period);
		HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_4);
		TIM_CHANNEL_STATE_SET(&htim2, TIM_CHANNEL_4, HAL_TIM_CHANNEL_STATE_READY);
		HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_4); 
		
		sConfigOC.Pulse =0;	
		HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_3);
		TIM_CHANNEL_STATE_SET(&htim2, TIM_CHANNEL_3, HAL_TIM_CHANNEL_STATE_READY);
		HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_3); 		
	}
	else if(pwm	>= 0)
	{
		sConfigOC.Pulse = (int)(pwm / 100.0f * period);	
		
		HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_3);
		TIM_CHANNEL_STATE_SET(&htim2, TIM_CHANNEL_3, HAL_TIM_CHANNEL_STATE_READY);
		HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_3); 
		
		sConfigOC.Pulse =0;	
		HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_4);
		TIM_CHANNEL_STATE_SET(&htim2, TIM_CHANNEL_4, HAL_TIM_CHANNEL_STATE_READY);
		HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_4); 		
	}
}

int32_t pwm_test = 0;
void bsp_motor3_pwm_set(int8_t pwm)
{ 
	pwm = (pwm >  100)? 100 : (pwm < -100)? -100 : pwm;  
	
	TIM_OC_InitTypeDef sConfigOC = {0};
	uint32_t period = htim4.Init.Period;  
	
	sConfigOC.OCMode = TIM_OCMODE_PWM1;
	sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
	sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
	if(pwm	< 0)
	{
		sConfigOC.Pulse =(int)(fabs(pwm)/100.0f * period);		
		HAL_TIM_PWM_ConfigChannel(&htim4, &sConfigOC, TIM_CHANNEL_2);
		TIM_CHANNEL_STATE_SET(&htim4, TIM_CHANNEL_2, HAL_TIM_CHANNEL_STATE_READY);
		HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_2); 
			
		sConfigOC.Pulse = 0;
		HAL_TIM_PWM_ConfigChannel(&htim4, &sConfigOC, TIM_CHANNEL_1);
		TIM_CHANNEL_STATE_SET(&htim4, TIM_CHANNEL_1, HAL_TIM_CHANNEL_STATE_READY);
		HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_1); 
	}
	else if (pwm >= 0)
	{
		sConfigOC.Pulse = (int)(pwm / 100.0f * period);	
		HAL_TIM_PWM_ConfigChannel(&htim4, &sConfigOC, TIM_CHANNEL_1);
		TIM_CHANNEL_STATE_SET(&htim4, TIM_CHANNEL_1, HAL_TIM_CHANNEL_STATE_READY);
		HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_1); 
		
		sConfigOC.Pulse = 0;
		HAL_TIM_PWM_ConfigChannel(&htim4, &sConfigOC, TIM_CHANNEL_2);
		TIM_CHANNEL_STATE_SET(&htim4, TIM_CHANNEL_2, HAL_TIM_CHANNEL_STATE_READY);
		HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_2); 
	}
}

void bsp_motor4_pwm_set(int8_t pwm)
{ 
	pwm = (pwm >  100)? 100 : (pwm < -100)? -100 : pwm;  
	
	TIM_OC_InitTypeDef sConfigOC = {0};
	uint32_t period = htim4.Init.Period;  
	
	sConfigOC.OCMode = TIM_OCMODE_PWM1;
	sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
	sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
	if(pwm	< 0)
	{
		sConfigOC.Pulse =(int)(fabs(pwm)/100.0f * period);		
		HAL_TIM_PWM_ConfigChannel(&htim4, &sConfigOC, TIM_CHANNEL_3);
		TIM_CHANNEL_STATE_SET(&htim4, TIM_CHANNEL_3, HAL_TIM_CHANNEL_STATE_READY);	
		HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_3); 
		
		sConfigOC.Pulse =0;	
		HAL_TIM_PWM_ConfigChannel(&htim4, &sConfigOC, TIM_CHANNEL_4);
		TIM_CHANNEL_STATE_SET(&htim4, TIM_CHANNEL_4, HAL_TIM_CHANNEL_STATE_READY);
		HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_4); 
	}
	else if (pwm >= 0)
	{
		sConfigOC.Pulse = (int)(pwm / 100.0f * period);	
		HAL_TIM_PWM_ConfigChannel(&htim4, &sConfigOC, TIM_CHANNEL_4);
		TIM_CHANNEL_STATE_SET(&htim4, TIM_CHANNEL_4, HAL_TIM_CHANNEL_STATE_READY);		
		HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_4); 
		
		sConfigOC.Pulse =0;	
		HAL_TIM_PWM_ConfigChannel(&htim4, &sConfigOC, TIM_CHANNEL_3);
		TIM_CHANNEL_STATE_SET(&htim4, TIM_CHANNEL_3, HAL_TIM_CHANNEL_STATE_READY);
		HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_3); 
	}
}
/***************** BSP 左电机占空比设置*****************/

/***************** BSP 右电机占空比设置*****************/

/***************** BSP 电机GPIO口初始化*****************/
void bsp_motor_gpio_init()
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	
    __HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();
	
    /**TIM2 GPIO Configuration
    PA0-WKUP     ------> TIM2_CH1
    PA1     ------> TIM2_CH2
    PA2     ------> TIM2_CH3
    PA3     ------> TIM2_CH4
    */

    GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);


    /**TIM4 GPIO Configuration
    PB6     ------> TIM4_CH1
    PB7     ------> TIM4_CH2
    PB8     ------> TIM4_CH3
    PB9     ------> TIM4_CH4
    */
    GPIO_InitStruct.Pin = GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}
/***************** BSP 电机GPIO口初始化*****************/

/***************** BSP 电机PWM输出TIM初始化*************/
void bsp_motor_tim_init()
{
	//tim2_init
	TIM_ClockConfigTypeDef sClockSourceConfig = {0};
	TIM_MasterConfigTypeDef sMasterConfig = {0};
	TIM_OC_InitTypeDef sConfigOC = {0};

	htim2.Instance = TIM2;
	htim2.Init.Prescaler = 71;
	htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
	htim2.Init.Period = 6999;
	htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
	if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
	{
		Error_Handler();
	}
	sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
	if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
	{
		Error_Handler();
	}
	if (HAL_TIM_PWM_Init(&htim2) != HAL_OK)
	{
		Error_Handler();
	}
	sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
	sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
	if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
	{
		Error_Handler();
	}
	sConfigOC.OCMode = TIM_OCMODE_PWM1;
	sConfigOC.Pulse = 0;
	sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
	sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
	if (HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
	{
		Error_Handler();
	}
	if (HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_2) != HAL_OK)
	{
		Error_Handler();
	}
	if (HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_3) != HAL_OK)
	{
		Error_Handler();
	}
	if (HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_4) != HAL_OK)
	{
		Error_Handler();
	}

	htim4.Instance = TIM4;
	htim4.Init.Prescaler = 71;
	htim4.Init.CounterMode = TIM_COUNTERMODE_UP;
	htim4.Init.Period = 6999;
	htim4.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	htim4.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
	if (HAL_TIM_Base_Init(&htim4) != HAL_OK)
	{
		Error_Handler();
	}
	sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
	if (HAL_TIM_ConfigClockSource(&htim4, &sClockSourceConfig) != HAL_OK)
	{
		Error_Handler();
	}
	if (HAL_TIM_PWM_Init(&htim4) != HAL_OK)
	{
		Error_Handler();
	}
	sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
	sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
	if (HAL_TIMEx_MasterConfigSynchronization(&htim4, &sMasterConfig) != HAL_OK)
	{
		Error_Handler();
	}
	sConfigOC.OCMode = TIM_OCMODE_PWM1;
	sConfigOC.Pulse = 0;
	sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
	sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
	if (HAL_TIM_PWM_ConfigChannel(&htim4, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
	{
		Error_Handler();
	}
	if (HAL_TIM_PWM_ConfigChannel(&htim4, &sConfigOC, TIM_CHANNEL_2) != HAL_OK)
	{
		Error_Handler();
	}
	if (HAL_TIM_PWM_ConfigChannel(&htim4, &sConfigOC, TIM_CHANNEL_3) != HAL_OK)
	{
		Error_Handler();
	}
	if (HAL_TIM_PWM_ConfigChannel(&htim4, &sConfigOC, TIM_CHANNEL_4) != HAL_OK)
	{
		Error_Handler();
	}
}
/***************** BSP 电机PWM输出TIM初始化*************/
