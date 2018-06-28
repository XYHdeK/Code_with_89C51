#include<reg52.h>
#define uint unsigned int
#define uchar unsigned char
uchar flag,a;
void init()
{
   TMOD = 0x20;		   //设置定时器工作方式2
   EA = 1;			   //开总中断
   TR1 = 1;			   //启动T1
   TH1 = 0xfd;		   //设置波特率位9600
   TL1 = 0xfd;		   
   REN = 1;			   //串口允许接收
   SM0 = 0;			   //设置串口工作方式1
   SM1 = 1;	 
   ES = 1;   		   //串口中断允许
//   SCON = 0x53;
}

void ser() interrupt 4
{
   RI = 0;
// P2 = SBUF;
   a = SBUF;	  //接收
   flag = 1;
}

void main()
{
    init();
	while(1)
	{
	   if(flag == 1)
	     {
		     ES =0;
			 flag = 0;
			 SBUF = a;	  // 送出
			 P2 = SBUF;
			 while(!TI);
			 TI = 0;
			 ES = 1;
		 }   
	}
}