#include <reg51.h>
#include <stdio.h>
sbit	tv = P2^0;
sbit	fan = P2^1;
sbit	heater = P2^2;
sbit	lamps = P2^3;

sbit rs = P2^4;
sbit rw = P2^5;
sbit e = P2^6;

sbit ac = P3^7;

#define display_port P1
void msdelay(unsigned char time)
{
	unsigned i,j;
	for(i=0; i<time ; i++)
	for(j=0; j<1275 ; j++);
}

void lcd_cmd(unsigned char command)  //Function to send command instruction to LCD
{
    display_port = command;
    rs= 0;
    rw=0;
    e=1;
    msdelay(1);
    e=0;
}
void lcd_data(unsigned char disp_data)  //Function to send display data to LCD
{
    display_port = disp_data;
    rs= 1;
    rw=0;
    e=1;
    msdelay(1);
    e=0;
}
 void lcd_init()    //Function to prepare the LCD  and get it ready
{
    lcd_cmd(0x38);  // for using 2 lines and 5X7 matrix of LCD
    msdelay(10);
    lcd_cmd(0x0F);  // turn display ON, cursor blinking
    msdelay(10);
    lcd_cmd(0x01);  //clear screen
    msdelay(10);
    lcd_cmd(0x81);  // bring cursor to position 1 of line 1
    msdelay(10);
}
void print(unsigned int c)
	{
		SBUF = c;
		while (TI == 0);
		TI=0;
	}
	
	void print_array( char C[], int s)	
	{
		int i;
		for (i = 0; i < s - 1; i++){
			
		print (C[i]);
		
		lcd_data(C[i]);
		msdelay(20);
		}
		
		msdelay(200);
		lcd_cmd(0x01);
		
	}
void main()
{
unsigned char X;
	char fan1[] = "fan on";
	char fan0[] = "fan off";
	char tv_name[] = "Open TV";
	char tv_close[] = "Close TV";
	char on_heater[] = "heater on";
	char of_heater[] = "heater off";
	char on[] = "on all";
	char off[] = "off all";
	char AC_on[] = "AC on";
	char AC_of[] = "AC off";
	unsigned char f = 0 ;
	unsigned char b = 0 ;
	unsigned char l = 0 ;
	unsigned char r = 0 ;
	unsigned char s = 0 ;
	unsigned char _a = 0 ;
	unsigned char h_of = 0;
	unsigned char AC_offf = 0 ;
	unsigned char tv_of= 0 ;
	unsigned char fan_0 = 0;
	unsigned i;
SCON = 0x50;
TMOD = 0X20;
TH1 = -3;
TR1 = 1;   //initilize Serial communication
	lcd_init();
	P2 = 0;
	ac = 0;
 while(1)
{
		     while(RI==0);
		     X = SBUF;
				 RI=0;
	
	if (X == fan1[f])
{
		f++;
	if(f == sizeof(fan1)-1)
	{
		fan=1;		
	print_array(fan1, sizeof(fan1));
f = 0 ;
b = 0 ;
l = 0 ;
r = 0 ;
s = 0 ;
_a = 0 ;
h_of = 0;
AC_offf = 0 ;
tv_of= 0 ;
fan_0 = 0;
	}
}
if (X ==fan0[fan_0])
{
		fan_0++;
	if(fan_0 == sizeof(fan0)-1)
	{
		fan=0;
	print_array(fan0, sizeof(fan0));
f = 0 ;
b = 0 ;
l = 0 ;
r = 0 ;
s = 0 ;
_a = 0 ;
h_of = 0;
AC_offf = 0 ;
tv_of= 0 ;
fan_0 = 0;
	}
}
	
	if (X ==tv_name[b])
{
		b++;
	
	if(b == sizeof(tv_name)-1)
	{
		tv=1;
		
	print_array(tv_name, sizeof(tv_name));
f = 0 ;
b = 0 ;
l = 0 ;
r = 0 ;
s = 0 ;
_a = 0 ;
h_of = 0;
AC_offf = 0 ;
tv_of= 0 ;
fan_0 = 0;
	}
}
	if (X ==tv_close[tv_of])
{
		tv_of++;
	if(tv_of == sizeof(tv_close)-1)
	{
		tv=0;
	print_array(tv_close, sizeof(tv_close));
	f = 0 ;
b = 0 ;
l = 0 ;
r = 0 ;
s = 0 ;
_a = 0 ;
h_of = 0;
AC_offf = 0 ;
tv_of= 0 ;
fan_0 = 0;

	}
}
	if (X ==on_heater[l])	
{
		l++;
	
	if(l == sizeof(on_heater)-1)
	{
		heater=1;
		
	print_array(on_heater, sizeof(on_heater));
	f = 0 ;
b = 0 ;
l = 0 ;
r = 0 ;
s = 0 ;
_a = 0 ;
h_of = 0;
AC_offf = 0 ;
tv_of= 0 ;
fan_0 = 0;

	}
}
if (X ==of_heater[h_of])	
{
		h_of++;
	
	if(h_of == sizeof(of_heater)-1)
	{
		heater=0;
		
	print_array(of_heater, sizeof(of_heater));
f = 0 ;
b = 0 ;
l = 0 ;
r = 0 ;
s = 0 ;
_a = 0 ;
h_of = 0;
AC_offf = 0 ;
tv_of= 0 ;
fan_0 = 0;

	}
}
	
	if (X ==on[r])
{
		r++;
		if(r == sizeof(on)-1)
	{
		tv=1;
		heater=1;
		fan=1;
		lamps=1;
		ac = 1;
		
	print_array(on, sizeof(on));
f = 0 ;
b = 0 ;
l = 0 ;
r = 0 ;
s = 0 ;
_a = 0 ;
h_of = 0;
AC_offf = 0 ;
tv_of= 0 ;
fan_0 = 0;
	}
	
}
	
	if (X ==off[s])
{
		s++;

	if(s == sizeof(off)-1)
	{
		tv=0;
		heater=0;
		fan=0;
		lamps=0;
		ac = 0;
	print_array(off, sizeof(off));
f = 0 ;
b = 0 ;
l = 0 ;
r = 0 ;
s = 0 ;
_a = 0 ;
h_of = 0;
AC_offf = 0 ;
tv_of= 0 ;
fan_0 = 0;
	}
}
	if (X ==AC_on[_a])
{
		_a++;

	if(_a == sizeof(AC_on)-1)
	{
		ac = 1;
	print_array(AC_on, sizeof(AC_on));
f = 0 ;
b = 0 ;
l = 0 ;
r = 0 ;
s = 0 ;
_a = 0 ;
h_of = 0;
AC_offf = 0 ;
tv_of= 0 ;
fan_0 = 0;

	}
	
}
		if (X ==AC_of[AC_offf])
{
		AC_offf++;

	if(AC_offf == sizeof(AC_of)-1)
	{
		ac = 0;
	print_array(AC_of, sizeof(AC_of));
f = 0 ;
b = 0 ;
l = 0 ;
r = 0 ;
s = 0 ;
_a = 0 ;
h_of = 0;
AC_offf = 0 ;
tv_of= 0 ;
fan_0 = 0;
	}
}
}
}
