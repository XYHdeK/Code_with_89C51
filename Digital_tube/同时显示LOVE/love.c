#include<reg52.h>
#include<intrins.h>
#define uint unsigned int
#define uchar unsigned char
uchar temp,num,wenum;
uchar code table1[]={
  0xfe,0xfd,0xfb,0xf7};
uchar code table[]={
 0x47,0x40,0x41,0x06};
void time(uint c)
{
	uint a,b;
	for(a=10;a>0;a--)
		for(b=c;b>0;b--);
} 

void time0() interrupt 1
{
	TH0=(65535-50000)/256;
	TL0=(65536-50000)%256;	
}

void main()
{
	temp=0xfe;
	TMOD=0x01;
	EA=1;
	TH0=(65535-50000)/256;
	TL0=(65536-50000)%256;
	ET0=1;
	TR0=1;
	EX0=1;
	
//	P1=0xf0;
    while(1)
	{
		P1=table1[wenum];
		wenum++;
		if(wenum==4)
		wenum=0;

		P0=table[num];
		time(1);
		num++;
		if(num==4)
		num=0;

//		} 

//	temp=0xfe;
//	while(1)
//	{
	P2=temp;
	time(1);
	temp=_crol_(temp,1);
	P2=temp;
	} 

}