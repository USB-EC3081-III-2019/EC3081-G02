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


  if (isAwesome){
      return true
    }

## Instrucciones para usar la plantilla
* Haga click sobre la opción 'use this template' en la parte superior del repositorio.
* Aparecera la ventana para crear un repositorio basado en esta plantilla.
* Debe crear el repositorio dentro de la organización correspondiente a la materia y no dentro de su cuenta personal de GitHub.
* El nombre del repositorio debe ser ECXXXX-GXX.
* Edite el README.md de su repositorio según los datos de su materia y grupo.
