#include <conio.h>
#include "timer.h"
extern "C"
{
    PCB::PCB(int id)
    {
        this->clean();
        this->Live = 0;
        this->Play = 0;
        this->ID = id;
        this->Quantum = 0;
    }

    PCB::locate(int x, int y)
    {
        this->screenPcb[x][y]=1;
    }

    void PCB::paint(int x, int y, char caracter)
    {
        x++;
        y++;
        x= (this->ID*26) + (X+3)
        y = (this->ID*20) + (Y+2)
        gotoxy(x,y);
        cprintf("%c",caracter);
    }

    void PCB::painted(int x, int y, char caracter)
    {
        if(screenPcb[x][y]==1)
        {
            this->paint(x,y,caracter):
        }
    }

    int PCB::isLive()
    {
        if(this->Live==1)
        {
            return 1;
        }
        return 0;
    }

    int PCB::isPlay()
    {
        if(this->isPlay)
        {
            return 1;
        }
        return 0;
    }

    int PCB::isWork()
    {
        if ((this->isLive==1) && (this->isPlay==1) && (getTimer() < this->Quantum))
        {
            return 1;
        }
        return 0;
    }

    void PCB::execute()
    {
        resetTimer();
        int delay = 0;
        while(this->isWork()==1)
        {
            if (nowCaracter == ".")
            {
                this->painted(this->posx, this->posy, '.');
            }
            else
            {
                this->painted(this->posx, this->posy, ' ');
            }
            if(this->posy < 20)
            {

            }
            else
            {
                if(this->posx < 24)
                {
                    
                }
            }
        }
    }

    PCB::clean()
    {
        for (int i = 0; i <24; i++)  
        {
            for (int j = 0; j < 20; j++)  
            {
                this->screenPcb[i][j]=0;
            }
        }
    }

    void PCB::setQuantum(int quantum)
    {
         this->Quantum=quantum;
    }
}
