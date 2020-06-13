/*
 * LED.c
 *
 *  Created on: Jun 5, 2020
 *      Author: shafek
 */
#include "../LIB/STD_TYPE.h"
#include "../MCAL/DIO/DIO_TYPE.h"
#include "../MCAL/DIO/DIO_Interface.h"
	#include <avr/delay.h>

void LED (void)
{
	DIO_VidSitPintDirection(PORTA,PIN4,OUTPUT);
	while (1)
	{
		DIO_VidSitPintValue(PORTC,PIN0,HIGH);
		_delay_ms(2000);
		DIO_VidSitPintValue(PORTC,PIN0,LOW);
		_delay_ms(1000);
	}
}
