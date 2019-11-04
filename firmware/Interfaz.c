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
void Retardo_2segundos();
void LCD_Cmd(char dato);
void Intro();
void Visualisar_Config();
void Temperatura_Humedad();
void Humedad();
void Temperatura();
void Luz_Na_Ar();
void Luz_02_Artificial();
void Luz_03_Artificial_Manual();
void Luz_03_Artificial_Automatica();
void AbrirPercianas();
void Presencia();
void LCD_Configuracion_Inicial();
void PIC_Configuracion_Inicial();
unsigned char n;
void main() {
    PIC_Configuracion_Inicial();
    LCD_Configuracion_Inicial();
    Intro();
    Retardo_2segundos();
    Visualisar_Config();
    switch(n){
        case'1':
            Temperatura_Humedad();
            switch(n){
                case'1':
                    //Temperatura();
                    break;
                case'2':
                   // Humedad();
                    break;
            }
        case'2':
            Luz_Na_Ar();
            switch(n){
                case'1':
                    
                    break;
                case'2':
                    switch(n){
                    case'1':
                    Luz_03_Artificial_Automatica();
                    break;
                    case'2':
                    Luz_03_Artificial_Manual();
                    break;
                  
                    break;
                }
                    
            }
            
    
    }
    
    }

    

    
    




void LCD_Escribir(char dato){
    LCD_RS = 1;
    LCD_DATO = dato;
    LCD_E = 1;
    LCD_E = 0;
    __delay_us(40);//función del delay
}

