/*******************************************************************************************************/
/* Author            : Mohamed Ashraf                                                             	   */
/* Version           : V0.0.0                                                                          */
/* Data              : 23 May 2022                                                                     */
/* Description       : NVIC_Interface.c --> implementations                                            */
/* Module  Features  :                                                                                 */
/*      01- MNVIC_voidEnableInterrupt                                                                  */
/*      02- MNVIC_voidDisableInterrupt                                                                 */
/*      03- MNVIC_voidEnableInterruptPending                                                           */
/*      04- MNVIC_voidDisableInterruptPinding                                                          */
/*      05- MNVIC_u8IsInterruptActive                                                                  */
/*      06- MNVIC_voidInitInterruptGroup                                                               */
/*      07- MNVIC_voidSetInterruptPriority                                                             */
/*      08- MNVIC_voidGenerateSoftwareInterrupt                                                        */
/*******************************************************************************************************/

/*******************************************************************************************************/
/*	* What i sell To Customer                                                                          */
/*		*  The Archictect Give The API	                                                               */
/*						- The Name Of Function                                                         */
/*						- What is The Input                                                            */
/*						- What Is The Output                                                           */
/*						- Macro                                                                        */
/*******************************************************************************************************/

/*******************************************************************************************************/
/*                                   guard of file will call on time in .c                             */
/*******************************************************************************************************/

#include "LSTD_TYPES.h"
#include "LERROR_STATES.h"
#include "LBIT_MATH.h"


#ifndef NVIC_INTERFACE_H_
#define NVIC_INTERFACE_H_

typedef enum
{
 NVIC_GROUP_MODE_G16S0 = 3 ,
 NVIC_GROUP_MODE_G8S2      ,
 NVIC_GROUP_MODE_G4S4      ,
 NVIC_GROUP_MODE_G2S8      ,
 NVIC_GROUP_MODE_G0S16
}NVIC_GroupMode_t ;

typedef struct
{
	u8 Copy_u8IntNum ;
	NVIC_GroupMode_t Copy_uddtGroupMode ;
	u8 Copy_GroupPriority  ;
	u8 Copy_SubPriority  ;

}NVIC_PriorityConfig_t ;

/*******************************************************************/
/********************** Function ProtoTypes ************************/
/*******************************************************************/

void MNVIC_voidEnableInterrupt(u8 Copy_u8IntNum) ;
void MNVIC_voidDisableInterrupt(u8 Copy_u8IntNum) ;
void MNVIC_voidEnableInterruptPending(u8 Copy_u8IntNum) ;
void MNVIC_voidDisableInterruptPending(u8 Copy_u8IntNum) ;
u8   MNVIC_u8InterruptActive(u8 Copy_u8IntNum)           ;
void MNVIC_voidInitInterruptGroup(NVIC_GroupMode_t Copy_uddtGroupMode)    ;
void MNVIC_voidSetInterruptPriority(u8 Copy_u8IntNum ,NVIC_GroupMode_t Copy_uddtGroupMode,u8 Copy_GroupPriority,u8 Copy_SubPriority) ;
//void MNVIC_voidSetInterruptPriority(NVIC_PriorityConfig_t* Copy_PuddtPriorityConfig) ;
void MNVIC_voidGenerateSoftwareInterrupt(u8 copy_u8IntNum);

/**
 * in main :
 *
 *
 * NVIC_PriorityConfig_t EXTI0_Priority = {6, NVIC_GROUP_MODE_G16S0 , 5 , 0} ;
 *
 * MNVIC_voidSetInterruptPriority(&EXTI0_Priority) ;
 *
 *
 * */

/*
 * in program.c
 *
 * void MNVIC_voidSetInterruptPriority(NVIC_PriorityConfig_t* Copy_PuddtPriorityConfig)
 * {
 *
 *   IPR0 = Copy_PuddtPriorityConfig->Copy_u8IntNum ;
 *   AIRCR =  Copy_PuddtPriorityConfig->Copy_uddtGroupMode;
 *
 *
 * }
 *
 * */



#endif /* NVIC_INTERFACE_H_ */
