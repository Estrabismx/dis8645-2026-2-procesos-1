# sesion-06b

En esta clase conversamos sobre los ejemplos del encargo 

Ejemplo de encargo cata:

1. Sustancia: termo
2. cantidad: 800ml
3. cualidad: blanco, metálico, térmico, acero inoxidable
4. relación: contenedor de té
5. Lugar: siempre a la izquierda de mi manito izquierda
6. Tiempo: aqui, ahora, siempre
7. posicion: Vertical
8. Posesión: Es mío, pero también puede ser lo que posee, por ende, puede ser "liquido"
9. Acción: Mantener el calor
10. Pasión: Ser llenado para transportar líquido

## Recomendaciones y/o consejos de la charla de Rodrigo Torres

+ pensar los proyectos de forma que sean fáciles de usar para cualquier persona
+ aprender de los errores y usar lo que salió mal para mejorar
+ registrar el proceso con muchas fotos, no solo el resultado final
+ recomendó leer La invención de Morel
+ dibujar mucho antes y durante el proceso, para ir probando y desarrollando las ideas

## CLASES EN C++

Una clase es como un molde para crear objetos.

     class Termo {
       public:
         bool existencia;
         int posicion;
         int cantidadML;
         float temperature;

         void abrir();
         void cerrar();
     };
     
En este ejemplo:

+ Termo es la clase
+ Los datos son los atributos: existencia, posición, cantidadML, temperatura
  
Y las acciones son los métodos: abrir(), cerrar()

+ La clase sirve para que después podamos crear objetos que tengan esas características y acciones

 Ejemplo: 

 ```c
 // tenemos que copiar y pegar este archivo
 // ojo que está entre "<>"
 // esto significa que este archivo está en un lugar lejano
 // y tiene que ver con C

#include <stdio.h>

 // 

#include "pico/stdlib.h"

 // podemos escribir nuestra propia funcion
 // tipo "void"
 // nombre
 // murcielagos
 // top-down
 // de lo macro a lo micro

 int prueba() {

  int x = 3;
  int y = 6;
  int resultado = x * y;
  return resultado;

 }
 

 // la funcion es main()
 // se identifica por los parentesis ()
 // es de tipo int
 // y cuando corren
 // retornan a un entero

int main() {

 // esta funcion inicializa la raspi
 // si no esta llamado en esta funcion
 // no va a ocurrir

  stdio_init_all();
  while (true) {

    // printf("Hello, Wokwi!\n");
    // convertir de int a chars

    // printf("resultado: %d\n, prueba()");

    printf("%d\n", prueba());
    prueba();
    sleep_ms(250);
  }
}


## apuntes sesión

## encargos

## lectura
