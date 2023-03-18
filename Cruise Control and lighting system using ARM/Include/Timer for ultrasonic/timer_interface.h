/*******************************************************************************************/
/*
 * Author : Mohamed Ashraf
 * Version : V0.0
 * Date : 09/02/2023
 * Description : Timer_Interface.h --> Functions' Prototypes
 * Module Features :
 * 					1) Timer3_voidEnable
 * 					2) Timer3_u16Count
 * 					3) Timer3_voidPrescale
 * 					4) Timer3_voidCapture_Compare_Init
 * 					5) Timer3_voidReadCaptureVal
 *
 */
/*******************************************************************************************/

/***************************************************************************************/
/*                            Guard of file will call on time in c file                */
/***************************************************************************************/

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

/***************************************************************************************/
/*                            Standard Types LIB                                       */
/***************************************************************************************/

#include "LSTD_TYPES.h"
#include "LERROR_STATES.h"
#include "LBIT_MATH.h"

typedef enum
{
	rising,
	falling,
	both_edges,
}CCEdge_t;

/***************************************************************************************/
/*                            Function Protypes                                        */
/***************************************************************************************/


//void Timer2_voidStart(void);
void DCM_PWM_Ctrl(u8 Copy_u8speedlvl);
void Timer2_voidInit(void);
void Timer2_voidPrescale(u16 Copy_u16Prescaler);


void Timer3_voidStart(void);
u16 Timer3_voidStatus(void);
void Timer3_u16Count(u16 Copy_u16Count);
u32  Timer3_voidReadCaptureVal(void);
void Timer3_voidPrescale(u16 Copy_u16Prescaler);
void Timer3_voidCapture_Compare_Init(void);


#endif /* TIMER_INTERFACE_H_ */
