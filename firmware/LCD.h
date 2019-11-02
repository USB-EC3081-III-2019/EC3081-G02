#define LCD_DATO PORTD

void LCD_Escribir(char dato);
void LCD_Cmd(char dato);
void LCD_Configuracion_Inicial();
void PIC_Configuracion_Inicial();
void LCD_Escribir_Cadena(char str[]);
void LCD_Cursor(int Horizontal, int Vertical);
void LCD_Display(int Tam, int Hor);
int LCD_Contar(char c[]);


#endif
