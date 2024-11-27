/******************************************************************************
 *
 * Module: MTMR (MCAL Timer)
 *
 * File Name: MTMR_Program.c
 *
 * Description: Source file for the MTMR module functions
 *
 * Author: Omar Khedr
 *
 ******************************************************************************/
#include "MTMR_Interface.h"

/* Pointer to store the callback function for the CTC interrupt */
static void (* GLOB_TMR0CTCCallBackPtr) (void);

/************************************************************************************
 * Function: MTMR0_VOIDOVInitialization
 * Description: Initializes Timer0 in Normal mode for overflow interrupt.
 *  - Configures the timer mode, clock source, and pre-scaler.
 *  - Enables the overflow interrupt and sets the pre-load value for the counter.
 ************************************************************************************/
void MTMR0_VOIDOVInitialization (void)
{
	/* Select Normal Mode: Clear WGM00 and WGM01 */
	CLR_BIT(TCCR0_REG,6);
	CLR_BIT(TCCR0_REG,3);
	/* Compare match output behavior depends on normal mode */
	CLR_BIT(TCCR0_REG,5);
	CLR_BIT(TCCR0_REG,4);
	/* Choose clock source: /1024 from pre-scalar */
	SET_BIT(TCCR0_REG,2);
	CLR_BIT(TCCR0_REG,1);
	SET_BIT(TCCR0_REG,0);
	/* Enable TOIE0 overflow interrupt enable */
	SET_BIT(TIMSK_REG,0);
	/* Pre-load value to start the counter */
	TCNT0_REG=123;
}

/************************************************************************************
 * Function: MTMR0_VOIDCTCInit
 * Description: Initializes Timer0 in CTC mode for compare match interrupt.
 *  - Configures the timer mode, clock source, and pre-scaler.
 *  - Sets the top value to generate an interrupt every 1ms.
 ************************************************************************************/
void MTMR0_VOIDCTCInit (void)
{
	/* Select CTC Mode: Set WGM01 and clear WGM00 */
	SET_BIT(TCCR0_REG,6);
	CLR_BIT(TCCR0_REG,3);
	/* OC0 Pin disconnected in CTC mode */
	CLR_BIT(TCCR0_REG,5);
	CLR_BIT(TCCR0_REG,4);
	/* Choose clock source: /64 from pre-scalar */
	CLR_BIT(TCCR0_REG,2);
	SET_BIT(TCCR0_REG,1);
	SET_BIT(TCCR0_REG,0);
	/* Set the TOP value to generate an interrupt every 1ms */
	OCR0_REG=125;
	/* Enable OCIE0 compare match interrupt enable */
	SET_BIT(TIMSK_REG,1);
}

/************************************************************************************
 * Function: MTMR0_CTC_CallbackFunction
 * Description: Sets a callback function that will be called on Timer0 CTC interrupt.
 ************************************************************************************/
void MTMR0_CTC_CallbackFunction (void (*Copy_ptf)(void))
{
	/* Store the pointer to the callback function */
	GLOB_TMR0CTCCallBackPtr=Copy_ptf;
}

/************************************************************************************
 * Function: MTMR0_VOIDFastPWMInit
 * Description: Initializes Timer0 in Fast PWM mode to generate PWM signals.
 *  - Configures the timer mode, clock source, and pre-scaler.
 *  - Sets output compare behavior for Fast PWM mode.
 *  - Disables OCIE0 interrupt.
 ************************************************************************************/
void MTMR0_VOIDFastPWMInit (void)
{
	/* Select Fast PWM Mode: Set WGM00 and WGM01 */
	SET_BIT(TCCR0_REG,6);
	SET_BIT(TCCR0_REG,3);
	/* Set OC0 behavior according to Fast PWM mode */
	SET_BIT(TCCR0_REG,5);
	CLR_BIT(TCCR0_REG,4);
	/* Choose clock source: /256 from pre-scalar --> Frequency = 3906.25Hz */
	SET_BIT(TCCR0_REG,2);
	CLR_BIT(TCCR0_REG,1);
	CLR_BIT(TCCR0_REG,0);
	/* Disable OCIE0 interrupt */
	CLR_BIT(TIMSK_REG,1);
}

/************************************************************************************
 * Function: MTMR0_VOIDSetDutyCycle
 * Description: Sets the duty cycle for Timer0 in Fast PWM mode.
 *  - Duty cycle is provided as a percentage (0-100).
 *  - The duty cycle is mapped to the OCR0 register for PWM generation.
 ************************************************************************************/
void MTMR0_VOIDSetDutyCycle (u8 Copy_U8DutyCycle)
{
	/* Set the OCR0 value to achieve the desired duty cycle */
	OCR0_REG= (Copy_U8DutyCycle*255)/100 ;
}

/************************************************************************************
 * Function: MTMR1_VOIDOVInitialization
 * Description: Initializes Timer1 in Normal mode for overflow interrupt.
 *  - Configures the timer mode, clock source, and pre-scaler.
 *  - Enables the overflow interrupt for Timer1.
 ************************************************************************************/
void MTMR1_VOIDOVInitialization (void)
{
	/* Select Normal Mode: Clear WGM10, WGM11, WGM12, and WGM13 */
	CLR_BIT(TCCR1A_REG,1);
	CLR_BIT(TCCR1A_REG,0);
	CLR_BIT(TCCR1B_REG,4);
	CLR_BIT(TCCR1B_REG,3);
	/* Compare match output behavior depends on normal mode */
	CLR_BIT(TCCR1A_REG,7);
	CLR_BIT(TCCR1A_REG,6);
	CLR_BIT(TCCR1A_REG,5);
	CLR_BIT(TCCR1A_REG,4);
	/* Choose clock source: /256 from pre-scalar */
	SET_BIT(TCCR1B_REG,2);
	CLR_BIT(TCCR1B_REG,1);
	CLR_BIT(TCCR1B_REG,0);
	/* Enable TOIE0 overflow interrupt enable */
	SET_BIT(TIMSK_REG,0);
}

/************************************************************************************
 * Interrupt Service Routine for Timer0 Overflow Interrupt.
 *  - Toggles Pin 0 of Port A every 31 overflows.
 ************************************************************************************/
void __vector_11 (void)
{
	static u8 counter=0;
	counter++;
	/* Every 31 overflows, reset the counter and toggle the pin */
	if(counter == 31)
	{
		TCNT0_REG=123;      /* Reset Timer0 counter */
		MDIO_VOIDTogglePinValue(0,0); /* Toggle Pin 0 of Port A */
		counter=0;          /* Reset counter */
	}
}

/************************************************************************************
 * Interrupt Service Routine for Timer0 CTC Interrupt.
 *  - Calls the user-defined callback function if set.
 ************************************************************************************/
void __vector_10 (void)
{
	/* Call the callback function set by the user */
	GLOB_TMR0CTCCallBackPtr();
}
