# proyecto 1

***Integrantes:***

> *Magdalena Balart (magdalenabalart)*
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  
*Catalina Oyadenel (catalinaoyanedel-01)*&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  
*Yaira Ruiz (yairaruiz)*&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  
>*Marcela Zuñiga (marcezm)*


(Todo este proceso, o gran parte de él, fue documentado en un documento de Google compartido para poder ir trabajando en conjunto. Esto también facilitó después agregar la información a GitHub, ya que fuimos rellenando y ordenando el contenido según la estructura que ya teníamos definida)

## Poema a trabajar

### Gansos salvajes - Mary Oliver

> "No tienes que ser buena.
>
> No tienes que recorrer el desierto de rodillas, arrepintiéndote.
>
> Sólo deja que el suave animal de tu cuerpo ame lo que ama.
>
> Háblame del dolor, del tuyo, yo te hablaré del mío.
>
> Mientras tanto, el mundo sigue.
>
> Mientras tanto, el sol y las claras piedritas de la lluvia
>
> recorren los paisajes, caen
>
> sobre los prados y los árboles frondosos, las montañas y los ríos.
>
> Mientras tanto, los gansos salvajes, allá arriba, en el cielo azul y limpio,
>
> emprenden rumbo de vuelta a casa.
>
> Seas quien seas, por más sola que te sientas,
>
> el mundo está ahí para tu imaginación, llamándote,
>
> como los gansos salvajes, rudamente, emocionante:
>
> anunciando una y otra vez
>
> tu lugar entre todo lo que existe."


Elegimos este poema ya que sentimos que representa la autoexigencia y la idea de tener que ser perfecta en los distintos ámbitos de la vida, dando la posibilidad de luchar contra eso, de rendirse ante las expectativas que están impuestas y darse el tiempo de existir, contemplar y tratarse con más autocompasión.

### biografía autora 
	
Mary Oliver (1935–2019) fue una poeta estadounidense cuya obra estuvo profundamente ligada a la naturaleza y a la observación de la vida cotidiana. Pasó gran parte de su vida en Provincetown, Massachusetts, donde los bosques, animales y paisajes cercanos al mar se volvieron parte constante de su escritura. Sus poemas hablan de la vida, la muerte, el dolor y el asombro desde un lenguaje sencillo y cercano. A lo largo de su carrera publicó numerosos libros y recibió reconocimientos como el Premio Pulitzer de Poesía en 1984 y el National Book Award en 1992. Su obra se caracteriza por una mirada atenta y sensible hacia el mundo, encontrando en lo pequeño una forma de pensar sobre cómo vivimos.


### Licencia

El poema está bajo la licencia de copyright, donde todos los derechos están reservados, pero se puede utilizar bajo el concepto legal del uso legítimo, ya que es sin fines de lucro y con propósitos educativos. "Proyecto académico / Fragmento de 'Wild Geese' por Mary Oliver / Uso educativo no comercial"

> "No tienes que ser buena.
>
> No tienes que recorrer el desierto de rodillas, arrepintiéndote.
>
> Sólo deja que el suave animal de tu cuerpo ame lo que ama.
>
> Háblame del dolor, del tuyo, yo te hablaré del mío.
>
> Mientras tanto, el mundo sigue."

© Wild Geese, 1986 Mary Oliver

## Proceso código

## Martes 25 de agosto

Empezamos por analizar el código que nos dieron de ejemplo, viendo que era lo que nos servía y lo que no. Eliminamos lo que era animación y movimiento de texto, dejando solo el que se desplaza a la izquierda y reemplazando el texto por el primer verso de nuestro poema hasta que funcionara. En esta etapa tuvimos una serie de errores en cuanto a cómo editábamos las propiedades del texto, algunos ejemplos de estos es que nos quedaba la tipografía expandida, desfasada o superpuesta con la otra frase.

`1,5 display size`

![errores](./imagenes/error1.png)

`1 display size`

![errores](./imagenes/error2.png)


![errores](./imagenes/error3.png)

Estas pruebas y errores nos ayudaron a entender de mejor manera el funcionamiento de el código:

+ Textos sobrepuestos: al utilizar el mismo `setCursor()` para dos textos estos quedaban en la misma posición. Es necesario cambiar las coordenadas para separar las líneas.

+ Uso de `display.clearDisplay()`: al ponerlo en el lugar incorrecto de el codigo este nos borraba el texto de manera inmediata después de mostrarse, `clearDisplay()` se debe utilizar cuando queremos eliminar un contenido para mostrar uno nuevo.

+ Instrucciones: el orden de `display.display()`, `delay()` y `clear.display()` afecta directamente lo que se muestra y por cuánto tiempo.


Ejemplo de la estructura inicial:

