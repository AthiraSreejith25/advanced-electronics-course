#include<reg51.h> 
#define lcd P0
sbit rs=P2^0;
sbit e=P2^1;

sbit sw1=P1^2;
sbit sw2=P1^1;
sbit sw3=P1^3;
sbit sw4=P1^0;

sbit forward = P3^0;
sbit backward = P3^1;
sbit stop = P3^2;


void delay (int);
void cmd (unsigned char);
void display (unsigned char);
void string (char *);
void init (void);


void delay (int d)
{
	unsigned char i;
	for(;d>0;d--)
	{
		for(i=250;i>0;i--);
		for(i=248;i>0;i--);
	}
}
void cmd (unsigned char c)
{
	lcd=c;
	rs=0;
	e=1;
	delay(10);
	e=0;
}
void display (unsigned char c)
{
	lcd=c;
	rs=1;
	e=1;
	delay(10);
	e=0;
}
void string (char *p)
{
	while(*p)
	{
		display(*p++);
	}
}
void init (void)
{
	cmd(0x38);
	cmd(0x0c);
	cmd(0x01);
	cmd(0x80);
}

void main()i
{
	int z=0;
	init();
	P3=0xff;
	P1=0x00;
	abc:
  cmd(0x80);
	while(stop==0);
	string("Press Forward Or");
	cmd(0xc0);
	string("Backward To Run");
	forward=1;
	backward=1;
	while(1)
	{
            if(forward==0)
						{	
              cmd(0x01);
							cmd(0x80);
              string("Running Forward");							
              while(forward==0);							
							while(1)
							{
								z++;
								if(z==1)
								{
								 sw1=1;sw2=0;sw3=0;sw4=0;delay(30);
                 if(backward==0 || stop==0)
                 break;									 
								}
								else if(z==2) 
								{
								 sw1=1;sw2=1;sw3=0;sw4=0;delay(30); 
								 if(backward==0 || stop==0)
                 break;
								}
								else if(z==3)
								{
								 sw1=0;sw2=1;sw3=0;sw4=0;delay(30); 
								 if(backward==0 || stop==0)
                 break;
								}
								else if(z==4)
								{
								 sw1=0;sw2=1;sw3=1;sw4=0;delay(30); 
                 if(backward==0 || stop==0)
                 break;
								}
								else if(z==5)
								{
							   sw1=0;sw2=0;sw3=1;sw4=0;delay(30); 
								 if(backward==0 || stop==0)
                 break;
								}
								else if(z==6)
								{									
								 sw1=0;sw2=0;sw3=1;sw4=1;delay(30); 
								 if(backward==0 || stop==0)
                 break;
								}
								else if(z==7)
								{
								 sw1=0;sw2=0;sw3=0;sw4=1;delay(30); 
								 if(backward==0 || stop==0)
                 break;
								}
								else if(z==8)
								{
								 z=0;
								 sw1=1;sw2=0;sw3=0;sw4=1;delay(30);
							   if(backward==0 || stop==0)
                 break;
								}
						  }
						}
            
            if(backward==0)
						{	
							cmd(0x01);
							cmd(0x80);
							string("Running Backward");
              while(backward==0);							
							while(1)
							{
								z++;
								if(z==1)
								{
								 sw1=1;sw2=0;sw3=0;sw4=1;delay(30);
                 if(forward==0 || stop==0)
                 break;									 
								}
								else if(z==2) 
								{
								 sw1=0;sw2=0;sw3=0;sw4=1;delay(30); 
								 if(forward==0 || stop==0)
                 break;
								}
								else if(z==3)
								{
								 sw1=0;sw2=0;sw3=1;sw4=1;delay(30); 
								 if(forward==0 || stop==0)
                 break;
								}
								else if(z==4)
								{
								 sw1=0;sw2=0;sw3=1;sw4=0;delay(30); 
                 if(forward==0 || stop==0)
                 break;
								}
								else if(z==5)
								{
							   sw1=0;sw2=1;sw3=1;sw4=0;delay(30);
								 if(forward==0 || stop==0)
                 break;
								}
								else if(z==6)
								{	
                 sw1=0;sw2=1;sw3=0;sw4=0;delay(30); 									
								 if(forward==0 || stop==0)
                 break;
								}
								else if(z==7)
								{
								 sw1=1;sw2=1;sw3=0;sw4=0;delay(30); 
								 if(forward==0 || stop==0)
                 break;
								}
								else if(z==8)
								{
								 z=0;
								 sw1=1;sw2=0;sw3=0;sw4=0;delay(30); 
	  					   if(forward==0 || stop==0)
                 break;
								}
						  }
						}
						if(stop==0)
							goto abc;
					}
}