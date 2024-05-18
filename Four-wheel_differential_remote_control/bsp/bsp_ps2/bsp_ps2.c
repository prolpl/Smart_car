#include "bsp_ps2.h"
#include "math.h"
#include "bsp_spi.h"


/***************** spi 初始化**********************/
void bsp_ps2_init()
{
	#ifdef BSP_SUPPORT_PS2_GPIO
	bsp_ps2_gpio_init();
	#endif 
	
	#ifdef BSP_SUPPORT_PS2_SPI
	bsp_spi_init();
	
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	
	__HAL_RCC_GPIOA_CLK_ENABLE();
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
	GPIO_InitStruct.Pin = GPIO_PIN_4;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
	
	bsp_spi_cs_set_high();
	#endif
}

/***************** spi GPIO口初始化*****************/
void bsp_ps2_gpio_init()
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	
	__HAL_RCC_GPIOA_CLK_ENABLE();
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_7, GPIO_PIN_RESET);
	
	  /*Configure GPIO pins : PA4 PA5 PA7 */
	GPIO_InitStruct.Pin = GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_7;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
	
	/*Configure GPIO pin : PA6 */
	GPIO_InitStruct.Pin = GPIO_PIN_6;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
}

void bsp_ps2_cs_set_high()
{
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
}

void bsp_ps2_cs_set_low()
{
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
}

void bsp_ps2_clk_set_high()
{
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
}

void bsp_ps2_clk_set_low()
{
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
}

void bsp_ps2_do_set_high()
{
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_SET);
}

void bsp_ps2_do_set_low()
{
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_RESET);
}

uint8_t bsp_ps2_get_di()
{
	uint8_t di = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6);
	return di;
}

