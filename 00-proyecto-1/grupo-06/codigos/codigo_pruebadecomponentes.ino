/* ============================================================
   SKETCH DE PRUEBA - Verificación de conexiones
   Pantalla OLED SSD1306 (128x32, I2C), potenciómetro B20K,
   botón. Úsalo antes de subir el código final del poema.
   ============================================================ */

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const int PIN_BOTON = 2;
const int PIN_POTENCIOMETRO = A0;

// contador de pulsaciones válidas del botón, para confirmar que
// cada clic físico se registra como UNA sola pulsación (debounce ok)
int contadorPulsaciones = 0;

bool estadoBotonActual = HIGH;
bool estadoBotonAnterior = HIGH;
unsigned long ultimoCambioBoton = 0;
const unsigned long TIEMPO_DEBOUNCE = 50;

// ---------------- PROTOTIPOS ----------------
bool debounceBoton();
void mostrarLecturas(int valorPot, int pagina, bool botonPresionado);

void setup() {
  Serial.begin(9600);
  pinMode(PIN_BOTON, INPUT_PULLUP);
  pinMode(PIN_POTENCIOMETRO, INPUT);

  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("ERROR: no se detecta la pantalla OLED (revisa SDA/SCL/VCC/GND)"));
    for (;;); // se detiene aquí si la pantalla falla, para que sea obvio
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("Pantalla OK");
  display.println("Prueba iniciada...");
  display.display();
  Serial.println("Pantalla inicializada correctamente.");
  delay(1500);
}

void loop() {
  int valorPot = analogRead(PIN_POTENCIOMETRO);
  int pagina = constrain(valorPot / 256, 0, 3);
  bool botonPresionado = debounceBoton();

  if (botonPresionado) {
    contadorPulsaciones++;
    Serial.print("Boton presionado. Total pulsaciones: ");
    Serial.println(contadorPulsaciones);
  }

  mostrarLecturas(valorPot, pagina, botonPresionado);

  Serial.print("Pot: ");
  Serial.print(valorPot);
  Serial.print("  Pagina: ");
  Serial.println(pagina);

  delay(100);
}

bool debounceBoton() {
  bool lectura = digitalRead(PIN_BOTON);
  bool pulsacionDetectada = false;

  if (lectura != estadoBotonAnterior) {
    ultimoCambioBoton = millis();
  }

  if ((millis() - ultimoCambioBoton) > TIEMPO_DEBOUNCE) {
    if (lectura != estadoBotonActual) {
      estadoBotonActual = lectura;
      if (estadoBotonActual == LOW) {
        pulsacionDetectada = true;
      }
    }
  }

  estadoBotonAnterior = lectura;
  return pulsacionDetectada;
}

void mostrarLecturas(int valorPot, int pagina, bool botonPresionado) {
  display.clearDisplay();

  display.setCursor(0, 0);
  display.print("Pot: ");
  display.print(valorPot);
  display.print("  Pag: ");
  display.print(pagina);

  display.setCursor(0, 12);
  display.print("Clics boton: ");
  display.print(contadorPulsaciones);

  display.setCursor(0, 24);
  display.print(digitalRead(PIN_BOTON) == LOW ? "BOTON PRESIONADO" : "boton suelto");

  display.display();
}