//esta parte es OBLIGATORIA en todas las estructuras con Adafruit, 
//ya que son las bibliotecas.
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
// en reposo el pin lee LOW, y al presionar el botón lee HIGH
const int botonPin = 2; // pin digital del Arduino R4 WiFi   donde se conecta el botón (2)
bool pantallaEncendida = false; // la pantalla parte apagada

int estadoBotonEstable = LOW;    // último estado del botón (LOW = no presionado)
int estadoBotonAnterior = LOW;   // última lectura cruda, para detectar cambios
unsigned long ultimoCambioBoton = 0; // instante (millis) del último cambio detectado
const unsigned long debounceDelay = 50; // ms que debe mantenerse estable una lectura para validarla

// con el segundo potenciómetro se elige el texto que se muestra (poema1 o poemaLuz)
// dependiendo de el lugar en el que se encuentre la perilla del segundo potenciómetro
// (antes de la mitad, o después de la mitad)
// (la mitad siendo 512)
const int potePatita2 = A1; // pin analógico donde se conecta el segundo potenciómetro
int pote2Lectura = -1;

// umbral que separa las dos mitades del potenciómetro
// por debajo de este valor se muestra poema1, por encima se muestra poemaLuz
const int umbralPote2 = 100; // rango 0–1023, 512 es el punto medio
                            // usaremos 100 porque queremos que el texto alternativo (poemaLuz)
                            // se vea cuando hay poca "luz" en el ambiente

// LED que vamos a manejar su intensidad mediante un potenciómetro
// más específico, pote2
// el mismo que muestra poemaLuz
int LED_PIN = 3; // pin del Arduino R4 WiFi

// el LDR ahora controla el AVANCE del scroll de poemaLuz (no solo animaciones):
// con luz directa, el texto avanza solo; sin luz, se congela donde esté.
// esto solo aplica una vez que poemaLuz ya está activo (ver poemaLuzActivado);
// si estamos en poema1, el LDR no hace nada.
const int ldrPin = A2; // pin analógico donde se conecta el LDR (divisor de voltaje)
int ldrLectura = -1;
const int umbralLuzLDR = 100; // rango 0–1023, esto se puede cambiar dependiendo del ambiente en el que estemos
                              // hoy, dentro de LID a las 11:46 AM funciona con el umbral a 100

// una vez que poemaLuz se activa (LED bajo), queda "enganchado": aunque
// después el LED suba de intensidad, ya no se vuelve a mostrar poema1.
// Se reinicia cuando se apaga la pantalla con el botón.
bool poemaLuzActivado = false;

// el LDR ahora funciona como el "motor de avance" de poemaLuz:
// mientras reciba luz directa, el scroll avanza solo (línea por línea);
// sin luz, se queda quieto en la línea donde estaba.
int scrollYLuz = 0; // posición de scroll de poemaLuz (ya NO depende del potenciómetro 1)
unsigned long ultimoAvanceLuz = 0;
const unsigned long intervaloAvanceLuz = 600; // ms de luz sostenida antes de avanzar una línea

// para detectar cuánto tiempo lleva quieta la línea actual de poemaLuz
int lineaAnteriorLuz = -1;
unsigned long inicioLineaActualLuz = 0;
const unsigned long tiempoQuietoAnimacion = 100; // ms que debe estar quieta la línea para animar

// líneas (contando los \n del poemaLuz) que disparan cada animación,
// cuando el scroll (avanzado por el LDR) se queda quieto en ellas
// por al menos "tiempoQuietoAnimacion" ms
const int lineaTrasRomeros = 7;      // justo después de "los Romeros florecen"
const int lineaTrasColibries = 10;   // justo después de "los Colibries cantan"
const int lineaTrasGrandecito = 17;  // justo después de "que es grandecito"
const int lineaTrasRevelandose = 24; // justo después de "revelandose de dia"

// margen de líneas: como el scroll con el LDR solo avanza (nunca retrocede),
// exigir la línea EXACTA hace casi imposible topar la animación si te pasas
// aunque sea una línea. Con este margen, cualquier línea cercana al objetivo
// también cuenta. OJO: con tolLinea > 1 los rangos de Romeros (7) y Colibries
// (10) se superponen (están a solo 3 líneas de distancia), así que lo dejamos en 1.
const int tolLinea = 0;


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
"los Colibries cantan\n"
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
"las Chinchineras\n"
"saltan\n"
"y las Turcas\n"
"cabriolean\n"
"En Chile,\n"
"el Zorro culpeo\n"
"no tiene la culpa\n"
"En Chile,\n"
"el Romero florece\n"
"Pero tambien,\n"
"ya en tu pecho\n"
"floreceran\n"
"colores de amor\n"
"\n"
"Floreceran...";

