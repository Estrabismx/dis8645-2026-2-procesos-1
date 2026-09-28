# sesion-06b

## apuntes sesión
- el día de hoy no fui a clases, pero mi amiga Vanessa me compartió de sus apuntes y me explicó lo pasado en clases, de esta forma pude realizar mis apuntes
---
- \n - significa enter
- int no es lo mismo que chars 

**código realizado para Raspberry PI**
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
### Wokwi
<https://wokwi.com/>
- haremos uso de esta plataforma para escribir códigos y ejecutarlos tipo simulador
- utilizar Pi Pico -- Starter Templates -- Pi Pico SDK (Advanced)
- <https://wokwi.com/projects/476140065507309569>

### c++ classes/objects
- c++ es un lenguaje de programación orientado a objetos
- en c++, todo está asociado a clases y objetos, junto con sus atributos y métodos.
```
coche = objeto

atributos -- peso y color

métodos -- conducir y frenar
```
- los atributos y métodos son básicamente variables y funciones que pertenecen a la clase -- denomina "miembros de la clase"
- clase -- tipo de dato definido por el usuario
- podemos utilizar en nuestro programa
- constructor de objetos/"plan maestro" para crear objetos
- los espacios no son obligatorios, pero son buenos modales
- este semestre todo público
- público -- modificable / privado -- no modificable 

### c++ constructors
- método más importante dentro de una función
- método especial -- se llama automáticamente cuando se crea un objeto de una clase
- utilizar mismo nombre que la clase -- seguido ():
- público
  
### Charla Rodrigo Toro
- mano con movimiento y grabadora de discos
- probar las cosas con más personas, que las rompan si es que es necesario, tomara nota de los errores
- pilló una impresora en la basura, vio las polaridades, le puso interruptores y se podía ir haciendo rayas con un lápiz

### links importantes clase

<https://www.w3schools.com/cpp/cpp_constructors.asp>

<https://www.w3schools.com/cpp/cpp_classes.asp>

