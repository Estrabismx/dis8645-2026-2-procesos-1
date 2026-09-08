/* ============================================================
   PROYECTO DE TALLER - "Irse y no volver..."
   Fragmento del poema "Puerto adelante" de Alejandra Pizarnik.

   Componentes:
   - Pantalla OLED SSD1306 128x32 (I2C)
   - Potenciómetro B20K
   - Botón pulsador
   ============================================================ */

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// ---------------- CONFIGURACIÓN DE PANTALLA ----------------
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// ---------------- PINES ----------------
const int PIN_BOTON = 2;
const int PIN_POTENCIOMETRO = A0;

// ---------------- MODOS DE OPERACIÓN ----------------
enum ModoOperacion {
  MODO_POTENCIOMETRO,
  MODO_DEMO
};

ModoOperacion modoActual = MODO_POTENCIOMETRO;

// ---------------- CONTROL DE PÁGINAS ----------------
// 0: Irse
// 1: y
// 2: no
// 3: volver...
// 4: puerto adelante
// 5: autora
// 6: ilustración
const int NUM_PAGINAS = 7;

int paginaActual = -1;

// ---------------- TEXTOS ----------------
const char LINEA_IRSE[]    = "Irse";
const char LINEA_Y[]       = "y";
const char LINEA_NO[]      = "no";
const char LINEA_VOLVER[]  = "volver...";
const char LINEA_PUERTO[]  = "puerto adelante";
const char LINEA_AUTOR_1[] = "Alejandra Pizarnik";
const char LINEA_AUTOR_2[] = "(uso educativo)";

// ---------------- DURACIÓN DEL MODO DEMO ----------------
const unsigned long DURACIONES_PAGINA[NUM_PAGINAS] = {
  900,    // Irse
  600,    // y
  700,    // no
  1200,   // volver...
  2200,   // puerto adelante
  2500,   // autora
  4000    // ilustración
};

// ---------------- POTENCIÓMETRO ----------------
int valorPotenciometro = 0;

// ---------------- BOTÓN / DEBOUNCE ----------------
bool estadoBotonActual = HIGH;
bool estadoBotonAnterior = HIGH;

unsigned long ultimoCambioBoton = 0;

const unsigned long TIEMPO_DEBOUNCE = 50;

// ---------------- MODO DEMO ----------------
unsigned long tiempoInicioPaginaDemo = 0;

// ---------------- TEXTO ----------------
const int TAMANO_TEXTO = 1;
const int ESPACIO_ENTRE_LINEAS = 12 * TAMANO_TEXTO;

// ---------------- PROTOTIPOS ----------------
void leerBoton();
bool debounceBoton();
int determinarPaginaPorPotenciometro();
void actualizarModoDemo();
void mostrarPagina(int numeroPagina);
void dibujarTexto(const char* linea1, const char* linea2);
void dibujarIlustracion();
int calcularX_centrado(const char* texto);


// ============================================================
// SETUP
// ============================================================

void setup() {

  Serial.begin(9600);

  pinMode(PIN_BOTON, INPUT_PULLUP);
  pinMode(PIN_POTENCIOMETRO, INPUT);

  // Iniciar pantalla OLED
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {

    Serial.println(F("Fallo al iniciar SSD1306"));

    for (;;);
  }

  display.clearDisplay();

  display.setTextSize(TAMANO_TEXTO);
  display.setTextColor(SSD1306_WHITE);

  // Mostrar primera página
  paginaActual = determinarPaginaPorPotenciometro();

  mostrarPagina(paginaActual);
}


// ============================================================
// LOOP
// ============================================================

void loop() {

  // Revisar botón
  leerBoton();

  // MODO POTENCIÓMETRO
  if (modoActual == MODO_POTENCIOMETRO) {

    int nuevaPagina = determinarPaginaPorPotenciometro();

    if (nuevaPagina != paginaActual) {

      paginaActual = nuevaPagina;

      mostrarPagina(paginaActual);
    }
  }

  // MODO DEMO
  else {

    actualizarModoDemo();
  }

  delay(20);
}


// ============================================================
// BOTÓN
// ============================================================

// Alterna entre:
// Potenciómetro <-> Demo

