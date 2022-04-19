#include<reg51.h>
sbit en = P3^5;
sbit rw = P3^6;
sbit rs = P3^7;
void msdelay(unsigned int time){
	unsigned i,j;
	for(i=0;i<time;i++){
		for(j=0;j<319;j++);
    }
}
void lcdcmd(unsigned char loc){
	P1=loc;
	en=1;
	rs=0;
	rw=0;
	msdelay(1);
	en=0;
}
void lcddata(unsigned char loc, unsigned int value){
	lcdcmd(loc);
	P1=value;
	en=1;
	rs=1;
	rw=0;
	msdelay(1);
	en=0;
}
void LCDINT(){
	lcdcmd(0X38);
	lcdcmd(0X06);
	lcdcmd(0X0c);
	lcdcmd(0x01);
	msdelay(1);
}
void lcddisplay(unsigned char loc , unsigned char word[]){
	unsigned char i;
	for(i=0;word[i]!='0';i++)
	{
		lcddata(loc+i,word[i]);
	}
	
}

void main(){
	char i;
	LCDINT();
	while(1){
		lcddisplay(0x82,"NIT NAGAlAND");
		msdelay(100);
		for(i=0;i<17;i++){
			lcdcmd(0X18);
			msdelay(100);
		}
	}
}
			
		



	
	
	
	
	
	
	
	
	
	
	
	