 #include<reg52.h>
 #include <intrins.h>
#define uint unsigned int
#define uchar unsigned char
uchar temp;
void time(uint);
void main()
{
	temp=0xfe;
	P2=temp;
	while(1)
	{
	temp=_crol_(temp,1);
	time(600);
	P2=temp;
	}
}

void time(uint c)
{
	uint a,b;
	for(a=100;a>0;a--)
		for(b=c;b>0;b--);
		}
