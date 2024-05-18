#ifndef ARM_SERVO_H
#define ARM_SERVO_H

#include "type_servo.h"

#ifdef __cplusplus
extern "C" {
#endif
 
	void arm_servo_init(void);
		
	void arm_left_pwm_set(uint16_t pwm);
		
	void arm_right_pwm_set(uint16_t pwm);
		
	void arm_up_pwm_set(uint16_t pwm);
		
	void arm_servo_pwm_run(void);
	
	uint16_t arm_servo_pwm_param_get(uint8_t servo_id,uint8_t servo_param);
	
#ifdef __cplusplus
}
#endif

#endif