```cpp
void testscrolltext(void) {
  
 display.setTextSize(1); // Draw 2X-scale text
  display.setTextColor(SSD1306_WHITE);

  // primer verso 
  display.setCursor(10, 0);
  display.println(F("No tienes")); // primera linea de texto
  display.setCursor(0, 10);
  display.println(F("que ser buena.")); // segunda linea de texto
 
  display.display();      // Show initial text
  delay(2500);

  // borrar primer verso
  display.clearDisplay();

  // segundo verso parte 1
  display.setCursor(0, 0);
  display.println(F("No tienes que"));
  display.setCursor(0, 10);
  display.println(F("recorrer el"));
  display.setCursor(0, 20);
  display.println(F("desierto de"));

  display.display();
  delay(2500);
```

## Viernes 28 de agosto

En esta clase terminamos de incorporar todos los versos al código, definimos el diagrama de flujo para estructurar la interacción, comenzamos a desarrollar la animación y organizamos los componentes en la protoboard. También comprobamos que cada componente funcionara por separado y empezamos a programarlos.

### Organización de la estructura del código

El viernes también para ordenar la estructura del código, utilizamos un prompt en ChatGPT que nos ayudó a transformar la idea general del proyecto en una lógica más clara y menos abstracta.

### Prompt utilizado

Según mis apuntes, quiero ordenar correctamente la estructura del código para Arduino usando char. Entiendo que primero debería incluir las librerías necesarias para la pantalla OLED, luego configurar la pantalla en el código y definir las conexiones del botón y del potenciómetro. Después debería declarar los textos que utilizará el proyecto, como el texto de licencia, el título del poema, los versos y el nombre de la autora, pero no tengo claro en qué momento conviene declarar las variables, crear funciones o si realmente es necesario utilizar una clase.
La interacción debería funcionar así: al iniciar, aparece el texto de licencia; luego se ejecuta una pequeña animación; después aparece un mensaje de “Presiona el botón” que parpadea. Al presionar el botón se muestra el título del poema y, desde ahí, cada nueva presión muestra uno de los cinco versos, almacenados en un array de char. Una vez mostrado el quinto verso, la pantalla se limpia y recién en ese momento se habilita el potenciómetro. Al moverlo, debería revelarse progresivamente, letra por letra, el nombre de la autora, utilizando el valor del potenciómetro para determinar cuántas letras mostrar y un for para recorrer los caracteres correspondientes.
Finalmente, al detectar una doble presión del botón, todo el sistema debería reiniciarse y volver al texto de licencia inicial.
Necesito ayuda para ordenar esta lógica en la estructura correcta de un programa de Arduino: qué debe ir primero, qué corresponde a variables, qué debería resolverse con funciones, si hace falta una clase y cómo organizar después `setup()` y `loop()`.

### Respuesta
```text
Para ordenar correctamente el código, conviene separar primero los elementos que existen durante todo el programa de aquellos que ocurren durante la ejecución.

Al comienzo deberían ir las librerías necesarias para trabajar con la pantalla OLED, como `Wire`, `Adafruit_GFX` y `Adafruit_SSD1306`. Después se configura el objeto `display`, que representa la pantalla, y se declaran los pines correspondientes al botón y al potenciómetro. Esta primera parte permite definir el hardware con el que trabajará Arduino.

Luego deberían declararse todos los textos que el programa necesita tener disponibles desde el inicio. Como queremos trabajar con `char`, aquí se pueden almacenar el texto de licencia, el título del poema, los cinco versos y el nombre de la autora. Los versos pueden organizarse en un arreglo como `const char *versos[]`, ya que necesitamos acceder a cada uno de manera individual según la cantidad de veces que se presione el botón.

Después vienen las variables que permiten recordar qué está ocurriendo durante la experiencia. Por ejemplo, una variable `versoActual` puede indicar si estamos en el verso 0, 1, 2, 3 o 4. También necesitamos una variable que indique en qué etapa del programa estamos, ya que el botón no realiza siempre la misma función. Al principio permite mostrar el título, después avanzar entre los versos y, finalmente, detectar el doble clic que reinicia el sistema.

Para este proyecto no parece necesario crear una clase propia. Una clase tendría más sentido si quisiéramos crear un objeto más complejo que contuviera sus propios versos, animaciones y comportamientos. En este caso, utilizar variables, arreglos y funciones resulta más claro.

Después de las variables conviene crear funciones para separar los distintos comportamientos del proyecto. Por ejemplo, una función para mostrar la licencia, otra para ejecutar la animación, otra para mostrar el aviso de “Presiona el botón”, otra para mostrar el título, otra para los versos, otra para la aparición de la autora y otra para reiniciar la experiencia.

El `setup()` debería encargarse de preparar el sistema cuando Arduino se enciende. Aquí se configura el botón con `pinMode`, se inicia la pantalla OLED, se limpia y se establecen propiedades generales como el color y el tamaño del texto. El potenciómetro puede estar conectado desde el principio, aunque su lectura solo se utilizará cuando la interacción llegue a esa etapa.

El `loop()` será el encargado de controlar la secuencia completa. Primero se muestra la licencia y luego la animación. Después aparece el mensaje de “Presiona el botón”. Al detectar la primera presión se muestra el título y, desde ese momento, cada nueva presión muestra `versos[versoActual]` y aumenta el valor mediante `versoActual++`.

Cuando se ha mostrado el quinto verso, el programa cambia de etapa. La pantalla se limpia y comienza a utilizarse la lectura del potenciómetro mediante `analogRead()`. Este valor se transforma en una cantidad de letras que deben aparecer.

El `for` no controla el potenciómetro. El potenciómetro determina cuántas letras deben mostrarse y el `for` recorre el nombre de la autora hasta esa posición. Por ejemplo, si el valor corresponde a cuatro letras, el `for` recorre `autora[0]`, `autora[1]`, `autora[2]` y `autora[3]`.

Finalmente, en esta última etapa el botón cambia nuevamente de función. En vez de avanzar versos, se utiliza para detectar dos presiones rápidas. Al reconocer un doble clic, una función de reinicio devuelve `versoActual` a 0, cambia la etapa al inicio, limpia la pantalla y vuelve a comenzar desde el texto de licencia.

La estructura general del código queda entonces organizada de la siguiente manera:

1. Librerías.
2. Configuración del hardware.
3. Textos en `char`.
4. Variables de estado.
5. Funciones.
6. `setup()`.
7. `loop()`.
```
Con este texto logramos dirigir de forma más ordenada el proceso de construcción del código, evitando enredarnos con los nuevos conceptos y estructuras que íbamos incorporando al proyecto.

