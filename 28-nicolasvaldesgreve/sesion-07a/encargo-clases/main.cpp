// este es main.cpp

// esto venia en wokwi
#include <stdio.h>
#include "pico/stdlib.h"

// incluir mis archivos
#include "Boton.h"
#include "Led.h"

int main() {

  stdio_init_all();

  // crear Boton que se llama miPrimerBoton
  // con el constructor
  Boton miPrimerBoton(7);
  Boton miSegundoBoton(22);

  // crear LED que es mi unico LED... hola
  Led miUnicoLed(20);
  
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
        miUnicoLed.encender();
    }
    else {
      printf("\n alguien plis \n");
      miUnicoLed.apagar();
    }

    sleep_ms(800);

  }

  
}