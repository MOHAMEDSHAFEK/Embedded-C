


/*
 * main.c
 *
 *  Created on: May 30, 2020
 *      Author: MGIsmail
 */
#include "../LIB/STD_TYPE.h"
#include "../MCAL/EXI/EXI_TYPE.h"
#include "../MCAL/GIE/GIE_TYPE.h"
#include "../MCAL/DIO/DIO_TYPE.h"
#include "../LIB/BIT_MATH.h"
#include "../HAL/LCD_4BIT/LCD_4BIT_Interface.h"
#include "../MCAL/GIE/GIE_Interface.h"
#include "../MCAL/DIO/DIO_Interface.h"
#include "../MCAL/ADC/ADC_Interface.h"
#include <avr/delay.h>

void ADC (void)
{

	ADC_VidInit();
	u16 Digital_value=0;
	u16 Analog_value=0;
	DIO_VidSitPintDirection(PORTB,PIN0,OUTPUT);
	DIO_VidSitPintDirection(PORTB,PIN1,OUTPUT);
	DIO_VidSitPintDirection(PORTB,PIN7,OUTPUT);
	while(1)
	{
		Digital_value= ADC_U16GitDigital(0);
		Analog_value=((Digital_value*5000UL)/1024);
		/*if ((Analog_value >= 1500) && (Analog_value <5000))
		{
			DIO_VidSetPinValue(PORTB,PIN0,1);
		}
		else
			DIO_VidSetPinValue(PORTB,PIN0,0);*/

		if ((Analog_value <= 400) )
				{
					DIO_VidSitPintValue(PORTB,PIN7,0);
					DIO_VidSitPintValue(PORTB,PIN1,0);
					DIO_VidSitPintValue(PORTB,PIN0,0);
				}
		else if ((Analog_value > 400)&& (Analog_value <= 1200) )
		{
			DIO_VidSitPintValue(PORTB,PIN7,0);
			DIO_VidSitPintValue(PORTB,PIN1,0);
			DIO_VidSitPintValue(PORTB,PIN0,1);
		}
		else if ((Analog_value > 1200)&& (Analog_value <= 2500))
		{
			DIO_VidSitPintValue(PORTB,PIN7,0);
			DIO_VidSitPintValue(PORTB,PIN0,0);
			DIO_VidSitPintValue(PORTB,PIN1,1);
		}

		else if ((Analog_value > 2500)&& (Analog_value <5000))
		{
			DIO_VidSitPintValue(PORTB,PIN7,1);
			DIO_VidSitPintValue(PORTB,PIN0,0);
			DIO_VidSitPintValue(PORTB,PIN1,0);
		}
	}


}
