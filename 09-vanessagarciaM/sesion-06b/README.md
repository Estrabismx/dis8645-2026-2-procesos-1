# sesion-06b

## apuntes sesión

Comenzamos revisando el encargo

### ejemplo en la clase

sustancia: mi termo 

cantidad: 800 ml 

cualidad: blanco, metálico, térmico 

relación: contenedor de té ceylan

lugar: favorito conmigo. a la izquierda de mi mano izquierda 

tiempo: ahora siempre pronto 

posición:

posesión: líquido,

acción: mantener el líquido caliente

pasión: ser llenado y transportado (no tiene, es inerte) 


**primero lidiamos con él qué es, después en el cómo se hace**

___

\n - significa enter 
int no es lo mismo que chars 

oye pero pucha que costó 

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
___

nos visita 

Rodrigo Toro 

oh waoh la mano con movimiento y su grabadora de discos

> 💡 **dato** modulor: librería de arquitectura como del porte de la u 

probar las cosas con más personas, que las rompan si es que es necesario, tomar nota de los errores

aprovechar el pañol, no siempre hay pañoles 🙁

encontró una impresora en la basura, vio las polaridades, le puso interruptores y se podía ir haciendo rayas con un lápiz. está increíble. 

___ 

## mini clase 

### c++ classes/objects 
c++ es un lenguaje de programación orientado a objetos.

en C++, todo está asociado a clases y objetos, junto con sus atributos y métodos. por ejemplo: en la vida real, un coche es un objeto. el coche tiene atributos , como peso y color, y métodos , como conducir y frenar.

los atributos y métodos son básicamente variables y funciones que pertenecen a la clase. a menudo se les denomina "miembros de la clase".

una clase es un tipo de dato definido por el usuario que podemos utilizar en nuestro programa, y ​​funciona como un constructor de objetos o como un "plan maestro" para crear objetos.
los espacios no son obligatorios, pero son buenos modales 

este semestre vamos hacer todo public, pero en la vida real no todo es así

si es público lo puedo modificar, si es privado no, ejemplo del rut, lo puedo ver, pero no modificarlo.

en classes después del murciélago de cierre hay punto y coma

con el punto, como en el ejemplo elDeMatias.cantidadML = 800;

se pueden poblar los valor por 0, como por defecto 


### c++ constructors

bob el constructor 

es el método más importante dentro de una función 

un constructor es un método especial que se llama automáticamente cuando se crea un objeto de una clase.

para crear un constructor, utilice el mismo nombre que la clase, seguido de paréntesis ():

con agregar una línea en classes, puede propagar todo a los otros ¨termos¨, ej: rodamientos

