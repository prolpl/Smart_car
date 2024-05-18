#ifndef TIME_H
#define TIME_H

#include "stdint.h"

#ifdef __cplusplus
extern "C" {
#endif

	void time_init(void);
	
	void time_run(void);
	
	uint8_t time_flag10ms_request(void);
	
	uint8_t time_flag20ms_request(void);
	
	uint8_t time_flag40ms_request(void);
	
	void time_count_run(void);
	
	void time_flag10us_reset(void);  
	
#ifdef __cplusplus
}
#endif

#endif


