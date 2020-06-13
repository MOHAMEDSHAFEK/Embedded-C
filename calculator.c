/*
 * key_pad.c
 *
 *  Created on: Jun 8, 2020
 *      Author: shafek
 */
#include "../../LIB/STD_TYPE.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_TYPE.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include <avr/delay.h>
#include "../../HAL/LCD/LCD_Interface.h"
#include "../../HAL/KEY_PAD/KEY_PAD_Interface.h"

void calculator (void)
{
	u8 number;
	KEY_PAD_VidInit();
	LCD_VidInit();

	//LCD_VidString("result=");
	//LCD_VidDispNumber(1020);
	/*LCD_VidWriteCommand(Clear_Display);
	_delay_ms(2);
	void LCD_VidGotoCGRAM();
	LCD_VidWriteData(0b00000110);
	LCD_VidWriteData(0b00000100);
	LCD_VidWriteData(0b00001110);
	LCD_VidWriteData(0b00000000);
	LCD_VidWriteData(0b00000100);
	LCD_VidWriteData(0b00000100);
	LCD_VidWriteData(0b00000100);
	LCD_VidWriteData(0b00000100);
	LCD_VidWriteData(0b00000000);
	LCD_VidWriteData(0b00000000);
	LCD_VidWriteData(0b00000000);
	LCD_VidWriteData(0b00000000);
	LCD_VidWriteData(0b00001100);
	LCD_VidWriteData(0b00000010);
	LCD_VidWriteData(0b00011111);
	LCD_VidWriteData(0b00000000);
	LCD_VidPostion(0,15);
	LCD_VidWriteData(0);
	LCD_VidPostion(0,14);
	LCD_VidWriteData(1);*/
	while(1)
	{
		number= KEY_PAD_VidGitPresedcalc();
		if (number==43)
		{LCD_VidWriteData('+');}
		else if (number==61)
		{LCD_VidWriteData('=');}
		else if (number==42)
		{LCD_VidWriteData('*');}
		else if (number==45)
		{LCD_VidWriteData('-');}
		else if (number==46)
		{LCD_VidWriteData('.');}
		else if (number==108)
		{LCD_VidWriteData('0');}
		else if (number==99)
		{
			LCD_VidInit();
			/*LCD_VidString("result=");*/
		}
		else
		LCD_VidDispNumber(number);
		/*LCD_VidPostion(0,0);
		LCD_VidString("Mohamed");
		_delay_ms(1000);
		LCD_VidWriteCommand(0b000000001);
		LCD_VidPostion(1,4);
		LCD_VidString("Mohamed");
		_delay_ms(1000);
		LCD_VidWriteCommand(0b000000001);
		LCD_VidPostion(0,9);
		LCD_VidString("Mohamed");
		_delay_ms(1000);
		LCD_VidWriteCommand(0b000000001);*/
	}
}

