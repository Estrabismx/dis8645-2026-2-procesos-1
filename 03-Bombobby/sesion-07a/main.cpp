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
  Boton miSegundoBoton(8);

  while (true) {

    miPrimerBoton.leer();
    miSegundoBoton.leer();

    //el primero boton dice una cosa

    if (miPrimerBoton.presionado) {
      printf("bacan estoy presionado, pero igual me impresiona\n");
    }

    //el segundo boton dice otra cosa

    if (miSegundoBoton.presionado) {
      printf("no me presiones porfa, gracias \n");
    }

    //si ningun botón está presionado
    // ! invierte el valor
    // entonces !blablabla.presionado
    // en realidad significa que no está presionado
    // && une dos condiciones y ambas deben cumplirse a la vez

    if (!miPrimerBoton.presionado && !miSegundoBoton.presionado) {
      printf("no hay nadie presionandome\n");
    }

    sleep_ms(10);

  }
}