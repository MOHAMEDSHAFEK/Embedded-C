/*
 * SEVEN_SEGMENT.h
 *
 *  Created on: Jun 5, 2020
 *      Author: shafek
 */

#ifndef COTS_HAL_SEVEN_SEGMENT_SEVEN_SEGMENT_H_
#define COTS_HAL_SEVEN_SEGMENT_SEVEN_SEGMENT_H_
#define ZERO1  	0b00111111
#define ONE1   	0b00000110
#define TWO1   	0b01011011
#define THREE1 	0b01001111
#define FOUR1  	0b01100110
#define FIVE1  	0b01101101
#define SIX1   	0b01111101
#define SEVEN1 	0b00000111
#define EIGHT1 	0b01111111
#define NINE1  	0b01101111
#define clear   0b11111111

#define ZERO  	0
#define ONE   	1
#define TWO   	2
#define THREE 	3
#define FOUR  	4
#define FIVE  	5
#define SIX   	6
#define SEVEN 	7
#define EIGHT 	8
#define NINE  	9
void SEVEN_SEGMENT_INT(void);

void SEVEN_SEGMENT_WRITE(unsigned char number,SEVEN_SEGMENT_TYPE TYPE);
void SEVEN_SEGMENT_CLEAR(void);

#endif /* COTS_HAL_SEVEN_SEGMENT_SEVEN_SEGMENT_H_ */
