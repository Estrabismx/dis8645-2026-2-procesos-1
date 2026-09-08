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

Versión 04: Experimentación con pantalla OLED 20 x 4 y pantalla TFT
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>
#include <LiquidCrystal_I2C.h>

// --- Configuración TFT ST7789 (SPI) ---
#define TFT_CS    10
#define TFT_DC     9
#define TFT_RST    8
Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);

// --- Configuración LCD 20x4 (I2C en 0x25) ---
LiquidCrystal_I2C lcd(0x25, 20, 4);

// Carácter personalizado: Círculo lleno para la LCD
byte customBall[8] = {
  0b00000,
  0b01110,
  0b11111,
  0b11111,
  0b11111,
  0b01110,
  0b00000,
  0b00000
};

// Parámetros de animación
const int radioTFT = 14;
const int yTFT = 120; // Centro vertical en la TFT
int posX = -radioTFT; // Posición global en X
int dir = 1;          // 1 = derecha, -1 = izquierda
int prevX_TFT = -100;
int prevCol_LCD = -1;

// Límites: TFT va de X = 0 a 320. La LCD (20 col) se mapea virtualmente de 320 a 520
const int limiteTFT = 320;
const int limiteTotal = 520; 

void setup() {
  Serial.begin(115200);

  // 1. Inicializar LCD 20x4
  lcd.init();
  lcd.backlight();
  lcd.createChar(0, customBall);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("<- ENTRADA BOLA");
  lcd.setCursor(0, 3);
  lcd.print("PANTALLA 20x4 (0x25)");

  // 2. Inicializar TFT ST7789
  tft.init(240, 320);
  tft.setRotation(1); // Modo Horizontal: 320 ancho x 240 alto
  tft.fillScreen(ST77XX_BLACK);

  tft.setTextColor(ST77XX_CYAN);
  tft.setTextSize(2);
  tft.setCursor(20, 20);
  tft.println("TFT -> LCD Sync");
}

void loop() {
  // --- FASE 1: DENTRO DE LA PANTALLA TFT (X: 0 a 320) ---
  if (posX <= limiteTFT) {
    // Borrar posición previa en TFT
    if (prevX_TFT >= -radioTFT && prevX_TFT <= limiteTFT + radioTFT) {
      tft.fillCircle(prevX_TFT, yTFT, radioTFT, ST77XX_BLACK);
    }
    // Dibujar nueva posición si es visible
    if (posX >= -radioTFT && posX <= limiteTFT + radioTFT) {
      tft.fillCircle(posX, yTFT, radioTFT, ST77XX_YELLOW);
    }
    prevX_TFT = posX;
  } else {
    // Si la bola ya pasó a la LCD, asegurar que la TFT quede limpia
    if (prevX_TFT != -100) {
      tft.fillCircle(prevX_TFT, yTFT, radioTFT, ST77XX_BLACK);
      prevX_TFT = -100;
    }
  }

  // --- FASE 2: DENTRO DE LA PANTALLA LCD 20x4 (X: 321 a 520) ---
  if (posX > limiteTFT && posX < limiteTotal) {
    // Mapear el rango [320, 520] a las columnas [0, 19] de la LCD
    int col = map(posX, limiteTFT, limiteTotal, 0, 20);

    if (col != prevCol_LCD && col >= 0 && col < 20) {
      // Borrar columna anterior en la fila 1 de la LCD
      if (prevCol_LCD >= 0 && prevCol_LCD < 20) {
        lcd.setCursor(prevCol_LCD, 1);
        lcd.print(" ");
      }
      // Dibujar bola personalizada
      lcd.setCursor(col, 1);
      lcd.write(0);
      prevCol_LCD = col;
    }
  } else {
    // Si la bola está en la TFT, asegurar que la LCD esté limpia
    if (prevCol_LCD != -1) {
      lcd.setCursor(prevCol_LCD, 1);
      lcd.print(" ");
      prevCol_LCD = -1;
    }
  }

  // --- CONTROL DE MOVIMIENTO Y REBOTE ---
  posX += (dir * 8); // Velocidad de avance

  // Rebote en el extremo derecho de la LCD
  if (posX >= limiteTotal) {
    dir = -1;
  }
  // Rebote en el extremo izquierdo de la TFT
  if (posX <= -radioTFT) {
    dir = 1;
  }

  delay(25); // Control de fluidez/FPS
}
