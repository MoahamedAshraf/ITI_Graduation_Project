/*
 * TMR_priv.h
 *
 *  Created on: Feb 3, 2023
 *      Author: salma
 */

#ifndef TMR_PRIV_H_
#define TMR_PRIV_H_



typedef struct
{
	u32 CR1;
	u32 CR2;
	u32 SMCR;
	u32 DIER;
	u32 SR;
	u32	EGR;
	u32 CCMR1;
	u32	CCMR2;
	u32 CCER;
	u32 CNT;
	u32 PSC;
	u32 ARR;
	u32 RESERVED_1;
	u32 CCR1;
	u32 CCR2;
	u32 CCR3;
	u32 CCR4;
	u32 RESERVED_2;
	u32 DCR;
	u32 DMAR;
	u32 OR;
}TMR_t;


#define TMR2_ADD		((volatile TMR_t *)(0x40000000))
#define TMR3_ADD		((volatile TMR_t *)(0x40000400))
#define TMR4_ADD		((volatile TMR_t *)(0x40000800))
#define TMR5_ADD		((volatile TMR_t *)(0x40000C00))


#define CEN_BIT			0
#define OPM_BIT			3
#define CC1S_SHIFT		0
#define OC1M_SHIFT		4
#define CC2S_SHIFT		8
#define OC2M_SHIFT		12
#define CC3S_SHIFT		0
#define OC3M_SHIFT		4
#define CC4S_SHIFT		8
#define OC4M_SHIFT		12
#define CC1IE_BIT		1
#define CC1P_BIT			1
#define CC1NP_BIT			3
#define CC3P_BIT			9
#define CC3NP_BIT			11
#define CC3EN_BIT			8
#define CC1EN_BIT		0

#define OC1PE_BET
#endif /* TMR_PRIV_H_ */
