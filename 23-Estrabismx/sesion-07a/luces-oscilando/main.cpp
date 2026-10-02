// esto venia en wokwi
#include <stdio.h>
#include "pico/stdlib.h"

// incluir mis archivos
#include "Boton.h"
#include "Pote.h"
#include "Led.h"

int main() {

  stdio_init_all();

  // crear Boton que se llama botonNumero
  // con el constructor

  //manera poco optima y descartada para realizar cada boton
  // Boton botonUno(8);
  // Boton botonDos(9);
  // Boton botonTres(10);
  // Boton botonCuatro(11);
  // Boton botonCinco(12);
  // Boton botonSeis(13);
  // Boton botonSiete(14);
  // Boton botonOcho(15);
  
 // mejor optar por un array
 Boton botones[] = {Boton(8), Boton(9), Boton(10), Boton(11), Boton(12), Boton(13), Boton(14), Boton(15)};

  Pote miPrimerPote(26,0);
 // lo mismo para los leds 

  // Led ledUno(16);
  // Led ledDos(17);
  // Led ledTres(18);
  // Led ledCuatro(19);
  // Led ledCinco(20);
  // Led ledSeis(21);
  // Led ledSiete(22);
  // Led ledOcho(27);
 
 Led lucesita[] = {Led(16), Led(17), Led(18), Led(19), Led(20), Led(21), Led(22), Led(27)};
 //creamos una variable para identificar que lucesita esta activa en el array
 // inicia en -1 por que el primer valor del array corresponde a 0
 int lucesitaActiva = -1;

  while (true) {

   // -- con la implementacion de los arrays, las funciones anteriores no son necesarias --
         
    // botonUno.leer();

    // if (botonUno.presionado) {
    //   ledUno.encenderLed();
    // }

    // if (ledUno.encendido == true)
    // printf("andao prendio mi loco\n");   

    // botonDos.leer();

    // if (botonDos.presionado) {
    //   ledUno.apagarLed();
    // }

    // if (ledUno.encendido == false)
    // printf("buuuu, que andan apagaos\n");

    // if (botonUno.presionado == false && botonDos.presionado == false) {
    //   ledDos.encenderLed();
    //   printf("presionen algo loco\n");

    //  } else {
    //   ledDos.apagarLed();
    // }
       
    // lee todos los botones del array
    // & sirve para actualizar el estado del boton original
    for (auto& boton : botones) {
      boton.leer();
    }

    // definimos una nueva variable llamada i
    // que posee valores de 0 a 8
    // i++ es lo mismo que decir 
    // i = i + 1
    // al valor actual de i sumale uno
    for (int i = 0; i < 8; i++) {
    if (botones[i].presionado) {

      //revisa si el boton asociado al led es distinto
      // al que se esta presionando
      if (lucesitaActiva != i) {
      //antes de apagar la luz anterior, verifica que haya una luz encendida 
      if (lucesitaActiva != -1) {
        //apaga el led
        lucesita[lucesitaActiva].apagarLed();
      }
      // actualiza cual es el led que esta activo
      lucesitaActiva = i;
    }

    // si se presionan 2 botones se cancela el for del bucle
    break;
   
    }
   }

    // esto mantiene el led oscilando sin tener que mantener el boton
    if (lucesitaActiva != -1) {
    lucesita[lucesitaActiva].oscilarLed();
    }

    sleep_ms(10);
    //actualiza la lectura
    miPrimerPote.leerPote();

    printf("Lectura ADC: %d\n", miPrimerPote.valorPote);
    printf("\n");
        sleep_ms(1000);
    

  }

}