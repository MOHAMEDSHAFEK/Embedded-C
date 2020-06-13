/*
 * DIO_Interface.h
 *
 *  Created on: Jun 3, 2020
 *      Author: shafek
 */

#ifndef COTS_MCAL_DIO_DIO_INTERFACE_H_
#define COTS_MCAL_DIO_DIO_INTERFACE_H_

void DIO_VidSitPortDirection(DIO_PORT_ID LOC_Port_ID,DIO_Direction LOC_Port_Direction);
void DIO_VidSitPortValue(DIO_PORT_ID LOC_Port_ID,u8 LOC_Port_Value);
void DIO_VidSitPintDirection(DIO_PORT_ID LOC_Port_ID,DIO_PIN_ID  LOC_Pin_ID,DIO_Direction LOC_Pin_Direction);
void DIO_VidSitPintValue(DIO_PORT_ID LOC_Port_ID,DIO_PIN_ID  LOC_Pin_ID,STD_Stat LOC_Pin_Value);
STD_Stat DIO_GitPinVule(DIO_PORT_ID LOC_Port_ID,DIO_PIN_ID  LOC_Pin_ID);

#endif /* COTS_MCAL_DIO_DIO_INTERFACE_H_ */
