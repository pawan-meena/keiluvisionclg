#include<reg51.h>
void DispChar(unsigned char ch);
void ClrLED();
unsigned char getkey();
unsigned char getnum();
unsigned char getOp();
sbit Clk = P3^4;
sbit Dat = P0^0;
int main()
{
	unsigned char temp=0x0ff,n1=0,n2,Op,Res;
	unsigned char NumTab[10]={0x0c0,0x0f9,0x0a4,0xb0,0x99,0x92,0x82,0x0f8,0x80,0x90};
	unsigned char OpTab[4]={0x88,0x0fb,0xc8,0x0a1};
	bit Neg=0;
	ClrLED();
	while(1)
	{
		Neg=0;
			n1=getnum();
		Op=getOp()-0x0B;
		n2= getnum();
	while(getkey()!=0x13);
	ClrLED();
	switch(Op){
		case 0: 
			Res= n1+n2;
		  break;
		case 1:
			if(n2>n1){
				Neg =1;
				Res = n2-n1;
				break;
			
			}
			Res = n1-n2;
			break;
		case 2:
			Res = n1*n2;
			break;
		case 3:
			Res = n1/n2;
			break;
	}
	DispChar(NumTab[Res%10]);
	DispChar(NumTab[Res/10]);
	if (Neg)
		DispChar(0x0Bf);
	
 }
}


void DispChar(unsigned char ch){
  unsigned char i, tmp;
	P0 =0x00;
	for(i=0;i<8;i++){
		tmp = ch&0x80;
		if(tmp)
			Dat =1;
		else
			Dat=0;
		Clk =0;
		Clk =1;
		ch= ch<<1;
	
	}

}


void ClrLED(){
	unsigned char i;
	for(i=0;i<4;i++)
	DispChar(0x0ff);
	

}
		
	
	unsigned char getkey()
	{ unsigned char i,j,indx,t;
		P2=0x00;
		P0=0xff;
		indx=0x00;
		while(1)
		{ for(i=1;i<4;i<<1)
			{  P2=0x0f&-i;
				t=P0;
				t=-t;
		if(t>0)
		{
			for(j=0;j<7;j++)
			{t>>=1;
			if(t==0)
			{ return(indx+j);
				}
			}
		}
		indx+=8;
	}}}
	unsigned char getnum()
	{
		unsigned char tmp;
		while(1)
		{
			tmp=getkey();
			if(tmp<0x0a || tmp==0x10)
				return(tmp);
				}}
	unsigned char getOp()
	{
		unsigned char tmp;
		while(1)
		{
			tmp=getkey();
			if((tmp>0x0a && tmp<0x0f)||tmp==0x10)
				return(tmp);
		}}