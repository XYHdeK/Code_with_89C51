#include<reg52.h>
void main()
{
	P1=0xfe;
	P0=0x47;
	P1=0xff;
	
	P1=0xfd;
	P0=0x40;
	P1=0xff;

	P1=0xfb;
	P0=0x41;
	P1=0xff;

	P1=0xf7;
	P0=0x06;
	P1=0xff;
}