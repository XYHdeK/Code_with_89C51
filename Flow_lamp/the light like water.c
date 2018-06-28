#include<reg52.h>
#include<intrins.h>
#define uint unsigned int
#define uchar unsigned char
sbit D1=P2^0;
uchar bian;
void time(uint)
void main()
{
	bian=0xfe
	D1=bian
	while(1)
	{
		bian=_crol_(bian,1);
		time();
		D1=bian;	
	}
}

void time()
{
	uint a,b;
	for(a=100;a>0;a--)
		for(b=100;b>0;b--);
}