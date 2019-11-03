#include <xc.h>
// CONFIG
#pragma config FOSC = XT        // Oscillator Selection bits (XT oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config CP = OFF         // FLASH Program Memory Code Protection bits (Code protection off)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low Voltage In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EE Memory Code Protection (Code Protection off)
#pragma config WRT = ON          // FLASH Program Memory Write Enable (Unprotected program memory may be written to by EECON control)

# define _XTAL_FREQ 4000000

#define LCD_RS PORTCbits.RC1
#define LCD_E PORTCbits.RC0
#define LCD_DATO PORTD


void LCD_Escribir(char dato);

void LCD_Comando(char dato);

void LCD_Configuracion_Inicial();
void PIC_Configuracion_Inicial();

void main() {
    PIC_Configuracion_Inicial();
    LCD_Configuracion_Inicial();
    LCD_Escribir('h');
    LCD_Escribir('o');
    LCD_Escribir('l');
    LCD_Escribir('a'); 
    
    while(1){
        __delay_ms(500);
        PORTAbits.RA0 = 1;
        __delay_ms(500);        
        PORTAbits.RA0 = 0;
    
    
    };
    
    



}
void LCD_Escribir(char dato){
    LCD_RS = 1;
    LCD_DATO = dato;
    LCD_E = 1;
    LCD_E = 0;
    __delay_us(40);//función del delay
}

void LCD_Comando(char dato){
    LCD_RS = 0;
    LCD_DATO = dato;
    LCD_E = 1;
    LCD_E = 0;
    if(dato <= 3){
      __delay_ms(2);
    }else{
      __delay_us(40);
    }
}
void LCD_Configuracion_Inicial(){
    LCD_E = 0;
    __delay_ms(15);
    LCD_Comando(0x38);
    __delay_ms(5);
    LCD_Comando(0x38);
    __delay_ms(1);
    LCD_Comando(0x38);
    LCD_Comando(0x38);
    LCD_Comando(0x0C);
    LCD_Comando(0x01);//Display clear
    LCD_Comando(0x06);//incrementar el cursor
    
    
    LCD_Comando(0x0C);//DISPLAY ON/ CURSOR OFF /NO BLINKING
    
}
void LCD_Escribir_Cadena(char str[]) {
    int i = 0;
    while (str[i] != '\0' && i < 1000) {
        LCD_Escribir(str[i]);
        i++;
    }
}

void LCD_Cursor(int h, int v) {
    int i;

    if (v == 1) {
        for (i = 0; i < h; i++) {
            __delay_us(40);
            LCD_Cmd(0x14);
        }
    }

    if (v == 2) {
        h = h + 40;
        for (i = 0; i < h; i++) {
            __delay_us(40);
            LCD_Cmd(0x14);
        }
    }

}

int LCD_Contar(char c[]) {
    int i = 0;
    while (c[i] != '\0' && i < 1000) {
        i++;
    }
    return i;
}

void LCD_Display(int Tam, int Hor) {
    int aux1, i;
    __delay_ms(2);
    LCD_Cmd(0x02);

    __delay_ms(2000);
    if (Tam > 16 && Tam < 40) {
        aux1 = Tam - 16;
        for (i = -1; i < aux1; i++) {
            __delay_ms(500);
            LCD_Cmd(0x1B);
        }
    }
}
void PIC_Configuracion_Inicial(){
    TRISD = 0;
    TRISCbits.TRISC0 = 0;
    TRISCbits.TRISC1 = 0;
    
    TRISA = 0;
    ADCON0=0b00000000; //Configuracion del registro ADCON0
    
    INTCON = 0; // Limpia Registro INICON
    INTCONbits.RBIE = 1; //Habilitar interrupciones de puerto B.
    INTCONbits.RBIF = 0; //Bandera desactivada.
    INTCONbits.GIE = 1; //Interrupciones globales habilitadas.
}