### Interacción 
Para realizar el diagrama, utilizamos Chat GPT y utilizamos el siguiente prompt:

_"Crea estructura conceptual del siguiente flujo para trabajar Arduino con pantalla pantalla OLED I2C SSD1306, con potenciómetro y botón._

_La estructura debe entenderse como una secuencia de interacción progresiva. Al iniciar el sistema, la pantalla muestra primero un texto de licencia y una pequeña animación. Después aparece un aviso que invita a presionar el botón. Con esa primera presión se presenta el título del poema y cada nueva presión del botón permite avanzar verso por verso: la primera muestra el verso 01, la segunda el verso 02, la tercera el verso 03, la cuarta el verso 04 y la quinta el verso 05._

_Solo una vez que se ha mostrado el quinto verso, y por lo tanto después de completar las cinco presiones correspondientes a los versos, la pantalla se limpia y se habilita el uso del potenciómetro. Aunque este se encuentre conectado físicamente desde el inicio, el programa debe ignorar su lectura hasta llegar a esta etapa. Al mover el potenciómetro, el nombre de la autora debe revelarse progresivamente, letra por letra, según la posición del control. Finalmente, cuando el sistema se encuentre en esta última etapa, una doble presión rápida del botón debe reiniciar toda la experiencia y volver al texto de licencia inicial."_

Nos dio de resultado el orden del diagrama, el cual rediseñamos y quedó el siguiente resultado:

![diagrama de flujo](./imagenes/diagrama.png)

### Animación
Para poder realizar la animación, primero elegimos un video en pixabay subido por Bell Alvarez. Gracias a su licencia, desde esta página se permite usar el contenido gratis,  sin tener que dar crédito al autor (aunque siempre es apreciado) y modificar o adaptar el contenido en obras nuevas. 

Elegimos este video donde se muestran a gansos salvajes volando, ya que referencia explícitamente el título y versos del poema, donde se utilizan como un recurso para hacerle recordar al receptor que hay un mundo para observar más allá  de su mente, y para aceptar nuestra propia naturaleza, como la de un suave animal.

https://pixabay.com/es/videos/ganso-salvaje-aterrizaje-de-gansos-342468/

Lo primero que hicimos fue pasar el video a Adobe Premiere Pro, editarlo para dejarlo en blanco y negro y sacar frames, quedando este resultado

![imagen frames](./imagenes/animacion.png)

Luego, pasamos estos frames a esta herramienta https://javl.github.io/image2cpp/, donde los convirtió en hexadecimales y a código de Arduino.

Parte del código, ejemplo con un frame:

```cpp
// 'frames animacion_1', 128x32px
const unsigned char epd_bitmap_frames_animacion_1 [] PROGMEM = {
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x31, 0xfe, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0xf0, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbf, 0xf1, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc1, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x83, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf3, 0xff, 0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf1, 0xfc, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe3, 0xf8, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfa, 0x07, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xff, 0x9f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x9f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe
};
```

Se intentó colocar directamente en donde traía la animación el código de ejemplo, pero no funcionó, así que le preguntamos a Gemini AI por qué y nos dio la siguiente respuesta:

_"El problema es que tienes definidos los cuadros de tu nueva animación en el arreglo epd_bitmap_allArray, pero nunca llamas a ninguna función que los dibuje dentro de setup() o loop(). Para que la animación se muestre en tu pantalla OLED, debes recorrer las imágenes del arreglo y pintarlas con display.drawBitmap()."_

