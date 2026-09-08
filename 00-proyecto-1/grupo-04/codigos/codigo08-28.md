 ```cpp

/*
 * ---------------------------------------------------------------
 * USAGE NOTICE / FAIR USE - FAIR DEALING
 * ---------------------------------------------------------------
 * The text of the poem "Pepper Sauce" (from the collection
 * "Pepper Seed", 2013) used in this code belongs to its author,
 * Malika Booker.
 *
 * This text is partially reproduced in this project for strictly
 * educational, non-commercial purposes, as part of an academic
 * project at Universidad Diego Portales (UDP). The use is
 * transformative: the poem is reinterpreted through text animations
 * on an OLED display as an installation piece, not reproduced or
 * distributed as a standalone work.
 *
 * No authorship over the original poem text is claimed.
 * All rights to the poem belong to Malika Booker.
 *
 * This project is non-profit and does not seek to substitute
 * for the acquisition or reading of the original work.
 * ---------------------------------------------------------------
 */

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define ANCHO_PANTALLA 128
#define ALTO_PANTALLA 32

Adafruit_SSD1306 display(ANCHO_PANTALLA, ALTO_PANTALLA, &Wire, -1);

// frame de introduccion: titulo y autora
char *intro[] = {
  "Poema 1:",
  "Pepper Sauce",
  "Malika Booker",
};

int cantidadLineasIntro = 3;

void setup() {
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    while (true);
  }

  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);

  for (int i = 0; i < cantidadLineasIntro; i++) {
    escribirLetraPorLetra(intro[i], 0, 0, 100);
    delay(700);
  }
}

void loop() {
  // vacio por ahora
}

void escribirLetraPorLetra(char *texto, int x, int y, int velocidad) {
  display.clearDisplay();
  display.setCursor(x, y);

  for (int i = 0; texto[i] != '\0'; i++) {
    display.print(texto[i]);
    display.display();
    delay(velocidad);
  }
} 
```
