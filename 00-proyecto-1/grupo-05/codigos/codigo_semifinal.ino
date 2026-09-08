#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Importamos nuestras librerías con los bitmaps
#include "bitmapluna.h"
#include "bitmapcorazon.h"
#include "bitmapojo.h"
#include "bitmapcaballo.h"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32

#define OLED_RESET     -1
#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define POT_PIN A0
#define BUTTON_PIN 2

const char* frases[] = {
  "Extracto poema Romance de la luna, luna.", // 0
  "Federico Garcia Lorca.",                  // 1
  "Huye luna, luna, luna.",                  // 2 (Animación Luna)
  "Si vinieran los gitanos,",                // 3
  "harian con tu corazon",                   // 4 (Animación Corazón)
  "collares y anillos blancos.",             // 5
  "Nino, dejame que baile.",                 // 6
  "Cuando vengan los gitanos,",              // 7
  "te encontraran sobre el yunque",          // 8
  "con los ojillos cerrados.",               // 9 (Animación Ojo)
  "Huye luna, luna, luna,",                  // 10 (Animación Luna)
  "que ya siento sus caballos.",             // 11 (Animación Caballo)
  "Nino, dejame, no pises",                  // 12
  "mi blancor almidonado."                   // 13
};

const int cantidadFrases = sizeof(frases) / sizeof(frases[0]);
int fraseActual = 0;

int16_t textWidth, textHeight;
int minX;
bool botonPresionadoAntes = false;

float xPos = 0;          
int potAnterior = 0;     

unsigned long frameInterval = 100;       
unsigned long previousFrameMillis = 0;
uint8_t currentFrame = 0;

const int ANIM_WIDTH  = 128;
const int ANIM_HEIGHT = 32;
const int xOffsetCentered = (SCREEN_WIDTH  - ANIM_WIDTH)  / 2;
const int yOffset = (SCREEN_HEIGHT - ANIM_HEIGHT) / 2;

unsigned long previousMoveMillis = 0;
int xPosCaballo = -128;  
const int xStep = 2;     

bool mostrandoAnimacion = false;

void drawPageBitmap(const uint8_t* bitmap, int bmpWidth, int bmpHeight, int xPos, int yPos) {
  uint8_t pages = bmpHeight / 8;
  for (uint8_t page = 0; page < pages; page++) {
    for (int col = 0; col < bmpWidth; col++) {
      uint8_t byteData = pgm_read_byte(&bitmap[page * bmpWidth + col]);
      if (byteData == 0) continue; 

      int screenX = col + xPos;
      if (screenX < 0 || screenX >= SCREEN_WIDTH) continue; 

      for (uint8_t bit = 0; bit < 8; bit++) {
        if (byteData & (1 << bit)) {
          int screenY = page * 8 + bit + yPos;
          if (screenY < 0 || screenY >= SCREEN_HEIGHT) continue;
          display.drawPixel(screenX, screenY, SSD1306_WHITE);
        }
      }
    }
  }
}

void actualizarMedidasTexto() {
  int16_t x1, y1;
  display.getTextBounds(frases[fraseActual], 0, 0, &x1, &y1, (uint16_t*)&textWidth, (uint16_t*)&textHeight);
  minX = SCREEN_WIDTH - textWidth;
  if (minX > 0) minX = 0;

  xPos = 0; 
  Serial.print("Frase (");
  Serial.print(fraseActual + 1);
  Serial.print("/");
  Serial.print(cantidadFrases);
  Serial.print("): ");
  Serial.println(frases[fraseActual]);
}

void setup() {
  Serial.begin(115200);
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
    if (mostrandoAnimacion) {
      mostrandoAnimacion = false;
      fraseActual = (fraseActual + 1) % cantidadFrases;
      actualizarMedidasTexto();
    } else {
      if (fraseActual == 2 || fraseActual == 10 || fraseActual == 4 || fraseActual == 9 || fraseActual == 11) {
        mostrandoAnimacion = true; 
        currentFrame = 0; 
        
        if (fraseActual == 9) {
          frameInterval = 400; 
        } else if (fraseActual == 11) {
          frameInterval = 100;
          xPosCaballo = -128;  
        } else {
          frameInterval = 100;
        }
      } else {
        fraseActual = (fraseActual + 1) % cantidadFrases;
        actualizarMedidasTexto();
      }
    }
    
    delay(200); 
    potAnterior = analogRead(POT_PIN); 
  }
  
  botonPresionadoAntes = botonPresionadoAhora;

  display.clearDisplay();

  if (mostrandoAnimacion) {
    uint8_t totalFrames = (fraseActual == 11) ? 4 : 3;
    unsigned long currentMillis = millis();

    if (currentMillis - previousFrameMillis >= frameInterval) {
      previousFrameMillis = currentMillis;
      currentFrame = (currentFrame + 1) % totalFrames;
    }

    if (fraseActual == 4) {
      drawPageBitmap(animationFramesCorazon[currentFrame], ANIM_WIDTH, ANIM_HEIGHT, xOffsetCentered, yOffset);
    } else if (fraseActual == 9) {
      drawPageBitmap(animationFramesOjo[currentFrame], ANIM_WIDTH, ANIM_HEIGHT, xOffsetCentered, yOffset);
    } else if (fraseActual == 11) {
      if (currentMillis - previousMoveMillis >= 20) { 
        previousMoveMillis = currentMillis;
        xPosCaballo += xStep;
        if (xPosCaballo > 128) {
          xPosCaballo = -128;
        }
      }
      drawPageBitmap(animationFramesCaballo[currentFrame], ANIM_WIDTH, ANIM_HEIGHT, xPosCaballo, yOffset);
    } else {
      drawPageBitmap(animationFramesLuna[currentFrame], ANIM_WIDTH, ANIM_HEIGHT, xOffsetCentered, yOffset);
    }
    
  } else {
    int potValue = analogRead(POT_PIN);
    int deltaPot = potValue - potAnterior;
    potAnterior = potValue;

    if (minX != 0) {
      float deltaPix = (float)deltaPot * minX / 1023.0;
      xPos += deltaPix;
    }

    if (xPos < minX) xPos = minX;
    if (xPos > 0) xPos = 0;

    int yPos = (SCREEN_HEIGHT - textHeight) / 2;
    display.setTextWrap(false);
    display.setCursor((int)xPos, yPos);
    display.print(frases[fraseActual]);
  }

  display.display();
  delay(20);
}