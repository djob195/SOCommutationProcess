#include <dos.h>
#include "utility.h"
#include <conio.h>
#define YPOSUTILITY  46
#define XPOSUTILITY  5

#define KEYWORDERROR1   "Error 1: No se ha tecleado un comando correcto"
#define KEYWORDERROR2   "Error 2: no se ha escrito un numero entero"
#define KEYWORDERROR3   "Error 3: Rango de ventana invalida, escriba un numero entre [1,6]" 
#define KEYWORDERROR4   "Error 4: el comando stats, debe tener un numero 1"  
#define MOUSEERROR5     "Error 5: Click fuera de lugar"

extern "C"
{
	void clearcmd(void)
	{
		for(int i = 0; i < 72; i++)
		{
			gotoxy(XPOSUTILITY + i, YPOSUTILITY);
			cprintf(" ");
		}	
	}
    void getError(int error)
    {
	clearcmd();
        gotoxy(XPOSUTILITY,YPOSUTILITY);
        switch(error)
        {
            case 1:{
                cprintf("%s",KEYWORDERROR1);
                break;
            }
            case 2:{
                cprintf("%s",KEYWORDERROR2);
                break;
            }
            case 3:{
                cprintf("%s",KEYWORDERROR3);
                break;
            }
            case 4:{
                cprintf("%s",KEYWORDERROR4);
                break;
            }
            case 5:{
		cprintf("%s",MOUSEERROR5);
                break;
            }
            default: break;
        }
    }

    void getMessage(char * message){
	clearcmd();
        gotoxy(XPOSUTILITY,YPOSUTILITY);
        cprintf("%s",message);
    }
}