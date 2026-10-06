# sesion-07b

29-09-2026

## apuntes sesión

%d: Es un placeholder (marcador de posición) para el número "int".

\n: Salto de línea, o si no, se imprime todo de corrido a la derecha.

Vamos a programar botones y ver los estados en los que pasan de cero a uno por unos instantes; y esa vez que pasan de cero a uno, se puede grabar.

Tendremos una clase que será:

C++
class Nombre {
public:
    // Variables internas (atributos) { int, bool, char }

    // Método constructor
    Nombre(...) {
    }

    abrir(...);
    cerrar(...);
};
O SEA:

ATRIBUTOS

MÉTODO CONSTRUCTOR

MÉTODOS (abrir, cerrar)

![tranquilo se la navega](./imagenes/tranquiloselanavega.jpg)

Class Btotn {

atributos

bool presionado=0;

bool normalAbierto=true;

Uint duracionPresionado=0; (U int permite que este valor sea siempre cero)

int patita;

Uint vecesPresionado=0;

CONSTRUCTOR: BOTON () {} 

Boton (int nuevaPatita){

 patita=nuevaPatita;

METODOS

Boton para (GP1);

Boton reproDICIR (GP3);

bOTON apagar (GP30)

}
👀 🐱

Metodos

void leer()

voidactualizar(); esto es una declaración y va en los archivos .h

vamos a ver una clase Boton.h

Boton.cpp

header

Nuestro MAin va a ser cpp

A todos los archivos.h le vamos a poner el #ifndef, #define, #endif

while true es una manera de pedirle a main que se repita para siempre
y como trata de decir siempre la verdad lo importante es poner algo que siempre sea la verdad osea (true)

¿Como comenta "//" todo con la selección?

y ¿como borra hacia adelante?

finalmente este fue el código:
// esto venia en wokwi
#include <stdio.h>
#include "pico/stdlib.h"


// esto lo agregamos para GPIO
// general purpose input output
#include "hardware/gpio.h"

// incluir mis archivos
#include "Boton.h"

int main() {

  stdio_init_all();

  // inicializar patita 7
  gpio_init(7);
  // la patita 7 es entrada
  gpio_set_dir(7, GPIO_IN);
  
  // crear Boton
  // que se llama miPrimerBoton
  // con el constructor
  // habia hecho un error
  // que era usar parentesis sin nada
  // que no son necesarios cuando
  // el constructor no tiene parametros
  // Boton miPrimerBoton();
  Boton miPrimerBoton;
  
  while (true) {


    // leer boton
    bool lectura = gpio_get(7);


    if (lectura) {
     printf("caramba estoy presionado\n"); 
    } else {
      printf("pucha no hay nadie\n"); 
    }

    // digitalRead();

    // if (miPrimerBoton.presionado) {
    //   printf("bacan estoy presionado, pero igual me presiona\n");
    //   printf("o como dice matias, estoy impresionado jaja\n");
    //   miPrimerBoton.soltar();
    // }
    // else {
    //   // cuando no este presionado
    //   printf("no hay nadie presionandome\n");
    //   miPrimerBoton.presionar();
    // }





    // printf("Hello, Wokwi!\n");
    sleep_ms(1000);
  }
}


## encargos

1. usar el ejemplo base visto en clases <https://wokwi.com/projects/476507507193136129>, agregar un segundo botón en la simulación de hardware, agregar una segunda instancia de la clase Boton, agregarle un atributo y un método a la clase Boton, y hacer que el segundo botón haga algo diferente al primero.
2. descargar todos los archivos de wokwi, descomprimir el archivo.zip y subir esa carpeta a tu repositorio en esta sesión.

**SOLUCIÓN ENCARGO**

En general quedaron así los ajustes:

**Boton.h**

```cpp
#ifndef BOTON_H
#define BOTON_H

// esto lo agregamos para GPIO
// general purpose input output
#include "hardware/gpio.h"


// Boton.h
// declaraciones de la clase Boton


// definir clase Boton
class Boton {

  // todo publico
  // nada de andar privatizando
  public:

  // Atributos
  bool presionado = false;
  int duracionPresionado = 0;
  int patita;

  // atributo nuevo
  int vecesPresionado = 0;

  // constructor
  Boton(int nuevaPatita);

  // metodos
  void leer();
  void presionar();
  void soltar();

  // metodo nuevo
  void contarPresion();
};

#endif
```
**Boton.cpp**

```cpp
// Boton.cpp
// implementaciones de la clase

// importar el archivo header
#include "Boton.h"

// constructor
Boton::Boton(int nuevaPatita) {

  // guardar el valor
  Boton::patita = nuevaPatita;

   // inicializar patita
  gpio_init(Boton::patita);
  // la patita es entrada
  gpio_set_dir(Boton::patita, GPIO_IN);
}

void Boton::leer() {
    // leer boton
    Boton::presionado = gpio_get(Boton::patita);
}

// metodos
void Boton::presionar() {
  Boton::presionado = true;
  // queda pendiente calcular
  // cuanto rato lleva presionado
}
  
void Boton::soltar() {
   Boton::presionado = false;
   Boton::duracionPresionado = 0;
}

// metodo nuevo
void Boton::contarPresion() {
  Boton::vecesPresionado++;
}
```
**main.cpp**

```cpp
// esto venia en wokwi
#include <stdio.h>
#include "pico/stdlib.h"

// incluir mis archivos
#include "Boton.h"

int main() {

  stdio_init_all();

  // crear Boton que se llama miPrimerBoton
  // con el constructor
  Boton miPrimerBoton(7);
  Boton segundoBoton(8);
  while (true) {

    miPrimerBoton.leer();
    segundoBoton.leer();

    if (miPrimerBoton.presionado) {
      printf("bacan estoy presionado, pero igual me presiona\n");
    }
    else {
      // cuando no este presionado
      printf("no hay nadie presionandome\n");
    }

    if (segundoBoton.presionado) {
      // cuenta la cantidad de presiones al oprimir el "segundoBoton"
      segundoBoton.contarPresion();
      // imprime el texto con la cantidad de veces presionando el "segundoBoton"
      printf(
        "estilo porta en la suela, llevo %d presiones\n",
        segundoBoton.vecesPresionado
      );
    }
    // es lo que se ve si no se presiona nada
    else {
      printf("tranquilo se la navega\n");
    }

    sleep_ms(100);
  }
}
```

Y acá está el link al wokwi directamente: https://wokwi.com/projects/477107804422557697

## lectura
