#include<reg52.h>
#include<intrins.h>
#define uint unsigned int
#define uchar unsigned char
uchar temp;uint D1;
void time(uint);

void main()
{
		temp=0xfe;
		D1=temp;
	while(1)
	{
		temp=_crol_(temp,1);
		time(500);
		D1=temp;		
	}
}

void time(uint c)
{
	uint a,b;
	for(a=100;a>0;a--)
		for(b=c;b>0;b--);
}
