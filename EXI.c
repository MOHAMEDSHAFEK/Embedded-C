/*
 * EXI.c
 *
 *
 *  Created on: Jun 17, 2020
 *      Author: shafek
 */
#include "../LIB/STD_TYPE.h"
#include "../MCAL/EXI/EXI_TYPE.h"
#include "../MCAL/GIE/GIE_TYPE.h"
#include "../MCAL/DIO/DIO_TYPE.h"
#include "../LIB/BIT_MATH.h"
#include "../HAL/LCD_4BIT/LCD_4BIT_Interface.h"
#include "../MCAL/GIE/GIE_Interface.h"
#include "../MCAL/DIO/DIO_Interface.h"
#include "../MCAL/EXI/EXI_Interface.h"
#include <avr/delay.h>
void EXI (void)
{
	u8 x=1;

	//lcd int
	LCD_Vid4Initialization();
	LCD_Write4String("TEST:",0,0);
	//0
	EXI_VidTrigerEdge(EX_INT0,LOW_LVEL);
	EXI_VidEnable(EX_INT0);
	//1
	EXI_VidTrigerEdge(EX_INT1,LOW_LVEL);
	EXI_VidEnable(EX_INT1);
	//2
	EXI_VidTrigerEdge(EX_INT2,LOW_LVEL);
	EXI_VidEnable(EX_INT2);
	//
	GIE_VidEnable();
	DIO_VidSitPintDirection(PORTB,PIN0, OUTPUT);
	DIO_VidSitPintDirection(PORTB,PIN1, OUTPUT);
	DIO_VidSitPintDirection(PORTB,PIN7, OUTPUT);
	while (1)
	{
		LCD_GoToPosition(1,0);
		LCD_VidDisp4Number(x);
		x++;
		_delay_ms(1000);
		if(x==10)
		{x=1;}
	}
}
