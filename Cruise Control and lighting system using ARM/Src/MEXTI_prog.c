/*******************************************************************************************************/
/* Author            : Ahmed khaled Hammad                                                             */
/* Version           : V0.0.0                                                                          */
/* Data              : 23 May 2022                                                                     */
/* Description       : NVIC_Program.c --> implementations                                              */
/* Module  Features  :                                                                                 */
/*      01- MEXTI_voidInit                                                                             */
/*      02- MEXTI_voidEnableEXTI                                                                       */
/*      03- MEXTI_voidDisableEXTI                                                                      */
/*      04- MEXIT_voidSoftwareInterrput                                                                */
/*      05- MEXTI_voidSetSignalLatch                                                                   */
/*      06- EXTI_voidSetCallBack                                                                       */
/*******************************************************************************************************/


/*#####################################################################################################*/
/*#####################################################################################################*/

/*******************************************************************************************************/
/*                                      Standard Types LIB                                             */
/*******************************************************************************************************/

#include "LSTD_TYPES.h"
#include "LERROR_STATES.h"
#include "LBIT_MATH.h"


/*#####################################################################################################*/
/*#####################################################################################################*/

/*******************************************************************************************************/
/*                                      MCAL Components                                                */
/*******************************************************************************************************/

#include "MEXTI_Private.h"
#include "MEXTI_Interface.h"
#include "MEXTI_Config.h"

/*#####################################################################################################*/
/*#####################################################################################################*/

void MEXTI_voidInit(void)
{
	/***************************	FOR_EXTI_LINE	***************************/
	/* Not Good TO Turn On Line At Initlizaion It is POWER Consumption So  */

#if		EXTI_Line ==	Line_0
	SET_BIT(MEXTI->IMR , Line_0) ;

#elif	EXTI_Line ==	Line_1
	SET_BIT(MEXTI->IMR , Line_1) ;

#elif	EXTI_Line ==	Line_2
	SET_BIT(MEXTI->IMR , Line_2) ;

#elif	EXTI_Line ==	Line_3
	SET_BIT(MEXTI->IMR , Line_3) ;

#elif	EXTI_Line ==	Line_4
	SET_BIT(MEXTI->IMR , Line_4) ;

#elif	EXTI_Line ==	Line_5
	SET_BIT(MEXTI->IMR , Line_5) ;

#elif	EXTI_Line ==	Line_6
	SET_BIT(MEXTI->IMR , Line_6) ;

#elif	EXTI_Line ==	Line_7
	SET_BIT(MEXTI->IMR , Line_7) ;

#elif	EXTI_Line ==	Line_8
	SET_BIT(MEXTI->IMR , Line_8) ;

#elif	EXTI_Line ==	Line_9
	SET_BIT(MEXTI->IMR , Line_9) ;

#elif	EXTI_Line ==	Line_10
	SET_BIT(MEXTI->IMR , Line_10) ;

#elif	EXTI_Line ==	Line_11
	SET_BIT(MEXTI->IMR , Line_11) ;

#elif	EXTI_Line ==	Line_12
	SET_BIT(MEXTI->IMR , Line_12) ;

#elif	EXTI_Line ==	Line_13
	SET_BIT(MEXTI->IMR , Line_13) ;

#elif	EXTI_Line ==	Line_14
	SET_BIT(MEXTI->IMR , Line_14) ;

#elif	EXTI_Line ==	Line_15
	SET_BIT(MEXTI->IMR , Line_15) ;

#else

#error "Wrong Mode and Line Choice !!! ";

#endif

}

void MEXTI_voidEnableEXTI(Line_t u8Copy_Line)
{
	SET_BIT(MEXTI -> IMR , u8Copy_Line);

}
void MEXTI_voidDisableEXTI(Line_t u8Copy_Line)
{
	CLR_BIT(MEXTI -> IMR , u8Copy_Line);

}

void MEXTI_voidEventEnable(Line_t u8Copy_Line)
{
	SET_BIT(MEXTI -> EMR , u8Copy_Line);
}
void MEXTI_voidEventDisable(Line_t u8Copy_Line)
{
	CLR_BIT(MEXTI -> EMR , u8Copy_Line);
}

void MEXTI_voidSenseMode(Sense_t u8Copy_Sense)
{
	switch(u8Copy_Sense)
	{

	case RISING : SET_BIT(MEXTI -> RTSR , EXTI_Line); break;

	case FALLING : SET_BIT(MEXTI -> FTSR , EXTI_Line); break;

	case ON_CHANGE :
		SET_BIT(MEXTI -> RTSR , EXTI_Line);
		SET_BIT(MEXTI -> FTSR , EXTI_Line);
		break;

	}

}
void MEXTI_voidSoftwareInterrupt(Line_t u8Copy_Line)
{
	SET_BIT(MEXTI -> SWIER , u8Copy_Line);

}
void MEXTI_voidPendingRegister(Line_t u8Copy_Line)
{
	SET_BIT(MEXTI -> PR , u8Copy_Line);

}
void MEXTI_voidSenseModeAndLine(Sense_t u8Copy_Sense ,Line_t u8Copy_Line )
{
	switch(u8Copy_Sense)
	{
	case RISING : SET_BIT(MEXTI -> RTSR , EXTI_Line); break;

	case FALLING : SET_BIT(MEXTI -> FTSR , EXTI_Line); break;

	case ON_CHANGE :
		SET_BIT(MEXTI -> RTSR , EXTI_Line);
		SET_BIT(MEXTI -> FTSR , EXTI_Line);
		break;
	}

	SET_BIT(MEXTI -> IMR , u8Copy_Line);

}


