Así que se le pidió a Gemini que integrara la animación dentro de nuestro código considerando la acotación anterior, y funcionó.

![integrar animación](./gifs/avance-animacion.gif)

### Proceso componentes

Durante este día pudimos avanzar principalmente en la organización y conexión de los componentes dentro de la protoboard y el Arduino. Una de las primeras cosas que hicimos fue revisar cómo debíamos distribuir las conexiones para que pudieran funcionar correctamente sin interferirse entre ellos. Antes de intentar conectar todo al mismo tiempo el Seba (gracias seba :-).) nos recomendó probar cada componente por separado, lo que nos permitió identificar si existía algún problema específico en el funcionamiento de cada uno.

Primero trabajamos con el potenciómetro. Realizamos las conexiones correspondientes y lo probamos utilizando el código para comprobar que la lectura de sus valores funcionara correctamente. Luego hicimos un procedimiento similar con el botón para comprobar que al presionarlo el código pudiera detectar correctamente el cambio de estado.

Una vez que comprobamos que ambos componentes funcionaban de manera independiente, tuvimos que conseguir que los dos pudieran estar conectados y funcionar al mismo tiempo dentro de una misma protoboard. Pudimos entender mejor cómo ordenar las conexiones dentro de la protoboard y conectarlo al Arduino. Después de realizar las conexiones, volvimos a probar el circuito utilizando el código, que fue importante porque no solo queríamos comprobar que los componentes estuvieran conectados físicamente sino que el código pudiera correr correctamente la información de ambos al mismo tiempo.

````
//1. Declaración y prueba de los componentes
//El primer paso fue comprobar que cada componente funcionara de manera individual antes de integrarlos en una misma interacción.
//Por esto, la primera parte del código corresponde a la declaración de los componentes que vamos a utilizar: pantalla OLED, botón, LED y potenciómetro.

```cpp
// Bibliotecas necesarias para utilizar la pantalla OLED
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Pantalla OLED: declaramos sus características principales
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C

// Creamos el objeto que representa la pantalla
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Componentes
// Es importante revisar que los pines coincidan con las conexiones físicas
const int potenciometro = A0;
const int buttonPin = 12;
const int ledPin = 13;
````

En esta parte primero se incluyen las bibliotecas necesarias para trabajar con la pantalla OLED y luego se definen sus características. Después se crea el objeto `display`, que utilizaremos para controlar la pantalla desde el código.

Finalmente, se declaran los pines correspondientes al potenciómetro, botón y LED, de manera que Arduino pueda identificar dónde está conectado cada componente.


![ejemplo](./gifs/componentes.gif)

## Martes 01 de septiembre

Este día tras la explicación de Aarón, se ordenó el código para que estuviera más estructurado y simplificar su extensión en cuanto a las funciones del texto, se conectaron los componentes a la pantalla y se agregaron pasos de la interacción. por otro lado se avanzó en el prototipo de la carcasa y su conceptualidad

### Organización de la estructura del código

Para esta parte fuimos ordenando el código por secciones, trabajando cada una por separado para entender mejor su función dentro del proyecto. Primero comenzamos con las **librerías**, que ya habíamos configurado en la clase anterior y que funcionaban como la base de nuestro código.

```cpp
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Pantalla OLED aquí declaramos la pantalla y sus características
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C

// Tipo de objeto 
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Componentes, importante revisar que los pin estén correctos 
const int potenciometro = A0;
const int buttonPin = 12; // pushbutton pin
const int ledPin = 9;    // LED pin
```

## 2. Declaración de la animación

El segundo paso en la estructura del código fue declarar la animación. Al principio incorporamos toda la animación directamente dentro del código principal, pero esto agregaba demasiadas líneas y hacía que el archivo fuera más difícil de leer y ordenar.

Para solucionarlo, movimos la animación a un **New Tab**, una pestaña adicional dentro del mismo proyecto de Arduino. De esta forma el código de la animación quedó separado del código principal pero siguió formando parte del mismo programa. Esto funciona como enlazar otro archivo al código principal.

Así, en vez de tener toda la declaración de la animación escrita en un solo archivo, desde el código principal simplemente hacemos el llamado al contenido de esa pestaña cuando necesitamos utilizarla.

```cpp
// 4. DATOS VISUALES
// Aquí estamos llamando al código donde tenemos los cuadros de la animación
#include "cuadros.h"
```

## 3. Declaración del poema, versos y textos generales

El tercer paso fue declarar todos los textos que íbamos a usar en el proyecto, siguiendo lo que nos enseñó Aarón sobre `char` y `arrays`.

En este caso usamos `const char`, porque los textos del poema no iban a cambiar durante la realización  del programa. `const` indica justamente que ese contenido se mantiene fijo y no debería modificarse.

Para los versos usamos un `array`, ya que necesitábamos guardar varias frases y poder ir mostrándolas una por una según la interacción.

Al principio los versos estaban declarados así:

```cpp
const char* versos[] = { 
  "No tienes", 
  "que ser buena",
  "No tienes", 
  "que recorrer el desierto", 
  "de rodillas", 
  "arrepintiendote" 
};
```
Cuando lo probamos, nos dimos cuenta de que varias frases no alcanzaban a entrar bien en la pantalla OLED. Por eso tuvimos que reorganizar la forma en que estaban divididos los textos, pensando en el espacio disponible de la pantalla y en cómo queríamos que se fueran mostrando.

A partir de ese error aprendimos a usar `\n`, que permite hacer un salto de línea dentro de un mismo texto.

```cpp
// TEXTOS DEL PROYECTO 

