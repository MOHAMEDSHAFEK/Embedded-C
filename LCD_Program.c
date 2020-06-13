
#include "../../LIB/STD_TYPE.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_TYPE.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "avr/delay.h"
#include "../../MCAL/DIO/DIO_Regster.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "LCD_Interface.h"

void LCD_VidInit(void)
{
	_delay_ms(50); // wait for LCD to initialize
	DIO_VidSitPortDirection(LCD_PORT, 0xff);
	//DIO_VidSetPortDirection(PORTB, 0b00111000 ); //RS RW E
	DIO_VidSitPintDirection(LCD_INIT,LCD_RS,1);   //RS
	DIO_VidSitPintDirection(LCD_INIT,LCD_RW,1);   //RW
	DIO_VidSitPintDirection(LCD_INIT,LCD_EN,1);   //EN
/**/


	LCD_VidWriteCommand(function_set_8_bit_lcd); 	//function set
	_delay_ms(1); // wait for LCD to Function set
	LCD_VidWriteCommand(Display_On_Cursor_OFF);	//Display On
	_delay_ms(1); // wait for LCD to Display On
	LCD_VidWriteCommand(Clear_Display);	//Clear Display
	_delay_ms(2); // wait for LCD to Clear Display

}

void LCD_VidWriteCommand(u8 LOC_u8Command)
{
	DIO_VidSitPintValue(LCD_INIT, LCD_RS, LOW);  //RS = 0   register selection
	DIO_VidSitPintValue(LCD_INIT, LCD_RW, LOW);  //RW = 0
	DIO_VidSitPortValue(LCD_PORT, LOC_u8Command);  // Write Command
	DIO_VidSitPintValue(LCD_INIT, LCD_EN, HIGH);  //Enable = 1 high rise edge
	_delay_ms(1);	// required by LCD Datasheet
	DIO_VidSitPintValue(LCD_INIT, LCD_EN, LOW);  //Enable = 0  Falling edge
	_delay_ms(1); // give the LCD time to wite / display
}

void LCD_VidWriteData(u8 LOC_u8Data)
{
	DIO_VidSitPintValue(LCD_INIT, LCD_RS, HIGH);  //RS = 0
	DIO_VidSitPintValue(LCD_INIT, LCD_RW, LOW);  //RW = 0
	DIO_VidSitPortValue(LCD_PORT, LOC_u8Data);  // Write data
	DIO_VidSitPintValue(LCD_INIT, LCD_EN, HIGH);  //Enable = 1 high rise edge
	_delay_ms(1);	// required by LCD Datasheet
	DIO_VidSitPintValue(LCD_INIT, LCD_EN, LOW);  //Enable = 0  Falling edge
	_delay_ms(1); // give the LCD time to wite / display

}

void LCD_VidString(u8* LOC_USER)
{
	u8 i=0;
	while(LOC_USER[i] !='\0')
	{
		LCD_VidWriteData(LOC_USER[i]);
		_delay_ms(2);
		i++;
	}
}

void LCD_VidDispNumber(u32 number)
{
/*	u32 revesed=0;

	u32 digit;
	while (number>0)
	{

		revesed=(revesed*10)+number%10;
		number=number/10;

	}
	while (revesed>0)
	{
		digit=revesed%10;
		LCD_VidWriteData(digit+48);
		revesed=revesed/10;
	}
*/
	u32 digit=0;
	u16 i=0;
	u32 f=0;
	u8 number_holder[10];

	while(number>0)
	{
		f=number%10;
		number_holder[i]=f;
		number=number/10;
		i++;
		digit++;
		if(number==0)
		{break;}
	}
	for(i=digit;i>0;i--)
	{
		LCD_VidWriteData(number_holder[i-1]+48);
	}
	/*if(number==0)
	{LCD_VidWriteData(48);}*/

}
void LCD_VidPostion(u8 row,u8 colm)
{
	if(row==0)
	{
		LCD_VidWriteCommand(DDRAM_address_row_one_lcd+colm);  //DDRAM address row one lcd
		_delay_ms(1);
	}
	else if(row==1)
		{
			LCD_VidWriteCommand(DDRAM_address_row_two_lcd+colm); //DDRAM address row two lcd
			_delay_ms(1);
		}

}
void LCD_VidGotoCGRAM()
{
	LCD_VidWriteCommand(SET_CGRAM_ADDRESS);
}

void LCD_VidArabicNume(void)
{
	LCD_VidGotoCGRAM();
	//أ
	/*LCD_VidWriteData(0b00000110);
	LCD_VidWriteData(0b00000100);
	LCD_VidWriteData(0b00001110);
	LCD_VidWriteData(0b00000000);
	LCD_VidWriteData(0b00000100);
	LCD_VidWriteData(0b00000100);
	LCD_VidWriteData(0b00000100);
	LCD_VidWriteData(0b00000100);*/
	LCD_VidWriteData(0b00000000);
	LCD_VidWriteData(0b00000000);
	LCD_VidWriteData(0b00000100);
	LCD_VidWriteData(0b00001010);
	LCD_VidWriteData(0b00011010);
	LCD_VidWriteData(0b00001010);
	LCD_VidWriteData(0b00000100);
	LCD_VidWriteData(0b00000000);
	//ح
	LCD_VidWriteData(0b00000000);
	LCD_VidWriteData(0b00000000);
	LCD_VidWriteData(0b00001100);
	LCD_VidWriteData(0b00000010);
	LCD_VidWriteData(0b00011111);
	LCD_VidWriteData(0b00000000);
	LCD_VidWriteData(0b00000000);
	LCD_VidWriteData(0b00000000);
	//م
	LCD_VidWriteData(0b00000000);
	LCD_VidWriteData(0b00000000);
	LCD_VidWriteData(0b00000100);
	LCD_VidWriteData(0b00001010);
	LCD_VidWriteData(0b00011011);
	LCD_VidWriteData(0b00001010);
	LCD_VidWriteData(0b00000100);
	LCD_VidWriteData(0b00000000);
	//د
	LCD_VidWriteData(0b00000000);
	LCD_VidWriteData(0b00000000);
	LCD_VidWriteData(0b00000100);
	LCD_VidWriteData(0b00000100);
	LCD_VidWriteData(0b00011111);
	LCD_VidWriteData(0b00000000);
	LCD_VidWriteData(0b00000000);
	LCD_VidWriteData(0b00000000);
}