void LCD_Cmd(char dato){
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
    LCD_Cmd(0x38);
    __delay_ms(5);
    LCD_Cmd(0x38);
    __delay_ms(1);
    LCD_Cmd(0x38);
    LCD_Cmd(0x38);
    LCD_Cmd(0x0C);
    LCD_Cmd(0x01);//Display clear
    LCD_Cmd(0x06);//incrementar el cursor
    
    
    LCD_Cmd(0x0C);//DISPLAY ON/ CURSOR OFF /NO BLINKING
    
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
void Lcd_Set_Cursor(char a, char b)
{
    char temp,z,y;
    if(a == 1)
    {
      temp = 0x80 + b - 1;
        z = temp>>4;
        y = temp & 0x0F;
        LCD_Cmd(z);
        LCD_Cmd(y);
    }
    else if(a == 2)
    {
        temp = 0xC0 + b - 1;
        z = temp>>4;
        y = temp & 0x0F;
        LCD_Cmd(z);
        LCD_Cmd(y);
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
void __interrupt () my_isr_routine (void) {
 if(RBIF) //Si hay cambio de estado en PORTB
 {
      char a = 1, b = 1, c = 1, i = 0, k = 1;
        while (k == 1) {
            PORTBbits.RB3 = a;
            PORTBbits.RB2 = b;
            PORTBbits.RB1 = c;


            if ((PORTBbits.RB7 == 0)&&(PORTBbits.RB3 == 0)) //Código de atención de la interrupción
            {
                __delay_ms(2);
                n = '*';
                k = 0;
                __delay_ms(50);

            }
            if ((PORTBbits.RB7 == 0)&&(PORTBbits.RB2 == 0))//Código de atención de la interrupción
            {
                __delay_ms(2);
                n = '0';
                k = 0;
                __delay_ms(50);
            }
            if ((PORTBbits.RB7 == 0)&&(PORTBbits.RB1 == 0))//Código de atención de la interrupción
            {
                LCD_Cmd(0x01); //Display clear
                __delay_ms(2);
                n = '#';
                k = 0;
                __delay_ms(50);
            }
            if ((PORTBbits.RB6 == 0)&&(PORTBbits.RB3 == 0)) //Código de atención de la interrupción
            {
                __delay_ms(2);
                n = '7';
                k = 0;
                __delay_ms(50);

            }
            if ((PORTBbits.RB6 == 0)&&(PORTBbits.RB2 == 0))//Código de atención de la interrupción
            {
                __delay_ms(2);
                n = '8';
                k = 0;
                __delay_ms(50);
            }
            if ((PORTBbits.RB6 == 0)&&(PORTBbits.RB1 == 0))//Código de atención de la interrupción
            {
                __delay_ms(2);
                n = '9';
                k = 0;
                __delay_ms(50);
            }
            if ((PORTBbits.RB5 == 0)&&(PORTBbits.RB3 == 0)) //Código de atención de la interrupción
            {
                __delay_ms(2);
                n = '4';
                k = 0;
                __delay_ms(50);
            }
            if ((PORTBbits.RB5 == 0)&&(PORTBbits.RB2 == 0))//Código de atención de la interrupción
            {   
                __delay_ms(2);
                n = '5';
                k = 0;
                __delay_ms(50);
            }
            if ((PORTBbits.RB5 == 0)&&(PORTBbits.RB1 == 0))//Código de atención de la interrupción
            {
                __delay_ms(2);
                n = '6';
                k = 0;
                __delay_ms(50);
            }
            if ((PORTBbits.RB4 == 0)&&(PORTBbits.RB3 == 0)) //Código de atención de la interrupción
            {
                
                __delay_ms(2);
                n = '1';
                k = 0;
                __delay_ms(50);
            }
            if ((PORTBbits.RB4 == 0)&&(PORTBbits.RB2 == 0))//Código de atención de la interrupción
            {
                __delay_ms(2);
                n = '2';
                k = 0;
                __delay_ms(50);
            }
            if ((PORTBbits.RB4 == 0)&&(PORTBbits.RB1 == 0))//Código de atención de la interrupción
            {
                __delay_ms(2);
                n = '3';
                k = 0;
                __delay_ms(50);
            }

            if (i == 0) {
                a = 0;
                b = 1;
                c = 1;
            }
            if (i == 1) {
                a = 1;
                b = 0;
                c = 1;
            }
            if (i == 2) {
                a = 1;
                b = 1;
                c = 0;
                //i=-1;
            }
            if (i == 3) {
                k = 0;
                i = -1;
            }
            i++;
        }
     
 RBIF = 0; //Desactivar bandera...
 }
}
void Intro(){
    int Horizontal, Vertical, aux2, aux3;
    Lcd_Set_Cursor(1,1);
    char aux1[] = "Welcome to";
    Lcd_Set_Cursor(2,2);
    char aux0[] = "Smartvite";
}
void Visualisar_Config(){
    int Horizontal, Vertical, aux2, aux3;
    Lcd_Set_Cursor(1,1);
    char aux1[] = "1.visualizar";
    Lcd_Set_Cursor(2,2);
    char aux0[] = "2.configurar";
}
void Temperatura_Humedad(){
    int Horizontal, Vertical, aux2;
    Lcd_Set_Cursor(1,1);
    char aux1[] = "1.Temperatura";
    Lcd_Set_Cursor(2,2);
    char aux0[] = "2.Humedad";
}
void Luz_Na_Ar(){
    int Horizontal, Vertical, aux2, aux3;
    Lcd_Set_Cursor(1,1);
    char aux1[] = "1.Luz Natural";
    Lcd_Set_Cursor(2,2);
    char aux0[] = "2.Luz Artificial";    
}
void AbrirPercianas(){
     int Horizontal, Vertical, aux2, aux3;
    Lcd_Set_Cursor(1,1);
    char aux1[] = "1.Abrir percianas";
    Lcd_Set_Cursor(2,2);
    char aux0[] = "2.cerrar percianas"; 


}
void Presencia(){
     int Horizontal, Vertical, aux2, aux3;
    Lcd_Set_Cursor(1,1);
    char aux1[] = "3.Presencia";
    Lcd_Set_Cursor(2,2);
    char aux0[] = "4.Salir";
}
void Luz_02_Artificial(){
     int Horizontal, Vertical, aux2, aux3;
    Lcd_Set_Cursor(1,1);
    char aux1[] = "1.Automatica";
    Lcd_Set_Cursor(2,2);
    char aux0[] = "2.manual";
}
void Luz_03_Artificial_Manual(){
     int Horizontal, Vertical, aux2, aux3;
    Lcd_Set_Cursor(1,1);
    char aux1[] = "Las luces han sido han sido encendidas";
}
void Luz_03_Artificial_Automatica(){
     int Horizontal, Vertical, aux2, aux3;
    Lcd_Set_Cursor(1,1);
    char aux1[] = "Las luces han seran encendidas a las 6 pm";
}
void Retardo_2segundos(){
    int i =0;
    while(i < 20 ){
        __delay_ms(100); 
    }
}
/*void Humedad(){
    


}*/
/*void Temperatra(){


}*/
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
