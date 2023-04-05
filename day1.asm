#include<regx52.h>
void DELAY_ms(unsigned int ms_Count) ) //Function to provide time delay in msec
{
unsigned int i,j;
for(i=0;i<ms_Count;i++)
{
for(j=0;j<100;j++);
}
}
int main() {
char seg_code[]={0x3f,0x06,0x5b,0x0f,0x66,0x6d,0x7c,0x07,0x7f,0x6f};
int i;
while (1)
{
for (i = 0; i <= 9; i++) // loop to display 0-9
{
P2 = seg_code[i];
DELAY_ms(1000);
}
}
}