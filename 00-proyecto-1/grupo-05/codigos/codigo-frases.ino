#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32


#define OLED_RESET     -1
#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


#define POT_PIN A0
#define BUTTON_PIN 2


// Reemplaza cada línea con un verso de tu poema
const char* frases[] = {
  "Huye luna, luna, luna.",
  "Si vinieran los gitanos,",
  "harian con tu corazon",
  "collares y anillos blancos.",
  "Nino, dejame que baile.",
  "Cuando vengan los gitanos,",
  "te encontraran sobre el yunque",
  "con los ojillos cerrados.",
  "Huye luna, luna, luna,",
  "que ya siento sus caballos.",
  "Nino, dejame, no pises",
  "mi blancor almidonado."
};
const int cantidadFrases = sizeof(frases) / sizeof(frases[0]);
int fraseActual = 0;


int16_t textWidth, textHeight;
int minX;


bool botonPresionadoAntes = false;


// --- Variables para el control relativo del potenciómetro ---
float xPos = 0;          // Posición actual del texto (persistente entre frases)
int potAnterior = 0;     // Última lectura del potenciómetro, para calcular el delta


void actualizarMedidasTexto() {
  int16_t x1, y1;
  display.getTextBounds(frases[fraseActual], 0, 0, &x1, &y1, (uint16_t*)&textWidth, (uint16_t*)&textHeight);
  minX = SCREEN_WIDTH - textWidth;
  if (minX > 0) minX = 0;


  // Cada vez que cambia la frase, la posición vuelve a 0 (inicio de la frase)
  xPos = 0;


  Serial.print("Frase (");
  Serial.print(fraseActual + 1);
  Serial.print("/");
  Serial.print(cantidadFrases);
  Serial.print("): ");
  Serial.println(frases[fraseActual]);
}


void setup() {
  Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT_PULLUP);


  delay(500);


  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }


  display.display();
  delay(1000);
  display.clearDisplay();


  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setTextWrap(false);


  potAnterior = analogRead(POT_PIN);
  actualizarMedidasTexto();
}


void loop() {
  bool botonPresionadoAhora = (digitalRead(BUTTON_PIN) == LOW);


  if (botonPresionadoAhora && !botonPresionadoAntes) {
    fraseActual = (fraseActual + 1) % cantidadFrases; // al llegar a 12, vuelve a 0
    actualizarMedidasTexto(); // esto resetea xPos a 0 (inicio de la nueva frase)
    delay(200); // antirrebote


    // Recién AQUÍ, después del delay, capturamos la referencia del pot.
    // Así, cualquier movimiento que hagas durante el delay no genera un salto,
    // y puedes seguir moviendo el potenciómetro desde donde esté físicamente.
    potAnterior = analogRead(POT_PIN);
  }


  botonPresionadoAntes = botonPresionadoAhora;


  int potValue = analogRead(POT_PIN);


  // Calculamos cuánto se movió el potenciómetro desde la última lectura
  int deltaPot = potValue - potAnterior;
  potAnterior = potValue;


  // Convertimos ese movimiento a píxeles, usando la misma escala que antes
  // (rango completo del pot 0-1023 equivale al rango completo de scroll 0-minX)
  if (minX != 0) {
    float deltaPix = (float)deltaPot * minX / 1023.0;
    xPos += deltaPix;
  }


  // Limitamos xPos para que no se salga del rango válido de scroll
  if (xPos < minX) xPos = minX;
  if (xPos > 0) xPos = 0;


  int yPos = (SCREEN_HEIGHT - textHeight) / 2;


  display.clearDisplay();
  display.setTextWrap(false);
  display.setCursor((int)xPos, yPos);
  display.print(frases[fraseActual]);
  display.display();


  delay(20);
}



