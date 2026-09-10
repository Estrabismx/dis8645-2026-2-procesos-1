# PROYECTO 1 — BITÁCORA DE PROCESO

## Acerca del proyecto


### Integrantes

Isidora Díaz — Natalia Gutiérrez — Carlo Martínez


### Poema y autora


**Pepper Sauce — Malika Booker**

Antes de leerlo queremos informar que el poema contiene situaciones de violencia y abuso que pueden ser sensibles para algunos espectadores.


> 
> I pray for that grandmother, grinding her teeth,  
> one hand pushing in fresh hot peppers, seeds and all, turning  
> the handle of that old iron mill, squeezing the limes, knowing  
>           they will burn and cut raw like acid.
>
> She pours in vinegar and gets Anne to chop five onions  
>           with a whole bulb of garlic,  
>           Chop them up real fine girl, you hear?  
> And Anne dicing, and crying, relieved that no belt has blistered her  
> skin,  
>           no knife handle smashed down onto her knuckles  
> until they bleed for stealing money from she grandmother purse.
>
> I hear she made Anne pour in the oil and vinegar  
>           and stir up that hot sauce, how she hold her down.  
> I hear she tied that girl to the bedposts,  
>           strung her out naked, like she there lying on a crucifix.  
> I hear she spread she out, then say,  
>           I go teach you to go and steal from me, Miss Lady.
>
> I hear she scoop that pepper sauce out of a white enamel bowl,  
>           and pack it deep into she granddaughter’s pussy,  
> I hear there was one piece of screaming in the house that day.
>
>           Anne bawl till she turn hoarse,  
>     bawl till the hair on the neighbours skin raise up,  
>   bawl till she start hiss through her teeth,  
>   bawl till she mouth could make no more sound,  
>  I hear how she turn raw,  
>  how that grandmother leave her there all day,
>
>   I hear how she couldn’t walk or talk for weeks.
>   


   
  
### ¿Qué queremos hacer con el poema?

Elegimos *Pepper Sauce* porque muestra cómo la violencia familiar puede estar conectada con traumas heredados desde la esclavitud y el colonialismo en el Caribe. También elegimos a Malika Booker porque su trabajo habla mucho de memoria, identidad caribeña y de cómo esas heridas históricas siguen presentes entre generaciones.



### Copyright


**Copyright © 2013 Malika Booker. All rights reserved.**

El poema no presenta una licencia Creative Commons o licencia abierta. Su reproducción y la creación de obras derivadas requieren autorización del titular de los derechos, salvo las excepciones legales aplicables a usos educativos, investigación o cita.




## 1. Primer acercamiento al poema


### Elección del poema

Elegimos *Pepper Sauce* de Malika Booker porque nos llamó la atención la forma en que el poema cuenta una situación de violencia familiar a través de algo tan cotidiano como preparar una salsa.

También nos interesó el trasfondo del poema y su relación con la memoria, la esclavitud y el colonialismo en el Caribe.



### Entender el poema


Al leerlo entendimos que el poema cuenta la violencia que Anne vive por parte de su abuela y cómo esta violencia se va haciendo cada vez más fuerte.

También nos llamó la atención que el poema no muestra la violencia de una sola vez, sino que la va aumentando progresivamente. Por eso empezamos a pensar que esa misma progresión podía aparecer en la forma en que el poema se mostraría en la pantalla.



### División del poema


Primero dividimos el poema en sus cinco estrofas y después fuimos separando los versos o palabras que tenían acciones o momentos que queríamos trabajar de manera distinta.

Algunos ejemplos fueron:

`I pray` / `for that` / `grandmother`

`turning the handle of that old iron mill`

`BURN` / `CUT` / `RAW` / `ACID`

`dicing` / `crying`

`I hear`

`crucifix`

`Miss Lady`

`SCREAMING`

`bawl`

El objetivo era que cada parte pudiera tener un comportamiento diferente dependiendo de lo que estaba pasando en el poema.



### ¿Qué queremos que pase en cada parte?


Desde el principio pensamos que la intensidad debía ir aumentando junto con el poema.

Al comienzo queríamos poco texto, movimientos lentos y pausas largas. Después queríamos ir sumando velocidad, tamaño, brillo, movimiento y acumulación de texto.

La primera estrofa parte más tranquila y termina con un cambio fuerte en `BURN`, `CUT`, `RAW` y `ACID`.

En la segunda estrofa aparece más la acción de cortar, por lo que usamos fragmentación y cambios de tamaño en `dicing` y `crying`.

En la tercera estrofa quisimos trabajar la repetición de `I hear`, el movimiento de revolver, el dibujo de `crucifix` y dejar `Miss Lady` sola y más grande.

En la cuarta estrofa agregamos un *trigger warning* y decidimos no representar literalmente la violencia sexual. Queríamos trabajarla principalmente con lentitud, pausas, brillo y acumulación. `SCREAMING` sería uno de los momentos de mayor intensidad.

En la quinta estrofa queríamos que la repetición de `bawl` fuera llenando la pantalla hasta llegar a un punto de saturación. Después todo desaparecería y la intensidad comenzaría a bajar hasta llegar al último verso, que aparecería solo y lentamente.


   