const char* partesVersos[] = {

  // Verso 1
  "No tienes\nque ser buena.",

  // Verso 2 - parte 1
  "No tienes que\nrecorrer el\ndesierto de",

  // Verso 2 - parte 2
  "rodillas,\narrepintiendote.",

  // Verso 3 - parte 1
  "Solo deja que\nel suave animal",

  // Verso 3 - parte 2
  "de tu cuerpo\name lo que ama.",

  // Verso 4
  "Hablame del dolor,\ndel tuyo,\nyo te hablare del mio.",

  // Verso 5
  "Mientras tanto,\nel mundo sigue."
};

const char autora[] = "Mary Oliver";
const char titulo[] = "Gansos salvajes";
const char instruccionPot[] = "Gira potenciometro";

const char* mensajeBoton[] = {
  "Presiona boton",
  "para leer"
};
```

## 4. Variables de control

El cuarto paso fue definir las **variables de control**, que son las que el programa usa para ir recordando qué está pasando durante la interacción. Por ejemplo, cuántas veces se ha apretado el botón, qué verso corresponde mostrar, cuál es el estado actual del botón, qué valor está entregando el potenciómetro o en qué etapa general del proyecto estamos.

Al principio teníamos este bloque:

```cpp
// 4. VARIABLES DE CONTROL

int etapa = 0;
int buttonState = 0;
int lastButtonState = 0;
int parteActual = 0;
int valorPot = 0;
int letrasMostrar = 0;

unsigned long tiempoUltimoClick = 0;
const unsigned long intervaloDobleClick = 400;
```

En esta primera versión también habíamos agregado tiempoUltimoClick e intervaloDobleClick, porque estábamos considerando desde el principio la lógica para detectar una doble presión del botón. Finalmente simplificamos esta parte y dejamos solamente las variables que necesitábamos para controlar el recorrido principal del proyecto:
```cpp
// 4. VARIABLES DE CONTROL

int etapa = 0; // Guarda en qué etapa general del programa estamos
int buttonState = 0;
int lastButtonState = 0;
int parteActual = 0;
int valorPot = 0;
int letrasMostrar = 0;
```

Esta parte la logramos entender bastante bien pero al principio no nos resultaba tan obvio por qué casi todas las variables comenzaban en 0, así que tuvimos que pedirle a ChatGPT que nos explicara la lógica. En este caso, el 0 funciona como un estado inicial: antes de que ocurra cualquier interacción, todavía no se ha avanzado de etapa, no se ha mostrado ningún verso y no se ha leído un valor útil del potenciómetro.

También aprendimos que en programación muchas veces se comienza a contar desde 0. Por ejemplo, si los versos están guardados en un array, el primer verso se encuentra en la posición 0, el segundo en la posición 1, y así sucesivamente. Por eso iniciar algunas de estas variables en 0 permite que el programa parta desde el primer elemento y avance de forma ordenada.

## 5. Declaración de funciones

El quinto paso fue declarar las funciones que iba a tener el programa. Esta parte fue más sencilla de entender, porque básicamente consistía en **ponerle un nombre a cada acción que queríamos que ocurriera** dentro de la interacción.
```cpp
// 5. DECLARACION DE FUNCIONES

void mostrarAnimacion();
void mostrarMensajeBoton();
void mostrarTitulo();
void mostrarVerso();
void mostrarAutora();
void revisarBoton();
void revisarDobleClick();
void reiniciarProyecto();
```

Para entender esta lógica nos sirvió bastante el primer ejercicio que hicimos donde tuvimos que representar un autorretrato o distintas acciones cotidianas mediante código. Ese ejercicio ya nos había ayudado a pensar una secuencia compleja como un conjunto de acciones más pequeñas y separadas, por lo que acá fue más fácil aplicar la misma idea.

## 6. `setup()`

El sexto paso fue armar el `setup()`. Esta parte sí tuvimos que pedirle ayuda a ChatGPT, porque entendíamos para qué servía, pero todavía no manejábamos todos los requerimientos del lenguaje ni qué instrucciones tenían que ir dentro.

El `setup()` sirve para **preparar todo cuando Arduino se enciende** y se ejecuta una sola vez.

La primera versión que armamos fue esta:

```cpp
// 6. SETUP

