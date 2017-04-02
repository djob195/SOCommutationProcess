#include <stdio.h>
#include <dos.h>
#include <conio.h>
#include "timer.h"
#define INTTICK 0X1C    /* The clock tick   interrupt */
#ifdef __cplusplus
    #define __CPPARGS ...
#else
    #define __CPPARGS
#endif
extern "C"
{
	int countClock=0;
	void interrupt (*oldhandler)(__CPPARGS);
	void interrupt handler(__CPPARGS) /* if C++, need the the ellipsis */
	{
	/* disable interrupts during the handling of the interrupt */
	   disable();
	/* increase the global counter */
	   countClock++;
	/* reenable interrupts at the end of the handler */
	   enable();
	/* call the old routine */
	   oldhandler();
	}
	void startClock(void)
	{
	   /* save the old interrupt vector */
	   oldhandler = getvect(INTTICK);
	   /* install the new interrupt handler */
	   setvect(INTTICK, handler);
	}
	void stopClock(void)
	{
		 setvect(INTTICK, oldhandler);
	}
	int getTimer(void)
	{
		 return countClock; 
	}
}