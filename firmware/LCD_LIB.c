#include "LCD_LIB.h"

void LCD_Cmd(char dato) {
    LCD_RS = 0;
    LCD_DATO = dato;
    LCD_E = 1;
    LCD_E = 0;

    if (dato <= 3) {
        __delay_ms(2);
    } else {
        __delay_us(40);
    }

}

void LCD_Escribir_STR(char str[]) {
    int i = 0;
    while (str[i] != '\0' && i < 1000) {
        LCD_Escribir(str[i]);
        i++;
    }

}

int LCD_Contador(char c[]) {
    int i = 0;
    while (c[i] != '\0' && i < 1000) {
        i++;
    }

    return i;
}

void LCD_Escribir(char dato) {
    LCD_RS = 1;
    LCD_DATO = dato;
    LCD_E = 1;
    LCD_E = 0;
    __delay_us(40);


}

void LCD_Confi_In() {
    LCD_E = 0;
    __delay_ms(15);
    LCD_Cmd(0x38);
    __delay_ms(5);
    LCD_Cmd(0x38);
    __delay_ms(1);
    LCD_Cmd(0x38); //Function Set
    LCD_Cmd(0x38); //1. Manda o recibe info en 8 o en 4Bits  

    LCD_Cmd(0x01); //Clear Display
    LCD_Cmd(0x06); //Entry mode set
    //1.Hace que el cursor se mueva hacia la derecha cuando escribe algo
    //2.Si se mueve o no se mueve la pantalla
    LCD_Cmd(0x0C); //Display ON/OFF Cntrl
    LCD_Cmd(0x0C); //1.Enciende lapantalla 2. apaga el cursor 3. no hace que titilee el cursor

}

void PIC_Confi_In() {

    TRISD = 0;
    TRISCbits.TRISC0 = 0;
    TRISCbits.TRISC1 = 0;

    //ADCON0 = 0b00000000;

    TRISB = 0B11110000;

    /////////////////////////////////

    OPTION_REGbits.nRBPU = 0; //Activa Pull up

    //PORTBbits.RB1 = 1;// RB1 a RB3 los pone en 111
    //PORTBbits.RB2 = 1;
    //PORTBbits.RB3 = 1;

    PORTB = 0;
    /*RBIF = 0; // Bandera de Interrupciones del RB4 al RB7 a 0
    INTCON = 0; // Limpia Registro INICON
    INTCONbits.RBIE = 1; //Habilita Interrupciones del RB4 al RB7
    INTCONbits.GIE = 1; // Habiita Interrupciones Gobales
     */

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

void LCD_Display(int T, int H) {
    int aux1, i;
    __delay_ms(2);
    LCD_Cmd(0x02);

    __delay_ms(2000);
    if (T > 16 && T < 40) {
        aux1 = T - 16;
        for (i = -1; i < aux1; i++) {
            __delay_ms(500);
            LCD_Cmd(0x1B);
        }
    }

}
