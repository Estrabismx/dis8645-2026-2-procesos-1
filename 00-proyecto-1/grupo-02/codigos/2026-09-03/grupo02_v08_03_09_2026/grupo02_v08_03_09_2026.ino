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

// push button para prender y apagar la pantalla
// usamos una resistencia física de pull-down
// en reposo el pin lee LOW, y al presionar el botón lee HIGH.
const int botonPin = 2; // pin digital donde se conecta el botón (2)
bool pantallaEncendida = false; // la pantalla parte apagada

int estadoBotonEstable = LOW;    // último estado del botón (LOW = no presionado)
int estadoBotonAnterior = LOW;   // última lectura cruda, para detectar cambios
unsigned long ultimoCambioBoton = 0; // instante (millis) del último cambio detectado
const unsigned long debounceDelay = 50; // ms que debe mantenerse estable una lectura para validarla

// el LDR muestra otro texto cuando le llega luz directa
const int ldrPin = A1; // pin analógico donde se conecta el LDR
int ldrLectura = -1;
// umbral a partir del cual consideramos que "hay luz"
// (LDR entre 5V y A1, resistencia de 1kΩ entre A1 y GND)
// mientras más luz = valor más alto
// este número lo podemos cambiar dependiendo de la luz
// que haya en el ambiente que presentemos
const int umbralLuz = 200; // rango 0–1023, como mencionamos arriba
                          // este se puede cambiar dependiendo de la luz
                          // del lugar en donde estemos
                          // en la biblioteca Nicanor Parra a las 17:45
                          // funciona en 200 el umbral

const char poemaLuz[] =
"Que pasa\n"
"cuando la luz del sol\n"
"aparece detras\n"
"de la cordillera?\n"
"\n"
"En Chile,\n"
"los Romeros florecen\n"
"\n"
"En Chile,\n"
"el cielo es rosado,\n"
"y cuando te ofrecen\n"
"un pedacito,\n"
"significa\n"
"que es grandecito\n"
"\n"
"En Chile,\n"
"los Andes\n"
"visten de novia\n"
"en las noches,\n"
"y se desvisten\n"
"revelandose de dia\n"
"\n"
"Pero..\n"
"En Chile,\n"
"los chirihues\n"
"dan conciertos,\n"
"y las libelulas\n"
"danzan\n"
"\n"
"Mientras el sol\n"
"siga saliendo detras\n"
"de la cordillera,\n"
"y se pose\n"
"sobre tu cabeza\n"
"es un dia mas\n"
"para sentirlo\n"
"\n"
"En Chile,\n"
"el Zorro culpeo\n"
"no tiene la culpa\n"
"En Chile,\n"
"el Romero florece\n"
"Pero ya en tu pecho\n"
"floreceran colores\n"
"de amor\n"
"\n"
"Floreceran...";

int totalLinesLuz = 73; // cantidad de líneas de Luz (contando los \n)
                        // al igual que los espacios que hay dentro
                        // de los rectángulos negros en la pantalla
                        // (los que nos permiten mostrar solo dos líneas de texto)
                        // (solo lo hacemos para hacernos los misteriosos)
int totalTextHeightLuz;
int maxScrollLuz;