void leerBoton() {

  if (debounceBoton()) {

    // Entrar al modo DEMO
    if (modoActual == MODO_POTENCIOMETRO) {

      modoActual = MODO_DEMO;

      paginaActual = 0;

      tiempoInicioPaginaDemo = millis();

      mostrarPagina(paginaActual);
    }

    // Volver al modo POTENCIÓMETRO
    else {

      modoActual = MODO_POTENCIOMETRO;

      paginaActual = determinarPaginaPorPotenciometro();

      mostrarPagina(paginaActual);
    }
  }
}


// ============================================================
// DEBOUNCE DEL BOTÓN
// ============================================================

bool debounceBoton() {

  bool lectura = digitalRead(PIN_BOTON);

  bool pulsacionDetectada = false;

  // Si cambió la lectura
  if (lectura != estadoBotonAnterior) {

    ultimoCambioBoton = millis();
  }

  // Esperar para confirmar que el cambio es real
  if ((millis() - ultimoCambioBoton) > TIEMPO_DEBOUNCE) {

    if (lectura != estadoBotonActual) {

      estadoBotonActual = lectura;

      // INPUT_PULLUP:
      // LOW = botón presionado
      if (estadoBotonActual == LOW) {

        pulsacionDetectada = true;
      }
    }
  }

  estadoBotonAnterior = lectura;

  return pulsacionDetectada;
}


// ============================================================
// POTENCIÓMETRO
// ============================================================

// Divide el rango 0-1023 del potenciómetro
// en las 7 páginas.

int determinarPaginaPorPotenciometro() {

  valorPotenciometro = analogRead(PIN_POTENCIOMETRO);

  long pagina =
    (long)valorPotenciometro * NUM_PAGINAS / 1024;

  return constrain(
    (int)pagina,
    0,
    NUM_PAGINAS - 1
  );
}


// ============================================================
// MODO DEMO
// ============================================================

void actualizarModoDemo() {

  if (
    millis() - tiempoInicioPaginaDemo
    >= DURACIONES_PAGINA[paginaActual]
  ) {

    paginaActual++;

    // Volver a la página 0 al terminar
    if (paginaActual >= NUM_PAGINAS) {

      paginaActual = 0;
    }

    mostrarPagina(paginaActual);

    tiempoInicioPaginaDemo = millis();
  }
}


// ============================================================
// MOSTRAR PÁGINA
// ============================================================

void mostrarPagina(int numeroPagina) {

  switch (numeroPagina) {

    case 0:
      dibujarTexto(LINEA_IRSE, "");
      break;

    case 1:
      dibujarTexto(LINEA_Y, "");
      break;

    case 2:
      dibujarTexto(LINEA_NO, "");
      break;

    case 3:
      dibujarTexto(LINEA_VOLVER, "");
      break;

    case 4:
      dibujarTexto(LINEA_PUERTO, "");
      break;

    case 5:
      dibujarTexto(
        LINEA_AUTOR_1,
        LINEA_AUTOR_2
      );
      break;

    case 6:
      dibujarIlustracion();
      break;
  }
}


// ============================================================
// CENTRAR TEXTO
// ============================================================

int calcularX_centrado(const char* texto) {

  int16_t x1;
  int16_t y1;

  uint16_t anchoTexto;
  uint16_t altoTexto;

  display.getTextBounds(
    texto,
    0,
    0,
    &x1,
    &y1,
    &anchoTexto,
    &altoTexto
  );

  int x =
    (SCREEN_WIDTH - anchoTexto) / 2;

  if (x < 0) {

    x = 0;
  }

  return x;
}


// ============================================================
// DIBUJAR TEXTO
// ============================================================

void dibujarTexto(
  const char* linea1,
  const char* linea2
) {

  display.clearDisplay();

  int yLinea1;

  // Si hay una sola línea,
  // centrar verticalmente
  if (strlen(linea2) == 0) {

    yLinea1 =
      (SCREEN_HEIGHT - (8 * TAMANO_TEXTO)) / 2;
  }

  // Si hay dos líneas
  else {

    yLinea1 = 4;
  }

  int yLinea2 =
    yLinea1 + ESPACIO_ENTRE_LINEAS;

  // Primera línea
  display.setCursor(
    calcularX_centrado(linea1),
    yLinea1
  );

  display.print(linea1);

  // Segunda línea
  if (strlen(linea2) > 0) {

    display.setCursor(
      calcularX_centrado(linea2),
      yLinea2
    );

    display.print(linea2);
  }

  display.display();
}


