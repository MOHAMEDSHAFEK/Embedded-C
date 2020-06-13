/*
 * dc_motor.c
 *
 *  Created on: Jun 12, 2020
 *      Author: shafek
 */

#include "../LIB/STD_TYPE.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/DIO/DIO_TYPE.h"
#include "../MCAL/DIO/DIO_Interface.h"
#include <avr/delay.h>

void dc_motor (void)

{
	DIO_VidSitPintDirection(PORTB,PIN0,OUTPUT);
	DIO_VidSitPintDirection(PORTB,PIN1,OUTPUT);

while (1)
	{
		DIO_VidSitPintValue(PORTB,PIN0,HIGH);
		DIO_VidSitPintValue(PORTB,PIN1,LOW);
		_delay_ms(2000);
		DIO_VidSitPintValue(PORTB,PIN0,LOW);
		DIO_VidSitPintValue(PORTB,PIN1,LOW);
		_delay_ms(5000);
		DIO_VidSitPintValue(PORTB,PIN0,LOW);
		DIO_VidSitPintValue(PORTB,PIN1,HIGH);
		_delay_ms(2000);
		DIO_VidSitPintValue(PORTB,PIN0,LOW);
		DIO_VidSitPintValue(PORTB,PIN1,LOW);
		_delay_ms(5000);
	}
}
