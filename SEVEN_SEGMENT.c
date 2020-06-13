/*
 * SEVEN_SEGMENT.c


 *
 *  Created on: Jun 5, 2020
 *      Author: shafek

 */
#include "../../LIB/STD_TYPE.h"
#include "../../MCAL/DIO/DIO_TYPE.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "SEVEN_SEGMENT.h"

void SEVEN_SEGMENT_INT(void)
{

	 DIO_VidSitPortDirection(PORTA,OUTPUT);
	 DIO_VidSitPortDirection(PORTB,OUTPUT);
	 DIO_VidSitPortDirection(PORTC,OUTPUT);
	 DIO_VidSitPortDirection(PORTD,OUTPUT);

}

void SEVEN_SEGMENT_WRITE(unsigned char number,SEVEN_SEGMENT_TYPE TYPE)
{
	const unsigned char seven_seg_digits[10]={ZERO1,ONE1,TWO1,THREE1,FOUR1,FIVE1,SIX1,SEVEN1,EIGHT1,NINE1};
	unsigned char VALUE;
	if (INOD == TYPE)
	{
		VALUE= ~seven_seg_digits[number];
		DIO_VidSitPortValue(PORTA,VALUE);
	}
	else if (CATHOD == TYPE)
	{
		VALUE= seven_seg_digits[number];
		DIO_VidSitPortValue(PORTA,VALUE);
	}
}

void SEVEN_SEGMENT_CLEAR(void)
{
	DIO_VidSitPortValue(PORTA,clear);
}

