// esto venia en wokwi
#include <stdio.h>
#include "pico/stdlib.h"

// incluir mis archivos
#include "Boton.h"
#include "Pote.h"

int main() {

  stdio_init_all();

  // crear Boton que se llama miPrimerBoton
  // con el constructor
  Boton miPrimerBoton(7);
  Boton miSegundoBoton(6);
  
  Pote miPrimerPote(26,0);

  while (true) {

    miPrimerBoton.leer();

    if (miPrimerBoton.presionado) {
      printf("bacan estoy presionado, pero igual me presiona\n");
    }

    miSegundoBoton.leer();

    if (miSegundoBoton.presionado) {
      printf("ayudaaaa, sueltameeeee\n");
    }

    if (miPrimerBoton.presionado == false && miSegundoBoton.presionado == false) {
      printf("estoy, terrible solo loco\n");
    }
    
    sleep_ms(10);
    //actualiza la lectura
    miPrimerPote.leerPote();

    printf("Lectura ADC: %d\n", miPrimerPote.valorPote);
        sleep_ms(1000);

  }
}