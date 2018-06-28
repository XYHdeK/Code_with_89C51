#include<reg52.h>
#include<intrins.h>
#define uint unsigned int
#define uchar unsigned char
sbit key1 = P3^7;
sbit key2 = P3^6;
sbit key3 =	P3^5;
uchar temp,num,aa,ge,shi,bai,qian;
uchar code table[]={
0xc0,0xf9,0xa4,0xb0,
0x99,0x92,0x82,0xf8, 
0x80,0x90,0x88,0x83, 
0xc6,0xa1,0x86,0x8e};
void time(uint pig)
{	
	uint boy,girl;
	for(girl = 110;girl > 0;girl--)
		for(boy = pig;boy > 0; boy--);
}

void display()
{
	bai = num/100;
	shi = num%100/10;
	ge = num%10;

	P1 = 0xfe;
	P0 = table[0];
	time(1);

	P1 = 0xfd;
	P0 = table[bai];
	time(1);

	P1 = 0xfb;
	P0 = table[shi];
	time(1);

	P1 =0xf7;
	P0 = table[ge];
	time(1);
}	

void time0() interrupt 1
{
	TH0 = 60;		 //(65535-50000)/256
	TL0 = 175;		    //(65535-50000)%256
	aa++;
}

void com() interrupt 4
{
	RI = 0;
	num = SBUF;
	display();	
}	  

void init()
{
	temp = 0xfe;
	num = 0;
	P1 = 0xf0;
	TMOD = 0x21;		   
	EA = 1;					//开总中断
	TH0 = 60;               //(65535-50000)/256;
	TL0 = 175;              //(65535-50000)%256;			  
	ET0 =1;				    //中断允许溢出
	TR0 = 0;			    //启动定时器0
	EX0 = 1;		   	    //外部中断允许
	TR1 = 1;		 	    //启动T1		  
	TH1 = 0xfd;		        //设置波特率位9600
	TL1 = 0xfd;		   
	REN = 1;			    //串口允许接收
	SM0 = 0;			    //设置串口工作方式1
	SM1 = 1;	 
	ES = 1;				    //串口中断允许  		   
}

void saomiao()
{
	if(key1 == 0)
		{
		 	TR0 = 1;
			while(!key1);
			time(5);
			while(!key1);
		}
	

	if(key2 == 0)
		{
			TR0 = 0;	
			while(!key2);
			time(5);
			while(!key2);
		}


	if(key3 == 0)
		{
			num = 0;
			while(!key3);
			time(5);
			while(!key3);
		}

	
}	

void main()
{
	init();	
	while(1)
	{	
		saomiao();	
		if(aa == 40)
			{
				num--;
				if(num == 0)
					{
						temp = _crol_(temp,1);
						time(60);
						P2 = temp;
						
					}
						   
			}
		display();
		
		if(aa == 60)
			{
				aa = 0;
				num++;
			}
		display();	
	}
}
