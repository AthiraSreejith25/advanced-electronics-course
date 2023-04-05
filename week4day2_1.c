#include<reg51.h>


//Function declarations
void cct_init(void);
void delay(int);
void lcdinit(void);
void writecmd(int);
void writedata(char);
void ReturnHome(void);

//*******************
//Pin description
/*
P2 is data bus
P1.0 is RS
P1.1 is E
*/
//********************

// Defines Pins
sbit RS = P1^0;
sbit E  = P1^1;

// ***********************************************************
// Main program
//
void main(void)
{
   cct_init();                                     //Make all ports zero

   lcdinit();                                      //Initilize LCD

   writecmd(0x81);
   writedata('0');                                 //write
   writedata('1');                                 //write
   writedata('2');                                 //write
   writedata('3');                                 //write
   writedata('4');                                 //write
   writedata('4');                                 //write
   writedata('5');                                 //write
   writedata('6');                                 //write
   writedata('7');                                 //write
   writedata('8');                                 //write
   writedata('9');                                 //write
	 writedata(' ');                                 //write
   writedata('P');                                 //write
   writedata('H');                                 //write
   writedata('Y');                                 //write
   writedata('3');                                 //write
   writedata('1');                                 //write
   writedata('2');                                 //write
   writedata(',');                                 //write

  
	 writecmd(0xc0);
   writedata('A');                                 //write
   writedata('d');                                 //write
   writedata('v');                                 //write
   writedata('a');                                 //write
   writedata('n');                                 //write
   writedata('c');                                 //write
   writedata('e');                                 //write
   writedata('d');                                 //write
	 
	 void delay(5);
	 writecmd(0x01);    //clear display
	 writecmd(0x81);
   writedata('E');                                 //write
   writedata('l');                                 //write
   writedata('e');                                 //write
   writedata('c');                                 //write
   writedata('t');                                 //write
   writedata('r');                                 //write
   writedata('o');                                 //write
   writedata('n');                                 //write
   writedata('i');                                 //write
   writedata('c');                                 //write
   writedata('s');                                 //write
	 writedata(' ');                                 //write
	 writedata('a');                                 //write
   writedata('n');                                 //write
   writedata('d');                                 //write
	 
	 writecmd(0xc0);
   writedata('I');                                 //write
   writedata('n');                                 //write
   writedata('s');                                 //write
   writedata('t');                                 //write
   writedata('r');                                 //write
   writedata('u');                                 //write
   writedata('m');                                 //write
   writedata('e');                                 //write
   writedata('n');                                 //write
   writedata('t');                                 //write
   writedata('a');                                 //write
   writedata('t');                                 //write
   writedata('i');                                 //write
   writedata('o');                                 //write
   writedata('n');                                 //write
	 
	 
	 
	 
   
 


   ReturnHome();                                   //Return to 0 position

    while(1)
    {
    }

}


void cct_init(void)
{
P0 = 0x00;   //not used 
P1 = 0x00;   //not used 
P2 = 0x00;   //used as data port
P3 = 0x00;   //used for generating E and RS
}

void delay(int a)
{
   int i;
   for(i=0;i<a;i++);   //null statement
}

void writedata(char t)
{
   RS = 1;             // => RS = 1
   P2 = t;             //Data transfer
   E  = 1;             // => E = 1
   delay(150);
   E  = 0;             // => E = 0
   delay(150);
}


void writecmd(int z)
{
   RS = 0;             // => RS = 0
   P2 = z;             //Data transfer
   E  = 1;             // => E = 1
   delay(150);
   E  = 0;             // => E = 0
   delay(150);
}

void lcdinit(void)
{
    delay(15000);
   writecmd(0x30);
     delay(4500);
   writecmd(0x30);
     delay(300);
   writecmd(0x30);
     delay(650);

   writecmd(0x38);    //function set
   writecmd(0x0c);    //display on,cursor off,blink off
   writecmd(0x01);    //clear display
   writecmd(0x06);    //entry mode, set increment 
}

void ReturnHome(void)     //Return to 0 location
{
  writecmd(0x02);
    delay(1500);
}