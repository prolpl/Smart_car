#ifndef BSP_PS2_H
#define BSP_PS2_H

#include "bsp.h"

#ifdef __cplusplus
extern "C" {
#endif

	void bsp_ps2_init(void);
		
	void bsp_ps2_gpio_init(void);
	
	void bsp_ps2_cs_set_high(void);

	void bsp_ps2_cs_set_low(void);

	void bsp_ps2_clk_set_high(void);

	void bsp_ps2_clk_set_low(void);

	void bsp_ps2_do_set_high(void);

	void bsp_ps2_do_set_low(void);

	uint8_t bsp_ps2_get_di(void);

#ifdef __cplusplus
}
#endif

#endif

