#include "time.h"
#include "bsp_board_tim.h"

#define TIME_COUNT_MAX  200

#ifdef TIM_SUPPORT_10MS
	#define TIME_10MS_COUNT	100
#endif

#define TIME_20MS_COUNT 200
#define TIME_40MS_COUNT 400

uint8_t time_10ms = 0;
uint8_t time_20ms = 0;
uint8_t time_40ms = 0;
uint16_t tim_count = 0;

void time_init()
{
	bsp_board_tim_init();
}

void time_run()
{	
    if (tim_count == TIME_20MS_COUNT)
    {
        time_20ms = 1;
    }
    else
    {
        time_20ms = 0;
    }
/* 
    if (tim_count == TIME_40MS_COUNT)
    {
        time_40ms = 1;
    }
    else
    {
        time_40ms = 0;
    }*/   
}

uint8_t time_flag10ms_request()
{
	return time_10ms;
}

uint8_t time_flag20ms_request()
{
	return time_20ms;
}

uint8_t time_flag40ms_request()
{
	return time_40ms;
}

void time_count_run()
{
    tim_count ++;

    if (tim_count > TIME_COUNT_MAX)
    {
        tim_count = 0;
    }
}
