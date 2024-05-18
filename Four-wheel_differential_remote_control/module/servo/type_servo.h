#ifndef TYPE_SERVO_H
#define TYPE_SERVO_H

#include "stdint.h"

typedef enum
{
    SERVO = 0,
    SERVO_LEFT,
    SERVO_RIGHT,
    SERVO_UP,
}servo_id;

typedef enum
{
    SERVO_MIDDLE = 0,
    SERVO_LEFT_LIMIT,
    SERVO_RIGHT_LIMIT,
}servo_limit;

struct SERVO_PARAM
{
	uint16_t	pwm;
	uint16_t	left_limit;
	uint16_t	middle;
	uint16_t	right_limit;
};

#ifdef __cplusplus
extern "C" {
#endif
 

#ifdef __cplusplus
}
#endif

#endif


