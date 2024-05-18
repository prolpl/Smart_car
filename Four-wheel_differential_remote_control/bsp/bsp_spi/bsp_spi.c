#include "bsp_spi.h"
#include "math.h"

SPI_HandleTypeDef hspi1;
DMA_HandleTypeDef hdma_spi1_tx;
DMA_HandleTypeDef hdma_spi1_rx;
/***************** spi 初始化**********************/
void bsp_spi_init()
{
//	bsp_spi_dma_init();
	bsp_spi_gpio_init();
	
	hspi1.Instance = SPI1;
	hspi1.Init.Mode = SPI_MODE_MASTER;
	hspi1.Init.Direction = SPI_DIRECTION_2LINES;
	hspi1.Init.DataSize = SPI_DATASIZE_8BIT;
	hspi1.Init.CLKPolarity = SPI_POLARITY_HIGH;     //clk_init = 1;
	hspi1.Init.CLKPhase = SPI_PHASE_1EDGE;
	hspi1.Init.NSS = SPI_NSS_SOFT;
	hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_256;
	hspi1.Init.FirstBit = SPI_FIRSTBIT_LSB;
	hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
	hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
	hspi1.Init.CRCPolynomial = 10;
	if (HAL_SPI_Init(&hspi1) != HAL_OK)
	{
		Error_Handler();
	}
}
/***************** spi 初始化**********************/

uint8_t bsp_spi_read_write_byte(uint8_t* write, uint8_t* read, uint32_t size)
{
//    HAL_SPI_DMAStart(&hspi1);
//	HAL_SPI_TransmitReceive_DMA(&hspi1, write, read,size);
//    HAL_SPI_DMAStop(&hspi1);
    
//    HAL_SPI_TransmitReceive(&hspi1, write, read,size,10);
	HAL_SPI_Transmit(&hspi1, write, size,1);
    HAL_Delay(1);
	HAL_SPI_Receive(&hspi1, read, size,1);

	return 0;
}

void bsp_spi_transmit(uint8_t* write, uint32_t size)
{
	HAL_SPI_Transmit(&hspi1, write, size,10);
}

void bsp_spi_receive(uint8_t* read, uint32_t size)
{
	HAL_SPI_Receive(&hspi1, read, size,10);
}
/***************** spi GPIO口初始化*****************/
void bsp_spi_gpio_init()
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};
  
    /* SPI1 clock enable */
    __HAL_RCC_SPI1_CLK_ENABLE();

    __HAL_RCC_GPIOA_CLK_ENABLE();
    /**SPI1 GPIO Configuration
    PA5     ------> SPI1_SCK
    PA6     ------> SPI1_MISO
    PA7     ------> SPI1_MOSI
    */
    GPIO_InitStruct.Pin = GPIO_PIN_5|GPIO_PIN_7;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
	
    GPIO_InitStruct.Pin = GPIO_PIN_6;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
}

void bsp_spi_dma_init()
{
	/* DMA controller clock enable */
	__HAL_RCC_DMA1_CLK_ENABLE();

	/* DMA interrupt init */
	/* DMA1_Channel2_IRQn interrupt configuration */
	HAL_NVIC_SetPriority(DMA1_Channel2_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(DMA1_Channel2_IRQn);
	/* DMA1_Channel3_IRQn interrupt configuration */
	HAL_NVIC_SetPriority(DMA1_Channel3_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(DMA1_Channel3_IRQn);
}

void bsp_spi_cs_set_high()
{
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
}

void bsp_spi_cs_set_low()
{
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
}

void bsp_spi_clk_set_high()
{
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
}

void bsp_spi_clk_set_low()
{
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
}

void bsp_spi_do_set_high()
{
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_SET);
}

void bsp_spi_do_set_low()
{
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_RESET);
}

uint8_t bsp_spi_get_di()
{
	uint8_t di = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6);
	return di;
}

