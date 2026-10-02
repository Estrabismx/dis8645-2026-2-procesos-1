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
  
  Boton miSegundoBoton(6);


  while (true) {

    miPrimerBoton.leer();
    miSegundoBoton.leer();

    if (miPrimerBoton.presionado) {
      printf("bacan estoy presionado, pero igual me presiona\n");
    }
    if (miSegundoBoton.presionado){
      miSegundoBoton.contar();
      printf("segundo botón in the house durante %d\n", miSegundoBoton.contador);
    }

    if (miPrimerBoton.presionado==false && miSegundoBoton.presionado==false){
      // cuando no este presionado ningun botón
      printf("nadie en casa\n");
    }

    sleep_ms(10);

  }
}