## 2. Primeras pruebas con código


### Strings y arreglos


El inicio del proceso de programación fue a la par con las clases en las que comenzamos a trabajar con `String`, arreglos y `for`. Esto nos permitió encontrar una forma de ordenar el poema dentro del código y trabajar sus versos de manera independiente.

Como queríamos que el proyecto pudiera seguir funcionando fuera de las soluciones propias de Arduino, comenzamos a utilizar arreglos de caracteres para guardar el texto.

```cpp
char nombre[6] = "aaron";
```

A partir de esto entendimos el texto como una secuencia de caracteres y pudimos llevar esa lógica al poema.

> un poemario es un arreglo de páginas → una página es un arreglo de líneas → una línea es un arreglo de caracteres

También comenzamos a utilizar `for` para recorrer conjuntos. Esto después fue útil no solamente para recorrer los versos, sino también para controlar posiciones, movimientos y otras animaciones.



### Variables


Una vez que entendimos cómo trabajar con arreglos, comenzamos a dividir `Pepper Sauce` dentro del código.

Usamos nombres como:

```cpp
e1_v1
e1_v2
e2_v1
```

donde:

* `e` = estrofa
* `v` = verso o fragmento

También dejamos algunas palabras separadas porque necesitaban un comportamiento visual propio:

```cpp
BURN
CUT
RAW
ACID
```

Esta forma de ordenar el poema nos permitió separar el **contenido** de lo que queríamos hacer visualmente con él.




### Pasar el poema a código

Antes de programar cada parte, escribimos dentro del código instrucciones que indicaban qué debía hacer cada verso. Estas instrucciones funcionaron como una guía para ir reemplazando poco a poco las indicaciones por código.

Por ejemplo, para la primera estrofa comenzamos con:

```cpp
// mostrar "I pray for that grandmother" lentamente
// hacer que aparezca primero i pray
// for that
// grandmother
// dejar una pausa al terminar

// mostrar "grinding her teeth"
// aumentar un poco la velocidad respecto a la frase anterior
// hacer que se sienta como el primer cambio de intensidad

// mostrar "turning the handle of that old iron mill"
// mover el texto horizontalmente
// hacer que el texto rebote y se vaya hacía la izquierda

// mostrar "they will burn and cut raw like acid"
// aumentar nuevamente la intensidad
// destacar las palabras "burn", "cut", "raw" y "acid"
// hacer que aparezcan de forma más brusca o rápida
```

La idea era no intentar programar todo de una vez. Primero definíamos **qué debía ocurrir**, y después buscábamos la función o estructura necesaria para hacerlo.



### Primeras funciones


Una de las primeras funciones que desarrollamos fue:

```cpp
escribirLetraPorLetra()
```

Esta recorre el texto carácter por carácter y permite controlar cuánto tiempo pasa entre cada letra.

La lógica era:

```text
I
I p
I pr
I pra
I pray
```

Al cambiar la velocidad podíamos reutilizar la misma función para generar distintas intensidades.

Por ejemplo:

**menos tiempo entre letras → texto más rápido → mayor intensidad**

Para el movimiento del molino creamos:

```cpp
moverMolino()
```

y utilizamos `for` para cambiar la posición del texto horizontalmente:

```text
derecha → izquierda → derecha
```

También creamos:

```cpp
mostrarGolpe()
```

para `BURN`, `CUT`, `RAW` y `ACID`. En este caso la función cambia completamente la apariencia de la pantalla:

```text
pantalla blanca
↓
letras negras
↓
texto grande
↓
aparición rápida
↓
pantalla vacía
```



### ¿Por qué lo hicimos de esta forma?


Desde el comienzo decidimos no crear una animación completamente distinta para cada verso. Como todavía estábamos aprendiendo C++ y trabajando con una pantalla OLED de `128 × 32 px`, nos parecía más útil construir pocas funciones que pudiéramos reutilizar.

Así comenzamos a trabajar con una lógica que se mantuvo durante el proyecto:

```text
VARIABLE
↓
qué texto es

FUNCIÓN
↓
cómo aparece

ESTROFA
↓
combinación de texto y comportamiento
```

Esto nos permitió ir construyendo el poema por partes y modificar los comportamientos sin tener que escribir nuevamente todo el código cada vez.




  

## 3. Interpretación del poema


Antes de comenzar a programar las animaciones, definimos qué queríamos que ocurriera visualmente en cada parte del poema. La idea general era que comenzara con una intensidad baja y que esta fuera aumentando progresivamente, para después disminuir hasta terminar nuevamente en una pantalla vacía.



### Primera estrofa


Al comienzo queríamos trabajar con poco texto, bastante espacio, movimientos lentos y pausas largas.

