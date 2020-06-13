/*
 * DIO_Register.c
 *
 *  Created on: Jun 3, 2020
 *      Author: shafek
 */
#include "../../LIB/STD_TYPE.h"
#include "../../LIB/BIT_MATH.h"
#include "DIO_Regster.h"
#include "DIO_TYPE.h"

void DIO_VidSitPortDirection(DIO_PORT_ID LOC_Port_ID,DIO_Direction LOC_Port_Direction)
{
/*	if(OUTPUT == LOC_Port_Direction)
	{
		switch (LOC_Port_ID)
		{
			case PORTA: DDRA_Reg=0xff; break;
			case PORTB: DDRB_Reg=0xff; break;
			case PORTC: DDRC_Reg=0xff; break;
			case PORTD: DDRD_Reg=0xff; break;
		}
	}
	else if (INPUT == LOC_Port_Direction)
	{
		switch (LOC_Port_ID)
		{
			case PORTA: DDRA_Reg=0x00; break;
			case PORTB: DDRB_Reg=0x00; break;
			case PORTC: DDRC_Reg=0x00; break;
			case PORTD: DDRD_Reg=0x00; break;
		}
	}
}*/
	switch (LOC_Port_ID)
	{
	case 0: DDRA_Reg = LOC_Port_Direction; break;
	case 1: DDRB_Reg = LOC_Port_Direction; break;
	case 2: DDRC_Reg = LOC_Port_Direction; break;
	case 3: DDRD_Reg = LOC_Port_Direction; break;
	}
}

void DIO_VidSitPortValue(DIO_PORT_ID LOC_Port_ID,u8 LOC_Port_Value)
{

			switch (LOC_Port_ID)
			{
				case PORTA: PORTA_Reg=LOC_Port_Value; break;
				case PORTB: PORTB_Reg=LOC_Port_Value; break;
				case PORTC: PORTC_Reg=LOC_Port_Value; break;
				case PORTD: PORTD_Reg=LOC_Port_Value; break;
			}

}

void DIO_VidSitPintDirection(DIO_PORT_ID LOC_Port_ID,DIO_PIN_ID  LOC_Pin_ID,DIO_Direction LOC_Pin_Direction)
{
	if (LOC_Port_ID <=PORTD &&LOC_Pin_ID <= PIN7)
	{
		if(OUTPUT ==LOC_Pin_Direction)
		{
			switch(LOC_Port_ID)
			{
				case PORTA: SET_BIT(DDRA_Reg,LOC_Pin_ID); break;
				case PORTB: SET_BIT(DDRB_Reg,LOC_Pin_ID); break;
				case PORTC: SET_BIT(DDRC_Reg,LOC_Pin_ID); break;
				case PORTD: SET_BIT(DDRD_Reg,LOC_Pin_ID); break;
			}
		}
		if(INPUT ==LOC_Pin_Direction)
		{
			switch(LOC_Port_ID)
			{
				case PORTA: CLR_BIT(DDRA_Reg,LOC_Pin_ID); break;
				case PORTB: CLR_BIT(DDRB_Reg,LOC_Pin_ID); break;
				case PORTC: CLR_BIT(DDRC_Reg,LOC_Pin_ID); break;
				case PORTD: CLR_BIT(DDRD_Reg,LOC_Pin_ID); break;
			}
		}
	}
}

void DIO_VidSitPintValue(DIO_PORT_ID LOC_Port_ID,DIO_PIN_ID  LOC_Pin_ID,STD_Stat LOC_Pin_Value)
{
	if (LOC_Port_ID <=PORTD &&LOC_Pin_ID <= PIN7)
	{
		if(HIGH ==LOC_Pin_Value)
			{
				switch(LOC_Port_ID)
				{
					case PORTA: SET_BIT(PORTA_Reg,LOC_Pin_ID); break;
					case PORTB: SET_BIT(PORTB_Reg,LOC_Pin_ID); break;
					case PORTC: SET_BIT(PORTC_Reg,LOC_Pin_ID); break;
					case PORTD: SET_BIT(PORTD_Reg,LOC_Pin_ID); break;
				}
			}
			if(LOW ==LOC_Pin_Value)
			{
				switch(LOC_Port_ID)
				{
					case PORTA: CLR_BIT(PORTA_Reg,LOC_Pin_ID); break;
					case PORTB: CLR_BIT(PORTB_Reg,LOC_Pin_ID); break;
					case PORTC: CLR_BIT(PORTC_Reg,LOC_Pin_ID); break;
					case PORTD: CLR_BIT(PORTD_Reg,LOC_Pin_ID); break;
				}
			}
	}
}

STD_Stat DIO_GitPinVule(DIO_PORT_ID LOC_Port_ID,DIO_PIN_ID  LOC_Pin_ID)
{
	STD_Stat Pin_Value;
	if (LOC_Port_ID <=PORTD &&LOC_Pin_ID <= PIN7)
	{
		switch (LOC_Port_ID)
		{
			case PORTA: Pin_Value= GET_BIT(PINA_Reg,LOC_Pin_ID); break;
			case PORTB: Pin_Value= GET_BIT(PINB_Reg,LOC_Pin_ID); break;
			case PORTC: Pin_Value= GET_BIT(PINC_Reg,LOC_Pin_ID); break;
			case PORTD: Pin_Value= GET_BIT(PIND_Reg,LOC_Pin_ID); break;
		}
	}

	return Pin_Value;
}
