#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels


#define OLED_RESET     -1 // Reset pin # (o -1 si comparte el reset del Arduino)
#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


#define POT_PIN A0        // Pin donde se conecta el potenciómetro


const char* texto = "hola";
int16_t textWidth, textHeight; // Se calculan en setup()


void setup() {
  Serial.begin(9600);


  delay(500);


  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // No continuar
  }


  display.display();
  delay(1000);
  display.clearDisplay();


  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);


  // Calculamos el ancho del texto para saber el rango válido de movimiento
  int16_t x1, y1;
  display.getTextBounds(texto, 0, 0, &x1, &y1, (uint16_t*)&textWidth, (uint16_t*)&textHeight);
}


void loop() {
  // Leemos el potenciómetro (0-1023 con resolución por defecto de 10 bits)
  int potValue = analogRead(POT_PIN);


  // Mapeamos el valor del potenciómetro al rango de posiciones X válidas
  // para que el texto se mueva de izquierda a derecha sin salirse de la pantalla
  int maxX = SCREEN_WIDTH - textWidth;
  if (maxX < 0) maxX = 0; // por si el texto es más ancho que la pantalla


  int xPos = map(potValue, 0, 1023, 0, maxX);


  // Posición vertical centrada
  int yPos = (SCREEN_HEIGHT - textHeight) / 2;


  display.clearDisplay();
  display.setCursor(xPos, yPos);
  display.print(texto);
  display.display();


  delay(20); // pequeño delay para estabilidad de lectura y refresco
}
