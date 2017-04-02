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
	kData keywordData;
	while (exitFlag==0)
	{
		gotoxy(5,46);
		mouseData = isClicked();
		if(mouseData->isClick == 1)
		{
		       cprintf("is click: %d %d",mouseData->mouseX,mouseData->mouseY);
		}
		keywordData = EstadoTecl();
		if(keywordData.isWork == 1)
		{
		       cprintf("key: %d",keywordData.caracter);
		}
	}
	stopClock();
	return 0;
}