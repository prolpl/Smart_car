#include "main.h"
#include "bsp.h"
#include "find_line.h"

void Delay(uint32_t nCount)
{
  for(; nCount != 0; nCount--);
}

int main()
{
	bsp_init();
	
	find_line_init();
	
	while(1)
	{	
		find_line_run();
	}
}

void Error_Handler(void)
{
	__disable_irq();
	while (1)
	{
		
	}
}
