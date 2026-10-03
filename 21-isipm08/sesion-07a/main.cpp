#include <stdio.h>
#include "pico/stdlib.h"

class Boton {
  private:
    uint pin; // almacena número GP asignado al botón
    bool estadoAnterior; //estado de suelto a presionado 
    bool pullUp; // tipo de configuración del botón
    // botón se conecta a GND usando la resistencia Pull-Up interna (true) 
    // utiliza un circuito Pull-Down externo conectado a $3.3 (false)

  public:
    bool presionado;
    // atributo si el botón si está presionado (true) o si no está presionado (false)
    int contadorPresiones; // nuevo atributo, tipo entera, guarda total de pulsaciones realizadas sobre el botón

    // constructor pull-Up
    Boton(uint pinNumero, bool usarPullUp = true) {
      pin = pinNumero; // configura entrada 
      pullUp = usarPullUp;
      presionado = false;
      estadoAnterior = false;
      contadorPresiones = 0; // inicio, contador en 0

      gpio_init(pin);
      gpio_set_dir(pin, GPIO_IN);

      if (pullUp) {
        gpio_pull_up(pin); // botones conectados a GND
      } else {
        gpio_disable_pulls(pin); // botón pull-down 
      // activar resistencia Pull-Up interna
      // si usarPullUp es true (caso del botón 2)
      // si es false, deshabilita las resistencias internas 
      // para no interferir con la resistencia externa que tiene el botón 1
      }
    }

    // estado ajustado al tipo de conexión
    void leer() {
      bool estadoActual;

      if (pullUp) {
        // En Pull-Up: Presionado = 0 (LOW), por eso invertimos (!)
        estadoActual = !gpio_get(pin);
      } else {
        // En Pull-Down externo (Tu Botón 1): Presionado = 1 (HIGH)
        estadoActual = gpio_get(pin);
      }

      // Incrementa el contador al momento de detectar la pulsación
      if (estadoActual && !estadoAnterior) {
        contadorPresiones++;
      }

      presionado = estadoActual;
      estadoAnterior = estadoActual;
    }

    // NUEVO MÉTODO
    int obtenerContador() {
      return contadorPresiones;
    }
};

int main() {
  stdio_init_all();

  // Configurar el LED en GP15
  const uint PIN_LED = 15;
  gpio_init(PIN_LED);
  gpio_set_dir(PIN_LED, GPIO_OUT);

  // Instancia 1: GP7 con Pull-Down externo (usarPullUp = false)
  Boton miPrimerBoton(7, false);

  // Instancia 2: GP16 con Pull-Up interno (usarPullUp = true, valor por defecto)
  Boton miSegundoBoton(16, true);

  uint32_t ultimoTiempoImpresion = 0;

  while (true) {
    // Lectura constante de ambos botones
    miPrimerBoton.leer();
    miSegundoBoton.leer();

    // --- ACCIÓN DEL SEGUNDO BOTÓN (Acción inmediata) ---
    if (miSegundoBoton.presionado) {
      gpio_put(PIN_LED, 1); // Enciende el LED en GP15
    } else {
      gpio_put(PIN_LED, 0); // Apaga el LED
    }

    // --- ACCIÓN DEL PRIMER BOTÓN (Mensaje cada 300 ms) ---
    uint32_t tiempoActual = to_ms_since_boot(get_absolute_time());
    if (tiempoActual - ultimoTiempoImpresion >= 300) {

      if (miPrimerBoton.presionado) {
        printf("bacan estoy presionado, pero igual me presiona\n");
      } else {
        printf("no hay nadie presionandome\n");
      }

      if (miSegundoBoton.presionado) {
        printf("-> [Botón 2 activo en GP16] Veces presionado: %d\n", miSegundoBoton.obtenerContador());
      }

      ultimoTiempoImpresion = tiempoActual;
    }

    sleep_ms(10);
  }
}