/*
 * EXI_Program.c
 *
 *  Created on: Jun 17, 2020
 *      Author: shafek
 */

#include "../../LIB/STD_TYPE.h"
#include "EXI_TYPE.h"
#include "../../LIB/BIT_MATH.h"
//#include "../../HAL/DIO_FUNCTION/DIO_TYPY1.h"
#include "EXI_Regster.h"
#include "../DIO/DIO_TYPE.h"
#include "../DIO/DIO_Interface.h"
#include "../DIO/DIO_Interface.h"
#include <avr/delay.h>

void EXI_VidEnable(ExInteruptSource LOC_Interupt)

{
	switch (LOC_Interupt)
	{
		case EX_INT0:
			SET_BIT(GICR,INT0);
		break;
		case EX_INT1:
			SET_BIT(GICR,INT1);
		break;
		case EX_INT2:
			SET_BIT(GICR,INT2);
		break;
	}
}

void EXI_VidDisable(ExInteruptSource LOC_Interupt)
{
	switch (LOC_Interupt)
	{
		case EX_INT0: CLR_BIT(GICR,INT0); break;
		case EX_INT1: CLR_BIT(GICR,INT1); break;
		case EX_INT2: CLR_BIT(GICR,INT2); break;
	}
}

void EXI_VidTrigerEdge(ExInteruptSource LOC_Interupt,TriggerEdge_Type LOC_Edge)
{
	switch (LOC_Interupt)
	{
	case EX_INT0:
		DIO_VidSitPintDirection(PORTD,PIN2, INPUT);
		DIO_VidSitPintValue(PORTD,PIN2, HIGH);
		switch (LOC_Edge)
		{
		case LOW_LVEL:
			CLR_BIT(MCUCR,ISC00);
			CLR_BIT(MCUCR,ISC01);
			break;
		case ANY_LOGIC_EDGE:
			SET_BIT(MCUCR,ISC00);
			CLR_BIT(MCUCR,ISC01);
			break;
		case FALLING_EDGE:
			CLR_BIT(MCUCR,ISC00);
			SET_BIT(MCUCR,ISC01);
			break;
		case RISING_EDGE:
			SET_BIT(MCUCR,ISC00);
			SET_BIT(MCUCR,ISC01);
			break;
		}
		break;
	case EX_INT1:
			DIO_VidSitPintDirection(PORTD,PIN3, INPUT);
			DIO_VidSitPintValue(PORTD,PIN3, HIGH);
			switch (LOC_Edge)
			{
			case LOW_LVEL:
				CLR_BIT(MCUCR,ISC00);
				CLR_BIT(MCUCR,ISC01);
				break;
			case ANY_LOGIC_EDGE:
				SET_BIT(MCUCR,ISC00);
				CLR_BIT(MCUCR,ISC01);
				break;
			case FALLING_EDGE:
				CLR_BIT(MCUCR,ISC00);
				SET_BIT(MCUCR,ISC01);
				break;
			case RISING_EDGE:
				SET_BIT(MCUCR,ISC00);
				SET_BIT(MCUCR,ISC01);
				break;
			}
			break;
	case EX_INT2:
			DIO_VidSitPintDirection(PORTB,PIN2, INPUT);
			DIO_VidSitPintValue(PORTB,PIN2, HIGH);
				switch (LOC_Edge)
				{
				case FALLING_EDGE:
					CLR_BIT(MCUCR,ISC2);
					break;
				case RISING_EDGE:
					SET_BIT(MCUCR,ISC2);
					break;
				default:
					CLR_BIT(MCUCR,ISC2);
					break;
				}
				break;
	}

}
ISR(INT0_VECT,ISR_NoBlock)
{
	DIO_VidSitPintValue(PORTB,PIN0, HIGH);
	_delay_ms(2000);
	DIO_VidSitPintValue(PORTB,PIN0, LOW);
}
ISR(INT1_VECT,ISR_NoBlock)
{
	DIO_VidSitPintValue(PORTB,PIN1, HIGH);
	_delay_ms(2000);
	DIO_VidSitPintValue(PORTB,PIN1, LOW);

}
ISR(INT2_VECT)
{
	DIO_VidSitPintValue(PORTB,PIN7, HIGH);
	_delay_ms(2000);
	DIO_VidSitPintValue(PORTB,PIN7, LOW);

}
