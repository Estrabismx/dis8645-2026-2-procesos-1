#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
#define OLED_RESET     -1
#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// ----------------------------------------------------------------
// un poemario es un arreglo de paginas
// una pagina es un arreglo de lineas
// una linea es un arreglo de caracteres (char*)
// ----------------------------------------------------------------

const char* pagina1[] = {
  "irse",
  "y",
  "no",
  "volver",
};

const char* pagina2[] = {
  "alejandra pizarnik",
  "",
  "",
  "",
};

const char** poemario[] = { pagina1, pagina2 };

const int numPaginas = 2;
const int lineasPorPagina = 4;

// ----------------------------------------------------------------
// PROTOTIPOS
// ----------------------------------------------------------------
const char* siguienteLinea();

// ----------------------------------------------------------------
// variables para el movimiento (rebote tipo "logo de DVD")
// ----------------------------------------------------------------
int x, y;          // posicion actual del texto
int dx = 2, dy = 1; // cuanto se mueve en cada frame (velocidad)
int textW, textH;  // ancho y alto del texto actual (se calculan solo)

unsigned long tiempoInicioLinea = 0;
const unsigned long duracionPorLinea = 4000; // 4 seg por linea, ajustable

int paginaActual = 0;
int lineaActual = 0;

void setup() {
  Serial.begin(9600);
  delay(500);

  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  // arrancamos en la esquina superior izquierda
  x = 0;
  y = 0;
  tiempoInicioLinea = millis();
}

void loop() {
  const char* texto = siguienteLinea();

  // calcula cuanto mide el texto en pixeles, para saber
  // hasta donde puede moverse sin salirse de la pantalla
  int16_t x1, y1;
  display.getTextBounds(texto, 0, 0, &x1, &y1, (uint16_t*)&textW, (uint16_t*)&textH);

  // mover la posicion
  x += dx;
  y += dy;

  // rebotar en los bordes (como el logo de DVD)
  if (x <= 0 || x + textW >= SCREEN_WIDTH)  dx = -dx;
  if (y <= 0 || y + textH >= SCREEN_HEIGHT) dy = -dy;

  // dibujar
  display.clearDisplay();
  display.setCursor(x, y);
  display.print(texto);
  display.display();

  // cada cierto tiempo, pasar a la siguiente linea del poemario
  if (millis() - tiempoInicioLinea >= duracionPorLinea) {
    avanzarLinea();
    tiempoInicioLinea = millis();
  }

  delay(30); // velocidad del movimiento (frames por segundo)
}

// ----------------------------------------------------------------
// devuelve la linea que toca mostrar ahora mismo
// ----------------------------------------------------------------
const char* siguienteLinea() {
  return poemario[paginaActual][lineaActual];
}

// ----------------------------------------------------------------
// avanza linea por linea, y de pagina en pagina, y al llegar
// al final del poemario vuelve a empezar (bucle infinito)
// ----------------------------------------------------------------
void avanzarLinea() {
  lineaActual++;
  if (lineaActual >= lineasPorPagina) {
    lineaActual = 0;
    paginaActual++;
    if (paginaActual >= numPaginas) {
      paginaActual = 0; // vuelve a la primera pagina: aqui esta el bucle
    }
  }
}