```cpp
// primera estrofa

// mostrar "I pray for that grandmother" lentamente
// hacer que aparezca primero i pray
// for that
// grandmother
// dejar una pausa al terminar

// mostrar "grinding her teeth"
// aumentar un poco la velocidad respecto a la frase anterior
// hacer que se sienta como el primer cambio de intensidad

// mostrar "one hand pushing in fresh hot peppers, seeds and all"
// mantener una velocidad intermedia
// mostrar el texto de forma más continua

// mostrar "turning the handle of that old iron mill"
// mover el texto horizontalmente
// hacer que el texto rebote y se vaya hacía la izquierda

// mostrar "squeezing the limes, knowing"
// volver a una lectura más estable
// mantener una pausa breve antes del cierre de la estrofa

// mostrar "they will burn and cut raw like acid"
// aumentar nuevamente la intensidad
// destacar las palabras "burn", "cut", "raw" y "acid"
// fondo blanco con letras negras y tamaño de toda la pantalla
// hacer que aparezcan de forma más brusca o rápida

// dejar la pantalla vacía por un momento
// terminar la primera estrofa
````

La primera estrofa establece la lógica inicial de la experiencia: comenzar de manera pausada y aumentar gradualmente la intensidad hasta llegar a los golpes visuales de `BURN`, `CUT`, `RAW` y `ACID`.



### Segunda estrofa


En esta parte aparece constantemente la acción de cortar, por lo que decidimos relacionar la forma de aparición del texto con esa acción.

```cpp
// segunda estrofa

// mostrar "She pours in vinegar and gets Anne to chop five onions"
// mantener una velocidad intermedia
// hacer que el texto avance de forma relativamente continua
// empezar a preparar visualmente la acción de cortar

// mostrar "with a whole bulb of garlic"
// mantener el mismo ritmo
// dejar una pausa breve al terminar

// mostrar "Chop them up real fine girl, you hear?"
// cortar la frase en partes
// mostrar cada parte por separado
// hacer que aparezcan más rápido entre sí
// relacionar la forma de aparición con la acción de cortar

// mostrar "And Anne dicing, and crying"
// continuar con apariciones fragmentadas
// hacer que "dicing" y "crying" aparezcan separadas
// aumentar un poco la tensión agrandando y achicando el texto

// mostrar "relieved that no belt has blistered her skin"
// bajar un poco la velocidad
// mostrar más texto junto
// mantener una lectura más estable antes del siguiente cambio

// mostrar "no knife handle smashed down onto her knuckles"
// hacer que el texto aparezca de golpe
// generar un cambio brusco respecto a lo anterior
// marcar desde aquí un aumento más evidente de violencia

// mostrar "until they bleed"
// mantener la aparición brusca
// destacar "bleed" dejándola sola por un momento

// mostrar "for stealing money from she grandmother purse"
// volver a mostrar más texto junto
// mantener una velocidad intermedia
// dejar una pausa al terminar la estrofa
```

La fragmentación de `Chop them up` busca que la acción de cortar también esté presente en el comportamiento del texto. En `dicing` y `crying`, el cambio de tamaño permite aumentar la tensión sin abandonar el recurso de fragmentación.



### Tercera estrofa


En esta parte comienza a repetirse `I hear`, por lo que decidimos convertir esa repetición en un recurso visual. Cada aparición debía adquirir progresivamente mayor presencia.

```cpp
// tercera estrofa

// mostrar "I hear she made Anne pour in the oil and vinegar"
// mantener una velocidad intermedia
// hacer que "I hear" aparezca primero como una frase que comienza a repetirse en esta parte

// mostrar "and stir up that hot sauce, how she hold her down"
// hacer que "stir up that hot sauce" tenga un movimiento circular o repetitivo, como las burbujas de windows
// relacionar el movimiento con la acción de revolver
// mantener el resto de la frase más estable

// mostrar "I hear she tied that girl to the bedposts"
// volver a mostrar "I hear"
// ir colocando las letras lentamente como máquina de escribir lenta
// mostrar el resto del verso de forma más continua
// hacer que este verso empiece con brillo 0 y suba poco a poco hasta 100%

// mostrar "strung her out naked, like she there lying on a crucifix"
// mantener una aparición más lenta y pesada
// destacar la palabra "crucifix"
// hacer aparecer un dibujo simple de una cruz en píxeles junto a la palabra
// mantener este verso con menos brillo, aprox entre 40% y 50%
// dejar una pausa breve

// mostrar "I hear she spread she out, then say"
// volver a mostrar "I hear"
// hacer que la repetición se empiece a sentir más insistente, llenar la pantalla de la frase
// mantener una velocidad intermedia
// hacer que cada repetición de "I hear" aparezca con más brillo que la anterior

// mostrar "I go teach you to go and steal from me, Miss Lady"
// mostrar primero la frase de forma continua
// separar "Miss Lady" del resto
// hacer que "Miss Lady" aparezca sola y más grande
// dejarla en pantalla por un momento
// dejar una pausa antes de continuar con la siguiente estrofa
```

En esta estrofa incorporamos nuevos recursos: control de brillo, movimiento, dibujo en píxeles y cambios de tamaño. La repetición de `I hear` comienza a adquirir cada vez más presencia dentro de la estrofa.



### Cuarta estrofa


Esta parte contiene el momento más explícito del poema, por lo que decidimos colocar un `trigger warning` antes de comenzar y evitar una representación literal de la violencia sexual.

```cpp
// cuarta estrofa

