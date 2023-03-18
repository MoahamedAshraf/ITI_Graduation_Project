/***************************************************************************************/
/*
 * Author 			: Mohamed Ashraf
 * Version			: v0.0
 *
 * Date				: 26/01/2023
 * Description		: MSTK_Program.c -> Functions' Implementation
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
/*                            Standard Types LIB                                       */
/***************************************************************************************/

#include <MSTK_Config.h>
#include <MSTK_Interface.h>
#include <MSTK_Private.h>
#include "LSTD_TYPES.h"
#include "LERROR_STATES.h"
#include "LBIT_MATH.h"



/***************************************************************************************/
/*                            Functions Implementation                                 */
/***************************************************************************************/


static void (*MSTK_CallBack)(void)  ;

// calling by Hardware if interrupt happens
void SysTick_Handler(void)
{
	// Execute CallBack Function
	MSTK_CallBack() ;
}


void MSTK_voidInit(void)
{
	/* [Enable Systick Interrupt - clock = AHB/8 - Stop Systick]*/

	CLR_BIT(MSTK -> CTRL ,0);
	SET_BIT(MSTK -> CTRL ,1);
	CLR_BIT(MSTK -> CTRL ,2);

}





void MSTK_voidStart(u32 Copy_u32PreloadValue)
{
	//if F_CPU -> HSI = 16MHz , AHB = 16 MHz , F_Timer = AHB/8 = 2 MHz
	// 0.5 us for each count

	//Step 1: Load Value

	MSTK -> LOAD = Copy_u32PreloadValue;

	//Step 2: Clear Val Reg

	MSTK -> VAL = 0;

	//Step 3: Enable Systick

	SET_BIT(MSTK -> CTRL ,0);

}


u8 MSTK_u8ReadFlag(void)
{
	//Step 1 : Get Count Flag

	return GET_BIT(MSTK -> CTRL , 16);

}


void MSTK_voidINTStatus(INTst_t Copy_u8INTStatus)
{
	switch (Copy_u8INTStatus)
	{
	case EN :
		// Set the Bit of interrupt with the input
		SET_BIT(MSTK -> CTRL ,1); break;
	case DIS :
		// Clear Bit of Interrupt
		CLR_BIT(MSTK -> CTRL,1); break;
	}

}
void MSTK_voidDelay_ms(u32 Copy_u3Time)
{
	//Step 1 : Init Systick

	MSTK_voidInit();

	//Step 2 : Disable INT

	MSTK_voidINTStatus(DIS);

	//Step 3 : Start Systick( Copy_u32Time )

	MSTK_voidStart(Copy_u3Time * 2000);

	//Step 4 : Wait Flag Polling */

	while(MSTK_u8ReadFlag() == 0);



}


void MSTK_voidDelay_us(u32 Copy_u3Time)
{
	//Step 1 : Init Systick

	MSTK_voidInit();

	//Step 2 : Disable INT

	MSTK_voidINTStatus(DIS);

	//Step 3 : Start Systick( Copy_u32Time )

	MSTK_voidStart(Copy_u3Time * 2);

	//Step 4 : Wait Flag Polling */

	while(MSTK_u8ReadFlag() == 0);

}


void MSTK_voidSetCallBack(void (*ptr) (void))
{
	MSTK_CallBack = ptr ;

}





























