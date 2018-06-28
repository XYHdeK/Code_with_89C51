#include<reg52.h>
#define uint unsigned int
#define uchar unsigned char
uchar num;
uchar code table[] = {0x47,0x40,0x41,0x06};//L,O,U,E
void time(uint c);

void main()
{
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