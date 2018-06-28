#include<reg52.h>
//#include<intrins.h>
#define uint unsigned int
#define uchar unsigned char
uchar ge,shi,bai,qian;
uint aa,temp;
uchar code table[] = {
   0xc0,0xf9,0xa4,0xb0,
   0x99,0x92,0x82,0xf8, 
   0x80,0x90,0x88,0x83, 
   0xc6,0xa1,0x86,0x8e};

void time(uint dog)
{
   uint cat,pig;
      for(cat = 110;cat > 0;cat--)
	     for(pig = dog;pig > 0;pig--);   
}

void time0() interrupt 1
{
   TH0 = (65535-50000)/256;	   //…∂“‚Àº£ø
   TL0 = (65536-50000)%256;
   aa++;   
}

void display(qian,bai,shi,ge)
{
   qian = temp/1000;
   bai = temp%1000/100;
   shi = temp%100/10;
   ge = temp%10;   
   
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
   temp=0;
   aa = 0;
   TMOD = 0X01;
   EA = 1;
   TR0 = 1;
   ET0 = 1;
   EX0=1;
   TH0 = (65535-50000)/256;
   TL0 = (65536-50000)%256;
}

void main()
{
   init();
   while(1)
   {
      if(aa == 5)
	   {
	     aa = 0;
		 temp++;
	   }
		 if(temp == 10000 )
		   {
		     temp = 0;
			}
		      //temp++;
				 
		 display(qian,bai,shi,ge); 
   }
   
}