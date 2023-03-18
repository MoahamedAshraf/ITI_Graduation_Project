/***************************************************************************************/
/*
 * Author : Mohamed Ashraf
 * Version : V0.0
 * Date : 09/02/2023
 * Description : Timer_Program.c --> Functions' Implementation
 * Module Features :
 * 					1) Timer3_voidEnable
 * 					2) Timer3_voidPrescale
 * 					3) Timer3_voidCapture_Compare_Init
 *
 */
/***************************************************************************************/



/***************************************************************************************/
/*                            Standard Types LIB                                       */
/***************************************************************************************/

#include "LSTD_TYPES.h"
#include "LERROR_STATES.h"
#include "LBIT_MATH.h"


/***************************************************************************************/
/*                            		MCAL Layer		                                   */
/***************************************************************************************/

#include "Timer_Interface.h"
#include "Timer_Private.h"
#include "Timer_Config.h"


/***************************************************************************************/
/*                            Functions' Implementation                                */
/***************************************************************************************/

void Timer3_voidStart(void)
{


	SET_BIT(Timer3 -> CR1 , 0);		// enable counter

	CLR_BIT(Timer3 -> CR1 , 4);		// counter mode is up counting
}


u16 Timer3_voidStatus(void)
{
	return GET_BIT(Timer3 -> SR , 1);
}


void Timer3_u16Count(u16 Copy_u16Count)
{
	Timer3 -> CNT = Copy_u16Count;	// timer counter initialize
}

u32  Timer3_voidReadCaptureVal(void)
{
	return Timer3 -> CCR1;			// return captured value
}

void Timer3_voidPrescale(u16 Copy_u16Prescaler)
{
	Timer3 -> PSC = Copy_u16Prescaler -1 ;	// prescale timer frequency
}



void Timer3_voidCapture_Compare_Init(void)
{
	/*DIER Register*/

	SET_BIT(Timer3 -> DIER , 1);	// Capture/Compare interrupt enable

	/*CCMR1 Register*/

	SET_BIT(Timer3 -> CCMR1 , 0);	// configure timer3 ch1 as input
	CLR_BIT(Timer3 -> CCMR1 , 1);

	CLR_BIT(Timer3 -> CCMR1 , 2);	// configure timer3 ch1 to capture at every edge detected
	CLR_BIT(Timer3 -> CCMR1 , 3);


	CLR_BIT(Timer3 -> CCMR1 , 6);
	CLR_BIT(Timer3 -> CCMR1 , 7);

	/*CCER Register*/

	SET_BIT(Timer3 -> CCER , 0);	// Capture Enabled


	SET_BIT(Timer3 -> CCER , 1);	// Capture/Compare channel captures on both edges (rising & falling)
	SET_BIT(Timer3 -> CCER , 3);

	Timer3_voidPrescale(72);

	Timer3 -> ARR = 65535;

}


void Timer2_voidPrescale(u16 Copy_u16Prescaler)
{
	Timer2 -> PSC = Copy_u16Prescaler - 1;
}


void Timer2_voidInit(void)
{
	/*Set Prescaler*/

	Timer2_voidPrescale(10);

	/*Set Auto Reload Register Value*/

	Timer2 -> ARR = 26666;

	/*Zero Counter*/

	Timer2 -> CNT = 0;

	/*Set PWM Mode in Capture/Compare Mode Register*/

	SET_BIT(Timer2 -> CCMR1 , 5);
	SET_BIT(Timer2 -> CCMR1 , 6);

	/*Enable PWM CH1*/

	SET_BIT(Timer2 -> CCER , 0);

	/*set pulse width 1/3 of the period */

	Timer2 -> CCR1 = 8889 - 1;

	/*Timer 2 Enable*/

	SET_BIT(Timer2 -> CR1 , 0);
}

void DCM_PWM_Ctrl(u8 Copy_u8speedlvl)
{

}

















