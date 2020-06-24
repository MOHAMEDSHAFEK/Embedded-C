/*
 * LCD_4BIT.c
 *
 *  Created on: Jun 11, 2020
 *      Author: shafek
 */


#include "../LIB/STD_TYPE.h"
//#include "../LIB/BIT_MATH.h"
//#include "../MCAL/DIO/DIO_TYPE.h"
//#include "../MCAL/DIO/DIO_Interface.h"
#include <avr/delay.h>
#include "../HAL/LCD_4BIT/LCD_4BIT_Interface.h"
//#include "../HAL/LCD/LCD_Interface.h"
void LCD_4BIT(void)
{

	u8 pattern1[]={0x00, 0x00, 0x04, 0x1A, 0x0A, 0x04, 0x00, 0x00};
	u8 pattern2[]={0x00, 0x0C, 0x02, 0x1F, 0x00, 0x00, 0x00, 0x00};
	u8 pattern3[]={0x00, 0x00, 0x04, 0x1B, 0x0A, 0x04, 0x00, 0x00};
	u8 pattern4[]={0x00, 0x04, 0x04, 0x1F, 0x00, 0x00, 0x00, 0x00};
	LCD_Vid4Initialization();
	LCD_Write4String("kaled",0,5);
	LCD_StoreCustomChr(pattern1,0);
	LCD_StoreCustomChr(pattern2,1);
	LCD_StoreCustomChr(pattern3,2);
	LCD_StoreCustomChr(pattern4,3);
	while (1)
	{
		/*LCD_Write4String("kaled",0,0);
		_delay_ms(1000);
		LCD_VidWrite4Cmd(Clear_Display);
		LCD_Write4String("kaled",1,4);
		_delay_ms(1000);
		LCD_VidWrite4Cmd(Clear_Display);
		/*LCD_Write4String("kaled",0,8);
		_delay_ms(1000);
		LCD_VidWrite4Cmd(Clear_Display);
		LCD_Write4String("kaled",1,12);
		_delay_ms(1000);
		LCD_VidWrite4Cmd(Clear_Display);
		LCD_Write4String("kaled",0,11);
		_delay_ms(1000);
		LCD_VidWrite4Cmd(Clear_Display);*/

		/*LCD_VidWrite4Cmd(Clear_Display);
		LCD_Disply(0,0,15);
		LCD_Disply(1,0,14);
		LCD_Disply(2,0,13);
		LCD_Disply(3,0,12);
		_delay_ms(1000);
		LCD_VidWrite4Cmd(Clear_Display);
		LCD_Disply(0,1,10);
		LCD_Disply(1,1,9);
		LCD_Disply(2,1,8);
		LCD_Disply(3,1,7);
		_delay_ms(1000);
		LCD_VidWrite4Cmd(Clear_Display);
		LCD_Disply(0,0,3);
		LCD_Disply(1,0,2);
		LCD_Disply(2,0,1);
		LCD_Disply(3,0,0);
		_delay_ms(1000);*/
		/*LCD_VidArabicNume();
				for(u8 i=15,j=0;i>11;i--,j++)
				{
				LCD_GoToPosition(0,i);
				LCD_VidWrite4Data(j);
				}
				_delay_ms(1000);
				LCD_VidWrite4Cmd(Clear_Display);
				LCD_Vid4ArabicNume();
				LCD_GoToPosition(1,9);
				LCD_VidWrite4Data(0);
				LCD_GoToPosition(1,8);
				LCD_VidWrite4Data(1);
				LCD_GoToPosition(1,7);
				LCD_VidWrite4Data(2);
				LCD_GoToPosition(1,6);
				LCD_VidWrite4Data(3);
				_delay_ms(1000);
				LCD_VidWrite4Cmd(Clear_Display);
				LCD_Vid4ArabicNume();
				LCD_GoToPosition(0,3);
				LCD_VidWrite4Data(0);
				LCD_GoToPosition(0,2);
				LCD_VidWrite4Data(1);
				LCD_GoToPosition(0,1);
				LCD_VidWrite4Data(2);
				LCD_GoToPosition(0,0);
				LCD_VidWrite4Data(3);
				_delay_ms(1000);
				LCD_VidWrite4Cmd(Clear_Display);*/
	}
}
