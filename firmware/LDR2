#include <stdio.h>
#include <stdlib.h>
#define _XTAL_FREQ 4000000
#include "LCD_LIB.h"
#include <math.h>



#include <xc.h>
#pragma config FOSC = XT        // Oscillator Selection bits (XT oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config CP = OFF         // FLASH Program Memory Code Protection bits (Code protection off)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low Voltage In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EE Memory Code Protection (Code Protection off)
#pragma config WRT = ON         // FLASH Program Memory Write Enable (Unprotected program memory may be written to by EECON control)

//Funciones
unsigned int ADC_Read(unsigned char canal);
void PIC_Confi_In();

void main() {
    PIC_Confi_In();

    //Analogico Digital
    ADCON1bits.PCFG = 0x1110; //A0 será la entrada analógica



    //Puertos


    //Perifericos (Iniciar configuraciones analogicas)
    ADCON0bits.ADCS = 0b00; //ADCS1:ADCS0: A/D Conversion Clock Select bits 00 = FOSC/2    
    ADCON0bits.ADON = 1; //Encendemos el modulo analogico
    ADCON1bits.ADFM = 1; //Justificación a la derecha(De esta manera, los bits más significativos se almacenan en ADRESH)


    ////////////////////////////Inicio//////////////////////////////////////////

    LCD_Confi_In();
    LCD_Cmd(0x01);
    __delay_ms(2);

    LCD_Cursor(5, 1);
    LCD_Escribir_STR("Prueba");

    //Lcd_Int(); inicio de la LCD, llamado de la función desde la libreria
    //Lcd_Cmd(LCD_CURSOR_OFF); ubicacion del cursor llamado de la función cursor desde la libreria
    //Lcd_Out(1,1,"mensaje"); pintf en la pantalla, llamado de la funcion desde 

    //Bucle
    while (1) {
        
        float valor = ADC_Read(0), aux4;        //Se coloca 0 porque es el canal analogico RA0
        float voltaje = (valor * 5)/1023;//voltajes a lumenes
        int aux1, aux2, aux3;
        char lumenes1, lumenes2, lumenes;
        valor = voltaje;
        
        //////////////////////////
        aux1 = valor;
        aux2 = aux1 * 10;
        aux4 = valor * 10;
        aux3 = aux4 - aux2;
        
        LCD_Cmd(0x01);//limpia
        __delay_ms(2);
        LCD_Escribir_STR("V: ");
        LCD_Escribir('0'+aux1);
        LCD_Escribir_STR(".");
        LCD_Escribir('0'+aux3);
        
        __delay_ms(1000);
        LCD_Cmd(0x01);
        __delay_ms(2);
        
        lumenes1 = ((78,357*(pow(valor, 6)) - 1310,4*(pow(valor, 5)) + 8587,1*(pow(valor, 4)) - 28006*(pow(valor, 3)) + 48118*(pow(valor, 2))));
        
        lumenes2 = (- 43329*(valor) + 18771);
        
        lumenes = lumenes1 + lumenes2;
        
        LCD_Cmd(0x01);
        __delay_ms(2);
        LCD_Escribir_STR('0'+lumenes);
        
        //lux = (78,357*(pow(valor, 6)) - 1310,4*(pow(valor, 5)) + 8587,1*(pow(valor, 4)) - 28006*(pow(valor, 3)) + 48118*(pow(valor, 2)) - 43329*(pow(valor)) + 18771);
        //lux = fabs(78,357*(valor)^6 - 1310,4*(valor)^5 + 8587,1*(valor)^4 - 28006*(valor)^3 + 48118*(valor)^2 - 43329*(valor) + 18771);
          __delay_ms(200);
    }

    __delay_ms(200);
}


//////////////////////////////Funcion para la Lectura//////////////////////////////////

unsigned int ADC_Read(unsigned char canal) {
    ADCON0 &= 0xC5; //Valor para reiniciar los canales a 0
    ADCON0bits.CHS = canal; //Se elige el canal
    __delay_ms(2); //Espera para el cambio
    GO_nDONE = 1; //Se activa la 
    while (GO_nDONE); //Esperamos hasta que terminen
    int X = ADRESH << 8;
    X = X + ADRESL; //Los valores se guardarán en el registro ADRES H(2 mas significativos) L(6 menos significativos)
    return (X);

}
