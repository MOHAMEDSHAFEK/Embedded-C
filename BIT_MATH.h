/*
 * BIT_MATH.h
 *
 *  Created on: Jun 6, 2020
 *      Author: shafek
 */

#ifndef COTS_LIB_BIT_MATH_H_
#define COTS_LIB_BIT_MATH_H_
#define SET_BIT(VAR,BITNO) (VAR) |=  (1 << (BITNO))
#define CLR_BIT(VAR,BITNO) (VAR) &= ~(1 << (BITNO))
#define TOG_BIT(VAR,BITNO) (VAR) ^=  (1 << (BITNO))
#define GET_BIT(VAR,BITNO) (((VAR) >> (BITNO)) & 0x01)


#endif /* COTS_LIB_BIT_MATH_H_ */
