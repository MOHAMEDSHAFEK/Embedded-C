/*
 * DIO_TYPE.h
 *
 *  Created on: Jun 3, 2020
 *      Author: shafek
 */

#ifndef COTS_MCAL_DIO_DIO_TYPE_H_
#define COTS_MCAL_DIO_DIO_TYPE_H_
typedef enum {
	INPUT,
	OUTPUT
}DIO_Direction;

typedef enum {
	PORTA,
	PORTB,
	PORTC,
	PORTD

}DIO_PORT_ID;


typedef enum {
	PIN0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7,
}DIO_PIN_ID;
typedef enum {
	INOD,
	CATHOD
}SEVEN_SEGMENT_TYPE;

#endif /* COTS_MCAL_DIO_DIO_TYPE_H_ */
