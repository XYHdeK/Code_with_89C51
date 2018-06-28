#include<reg52.h>
#include<intrins.h>
#define uint unsigned int
#define uchar unsigned char
uchar num,qian,bai,shi,ge,aa;
uint temp;
uchar code table[]={
  0xc0,0xf9,0xa4,0xb0,
  0x99,0x92,0x82,0xf8, 
  0x80,0x90,0x88,0x83, 
  0xc6,0xa1,0x86,0x8e};
void time(uint c)
{
	uint a,b;
	for(a=110;a>0;a--)
		for(b=c;b>0;b--);
} 

void time0() interrupt 1
{
	TH0=(65535-50000)/256;
	TL0=(65536-50000)%256;
	aa++;	
}		   

void display(qian,bai,shi,ge)
{
	P1=0xfe;
	P0=table[qian];
	time(1);
	
	P1=0xfd;
	P0=table[bai];
	time(1);

	P1=0xfb;
	P0=table[shi];
	time(1);

	P1=0xf7;
	P0=table[ge];
	time(1);
}

void init()
{
	TMOD=0x01;
	EA=1;
	TH0=(65535-50000)/256;
	TL0=(65536-50000)%256;
	ET0=1;
	TR0=1;
	EX0=1;
}	 

void main()
{		init();
		while(1)
		{
			if(aa==20)
			  temp++;
				if(temp==10000)
					temp=0;
					qian=temp/1000;
					bai=temp%1000/100;
					shi=temp%100/10;
					ge=temp%10; 
					temp++;


		display(qian,bai,shi,ge);
		} 

/*	temp=0xfe;
	while(1)
	{
	P2=temp;
	time(1000);
	temp=_crol_(temp,1);
	P2=temp;
	}*/ 

}