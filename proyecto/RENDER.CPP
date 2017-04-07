#ifndef __RENDERKERNEL_H__
#define __RENDERKERNEL_H__

#include <conio.h>
#include <stdlib.h> 
#include <dos.h>
#include <graphics.h> 
#include "render.h"

#define DELAYBLINK		5000
#define FREESPACEX      25
#define FREESPACEY      19
#define OFFSETX         3
#define OFFSETY         2
#define UISEPARATE      40
#define XMAXSCREEN      3
#define XMINSCREEN      78
#define YMAXSCREEN      48
#define YMINSCREEN      2
#define XMAXWINDOW      3
#define YMAXWINDOW      2
	
extern "C"
{
class RenderKernel{
public:
    static void paint (int x, int y);
    static void paintLine(int x1, int x2, int y1, int y2);
    static void blink (int x, int y);
    RenderKernel();
    int getFreeSpaceX();
    int getFreeSpaceY();
    int getWindows(int x, int y);
};
void RenderKernel::paint(int x, int y)
{
    gotoxy(x,y);
    textbackground(RED);
    cprintf(" ");
}
void RenderKernel::paintLine(int x1, int x2, int y1, int y2)
{
    int i = 0 ;
    int finalComponent = 0;
    if(x1==x2)
    {
        if(y1 < y2)
        {
            i = y1;
            finalComponent = y2;
        }
        else
        {
            i = y2;
            finalComponent = y1;
	}
	for(i; i <= finalComponent; i++)
	{
	    RenderKernel::paint(x1,i);
	}
    }
    else
    {
	int pending = (y1-y2) / (x1-x2);
	if(x1 < x2)
	{
	    i = x1;
	    finalComponent = x2;
	}
	else
	{
	    i = x2;
	    finalComponent = x1;
	}
	int y = 0;
	for(i; i <= finalComponent; i++)
	{
	    y = (pending * (i - x1)) + y1;
	    RenderKernel::paint(i,y);
	}
    }
}
void RenderKernel::blink(int x, int y)
{
	int flag = 1;
	int delay = 0;
	while (flag==1)
	{
		while (delay < DELAYBLINK)
		{
			gotoxy(x,y);
    			textbackground(BLUE);
    			cprintf(" ");
			delay++;
		}
		delay = 0;
		while (delay < DELAYBLINK)
		{
			gotoxy(x,y);
    			textbackground(BLACK);
    			cprintf(" ");
			delay++;
		}
		delay = 0;
	}
}
RenderKernel::RenderKernel()
{
	// -- Clear CMD -- //
	clrscr();
	//Verticales
	this->paintLine(3,3,2,48);
	this->paintLine(28,28,2,40);
	this->paintLine(53,53,2,40);
	this->paintLine(78,78,2,48);
	//Horizontales
	this->paintLine(3,78,2,2);
	this->paintLine(3,78,21,21);
	this->paintLine(3,78,40,40);
	this->paintLine(3,78,44,44);
	this->paintLine(3,78,48,48);
	textbackground(BLACK);
}
int RenderKernel::getFreeSpaceX()
{
    return (XMAXSCREEN-XMINSCREEN) / XMAXWINDOW;
}
int RenderKernel::getFreeSpaceY()
{
    return (YMAXSCREEN-YMINSCREEN) / YMAXWINDOW;
}
struct pointPCB RenderKernel::getWindows(int x, int y)
{
	struct pointPCB point;
	point.error = 0;
	point.x = 0;
	point.y = 0;
	point.z = 0;
    if( (XMINSCREEN >= x) || (x >= XMAXSCREEN) || (YMINSCREEN >= y) || (y >= YMAXSCREEN) )
    {
		point.error = -5;
		return point;
    }
    if (y == UISEPARATE)
    {
		point.error = -5;
		return point;
    }
	point.x =(x-OFFSETX) % FREESPACEX;
	point.y =(y-OFFSETY) % FREESPACEY;
    if ( (point.x == 0 ) && ( point.y  == 0 ) )
    {
		point.error = -5;
		return point;
    }
    int xRelativePos = (x-OFFSETX) / getFreeSpaceX();
    int yRelativePos = (y-OFFSETY) / getFreeSpaceY();
	point.x--;
	point.y--;
	point.z = xRelativePos + (yRelativePos*(XMAXSCREEN)); 

    return point;
}
}
#endif