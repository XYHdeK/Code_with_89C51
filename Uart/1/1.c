#include<reg52.h>
#define uint unsigned int
#define uchar unsigned char
uchar flag,a;
uchar code table[]={
0xc0,0xf9,0xa4,0xb0,
0x99,0x92,0x82,0xf8, 
0x80,0x90,0x88,0x83, 
0xc6,0xa1,0x86,0x8e};
void init()
{
   P1 = 0xf0;
   TMOD = 0x20;		   //设置定时器工作方式2
   EA = 1;			   //开总中断
   TR1 = 1;			   //启动T1
   TH1 = 0xfd;		   //设置波特率位9600
   TL1 = 0xfd;		   
   REN = 1;			   //串口允许接收
   SM0 = 0;			   //设置串口工作方式1
   SM1 = 1;	 
   ES = 1;   		   //串口中断允许

}

void ser() interrupt 4
{
   RI = 0;
   a = SBUF;
   SBUF = a;	 
 //  P2 = a;
}

void main()
{
    init();
	while(1)
	{	  
        P0=a;		 
	}
}