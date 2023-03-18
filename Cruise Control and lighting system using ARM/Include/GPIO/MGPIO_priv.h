/***************************************************************************************/
/* Author               : Mohamed Ashraf                                               */
/* Version              : V0.0.0                                                       */
/* Date                 : 22 - 1 -2023                                                 */
/* Description          : MGPIO_Private.h -> Register Definitions                      */
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

#ifndef MGPIO_PRIVATE_H_
#define MGPIO_PRIVATE_H_

/***************************************************************************************/
/*                            GPIO_BASE_ADDRESS                						   */
/***************************************************************************************/

#define MGPIOA_BASE_ADDRESS		(0x40020000)
#define MGPIOB_BASE_ADDRESS		(0x40020400)
#define MGPIOC_BASE_ADDRESS		(0x40020800)


typedef struct
{
	u32 volatile MODER 		;
	u32 volatile OTYPER 	;
	u32 volatile OSPEEDR 	;
	u32 volatile PUPDR 		;
	u32 volatile IDR 		;
	u32 volatile ODR 		;
	u32 volatile BSRR 		;
	u32 volatile LCKR 		;
	u32 volatile AFRL 		;
	u32 volatile AFRH 		;

}MGPIOR_t;

#define MGPIOA 		((MGPIOR_t *) (MGPIOA_BASE_ADDRESS))
#define MGPIOB 		((MGPIOR_t *) (MGPIOB_BASE_ADDRESS))
#define MGPIOC 		((MGPIOR_t *) (MGPIOC_BASE_ADDRESS))














#endif /* MGPIO_PRIVATE_H_ */
