/***************************************************************************************/
/*
 * Author 			: Mohamed Ashraf
 * Version			: v0.0
 *
 * Date				: 26/01/2023
 * Description		: MSTK_Interface.h -> Functions' Prototypes
 * Module Features	:
 * 						1) MSTK_voidInit(void)
 * 						2) MSTK_voidStart(u32 Copy_u32PreloadValue)
 * 						3) MSTK_u8ReadFlag(void)
 * 						4) MSTK_voidINTStatus(u8 Copy_u8INTStatus)
 * 						5) MSTK_voidDelay_ms(u32 Copy_u3Time)
 * 						6) MSTK_voidDelay_us(u32 Copy_u3Time)
 * 						7) MSTK_voidSetCallBack(void(*ptr)void)
 */
/***************************************************************************************/

/***************************************************************************************/
/** What i sell to customer                                                            */
/** The Architecture Give The API                                                      */
/*                    - The Name Of Function                                           */
/*                    - What is The input                                              */
/*                    - What is The Output                                             */
/*                    - Macro                                                          */
/***************************************************************************************/


/***************************************************************************************/
/*                            Guard of file will call on time in c file                */
/***************************************************************************************/

/***************************************************************************************/
/*                            Standard Types LIB                                       */
/***************************************************************************************/


#include "LSTD_TYPES.h"
#include "LERROR_STATES.h"
#include "LBIT_MATH.h"

#ifndef MSTK_INTERFACE_H_
#define MSTK_INTERFACE_H_

/***************************************************************************************/
/*                            Systick Control & Status                                 */
/***************************************************************************************/

typedef enum
{
	ENABLE,
	TICKINT,
	CLKSRC,
	COUNTFLAG
}Ctrl_t;

/***************************************************************************************/
/*                            Systick Control & Status                                 */
/***************************************************************************************/

typedef enum
{
	DIS,
	EN
}INTst_t;

void MSTK_voidInit(void);
void MSTK_voidStart(u32 Copy_u32PreloadValue);
u8 MSTK_u8ReadFlag(void);
void MSTK_voidINTStatus(u8 Copy_u8INTStatus);
void MSTK_voidDelay_ms(u32 Copy_u3Time);
void MSTK_voidDelay_us(u32 Copy_u3Time);
//void MSTK_voidSetCallBack(void (*ptr) (void));




#endif /* MSTK_INTERFACE_H_ */
