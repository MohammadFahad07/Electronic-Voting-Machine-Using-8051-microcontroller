// Program to make voting machine using seven segment
#include <reg51.h>
#define msec 1

sbit s1=P3^2;//Input pins for four candidates
sbit s2=P3^3;
sbit s3=P3^4;
sbit s4=P3^5;

sbit ctrl_4=P1^0;//Declare the control pins of seven segments
sbit ctrl_3=P1^1;
sbit ctrl_2=P1^2;
sbit ctrl_1=P1^3;

unsigned int v1,v2,v3,v4;

unsigned int digi_val[10]={0x40,0xF9,0x24,0x30,0x19,0x12,0x02,0xF8,0x00,0x10};
unsigned int dig_1,dig_2,dig_3,dig_4;



void delay(unsigned int count)// Time delay function
{
unsigned int j,k;
for (j=0;j<=count;j++)
for (k=0;k<=50;k++);
}

void digi_out(unsigned int current_num)// Funtion to display total votes
{
unsigned int dig_disp;
dig_disp=current_num;
P2 = digi_val[current_num];
delay(msec);
}


void calc_vote()// Funtion to count the number of votes
{
while(1)
{
if (s1==0)
{
while (s1 == 0);//check if switch 1 is pressed
{
v1 = v1 + 1;
if(v1==10)
v1=0;
}
}

if (s2==0)//check if switch 2 is pressed
{
while (s2 == 0);
{
v2 = v2 + 1;
if(v2==10)
v2=0;
}
}

if (s3==0)//check if switch 3 is pressed
{
while (s3 == 0);
{
v3 = v3 + 1;
if(v3==10)
v3=0;
}
}

if (s4==0)//check if switch 4 is pressed
{
while (s4 == 0);
{
v4 = v4 + 1;
if(v4==10)
v4=0;
}
}

ctrl_1 = 1;
ctrl_3 = ctrl_2 = ctrl_4 = 0;
digi_out(v1);
ctrl_2 = 1;
ctrl_4 = ctrl_3 = ctrl_1 = 0;
digi_out(v2);
ctrl_3 = 1;
ctrl_2 = ctrl_4 = ctrl_1 = 0;
digi_out(v3);
ctrl_4 = 1;
ctrl_3 = ctrl_2 = ctrl_1 = 0;
digi_out(v4);
}
}


void main()
{
v1 = v2 = v3 = v4 = 0;
s1 = s2 = s3 = s4 = 1;// Initialize the input pins
while(1)
{
calc_vote();
}
}

 