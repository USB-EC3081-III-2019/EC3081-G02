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
#define LCD_RD7     PORTDbits.RD7       // D7
#define TRISRD7     TRISDbits.TRISD7

#define LCD_RD6     PORTDbits.RD6       // D6
#define TRISRD6     TRISDbits.TRISD6

#define LCD_RD5     PORTDbits.RD5       // D5
#define TRISRD5     TRISDbits.TRISD5

#define LCD_RD4     PORTDbits.RD4       // D4
#define TRISRD4     TRISDbits.TRISD4

#define LCD_EN      PORTBbits.RB3       // EN
#define TRISEN      TRISBbits.TRISB3

void LCD_Escribir(char dato);
void LCD_Escribir_Cadena(char str[]);
void Retardo_2segundos();
void Lcd_Out(unsigned char y, unsigned char x, const char *buffer);
void LCD_Cmd(char dato);
void Intro();
void Visualisar_Config();
void Temperatura_Humedad();
void Humedad();
void Temperatura();
void Luz_Natural();
void Luz_Na_Ar();
void Luz_02_Artificial();
void Luz_03_Artificial_Manual();
void Luz_03_Artificial_Automatica();
void AbrirPercianas();
void Lcd_Chr_CP(char data);
void Presencia();
void LCD_Configuracion_Inicial();
void PIC_Configuracion_Inicial();
unsigned char n;
unsigned int Status,Variable,j,l,g;
void main() {
    PIC_Configuracion_Inicial();
    LCD_Configuracion_Inicial();
    while(1){
    Intro();
    Retardo_2segundos();
      LCD_Cmd(0x01);
    Visualisar_Config();
    switch(n){
        case'1':
            if(j == -1){
                break;
            
            Status = 0;
            j = Status + n - 1;
            Temperatura_Humedad();
            Retardo_2segundos();
            switch(j) {
                    case'1':
                        Temperatura();
                        if (n == 10){
                                j = j-2;

                        }
                    break;
                case'2':
                    Humedad();
                        if (n == 10){
                                j = j-2;
                        }
                    break;
            }
            }
        case'2':
            if(l == -1){
            Status = 0;
            l = Status + n -1;
            Luz_Na_Ar();
            switch(l){
                case'1':
                    Luz_Natural();
                    if (n == 10){
                                l = l-2;
                        }
                 
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
        h = h + 64;
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
                n = '11';
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
                n = '10';
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
 
    LCD_Cursor(1,1);
    LCD_Escribir_Cadena("Welcome to");
    LCD_Cursor(0,0);
    LCD_Cursor(-6,2);
    LCD_Escribir_Cadena("Smartvite");
}
void Visualisar_Config(){
    LCD_Cmd(0x01); // Limpiar Display
    LCD_Cursor(1,1);
    LCD_Escribir_Cadena("1.visualizar");
    LCD_Cursor(0,0);
    LCD_Cursor(-13,2);
    LCD_Escribir_Cadena("2.configurar");
}
void Temperatura_Humedad(){
     LCD_Cmd(0x01); // Limpiar Display
    LCD_Cursor(1,1);
    LCD_Escribir_Cadena("1.Temperatura");
    LCD_Cursor(-9,2);
    LCD_Escribir_Cadena("2.Humedad");
}
void Luz_Na_Ar(){
     LCD_Cmd(0x01); // Limpiar Display
    LCD_Cursor(1,1);
    LCD_Escribir_Cadena("1.Luz Natural");
    LCD_Cursor(-16,2);
    LCD_Escribir_Cadena("2.Luz Artificial");
   
}
void AbrirPercianas(){
    LCD_Cmd(0x01); // Limpiar Display
    LCD_Cursor(1,1);
    LCD_Escribir_Cadena("1.Abrir percianas");
    LCD_Cursor(-18,2);
    LCD_Escribir_Cadena("2.cerrar percianas");


}
void Presencia(){
    LCD_Cmd(0x01); // Limpiar Display
    LCD_Cursor(1,1);
    LCD_Escribir_Cadena("3.Presencia");
    LCD_Cursor(-7,2);
    LCD_Escribir_Cadena("4.Salir");
}
void Luz_02_Artificial(){
    LCD_Cmd(0x01); // Limpiar Display
    LCD_Cursor(1,1);
    LCD_Escribir_Cadena("1.Automatica");
    LCD_Cursor(-8,2);
    LCD_Escribir_Cadena("2.manual");
}
void Luz_03_Artificial_Manual(){
    LCD_Cmd(0x01); // Limpiar Display
    LCD_Cursor(1,1);
    LCD_Escribir_Cadena("Las luces han sido han sido encendidas");
}
void Luz_03_Artificial_Automatica(){
    LCD_Cmd(0x01); // Limpiar Display
    LCD_Cursor(1,1);
    LCD_Escribir_Cadena("Las luces han seran encendidas a las 6 pm");
}
void Temperatura(){
    LCD_Cmd(0x01); // Limpiar Display
    LCD_Cursor(1,1);
    LCD_Escribir_Cadena("La Temperatura es:");
}
void Humedad(){
    LCD_Cmd(0x01); // Limpiar Display
    LCD_Cursor(1,1);
    LCD_Escribir_Cadena("La Humedad es:");

}
void Luz_Natural(){
        LCD_Cmd(0x01); // Limpiar Display
    LCD_Cursor(1,1);
    LCD_Escribir_Cadena("1.abrir persianas");
    LCD_Cursor(-8,2);
    LCD_Escribir_Cadena("2.cerrar persianas");
}
void Retardo_2segundos(){
    int i;
    for(i=0; i<20;i++){
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
