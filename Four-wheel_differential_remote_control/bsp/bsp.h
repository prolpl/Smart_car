#ifndef BSP_H
#define BSP_H

#include "main.h"
#include "stm32f1xx_hal.h"

/********************** BSP - SYS CLOCK  ***************/
#define BSP_SUPPORT_SYS_CLK
#define BSP_SUPPORT_BOARD_TIM
#define BSP_SUPPORT_MOTOR
#define BSP_SUPPORT_ARC_SERVO
#define BSP_SUPPORT_ARM_SERVO
//#define BSP_SUPPORT_SENSOR_ADC
//#define BSP_SUPPORT_SENSOR_GPIO
//#define BSP_SUPPORT_UART
//#define BSP_SUPPORT_ENCODER 
#define BSP_SUPPORT_PS2_GPIO

//#define BSP_SUPPORT_MAX7219


/********************** BSP - SYS CLOCK  ***************/
#ifdef BSP_SUPPORT_SYS_CLK
	#include "bsp_sys_clock.h"
#endif
/********************** BSP - SYS CLOCK  ***************/

/********************** BSP - BOARD TIM  ***************/
#ifdef BSP_SUPPORT_BOARD_TIM
	#include "bsp_board_tim.h"
	#include "time.h"
#endif
/********************** BSP - BOARD TIM  ***************/

/********************** BSP - MOTOR ********************/
#ifdef BSP_SUPPORT_MOTOR
//#include "type_motor.h"
#include "bsp_motor.h"
//#include "drv_motor.h"
#endif
/********************** BSP - MOTOR ********************/

/********************** BSP - SERVO ********************/
#ifdef BSP_SUPPORT_ARC_SERVO
	#include "bsp_arc_servo.h"
	#include "arc_servo.h"
	#include "type_servo.h"
#endif

#ifdef BSP_SUPPORT_AEM_SERVO
	#include "bsp_arm_servo.h"
	#include "arm_servo.h"
	#include "type_servo.h"
#endif
/********************** BSP - SERVO ********************/

/********************** BSP	- SENSOR *******************/
#ifdef BSP_SUPPORT_SENSOR_ADC
	#include "bsp_sensor_adc.h"
#endif
/********************** BSP	- SENSOR *******************/

/********************** BSP	- SENSOR *******************/
#ifdef BSP_SUPPORT_SENSOR_GPIO
	#include "bsp_sensor_gpio.h"
#endif
/********************** BSP	- SENSOR *******************/

/********************** BSP	- SENSOR *******************/
#ifdef BSP_SUPPORT_PS2_GPIO
	#include "bsp_ps2.h"
#endif
/********************** BSP	- SENSOR *******************/

#ifdef BSP_SUPPORT_MAX7219
	#include "bsp_max7219.h"
#endif 
///********************** BSP - UART *********************/
//#ifdef BSP_SUPPORT_UART
//#include "type_uart.h"
//#include "bsp_uart.h"
//#include "drv_uart.h"
//#endif
///********************** BSP - UART *********************/

///********************** BSP - ENCODER ******************/
//#ifdef BSP_SUPPORT_ENCODER
//#include "bsp_encoder.h"
//#include "drv_encoder.h"
//#endif
///********************** BSP - ENCODER ******************/
#ifdef __cplusplus
extern "C" {
#endif
	
	void bsp_init(void);
 
#ifdef __cplusplus
}
#endif

#endif

