#ifndef ARC_SERVO_H
#define ARC_SERVO_H

#include "stdint.h"
#include "type_servo.h"

#ifdef __cplusplus
extern "C" {
#endif
 
	void arc_servo_init(void);

	void arc_servo_pwm_set(uint16_t pwm);
	
	uint16_t arc_servo_pwm_param_get(uint8_t servo_param);
	
	void arc_servo_pwm_run(void);
	
#ifdef __cplusplus
}
#endif

#endif


