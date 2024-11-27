/******************************************************************************
 *
 * Module: MGIE (MCAL General Interrupt Enable)
 *
 * File Name: MGIE_Private.h
 *
 * Description: Header file for the MGIE module functions
 *
 * Author: Omar Khedr
 *
 ******************************************************************************/
#ifndef _MGIE_PRIVATE_H_
#define _MGIE_PRIVATE_H_

/************************************************************************************
 * Register Name: SREG_REG
 * Description: The Status Register (SREG) is used to control global interrupt
 *              enable/disable and reflect the status of the processor.
 * Address: 0x5F
 * Type: u8 (8-bit unsigned)
 * Access: Read/Write
 *
 * Usage:
 *      - Bit 7 (I): Global Interrupt Enable Bit
 *          - 1: Interrupts are enabled
 *          - 0: Interrupts are disabled
 *      - Other bits reflect various processor flags.
 ************************************************************************************/
#define SREG_REG *((u8 *)0x5F)

#endif
