/*
 * NVIC_PROG.C
 *
 *  Created on: Aug 9, 2019
 *      Author: GEEK
 */

#include "NVIC_INT.h"


/* STM32F4xx Peripherals Interrupt Handlers */

void EXTI0_IRQHandler(void)
{

  //NVIC_SetPendingIRQ(GREEN_LED_OFF_IRQ);
}

void EXTI0_IRQHandler(void)
{

  //NVIC_SetPendingIRQ(GREEN_LED_OFF_IRQ);
}

void EXTI0_IRQHandler(void)
{

  //NVIC_SetPendingIRQ(GREEN_LED_OFF_IRQ);
}


void EXTI0_IRQHandler(void)
{

  //NVIC_SetPendingIRQ(GREEN_LED_OFF_IRQ);
}

/*
!Comment:
Description: this Function Sets the Group priority
Input: 1)u8PriorityGroup -> the Group priority .    [0:7]

Output: Setting the priority Group .
*/
void NVIC_SetPriorityGrouping(u32 PriorityGroup)
{
  u32 u32RegValue =  AIRCR ;     /*definition for Application Interrupt and Reset Control Register */
  u32RegValue = 0;              /*clear bits in the beginning */
  u32RegValue = VECTKEYACTIVE ;
  u32RegValue = (u32RegValue <<AIRCRPOSbit);
  (PriorityGroup << 8);
  u32RegValue = (u32RegValue |PriorityGroup );
  AIRCR = u32RegValue ;
}

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
void NVIC_EnableIRQ(u8 IRQn)
{

	u8 u8InterruptNo                                                  ;         /* local variable for the no. of the interrupt register */
    u8InterruptNO =  (IRQn /32)                                       ;        /*  definition for the register No.                     */
	NVIC->ISER[u8InterruptNO] = (u32)(1 << ((u32)(IRQn) & (u32)0x1F)) ;       /* enable interrupt                                     */
}

/*
!Comment:
Description: this Function disable the interrupt request no.
Input: 1)u8 IRQn -> the Interrupt no. .    [0:240]

Output: disable that interrupt  .
*/
void NVIC_DisableIRQ(u8 IRQn)
{
	u8 u8InterruptNo                                                 ;          /* local variable for the no. of the interrupt register */
    u8InterruptNO =  (IRQn /32)                                      ;         /*  definition for the register No.                     */
	NVIC->ICER[u8InterruptNO] = (u32)(1 << ((u32)(IRQn) & (u32)0x1F));        /* enable interrupt                                     */
}

/*
!Comment:
Description: this Function trigger the interrupt request no.
Input: 1)u8 IRQn -> the Interrupt no. .    [0:240]

Output: trigger that interrupt  .
*/
void NVIC_SetPendingIRQ(u8 IRQn)
{
	u8 u8InterruptNo                                                 ;         /* local variable for the no. of the interrupt register */
    u8InterruptNO =  (IRQn /32)                                      ;         /*  definition for the register No.                     */
	NVIC->ISPR[u8InterruptNO] = (u32)(1 << ((u32)(IRQn) & (u32)0x1F));        /* enable interrupt                                     */
}

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
void NVIC_ClearPendingIRQ(u8 IRQn)
{
	u8 u8InterruptNo                                                 ;          /* local variable for the no. of the interrupt register */
    u8InterruptNO =  (IRQn /32)                                      ;         /*  definition for the register No.                     */
	NVIC->ICPR[u8InterruptNO] = (u32)(1 << ((u32)(IRQn) & (u32)0x1F));        /* enable interrupt                                     */
}

/*
!Comment:
Description: this Function Sets the interrupt priority .
Input: 1)u8 IRQn  -> the interrupt no..    [0:240]
	   2)priority -> the priority no ..    [0:256]

Output: Setting the priority no.
*/
void NVIC_SetPriority(u8 IRQn, u32 priority)
{

	u8 u8PRiorityRegisterNo                                                        ;      /*local variable for the no. of priority register  */
	u8 u8Offset                                                                    ;     /* local variable for the offset                   */
	u8PRiorityRegisterNo = (IRQn/IPprescl)                                         ;    /*  get the no. of the register                    */
    u8Offset = (priority % IPprescl)                                               ;   /*   get the offset of the priority in the register*/
	u8Offset =(u8Offset * 8)                                                       ;  /*    at which offset  from 0..3                   */
 	priority = (priority  << u8Offset)                                             ; /*     shift the priority to the defined area      */

 	NVIC->IP[u8PRiorityRegisterNo] =(( NVIC->IP[u8PRiorityRegisterNo])|	(priority));/*      pass the final value to the interrupt REG  */

}
