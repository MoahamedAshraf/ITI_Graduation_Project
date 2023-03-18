/*
 * NVIC_Private.h
 *
 *  Created on: 29 Jan 2023
 *      Author: user
 */

#ifndef NVIC_PRIVATE_H_
#define NVIC_PRIVATE_H_

/***********************************************************************************************/
/*************************************** Base Address ******************************************/
/***********************************************************************************************/

#define MNVIC_BASE_ADDRESS		0xE000E100

/***********************************************************************************************/
/*************************************** Register Definition ***********************************/
/***********************************************************************************************/

typedef struct
{
	u32 ISER[8];
	u32 RESERVED_1[24];
	u32 ICER[8];
	u32 RESERVED_2[24];
	u32 ISPR[8];
	u32 RESERVED_3[24];
	u32 ICPR[8];
	u32 RESERVED_4[24];
	u32 IABR[8];
	u32 RESERVED_5[56];
	u32 IPR[60];
	//U8 IPR[240];  (Byte Accessible)
	u32 RESERVED_6[580];
	u32 STIR;

}MNVIC_t;


#define MNVIC 		((volatile MNVIC_t*) (MNVIC_BASE_ADDRESS))

#define SCB_AIRCR   (*(volatile u32*) 0xE000ED0C)

#define VECTKEY     0x05FA0000


#endif /* NVIC_PRIVATE_H_ */
