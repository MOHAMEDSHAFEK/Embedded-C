/*
 * EXI_Regster.h
 *
 *  Created on: Jun 17, 2020
 *      Author: shafek
 */

#ifndef COTS_MCAL_EXI_EXI_REGSTER_H_
#define COTS_MCAL_EXI_EXI_REGSTER_H_


#define INT0_VECT     __vector_1

#define INT1_VECT     __vector_2
#define INT2_VECT     __vector_3

#define ISR(vector,...) \
	void vector(void)   __attribute__((signal)) __VA_ARGS__; \
	void vector(void)

#define ISR_NoBlock __attribute__((interrupt))
#define ISR_NAKED __attribute__((naked))
/*
void __vector_1 (void)   __attribute__((signal));

void __vector_2 (void)   __attribute__((signal));

void __vector_3 (void)   __attribute__((signal));
*/

#define MCUCSR *((volatile unsigned char*) 0x54)

#define MCUCR *((volatile unsigned char *)0x55)

#define GICR *((volatile unsigned char *)0x5B)

#define GIFR *((volatile unsigned char *)0x5A)

#endif /* COTS_MCAL_EXI_EXI_REGSTER_H_ */