// mostrar un trigger warning antes de comenzar esta parte
// avisar que la siguiente sección contiene violencia sexual y abuso
// dejar una pausa suficiente para que se pueda leer

// mostrar "I hear she scoop that pepper sauce out of a white enamel bowl"
// volver a usar "I hear" como inicio repetitivo
// mantener una velocidad más lenta y tensa
// mostrar el resto de la frase de forma continua

// mostrar "and pack it deep into she granddaughter’s pussy,"
// evitar una animación demasiado literal
// trabajar principalmente con pausas, lentitud y acumulación
// hacer que la lectura se sienta más pesada que en las estrofas anteriores

// mostrar "I hear there was one piece of screaming in the house that day"
// hacer aparecer "I hear" nuevamente
// destacar "screaming"
// hacer que "screaming" aumente de tamaño o ocupe gran parte de la pantalla
// hacer que en este verso el brillo también aumente progresivamente hasta llegar al máximo
// dejar el resto de la frase aparecer después

// dejar la pantalla vacía por un momento
// antes de dejarla vacía, bajar el brillo poco a poco de 100% a 0%
// marcar el punto de mayor intensidad hasta ahora
```

En esta estrofa la intensidad llega a uno de sus puntos más altos. El brillo y el tamaño trabajan juntos para que `screaming` tenga un peso visual mayor, mientras que la disminución progresiva del brillo permite comenzar a bajar la intensidad.



### Quinta estrofa y final


Para la repetición de `bawl`, queríamos que el texto dejara de desaparecer inmediatamente y comenzara a acumularse. La pantalla debía sentirse cada vez más llena hasta llegar a un punto de saturación.

```cpp
// quinta estrofa

// mostrar "Anne bawl till she turn hoarse"
// empezar a acumular más texto en pantalla
// aumentar la intensidad respecto a la estrofa anterior
// destacar "bawl" como palabra que se repetirá

// mostrar "bawl till the hair on the neighbours skin raise up"
// volver a mostrar "bawl"
// hacer que aparezca más grande o más rápido que antes
// mantener parte del verso anterior visible para generar acumulación

// mostrar "bawl till she start hiss through her teeth"
// repetir nuevamente "bawl"
// seguir aumentando el tamaño o la velocidad
// hacer que la pantalla se sienta cada vez más llena

// mostrar "bawl till she mouth could make no more sound"
// mostrar la última repetición de "bawl"
// alcanzar el punto de mayor acumulación
// hacer que el texto ocupe gran parte de la pantalla

// borrar todo de golpe
// dejar la pantalla completamente vacía
// mantener una pausa más larga

// mostrar "I hear how she turn raw"
// volver a una velocidad lenta
// hacer que aparezca poco texto a la vez
// bajar la intensidad después del momento anterior
// hacer que este verso empiece con brillo bajo y suba suavemente

// mostrar "how that grandmother leave her there all day"
// mantener el ritmo lento
// mostrar la frase de forma continua
// dejar una pausa al terminar


// último verso

// mostrar "I hear how she couldn’t walk or talk for weeks"
// mostrar la frase sola
// mantener una aparición lenta
// dejarla en pantalla durante más tiempo
// hacer que el verso se vaya apagando poco a poco, bajando el brillo hasta 0
// terminar con una pausa larga
// dejar la pantalla vacía al final
```


La quinta estrofa concentra primero la acumulación y luego comienza a bajar la intensidad. Después del momento de mayor saturación, la pantalla queda vacía y el último verso aparece solo y lentamente, terminando nuevamente en negro.



## 4. Cómo funciona el código


El código funciona como un sistema en el que los textos del poema se combinan con distintas funciones de animación. El `loop()` se encarga de mantener el sistema funcionando y de revisar los controles mientras el poema está en reproducción.



### Controles


El proyecto cuenta con tres botones y un potenciómetro. Los botones permiten controlar la reproducción del poema y el potenciómetro permite modificar el tamaño del texto mientras la animación está funcionando.

```text
PLAY → comienza el poema
STOP → detiene el poema
REPEAT → activa o desactiva la repetición
POTENCIÓMETRO → modifica el tamaño del texto
````

Los botones están conectados de la siguiente manera:

```cpp
PLAY → pin 2
STOP → pin 3
REPEAT → pin 4
POTENCIÓMETRO → A0
```

Para evitar que una sola pulsación sea registrada varias veces se agregó `debounce`, utilizando el estado anterior del botón y el tiempo transcurrido desde la última pulsación.



### PLAY, STOP y REPEAT


`PLAY` inicia la reproducción del poema. Una vez que comienza, el código va ejecutando las distintas estrofas en orden.

`STOP` permite interrumpir la reproducción incluso durante una pausa o animación. Para conseguirlo reemplazamos parte de los `delay()` por una función llamada:

```cpp
pausaControlada()
```

Durante la pausa, esta función continúa revisando los controles mediante `leerControles()`.

También modificamos algunas funciones para que devuelvan un valor `bool`. De esta forma pueden indicar si terminaron normalmente o si fueron interrumpidas por `STOP`.

```text
STOP
↓
animación = false
↓
estrofa = false
↓
poema = false
↓
se detiene la reproducción
```

