# sesion-06b

2026.09.25

## apuntes sesión

No asistí a esta clase, así que todo lo siguiente es basado en los apuntes de mis compañeros

---

Usando wokwi, se simuló el micro controlador Pi Pico W

```cpp
include <stdio.h>
```

std es por **standard** and io is for **input output**

```cpp
include "pico/stdlib.h"
```

```cpp
int main()
```

`main()` es de tipo `int`, meaning que devuelve enteros

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

Aparentemente este código específico no funcionó. Primero Aarón pensó que era porque `print`es para `char`, mientras que `int` es para números enteros, pero seguía sin funcionar luego de cambiar esto. Se realizaron varios cambios al código y aún así no funcionaba lol

Resultó ser que en la línea `printf(prueba();)`, había que añadir `%d/n` antes de `prueba()`, i.e. había que escrbir `printf(%d/n, prueba());`
