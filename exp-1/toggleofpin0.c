#include<reg51.h>
sbit led = P0^0;
void delay ( unsigned int a )
{
unsigned int I,j;
for(I=0;I<a;I++)
for(j=0;j<120;j++);
}
void main(){
	  led=0x00;
    while(1){
		led=0x55;
		delay(1);//1ms delay
		led=0x00;
		delay(1);//1ms delay
	}
}