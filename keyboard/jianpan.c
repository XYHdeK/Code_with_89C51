#include<reg52.h>
#define uint unsigned int
#define uchar unsigned char
uchar code table[]={
0xc0,0xf9,0xa4,0xb0,
0x99,0x92,0x82,0xf8, 
0x80,0x90,0x88,0x83, 
0xc6,0xa1,0x86,0x8e};
uchar num;
sbit D1 = P2^3;
sbit key1 = P3^7;
void time(uint pig)
{
   uint boy,girl;
   for(girl = 110;girl > 0;girl--)
      for(boy = pig; boy > 0;boy--);   
}
void main()
{
   P1 = 0xfe;
   P3 = 0xff;
   while(1)
	{
		if(key1 == 0)
		   {
			   D1 = 0;
			   num++ ;
			   if(num == 10)
			      num = 0;
				  while(!key1);
				  time(5);
				  while(!key1);
			}			 
		else 
			D1 = 1;

		    P0 = table[num];	
	}   
}