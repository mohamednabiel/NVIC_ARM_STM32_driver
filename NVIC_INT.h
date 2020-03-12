/*
 * NVIC_INT.h
 *
 *  Created on: Aug 9, 2019
 *      Author: GEEK
 */

#ifndef NVIC_INT_H_
#define NVIC_INT_H_


#include "std_types.h"

/******  STM32 specific Interrupt Numbers **********************************************************************/
#define  WWDG_IRQn                    0               /*!< Window WatchDog Interrupt                                         */
#define  PVD_IRQn                     1              /*!< PVD through EXTI Line detection Interrupt                         */
#define  TAMP_STAMP_IRQn              2             /*!< Tamper and TimeStamp interrupts through the EXTI line             */
#define  RTC_WKUP_IRQn                3            /*!< RTC Wakeup interrupt through the EXTI line                        */
#define  FLASH_IRQn                   4           /*!< FLASH global Interrupt                                            */
#define  RCC_IRQn                     5          /*!< RCC global Interrupt                                              */
#define  EXTI0_IRQn                   6         /*!< EXTI Line0 Interrupt                                              */
#define  EXTI1_IRQn                   7        /*!< EXTI Line1 Interrupt                                              */
#define  EXTI2_IRQn                   8       /*!< EXTI Line2 Interrupt                                              */
#define  EXTI3_IRQn                   9      /*!< EXTI Line3 Interrupt                                              */
#define  EXTI4_IRQn                   10             /*!< EXTI Line4 Interrupt                                              */
#define  DMA1_Stream0_IRQn            11            /*!< DMA1 Stream 0 global Interrupt                                    */
#define  DMA1_Stream1_IRQn            12           /*!< DMA1 Stream 1 global Interrupt                                    */
#define  DMA1_Stream2_IRQn            13          /*!< DMA1 Stream 2 global Interrupt                                    */
#define  DMA1_Stream3_IRQn            14         /*!< DMA1 Stream 3 global Interrupt                                    */
#define  DMA1_Stream4_IRQn            15        /*!< DMA1 Stream 4 global Interrupt                                    */
#define  DMA1_Stream5_IRQn            16       /*!< DMA1 Stream 5 global Interrupt                                    */
#define  DMA1_Stream6_IRQn            17      /*!< DMA1 Stream 6 global Interrupt                                    */
#define  ADC_IRQn                     18     /*!< ADC1, ADC2 and ADC3 global Interrupts                             */

/*
 * !Comment:
	Description: this Macros Define base address of NVIC .
 */
#define BASE_ADDRESS        (0xE000E100)                        /* NVIC base address                                          */
#define NVIC                ((NVIC_Type *)    BASE_ADDRESS )   /*  NVIC configuration struct                                 */
#define AIRCR               *((volatile u32*) 0xE000ED0C   )  /*   Application Interrupt and Reset Control Register address */
#define VECTKEYACTIVE       (0x5FA)                          /*    the bit field activation for the wrIting in AIRCR       */
#define AIRCRPOSbit           16                            /*     the value of shifting quantity                         */
#define IPprescl              4

typedef struct
{
     u32 ISER[8]        ;                   /*!< Offset: 0x000 (R/W)  Interrupt Set Enable Register           */
     u32 RESERVED0[24]  ;
     u32 ICER[8]        ;                   /*!< Offset: 0x080 (R/W)  Interrupt Clear Enable Register         */
     u32 RSERVED1[24]   ;
     u32 ISPR[8]        ;                   /*!< Offset: 0x100 (R/W)  Interrupt Set Pending Register          */
     u32 RESERVED2[24]  ;
     u32 ICPR[8]        ;                   /*!< Offset: 0x180 (R/W)  Interrupt Clear Pending Register        */
     u32 RESERVED3[24]  ;
     u32 IABR[8]        ;                   /*!< Offset: 0x200 (R/W)  Interrupt Active bit Register           */
     u32 RESERVED4[56]  ;
     u32 IP[60]        ;                   /*!< Offset: 0x300 (R/W)  Interrupt Priority Register (8Bit wide) */
     u32 RESERVED5[824] ;
     u32 STIR           ;                   /*!< Offset: 0xE00 ( /W)  Software Trigger Interrupt Register     */
}  NVIC_Type;



/*
!Comment:
Description: this Function Sets the Group priority
Input: 1)u8PriorityGroup -> the Group priority .    [0:7]

Output: Setting the priority Group .
*/
void NVIC_SetPriorityGrouping(u32 PriorityGroup) ;

/*
!Comment:
Description: this Function Gets the PriorityGrouping .
Input: NO input

Output: Getting the priority Group .
*/
u32 NVIC_GetPriorityGrouping(void);

/*
!Comment:
Description: this Function enable the interrupt request no.
Input: 1)u8 IRQn -> the Interrupt no. .    [0:240]

Output: enable that interrupt  .
*/
void NVIC_EnableIRQ(u8 IRQn) ;

/*
!Comment:
Description: this Function disable the interrupt request no.
Input: 1)u8 IRQn -> the Interrupt no. .    [0:240]

Output: disable that interrupt  .
*/
void NVIC_DisableIRQ(u8 IRQn) ;

/*
!Comment:
Description: this Function trigger the interrupt request no.
Input: 1)u8 IRQn -> the Interrupt no. .    [0:240]

Output: trigger that interrupt  .
*/
void NVIC_SetPendingIRQ(u8 IRQn);

/*
!Comment:
Description: this Function Gets the pending interrupt no. .
Input: NO input

Output: Getting the pending interrupt no. .
*/
u32 NVIC_GetPendingIRQ(u8 IRQn) ;


/*
!Comment:
Description: this Function clear the pending interrupt no. .
Input: NO input

Output: clear the pending interrupt no. .
*/
void NVIC_ClearPendingIRQ(u8 IRQn) ;

/*
!Comment:
Description: this Function Sets the interrupt priority .
Input: 1)u8 IRQn  -> the interrupt no..    [0:240]
	   2)priority -> the priority no ..    [0:240]

Output: Setting the priority no.
*/
void NVIC_SetPriority(u8 IRQn, u8 priority);


/* STM32F4xx Peripherals Interrupt Handlers */
void EXTI0_IRQHandler(void);
void EXTI1_IRQHandler(void);
void EXTI2_IRQHandler(void);
void EXTI3_IRQHandler(void);
#endif /* NVIC_INT_H_ */
