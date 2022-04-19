#include<reg51.h>
sbit c0=P1^4;
sbit c1=P1^5;
sbit c2=P1^6;
sbit c3=P1^7;
void msdelay(unsigned int time){
	unsigned int i,j;
	for(i=0;i<time;i++)
	for(j=0;j<319;j++);
}
void main(){
	unsigned int i,DD0,DD1,DD2,count;
	while(1)
	{
		count=count+1;
		if(count>100)
			count=0;
		DD0=count%10;
		DD1=(count/10)%10;
		DD2=(count/100)%10;
		for(i=0;i<=100;i++){
			P1=DD0;
			c0=1;
			msdelay(100);
			P1=DD1;
			c1=1;
			msdelay(100);
			P1=DD2;
			c2=1;
			msdelay(100);
		}
	}
}
			
			