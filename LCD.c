/*
 * LCD.c
 *
 *  Created on: Jun 6, 2020
 *      Author: shafek
 */

#include "../LIB/STD_TYPE.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/DIO/DIO_TYPE.h"
#include "../MCAL/DIO/DIO_Interface.h"
#include <avr/delay.h>
#include "../HAL/LCD/LCD_Interface.h"


void LCD (void)
{
	LCD_VidInit();
	//LCD_VidWriteData('A');
	//LCD_VidWriteData('52');
	//LCD_VidString("result=");
	//LCD_VidDispNumber(234);
	/*LCD_VidPostion(0,15);
	LCD_VidWriteData(0);
	LCD_VidPostion(0,14);
	LCD_VidWriteData(1);
	LCD_VidPostion(0,13);
	LCD_VidWriteData(2);
	LCD_VidPostion(0,12);
	LCD_VidWriteData(3);*/
	while(1)
	{
		LCD_VidArabicNume();
		for(u8 i=15,j=0;i>11;i--,j++)
		{
		LCD_VidPostion(0,i);
		LCD_VidWriteData(j);
		}
		_delay_ms(1000);
		LCD_VidWriteCommand(Clear_Display);
		LCD_VidArabicNume();
		LCD_VidPostion(1,9);
		LCD_VidWriteData(0);
		LCD_VidPostion(1,8);
		LCD_VidWriteData(1);
		LCD_VidPostion(1,7);
		LCD_VidWriteData(2);
		LCD_VidPostion(1,6);
		LCD_VidWriteData(3);
		_delay_ms(1000);
		LCD_VidWriteCommand(Clear_Display);
		LCD_VidArabicNume();
		LCD_VidPostion(0,3);
		LCD_VidWriteData(0);
		LCD_VidPostion(0,2);
		LCD_VidWriteData(1);
		LCD_VidPostion(0,1);
		LCD_VidWriteData(2);
		LCD_VidPostion(0,0);
		LCD_VidWriteData(3);
		_delay_ms(1000);
		LCD_VidWriteCommand(Clear_Display);
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
