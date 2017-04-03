#include <conio.h>
#include <dos.h>
#include<stdlib.h>
#include "mouse.h"
#include "timer.h"
#include "render.h"
#include "keyword.h"

int main(void)
{
	RenderKernel *render = new RenderKernel();
	startClock();
	int exitFlag = 0;
	mData* mouseData;
	gotoxy(5,46);
	while (exitFlag==0)
	{
		/*mouseData = isClicked();
		if(mouseData->isClick == 1)
		{
		       cprintf("is click: %d %d",mouseData->mouseX,mouseData->mouseY);
		}*/
		isKeyPress();
	}
	stopClock();
	return 0;
}