/*
* TMR_porg.c
 *
 *  Created on: Feb 3, 2023
 *      Author: salma
 */
#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "TMR_priv.h"
#include "TMR_int.h"




void TMR_voidStart(TMRN_t Copy_uddtTMR_no)
{
	switch(Copy_uddtTMR_no)
	{
	case TMR2:
		SET_BIT(TMR2_ADD -> CR1, CEN_BIT); break;
	case TMR3:
		SET_BIT(TMR3_ADD -> CR1, CEN_BIT); break;
	case TMR4:
		SET_BIT(TMR4_ADD -> CR1, CEN_BIT); break;
	case TMR5:
		SET_BIT(TMR5_ADD -> CR1, CEN_BIT); break;

	default:                               break;
	}
}

void TMR_voidStop(TMRN_t Copy_uddtTMR_no)
{
	switch(Copy_uddtTMR_no)
	{
	case TMR2:
		CLR_BIT(TMR2_ADD -> CR1, CEN_BIT); break;
	case TMR3:
		CLR_BIT(TMR3_ADD -> CR1, CEN_BIT); break;
	case TMR4:
		SET_BIT(TMR4_ADD -> CR1, CEN_BIT); break;
	case TMR5:
		CLR_BIT(TMR5_ADD -> CR1, CEN_BIT); break;

	default:                               break;
	}
}

void TMR_voidSetPrescaler(TMRN_t Copy_uddtTMR_no, u16 Copy_u16Value)
{
	switch(Copy_uddtTMR_no)
	{
	case TMR2:
		Clr_ALL_BITS(TMR2_ADD -> PSC);
		TMR2_ADD -> PSC |= Copy_u16Value;
		break;
	case TMR3:
		Clr_ALL_BITS(TMR3_ADD -> PSC);
		TMR3_ADD -> PSC |= Copy_u16Value;
		break;
	case TMR5:
		Clr_ALL_BITS(TMR5_ADD -> PSC);
		TMR5_ADD -> PSC |= Copy_u16Value;
		break;
	default:                               break;
	}
}

void TMR_voidEnableOPM(TMRN_t Copy_uddtTMR_no)
{
	switch(Copy_uddtTMR_no)
	{
	case TMR2:
		SET_BIT(TMR2_ADD -> CR1, OPM_BIT);
		break;
	default:                               break;
	}
}

void TMR_voidSetChannelOutput(TMRN_t Copy_uddtTMR_no, CMPFn_t Copy_uddtFn, CHN_t Copy_uddtChNo)
{
	switch(Copy_uddtTMR_no)
	{
	case TMR2:
		switch(Copy_uddtChNo)
		{
		case CH1:
			Clr_BITS(TMR2_ADD -> CCMR1, 0x00000073);
			TMR2_ADD -> CCMR1 |= (Copy_uddtFn << OC1M_SHIFT);
			SET_BIT(TMR2_ADD -> CCER, CC1EN_BIT);
			break;
		case CH2:	break;
		case CH3:
			Clr_BITS(TMR2_ADD -> CCMR2, 0x00000073);
			TMR2_ADD -> CCMR2 |= (Copy_uddtFn << OC1M_SHIFT);
			SET_BIT(TMR2_ADD -> CCER, CC3EN_BIT);
			break;
		case CH4:	break;
		}
		break;
		default:                               break;
	}
}

void TMR_voidSetCMPVal(TMRN_t Copy_uddtTMR_no, CHN_t Copy_uddtChNo, u32 cmpValue)
{
	switch(Copy_uddtTMR_no)
	{
	case TMR2:
		switch(Copy_uddtChNo)
		{
		case CH1:
			TMR2_ADD -> CCR1 = cmpValue;
			break;
		case CH2:
			TMR2_ADD -> CCR2 = cmpValue;
			break;
		case CH3:
			TMR2_ADD -> CCR3 = cmpValue;
			break;
		case CH4:
			TMR2_ADD -> CCR4 = cmpValue;
			break;
		}
		break;
		default:                               break;
	}
}

