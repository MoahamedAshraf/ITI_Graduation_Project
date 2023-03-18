/***************************************************************************************/
/* Author               : Mohamed Ashraf                                               */
/* Version              : V0.0.0                                                       */
/* Date                 : 17 - 1 -2023                                                 */
/* Description          : MRCC_Interface.h -> Function Prototypes                      */
/* Module Features      :                                                              */
/*        01- MRCC_voidEnablePeripheralClock                                           */
/*        02- MRCC_voidDisablePeripheralClock                                          */
/*        03- MRCC_voidEnableSecuritySystem                                            */
/*        04- MRCC_voidDisableSecuritySystem                                           */
/*        05- MRCC_voidInitSystemClock                                                 */
/*        06- MRCC_voidSetSystemClock                                                  */
/***************************************************************************************/

/***************************************************************************************/
/*          * What i sell to customer                                                  */
/*                        * The Architecture Give The API                              */
/*                                           - The Name Of Function                    */
/*                                           - What is The input                       */
/*                                           - What is The Output                      */
/*                                           - Macro                                   */
/***************************************************************************************/


/***************************************************************************************/
/*                            Guard of file will call on time in c file                */
/***************************************************************************************/

#ifndef MRCC_INTERFACE_H_
#define MRCC_INTERFACE_H_


/***************************************************************************************/
/*                            Standard Types LIB                                       */
/***************************************************************************************/

#include "LSTD_TYPES.h"
#include "LERROR_STATES.h"
#include "LBIT_MATH.h"

/***************************************************************************************/
/*                                   BusName                                           */
/***************************************************************************************/


typedef enum
{
	AHB1 	 ,
	AHB2     ,
	APB1     ,
	APB2
}BusName_t;

/***************************************************************************************/
/*                            Function Protypes                                        */
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

void MRCC_voidEnablePeripheralClock(BusName_t Copy_uddtBusName, u8  Copy_u8PerNum) ;


/***************************************************************************************/
/*                         02- MRCC_voidDisablePeripheralClock                         */
/*-------------------------------------------------------------------------------------*/
/* @fu MRCC_voidDisablePeripheralClock                                                 */
/* @brief  This Function used to Disable Clock Peripheral                              */
/* @param[in] Copy_uddtBusName : The bus of the peripheral                             */
/*    [AHB1 - AHB2 - APB1 - APB2] Detect The Required Register                         */
/* @param[in] Copy_u8PerNum : the order of peripheral on selected Reg                  */
/***************************************************************************************/

void MRCC_voidDisablePeripheralClock(BusName_t Copy_uddtBusName, u8  Copy_u8PerNum) ;
/***************************************************************************************/
/*                         03- MRCC_voidEnableSecuritySystem                           */
/*-------------------------------------------------------------------------------------*/
/* @fu MRCC_voidEnableSecuritySystem                                                   */
/* @brief  This Function used to Enable Clock Security System                          */
/* @param[in] void                                                                     */
/***************************************************************************************/

void MRCC_voidEnableSecuritySystem(void) ;

/***************************************************************************************/
/*                         04- MRCC_voidDisableSecuritySystem                          */
/*-------------------------------------------------------------------------------------*/
/* @fu MRCC_voidDisableSecuritySystem                                                  */
/* @brief  This Function used to Disable Clock Security System                         */
/* @param[in] void                                                                     */
/***************************************************************************************/

void MRCC_voidDisableSecuritySystem(void) ;

/***************************************************************************************/
/*                         05- MRCC_voidInitSystemClock                                */
/*-------------------------------------------------------------------------------------*/
/* @fu MRCC_voidInitSystemClock                                                        */
/* @brief  This Function used to initialize the System Clock                           */
/* @param[in] void                                                                     */
/***************************************************************************************/

void MRCC_voidInitSystemClock(void) ;


/***************************************************************************************/
/*                      MACROS of : RCC AHB1 CLOCK  Enable                             */
/***************************************************************************************/

#define MRCC_PERIPHERIAL_EN_GPIOA       0U
#define MRCC_PERIPHERIAL_EN_GPIOB       1U
#define MRCC_PERIPHERIAL_EN_GPIOC       2U
#define MRCC_PERIPHERIAL_EN_GPIOD       3U
#define MRCC_PERIPHERIAL_EN_GPIOE       4U
#define MRCC_PERIPHERIAL_EN_GPIOH       7U
#define MRCC_PERIPHERIAL_EN_CRC         12U
#define MRCC_PERIPHERIAL_EN_DMA1        21U
#define MRCC_PERIPHERIAL_EN_DMA2        22U

/***************************************************************************************/
/*                      MACROS of : RCC AHB2 CLOCK  Enable                             */
/***************************************************************************************/

#define MRCC_PERIPHERIAL_EN_USB_OTG_FS       	0U

/***************************************************************************************/
/*                      MACROS of : RCC APB1 CLOCK  Enable                             */
/***************************************************************************************/


#define MRCC_PERIPHERIAL_EN_TIM2       			0U
#define MRCC_PERIPHERIAL_EN_TIM3       			1U
#define MRCC_PERIPHERIAL_EN_TIM4       			2U
#define MRCC_PERIPHERIAL_EN_TIM5       			3U
#define MRCC_PERIPHERIAL_EN_RTC_BKP       		10U
#define MRCC_PERIPHERIAL_EN_WWDG       			11U
#define MRCC_PERIPHERIAL_EN_IWDG         		12U
#define MRCC_PERIPHERIAL_EN_I2S2ext        		13U
#define MRCC_PERIPHERIAL_EN_SPI2_I2S2        	14U
#define MRCC_PERIPHERIAL_EN_SPI3_I2S3        	15U
#define MRCC_PERIPHERIAL_EN_I2S3ext        		16U
#define MRCC_PERIPHERIAL_EN_USART2        		17U
#define MRCC_PERIPHERIAL_EN_I2C1        		21U
#define MRCC_PERIPHERIAL_EN_I2C2        		22U
#define MRCC_PERIPHERIAL_EN_I2C3        		23U
#define MRCC_PERIPHERIAL_EN_PWR        			29U



/***************************************************************************************/
/*                      MACROS of : RCC APB2 CLOCK  Enable                             */
/***************************************************************************************/


#define MRCC_PERIPHERIAL_EN_TIM1       			0U
#define MRCC_PERIPHERIAL_EN_USART1       		4U
#define MRCC_PERIPHERIAL_EN_USART6      		5U
#define MRCC_PERIPHERIAL_EN_ADC1       			8U
#define MRCC_PERIPHERIAL_EN_SDIO       			11U
#define MRCC_PERIPHERIAL_EN_SPI1       			12U
#define MRCC_PERIPHERIAL_EN_SPI4         		13U
#define MRCC_PERIPHERIAL_EN_SYSCFG        		14U
#define MRCC_PERIPHERIAL_EN_EXTI        		15U
#define MRCC_PERIPHERIAL_EN_TIM9        		16U
#define MRCC_PERIPHERIAL_EN_TIM10        		17U
#define MRCC_PERIPHERIAL_EN_TIM11        		18U

#endif /* MRCC_INTERFACE_H_ */
