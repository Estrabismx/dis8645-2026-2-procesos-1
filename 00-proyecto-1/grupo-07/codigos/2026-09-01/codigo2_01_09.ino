// ================================================================
// Poema "Queja" de Alfonsina Storni
// Sketch para mostrar el poema en pantalla OLED 0,91" I2C (128x32)
// usando Adafruit_GFX + Adafruit_SSD1306
// ================================================================

#include <Wire.h>              // Maneja la comunicación I2C entre el Arduino y la pantalla
#include <Adafruit_GFX.h>      // Librería base de gráficos (dibuja texto, líneas, formas)
#include <Adafruit_SSD1306.h>  // Librería específica para el chip controlador SSD1306 de la OLED
#include <string.h>            // Nos da funciones para manejar texto: strlen, strcpy, strncpy

// Definimos el tamaño de la pantalla en píxeles (ancho x alto)
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32

// -1 significa que la pantalla comparte el pin de reset con el Arduino
// (no usa un pin de reset propio)
#define OLED_RESET -1

// Dirección I2C típica de estos módulos OLED (si no funciona, probar 0x3D)
#define SCREEN_ADDRESS 0x3C

// Creamos el objeto "display" que representa nuestra pantalla física,
// indicando ancho, alto, el bus I2C a usar (&Wire) y el pin de reset
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Arreglo con los versos ORIGINALES (con tildes), que se usan
// para imprimir el poema completo y correcto en el Monitor Serie
char *misVersos[] = {
  "Señor, mi queja es ésta,",
  "Tú me comprenderás",
  "De amor me estoy muriendo,",
  "Pero no puedo amar.",
  "Persigo lo perfecto",
  "En mí y en los demás,",
  "Persigo lo perfecto",
  "Para poder amar.",
  "Me consumo en mi fuego,",
  "¡Señor, piedad, piedad!",
  "De amor me estoy muriendo,",
  "¡Pero no puedo amar!"
};

// Arreglo con los mismos versos SIN tildes ni signos especiales,
// porque la fuente por defecto de Adafruit_GFX no los dibuja bien
char *versosPantalla[] = {
  "Senor, mi queja es esta,",
  "Tu me comprenderas",
  "De amor me estoy muriendo,",
  "Pero no puedo amar.",
  "Persigo lo perfecto",
  "En mi y en los demas,",
  "Persigo lo perfecto",
  "Para poder amar.",
  "Me consumo en mi fuego,",
  "Senor, piedad, piedad!",
  "De amor me estoy muriendo,",
  "Pero no puedo amar!"
};

// Cantidad total de versos (para no tener que contarlos a mano en el for)
const int totalVersos = 12;

// setup() se ejecuta UNA sola vez, al encender o resetear la placa
void setup() {
  Serial.begin(9600); // Inicia la comunicación serial a 9600 baudios

  // Intenta inicializar la pantalla. SSD1306_SWITCHCAPVCC le dice que
  // genere su propio voltaje interno para el panel OLED
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("Error al iniciar la pantalla OLED")); // Si falla, avisa por Serial
    for (;;);   // Bucle infinito vacío: detiene el programa acá si la pantalla no arrancó
  }

  display.clearDisplay();       // Borra cualquier contenido inicial de la pantalla
  display.setTextSize(1);       // Tamaño de letra: 1 = el más chico (6x8 px por caracter aprox)
  display.setTextColor(SSD1306_WHITE); // Color del texto (en OLED monocromo, "blanco" = encendido)
}

// loop() se ejecuta UNA Y OTRA VEZ, sin parar
void loop() {
  // Recorremos ambos arreglos en paralelo usando el mismo índice i
  for (int i = 0; i < totalVersos; i++) {
    mostrarVerso(versosPantalla[i]); // Muestra en la OLED la versión sin tildes
    Serial.println(misVersos[i]);    // Imprime por Serial la versión completa con tildes
    delay(2500);                     // Espera 2.5 segundos antes del siguiente verso
  }
  // Al terminar el for (mostró los 12 versos), loop() arranca de nuevo desde el principio
}

// Función que recibe un verso y lo dibuja en pantalla,
// partiéndolo en dos líneas si no entra completo en el ancho disponible
void mostrarVerso(char *verso) {
  char linea1[35] = ""; // String vacío donde armamos la primera línea
  char linea2[35] = ""; // String vacío donde armamos la segunda línea (si hace falta)

  int len = strlen(verso); // Cantidad de caracteres del verso
  int maxChars = 21;       // Caracteres aprox. que entran en 128px con fuente tamaño 1

  if (len <= maxChars) {
    // Si el verso entra en una sola línea, lo copiamos completo a linea1
    strcpy(linea1, verso);
  } else {
    // Si es más largo, buscamos dónde cortarlo
    int corte = maxChars;

    // Retrocedemos desde el límite hasta encontrar un espacio,
    // para no cortar una palabra por la mitad
    while (corte > 0 && verso[corte] != ' ') corte--;

    // Si no hay ningún espacio antes del límite, cortamos igual ahí
    if (corte == 0) corte = maxChars;

    strncpy(linea1, verso, corte); // Copia los primeros "corte" caracteres a linea1
    linea1[corte] = '\0';          // Cierra el string (fin de cadena en C)

    strcpy(linea2, verso + corte + 1); // Copia el resto del verso (después del espacio) a linea2
  }

  display.clearDisplay();      // Borra lo que estaba dibujado antes
  display.setCursor(0, 0);     // Posiciona el cursor en x=0, y=0 (primera línea, arriba)
  display.println(linea1);     // Escribe la primera línea (println además baja el cursor)
  display.setCursor(0, 12);    // Mueve el cursor a x=0, y=12 (segunda línea, más abajo)
  display.println(linea2);     // Escribe la segunda línea (vacía si no hizo falta cortar)
  display.display();           // Envía todo el contenido al panel físico para que se vea
}