`REPEAT` fue pensado para activar o desactivar la repetición del poema. En el estado actual, el botón presenta un problema: si el poema ya está reproduciéndose y se presiona `REPEAT`, no se activa la repetición. Actualmente funciona cuando se presiona `STOP`, se activa `REPEAT` y luego se vuelve a iniciar el ciclo.

Este problema quedó pendiente de resolver.



### Potenciómetro


El potenciómetro entrega valores entre `0` y `1023`. Estos valores se dividen en tres rangos para obtener los tamaños:

```text
0 – 341     → tamaño 1
342 – 682   → tamaño 2
683 – 1023  → tamaño 3
```

Para leer este valor creamos:

```cpp
leerTamanoLetra()
```

El tamaño se consulta mientras el poema está funcionando, por lo que puede cambiarse durante la reproducción.

Esto también permitió simplificar `escribirLetraPorLetra()`. En vez de entregar el tamaño manualmente cada vez que llamamos a la función, el tamaño se obtiene directamente desde el potenciómetro.



### Diagrama de flujo


El diagrama debe mostrar el recorrido general del programa desde que Arduino comienza hasta que termina o vuelve a iniciar el poema.

```text
INICIO
↓
Configurar OLED
↓
Configurar botones y potenciómetro
↓
Cargar variables y textos del poema
↓
SETUP
↓
LOOP
↓
¿Se presionó PLAY?
├── NO → seguir revisando controles
└── SÍ
     ↓
  comenzar poema
     ↓
  ¿STOP presionado?
  ├── SÍ → detener reproducción
  │        ↓
  │     volver a revisar controles
  │
  └── NO
       ↓
  leer potenciómetro
       ↓
  obtener tamaño de letra
       ↓
  ejecutar primera estrofa
       ↓
  ejecutar segunda estrofa
       ↓
  ejecutar tercera estrofa
       ↓
  ejecutar cuarta estrofa
       ↓
  ejecutar quinta estrofa
       ↓
  ejecutar último verso
       ↓
  ¿REPEAT activado?
  ├── SÍ → volver al inicio del poema
  └── NO → terminar reproducción
              ↓
           volver a LOOP
```

Dentro de cada estrofa, las funciones de animación se ejecutan en el orden definido para cada verso. Mientras existen pausas controladas, el código continúa revisando los botones para permitir que `STOP` interrumpa la reproducción.



### Cosas que funcionan como esperábamos


| Función                       | Estado   | Descripción                                                         |
| ----------------------------- | -------- | ------------------------------------------------------------------- |
| Pantalla OLED                 | Funciona | Muestra la portada y el poema completo.                             |
| Escritura letra por letra     | Funciona | El texto aparece progresivamente carácter por carácter.             |
| Velocidad                     | Funciona | Permite generar diferentes niveles de intensidad.                   |
| Movimiento del molino         | Funciona | El texto se desplaza horizontalmente.                               |
| `mostrarGolpe()`              | Funciona | Permite los cambios visuales de `BURN`, `CUT`, `RAW` y `ACID`.      |
| `mostrarPulso()`              | Funciona | Permite variar el tamaño en `dicing` y `crying`.                    |
| Control de brillo             | Funciona | Permite aumentar y disminuir progresivamente la intensidad.         |
| Movimiento de revolver        | Funciona | Genera pequeños desplazamientos que simulan la acción de revolver.  |
| Cruz en píxeles               | Funciona | `crucifix` incorpora un dibujo realizado con píxeles.               |
| Repetición visual de `I hear` | Funciona | Las apariciones pueden aumentar progresivamente su brillo.          |
| `Miss Lady`                   | Funciona | Aparece sola y en tamaño grande.                                    |
| Trigger warning               | Funciona | Aparece antes de la cuarta estrofa.                                 |
| `SCREAMING`                   | Funciona | Aumenta progresivamente en tamaño y brillo.                         |
| Acumulación de `bawl`         | Funciona | El texto permanece y se acumula durante las repeticiones.           |
| Fade out                      | Funciona | El brillo puede disminuir progresivamente hasta llegar a 0.         |
| PLAY                          | Funciona | Inicia la reproducción del poema.                                   |
| STOP                          | Funciona | Permite detener la reproducción durante el recorrido.               |
| Debounce                      | Funciona | Estabiliza la lectura de los botones.                               |
| Potenciómetro                 | Funciona | Permite modificar el tamaño entre 1, 2 y 3 durante la reproducción. |



### Cosas que no funcionan


| Problema                         | Estado actual                                                                                                                                                       |
| -------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| `REPEAT` durante la reproducción | Si el poema ya está corriendo y se presiona `REPEAT`, no se activa. Actualmente funciona después de presionar `STOP`, activar `REPEAT` y volver a iniciar el ciclo. |
| Corte de palabras                | Todavía existen algunos casos en que una palabra puede quedar dividida entre líneas debido al tamaño de la pantalla y al tamaño de letra.                           |
| Ajuste perfecto de versos largos | La pantalla de `128 × 32 px` limita cuánto texto puede mostrarse simultáneamente, especialmente cuando se utiliza tamaño 3.                                         |



## 5. Evolución del código


### Tabla de versiones