int totalLinesLuz = 86; // cantidad de líneas de poemaLuz (contando los \n)
                        // al igual que los espacios que hay dentro
                        // de los rectángulos negros en la pantalla
                        // (los que nos permiten mostrar solo dos líneas de texto)
                        // (solo lo hacemos para hacernos los misteriosos)
int totalTextHeightLuz;
int maxScrollLuz;

const char poema1[] = 
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
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

int totalLines = 32; //no son las lineas de este código,
int lineHeight = 8;  //sino que son la cantidad de líneas que se muestran en la pantalla (contando los \n)
int totalTextHeight;
int maxScroll;

const int visibleLines = 2; // cantidad de líneas completas que queremos ver en la pantalla

// offsetY centra el bloque de líneas visibles
// dentro del alto total de la pantalla (64 px)
const int offsetY = (SCREEN_HEIGHT - (visibleLines * 8)) / 2; // 8 = alto de la fuente en textSize(1)

// el setup sucede solo una sola vez al encender
void setup() {

  Serial.begin(tasa);  // parte la pantalla

  pinMode(LED_PIN, OUTPUT); // hola declaro el pin para el LED para que sea un output


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

  display.clearDisplay();
  display.display();
  display.ssd1306_command(SSD1306_DISPLAYOFF); // apaga físicamente el panel OLED
                                                // se queda así hasta la primera presión del botón
}

    // queremos mostrar líneas de texto más largas
    // ya que queremos mostrar un poema mediante la pantalla
    // por lo que para lograr esto
    // integraremos un potenciómetro
    // para poder avanzar o retroceder en el texto
    // así podremos leer todo completo sin que esta se corte por la pantalla

    // para conectar el potenciómetro 1 a nuestro Arduino UNO R4 WiFi
    // pin 1 de potenciómetro a 3.3V del Arduino
    // pin 2 del potenciómetro a un pin Analog del Arduino
    // en nuestro caso fue al pin A0
    // pin 3 del potenciómetro a GND del Arduino

    // para conectar el push button a nuestro Arduino UNO R4 WiFi
    // las conexiones del botón se hacen en diagonal
    // patita 1 del botón a 3.3V del Arduino
    // patita B del botón (la que está diagonal a la A) se conecta a dos cosas
    // una de ellas es el pin digital 2 del Arduino
    // mientras que la otra va a una resistencia de 1kΩ
    // la otra patita de la resistencia va a GND del Arduino

    // el segundo potenciómetro se conecta de la siguiente manera
    // pin 1 del potenciómetro a 3.3V del Arduino
    // pin 2 del potenciómetro al pin analógico A1 del Arduino
    // pin 3 del potenciómetro va a GND del Arduino

    // para conectar el LED a nuestro Arduino
    // el pin digital 3 del Arduino va a una patita de una resistencia de 1k
    // la otra patita de esta resistencia va a la patita positiva de nuestro LED
    // la patita negativa del LED va a GND del Arduino

    // para conectar el LDR a nuestro Arduino
    // patita 1 del LDR va a 3.3V del Arduino
    // pata 2 del LDR se conecta a dos cositas:
    // una de ellas es el pin analógico A2 del Arduino
    // mientras que la otra va a una patita de una resistencia de 1kΩ
    // la otra patita de la resistencia va a GND del Arduino

  void loop() {

    // aquí sucede la lectura del botón con debounce
    // cosa que nos ayuda a detectar de inmediato cuando fue presionado el botón
    // pasa de "hola aún no me presionan" a "omg me presionaron"  
    int lecturaBoton = digitalRead(botonPin);

    // el segundo potenciómetro también controla al LED
    // este lo controla siempre, sin importar si la pantalla está prendida o no
    // ya que el LED es independiente, su presencia no depende de la pantalla
    pote2Lectura = analogRead(potePatita2);
    int brightness = map(pote2Lectura, 0, 1023, 0, 255);
    analogWrite(LED_PIN, brightness);

    Serial.print("Pote 2: ");
    Serial.print(pote2Lectura);
    Serial.print(", Brightness: ");
    Serial.println(brightness);

    if (lecturaBoton != estadoBotonAnterior) {
      ultimoCambioBoton = millis(); // al cambiar la lectura, se reinicia el rebounce
    }

    if ((millis() - ultimoCambioBoton) > debounceDelay) {

      if (lecturaBoton != estadoBotonEstable) {
        estadoBotonEstable = lecturaBoton;

        if (estadoBotonEstable == HIGH) { // high si el botón fue presionado
          pantallaEncendida = !pantallaEncendida; // el toggle prende si es que estaba apagada
                                                  // y apaga si estaba prendida

          if (pantallaEncendida) {
            display.ssd1306_command(SSD1306_DISPLAYON); // prendemos la pantalla

            } else {
            display.ssd1306_command(SSD1306_DISPLAYOFF); // apagamos la pantalla
            poemaLuzActivado = false; // se reinicia, la próxima vez hay que
                                       // volver a bajar la intensidad del LED para ver poemaLuz
            scrollYLuz = 0; // y el scroll de poemaLuz vuelve al principio
          }
        }
      }
    }
    estadoBotonAnterior = lecturaBoton;

    if (!pantallaEncendida) {
      return; // mientras esté apagada, no leemos el potenciómetro ni aparece nada en ella
    }

    // cuando no hay suficiente luz, poemaLuz queda quieto
    // este no vuelve a poema1 aunque el LED suba de intensidad después
    // desde ese momento, pote2 solo controla el brillo del LED (arriba),
    // sin afectar nada de lo que pasa en la pantalla
    if (!poemaLuzActivado && pote2Lectura < umbralPote2) {
      poemaLuzActivado = true;
    }
    bool mostrarPoemaLuz = poemaLuzActivado;

    // lee y filtra el primer potenciómetro (es para scroll de poema1)
    poteLectura = analogRead(potePatita);
    poteFiltrado = filtrarConDivision(poteLectura, 4); // 0–255 approx

    // lectura del LDR
    // solo importa cuando se está mostrando poemaLuz
    ldrLectura = analogRead(ldrPin);
    bool hayLuzLDR = ldrLectura > umbralLuzLDR;

    display.clearDisplay();
    display.setTextSize(1);

    if (mostrarPoemaLuz) {
      // el LDR avanza el scroll de poemaLuz mientras reciba luz directa
      if (hayLuzLDR) {
        if (millis() - ultimoAvanceLuz >= intervaloAvanceLuz) {
          scrollYLuz += lineHeight;
          if (scrollYLuz > maxScrollLuz) scrollYLuz = maxScrollLuz;
          ultimoAvanceLuz = millis();
        }
      } else {
        // sin luz no avanza, y reiniciamos el temporizador para que no
        // se salte varias líneas cuando le llegue la luz de vuelta
        ultimoAvanceLuz = millis();
      }

      int lineaActualLuz = scrollYLuz / lineHeight;

      // si la línea actual cambió, reiniciamos el conteo
      // de la pantalla estando quieta en una misma línea
      if (lineaActualLuz != lineaAnteriorLuz) {
        lineaAnteriorLuz = lineaActualLuz;
        inicioLineaActualLuz = millis();
      }

      bool quietaSuficiente = (millis() - inicioLineaActualLuz) >= tiempoQuietoAnimacion;

      if (quietaSuficiente && cercaDe(lineaActualLuz, lineaTrasRomeros)) {
        mostrarAnimacion1();
        Serial.println("4+ seg quieto después de Romeros -> animación 1");
      } else if (quietaSuficiente && cercaDe(lineaActualLuz, lineaTrasColibries)) {
        mostrarAnimacion2();
        Serial.println("4+ seg quieto después de Colibries -> animación 2");
      } else if (quietaSuficiente && cercaDe(lineaActualLuz, lineaTrasGrandecito)) {
        mostrarAnimacion3();
        Serial.println("4+ seg quieto después de grandecito -> animación 3");
      } else if (quietaSuficiente && cercaDe(lineaActualLuz, lineaTrasRevelandose)) {
        mostrarAnimacion4();
        Serial.println("4+ seg quieto después de revelandose de dia -> animación 4");
      } else {
        // mostramos poemaLuz en la línea actual (fija si no hay luz,
        // avanzando si hay luz), con el mismo centrado y enmascarado de siempre
        dibujarTextoEnScroll(poemaLuz, scrollYLuz);

        Serial.print("poemaLuz, linea actual: ");
        Serial.println(lineaActualLuz);
      }
    } else {

      // con poemaLuz aún no activado, mostramos el poema principal
      mostrarTextoConScroll(poema1, maxScroll);

      Serial.print("valor filtrado: ");
      Serial.println(poteFiltrado);
    }

    display.display();

  delay(200); // delay de lo que se muestra en el monitor serial (valores potenciómetro)
              // también afecta en la velocidad a la que reacciona el potenciómetro
              // con como se muestra el desplazamiento en la pantalla
              // mientras más delay, más tarda en reaccionar la pantalla al movimiento del potenciómetro
              // menos delay, más rápido reacciona
  }

  // esto aplica scroll según el potenciómetro 1 (se usa solo para poema1),
  // centra el bloque de líneas visibles en la pantalla, y tapa todo lo que
  // quede fuera de esa ventana central
  void mostrarTextoConScroll(const char* texto, int maxScrollTexto) {
    // convertir el valor filtrado en posición de scroll

    int scrollY = map(poteFiltrado, 0, 255, maxScrollTexto, 0);

    // redondeamos scrollY al múltiplo de lineHeight más cercano (aquí es 8)
    // así el scroll avanza línea por línea completa, sin cortar ninguna a la mitad
    scrollY = (scrollY / lineHeight) * lineHeight;

    dibujarTextoEnScroll(texto, scrollY);
  }

  // dibuja texto con un scrollY que ya está calculado
  // no lo controla ningún potenciómetro
  // centra el bloque de líneas visibles y tapa lo que quede
  // fuera de esa ventana
  void dibujarTextoEnScroll(const char* texto, int scrollY) {
    display.setCursor(0, offsetY - scrollY); // offsetY centra el bloque de líneas visibles,
                                              // y scrollY lo desplaza línea por línea
    display.print(texto);

    // pintamos de negro todo lo que quede fuera de la ventana central
    // esto es lo que asegura que siempre se vean exactamente líneas visibles,
    // sin importar cuánto se mueva el scroll
    int windowHeight = visibleLines * lineHeight; // alto de la ventana visible (16 px)
    display.fillRect(0, 0, SCREEN_WIDTH, offsetY, SSD1306_BLACK); // tapa la franja superior
    display.fillRect(0, offsetY + windowHeight, SCREEN_WIDTH,
                      SCREEN_HEIGHT - (offsetY + windowHeight), SSD1306_BLACK); // tapa la franja inferior
  }


    int filtrarConDivision(int valor, int divisor) {
  int resultado = valor / divisor;
  return resultado;
}

