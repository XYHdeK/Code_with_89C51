#include<reg52.h>
#define uint unsigned int
#define uchar unsigned char
uchar num;
uchar code table[]={ 
 0xc0,0xf9,0xa4,0xb0,
 0x99,0x92,0x82,0xf8,
 0x80,0x90,0x88,0x83,
 0xc6,0xa1,0x86,0x8e };
 
void sj(uint c);
void main()
{
	P1=0xf0;
	while(1)
	{
	for(num=0;num<16;num++)
	{
	P0=table[num];
	sj(600);
	}
	}		
}

void sj(uint c)
{
	uint a,b;
	for(a=100;a>0;a--)
		for(b=c;b>0;b--);
}