# sesion-04b

## apuntes sesión

# Sesión 04b

## Avance general

En esta sesión nos dividimos para avanzar varias partes del proyecto al mismo tiempo. Mientras una parte del grupo seguía trabajando en los componentes y la carcasa, yo me enfoqué más en terminar y ordenar el código. Igual íbamos probando todo en conjunto, porque cualquier cambio en el código tenía que funcionar después con las conexiones y la forma final del proyecto.

## Separar la animación del código principal

Uno de los cambios que dejamos listo fue separar los cuadros de la animación del código principal. Como cada frame convertido a hexadecimal ocupaba demasiadas líneas, dejamos toda esa información en una pestaña aparte llamada `cuadros.h`.

En el código principal solamente hacemos el llamado:

```cpp
// DATOS VISUALES
// Aquí estamos llamando al código donde tenemos los cuadros de la animación
#include "cuadros.h"
```

Así el código principal queda mucho más fácil de leer y la animación sigue funcionando igual, porque ambos archivos son parte del mismo proyecto.

## Alargar la animación desde el código

También queríamos que la animación durara un poco más, pero sin tener que volver a editar el video ni crear nuevos cuadros. Para eso hicimos que el código recorriera varias veces los mismos frames.

```cpp
void mostrarAnimacion() {

  for (int repeticion = 0; repeticion < 3; repeticion++) {

    for (int i = 0; i < epd_bitmap_allArray_LEN; i++) {

      display.clearDisplay();

      display.drawBitmap(
        0,
        0,
        epd_bitmap_allArray[i],
        SCREEN_WIDTH,
        SCREEN_HEIGHT,
        SSD1306_WHITE
      );

      display.display();

      delay(150);
    }
  }
}
```

El primer `for` hace que la animación completa se repita **3 veces**, mientras que el segundo recorre todos los cuadros. De esta forma pudimos alargarla directamente desde el código, sin modificar los frames.

> **Ojo:** en el comentario del código dice “repetir la animación 2 veces”, pero `repeticion < 3` hace que realmente se repita **3 veces**.

## Agregar una presión para comenzar

Otro cambio fue que la animación ya no empezara automáticamente al prender Arduino.

Ahora, cuando el programa inicia, el `setup()` muestra primero:

```text
Presiona boton
para leer
```

y queda esperando.

```cpp
mostrarMensajeBoton();
```

En el `loop()`, mientras `etapa == 0`, el programa revisa el botón:

```cpp
if (etapa == 0 || etapa == 2 || etapa == 3) {
  revisarBoton();
}
```

Cuando detecta la primera presión recién ocurre:

```cpp
mostrarAnimacion();
mostrarTitulo();
etapa = 2;
```

Esto nos gustó más para la experiencia porque la persona puede decidir cuándo comenzar, en vez de que todo parta automáticamente apenas se conecta Arduino.

## Arreglo del rebote del botón

También seguimos arreglando el problema del botón, porque anteriormente una sola presión podía hacer que avanzara más de una pantalla.

En esta versión usamos un **intervalo de antirrebote de 180 milisegundos**:

```cpp
unsigned long tiempoUltimaPresion = 0;
const unsigned long intervaloBoton = 180;
```

Después, en `revisarBoton()`, no basta con detectar que el botón cambió de `LOW` a `HIGH`, sino que también se revisa cuánto tiempo pasó desde la última presión válida:

```cpp
if (
  buttonState == HIGH &&
  lastButtonState == LOW &&
  millis() - tiempoUltimaPresion > intervaloBoton
) {

  tiempoUltimaPresion = millis();
```

Así, aunque el botón haga pequeños cambios muy rápidos al presionarlo, Arduino ignora los que ocurren dentro de esos `180 ms`. Esto hizo mucho más estable la lógica de **1 presión = 1 pantalla**.

## Cambio del pin del LED

También corregimos el pin del LED externo. Al principio lo teníamos declarado en el pin `13`, pero después averiguamos que ese pin está relacionado con el LED integrado de la placa Arduino, cosa que no sabíamos al principio.

Por eso finalmente quedó:

```cpp
const int ledPin = 9;
```

Además de cambiarlo en el código, también tuvimos que cambiar físicamente la conexión del LED para que coincidiera con el pin `9`.

## LED según los versos

En esta versión también quedó funcionando el LED según la parte del poema que se estuviera mostrando.

Por ejemplo:

```cpp
// Verso 1
if (parteActual == 0) {
  digitalWrite(ledPin, HIGH);
}

// Verso 2
else if (parteActual == 1 || parteActual == 2) {
  digitalWrite(ledPin, LOW);
}

// Verso 3
else if (parteActual == 3 || parteActual == 4) {
  digitalWrite(ledPin, HIGH);
}
```

Como algunos versos están divididos en dos pantallas, usamos `parteActual` para saber qué parte se está mostrando y mantener el LED encendido o apagado según el verso real.

## Ajuste del potenciómetro y nombre de la autora

La parte del potenciómetro también quedó más cerrada. Su valor se lee con:

```cpp
valorPot = analogRead(potenciometro);
```

y después se transforma en la cantidad de letras que deberían aparecer:

```cpp
letrasMostrar = map(
  valorPot,
  0,
  1023,
  0,
  strlen(autora)
);
```

También agregamos una condición para asegurarnos de que nunca intente mostrar más letras de las que realmente tiene `"Mary Oliver"`:

```cpp
if (letrasMostrar > strlen(autora)) {
  letrasMostrar = strlen(autora);
}
```

Después un `for` recorre solamente las letras correspondientes:

```cpp
for (int i = 0; i < letrasMostrar; i++) {
  display.print(autora[i]);
}
```

## Doble clic para reiniciar

Al llegar al final del poema, el programa pasa a la `etapa = 4`, donde funcionan el potenciómetro y el doble clic.

```cpp
else if (etapa == 4) {
  mostrarAutora();
  revisarDobleClick();
}
```

Para detectar el doble clic se guarda el tiempo de la primera presión y se compara con la siguiente. Dejamos un intervalo de `400 ms`:

```cpp
unsigned long tiempoUltimoClick = 0;
const unsigned long intervaloDobleClick = 400;
```

Si las dos presiones ocurren dentro de ese tiempo, se llama a:

```cpp
reiniciarProyecto();
```

Esta función vuelve las variables a sus valores iniciales, apaga el LED y muestra nuevamente el mensaje:

```text
Presiona boton
para leer
```

Así el proyecto queda listo para comenzar todo el recorrido otra vez.

## Recorrido final del código

Con estos últimos cambios, el recorrido quedó más o menos así:

```text
Arduino se enciende
        ↓
"Presiona botón para leer"
        ↓
Primera presión
        ↓
Animación x3
        ↓
Título
        ↓
Presión
        ↓
Verso 1
        ↓
Presiones sucesivas
        ↓
Resto del poema
        ↓
Termina poema
        ↓
Potenciómetro
        ↓
Mary Oliver aparece letra por letra
        ↓
Doble clic
        ↓
Reinicio
        ↓
"Presiona botón para leer"
```

A esta altura el código ya estaba prácticamente terminado. Esta sesión fue más de ir corrigiendo estas cosas que nos habían quedado de las pruebas anteriores y dejar el recorrido más estable, mientras en paralelo seguíamos juntando todo con los componentes y la carcasa.


## encargos

## lectura
