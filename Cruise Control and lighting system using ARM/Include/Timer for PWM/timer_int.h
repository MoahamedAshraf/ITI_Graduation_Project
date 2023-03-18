/*
 * TMR_int.h
 *
 *  Created on: Feb 3, 2023
 *      Author: salma
 */

#ifndef TMR_INT_H_
#define TMR_INT_H_


typedef enum
{
	TMR2,
	TMR3,
	TMR4,
	TMR5
}TMRN_t;

typedef enum
{
	CH1 = 1,
	CH2,
	CH3,
	CH4
}CHN_t;

typedef enum
{
	FROZEN,
	ACTIVE,
	INACTIVE,
	TOGGLE,
	INACTIVE_FORCE,
	ACTIVE_FORCE,
	PWM_MODE1,
	PWM_MODE2
}CMPFn_t;

typedef enum
{
	OUTPUT,
	IC_T2,
	IC_T1,
	IC_TRC
}CH_MODE_t;

typedef enum
{
	RISIN,
	FALLIN,
	RESERVED,
	BOTH
}EDGE_t;



void TMR_voidStart(TMRN_t Copy_uddtTMR_no);
void TMR_voidStop(TMRN_t Copy_uddtTMR_no);
void TMR_voidSetPrescaler(TMRN_t Copy_uddtTMR_no, u16 Copy_u16Value);
void TMR_voidEnableOPM(TMRN_t Copy_uddtTMR_no);
void TMR_voidCountRst(TMRN_t Copy_uddtTMR_no);
void TMR_voidSetChannelOutput(TMRN_t Copy_uddtTMR_no, CMPFn_t Copy_uddtFn, CHN_t Copy_uddtChNo);
void TMR_voidSetChannelInput(TMRN_t Copy_uddtTMR_no, CHN_t Copy_uddtCH_no);
void TMR_voidSetARR(TMRN_t Copy_uddtTMR_no, u32 Copy_u32Value);
void TMR_voidStop(TMRN_t Copy_uddtTMR_no);
void TMR_voidClearCount(TMRN_t Copy_uddtTMR_no);
void TMR_voidEnableICUInt(TMRN_t Copy_uddtTMR_no);
void TMR_voidSetCMPVal(TMRN_t Copy_uddtTMR_no, CHN_t Copy_uddtChNo, u32 cmpValue);
u32 TMR_voidReadCapture(TMRN_t Copy_uddtTMR_no, CHN_t Copy_uddtChNo);





#endif /* TMR_INT_H_ */
