/***************************************************************************************/
/* Author               : Mohamed Ashraf                                               */
/* Version              : V0.0.0                                                       */
/* Date                 : 17 - 1 -2023                                                 */
/* Description          : MRCC_Program.c -> Function Implemntation                     */
/* Module Features      :                                                              */
/*        01- MRCC_voidEnablePeripheralClock                                           */
/*        02- MRCC_voidDisablePeripheralClock                                          */
/*        03- MRCC_voidEnableSecuritySystem                                            */
/*        04- MRCC_voidDisableSecuritySystem                                           */
/*        05- MRCC_voidInitSystemClock                                                 */
/*        06- MRCC_voidSetSystemClock                                                  */
/***************************************************************************************/


/***************************************************************************************/
/*                            Standard Types LIB                                       */
/***************************************************************************************/

#include <MRCC_Config.h>
#include <MRCC_Interface.h>
#include <MRCC_Private.h>
#include "LSTD_TYPES.h"
#include "LERROR_STATES.h"
#include "LBIT_MATH.h"


/***************************************************************************************/
/*                                    Lower Layer                                      */
/***************************************************************************************/



/***************************************************************************************/
/*                                    Own Header                                       */
/***************************************************************************************/


/***************************************************************************************/
/*                                    Function Implementation                          */
/***************************************************************************************/

/***************************************************************************************/
/*                         01- MRCC_voidEnablePeripheralClock                          */
/*-------------------------------------------------------------------------------------*/
/* @fu MRCC_voidEnablePeripheralClock                                                  */
/* @brief  This Function used to Enable Clock Peripheral                               */
/* @param[in] Copy_uddtBusName : The bus of the peripheral                             */
/*    [AHB1 - AHB2 - APB1 - APB2] Detect The Required Register                         */
/* @param[in] Copy_u8PerNum : the order of peripheral on selected Reg                  */
/***************************************************************************************/

void MRCC_voidEnablePeripheralClock(BusName_t Copy_uddtBusName, u8  Copy_u8PerNum)
{
	switch(Copy_uddtBusName)
	{
	case AHB1: SET_BIT(MRCC_AHB1ENR,Copy_u8PerNum) ;   break ;
	case AHB2: SET_BIT(MRCC_AHB2ENR,Copy_u8PerNum) ;   break ;
	case APB1: SET_BIT(MRCC_APB1ENR,Copy_u8PerNum) ;   break ;
	case APB2: SET_BIT(MRCC_APB2ENR,Copy_u8PerNum) ;   break ;
	default : /*Error*/                                break ;
	}
}


/***************************************************************************************/
/*                         02- MRCC_voidDisablePeripheralClock                         */
/*-------------------------------------------------------------------------------------*/
/* @fu MRCC_voidDisablePeripheralClock                                                 */
/* @brief  This Function used to Disable Clock Peripheral                              */
/* @param[in] Copy_uddtBusName : The bus of the peripheral                             */
/*    [AHB1 - AHB2 - APB1 - APB2] Detect The Required Register                         */
/* @param[in] Copy_u8PerNum : the order of peripheral on selected Reg                  */
/***************************************************************************************/

void MRCC_voidDisablePeripheralClock(BusName_t Copy_uddtBusName, u8  Copy_u8PerNum)
{
	switch(Copy_uddtBusName)
	{
	case AHB1: CLR_BIT(MRCC_AHB1ENR,Copy_u8PerNum) ;   break ;
	case AHB2: CLR_BIT(MRCC_AHB2ENR,Copy_u8PerNum) ;   break ;
	case APB1: CLR_BIT(MRCC_APB1ENR,Copy_u8PerNum) ;   break ;
	case APB2: CLR_BIT(MRCC_APB2ENR,Copy_u8PerNum) ;   break ;
	default : /*Error*/                                break ;
	}
}
/***************************************************************************************/
/*                         03- MRCC_voidEnableSecuritySystem                           */
/*-------------------------------------------------------------------------------------*/
/* @fu MRCC_voidEnableSecuritySystem                                                   */
/* @brief  This Function used to Enable Clock Security System                          */
/* @param[in] void                                                                     */
/***************************************************************************************/

void MRCC_voidEnableSecuritySystem(void)
{
	SET_BIT(MRCC_CR,19) ;
}

/***************************************************************************************/
/*                         04- MRCC_voidDisableSecuritySystem                          */
/*-------------------------------------------------------------------------------------*/
/* @fu MRCC_voidDisableSecuritySystem                                                  */
/* @brief  This Function used to Disable Clock Security System                         */
/* @param[in] void                                                                     */
/***************************************************************************************/

void MRCC_voidDisableSecuritySystem(void)
{
	CLR_BIT(MRCC_CR,19) ;
}

/***************************************************************************************/
/*                         05- MRCC_voidInitSystemClock                                */
/*-------------------------------------------------------------------------------------*/
/* @fu MRCC_voidInitSystemClock                                                        */
/* @brief  This Function used to initialize the System Clock                           */
/* @param[in] void                                                                     */
/***************************************************************************************/

void MRCC_voidInitSystemClock(void)
{
  /*********************** HSI *********************************/
#if MRCC_CLKSRC == HSI
	/*Step 1 : Enable HSI*/
	SET_BIT(MRCC_CR,0U) ;
	/*Step 2: Wait Till HSI is ready */
	while(GET_BIT(MRCC_CR,1) == 0) ;
	/*Step 3 : Switch to HSI*/
	CLR_BIT(MRCC_CFGR,0U) ;
	CLR_BIT(MRCC_CFGR,1U) ;

#elif MRCC_CLKSRC == HSE
	 /*Step 1 : Enable HSE*/
	 SET_BIT(MRCC_CR,16U) ;
	 /*Step 2 : Wait Till HSI is ready */
	 while(GET_BIT(MRCC_CR,17) == 0) ;
   #if   MRCC_HSE_SRC == HSE_MECH
	 /*Step 3 : Disable BYPass*/
	 CLR_BIT(MRCC_CR,18U) ;
	 /*Step 4 : Switch to HSE*/
	 SET_BIT(MRCC_CFGR,0U) ;
	 CLR_BIT(MRCC_CFGR,1U) ;
   #elif MRCC_HSE_SRC == HSE_RC

		 /*Step 3 : Enable BYPass*/
	    SET_BIT(MRCC_CR,18U) ;
	     /*Step 3 : Switch to HSE*/
	    SET_BIT(MRCC_CFGR,0U) ;
	 	CLR_BIT(MRCC_CFGR,1U) ;
   #else
	/*Error*/
   #endif

#elif MRCC_CLKSRC == PLL
   //TODO
#else
	/*Error*/
#endif
}
