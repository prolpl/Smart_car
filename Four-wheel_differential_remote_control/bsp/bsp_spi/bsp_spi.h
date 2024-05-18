#ifndef BSP_SPI_H
#define BSP_SPI_H

#include "bsp.h"

#ifdef __cplusplus
extern "C" {
#endif

	void bsp_spi_init(void);
		
	void bsp_spi_init(void);

	void bsp_spi_gpio_init(void);

	void bsp_spi_dma_init(void);
	
	void bsp_spi_cs_set_high(void);

	void bsp_spi_cs_set_low(void);

	void bsp_spi_clk_set_high(void);

	void bsp_spi_clk_set_low(void);

	void bsp_spi_do_set_high(void);

	void bsp_spi_do_set_low(void);

	uint8_t bsp_spi_get_di(void);

	uint8_t bsp_spi_read_write_byte(uint8_t* write, uint8_t* read, uint32_t size);
	
	void bsp_spi_transmit(uint8_t* write, uint32_t size);

	void bsp_spi_receive(uint8_t* read, uint32_t size);

#ifdef __cplusplus
}
#endif

#endif