void TMR_voidSetARR(TMRN_t Copy_uddtTMR_no, u32 Copy_u32Value)
{
	switch(Copy_uddtTMR_no)
	{
	case TMR2:
		TMR2_ADD -> ARR = Copy_u32Value;
		break;
	case TMR3:
		TMR3_ADD -> ARR = Copy_u32Value;
		break;
	case TMR5:
		TMR5_ADD -> ARR = Copy_u32Value;
		break;
	default:                               break;
	}
}

void TMR_voidClearCount(TMRN_t Copy_uddtTMR_no)
{
	switch(Copy_uddtTMR_no)
	{
	case TMR2:
		TMR2_ADD -> CNT = 0;
		break;
	case TMR3:
		TMR3_ADD -> CNT = 0;
		break;
	case TMR5:
		TMR5_ADD -> CNT = 0;
		break;
	default:                               break;
	}
}

void TMR_voidEnableICUInt(TMRN_t Copy_uddtTMR_no)
{
	switch(Copy_uddtTMR_no)
	{
	case TMR2:
		SET_BIT(TMR2_ADD -> DIER, 1);
		break;
	case TMR3:
		SET_BIT(TMR3_ADD -> DIER, 1);
		break;
	case TMR4:
		break;
	case TMR5:
		SET_BIT(TMR5_ADD -> DIER, 1);
		break;
	}
}

void TMR_voidSetChannelInput(TMRN_t Copy_uddtTMR_no, CHN_t Copy_uddtCH_no)
{
	switch(Copy_uddtTMR_no)
	{
	case TMR2:

		break;
	case TMR3:
		switch(Copy_uddtCH_no)
		{
		case CH1:
			Clr_BITS(TMR3_ADD -> CCMR1, 0x00000003);
			SET_BIT(TMR3_ADD -> CCMR1, CC1S_SHIFT);

			SET_BIT(TMR3_ADD -> CCER, CC1P_BIT);
			SET_BIT(TMR3_ADD -> CCER, CC1NP_BIT);

			SET_BIT(TMR3_ADD -> CCER, CC1EN_BIT);
			break;
		case CH2:
			break;
		case CH3:
			break;
		case CH4:
			break;
		}
		break;
		case TMR4:
			break;
		case TMR5:
			switch(Copy_uddtCH_no)
			{
			case CH1:
				Clr_BITS(TMR5_ADD -> CCMR1, 0x00000003);
				SET_BIT(TMR5_ADD -> CCMR1, CC1S_SHIFT);

				SET_BIT(TMR5_ADD -> CCER, CC1P_BIT);
				SET_BIT(TMR5_ADD -> CCER, CC1NP_BIT);

				SET_BIT(TMR5_ADD -> CCER, CC1EN_BIT);
				break;
			case CH2:
				break;
			case CH3:
				Clr_BITS(TMR5_ADD -> CCMR2, 0x00000003);
				SET_BIT(TMR5_ADD -> CCMR2, CC1S_SHIFT);

				SET_BIT(TMR5_ADD -> CCER, CC3P_BIT);
				SET_BIT(TMR5_ADD -> CCER, CC3NP_BIT);

				SET_BIT(TMR5_ADD -> CCER, CC3EN_BIT);
				break;
			case CH4:
				break;
			}
			break;
	}
}

u32 TMR_voidReadCapture(TMRN_t Copy_uddtTMR_no, CHN_t Copy_uddtChNo)
{
	u32 reading = 0;
	switch(Copy_uddtTMR_no)
	{
	case TMR2:


		break;
	case TMR3:
		switch(Copy_uddtChNo)
		{
		case CH1:
			reading = TMR3_ADD -> CCR1;
			break;
		case CH2:
			reading = TMR3_ADD -> CCR2;
			break;
		case CH3:
			reading = TMR3_ADD -> CCR3;
			break;
		case CH4:
			reading = TMR3_ADD -> CCR4;
			break;
		}
		break;
		case TMR5:
			switch(Copy_uddtChNo)
			{
			case CH1:
				reading = TMR5_ADD -> CCR1;
				break;
			case CH2:
				reading = TMR5_ADD -> CCR2;
				break;
			case CH3:
				reading = TMR5_ADD -> CCR3;
				break;
			case CH4:
				reading = TMR5_ADD -> CCR4;
				break;
			}
			break;
			default:            break;
	}
	return reading;
}






