#include<reg52.h>
#define uint unsigned int
#define uchar unsigned char
uchar flag,a;
uchar code table[]={
0xc0,0xf9,0xa4,0xb0,
0x99,0x92,0x82,0xf8, 
0x80,0x90,0x88,0x83, 
0xc6,0xa1,0x86,0x8e};
void init()
{
   P1 = 0xf0;
   TMOD = 0x20;		   //���ö�ʱ��������ʽ2
   EA = 1;			   //�����ж�
   TR1 = 1;			   //����T1
   TH1 = 0xfd;		   //���ò�����λ9600
   TL1 = 0xfd;		   
   REN = 1;			   //�����������
   SM0 = 0;			   //���ô��ڹ�����ʽ1
   SM1 = 1;	 
   ES = 1;   		   //�����ж�����

}

void ser() interrupt 4
{
   RI = 0;
   a = SBUF;
   SBUF = a;	 
 //  P2 = a;
}

void main()
{
    init();
	while(1)
	{	  
        P0=a;		 
	}
}