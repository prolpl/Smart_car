#include "bsp_board_tim.h"
#include "math.h"

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

TIM_HandleTypeDef htim3;

void bsp_board_tim_init()
{
	TIM_ClockConfigTypeDef sClockSourceConfig = {0};
	TIM_MasterConfigTypeDef sMasterConfig = {0};

	htim3.Instance = TIM3;
	htim3.Init.Prescaler = 71;
	htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
	htim3.Init.Period = 99;
	htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	htim3.Init.RepetitionCounter = 0;
	htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
	if (HAL_TIM_Base_Init(&htim3) != HAL_OK)
	{
		Error_Handler();
	}
	sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
	if (HAL_TIM_ConfigClockSource(&htim3, &sClockSourceConfig) != HAL_OK)
	{
		Error_Handler();
	}
	sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
	sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
	if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig) != HAL_OK)
	{
		Error_Handler();
	}
	
	HAL_TIM_Base_Start_IT(&htim3);
}

void bsp_board_tim_enable()
{
	HAL_TIM_Base_Start_IT(&htim3);
}

void bsp_board_tim_disable()
{
	HAL_TIM_Base_Stop_IT(&htim3);
}

