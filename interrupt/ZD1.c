#include<reg52.h>
#define uint unsigned int
#define uchar unsigned char
sbit D1=P2^0;
uchar num;
uchar code table[] = {0x47,0x40,0x41,0x06};//L,O,U,E
void time(uint c);

void main()
{   
	EA=1;
	EX1=1;
//	IT0=1;
//	TCON=0x01;


	num = 0;
	P1 = 0xf0;
	while(1)
	{
		   
			P0 = table[num];
			num++;
			time(600);	
			if(num == 4)
			{
				num = 0;
			}
	}
}

void time(uint c)
{
	uint a,b;
	for(a = 100;a>0;a--)
		for(b = c;b>0;b--);
}

void exter0() interrupt 0
{
	D1=0;
	time(600);
	D1=1;
}