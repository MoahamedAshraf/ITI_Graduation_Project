/***************************************************************************************/
/*
 * Author 			: Mohamed Ashraf
 * Version			: v0.0
 * Date				: 26/01/2023
 * Description		: MSTK_Private.h -> Register Definitions
 */
/***************************************************************************************/

/***************************************************************************************/
/*  - Developer can't Edit                                                             */
/*                 * Register Definition Design                                        */
/*                         1)  #define : NO                                            */
/*                         2)  Struct  : YES                                           */
/*                         3)  Union   : NO                                            */
/***************************************************************************************/


/***************************************************************************************/
/*                            Guard of file will call on time in c file                */
/***************************************************************************************/

#ifndef MSTK_PRIVATE_H_
#define MSTK_PRIVATE_H_

/***************************************************************************************/
/*                            SysTick_BASE_ADDRESS                					   */
/***************************************************************************************/

#define MSTK_Base_Address	(0xE000E010)

typedef struct
{
	u32 volatile CTRL;
	u32 volatile LOAD;
	u32 volatile VAL;
	u32 volatile CALIB;
}MSTKR_t;


#define MSTK	((MSTKR_t *)(MSTK_Base_Address))






#endif /* MSTK_PRIVATE_H_ */