La evolución del código fue principalmente de **probar primero las funciones por separado, completar progresivamente el poema y después corregir problemas específicos de visualización y control**. En el caso de `codigo09-06-error`, el nombre no significa que el código haya dado un error de compilación: el problema apareció al incorporar la separación de palabras, porque la nueva lógica hizo que algunos versos y palabras comenzaran a solaparse en la pantalla.

| Versión               | Qué incorporamos / cambiamos                                                                                                                                                                                                                                                                                                                                                          | Problemas o aprendizajes                                                                                                                                                                                                                                                                                                                                                                                                                                                           |
| --------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **codigo08-28**       | Primera prueba del proyecto. Se configuró la pantalla OLED y se trabajó la **introducción del poema**, mostrando el título y la autora letra por letra. También se creó por primera vez la función `escribirLetraPorLetra()`.                                                                                                                                                         | Fue la base para entender cómo llevar un texto a la pantalla y hacerlo aparecer progresivamente.  [Ver codigo08-28 en GitHub](https://github.com/disenoUDP/dis8645-2026-2-procesos-1/blob/main/00-proyecto-1/grupo-04/codigos/codigo08-28.md?utm_source=chatgpt.com)                                                                                                                                                                                                               |
| **codigo09-01**       | Se pasó de la prueba inicial a trabajar directamente con el poema. Se incorporaron las **cinco estrofas**, el verso final, los botones `PLAY`, `STOP` y `REPEAT`, el potenciómetro y las primeras funciones de animación. También se programó la primera estrofa con diferentes velocidades, el movimiento de `moverMolino()` y los golpes visuales de `BURN`, `CUT`, `RAW` y `ACID`. | El código ya tenía la estructura general del proyecto, pero todavía estaba en una etapa inicial: la reproducción solo estaba desarrollada hasta la segunda estrofa y los controles eran más simples.  [Ver codigo09-01 en GitHub](https://github.com/disenoUDP/dis8645-2026-2-procesos-1/blob/main/00-proyecto-1/grupo-04/codigos/codigo09-01?utm_source=chatgpt.com)                                                                                                              |
| **codigo09-06**       | Se reorganizó el código y se mejoró el funcionamiento de los controles. Se agregó **antirrebote (`DEBOUNCE`)**, lectura del potenciómetro en tres niveles y una `pausaControlada()` que permite seguir leyendo los botones durante las pausas. Se mantuvo el trabajo de la primera y segunda estrofa.                                                                                 | En esta etapa el control del sistema se volvió más estable y se preparó la estructura para poder interrumpir la reproducción con `STOP`.  [Ver codigo09-06 en GitHub](https://github.com/disenoUDP/dis8645-2026-2-procesos-1/blob/main/00-proyecto-1/grupo-04/codigos/codigo09-06?utm_source=chatgpt.com)                                                                                                                                                                          |
| **codigo09-06-error** | Se completó la **interpretación de todo el poema**: tercera, cuarta y quinta estrofa, trigger warning, cambios de brillo, `crucifix`, repetición de `I hear`, `SCREAMING`, acumulación de `bawl` y el resto de las animaciones. En esta versión también se intentó incorporar la lógica para **separar palabras y evitar que se cortaran entre líneas**.                              | El problema no fue un error de compilación. Al agregar la separación de palabras, la lógica de impresión provocó que **versos y palabras se solaparan en la pantalla**. Por eso primero se priorizó terminar el poema con las animaciones funcionando y después solucionar la separación de palabras.  [Ver codigo09-06-error en GitHub](https://github.com/disenoUDP/dis8645-2026-2-procesos-1/blob/main/00-proyecto-1/grupo-04/codigos/codigo09-06-error?utm_source=chatgpt.com) |
| **codigo09-06-final** | Se corrigió la forma en que se procesaba el texto para mantener la escritura **letra por letra**, pero calculando la posición de cada palabra antes de mostrarla. Así se intentó evitar que una palabra quedara partida entre líneas. Además, se incorporó el **último verso como una función independiente** y se mantuvo la interpretación completa del poema.                      | Esta versión corresponde al código final del proceso: se conserva la interpretación completa y se integra la solución para el problema de separación de palabras.  [Ver codigo09-06-final en GitHub](https://github.com/disenoUDP/dis8645-2026-2-procesos-1/blob/main/00-proyecto-1/grupo-04/codigos/codigo09-06-final?utm_source=chatgpt.com)                                                                                                                                     |
La idea fue **primero hacer que la interpretación completa funcionara y después solucionar la distribución del texto**, en vez de detener el desarrollo del poema mientras se intentaba resolver la separación de palabras.




## 6. Problemas y pruebas


Durante el proceso fuimos probando el código directamente en la pantalla OLED y ajustando las funciones según lo que ocurría al ejecutar el poema. Los problemas más importantes aparecieron al intentar controlar la reproducción, adaptar los versos al espacio reducido de la pantalla y evitar que las palabras se cortaran.



### STOP y los `delay()`


Uno de los primeros problemas apareció con el botón `STOP`. En las primeras versiones utilizábamos `delay()` para controlar cuánto tiempo permanecía cada verso en pantalla. Mientras el programa estaba dentro de un `delay()`, no podía volver a revisar los botones.

Por ejemplo, si un verso tenía un `delay(1000)`, durante ese segundo el programa no estaba leyendo `STOP`. Aunque presionáramos el botón, la reproducción continuaba hasta que terminara la pausa.

Para solucionarlo creamos `pausaControlada()`. En vez de esperar todo el tiempo de una sola vez, esta función utiliza `millis()` y durante la espera sigue ejecutando `leerControles()`. De esta manera `STOP` puede interrumpir la reproducción.

También tuvimos que modificar las funciones de las estrofas para que pudieran devolver `false` cuando la reproducción fuera cancelada. Así, la interrupción de `STOP` puede pasar desde las animaciones hasta `reproducirPoema()`.



### Botones y debounce


Al comenzar a trabajar con los botones físicos también tuvimos que considerar que una sola pulsación podía ser detectada varias veces.

Para evitarlo incorporamos un sistema de debounce de `120 ms` y guardamos el estado anterior de cada botón.

```cpp
bool ultimoPlay = HIGH;
bool ultimoStop = HIGH;
bool ultimoRepeat = HIGH;
```

De esta manera podemos comparar el estado anterior con el actual y reconocer una pulsación como una acción individual.



### Tamaño y espacio de la pantalla


La pantalla OLED tiene un espacio muy reducido de `128 × 32` píxeles. Esto se volvió especialmente importante al trabajar con versos largos y con los tres tamaños de letra disponibles mediante el potenciómetro.

Al aumentar el tamaño, disminuye el espacio disponible para mostrar cada verso. Por eso tuvimos que probar distintas combinaciones de tamaño y velocidad y considerar el espacio disponible al escribir cada palabra.

Este problema también fue el que nos llevó a trabajar posteriormente en una solución para evitar que una palabra quedara dividida entre dos líneas.



### Problema con el corte de palabras


Al escribir los versos letra por letra, algunas palabras podían quedar cortadas cuando llegaban al límite de la pantalla.

Por ejemplo, una palabra podía comenzar al final de una línea y continuar en la siguiente. Queríamos mantener el efecto de escritura progresiva, pero hacer que cada palabra comenzara completa en una nueva línea cuando no hubiera espacio suficiente.

Para solucionar esto desarrollamos una función llamada `imprimirTextoSinCortar()` y modificamos la lógica de `escribirLetraPorLetra()` para calcular previamente el espacio necesario para cada palabra.



### Versión `codigo09-06-error`


Esta versión corresponde a una prueba realizada específicamente para solucionar el problema del corte de palabras.

El código no produjo un error de compilación. El problema apareció al ejecutarlo: después de incorporar la nueva lógica, los textos comenzaron a **solaparse** y algunas letras y palabras aparecían repetidas o superpuestas en la pantalla.

Como esta modificación afectaba directamente la reproducción del poema, decidimos eliminarla temporalmente y volver a una versión estable.

Primero terminamos de hacer funcionar el poema completo con sus estrofas y animaciones. Una vez que tuvimos esa versión funcionando, retomamos nuevamente el problema de la separación de palabras.

La solución posterior permitió mejorar la distribución de las palabras, pero el problema no quedó completamente resuelto. Debido al tamaño reducido de la OLED y a que el usuario puede cambiar el tamaño de letra con el potenciómetro, todavía existen algunos casos en que ciertas palabras pueden cortarse.



### Problema con `REPEAT`


Otro problema apareció al probar el botón `REPEAT`.

La intención era que este botón permitiera repetir el poema, pero durante las pruebas comprobamos que **no funciona como esperábamos mientras el poema está reproduciéndose**.

Cuando el poema está corriendo y presionamos `REPEAT`, no comienza una nueva reproducción ni se produce un cambio visible inmediato.

En cambio, comprobamos que `REPEAT` funciona cuando el poema se encuentra detenido mediante `STOP`.

En el código, el botón cambia el estado de la variable:

```cpp
repetir = !repetir;
```

pero la repetición del poema no ocurre inmediatamente al presionar el botón mientras la reproducción está en curso. 

Por ahora decidimos dejar este comportamiento como parte del estado actual del proyecto, ya que el resto de la reproducción y los controles principales quedaron funcionando.




## 7. Desarrollo de la caja



### Primer boceto


![Boceto de la caja](./imagenes/boceto.jpeg)

El primer boceto parte de la idea de construir una caja relacionada directamente con el universo del poema y con la preparación de la salsa.

La propuesta fue que la caja tuviera la forma de una **tabla de picar**, tomando como referencia uno de los elementos presentes en el poema.



### Relación entre la caja y el poema


La forma de tabla de picar busca que el objeto físico no sea solamente un soporte para la pantalla OLED y los componentes electrónicos, sino que también tenga relación con las acciones que aparecen en *Pepper Sauce*.

El poema habla de preparar la salsa, cortar ingredientes y utilizar distintos elementos de cocina. Por eso decidimos llevar esa idea al objeto que contiene el proyecto.

De esta manera, la pantalla, los controles y la forma de la caja pertenecen al mismo universo del poema.



### Control con cuchillo


A partir de la idea de la tabla de picar pensamos en incorporar un control que estuviera integrado al objeto: **un contacto que se active cuando el cuchillo toque una zona determinada de la tabla**.

La intención era que este contacto pudiera funcionar como una forma de pausar el poema.

Así, el control tendría una relación directa con la acción de cortar que aparece en el poema, en vez de ser simplemente un botón externo.

Esta idea quedó solamente en la etapa conceptual. **No llegamos a probar físicamente el contacto con el cuchillo**, por lo que no forma parte de los controles que actualmente funcionan en el proyecto.


## 10. Bill of Materials

| Cantidad | Componente                          | Descripción / uso                                                                      |
| -------: | ----------------------------------- | -------------------------------------------------------------------------------------- |
|        1 | Arduino UNO R4 WiFi                 | Microcontrolador utilizado para ejecutar el código y controlar la instalación.         |
|        1 | Pantalla OLED SSD1306 128 × 32 px   | Pantalla donde se muestra e interpreta visualmente el poema. Utiliza comunicación I2C. |
|        3 | Botones                             | Controles físicos para **PLAY**, **STOP** y **REPEAT**.                                |
|        1 | Potenciómetro                       | Permite controlar el tamaño de letra en tiempo real entre los tamaños 1, 2 y 3.        |
|        1 | Protoboard                          | Utilizada para realizar las conexiones y pruebas del circuito.                         |
|        — | Cables jumper                       | Utilizados para conectar el Arduino, la pantalla OLED, los botones y el potenciómetro. |
|        1 | Caja / estructura de la instalación | Soporte físico del proyecto, planteado a partir de la idea de una tabla de picar.      |



## 11. Referencias

### Código

Los códigos fueron desarrollados y modificados progresivamente durante el proceso del proyecto. Cada versión corresponde a una etapa distinta de prueba y desarrollo.

* [`codigo08-28.md`](./codigo08-28.md) — primera etapa de desarrollo del código.
* [`codigo09-01.txt`](./codigo09-01.txt) — incorporación y organización de nuevas funciones.
* [`codigo09-06.txt`](./codigo09-06.txt) — desarrollo avanzado de las animaciones y controles.
* [`codigo09-06-error.txt`](./codigo09-06-error.txt) — prueba de separación de palabras que produjo el solapamiento de textos.
* [`codigo09-06-final.txt`](./codigo09-06-final.txt) — versión posterior a la prueba anterior, con el poema completo funcionando.

Repositorio del proceso:

[Repositorio del proyecto en GitHub](https://github.com/blosssom-n/dis8645-2026-2-procesos-1?utm_source=chatgpt.com)



### Poema y autora


**Booker, Malika.** *Pepper Sauce*. En *Pepper Seed*, 2013.

Copyright © 2013 Malika Booker. All rights reserved.

El poema fue utilizado dentro del proyecto con fines académicos y no comerciales, como parte de una reinterpretación visual mediante código y una pantalla OLED.



### Otras referencias


* [Arduino — String Object](https://docs.arduino.cc/language-reference/en/variables/data-types/stringObject/?utm_source=chatgpt.com) — referencia utilizada para comprender el uso de `String` en Arduino.

* [Arduino — String Characters](https://docs.arduino.cc/built-in-examples/strings/StringCharacters/?utm_source=chatgpt.com) — referencia utilizada durante las primeras pruebas con caracteres y arreglos.



* **Registro visual del proceso:** las fotografías utilizadas en la bitácora se encuentran en la carpeta `./imagenes/`.


# Conclusión


El desarrollo de *Pepper Sauce* nos permitió entender que programar una interpretación no consiste solamente en conseguir que el texto aparezca en una pantalla, sino en tomar decisiones sobre **cómo el código puede transmitir lo que ocurre en el poema**.

Durante el proceso pasamos de trabajar con el texto de manera bastante directa a construir un sistema de variables, funciones y estrofas que nos permitió reutilizar comportamientos y relacionarlos con distintos momentos del poema. Las variaciones de velocidad, tamaño, movimiento, brillo, pausas y acumulación fueron convirtiéndose en herramientas para representar los cambios de intensidad de la obra.

También fue importante trabajar a partir de pruebas reales. La pantalla de 128 × 32 px, los botones, el potenciómetro y los `delay()` nos obligaron a adaptar constantemente nuestras ideas a las posibilidades y limitaciones del dispositivo. Algunos problemas, como el comportamiento de `REPEAT`, el corte de palabras y el solapamiento de textos, todavía no están completamente resueltos, pero también fueron parte importante del proceso porque nos permitieron entender mejor cómo estaba funcionando nuestro código.

Al terminar esta etapa conseguimos que **el poema completo pudiera reproducirse en la OLED**, incorporando las principales animaciones y controles que habíamos planteado. Al mismo tiempo, dejamos identificados los aspectos que todavía podemos seguir mejorando, tanto en el código como en la construcción física de la caja.

Más que buscar una reproducción literal del poema, nuestro objetivo fue construir una **interpretación visual y programada de su intensidad**, haciendo que el comportamiento del texto acompañara su recorrido desde el inicio hasta el final.

