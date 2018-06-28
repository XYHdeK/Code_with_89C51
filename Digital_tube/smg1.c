sbit wei=P2^7;
void main()
{
	wei=1;
	P0=0x9f;
	wei=0;
	while(1);
}