// ============================================================
// ILUSTRACIÓN
// BARCO YÉNDOSE / ALEJÁNDOSE DEL MUELLE
// ============================================================

void dibujarIlustracion() {

  display.clearDisplay();

  // ----------------------------------------------------------
  // HORIZONTE
  // ----------------------------------------------------------

  display.drawLine(
    24, 17,
    127, 17,
    SSD1306_WHITE
  );


  // ----------------------------------------------------------
  // MUELLE
  // Queda atrás, a la izquierda.
  // ----------------------------------------------------------

  // Plataforma
  display.drawLine(
    0, 18,
    22, 18,
    SSD1306_WHITE
  );

  // Poste 1
  display.drawLine(
    4, 18,
    4, 30,
    SSD1306_WHITE
  );

  // Poste 2
  display.drawLine(
    16, 18,
    16, 30,
    SSD1306_WHITE
  );

  // Parte inferior del muelle
  display.drawLine(
    0, 30,
    22, 30,
    SSD1306_WHITE
  );


  // ----------------------------------------------------------
  // BARCO
  // Se encuentra separado del muelle,
  // avanzando hacia la derecha.
  // ----------------------------------------------------------

  // Casco
  display.fillTriangle(
    65, 20,
    105, 20,
    112, 25,
    SSD1306_WHITE
  );

  display.fillTriangle(
    65, 20,
    112, 25,
    72, 26,
    SSD1306_WHITE
  );


  // ----------------------------------------------------------
  // MÁSTIL
  // ----------------------------------------------------------

  display.drawLine(
    82, 20,
    82, 5,
    SSD1306_WHITE
  );


  // ----------------------------------------------------------
  // VELA
  // Inclinada hacia la derecha,
  // dando sensación de movimiento.
  // ----------------------------------------------------------

  display.fillTriangle(
    82, 6,
    82, 19,
    101, 16,
    SSD1306_WHITE
  );


  // ----------------------------------------------------------
  // BANDERA
  // ----------------------------------------------------------

  display.drawLine(
    82, 5,
    88, 7,
    SSD1306_WHITE
  );

  display.drawLine(
    82, 9,
    88, 7,
    SSD1306_WHITE
  );


  // ----------------------------------------------------------
  // ESTELA DEL BARCO
  // Deja una estela hacia la izquierda,
  // reforzando la idea de que se está yendo.
  // ----------------------------------------------------------

  display.drawLine(
    62, 27,
    55, 25,
    SSD1306_WHITE
  );

  display.drawLine(
    54, 29,
    46, 27,
    SSD1306_WHITE
  );

  display.drawLine(
    45, 26,
    38, 24,
    SSD1306_WHITE
  );

  display.drawLine(
    36, 29,
    29, 27,
    SSD1306_WHITE
  );


  // ----------------------------------------------------------
  // OLAS
  // ----------------------------------------------------------

  display.drawLine(
    25, 23,
    31, 21,
    SSD1306_WHITE
  );

  display.drawLine(
    32, 23,
    38, 21,
    SSD1306_WHITE
  );

  display.drawLine(
    42, 24,
    48, 22,
    SSD1306_WHITE
  );

  display.drawLine(
    50, 30,
    57, 28,
    SSD1306_WHITE
  );

  display.drawLine(
    60, 30,
    67, 28,
    SSD1306_WHITE
  );

  display.drawLine(
    74, 30,
    81, 28,
    SSD1306_WHITE
  );

  display.drawLine(
    88, 30,
    95, 28,
    SSD1306_WHITE
  );

  display.drawLine(
    100, 30,
    107, 28,
    SSD1306_WHITE
  );


  // ----------------------------------------------------------
  // AVES A LO LEJOS
  // ----------------------------------------------------------

  display.drawLine(
    103, 7,
    106, 4,
    SSD1306_WHITE
  );

  display.drawLine(
    106, 4,
    109, 7,
    SSD1306_WHITE
  );

  display.drawLine(
    116, 10,
    119, 7,
    SSD1306_WHITE
  );

  display.drawLine(
    119, 7,
    122, 10,
    SSD1306_WHITE
  );


  // ----------------------------------------------------------
  // MOSTRAR TODO
  // ----------------------------------------------------------

  display.display();
}