#ifndef LED_H
#define LED_H

// esto lo agregamos para GPIO
// general purpose input output
#include "pico/stdlib.h"

class Led {

  public:

  //atributos -----
  int conexionLed; //en que GPio se encuentra conectado
  bool encendido = false;
  unsigned int duracionEncendido = 0;


  //constructor -----
  Led(int nuevaConexionLed);

  //metodos -----
  void encenderLed();
  void apagarLed();
  void oscilarLed();
  };

#endif // esto sumado a la primera linea sirven para que solo sea llamado una vez y no caiga en un bucle