/*
 * DIO_Regster.h
 *
 *  Created on: Jun 5, 2020
 *      Author: shafek
 */

#ifndef COTS_MCAL_DIO_DIO_REGSTER_H_
#define COTS_MCAL_DIO_DIO_REGSTER_H_


#define PORTA_Reg *((volatile unsigned char*) 0x3B)
#define DDRA_Reg  *((volatile unsigned char*) 0x3A)
#define PINA_Reg  *((volatile unsigned char*) 0x39)

#define PORTB_Reg *((volatile unsigned char*) 0x38)
#define DDRB_Reg  *((volatile unsigned char*) 0x37)
#define PINB_Reg  *((volatile unsigned char*) 0x36)

#define PORTC_Reg *((volatile unsigned char*) 0x35)
#define DDRC_Reg  *((volatile unsigned char*) 0x34)
#define PINC_Reg  *((volatile unsigned char*) 0x33)

#define PORTD_Reg *((volatile unsigned char*) 0x32)
#define DDRD_Reg  *((volatile unsigned char*) 0x31)
#define PIND_Reg  *((volatile unsigned char*) 0x30)



#endif /* COTS_MCAL_DIO_DIO_REGSTER_H_ */
