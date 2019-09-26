# Configuración de la LCD
Realizamos las especificaciones que nos indicaba el fabricante para poder configurar la LCD para mostrar un mensaje en nuestro caso el mensaje fue hola 
## Integrantes del equipo
* 14-05775 Enmanuel Gerardo Alfonzo Angulo
* 15-11592 Víctor García 

### Material de apoyo 
El fabricante nos da información que nos facilito bastante la configuración en la cual pudimos ver como mandar comandos y caracteres que este se indica con RS. Los comandos para leer y escribir entres otras funciones que se nos indica en el material 
![module_intruction_code](https://user-images.githubusercontent.com/53823068/65625784-81f84580-df9a-11e9-871c-b023b27f67d4.png)


Podemos ver como con un diagrama de flujo se nos indica que comandos se tienen que mandar para que se muestre un mensaje en la pantalla.


![8_bits](https://user-images.githubusercontent.com/53823068/65627389-46ab4600-df9d-11e9-93ff-264ee9e60d3e.png)


lo que se traduce a nuestro código como 
![conf_led](https://user-images.githubusercontent.com/53823068/65627992-86266200-df9e-11e9-8984-8e183ad6bd58.png)

Claro que otros aspectos debemos declarar varias funciones que nos permita ver el mensaje en pantalla además de todas las configuraciones que debe tener previamente el PIC como por ejemplo el oscilador de 4MHz.

![conf_pic01](https://user-images.githubusercontent.com/53823068/65629167-e28a8100-dfa0-11e9-9faa-93c128217bac.png)

Definimos unas constantes para así hacer más fácil la codificación además de ser mejor para futuras modificaciones.
## Funciones 
### LCD_Escribir
![escribir](https://user-images.githubusercontent.com/53823068/65629603-a146a100-dfa1-11e9-8b60-ce76c3d261f8.png)

### LCD_Comando
![comando](https://user-images.githubusercontent.com/53823068/65629775-03070b00-dfa2-11e9-9668-5b03e24efb8b.png)

### PIC_Configuracion_Inicial
![Pic_confi](https://user-images.githubusercontent.com/53823068/65629923-609b5780-dfa2-11e9-8166-88569f7a0c25.png)
### Main
![main](https://user-images.githubusercontent.com/53823068/65630142-cdaeed00-dfa2-11e9-951e-405b27dbfa0f.png)
### firmware/
* LCD.c https://github.com/USB-EC3081-III-2019/EC3081-G02.md/blob/master/firmware/LCD.c


### Software 
* [MPLAB X IDE v5.25](https://www.microchip.com/mplab/mplab-x-ide)
* [MPLAB XC8 C compiler v2.10](https://www.microchip.com/mplab/compilers)

## Codigo

```c
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
void PIC_Configuracion_Inicial(){
    TRISD = 0;
    TRISCbits.TRISC0 = 0;
    TRISCbits.TRISC1 = 0;
   
    TRISA = 0;
    ADCON0=0b00000000; //Configuracion del registro ADCON0
   
   
     /*INICIALIZACIÓN DE INTERRUPCIONES*/
    INTCON = 0;//limpieza del registro INTCON
    INTCONbits.GIE = 0;//Habilitacion de interrupciones
   
}

```

## Resultados 
![IMG_20190924_150553](https://user-images.githubusercontent.com/53823068/65649982-cc97b300-dfd6-11e9-9d7e-bb8d464cbe1a.jpg)

