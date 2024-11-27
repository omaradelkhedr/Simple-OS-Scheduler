/******************************************************************************
 *
 * Module: Operating System (OS)
 *
 * File Name: OS_Interface.h
 *
 * Description: Header file for OS module functions
 *
 * Author: Omar Khedr
 *
 ******************************************************************************/

#ifndef OS_INTERFACE_H_
#define OS_INTERFACE_H_

#include "../LIB/STD_TYPES.h"
#include "OS_CFG.h"
#include "OS_Private.h"
#include "../MCAL/General Interrupts/MGIE_Interface.h"
#include "../MCAL/DIO/MDIO_Interface.h"
#include "../MCAL/Timer/MTMR_Interface.h"  /* Include Timer interface */

/* Function to start the OS and initialize necessary components */
void OS_VOIDOSStart (void);

/* Function to create tasks and assign priority and periodicity */
void OS_VOIDCreateTask (void (*Copy_VOIDptf) (void), u8 Copy_U8Priority, u16 Copy_U16Periodicity);

/* Scheduler function to manage task execution */
void OS_VOIDSchedular (void);

/* Animation functions on PORTC */
void OS_VOIDAnimation1_1 (void);  /* Pattern 1 - Stage 1 */
void OS_VOIDAnimation1_2 (void);  /* Pattern 1 - Stage 2 */
void OS_VOIDAnimation1_3 (void);  /* Pattern 1 - Stage 3 */
void OS_VOIDAnimation1_4 (void);  /* Pattern 1 - Stage 4 */

void OS_VOIDAnimation2_1 (void);  /* Pattern 2 - Stage 1 */
void OS_VOIDAnimation2_2 (void);  /* Pattern 2 - Stage 2 */
void OS_VOIDAnimation2_3 (void);  /* Pattern 2 - Stage 3 */
void OS_VOIDAnimation2_4 (void);  /* Pattern 2 - Stage 4 */

/* 7-Segment display functions */
void OS_VOIDSegUp (void);         /* Count-up display on PORTA */
void OS_VOIDSegDown (void);       /* Count-down display on PORTB */

/* Function to select animation */
void OS_VOIDSelectanimation (void);

/* Function to change door lock position on PORTD */
void OS_VOIDDoorChangePosition (void);

#endif /* OS_INTERFACE_H_ */
