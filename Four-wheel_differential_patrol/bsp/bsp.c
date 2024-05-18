#include "bsp.h"

void bsp_init(void)
{
	HAL_Init();
	
	SystemClock_Config();
}