void setup() {

  // Preparar componentes
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);

  // LED comienza apagado
  digitalWrite(ledPin, LOW);

  // Iniciar pantalla OLED
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    for (;;);
  }

  // Limpiar pantalla
  display.clearDisplay();
  display.display();

  // Comenzar desde el inicio
  etapa = 0;
}
```

Después, al ir modificando algunas funciones del proyecto, también tuvimos que ajustar el `setup()`. En esta nueva versión chatgpt nos ayudó a agregar la nueva lectura inicial del botón con `buttonState = digitalRead(buttonPin);` y luego que se guardara ese mismo valor en `lastButtonState`. Esto se hizo para que Arduino supiera desde el comienzo en qué estado estaba realmente el botón y así evitar que detectara una presión falsa apenas se encendía el sistema. También agregamos `mostrarMensajeBoton();`, para que una vez que todos los componentes estuvieran preparados, apareciera directamente en la pantalla el mensaje inicial de la interacción.

y quedó así: 

```cpp
// 6. SETUP

void setup() {

  // Preparar componentes
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);

  // LED comienza apagado
  digitalWrite(ledPin, LOW);


  // Iniciar pantalla OLED
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    for (;;);
  }


  // Limpiar pantalla
  display.clearDisplay();
  display.display();


  // Leer estado inicial del boton
  // Esto ayuda a evitar una falsa presion al comenzar
  buttonState = digitalRead(buttonPin);
  lastButtonState = buttonState;


  // Comenzar desde el inicio
  etapa = 0;


  // Mostrar mensaje inicial
  mostrarMensajeBoton();
}
```

## 9. `loop()`

Después armamos el `loop()`, que a diferencia del `setup()` se ejecuta constantemente mientras Arduino está encendido. En esta parte organizamos la interacción según el valor de `etapa`, para que el programa supiera qué tenía que hacer en cada momento.

```cpp
void loop() {

  // ETAPA 0: animacion inicial
  if (etapa == 0) {

    mostrarAnimacion();
    mostrarMensajeBoton();

    etapa = 1;
  }

  // ETAPAS 1, 2 y 3:
  // esperar presiones normales del boton
  else if (etapa >= 1 && etapa <= 3) {

    revisarBoton();
  }

  // ETAPA 4:
  // potenciometro + doble clic para reiniciar
  else if (etapa == 4) {

    mostrarAutora();
    revisarDobleClick();
  }
}
```

En esta parte también tuvimos que pedirle ayuda a ChatGPT, si bien entendíamos la lógica general del `loop()` y que este debía ir revisando constantemente en qué etapa estaba el proyecto, preferimos guiarnos con un ejemplo para ir acostumbrándonos a cómo se estructura este tipo de código y normalizar el uso de `if`, `else if` y las condiciones dentro de Arduino.

## 10. Funciones

Después armamos las **funciones**, siguiendo el mismo orden en que ocurrían las acciones dentro del recorrido. La idea era separar cada acción para no mezclar todo dentro del `loop()`, partiendo por las funciones más simples y dejando para el final las que tenían una lógica más compleja, como `revisarBoton()` y `revisarDobleClick()`.

(no adjunté esta parte del código ya que es muy largo y prefiero que se profundice el proceso ya que esta parte del código se puede ver en la carpeta ofical de este)

En esta parte fuimos construyendo cada función según lo que necesitábamos que pasara en la experiencia: `mostrarAnimacion()` reproduce los cuadros de la animación, `mostrarMensajeBoton()` y `mostrarTitulo()` muestran los textos correspondientes, `mostrarVerso()` controla los versos y el LED, y `mostrarAutora()` relaciona el valor del potenciómetro con la cantidad de letras visibles. Después, `revisarBoton()` organiza el avance entre las etapas, `revisarDobleClick()` detecta las dos presiones seguidas y `reiniciarProyecto()` devuelve todas las variables a su estado inicial.

En esta parte también fuimos pidiendo ayuda a ChatGPT, pero no para construir todas las funciones de una sola vez. Primero intentábamos armar por nuestra cuenta la parte más simple de cada `void`, entendiendo qué acción queríamos que realizara y después mandábamos esa función de forma individual para corregirla, completarla o entender mejor la sintaxis que nos faltaba.

Así fuimos trabajando función por función y **apilándolas de a poco**, en vez de pedir el bloque completo desde el comienzo. Esto nos sirvió para no perdernos dentro de un código demasiado largo y para ir entendiendo qué hacía cada parte antes de pasar a la siguiente.

### Ajustes pendientes para la siguiente clase

Hasta este punto habíamos avanzado harto en la construcción del código y ya teníamos funcionando gran parte del recorrido pero nos quedaron algunos detalles por corregir y probar en la siguiente clase.

Uno de los principales problemas estaba en el botón. A veces, al presionarlo una sola vez, el programa avanzaba inmediatamente por más de un verso. En base una explicación que dieron en clases entendimos que era por el **rebote mecánico del botón**, ya que físicamente puede cambiar muy rápido entre `HIGH` y `LOW` y Arduino puede interpretar una sola presión como varias.

Como queríamos que la lógica fuera **una presión = una pantalla**, quedamos con la idea de ajustar el código para que después de aceptar una presión Arduino espere a que el botón sea soltado antes de permitir avanzar nuevamente.

### Proceso componentes

Avance: [LINK YOUTUBE](https://youtube.com/shorts/AT0fQQUXfAs?feature=share)

Habíamos dejado funcionando en la protoboard el botón y el potenciómetro conectados al Arduino. Esto nos permitió tener una base sobre la cual seguir agregando los demás componentes y comprobar que el circuito que habíamos pensado podía funcionar. A partir de esta conexión, durante esta sesión nos enfocamos en incorporar la pantalla y, al mismo tiempo comenzar a pensar cómo llevar todo este sistema desde la protoboard/Arduino hacia la carcasa. Además de conectar la pantalla, extendimos las conexiones de los componentes para que no quedaran limitadas a la posición que tenían en la protoboard.

![IMG](./imagenes/avance01.png)

## Desarrollo carcasa

Por temas de tiempo, decidimos darle prioridad al desarrollo de la carcasa y terminar los últimos detalles relacionados con la organización de los componentes. Esto fue necesario porque ya teníamos una idea más clara de cómo funcionaría el circuito, por lo que podíamos comenzar a tomar decisiones más concretas sobre el espacio que necesitaríamos para instalarlo.

Esta clase fue súper proactiva porque, si bien todas estábamos preocupadas de que todo funcionara como un mismo “cerebro”, cada una se dedicó a avanzar en alguna zona del proyecto, como los componentes, el código, la carcasa y la parte conceptual.


### Viernes 04 de septiembre: Finalización del código 

En esta clase terminamos de ajustar varias cosas del código para que todo funcionara mejor. Aplicamos lo que habíamos visto antes de **separar la animación del código principal**, dejando los cuadros en otra pestaña y llamándolos desde el archivo principal para que quedara más ordenado.

También arreglamos el problema del **rebote del botón**, porque a veces una sola presión hacía que pasara más de un verso. 

También arreglamos el problema del **rebote del botón**, porque a veces una sola presión hacía que pasara más de un verso. Para solucionarlo, después de detectar una presión válida hicimos que Arduino esperara a que el botón se soltara antes de permitir otra.

La idea fue agregar esta espera después de ejecutar la acción del botón:

```cpp
while (digitalRead(buttonPin) == HIGH) {
  delay(10);
}
```

También mantuvimos un pequeño delay(30) como antirrebote inicial

Además, para mejorar la experiencia de usuario, agregamos un botón para iniciar todo el programa en vez de que comenzara automáticamente apenas se encendía Arduino.

Otro cambio fue el LED. Al principio lo teníamos conectado al pin `13`, sin saber que ese pin correspondía al LED integrado de Arduino. Después de averiguarlo, cambiamos el LED externo al pin `9`.

Por último, alargamos un poco la animación, pero no modificando los cuadros, sino desde el código, para que durara más antes de seguir con el resto de la interacción.

Ya teníamos el código funcionando, por lo que solo nos quedó ajustar pequeños detalles y avanzar con la carcasa. 

### Componentes

Con estas conexiones logramos integrar todos los componentes en la misma protoboard y dejarlos preparados para continuar con el proyecto: 

Para conectar el Arduino a la protoboard, primero conectamos 5V del Arduino UNO 4R WIFI,  al VCC de la protoboard y el GND, para poder distribuir la alimentación a los componentes.
Luego conectamos el potenciómetro, dejando la patita 1 conectada a VCC, la patita 3 a GND y la patita central al pin A0 del Arduino. Para el botón, utilizamos una resistencia de 470  conectada a GND, mientras que otra patita del botón se conectó a VCC y la restante al pin 12 del Arduino.
Incorporamos la pantalla, conectando VCC, GND, SDA al pin A4 del Arduino y SCK al pin A5 del Arduino. Finalmente, agregamos un LED, conectando su patita larga al pin 9 y la otra patita a GND mediante una resistencia.

## Materiales

| # | Componente | Cantidad | Especificación |
| --- | --- | --- | --- |
| 1 | Resistencia | 1 | 470 Ω |
| 2 | Potenciómetro | 1 | B20K |
| 3 | Botón | 1 | Pulsador |
| 4 | Arduino UNO R4 WiFi | 1 | Placa de desarrollo |
| 5 | LED | 1 | —  |
| 6 | Resistencia para LED | 1 | — |
| 7 | Cables Dupont | — | Macho/Hembra |
| 8 | Protoboard | 1 | 400 puntos |
| 9 | Cable USB-C | 1 | Para conexión del Arduino |

## Carcasa

Para generar la idea de la carcasa, partimos desde el querer relacionarla al significado del poema y fuimos explorando referentes, hasta llegar a uno que nos llamó la atención por su forma. Este referente en forma de cofre nos hizo pensar en el poema dentro de él, como un tesoro, un recordatorio, algo que se pudiera revisar con cuidado. 

![referente](./imagenes/referente.png)

*(Nuestro referente fue el cyberdeck de CocoasAesthetic, quien convirtió una caja de Dunkin’ Donuts en una consola. Nos interesó cómo utilizó un objeto cotidiano para contener la tecnología y hacer que este también fuera parte del diseño.)*

La idea de este cofre también nos permite mostrar los componentes sin necesidad de que queden tan expuestos, haciendo que formen parte de la experiencia. Al levantar la tapa el usuario podrá encontrarse directamente con la pantalla, el botón y el potenciómetro. De igual manera en la parte inferior se podrá observar el proceso que permite llegar a este resultado: los cables, el Arduino y la protoboard. De esta forma buscamos que la interacción se sienta más cercana y que el usuario pueda ver tanto el resultado como lo que hay detrás de su funcionamiento.

Por lo tanto, la finalidad de la estructura genera esta conversación entre los supuestos de perfección e imperfección, donde hay cosas que se puedan ver más prolijas y otras expuestas, pero sobre todo dejando el poema en el centro como el foco principal para darle su importancia.
Para el proceso durante clases fuimos generando distintos bocetos manteniendo la idea del cofre, mientras avanzabamos definimos la estructura de este y como se distribuyeron los componentes.

En cuanto a la estructura diseñamos el boceto final en Rhino, esto nos ayudó para confirmar medidas y alturas. Una vez que tuvimos el modelo 3D, separamos cada una de sus piezas para enviarlas a corte láser en el cartón, de esta manera ahorramos tiempo y nos aseguramos de que las piezas quedarán en las medidas precisas. 

![boceto Rhino](./imagenes/boceto-final.png)


## Resumen del proceso para llegar al código final

| Paso | Qué hicimos |
|---|---|
| 0 | Experimentamos con el primer código de ejemplo que nos dieron, eliminando cosas que no necesitábamos, probando propiedades del texto y reemplazando el contenido por partes de nuestro poema para entender cómo funcionaba. |
| 1 | Definimos la interacción completa y armamos el diagrama de flujo. |
| 2 | Probamos por separado el botón, el potenciómetro, el LED y la pantalla OLED. |
| 3 | Declaramos las librerías, la pantalla y los pines de cada componente. |
| 4 | Declaramos los textos del proyecto usando `const char` y `arrays`. |
| 5 | Ajustamos los versos al tamaño de la pantalla usando `\n` para los saltos de línea. |
| 6 | Creamos las variables de control para guardar la etapa, el estado del botón, la parte del poema y el valor del potenciómetro. |
| 7 | Declaramos las funciones con `void`, separando cada acción del proyecto. |
| 8 | Armamos el `setup()` para preparar los componentes cuando Arduino se enciende. |
| 9 | Armamos el `loop()` usando etapas para ordenar todo el recorrido. |
| 10 | Fuimos construyendo las funciones una por una, partiendo por las más simples y después apilándolas. |
| 11 | Conectamos todos los componentes y probamos que funcionaran juntos. |
| 12 | Corregimos el rebote del botón para que una presión avanzara solo una pantalla. |
| 13 | Agregamos un botón de inicio y corregimos la conexión del LED externo, cambiándolo del pin `13` al pin `9`. |
| 14 | Separamos finalmente la animación del código principal, dejándola en un `New Tab`, y ajustamos desde el código cuánto tiempo duraba. |
| 15 | Hicimos las últimas pruebas y ajustes hasta dejar funcionando el recorrido completo. |


## Conclusión

En el desarrollo de nuestro Proyecto 01 pudimos trabajar con el poema Gansos salvajes de Mary Oliver, combinando texto, imagen, programación y electrónica. Desde el inicio, nuestra interpretación del poema estuvo relacionada con la autoexigencia y las expectativas de perfección que muchas veces nos imponemos. A partir de esto, buscamos crear una experiencia que permitiera a las personas interactuar con el poema de una forma más personal, introspectiva y pausada.

Nuestro principal aprendizaje durante este proceso fue acercarnos a la programación, entendiendo que programar básicamente consiste en aprender a ordenar nuestras ideas y transformarlas en instrucciones exactas para que el sistema pueda responder de la manera que esperamos. Tuvimos diferentes problemas, tanto con la visualización y organización del texto como con la integración de la animación.

Por otra parte, el desarrollo de la carcasa nos hizo cuestionarnos cómo organizar físicamente los componentes y, al mismo tiempo, cómo integrar a la persona que invitamos a leer el poema para que no fuera solamente una espectadora, sino que pudiera formar parte de la experiencia. Finalmente, buscamos que la interacción reforzara el mensaje del poema: detenerse, dejar de exigirse constantemente y reconocer que cada persona tiene un lugar dentro de todo lo que habitamos.


## Resultado Final

![final](./imagenes/listo.png/)

[LINK YOTUBE]<https://www.youtube.com/watch?v=PrD93Q1XOUg&feature=youtu.be>


