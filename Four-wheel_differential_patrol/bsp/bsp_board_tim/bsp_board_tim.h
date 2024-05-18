#ifndef BSP_BOARD_TIM_H
#define BSP_BOARD_TIM_H

#include "bsp.h"

#ifdef __cplusplus
extern "C" {
#endif
	
	void bsp_board_tim_init(void);
	
	void bsp_flag10us_inform(void);
	
	void bsp_board_tim_enable(void);

	void bsp_board_tim_disable(void);

#ifdef __cplusplus
}
#endif

#endif

