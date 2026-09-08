//esta parte es OBLIGATORIA en todas las estructuras con Adafruit, 
//ya que son las librerias.
//de aquí:
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // tamaño original de la pantalla actual
                        // nos dimos cuenta de que con los 32 se cortaba el texto
                        // y se veía todo más grande
                        // era por el tamaño de la altura de la pantalla... estaba mal definido

                        // usaremos toda la pantalla  
                       // al final era solo yo el que no quería el amarillo
                       // a mis compañeros les gustaba
                       // todos contra mi
                       // para pensar....
                       

#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

//hasta aquí. 

const int tasa = 9600;
const int potePatita = A0;
int poteLectura = -1;
int poteFiltrado = -1;

// --- Push button para encender/apagar la pantalla (toggle) ---
// Ahora usamos una resistencia física de pull-down (no el pull-up interno):
// en reposo el pin lee LOW, y al presionar el botón lee HIGH.
const int botonPin = 2; // pin digital donde se conecta el botón
bool pantallaEncendida = false; // arranca apagada

int estadoBotonEstable = LOW;    // último estado "confirmado" del botón (LOW = no presionado)
int estadoBotonAnterior = LOW;   // última lectura cruda, para detectar cambios
unsigned long ultimoCambioBoton = 0; // instante (millis) del último cambio detectado
const unsigned long debounceDelay = 50; // ms que debe mantenerse estable una lectura para validarla

const char poem1[] = 
"No somos poetas\n"
"con titulo,\n"
"pero las palabras\n"
"plasmadas aqui,\n"
"crecieron\n"
"de nuestro ser,\n"
"como las flores\n"
"en primavera.\n"
"La primavera\n"
"de Santiago de Chile.\n"
"Que coincidencia!\n"
"estamos en primavera\n"
"\n"
"Bienvenide\n"
"\n"
"Con amor:\n"
"Francisca\n"
"Nicolas\n"
"y Santiago";

int totalLines = 33; //no son las lineas de este código,
int lineHeight = 8;  //sino que son la cantidad de líneas que se muestran en la pantalla (contando los \n)
int totalTextHeight;
int maxScroll;

const int visibleLines = 2; // cantidad de líneas completas que queremos ver a la vez
// offsetY centra ese bloque de "visibleLines" líneas dentro del alto total de la pantalla (64 px)
const int offsetY = (SCREEN_HEIGHT - (visibleLines * 8)) / 2; // 8 = alto de la fuente en textSize(1)

