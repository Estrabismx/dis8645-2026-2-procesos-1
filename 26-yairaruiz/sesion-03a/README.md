# sesion-03a

## apuntes sesión

martes 25/08

### la pantalla de 0.91 pulgadas con controlador SSD1306

Conexión con Arduino

+ 5V	: VCC
+ GND	: GND
+ A4 :  SDA
+ A5 :  SCK

la pantalla tiene 4 patitas que se conectan a la protoboard, en el extremo  gnd/vcc:

+ sda (señal de datos)
+ sck (señal de Clock)

voltaje: 3.3 V - 5 V

abrir Arduino IDE*

- la biblioteca son mini códigos que vamos a usar (vamos a escribir bibliotecas en segunda entrega)
- instalar la biblioteca: Adafruit SSD1306

![IMG](./imagenes/adafruit.png)
  
- en c++ los #include son importantes: anda a ese archivo y pégalo aqui
- #elfe: si o en otro caso
- ir a file, example, y seleccionar adafruit SSD1306 : adafruitssd1306_128x32_i2c

  
![IMG](./imagenes/file.png)

a4 va en sda 
a5 va a sck

![IMG](./imagenes/arduino.png)

para recordar*

+ (display es pantalla)

+ #include:  buscar archivo o biblioteca e inclúyelo en este código

+ display: representa nuestra pantalla dentro del código



## encargos

## lectura

pág: 36-40

Se explica cómo la “mercancía” en vez de satisfacer necesidades pasa a convertirse en algo que organiza nuestra forma de vivir, trabajar y consumir. También habla de que dejamos de ver las relaciones humanas y el trabajo detrás y comenzamos a percibirlos solamente por su valor, apariencia o capacidad de generar deseo, como por ejemplo cuando escogemos comprar algo por su marca. Me recordó mucho a que esta semana se mencionó bastante la sandalia channel sin suela que usó una actriz a la premiere de una nueva película. 



También algo que me cuestiono mucho y lo menciona es que cada vez hay más producción y ventas, ¿pero por qué no dejamos de sentirnos necesitados? ¿Por qué el consumo genera tanta producción pero nunca es suficiente y cada vez hay más necesidades y deseos? Esto se relaciona con el espectáculo, porque la publicidad hace que deseemos cosas que muchas veces no necesitamos realmente, pero ¿Qué es lo que sí necesitamos y cuál es el punto que se empieza a considerar un espectáculo? 

+ “El espectáculo señala el momento en que la mercancía ha alcanzado la ocupación total de la vida social.”
  
+ “El mundo de la mercancía se muestra así tal como es, puesto que su movimiento equivale al distanciamiento de los hombres entre sí y respecto de su producto global.”
