#ifndef BSP_MOTOR_H
#define BSP_MOTOR_H

#include "bsp.h"

#ifdef __cplusplus
extern "C" {
#endif

	void bsp_motor_init(void);
	
	void bsp_motor1_pwm_set(int8_t pwm);
	
	void bsp_motor2_pwm_set(int8_t pwm);
	
	void bsp_motor3_pwm_set(int8_t pwm);

	void bsp_motor4_pwm_set(int8_t pwm);

	void bsp_motor_gpio_init(void);

	void bsp_motor_tim_init(void);
	
#ifdef __cplusplus
}
#endif

#endif

