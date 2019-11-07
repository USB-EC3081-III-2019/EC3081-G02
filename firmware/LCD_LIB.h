#ifndef LCD_LIB_H
#define	LCD_LIB_H

#include <xc.h>

#define LCD_RS PORTCbits.RC1
#define LCD_E PORTCbits.RC0 
#define LCD_DATO PORTD

#define _XTAL_FREQ 4000000

void LCD_Cmd(char dato);
void LCD_Escribir(char dato);
void LCD_Confi_In();
void PIC_Confi_In();
void LCD_Escribir_STR(char str[]);
void LCD_Cursor(int Horizontal, int Vertical);
void LCD_Display(int T, int H);
int LCD_Contador(char c[]);

#endif	/* XC_HEADER_TEMPLATE_H */

