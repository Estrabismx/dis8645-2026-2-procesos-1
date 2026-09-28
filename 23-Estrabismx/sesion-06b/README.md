# sesion-06b

## apuntes sesión

### 10 Categorias de Aristoteles

1. sustancia: mi encendedor
2. cantidad: 1
3. cualidad: posee una dimensiones aproximadas de 8cm x 3cm x 1.5 cm. Sus colores son negro y rojo, posee gas butano y un regulador
4. relación: comparado con otros, este posee una llama más contenida
5. lugar: actualmente se encuentra a unos centimetros de mi pc
6. tiempo: ahora y durante un lapso de tiempo 
7. posición: acostado de forma horizontal
8. posesión: porta gas butano
9. acción: encender una llama
10. pasión: quemar o iniciar combustión

### charla ---

[]

### [Wokwi](https://wokwi.com/)

En esta clase trabajamos con Wokwi, un simulador con mucho parecido a Tinkercad. En este podemos escribir código y hacer pruebas para ejecutarlo de manera On-Line, evitando así causar daños a nuestras placas (además de realizar pruebas en caso de no poseer un microcontrolador)

![wokwi](./imagenes/sc-13.png)

Existe diversidad de microcontroladores para hacer pruebas, solo que nos enfocaremos en Raspberry Pi Pico

<br>

![Wokwi](./imagenes/sc-14.png)

Además podremos elegir múltiples ejemplos de proyectos y plantillas para desarrollar ideas. Nosotros utilizaremos "_Pi Pico SDK (Adanced)_"

<br>

![Wokwi](./imagenes/sc-15.png)

Ya tenemos una plantilla con la que iniciar nuestros proyectos.

Vamos a desglosar el código que vemos:

```cpp

#include <stdio.h>
#include "pico/stdlib.h"

int main() {
  stdio_init_all();
  while (true) {
    printf("Hello, Wokwi!\n");
    sleep_ms(250);
  }
}

```

Iniciando observamos dos `#include`, el que utiliza `<stdio.h>` corresponde aun llamado directo a la biblioteca estandar del sistema. Y en cambio, `"pico/stdlib.h"` primero busca el archivo en la ruta del proyecto 

Luego podemos ver la función:

```cpp

int main() {

}

```

Esta función nos retorna un número entero, además de ser la principal, todo debe ocurrir dentro de ella 

Continuamos tenemos `stdio_init_all();` que inicializa el Raspberry Pi Pico

<br>

```cpp
// copia y pega ese archivo
// ojo que esta entre <>
// este archivo esta en un lugar lejano
// que tiene que ver con C
#include <stdio.h>
// este otro esta entre ""
// entre "" es literalmente
// en ese lugar
// en este caso
// al lado de este archivo
// hay una carpeta pico/
// y adentro esta stdlib.h
#include "pico/stdlib.h"


// mi propia funcion
// tipo nombre
// parentesis murcielagos
// diseno top-down
int prueba() {
  int x = 3;
  int y = 6;
  int resultado = x * y;
  return resultado;
}


// funcion main()
// es de tipo int
// las int cuando corren
// retornan un entero
int main() {
  // esta funcion
  // inicializa raspico
  stdio_init_all();
  while (true) {
    // printf("Hello, Wokwi!\n");
    // convertir de int a chars
    printf("%d\n", prueba());
    sleep_ms(250);
  }
}
```

## encargos

RRSS

## lectura
