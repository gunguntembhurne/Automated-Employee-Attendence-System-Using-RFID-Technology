#include<lpc21xx.h>

#include "header.h"


void lcd_data(unsigned char data)

{

 unsigned int temp;


 IOCLR1|=0XFE<<16;

 temp=(data&0xf0)<<16;

 IOSET1=temp;


 IOSET1=(1<<17);

 IOCLR1=(1<<18);

 IOSET1=(1<<19);

 delay_ms(2); 

 IOCLR1=(1<<19);


 IOCLR1|=0XFE<<16;

 temp=(data&0x0f)<<20;

 IOSET1=temp;

 IOSET1=(1<<17);

 IOCLR1=(1<<18);

 IOSET1=(1<<19);

 delay_ms(2); 

 IOCLR1=(1<<19);

}


void lcd_cmd(unsigned char cmd)

{

	unsigned int temp;


 IOCLR1|=0XFE<<16;

 temp=(cmd&0xf0)<<16;

 IOSET1=temp;

 IOCLR1=(1<<17);

 IOCLR1=(1<<18);

 IOSET1=(1<<19);

 delay_ms(2); 

 IOCLR1=(1<<19);


 IOCLR1|=0XFE<<16;

 temp=(cmd&0x0f)<<20;

 IOSET1=temp;

 IOCLR1=(1<<17);

 IOCLR1=(1<<18);

 IOSET1=(1<<19);

 delay_ms(2); 

 IOCLR1=(1<<19);

}


void lcd_init(void)

{

 PINSEL2=0;

 IODIR1|=0XFE<<16;

 

 lcd_cmd(0x02);

  lcd_cmd(0x03);

	  lcd_cmd(0x28);

		lcd_cmd(0x0E);

		 lcd_cmd(0x01);

}




void lcd_string(char *p)

{

 while(*p!=0)

  {

	 lcd_data(*p);

	 p++;

	}

}




//

//void lcd_int(int num)

//{

// int arr[10],i=0;

// if(num==0)

//   {

//	  lcd_data('0');

//    return;

//	 }

//	if(num<0)

//	{

//	 lcd_data('-');

//	 num=-num;

//	}

//		i=0;

//		while(num>0)

//		 {

//		  arr[i]=num%10;

//			num=num/10;

//			i++;

//		 }

//		for(--i;i>=0;i--)

//		  {

//			 lcd_data(arr[i]+48);

//			}

//}


