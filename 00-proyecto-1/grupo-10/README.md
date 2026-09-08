# Proyecto 1/ Grupo 10
**Integrantes:**


- Belén Castillo / [bombobby](https://github.com/bombobby) 


- Martina Fernandez / [pumpkinguurl](https://github.com/pumpkinguurl) 

- Maite Villarroel / [maiteev](https://github.com/maiteev) 


- Nacha Zamudio / [nachazamudio](https://github.com/nachazamudio) 

  
# Poema
Este proyecto busca exponer el poema "Hope is the thing with feathers" del año 1861 y publicado por primera vez de forma póstuma en 1891. Fue escrito por la poeta estadounidense Emily Dickinson.

**Poema original:**
--
“Hope is the thing with feathers

That perches in the soul,

And sings the tune without the words,

And never stops at all,
***
And sweetest in the gale is heard,

And sore must be the storm,

That could abash the little bird,

That kept so many warm.
***

I’ve heard it in the chillest land,

And on the strangest sea,

Yet, never, in extremity,

It asked a crumb of me”



**Poema traducido al español:**
--
“La esperanza es esa cosa con plumas

que se posa en el alma

y canta la melodía sin palabras,

y nunca se detiene.
***
Y se oye más dulcemente en la tempestad,

y muy fuerte debe ser la tormenta

que pudiera acobardar al pajarito

que a tantos les dio calor.
***
La he oído en la tierra más fría

y en el mar más extraño,

pero nunca, en la adversidad,

me pidió una migaja” 

# Licencias explícitas del corpus

Se verificó el estado de derechos de autor de las obras utilizadas. En el caso del poema "Hope is the thing with feathers", de Emily Dickinson, la fuente utilizada, Academy of American Poets (Poets.org), declara explícitamente que la obra se encuentra en el dominio público: “This poem is in the public domain.” Esta indicación aparece directamente en la página de la obra, después del texto del poema.
Por lo tanto, el poema fue incorporado al corpus bajo la condición de dominio público, utilizando como evidencia la declaración explícita de la fuente.


| Obra | Autor/a | Fuente | Licencia / estado | Evidencia |
| :--- | :--- | :--- | :--- | :--- |
| *Hope is the thing with feathers* | Emily Dickinson | Academy of American Poets | Dominio público | https://poets.org/poem/hope-thing-feathers-254 |

Evidencia:

![](./imagenes/poema-dominio.png) 

# Flujo de trabajo 
![](./imagenes/flujo-trabajo.png) 

# Proceso clases

**Apuntes / estudio**

Parte del estudio para generar el codigo.

1. Revisa el estado del botón ``` (digitalRead)  ```para saber si está presionado (1) o suelto (0) y también lee la posición de la perilla del potenciómetro ```(analogRead)```
  
2. Convierte el valor del potenciómetro (de 0 a 1023) en coordenadas espaciales Y (20 a -900) usando la función ```map```. Esto crea el deslizamiento del poema hacia arriba y abajo.
   
3. Se borra la pantalla y usa el condicional ```if (lecturaBoton == 1)```para decidir qué idioma usar. Luego mediante for imprime todas las lineas del poemas en forma de columna vertical, sumando píxeles a ```posicionY``` para separar cada línea.
   
4. Mientras ```for``` imprime las lineas del poema, también vigila qué verso se está imprimiendo. Si pasa por el verso asignado para las plumas, dibuja los dibujitos de las plumas. Si pasa por el verso asignado para la tormenta, dibuja la animación del pajarito.
   
5. Actualiza el ```display display.display(),``` y hace una pausa mínima de 80 milisegundos que define la velocidad de cambio de frames de la animación del pájaro.
   
# Animaciones 
Las animación hecha en la plataforma www.pixilart.com, siguiendo el formato de 128x32 px, la primera animacion tiene 5 fotogramas y la segunda 10 fotogramas, se pasaron a https://javl.github.io/image2cpp/ para poder generar el código y agregarlas en el código final, con su respectiva carpeta conocimos esta pagina gracias a los repositorios de la generación pasada.

- Plumas: El programa dibuja los 5 frames de las plumas al mismo tiempo, apilados uno debajo del otro. Al mover el potenciómetro para leer el poema, la pantalla baja y crea la ilusión de que las plumas van cayendo.
  
- Pollo: Se utiliza la función ```pollo++``` que suma 1 en cada vuelta del programa. Cuando el contador llega al límite de frames ```(pollo_allArray_LEN)```, se reinicia a 0, así la animación del pájaro está en un bucle en tiempo real de 10 fotogramas.

 # Errores y problemas 
- Uno de los primeros errores que cometimos al empezar con el proceso de conocer los componentes que íbamos a usar (como la pantallita) fue un error en las conexiones.

Seguimos las conexiones de una foto que compartieron por discord, pero al conectar el arduino al computador, empezamos a sentir un olor a plástico quemado, desconectamos el arduino e hicimos nuestras consultas, teníamos algunos cables mal conectados. Cambiamos las conexiones y por suerte la pantalla había sobrevivido.


- Cuando empezamos a implementar el botón para que se mostrará el poema traducido, el poema se quedaba pegado en la versión en español y no avanzaba, finalmente era un error del código, que fue corregido con el profe Aaron.


- Para dividir la tarea, trabajamos en dos códigos distintos, uno para las animaciones y otro para el texto y la reproducción de este, esto nos aliviano a la pega como grupo. Pero lamentablemente esto nos trajo problemas al intentar unirlos luego, pues no sabíamos cómo y produjo mucho desorden de funciones y esquema general del código. 


- Uno de los ayudantes nos recomendó investigar sobre los “millis” para que la visualización del poema se viera más fluido pero fue un proceso tortuoso intentar entenderlo y que funcionara. Igual después de muchos intentos de probar cambiando cositas pequeñas que creíamos eran el problema, logramos que funcionara. Sin embargo, al final decidimos descartar el uso de este comando porque si fue difícil implementarlo solo al poema, cuando tuviéramos que juntarlo con la animación podríamos perder la cabeza.

intento de código con milis:
```cpp
//el tiempo es la variable millis, sumando constantemente desde el 0.
void loop() (
    tiempo = millis(); 
//si el primer tiempo es mayor o igual a el tiempo sumado 1 segundo u otra cantidad
if (tiempo >= (tiempo2+diferencia))
{ 
//actualizamos el tiempo2, vuelve a 0¿
   tiempo2 = tiempo; 
//dividido en 1000 para que lo muestre en segundos y no milisegundos
   segundos = tiempo/1000; 
```

- Quisimos agregarle una tipografía que conectara con el poema y se viera más fluído. Estuvimos probando distintos tamaños y aunque pusiéramos el más pequeño, aún así se nos cortaba la visualización del verso, por lo que decidimos separar algunas palabras de su verso, aumentando la cantidad de estos para que el poema fuese legible. 
![](./imagenes/imagen-sector-errores.jpeg) 

- Cuando intentamos conectar el potenciómetro para empezar a hacer pruebas para aplicarlo, lo conectamos una primera vez y funcionó bien, luego lo desconectamos, volvimos a conectar y a los segundos comenzó a salir humo, lo desconectamos. Luego nos pasaron un potenciómetro que tenía las patitas para conectarlo directo a la proto.


- Cuando ya habíamos terminado de tomar decisiones como que el poema se iba a mostrar entero, tendría dos animaciones, y las funciones de los componentes que agregamos, mandamos el código al Arduino y nos percatamos de que habían partes que se leían bien, pero cuando empezaba a mostrarse la continuación del poema, nos percatamos de que nuevamente los versos eran muy largos y estos se mezclaban junto a los versos siguientes, por lo que tuvimos que probar distintos valores hasta que el poema estuviese legible y además cupiera todo dentro del rango del potenciómetro.

Video problema:  
https://www.youtube.com/shorts/l3qSqMJfn6Y

- En problemas más comunes, tuvimos muchas confusiones con murciélagos y paréntesis que nos faltaban o sobraban, o teníamos mal anotadas ciertas cosas, como haberle puesto un nombre, luego cambiarle el nombre pero no cambiarlo a lo largo del código. O colocamos variables pero no las declaramos antes, nos faltaban puntos y comas, o comas, o poníamos mayúsculas o tildes.

# Codigo final
1. Incluye librerías, tipografías, carpetas de animaciones, pantalla. 
 ```cpp
//primero lo primero
//llamar a la biblioteca de las
//cosas que queremos usar
//para que esto funcione
//incluir librerias
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Fonts/FreeSans9pt7b.h>
//librería de la fuente Sans Serif
#include <Fonts/FreeSerifItalic9pt7b.h>
//carpeta animación pluma
#include "animacion.h"
//carpeta animación pollo
#include "pollo.h"
//definir el tipo de pantalla que estamos usando
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C
```
2. Botón y potenciómetro
 ```cpp
//definir conexión del botón
int patitaBoton = 3;
int lecturaBoton = 0;


//definir conexión del pote
int patitaPot = A0;
int lecturaPot = 0;
//crear variable pollo
int pollo = 0;
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
```
3. Poema inglés y español
```cpp
//Versos en inglés
//Los versos estan ordenados
//a conveniencia
//por el tamaño de la tipografía
const char *versos[] = {


  "Hope is the thing",
  "with feathers",
  "That perches in",
  "the soul",
  "and sings the tune",
  "without the words",
  "and never stops",
  "at all...",
  "And sweetest in",
  "the gale is heard;",
  "And sore must",
  "be the storm",
  "That could abash",
  "the little bird",
  "That kept",
  "so many warm",
  "I've heard in the",
  "chillest land",
  "And on the",
  "strangest sea;",
  "Yet, never,",
  "in extremity,",
  "It asked a crumb of me",
  " ",
  "-Emily Dickinson"


};




//Versos en español
//estos versos también están
//ordenados a conveniencia
const char *


[] = {


  "La esperanza",
  "es algo",
  "Con plumas",
  "Que se posa en",
  "el alma",
  "que canta su",
  "cancion",
  "sin palabras",
  "y jamas",
  "se calla",
  "Y se oye mas",
  "dulcemente",
  "en la tempestad,",
  "Y muy fuerte",
  "debe ser",
  "la tormenta",
  "Que pudiera",
  "acobardar al",
  "pajarito",
  "Que a tantos",
  "le dio calor",
  "La he oido en la",
  "tierra mas fria",
  "Y en el mar",
  "mas extrano",
  "Pero nunca,",
  "en la adversidad,",
  "Me pidió una",
  "migaja",
  "-Emily Dickinson"


};
```
4. void setup
```cpp
//solo se inicia una vez
void setup() {


  Serial.begin(9600);


//patitaBoton recibe información
  pinMode(patitaBoton, INPUT);


//Llamando a pantalla
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {


    Serial.println("SSD1306 allocation failed");


    for (;;);


  }


  display.clearDisplay();


//cosas tipograficas
  display.setTextSize(1);


  display.setTextColor(SSD1306_WHITE);


  display.setFont(&FreeSerifItalic9pt7b);


}

```
5. void loop, lecturas elementos, animaciones, 
```cpp
void loop() {


//Leer boton
  lecturaBoton = digitalRead(patitaBoton);


//Leer potenciometro
  lecturaPot = analogRead(patitaPot);


//El potenciómetro cumplirá la función de
//desplazar el poema hacia arriba o hacia abajo
  int y = map(lecturaPot, 0, 1023, 20, -900);




//Aparece un frame del pollo
//luego +1 aparece el otro
//y así sucesivamente
  pollo++;
//La animación empieza en el 0 y cuando pasa el décimo frame
//se reinicia
  if (pollo >= pollo_allArray_LEN) {
    pollo = 0;
  }




  display.clearDisplay();


//Poema en español
//si el botón está presionado
//se muestra el poema en español
  if (lecturaBoton == 1) {


//posición del poema en y variable
    int posicionY = y;


//Ordenamos en una formula
//el avance del poema
//i será la variable que cambia mientras corre el poema
    for (int i = 0; i < 30; i++) {


      display.setCursor(0, posicionY);
      display.println(versosEspanol[i]);


//el poema se mueve en y con una separación de 22px entre versos
      posicionY = posicionY + 22;




//si el poema pasa el segundo verso
//se muestran los frames de plumas cayendo
      if (i == 2) {


        display.drawBitmap(
          0,
          posicionY,
          epd_bitmap_frame1,
          128,
          32,
          SSD1306_WHITE
        );


        display.drawBitmap(
          0,
          posicionY + 32,
          epd_bitmap_frame2,
          128,
          32,
          SSD1306_WHITE
        );


        display.drawBitmap(
          0,
          posicionY + 64,
          epd_bitmap_frame3,
          128,
          32,
          SSD1306_WHITE
        );


        display.drawBitmap(
          0,
          posicionY + 96,
          epd_bitmap_frame4,
          128,
          32,
          SSD1306_WHITE
        );


        display.drawBitmap(
          0,
          posicionY + 128,
          epd_bitmap_frame5,
          128,
          32,
          SSD1306_WHITE
        );


        posicionY = posicionY + 170;
      }




//Si pasa el verso 15
//se muestra la animación del pollo
      if (i == 15) {


        display.drawBitmap(
          0,
          posicionY,
          pollo_allArray[pollo],
          128,
          32,
          SSD1306_WHITE
        );


        posicionY = posicionY + 50;
      }


    }


  }


//Poema en ingles
//si el botón no está presionado
//se muestra la versión original
  else {


//posición del poema en y variable
    int posicionY = y;


//Ordenamos en una formula
//el avance del poema
//i será la variable que cambia mientras corre el poema
    for (int i = 0; i < 25; i++) {


      display.setCursor(0, posicionY);
      display.println(versos[i]);


//el poema se mueve en y con una separación de 22px entre versos
      posicionY = posicionY + 25;


//si el poema pasa el segundo verso
//se muestran los frames de plumas cayendo
      if (i == 1) {


        display.drawBitmap(
          0,
          posicionY,
          epd_bitmap_frame1,
          128,
          32,
          SSD1306_WHITE
        );


        display.drawBitmap(
          0,
          posicionY + 32,
          epd_bitmap_frame2,
          128,
          32,
          SSD1306_WHITE
        );


        display.drawBitmap(
          0,
          posicionY + 64,
          epd_bitmap_frame3,
          128,
          32,
          SSD1306_WHITE
        );


        display.drawBitmap(
          0,
          posicionY + 96,
          epd_bitmap_frame4,
          128,
          32,
          SSD1306_WHITE
        );


        display.drawBitmap(
          0,
          posicionY + 128,
          epd_bitmap_frame5,
          128,
          32,
          SSD1306_WHITE
        );


        posicionY = posicionY + 170;
      }




//Si pasa el verso 11
//se muestra la animación del pollo
      if (i == 11) {


        display.drawBitmap(
          0,
          posicionY,
          pollo_allArray[pollo],
          128,
          32,
          SSD1306_WHITE
        );


        posicionY = posicionY + 50;
      }


    }


  }
```

# Resultado final 
https://www.youtube.com/watch?v=SDmdVimu-xw 

https://www.youtube.com/watch?v=w7oqHxpn4oM

# Bibliografía 

AleCondeando. (22 de septiembre de 2019). Funcion Millis con Arduino [Video]. YouTube. https://www.youtube.com/watch?v=yyYjdyGImFM

Arduino. (s.f.). Digital Pins. Arduino Documentation. https://docs.arduino.cc/learn/microcontrollers/digital-pins/

Arduino. (s.f.). map(). Arduino Documentation. https://docs.arduino.cc/language-reference/en/functions/math/map/

Burgess,P.(2012, 29 julio). AdaFruit GFX Graphics Library. Adafruit Learning System. https://learn.adafruit.com/adafruit-gfx-graphics-library/using-fonts 

Dickinson, E. (s. f.). “Hope” is the thing with feathers (254). Academy of American Poets. https://poets.org/poem/hope-thing-feathers-254

Recursos
https://www.pixilart.com/

https://javl.github.io/image2cpp/ 

