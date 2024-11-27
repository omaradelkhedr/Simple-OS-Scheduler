/******************************************************************************
 *
 * Module: MGIE (MCAL General Interrupt Enable)
 *
 * File Name: MGIE_Program.c
 *
 * Description: Source file for the MGIE module functions
 *
 * Author: Omar Khedr
 *
 ******************************************************************************/

#include "MGIE_Interface.h"

/************************************************************************************
 * Function Name: MGIE_VOIDEnable
 * Description: This function enables global interrupts by setting the Global Interrupt
 *              Enable bit (I) in the Status Register (SREG).
 * Parameters: None
 * Return: None
 * Usage: Call this function to enable interrupts globally in the system.
 ************************************************************************************/
void MGIE_VOIDEnable(void)
{
    /* Set the I bit (bit 7) of the SREG register to 1 to enable interrupts */
    SET_BIT(SREG_REG, 7);
}

/************************************************************************************
 * Function Name: MGIE_VOIDDisable
 * Description: This function disables global interrupts by clearing the Global Interrupt
 *              Enable bit (I) in the Status Register (SREG).
 * Parameters: None
 * Return: None
 * Usage: Call this function to disable interrupts globally in the system.
 ************************************************************************************/
void MGIE_VOIDDisable(void)
{
    /* Clear the I bit (bit 7) of the SREG register to disable interrupts */
    CLR_BIT(SREG_REG, 7);
}
