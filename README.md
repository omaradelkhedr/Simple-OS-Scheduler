
# ATmega32 Embedded Operating System

This repository contains an implementation of a simple embedded operating system for the ATmega32 microcontroller, developed using Eclipse IDE. The project demonstrates basic scheduling and task management, interfacing with GPIO, and animations using 7-segment displays and LEDs.

![Logo](https://github.com/user-attachments/assets/8ce13ffe-bb1a-4851-99b6-c13911e1d7b9)


## Project Overview

The embedded OS is designed to execute multiple tasks periodically using a cooperative scheduling approach. It includes functionalities such as:

- LED animations.
- 7-segment up/down counting.
- A simple door lock mechanism simulation.

## Features

- **Task Scheduler**: Periodically executes tasks based on their priority and periodicity.
- **7-Segment Display**: Displays a count-up and count-down animation.
- **LED Animation**: Creates dynamic patterns on an LED array.
- **Door Lock Simulation**: Simulates a door lock mechanism using GPIO pins.

## Hardware Requirements

- **Microcontroller**: ATmega32.
- **External Components**:
  - LEDs for animations (connected to PORTC).
  - 7-segment displays (connected to PORTA and PORTB).
  - GPIO pins for door lock simulation (connected to PORTD).

## Software Requirements

- **IDE**: Eclipse IDE for C/C++ Developers.
- **Compiler**: AVR GCC.
- **Programming Tool**: AVRDUDE or any compatible tool for uploading the HEX file to ATmega32.

## Task Details

| Task Name            | Priority | Periodicity | Description                          |
|----------------------|----------|-------------|--------------------------------------|
| `OS_VOIDSegUp`       | 0        | 1000ms      | Increment 7-segment display on PORTA. |
| `OS_VOIDSegDown`     | 1        | 2000ms      | Decrement 7-segment display on PORTB. |
| `OS_VOIDAnimation1`  | 2-5      | 3000ms      | LED animation pattern 1 on PORTC.   |
| `OS_VOIDAnimation2`  | 6-9      | 3000ms      | LED animation pattern 2 on PORTC.   |
| `OS_VOIDDoorChangePosition` | 10 | 20000ms | Simulate door lock mechanism on PORTD. |


## Author

Developed by **Omar Khedr**.

---

Feel free to contribute or raise issues if you encounter any problems!

### Test Results

You can view videos of the tests conducted for this project by clicking the link below:

[View Test Results](https://drive.google.com/drive/folders/1nD22UFZW3IRkxjyOEg64OneziIeQ_KxL?usp=sharing)
