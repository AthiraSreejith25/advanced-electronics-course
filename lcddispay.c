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
 P0 = cmdword;
 rs=0; //select the instruction register
 rw=0; // 0 for write operation
 en=1; // to strobe the data
 msdelay(2); // create some delay
 en=0; // reset strobe signal
 }
void init() //lcd initializtion
 {
 cmd(0x38); //function set: 8 bit, 2 lines, 5x7 dot matirx
 cmd(0x0E); //display on and cursor on
 cmd(0x01); // clear display
 cmd(0x06); // entry mode: move cursor right, don�t shift display
 cmd(0x80); //cursor position to first position of first line
 }
void senddata(unsigned char mymsg) //sub to write data
 {
 P0=mymsg;
 rs=1;
 rw=0;
 en=1; //start data write
 msdelay(2);
 en=0; // end data write
 }

void CaD(unsigned char value)
 {
 unsigned char x,d1,d2,d3,a1,a2,a3;
 x = value/10;
 d1 = value%10;
 a1=d1+'0';
 d2 = x%10;
 a2=d2+'0';
 d3 = x/10;
 a3 = d3+'0';
 senddata(a1);
 msdelay(10);
 senddata(a2);
 msdelay(10);
 senddata(a3);
 msdelay(10);
 senddata(' ');
 msdelay(200);

 }