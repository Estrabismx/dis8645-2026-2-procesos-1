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
  
  while (true) {

    miPrimerBoton.leer();

    if (miPrimerBoton.presionado) {
      printf("bacan estoy presionado, pero igual me presiona\n");
    }
    else {
      // cuando no este presionado
      printf("no hay nadie presionandome\n");
    }

    sleep_ms(10);

  }
}