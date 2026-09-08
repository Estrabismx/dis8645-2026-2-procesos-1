#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Fonts/FreeSans9pt7b.h>
 
 // Librería de la fuente Sans Serif
#include <Fonts/FreeSerifItalic9pt7b.h>


#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32




#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C




Adafruit_SSD1306 display(
  SCREEN_WIDTH,
  SCREEN_HEIGHT,
  &Wire,
  OLED_RESET
);


const char *versos[] = {
  "Hope is the thing with",
  "feathers",
  "That perches in",
  "the soul",
  "and sings the tune without the words",
  "and never stops",
  "at all...",
  "-Emily Dickinson"
};


// Obtenemos la cantidad total de versos
// se coloca sizepf(poema) para no tener que actualizar constantemente en caso de incluir versos
//divide la cantidad de versos totales(en bites) sobre un solo verso(en bites también).
const int totalVersos = sizeof(versos) / sizeof(versos[0]);


// Variables para el control del tiempo con millis()
//mismo tiempo1 con otro nombre
unsigned long tiempoAnterior = 0;
//intervalo de tiempo
const unsigned long intervalo = 3000;


// Índice para saber qué verso toca imprimir
int versoActual = 0;




void setup() {


Serial.begin(9600);


  // Iniciar OLED
  display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
   // ASIGNAR FUENTE
  display.setFont(&FreeSerifItalic9pt7b);
  display.display();


}


void loop() {
//le colocó esa primera parte a la función¿¿
  unsigned long tiempoActual = millis();
 
// Comprobamos si ya transcurrió el tiempo
//lo configuró al revés como una resta en vez de suma
  if (tiempoActual - tiempoAnterior >= intervalo) {
 // Actualizamos la marca de tiempo
    tiempoAnterior = tiempoActual;


    // Verificamos que aún queden versos por mostrar
    //está parte es la necesaria para ocupar el println con los versos
    if (versoActual < totalVersos) {
   //si el verso actual es menor a la cantidad de versos, o sea  no ha terminado el poema
   //entonces se cargará el VersoActual
      display.clearDisplay();
      display.setCursor(5, 10);
      display.println(versos[versoActual]);
      display.display();
   //++ para que vaya sumando 1 luego de presentar cada verso.
      versoActual++;
    }
    else {
      versoActual = 0;
    }
}
}