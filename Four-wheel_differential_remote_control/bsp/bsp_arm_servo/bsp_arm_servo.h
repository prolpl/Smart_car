#ifndef BSP_ARM_SERVO_H
#define BSP_ARM_SERVO_H

#include "bsp.h"

#ifdef __cplusplus
extern "C" {
#endif

	void bsp_arm_servo_init(void);

	void bsp_arm_left_high_tim_set(uint16_t high_tim);
	
	void bsp_arm_right_high_tim_set(uint16_t high_tim);
	
	void bsp_arm_up_high_tim_set(uint16_t high_tim);
	
	void bsp_arm_servo_pwm_run(void);

	void bsp_arm_servo_gpio_init(void);
		
#ifdef __cplusplus
}
#endif

#endif

