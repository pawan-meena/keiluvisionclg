#include<reg51.h>
void wait1()
{
unsigned int i,j;
for(i=0;i<1000;i++)
for(j=0;j<319;j++);
}
void wait2()
{
unsigned int i,j;
for (i=0;i<500;i++)
for(j=0;j<319;j++);
}
void main()
{
P1=0x00;
P2=0x00;
P3=0x00;
while(1)
{
P0=0xDB;
P1=0xCD;
P2=0xB6;
wait1();
P0=0xDB;
P1=0xB5;
P2=0xB6;
wait2();
P0=0xDB;
P1=0x79;
P2=0xB6;
wait1();
P0=0xDB;
P1=0x76;
P2=0xB6;
wait2();
P0=0xDB;
P1=0x6F;
P2=0x36;
wait1();
P0=0xDB;
P1=0x6F;
P2=0x16;
wait2();
P0=0xDB;
P1=0x6D;
P2=0xE6;
wait1();
P0=0x49;
P1=0x6D;
P2=0xC2;
wait2();
P0=0xB6;
P1=0x6D;
P2=0xBD;
wait1();
P0=0x24;
P1=0x2D;
P2=0xB9;
wait2();
}
}