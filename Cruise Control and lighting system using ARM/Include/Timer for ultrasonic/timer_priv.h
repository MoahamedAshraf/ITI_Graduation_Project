/*
 * Author 		:	Mohamed Ashraf
 * Version 		:	V0.0
 * Date 		:	09/02/2023
 * Description 	:	Timer_Private.h --> Registers Definition
 *
 */

/***************************************************************************************/
/*                            Guard of file will call on time in c file                */
/***************************************************************************************/

#ifndef TIMER_PRIVATE_H_
#define TIMER_PRIVATE_H_

/***************************************************************************************/
/* 							Timers Base Addresses									   */
/***************************************************************************************/

#define Timer2_BASE_ADDRESS		(0x40000000)
#define Timer3_BASE_ADDRESS		(0x40000400)

typedef struct
{
	u32	volatile CR1		;
	u32	volatile CR2		;
	u32 volatile SMCR		;
	u32 volatile DIER		;
	u32 volatile SR			;
	u32 volatile EGR		;
	u32 volatile CCMR1		;
	u32 volatile CCMR2		;
	u32 volatile CCER		;
	u32 volatile CNT		;
	u32 volatile PSC		;
	u32 volatile ARR		;
	u32 volatile RESERVED_1	;
	u32 volatile CCR1		;
	u32 volatile CCR2		;
	u32 volatile CCR3		;
	u32 volatile CCR4		;
	u32 volatile RESERVED_2	;
	u32 volatile DCR		;
	u32 volatile DMAR		;
	u32 volatile QR			;

}TIMR_t;

#define Timer3		((TIMR_t *) (Timer3_BASE_ADDRESS))
#define Timer2		((TIMR_t *) (Timer2_BASE_ADDRESS))

#endif /* TIMER_PRIVATE_H_ */
