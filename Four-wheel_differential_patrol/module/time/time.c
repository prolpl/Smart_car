#include "time.h"
#include "bsp_board_tim.h"

#define TIME_COUNT_MAX  200

#define TIME_20MS_COUNT 200

uint8_t time_20ms = 0;
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
}

uint8_t time_flag20ms_request()
{
	return time_20ms;
}

void time_count_run()
{
    tim_count ++;

    if (tim_count > TIME_COUNT_MAX)
    {
        tim_count = 0;
    }
}
