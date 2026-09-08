#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
#define OLED_RESET    -1
#define SCREEN_ADDRESS 0x3C 

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const int potPin = A0;
int valorAnterior = -1;

void setup() {
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    for (;;); // Bloqueo si no detecta la pantalla
  }
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
}

void loop() {
  int lecturaADC = analogRead(potPin);
  // Mapea de 0-1023 al rango 1-7 (se usa 8 en el límite superior para abarcar bien el 7)
  int numero = map(lecturaADC, 0, 1024, 1, 8);
  numero = constrain(numero, 1, 7);

  // Solo actualiza la pantalla si el valor cambió para evitar parpadeos
  if (numero != valorAnterior) {
    valorAnterior = numero;
    display.clearDisplay();
    display.setTextSize(3);
    // Centrar el número en la pantalla (128x32)
    display.setCursor(55, 6);
    display.print(numero);
    display.display();
  }
  delay(20);
}

Versión 02: Incorporación de Filtro de Ruido y arreglos de texto (Prueba Akriila)
C++
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
#define OLED_RESET    -1
#define SCREEN_ADDRESS 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const int potPin = A0;

// Arreglo de versos (5 elementos: índices 0 a 4)
const char *misVersos[] = {
  "Mami, no te haga' de rogar",
  "No me gustaria perder el tiempo",
  "Que tenemo' pa' poderte tocar",
  "Y estas con otro, esa mierda no lo entiendo, yeah",
  "Que te lo juro, no eres nada pa' mi, te lo juro, ah"
};

const int totalVersos = sizeof(misVersos) / sizeof(misVersos[0]);

int versoActual = -1;
int lecturaFiltrada = 0;

void setup() {
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    for (;;);
  }
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextWrap(true); 
  lecturaFiltrada = analogRead(potPin);
}

void loop() {
  // 1. Filtro paso bajo (Exponential Moving Average) para suavizar la lectura
  int lecturaRaw = analogRead(potPin);
  lecturaFiltrada = (lecturaFiltrada * 7 + lecturaRaw) / 8;

  // 2. Mapeo seguro al rango de índices (0 a 4)
  int nuevoVerso = map(lecturaFiltrada, 0, 1024, 0, totalVersos);
  nuevoVerso = constrain(nuevoVerso, 0, totalVersos - 1);

  // 3. Actualización de pantalla solo al cambiar de verso
  if (nuevoVerso != versoActual) {
    versoActual = nuevoVerso;
    display.clearDisplay();
    display.setTextSize(1);
    display.setCursor(0, 4);
    display.print(misVersos[versoActual]);
    display.display();
  }
  delay(20);
}
