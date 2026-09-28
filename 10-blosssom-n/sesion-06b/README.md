# sesion-06b

## apuntes sesión


Llegué tarde a la clase oops pero cuando llegué estaban hablando de metros cúbicos y volumen (en L mayúscula)


Include `<stdio.h>`  
std = standard, io = input output

Include `"pico/stdlib.h"` literalmente está en ese lugar, hay una carpeta al lado de este archivo `pico/` y adentro esta `stdlib.h`


La función `main()` es de tipo `int` (devuelve enteros)

```cpp
int main()
```

Esta función dice raspberry por fa inicia todo lo que tiene input y output

```cpp
//Mi propia función

Tipo nombre paréntesis murciélagos

int prueba() {
  int x = 3;
  int y = 6;
  int resultado = x * y;
```

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

    printf(prueba());

    sleep_ms(250);
  }
}
```

No funcionó pk el print es para char, y el int es respecto a numeros enteros, no es compatible

Probó con varias formas pero seguía sin funcionar

Resulta que había que mostrar primero la función y dsp el main porque si no no sabe cuál es la función

Tampoco funcionó lol

Había que agregar `"%d\n"` antes de la prueba wuajaja funcionó!!

```cpp
printf("%d\n", prueba());
```


## encargos



## lectura
