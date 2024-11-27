/******************************************************************************
 *
 * Module: Main
 *
 * File Name: main.c
 *
 * Description: Source file for the main
 *
 * Author: Omar Khedr
 *
 ******************************************************************************/
#include "LIB/STD_TYPES.h"
#include "OS/OS_Interface.h"
#include "MCAL/DIO/MDIO_Interface.h"

int main (void)
{
	/* Initialize animation pins on PORTC */
	MDIO_VOIDSetPortDirection(2, 0xFF);   /* Set all pins of PORTC as output */

	/* Initialize 1st 7-segment to start from zero on PORTA */
	MDIO_VOIDSetPortDirection(0, 0xFF);   /* Set all pins of PORTA as output */
	MDIO_VOIDSetPortValue(0, 0x3F);       /* Set PORTA to display 0 on the 7-segment */

	/* Initialize 1st 7-segment to start from nine on PORTB */
	MDIO_VOIDSetPortDirection(1, 0xFF);   /* Set all pins of PORTB as output */
	MDIO_VOIDSetPortValue(1, 0x6F);       /* Set PORTB to display 9 on the 7-segment */

	/* Initialize Door lock pins on PORTD */
	MDIO_VOIDSetPinDirection(3, 0, 1);    /* Set pin 0 of PORTD as output */
	MDIO_VOIDSetPinDirection(3, 7, 1);    /* Set pin 7 of PORTD as output */

	/* Use the scheduler in the interrupt */
	MTMR0_CTC_CallbackFunction(&OS_VOIDSchedular);  /* Set the scheduler function to be called on interrupt */

	/* Creating tasks and assigning their priority and periodicity */
	OS_VOIDCreateTask(&OS_VOIDSegUp, 0, 1000);        /* Task 0: 7-segment up count every 1000ms */
	OS_VOIDCreateTask(&OS_VOIDSegDown, 1, 2000);      /* Task 1: 7-segment down count every 2000ms */
	OS_VOIDCreateTask(&OS_VOIDAnimation1_1, 2, 3000); /* Task 2: Animation 1 - Stage 1 every 3000ms */
	OS_VOIDCreateTask(&OS_VOIDAnimation1_2, 3, 3000); /* Task 3: Animation 1 - Stage 2 every 3000ms */
	OS_VOIDCreateTask(&OS_VOIDAnimation1_3, 4, 3000); /* Task 4: Animation 1 - Stage 3 every 3000ms */
	OS_VOIDCreateTask(&OS_VOIDAnimation1_4, 5, 3000); /* Task 5: Animation 1 - Stage 4 every 3000ms */
	OS_VOIDCreateTask(&OS_VOIDAnimation2_1, 6, 3000); /* Task 6: Animation 2 - Stage 1 every 3000ms */
	OS_VOIDCreateTask(&OS_VOIDAnimation2_2, 7, 3000); /* Task 7: Animation 2 - Stage 2 every 3000ms */
	OS_VOIDCreateTask(&OS_VOIDAnimation2_3, 8, 3000); /* Task 8: Animation 2 - Stage 3 every 3000ms */
	OS_VOIDCreateTask(&OS_VOIDAnimation2_4, 9, 3000); /* Task 9: Animation 2 - Stage 4 every 3000ms */
	OS_VOIDCreateTask(&OS_VOIDDoorChangePosition, 10, 20000); /* Task 10: Change door position every 20000ms */

	/* Initialize OS */
	OS_VOIDOSStart();  /* Start the OS and enable global interrupts */

	/* Main loop: Runs indefinitely as OS scheduler handles tasks */
	while (1)
	{
		// Main program does not need to do anything in the loop
	}

	return 0;  /* End of main function */
}
