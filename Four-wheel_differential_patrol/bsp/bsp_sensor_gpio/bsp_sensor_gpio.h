#ifndef BSP_SENSOR_GPIO_H
#define BSP_SENSOR_GPIO_H

#include "bsp.h"

#ifdef __cplusplus
extern "C" {
#endif
	
	void bsp_sensor_gpio_init(void);
	
	uint8_t bsp_sensor0_get(void);

	uint8_t bsp_sensor1_get(void);

	uint8_t bsp_sensor2_get(void);

	uint8_t bsp_sensor3_get(void);
	
#ifdef __cplusplus
}
#endif

#endif
