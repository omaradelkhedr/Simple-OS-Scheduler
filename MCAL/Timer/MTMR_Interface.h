/******************************************************************************
 *
 * Module: MTMR (MCAL Timer)
 *
 * File Name: MTMR_Interface.h
 *
 * Description: Header file for the MTMR module functions
 *
 * Author: Omar Khedr
 *
 ******************************************************************************/

#ifndef _MTMR_INTERFACE_H_
#define _MTMR_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "MTMR_Private.h"
#include "../DIO/MDIO_Interface.h"

/************************************************************************************
 * Function: MTMR0_VOIDNormalInit
 * Description: Initializes Timer0 in Normal mode.
 *  - Configures the timer for overflow interrupt generation.
 ************************************************************************************/
void MTMR0_VOIDNormalInit (void);

/************************************************************************************
 * Function: MTMR0_VOIDFastPWMInit
 * Description: Initializes Timer0 in Fast PWM mode.
 *  - Configures Timer0 for Fast PWM output with a given frequency.
 ************************************************************************************/
void MTMR0_VOIDFastPWMInit (void);

/************************************************************************************
 * Function: MTMR0_VOIDSetDutyCycle
 * Description: Sets the duty cycle for Timer0 in Fast PWM mode.
 *  - Takes a percentage value (0-100) and adjusts the OCR0 register to set the duty cycle.
 ************************************************************************************/
void MTMR0_VOIDSetDutyCycle (u8 Copy_U8DutyCycle);

/************************************************************************************
 * Function: MTMR1_VOIDFastPWMInit
 * Description: Initializes Timer1 in Fast PWM mode.
 *  - Configures Timer1 for Fast PWM output, similar to Timer0 but for a different timer.
 ************************************************************************************/
void MTMR1_VOIDFastPWMInit(void);

/************************************************************************************
 * Function: MTMR1_VOIDFastPWMFreqDutyCycle
 * Description: Configures Timer1 in Fast PWM mode with a specific frequency and duty cycle.
 *  - Takes frequency and duty cycle as input and sets the appropriate OCR and ICR registers.
 ************************************************************************************/
void MTMR1_VOIDFastPWMFreqDutyCycle(u32 Copy_U32Frequency, u8 Copy_U8DutyCycle);

/************************************************************************************
 * Function: MTMR0_VOIDCTCInit
 * Description: Initializes Timer0 in CTC mode for Compare Match interrupt.
 *  - Configures the mode, clock source, and pre-scaler to generate CTC interrupts.
 ************************************************************************************/
void MTMR0_VOIDCTCInit (void);

/************************************************************************************
 * Function: MTMR0_CTC_CallbackFunction
 * Description: Sets a callback function to be called upon Timer0 CTC interrupt.
 *  - Allows the user to register a custom callback for handling CTC interrupts.
 ************************************************************************************/
void MTMR0_CTC_CallbackFunction (void (*Copy_ptf)(void));

#endif
