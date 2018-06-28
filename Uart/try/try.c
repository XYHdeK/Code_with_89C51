#include<reg52.h>
#define uchar unsigned char
uchar flag,a,b,c;
uchar code table[]={
0xc0,0xf9,0xa4,0xb0,
0x99,0x92,0x82,0xf8, 
0x80,0x90,0x88,0x83, 
0xc6,0xa1,0x86,0x8e};
void init()
{
   P1 = 0xf0;
   P0 = 0xc0;
   TMOD = 0x20;
   
   EA = 1;
   TH1 = 0xfd; 
   TL1 = 0xfd;
   REN = 1;
   SM0 = 0;
   SM1 = 1;
   ES = 1;
  // TR1 = 1;
   
}

void duan() interrupt 4
{
   RI = 0;
 
   P0=a;
   flag = 1;
}

void main()
{
   int aa=0;
   init();
   while(1)
   {
   		if(flag == 1)
        {
		    ES =0 ;
		    flag = 0;
		    SBUF = a;
	        b = SBUF;
		    
		    while(!TI);
		    TI = 0;
		    ES = 1;
	    }
   }
   
}