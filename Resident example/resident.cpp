#include "dos.h"
#include<stdlib.h>

int count;
void interrupt tick(...);
void interrupt (*ptTick)(...);
void color_text();
char far *video_mem=(char far *) 0xB8000000L;
void color_text()
{
   int i;
   randomize();

   for (i=1; i<=3999; i=i+2) {
   *(video_mem+i)=random(15);  //Directly changing ASCII's color attribute
   }
}
int main(){
	ptTick = getvect(8);
	setvect(8, tick);
	keep(0, 500);
	return 0;
}
void interrupt tick(...)
{
 (*ptTick)(...); // Executing timer interrupt

 count++;   // Counting tick

 if (count==182) {
 color_text();
 count=0;   // Change to zero
 }
}