// revisa si una línea está cerca de
// una línea objetivo
bool cercaDe(int linea, int objetivo) {
  return abs(linea - objetivo) <= tolLinea;
}


// aquí van las animaciones
void mostrarAnimacion1() {
  static int radio = 0;
  static int direccion = 1;

  display.drawCircle(64, 32, radio, SSD1306_WHITE);

  radio += direccion * 2;
  if (radio >= 28 || radio <= 0) direccion *= -1;
}

// animación 2, colibríes
void mostrarAnimacion2() {
  static int x = 0;
  static int direccion = 4;

  display.fillTriangle(x, 32, x + 12, 24, x + 12, 40, SSD1306_WHITE);

  x += direccion;
  if (x >= SCREEN_WIDTH - 12 || x <= 0) direccion *= -1;
}

// animación 3, grandecito
void mostrarAnimacion3() {
  static int radio = 0;

  display.drawCircle(64, 32, radio % 30, SSD1306_WHITE);
  display.drawCircle(64, 32, (radio + 10) % 30, SSD1306_WHITE);
  display.drawCircle(64, 32, (radio + 20) % 30, SSD1306_WHITE);

  radio += 2;
}

// animación 4, revelándose de día
void mostrarAnimacion4() {
  static int y = SCREEN_HEIGHT;

  display.fillCircle(64, y, 10, SSD1306_WHITE);

  y -= 2;
  if (y < 0) y = SCREEN_HEIGHT;
}