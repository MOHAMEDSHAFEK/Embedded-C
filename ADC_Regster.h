

#ifndef COTS_MCAL_ADC_ADC_REGSTER_H_
#define COTS_MCAL_ADC_ADC_REGSTER_H_

#define  REFS1 7
#define  REFS0 6
#define  ADLAR 5

#define  ADTS2 2
#define  ADTS1 1
#define  ADTS0 0

#define  ADEN 7	  //ENABLE 1
#define  ADSC 6  //ENABLE  1
#define  ADIF 4
#define ADATE  5 //TRIGGER
#define ADIE   3 //ENABLE FLAG


#define ACSR *((volatile unsigned char *)0x28)
#define ADCSRA *((volatile unsigned char *)0x26)
#define ADMUX *((volatile unsigned char *)0x27)
#define ADCH *((volatile unsigned char *)0x25)
#define ADCL *((volatile unsigned char *)0x24)
#define ADC *((volatile unsigned short int *)0x24)

#endif /* COTS_MCAL_ADC_ADC_REGSTER_H_ */
