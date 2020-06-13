/*
 * SEGMENT.c


 *
 *  Created on: Jun 5, 2020
 *      Author: shafek
*/
#include "../LIB/STD_TYPE.h"
#include "../MCAL/DIO/DIO_TYPE.h"
#include "../MCAL/DIO/DIO_Interface.h"
#include "../HAL/SEVEN_SEGMENT/SEVEN_SEGMENT.h"
#include <avr/delay.h>

void SEGMENT(void)
{
	unsigned char i;
	SEVEN_SEGMENT_INT();
	DIO_VidSitPintDirection(PORTC,PIN0, OUTPUT);
	DIO_VidSitPintDirection(PORTC,PIN1, OUTPUT);
	DIO_VidSitPintDirection(PORTC,PIN2, OUTPUT);
	DIO_VidSitPintDirection(PORTC,PIN7, INPUT);
	DIO_VidSitPintDirection(PORTC,PIN6, INPUT);
	DIO_VidSitPintValue(PORTC,PIN7, HIGH);
	DIO_VidSitPintValue(PORTC,PIN6, HIGH);

	while (1)
	{
		if ((DIO_GitPinVule(PORTC,PIN7)==LOW))
		{
			SEVEN_SEGMENT_CLEAR();
			DIO_VidSitPintValue(PORTC,PIN0, HIGH);
			DIO_VidSitPintValue(PORTC,PIN1, LOW);
			_delay_ms(1000);
			DIO_VidSitPintValue(PORTC,PIN0, LOW);
			DIO_VidSitPintValue(PORTC,PIN1, HIGH);
			_delay_ms(1000);
			DIO_VidSitPintValue(PORTC,PIN0, LOW);
			DIO_VidSitPintValue(PORTC,PIN1, LOW);
			DIO_VidSitPintValue(PORTC,PIN2, HIGH);
			_delay_ms(1000);
		}
			else if ((DIO_GitPinVule(PORTC,PIN7)==HIGH))
			{
				{
					DIO_VidSitPintValue(PORTC,PIN0, LOW);
					DIO_VidSitPintValue(PORTC,PIN1, LOW);
					DIO_VidSitPintValue(PORTC,PIN2, LOW);
					for(i=0;i<10;i++)
					{
						SEVEN_SEGMENT_WRITE(i,INOD);
						_delay_ms(1000);
						if (i==9)
						{
							break;
						}
					}
				}
			}
	}
}

