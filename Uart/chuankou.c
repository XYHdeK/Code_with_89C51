#include<reg52.h>
#define uint unsigned int
#define uchar unsigned char
uchar flag,a;
void init()
{
   TMOD = 0x20;		   //���ö�ʱ��������ʽ2
   EA = 1;			   //�����ж�
   TR1 = 1;			   //����T1
   TH1 = 0xfd;		   //���ò�����λ9600
   TL1 = 0xfd;		   
   REN = 1;			   //�����������
   SM0 = 0;			   //���ô��ڹ�����ʽ1
   SM1 = 1;	 
   ES = 1;   		   //�����ж�����
//   SCON = 0x53;
}

void ser() interrupt 4
{
   RI = 0;
// P2 = SBUF;
   a = SBUF;	  //����
   flag = 1;
}

void main()
{
    init();
	while(1)
	{
	   if(flag == 1)
	     {
		     ES =0;
			 flag = 0;
			 SBUF = a;	  // �ͳ�
			 P2 = SBUF;
			 while(!TI);
			 TI = 0;
			 ES = 1;
		 }   
	}
}