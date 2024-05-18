#include "main.h"
#include "bsp.h"
#include "remote_control.h"

int main()
{
	bsp_init();
	remote_control_init();
	
	while(1)
	{	
		remote_control_run();
	}
}

void Error_Handler(void)
{
	__disable_irq();
	while (1)
	{
		
	}
}
