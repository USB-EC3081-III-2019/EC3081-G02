## SmartVite
  El proyecto consiste en realizar un hervidero inteligente con los principios de la domótica ya que se planea hacer uso de un servomodor para el control de persianas y un relé el cual activará las luminarias según sea requerido, de esta manera, las plantas contarias con un proceso de fotosintesis mucho mayor.

## Integrantes del equipo
* 14-05775 Enmanuel Gerardo Alfonzo Angulo
* 15-11592 Víctor Manuel García Martínez 

## ¿Qué es un sensor?
Un sensor es aquel dispositivo que está capacitado para detectar acciones o estimulos externos y responder en consecuencia. Es decir, nos permiten captar información del medio físico que nos rodea, se encarga de medir las magnitudes físicas y transformarlas en señales electricas capaces de ser encendidas por un microcontrolador capáz de detectar magnitudes tando fisicas como químicas y transformarlas en señales electricas.

### Sensores a ser usador:
    
#1. [DHT11](https://github.com/USB-EC3081-III-2019/EC3081-G02/blob/master/docs/DataSheet%20DHT11.pdf): 
El sensor DHT11 es capaz de realizar mediciones de temperatura y humedad relativa con un costo muy económico. El sensor posee una interfaz serial propietaria, que solo requiere de un pin para comunicarse con un microcontrolador.Este sensor, aunque es algo lento y no muy preciso es ideal cuando el costo es una preocupación, resulta entonces ideal para las aplicaciones pequeñas o maquetas en las cuales se pueda apreciar el funcionamiento de cierto proyecto.
   ![Imagen de dht1111](https://github.com/USB-EC3081-III-2019/EC3081-G02/blob/master/Imagenes/dht11.jpg)
    
#2. [FotoResistencia](https://github.com/USB-EC3081-III-2019/EC3081-G02/blob/master/docs/Datasheet%20LDR.pdf):

Un fotorresistor o fotorresistencia es un componente electrónico cuya resistencia disminuye con el aumento de intensidad de luz incidente.Su funcionamiento se basa en el efecto fotoeléctrico. Un fotorresistor está hecho de un semiconductor de alta resistencia como el sulfuro de cadmio, CdS.2​ Si la luz que incide en el dispositivo es de alta frecuencia, los fotones son absorbidos por las elasticidades del semiconductor dando a los electrones la suficiente energía para saltar la banda de conducción. El electrón libre que resulta, y su hueco asociado, conducen la electricidad, de tal modo que disminuye la resistencia.

![Imagen de foto-resistencia](https://github.com/USB-EC3081-III-2019/EC3081-G02/blob/master/Imagenes/foto-resistencia.jpg)

#3. HC-SR501(Sensor de proximidad):
El sensor HC-SR501 se basa en un sensor piroeléctrico dividido en dos zonas sensibles. Estas dos zonas sensibles en condiciones normales son activadas igualmente por la radiación infrarroja del ambiente, pero emiten una señal cuando una de ellas se encuentra en diferencia con la otra (porque, por ejemplo, en una zona se encuentre una persona). La detección se basa en el calor emitido por el cuerpo humano, en forma de radiación infrarroja. Las zonas de detección intercaladas además se multiplican mediante una lente especial que se encuentra encima del sensor piroeléctrico (esa cosa blanca en forma de cúpula).

![Imagen de sensor de proximidad HC-SR501](https://github.com/USB-EC3081-III-2019/EC3081-G02/blob/master/Imagenes/sensor%20de%20proximidad%20HC-SR501.jpg)


### Actuadores:
Los actuadores son dispositivos que brindan la posibilidad de transformar diferentes tipos de energía para generar algún funcionamiento dentro de un sistema automatizado determinado. Usualmente, los actuadores generan una fuerza mecánica a partir de distintos tipos de energía, como puede ser eléctrica, neumática, o hidráulica.

#1. [Relé](https://github.com/USB-EC3081-III-2019/EC3081-G02/blob/master/docs/Datasheet%20de%20rele%20831A-1.pdf):
Un relevador es un interruptor que puede ser controlador eléctricamente. Este dispositivo también puede entenderse como un controlador electro-mecánico. Fue inventado por el científico estadounidense Joseph Henry quien descubrió el fenómeno electromagnético de auto-inductancia e inductancia mutua. Este principio le permitió crear un tipo de electroimán que al activarse puede controlar a un interruptor, este es el principio del relevador.

![Imagen de rele](https://github.com/USB-EC3081-III-2019/EC3081-G02/blob/master/Imagenes/rele.jpg)

#2. [Servomotor](https://github.com/USB-EC3081-III-2019/EC3081-G02/blob/master/docs/Servomotores.docx)

Un servomotor es un tipo especial de motor que permite controlar la posición del eje en un momento dado. Esta diseñado para moverse determinada cantidad de grados y luego mantenerse fijo en una posición.

![Imagen de servo](https://github.com/USB-EC3081-III-2019/EC3081-G02/blob/master/Imagenes/servo.jpg)


    
   
### Propuesta de Proyecto:
El proyecto será un invernadero inteligente el cual controlará la Irradiación dentro del mismo. De esta manera, las plantas podrán contar con una fotosintesis (Es el proceso biológico en el que las plantas capturan la energía de la luz solar para fabricar su propio alimento y liberar oxígeno a partir del dióxido de carbono y el agua) mayor, de manera que se cuente con un crecimiento más eficiente.Adicionalemte, dicho proyecto cuenta con sensores de proximidad el cual será usado para tener datos de cuando esté el operario dentro del invernadero realizando cualquier cambio necesario.



#### Diagrama de flujo (sujeto a posibles modificaciones):


![Imagen de diagrama de flujo](https://github.com/USB-EC3081-III-2019/EC3081-G02/blob/master/Imagenes/diagrama%20de%20flujo.png)
[Diagrama](https://github.com/USB-EC3081-III-2019/EC3081-G02/blob/master/docs/Diagrama%20de%20Flujo%20Proyectos_2.pdf)
