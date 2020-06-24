
#include "../../LIB/STD_TYPE.h"
#include "../../LIB/BIT_MATH.h"
#include "ADC_Regster.h"

/*
 #define  REFS1 7
#define  REFS0 6
#define  ADLAR 5

#define  ADTS2 2
#define  ADTS1 1
#define  ADTS0 0
 *
 */
void ADC_VidInit(void)

{
	SET_BIT(ADMUX,REFS0);
	CLR_BIT(ADMUX,REFS1);              //V reference
	
	CLR_BIT(ADMUX,ADLAR);             //right adjast
	
	SET_BIT(ADCSRA,ADTS2);
	SET_BIT(ADCSRA,ADTS1);
	CLR_BIT(ADCSRA,ADTS0);	         //Prescaler
	
	
	SET_BIT(ADCSRA,ADEN);            //enable ADC when it's running in the initialization it's will running in sleep mode

	
}

u16 ADC_U16GitDigital(u8 LOC_Channel)
{
	ADMUX&=0b11100000;               //singel ended
	ADMUX|=LOC_Channel;              //number of channel by user

	SET_BIT(ADCSRA,ADSC);           //Start Conversion
	while(0==GET_BIT(ADCSRA,ADIF))  //if ADC interrupt flag=0 waite until be one
	{
	}
	SET_BIT(ADCSRA,ADIF);           //reset the interrupt flag over write one to be zero
    return ADC;

}
