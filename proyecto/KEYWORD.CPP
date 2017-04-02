#define INTTECL 0x16 // N� de interrupci�n de teclado (BIOS)
#define ZF 64
#define YPOS 42
#define XMINPOS 5
#define XMAXPOS 76
#define MAXCHARSCREEN 70
#define MK_WORD(HIBYTE,LOBYTE) (int)((HIBYTE << 8) + LOBYTE)
#include <dos.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include "keyword.h"
#include "utility.h"

extern "C"
{
	struct tokenRead{
        char* word;
        int type; 
    }

	struct tokenRead tomaToken(char * &input)
	{
		tokenRead token;
		if(input == 0)
		{
			token.type = -1;
			return token;
		}
		char* word;	
		int state = 0;
		int flagExit = 0;
		while(input == " " || input == "\t")
		{
			input = input++;
		}
		while(flagExit == 0)
		{
			switch(state)
			{
				case 0:
				{
					if((96 < input) && (input < 123))
					{
						state = 1;
					}
					if(input == 45)
					{
						state = 2;
					}
					if((47 < input) && (input < 58))
					{
						state = 3;
					}
					else
					{
						flagExit = 1;
					}
					break;
				}
				case 1:
				{
					if((96 < input) && (input < 123) )
					{
						state = 1;
					}
					else
					{
						flagExit = 1;
					}
					break;
				}
				case 2:
				{
					flagExit = 1;
				}
				case 3:
				{
					if((47 < input) && (input < 58))
					{
						state = 3;
					}
					else
					{
						flagExit = 1;
					}
				}
			}
			if(flagExit == 0)
			{
				strcat(word,input);
				input++;
			}
		}
		input--;
		token.type = state;
		token.word = word;
		return token;
	}

	int inWindow (struct tokenRead token)
	{
		if (token.type !=3)	
		{
			return -2;
		}	
		int window = atoi(token.word);
		if ((window < 1) || (window > 6))
		{
			return -3;
		}
		return window;
	}

	void selectAction(void)
	{
		char* command;
		int window = 0;
		tokenRead token = tomaToken(command);
		if(token.type == 1)
		{
			if (strcmp(token.word,"quantum") ==0)
			{
				token =  tomaToken(command);
				if (token.type !=3)	
				{
					getError(2);
					return;
				}	
				int quantum = atoi (token.word);
				token =  tomaToken(command);
				window = inWindow(token);
				if(window < 0)
				{
					window *= -1;
					getError(window);
					return;
				}
				getMessage("se ha leido quantum");
			}
			else if (strcmp(token.word,"stats") ==0)
			{
				token =  tomaToken(command);
				char isPositive = '+';
				int status = 0;
				if (token.type != 2)
				{
					token =  tomaToken(command);
				}
				if (token.type !=3)	
				{
					getError(2);
					return;
				}	
				int stats = atoi(token.word);
				if (stats != 1)
				{
					getError(2);
					return;
				}
				getMessage("se ha leido stats");
			}
			else if (strcmp(token.word,"exit") ==0)
			{
				getMessage("se ha leido exit");
			}
			else
			{
				int action = 0;
				if(strcmp(token.word,"add") ==0)
				{
					action = 1;
				}
				else if (strcmp(token.word,"pause") ==0)
				{
					action = 2;
				}
				else if (strcmp(token.word,"play") ==0)
				{
					action = 3;
				}	
				else if (strcmp(token.word,"remove") ==0)
				{
					action = 4;
				}
				else if (strcmp(token.word,"clear") ==0)
				{
					action = 5;
				}
				else
				{
					getError(1);
					return;
				}
				token =  tomaToken(command);
				window = inWindow(token);
				if(window  < 0)
				{
					window *= -1;
					getError(window);
					return;
				}
				switch(action)
				{
					case 1:
					{
						getMessage("se ha leido add");
						break;
					}
					case 2:
					{
						getMessage("se ha leido pause");
						break;
					}
					case 3:
					{
						getMessage("se ha leido play");
						break;
					}
					case 4:
					{
						getMessage("se ha leido remove");
						break;
					}
					case 5:
					{
						getMessage("se ha leido clear");
						break;
					}
				}
			}
		}
	}
	void cleanScreen()
	{
		for(int i = 0; i < MAXCHARSCREEN; i++)
		{
			gotoxy(XMINPOS + i,YPOS);
			cprintf(" ");
		}
		gotoxy(XMINPOS,YPOS);
	}

	void isKeyPress()
	{
		if(kbhit()!=0)
		{
			if(caracter == 13)
			{
				char comand [71];
				gotoxy(XMINPOS,YPOS);
				gets(comand);
				strlwr(comand);
				cleanScreen();
				getMessage(comand);
			}
		}
	}
}