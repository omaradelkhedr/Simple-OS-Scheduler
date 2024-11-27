/******************************************************************************
 *
 * Module: MTMR (MCAL Timer)
 *
 * File Name: MTMR_Private.h
 *
 * Description: Header file for the MTMR module registers
 *
 * Author: Omar Khedr
 *
 ******************************************************************************/

#ifndef _MTMR_PRIVATE_H_
#define _MTMR_PRIVATE_H_

/************************************************************************************
 * The following are the memory-mapped register addresses for Timer/Counter 0, 1, and 2.
 * These registers are used to control and configure the timer modules in the system.
 ************************************************************************************/

/* Timer/Counter 0 Registers */
#define TCNT0_REG *((volatile u8 *)0x52)   /* Timer/Counter 0 register */
#define OCR0_REG  *((volatile u8 *)0x5C)   /* Output Compare Register 0 */
#define TIFR_REG  *((volatile u8*)0x58)    /* Timer/Counter Interrupt Flag Register */
#define TIMSK_REG *((volatile u8*)0x59)    /* Timer/Counter Interrupt Mask Register */
#define TCCR0_REG *((volatile u8*)0x53)    /* Timer/Counter Control Register 0 */

/* Timer/Counter 1 Registers */
#define TCNT1L_REG *((volatile u8*)0x4C)   /* Timer/Counter 1 Low byte */
#define TCNT1H_REG *((volatile u8*)0x4D)   /* Timer/Counter 1 High byte */
#define OCR1AL_REG *((volatile u8*)0x4A)   /* Output Compare Register 1A Low byte */
#define OCR1AH_REG *((volatile u8*)0x4B)   /* Output Compare Register 1A High byte */
#define OCR1BL_REG *((volatile u8*)0x48)   /* Output Compare Register 1B Low byte */
#define OCR1BH_REG *((volatile u8*)0x49)   /* Output Compare Register 1B High byte */
#define ICR1L_REG  *((volatile u8*)0x46)   /* Input Capture Register 1 Low byte */
#define ICR1H_REG  *((volatile u8*)0x47)   /* Input Capture Register 1 High byte */
#define TCCR1A_REG *((volatile u8*)0x4F)   /* Timer/Counter 1 Control Register A */
#define TCCR1B_REG *((volatile u8*)0x4E)   /* Timer/Counter 1 Control Register B */

/* Timer/Counter 2 Registers */
#define TCCR2_REG  *((volatile u8*)0x45)   /* Timer/Counter 2 Control Register */
#define TCNT2_REG  *((volatile u8*)0x44)   /* Timer/Counter 2 register */
#define OCR2_REG   *((volatile u8*)0x43)   /* Output Compare Register 2 */

/************************************************************************************
 * The following are the interrupt vectors for the Timer/Counter interrupts.
 ************************************************************************************/

/* Timer/Counter 1 Overflow interrupt vector */
void __vector_11 (void) __attribute__((signal));   /* Timer/Counter 1 overflow interrupt */

/* Timer/Counter 0 Overflow interrupt vector */
void __vector_10 (void) __attribute__((signal));   /* Timer/Counter 0 overflow interrupt */

#endif
