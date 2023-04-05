#include<reg51.h>

sbit switch1=P3^0;                         // assign switch =port 3 , 0 th pin

void ms_delay(unsigned int t) //To create a delay of 200 ms = 200 x 1ms
    {
    unsigned i,j ;
    for(i=0;i<t;i++)       //200 times 1 ms delay
    for(j=0;j<1275;j++);   //1ms delay
    }
void main()
{
		
    if(switch1 == 1) // To repeat infinitely
    {
        P2=0x0C;           //P2 = 0000 1000 First Step
        ms_delay(200);
        P2=0x06;           //P2 = 0000 0100 Second Step
        ms_delay(200);
        P2=0x03;           //P2 = 0000 0010 Third Step
        ms_delay(200);
        P2=0x09;           //P2 = 0000 0001 Fourth Step
        ms_delay(200);
    }
    else
    {
				P2=0x09;           //P2 = 0000 0001 Fourth Step
        ms_delay(200);
				P2=0x03;           //P2 = 0000 0010 Third Step
        ms_delay(200);
				P2=0x06;           //P2 = 0000 0100 Second Step
        ms_delay(200);
				P2=0x0C;           //P2 = 0000 1000 First Step
        ms_delay(200);
		}
}