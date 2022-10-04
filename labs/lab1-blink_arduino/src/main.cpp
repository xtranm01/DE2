
/***********************************************************************
 * 
 * Blink a LED in Arduino-style and use function from the delay library.
 * ATmega328P (Arduino Uno), 16 MHz, PlatformIO
 *
 * Copyright (c) 2022 Tomas Fryza
 * Dept. of Radio Electronics, Brno University of Technology, Czechia
 * This work is licensed under the terms of the MIT license.
 * 
 **********************************************************************/


/* Defines -----------------------------------------------------------*/
#define LED_GREEN PB5   // PB5 is AVR pin where green on-board LED 
                        // is connected
#define DOT 200 // Delay in milliseconds
#define DASH DOT*2
#define SPACE DOT*7
#ifndef F_CPU
# define F_CPU 16000000 // CPU frequency in Hz required for delay funcs
#endif

/* Includes ----------------------------------------------------------*/
#include <avr/io.h>     // AVR device-specific IO definitions
#include <util/delay.h> // Functions for busy-wait delay loops


// -----
// This part is needed to use Arduino functions but also physical pin
// names. We are using Arduino-style just to simplify the first lab.
#include "Arduino.h"
#define PB5 13 
// -----


/* Function definitions ----------------------------------------------*/
/**********************************************************************
 * Function: Main function where the program execution begins
 * Purpose:  Toggle one LED and use delay library.
 * Returns:  none
 **********************************************************************/
int main(void)
{ 
    pinMode(LED_GREEN, OUTPUT);
    digitalWrite(LED_GREEN, LOW);

    // Set pin where on-board LED is connected as output
    

    // Infinite loop
    while (1)
    {
      digitalWrite(LED_GREEN, HIGH);
      _delay_ms(DOT);
      digitalWrite(LED_GREEN, LOW);
      _delay_ms(DOT);
      digitalWrite(LED_GREEN, HIGH);
      _delay_ms(DASH);
      digitalWrite(LED_GREEN, LOW);
      _delay_ms(SPACE);
    }

    // Will never reach this
    return 0;
}
