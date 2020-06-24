#include "../../LIB/STD_TYPE.h"
#include "GIE_TYPE.h"
#include "../../LIB/BIT_MATH.h"
#include "GIE_Regster.h"


void GIE_VidEnable(void)
{
	SET_BIT(SREG,INTF0);
	/*switch (LOC_Interupt)
	{
		case EXGIE_INT0:
			SET_BIT(SREG,INTF0);
		break;
		case EXGIE_INT1:
			SET_BIT(SREG,INTF0);
		break;
		case EXGIE_INT2:
			SET_BIT(SREG,INTF0);
		break;
	}*/
}
void GIE_VidDisable(void)
{
	CLR_BIT(SREG,INTF0);
    	/*switch (LOC_Interupt)
    	{
    		case EXGIE_INT0:
    			CLR_BIT(SREG,INTF0);
    		break;
    		case EXGIE_INT1:
    			CLR_BIT(SREG,INTF0);
    		break;
    		case EXGIE_INT2:
    			CLR_BIT(SREG,INTF0);
    		break;
    	}*/
}
