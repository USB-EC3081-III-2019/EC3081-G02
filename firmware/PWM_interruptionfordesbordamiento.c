#include <stdio.h>
#include <stdlib.h>
#include <xc.h>

#pragma config FOSC = XT        // Oscillator Selection bits (XT oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config CP = OFF         // FLASH Program Memory Code Protection bits (Code protection off)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low Voltage In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EE Memory Code Protection (Code Protection off)
#pragma config WRT = ON         // FLASH Program Memory Write Enable (Unprotected program memory may be written to by EECON control)

#define _XTAL_FREQ 4000000

//#include<pic16f877.h>
//#define SBIT_T2CKPS1  1
//char value = 0;
//int count = 0;

int on_time; //= 150; //On-Time for the PWM signal
int count = 0; //count gets incremented for every timer overlap

void interrupt timer_isr() {
    if (TMR2IF == 1) // Timer has overflown
    {
        //TMR2 = 252;     /*Load the timer Value, (Note: Timervalue is 101 instaed of 100 as the
        // TImer0 needs two instruction Cycles to start incrementing TMR0 */
        TMR2IF = 0; // Clear timer interrupt flag
        count++;
        //RB0=~RB0;
    }

    if (count <= on_time) {
        RE1 = 1; // complement the value for blinking the LEDs
    } else {

        RE1 = 0;
    }

    if (count >= 235) {
        count = 0;
    }
}

void main() {
    /* TRISD=0x00;    //COnfigure PORTD as output to blink the LEDs

     T2CON = (1<<SBIT_T2CKPS1);  // Timer2 with external freq and 16 as prescalar
     TMR2=100;       // Load the timer value for 500us delay
     TMR2IE=1;       //Enable timer interrupt bit in PIE1 register
     GIE=1;          //Enable Global Interrupt
     PEIE=1;         //Enable the Peripheral Interrupt
     TMR2ON = 1;*/

    TRISE = 0;   //recordar que la LDR está conectada en el RA0 y los demás pines son digitales
    /*OPTION_REG = 0b00000011;  // Timer0 with external freq and 32 as prescaler
    TMR0=251;       // Load the time value for 1us delayValue can be between 0-256 only
    TMR0IE=1;       //Enable timer interrupt bit in PIE1 register
    GIE=1;          //Enable Global Interrupt
    PEIE=1;         //Enable the Peripheral Interrupt*/

    T2CON = 0b00000100; // Timer0 with external freq and 32 as prescaler
    TMR2 = 0; // Load the time value for 1us delayValue can be between 0-256 only
    PR2 = 85;
    TMR2ON = 1; //Enable timer interrupt bit in PIE1 register
    TMR2IE = 1; //Enable timer interrupt bit in PIE1 register
    GIE = 1; //Enable Global Interrupt
    PEIE = 1; //Enable the Peripheral Interrupt

    while (1) {
        on_time = 6; // on time = 0.5ms
        __delay_ms(250);
       on_time = 26; // on time = 6ms
        __delay_ms(250);
        
/////////////////////0/////////////////////////////       
        /* on_time = 6; // on time = 0.5ms
        __delay_ms(250);
       //on_time = 28; // on time = 6ms
       // __delay_ms(1000);*/        
////////////////////90/////////////////////////////
        /* on_time = 6; // on time = 0.5ms
        __delay_ms(250);
       on_time = 14; // on time = 6ms
        __delay_ms(250);*/
////////////////////180///////////////////////////
        /*on_time = 6; // on time = 0.5ms
        __delay_ms(250);
       on_time = 26; // on time = 6ms
        __delay_ms(250);*/
//////////////////////////////////////////////////

    }
    /*
    while(1)
    {
        PORTD = value;
    }*/
}
