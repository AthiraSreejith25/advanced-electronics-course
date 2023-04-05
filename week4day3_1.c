#include <reg51.h>
sbit rs=P1^2;
sbit rw=P1^1;
sbit en=P1^0;
sbit rd=P1^3;
sbit wr=P1^4;
sbit intr=P1^5;
void msdelay(unsigned int t);
void cmd(unsigned char cmdword);
void init();
void senddata(unsigned char mymsg);
void CaD(unsigned char value);
void main()
 { unsigned char B_Data;
 init();

 P3 = 0xFF;
 intr = 1;
 rd = 1;
 wr = 1;

 while(1)
 {
 wr = 0;
 wr = 1;
 while(intr == 1);

 rd=0;
 B_Data = P3;
 CaD(B_Data);
 rd = 1;
 }
 }
void msdelay(unsigned int t)
{
unsigned int i,j;
for (i=0;i<t;i++)
for (j=0;j<1275;j++);
}
void cmd(unsigned char cmdword) //sub. to write commands
 { 
