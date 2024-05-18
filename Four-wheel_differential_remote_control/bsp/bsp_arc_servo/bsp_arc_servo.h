#ifndef BSP_ARC_SERVO_H
#define BSP_ARC_SERVO_H

#include "bsp.h"

#ifdef __cplusplus
extern "C" {
#endif

	void bsp_arc_servo_init(void);

	void bsp_arc_servo_high_tim_set(uint16_t high_tim);

	void bsp_arc_servo_pwm_run(void);

	void bsp_arc_servo_gpio_init(void);
		
#ifdef __cplusplus
}
#endif

#endif

