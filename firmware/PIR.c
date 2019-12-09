#include <xc.h>

#pragma config FOSC = XT        // Oscillator Selection bits (XT oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config CP = OFF         // FLASH Program Memory Code Protection bits (Code protection off)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low Voltage In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EE Memory Code Protection (Code Protection off)
#pragma config WRT = ON          // FLASH Program Memory Write Enable (Unprotected program memory may be written to by EECON control)


#define _XTAL_FREQ 4000000 
 
#define PIR_hcsr501 RC0     //El PIR estará conectado en el pin RC0
#define corneta RB2         //La corneta estará conectada en el pin RB2

void main(){
    
TRISB=0X00;
TRISC=0Xff; 
PORTB=0X00; 

while(1) //Get into the Infinie While loop
{
    if(PIR_hcsr501==1){
        corneta=1;
        __delay_ms(500); 
    }
    else{
        corneta=0;
        }
    }
}
