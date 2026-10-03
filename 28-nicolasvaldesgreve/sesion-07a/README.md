# sesion-07a

## apuntes sesión
una función tiene un int main, dentro de eso está todo lo que ocurre. todo lo que est´fuera, es infraestructura que nos ayuda a que cuando pase int main todo funcione

el if es una pregunta

printf("..")

%d = placeholder (jefe lo hago al tiro), número entero
\n = enter, salto de línea 

```cpp
// estructura típica:
class Nombre {
public:
// int     // variables, atributos
// bools
// char

Nombre (...) { // método constructor 
}
	abrir(...); // métodos en general (funciones en una clase)
	cerrar(...);
};
```

en la misma clase puede haber más de un constructor

while (true) -> mientras es verdad, hazlo. cuando sea falso, para. es como un void loop de arduino pero más crudo.
el main sucede una vez pero nunca va a parar ya que se queda atrapado en un while true.

e.o.c -> en otro caso

_%.1f_

%. -> place holder, aquí va un valor que voy a cambiar

f -> float, para mostrar decimales 
  
.1 -> dame solo un decimal

---

## botones

atributos:

+ bool presionado = 0;
+ bool normallyOpen = true;
+ int patita; // este es buen candidato para constructor
+ Uint vecesPresionado = 0;
+ char [] nombre;

constructor:

```cpp
Boton (~int patita~ nuevaPatita) {
	 patita = ~int patita~ nuevaPatita;
}
```

métodos:

```cpp
void leer();
```

al hacer archivos tendremos:

+ main.cpp
+ Boton.cpp // estos son en el caso del ejemplo
+ Boton.h // ya que tenemos la clase Boton, por eso se llaman así
	// h es de header kkkkkkkk

---

## encargos

1. usar el ejemplo base visto en clases <https://wokwi.com/projects/476507507193136129>, agregar un segundo botón en la simulación de hardware, agregar una segunda instancia de la clase Boton, agregarle un atributo y un método a la clase Boton, y hacer que el segundo botón haga algo diferente al primero.
2. descargar todos los archivos de wokwi, descomprimir el archivo.zip y subir esa carpeta a tu repositorio en esta sesión.

#### avance en clases

main:

```cpp
// este es main.cpp

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
  Boton miSegundoBoton(22);
  
  while (true) {

    miPrimerBoton.leer();

    if (miPrimerBoton.presionado) {
      printf("bacan estoy presionado, pero igual me presiona\n");
    }
    else {
      // cuando no este presionado
      printf("\n no hay nadie presionandome\n");
    }

// agrego otro boton kkkkkk hola

    miSegundoBoton.leer();

    if (miSegundoBoton.presionado) {
        printf("hola soy el otro y estoy presionado\n");
    }
    else {
      printf("\n alguien plis \n");
    }

    sleep_ms(800);

  }

  
}
```

Boton.h

```cpp
// Boton.h
// declaraciones de la clase Boton

#ifndef BOTON_H
#define BOTON_H

// esto lo agregamos para GPIO
// general purpose input output
#include "hardware/gpio.h"

// definir clase Boton
class Boton {

  // todo publico
  // nada de andar privatizando
  public:

  // atributos
  bool presionado = false;
  int duracionPresionado = 0;
  int patita;


  // constructor
  Boton(int nuevaPatita);

  // metodos
  void leer();
  void presionar();
  void soltar();

};

#endif
```

Boton.cpp

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
```
## lectura