const char poema1[] = 
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

  totalTextHeightLuz = totalLinesLuz * lineHeight;
  maxScrollLuz = totalTextHeightLuz - SCREEN_HEIGHT;
  if (maxScrollLuz < 0) maxScrollLuz = 0;

  display.clearDisplay();
  display.display();
  display.ssd1306_command(SSD1306_DISPLAYOFF); // apaga físicamente el panel OLED
                                                // se queda así hasta la primera pulsación del botón
}

    // queremos mostrar líneas de texto más largas
    // ya que queremos mostrar un poema mediante la pantalla
    // por lo que para lograr esto
    // integraremos un potenciómetro
    // para poder avanzar o retroceder en el texto
    // así podremos leer todo completo sin que esta se corte por la pantalla

    // para conectar el potenciómetro a nuestro Arduino UNO R4 WiFi
    // pin 1 de potenciómetro a 5V del Arduino
    // pin 2 del potenciómetro a un pin Analog del Arduino
    // en nuestro caso fue al pin A0
    // pin 3 del potenciómetro a GND del Arduino

    // para conectar el push button a nuestro Arduino UNO R4 WiFi
    // pata A del botón -> 5V del Arduino
    // pata B del botón (diagonal a la A) -> se conecta a DOS cosas a la vez:
    //     1) al pin digital 2 del Arduino
    //     2) a una resistencia de 10kΩ, cuyo otro extremo va a GND del Arduino
    // así, sin presionar el botón, la resistencia "tira" el pin 2 hacia GND (lee LOW),
    // y al presionar el botón, el pin 2 queda conectado directo a 5V (lee HIGH)
    // el botón funciona como interruptor: una pulsación enciende la pantalla,
    // la siguiente pulsación la apaga, y así sucesivamente

    // para conectar el LDR a nuestro Arduino UNO R4 WiFi (divisor de voltaje):
    // pata 1 del LDR -> 5V del Arduino
    // pata 2 del LDR -> se conecta a DOS cosas a la vez:
    //     1) al pin analógico A1 del Arduino
    //     2) a una resistencia de 10kΩ, cuyo otro extremo va a GND del Arduino
    // con luz directa sobre el LDR, su resistencia baja y el voltaje en A1 sube
    // (se acerca a 5V) -> analogRead(A1) da un valor alto -> se muestra el texto alternativo
    // sin luz, el LDR tiene mucha resistencia, el voltaje en A1 es bajo (cercano a GND)
    // -> analogRead(A1) da un valor bajo -> se muestra el poema normal

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

    // --- Lectura del LDR ---
    ldrLectura = analogRead(ldrPin);
    bool hayLuz = ldrLectura > umbralLuz;

    // leer y filtrar el potenciómetro (se usa para el scroll, en ambos modos)
    poteLectura = analogRead(potePatita);
    poteFiltrado = filtrarConDivision(poteLectura, 4); // 0–255 approx

    display.clearDisplay();
    display.setTextSize(1);

    if (hayLuz) {
      // MODO LDR: mientras haya luz directa sobre el sensor, mostramos el texto
      // alternativo, con el mismo scroll/centrado/enmascarado que el poema.
      mostrarTextoConScroll(poemaLuz, maxScrollLuz);

      Serial.print("LDR: ");
      Serial.print(ldrLectura);
      Serial.println(" -> hay luz, mostrando texto alternativo");
    } else {
      // MODO NORMAL (sin luz sobre el LDR): el poema con scroll, como antes
      mostrarTextoConScroll(poema1, maxScroll);

      Serial.print("valor filtrado: ");
      Serial.println(poteFiltrado);
    }

    display.display();

  delay(100); // delay de lo que se muestra en el monitor serial (valores potenciómetro)
              // también afecta en la velocidad a la que reacciona el potenciómetro
              // con como se muestra el desplazamiento en la pantalla
              // mientras más delay, más tarda en reaccionar la pantalla al movimiento del potenciómetro
              // menos delay, más rápido reacciona
  }

  // Función reutilizable: aplica scroll (según el potenciómetro), centra el bloque
  // de "visibleLines" líneas en la pantalla, y tapa (enmascara) todo lo que quede
  // fuera de esa ventana central. Se usa tanto para el poema como para poemaLuz.
  void mostrarTextoConScroll(const char* texto, int maxScrollTexto) {
    // convertir el valor filtrado en posición de scroll
    int scrollY = map(poteFiltrado, 0, 255, 0, maxScrollTexto);

    // redondeamos scrollY al múltiplo de lineHeight más cercano
    // así el scroll avanza línea por línea completa, sin cortar ninguna a la mitad
    scrollY = (scrollY / lineHeight) * lineHeight;

    // dibujar el texto desplazado
    display.setCursor(0, offsetY - scrollY); // offsetY centra el bloque de "visibleLines" líneas,
                                              // y scrollY lo desplaza línea por línea
    display.print(texto);

    // ENMASCARAR: pintamos de negro todo lo que quede fuera de la ventana central.
    // Esto es lo que garantiza que SIEMPRE se vean exactamente "visibleLines" líneas,
    // sin importar cuánto se mueva el potenciómetro.
    int windowHeight = visibleLines * lineHeight; // alto de la ventana visible (16 px)
    display.fillRect(0, 0, SCREEN_WIDTH, offsetY, SSD1306_BLACK); // tapa la franja superior
    display.fillRect(0, offsetY + windowHeight, SCREEN_WIDTH,
                      SCREEN_HEIGHT - (offsetY + windowHeight), SSD1306_BLACK); // tapa la franja inferior
  }


    int filtrarConDivision(int valor, int divisor) {
  int resultado = valor / divisor;
  return resultado;
}