/******************************************************************************
 *
 * Module: MGIE (MCAL General Interrupt Enable)
 *
 * File Name: MGIE_Interface.h
 *
 * Description: Header file for the MGIE module functions Interfaces
 *
 * Author: Omar Khedr
 *
 ******************************************************************************/

#ifndef _MGIE_INTERFACE_H_
#define _MGIE_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "MGIE_Private.h"

/************************************************************************************
 * Function Name: MGIE_VOIDEnable
 * Description: This function enables global interrupts by setting the Global Interrupt
 *              Enable bit (I) in the Status Register (SREG).
 * Parameters: None
 * Return: None
 * Usage: Call this function to enable interrupts globally in the system.
 ************************************************************************************/
void MGIE_VOIDEnable(void);

/************************************************************************************
 * Function Name: MGIE_VOIDDisable
 * Description: This function disables global interrupts by clearing the Global Interrupt
 *              Enable bit (I) in the Status Register (SREG).
 * Parameters: None
 * Return: None
 * Usage: Call this function to disable interrupts globally in the system.
 ************************************************************************************/
void MGIE_VOIDDisable(void);

#endif
