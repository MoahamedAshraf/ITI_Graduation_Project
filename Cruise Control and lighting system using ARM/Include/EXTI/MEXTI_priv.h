
#ifndef MEXTI_PRIVATE_H_
#define MEXTI_PRIVATE_H_

#define MXTI_BASE_ADDRESS	0x40013C00

typedef struct
{

	u32 IMR		;
	u32 EMR		;
	u32 RTSR	;
	u32 FTSR	;
	u32 SWIER	;
	u32 PR		;

}MEXTI_t;

#define MEXTI 		((volatile MEXTI_t*) (MXTI_BASE_ADDRESS))


#endif /* MEXTI_PRIVATE_H_ */
