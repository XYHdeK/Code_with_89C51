#include<reg52.h>
#define uint unsigned int
#define uchar unsigned char
sbit D1=P2^0;
uchar num,tt;
uchar code table[]={ 
 0xc0,0xf9,0xa4,0xb0,
 0x99,0x92,0x82,0xf8,
 0x80,0x90,0x88,0x83,
 0xc6,0xa1,0x86,0x8e };
 
void sj(uint c);
void main()
{
	TMOD=0x01; //���ö�ʱ��0Ϊ������ʽ1
	TH0=(65536-50000)/256;
	TL0=(65536-50000)%256;
	EA=1;//�����ж�
	ET0=1;//����ʱ��0�ж�
	TR0=1;//������ʱ��0
//	EX0=1;//���ⲿ�ж�0
	P1=0xf0;
	while(1)
	{	
			P0=table[num];
			sj(1000);
			num++;
			 if(num==16)
				num=0;				 
	}		
}

void sj(uint c)
{
	uint a,b;
	for(a=110;a>0;a--)
		for(b=c;b>0;b--);
}

void exter0() interrupt 1
{
	TH0=(65536-50000)/256;
	TL0=(65536-50000)%256;
	tt++;	
}