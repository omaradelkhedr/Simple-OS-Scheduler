/******************************************************************************
 *
 * Module: OS (Operating System)
 *
 * File Name: OS_Program.c
 *
 * Description: Source file for the OS module functions
 *
 * Author: Omar Khedr
 *
 ******************************************************************************/
#include "OS_Interface.h"

/* Create a new datatype for tasks */
typedef struct
{
    void (*ptf) (void);   /* Function pointer to task */
    u16 periodicity;      /* Periodicity of the task */

} Task_t;

/* Create a global tick variable */
u16 GLOB_U16TickNum = 0 ;

/* Create an array of type Task_t for task management */
Task_t Tasks[NUMBER_OF_TASKS];

/* Initialization function for the OS */
void OS_VOIDOSStart (void)
{
    /* Enable Global Interrupt */
    MGIE_VOIDEnable();

    /* Initialize Timer0 in CTC mode */
    MTMR0_VOIDCTCInit();
}

/* Function to create tasks and list them according to their priority in the task array */
void OS_VOIDCreateTask (void (*Copy_VOIDptf) (void), u8 Copy_U8Priority, u16 Copy_U16Periodicity)
{
    Tasks[Copy_U8Priority].periodicity = Copy_U16Periodicity;  /* Set task periodicity */
    Tasks[Copy_U8Priority].ptf = Copy_VOIDptf;                  /* Set task function pointer */
}

/* Scheduler function to manage the execution of tasks based on their periodicity */
void OS_VOIDSchedular (void)
{
    GLOB_U16TickNum++;  /* Increment the global tick */

    /* Iterate through all tasks to check if they should be executed */
    for (u8 LOC_U8Iterator = 0; LOC_U8Iterator < NUMBER_OF_TASKS; LOC_U8Iterator++)
    {
        /* Execute the task if it's time based on its periodicity */
        if ((GLOB_U16TickNum % Tasks[LOC_U8Iterator].periodicity) == 0)
        {
            Tasks[LOC_U8Iterator].ptf();
        }
    }
}

/* Global flag to control animation state */
u8 GLOB_U8Flag = 0;
void OS_VOIDAnimationFlag (void)
{
    GLOB_U8Flag = 1;  /* Set the animation flag */
}

/* Animation on PORTC: Pattern 1 - Stage 1 */
void OS_VOIDAnimation1_1 (void)
{
    MDIO_VOIDSetPortValue(2, 0x18);  /* Set PORTC value to 0x18 */
}

/* Animation on PORTC: Pattern 1 - Stage 2 */
void OS_VOIDAnimation1_2 (void)
{
    MDIO_VOIDSetPortValue(2, 0b00111100);  /* Set PORTC value to 0b00111100 */
}

/* Animation on PORTC: Pattern 1 - Stage 3 */
void OS_VOIDAnimation1_3 (void)
{
    MDIO_VOIDSetPortValue(2, 0b01111110);  /* Set PORTC value to 0b01111110 */
}

/* Animation on PORTC: Pattern 1 - Stage 4 */
void OS_VOIDAnimation1_4 (void)
{
    MDIO_VOIDSetPortValue(2, 0b11111111);  /* Set PORTC value to 0b11111111 */
}

/* Animation on PORTC: Pattern 2 - Stage 1 */
void OS_VOIDAnimation2_1 (void)
{
    MDIO_VOIDSetPortValue(2, 0b01111110);  /* Set PORTC value to 0b01111110 */
}

/* Animation on PORTC: Pattern 2 - Stage 2 */
void OS_VOIDAnimation2_2 (void)
{
    MDIO_VOIDSetPortValue(2, 0b00111100);  /* Set PORTC value to 0b00111100 */
}

/* Animation on PORTC: Pattern 2 - Stage 3 */
void OS_VOIDAnimation2_3 (void)
{
    MDIO_VOIDSetPortValue(2, 0b00011000);  /* Set PORTC value to 0b00011000 */
}

/* Animation on PORTC: Pattern 2 - Stage 4 */
void OS_VOIDAnimation2_4 (void)
{
    MDIO_VOIDSetPortValue(2, 0b00000000);  /* Set PORTC value to 0b00000000 */
}

/* Array of numbers to display on 7-segment display */
u8 GLOB_U8Numbers[10] = {ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE};

/* 7-Segment count-up function, to display on PORTA */
void OS_VOIDSegUp (void)
{
    static u8 LOC_U8Counter1 = 0;

    LOC_U8Counter1++;  /* Increment counter */
    MDIO_VOIDSetPortValue(0, GLOB_U8Numbers[LOC_U8Counter1]);  /* Set PORTA value based on counter */

    /* If counter reaches 9, reset to 0 */
    if (GLOB_U8Numbers[LOC_U8Counter1] == NINE)
    {
        MDIO_VOIDSetPortValue(0, GLOB_U8Numbers[LOC_U8Counter1]);
        LOC_U8Counter1 = -1;  /* Reset counter */
    }
}

/* 7-Segment count-down function, to display on PORTB */
void OS_VOIDSegDown (void)
{
    static u8 LOC_U8Counter2 = 9;

    /* If counter reaches 0, reset to 10 */
    if (GLOB_U8Numbers[LOC_U8Counter2] == ZERO)
    {
        MDIO_VOIDSetPortValue(1, GLOB_U8Numbers[LOC_U8Counter2]);
        LOC_U8Counter2 = 10;  /* Reset counter */
    }

    LOC_U8Counter2--;  /* Decrement counter */
    MDIO_VOIDSetPortValue(1, GLOB_U8Numbers[LOC_U8Counter2]);  /* Set PORTB value based on counter */
}

/* Door lock change position function, to display on PORTD */
void OS_VOIDDoorChangePosition (void)
{
    static u8 LOC_U8Position = 0;

    /* Change position of door lock */
    if (LOC_U8Position == 0)
    {
        LOC_U8Position = 1;
        MDIO_VOIDSetPinValue(3, 0, 1);  /* Set PORTD pin 0 to high */
        MDIO_VOIDSetPinValue(3, 7, 0);  /* Set PORTD pin 7 to low */
    }
    else if (LOC_U8Position == 1)
    {
        LOC_U8Position = 0;
        MDIO_VOIDSetPinValue(3, 0, 0);  /* Set PORTD pin 0 to low */
        MDIO_VOIDSetPinValue(3, 7, 1);  /* Set PORTD pin 7 to high */
    }
}
