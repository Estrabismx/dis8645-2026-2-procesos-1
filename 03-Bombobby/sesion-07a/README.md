# sesion-07a

## apuntes sesión

placeholder %d (número "int") es un espacio reservado que se usa dentro de un string para indicar que aquí se inserta el valor de una variable que es un número entero.

\n (salto de línea) un carácter de escape, significa "enter" obligando a que lo que siga se escriba en la línea de abajo.

orden estándar (ordenao):
```
class Nombre {
public:
variables  | int
           | bool
atributos  | char

//constructor
Nombre(...){
}

//método
abrir(...);
cerrar(...);
```
En la misma clase puede haber más de un constructor con los mismos parámetros

el rut es una variable interna
para el registro civil, ser chileno es una clase
```
//mientras esto sea verdad
//hazlo
//practicamente lo mismo que el void(loop) de arduino
while (true)
```
para acceder a las funciones y estados de una clase ocupamos un punto .
ej: elDeCata.cantidadML, esto nos dice cuantos ml tiene el termo de Cata

%.1f | f es float y se agrega si el número tiene parte decimal
el .1 dice: solo dame 1 decimal
```
//hace que el programa pause o detenga su ejecución durante 1 segundo
sleep_ms(1000)
```
Una clase implica 2 archivos
.cpp
.h tendrá un resumen de todo
```
class Boton{
public:
//u es porque el número nunca será negativo
bool presionado = 0;
bool normalAbierto = true
uint duracionPresionado = 0;
int patita;
uint vecesPresionado = 0;
char[] nombre;

//constructor
//para evitar confusiones
// ojalá cambiar el nombre del parámetro en el constructor
//constructor le da el valor a la patita
Boton (int nuevaPatita) {
patita = nuevaPatita;
}

//metodos
//declaración, va en h.
void leer();
void actualizar();
};
```
Plantilla Boton.h
```
#ifndef BOTON_H
#define BOTON_H

// Boton.h
// declaraciones de la clase Boton

//definir clase boton
class Boton {
  //todo publico
  public:

  //atributos
  bool presionado = false

  //constructor
  Boton();

  //metodos
  void presionar();
  void soltar();


};

#endif
```
Plantilla Boton.cpp
```
// Boton.cpp
// implementaciones de la clase

// importar archivo header
#include "Boton.h"

// constructor
Boton::Boton() {

}

// metodos
void Boton::presionar() {
  Boton::presionado = true;
}

void Boton::soltar() {
  Boton::presionado = false;
  Boton::duracionPresionado = 0;
}
```
main.cpp
```
#include <stdio.h>
#include "pico/stdlib.h"
// incluir mis archivos
#include "Boton.h"

int main() {

  stdio_init_all();
  
  // crear Boton
  // llamado miPrimerBoton
  // con el constructor
  // los parentesis no son necesarios cuando
  // el constructor no tiene parametros
  // Boton miPrimerBoton();
  Boton miPrimerBoton;
  
  while (true) {

    if (miPrimerBoton.presionado) {
      printf("bacan estoy presionado, pero igual me presiona\n");
      printf("o como dice matias, estoy impresionado jaja\n");
      miPrimerBoton.soltar();
    }
    else {
      // cuando no este presionado
      printf("no hay nadie presionandome\n");
      miPrimerBoton.presionar();
    }





    // printf("Hello, Wokwi!\n");
    sleep_ms(1000);
  }
}
```
## encargos

## lectura