//setup() — se ejecuta una sola vez al encender
void setup() {

  Serial.begin(tasa);  //inicialización de la pantalla

  // hola lo siguiente comentado no está haciendo nada ayuda chavales

  // while (!Serial) {}
  // Serial.println("Elvira Sastre"); // se muestra luego de la ilustración del cactus
  // delay(2000);   // Wait for display para prenderse

//Esta parte igual, es obligatoria por el bien de la sociedad.
//Esta parte es por si a la pantalla no le llega la suficiente energía y hay un error, 
//ella pueda procesarlo y resistir, y nosotres actuar.
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  display.setTextColor(SSD1306_WHITE);

  totalTextHeight = totalLines * lineHeight;
  maxScroll = totalTextHeight - SCREEN_HEIGHT;
  if (maxScroll < 0) maxScroll = 0;

  pinMode(botonPin, INPUT); // ya no usamos el pull-up interno: el estado en reposo (LOW)
                             // lo define la resistencia física de pull-down hacia GND

  display.clearDisplay();
  display.display();
  display.ssd1306_command(SSD1306_DISPLAYOFF); // apaga físicamente el panel OLED
                                                // se queda así hasta la primera pulsación del botón
}
//La animación de bienvenida (testdrawstyles + invertDisplay) ahora se dispara
//desde loop(), cada vez que se detecta una pulsación que enciende la pantalla
//(el botón funciona como interruptor: una pulsación enciende, la siguiente apaga).



    // queremos mostrar líneas de texto más largas
    // ya que queremos mostrar una estrofa de un poema mediante la pantalla
    // por lo que para lograr esto
    // integraremos un potenciómetro
    // para poder avanzar o retroceder en el texto
    // así podremos leer una línea completa sin que esta se corte por la pantalla

    // para conectar el potenciómetro a nuestro Arduino UNO R4 WiFi
    // conectamos lo siguiente
    // pin 1 de potenciómetro a 5V del Arduino
    // pin 2 del potenciómetro a un pin Analog del Arduino
    // en nuestro caso fue al pin A0
    // pin 3 del potenciómetro a GND del Arduino

    // para conectar el push button a nuestro Arduino UNO R4 WiFi (con resistencia física de pull-down):
    // pata A del botón -> 5V del Arduino
    // pata B del botón (diagonal a la A) -> se conecta a DOS cosas a la vez:
    //     1) al pin digital 2 del Arduino
    //     2) a una resistencia de 10kΩ, cuyo otro extremo va a GND del Arduino
    // así, sin presionar el botón, la resistencia "tira" el pin 2 hacia GND (lee LOW),
    // y al presionar el botón, el pin 2 queda conectado directo a 5V (lee HIGH)
    // el botón funciona como interruptor: una pulsación enciende la pantalla,
    // la siguiente pulsación la apaga, y así sucesivamente

  void loop() {

    // --- Lectura del botón con debounce (por flanco, no por nivel) ---
    // Esto detecta el instante exacto en que se pasa de "no presionado" a "presionado",
    // así una sola pulsación = un solo toggle, sin importar cuánto tiempo se mantenga apretado.
    int lecturaBoton = digitalRead(botonPin);

    if (lecturaBoton != estadoBotonAnterior) {
      ultimoCambioBoton = millis(); // la lectura cambió: reiniciamos el conteo de debounce
    }

    if ((millis() - ultimoCambioBoton) > debounceDelay) {
      // la lectura lleva "debounceDelay" ms estable: la damos por válida
      if (lecturaBoton != estadoBotonEstable) {
        estadoBotonEstable = lecturaBoton;

        if (estadoBotonEstable == HIGH) { // flanco de subida = botón recién presionado
          pantallaEncendida = !pantallaEncendida; // toggle: enciende si estaba apagada, y viceversa

          if (pantallaEncendida) {
            display.ssd1306_command(SSD1306_DISPLAYON); // encendemos físicamente el panel

            } else {
            display.ssd1306_command(SSD1306_DISPLAYOFF); // apagamos físicamente el panel
          }
        }
      }
    }
    estadoBotonAnterior = lecturaBoton;

    if (!pantallaEncendida) {
      return; // mientras esté apagada, no leemos potenciómetro ni dibujamos nada
    }

    // leer y filtrar
  poteLectura = analogRead(potePatita);
  poteFiltrado = filtrarConDivision(poteLectura, 4); // 0–255 approx

  // convertir el valor filtrado en posición de scroll
  int scrollY = map(poteFiltrado, 0, 255, 0, maxScroll);

  // redondeamos scrollY al múltiplo de lineHeight más cercano
  // así el scroll avanza línea por línea completa, sin cortar ninguna a la mitad
  scrollY = (scrollY / lineHeight) * lineHeight;

  // dibujar el poema desplazado
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, offsetY - scrollY); // offsetY centra el bloque de 2 líneas en la pantalla,
                                            // y scrollY lo desplaza línea por línea
  display.print(poem1);

  // ENMASCARAR: pintamos de negro todo lo que quede fuera de la ventana central
  // de "visibleLines" líneas. Esto es lo que garantiza que SIEMPRE se vean
  // exactamente 2 líneas, sin importar cuánto se mueva el potenciómetro.
  int windowHeight = visibleLines * lineHeight; // alto de la ventana visible (16 px)
  display.fillRect(0, 0, SCREEN_WIDTH, offsetY, SSD1306_BLACK); // tapa la franja superior
  display.fillRect(0, offsetY + windowHeight, SCREEN_WIDTH,
                    SCREEN_HEIGHT - (offsetY + windowHeight), SSD1306_BLACK); // tapa la franja inferior

  display.display();

  Serial.print("valor filtrado: ");
  Serial.println(poteFiltrado);

  delay(100); // delay de lo que se muestra en el monitor serial (valores potenciómetro)
              // también afecta en la velocidad a la que reacciona el potenciómetro
              // con como se muestra el desplazamiento en la pantalla
              // mientras más delay, más tarda en reaccionar la pantalla al movimiento del potenciómetro
              // menos delay, más rápido reacciona
  }

    int filtrarConDivision(int valor, int divisor) {
  int resultado = valor / divisor;
  return resultado;
}