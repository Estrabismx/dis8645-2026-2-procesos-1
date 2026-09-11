// ================================================================
// Poema "Queja" de Alfonsina Storni
// Sketch para mostrar el poema en pantalla OLED 0,91" I2C (128x32)
// usando Adafruit_GFX + Adafruit_SSD1306
// - Palabras clave se muestran más grandes (efecto "grito")
// - La velocidad de cambio de verso se controla con un potenciómetro B10K
// - Placa: Arduino Uno R4 WiFi
// ================================================================

#include <Wire.h>              // Maneja la comunicación I2C entre el Arduino y la pantalla
#include <Adafruit_GFX.h>      // Librería base de gráficos (dibuja texto, líneas, formas)
#include <Adafruit_SSD1306.h>  // Librería específica para el chip controlador SSD1306 de la OLED
#include <string.h>            // Funciones para manejar texto: strlen, strcpy, strtok, strcmp
#include <ctype.h>             // Funciones para clasificar/transformar caracteres: isalpha, tolower

// Definimos el tamaño de la pantalla en píxeles (ancho x alto)
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32

// -1 significa que la pantalla comparte el pin de reset con el Arduino
#define OLED_RESET -1

// Dirección I2C típica de estos módulos OLED (si no funciona, probar 0x3D)
#define SCREEN_ADDRESS 0x3C

// Pin analógico donde conectamos el pin central (wiper) del potenciómetro B10K
#define POT_PIN A0

// Creamos el objeto "display" que representa nuestra pantalla física
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Arreglo con los versos ORIGINALES (con tildes), usados
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

// Por cada verso, indicamos qué palabra hay que agrandar.
// Si el string está vacío (""), ese verso se muestra todo en tamaño normal.
// Van en minúscula y sin signos, porque así las compara limpiarPalabra().
char *palabraGrande[] = {
  "queja",      // 0: Señor, mi queja es ésta,
  "",           // 1: Tú me comprenderás
  "muriendo",   // 2: De amor me estoy muriendo,
  "",           // 3: Pero no puedo amar.
  "persigo",    // 4: Persigo lo perfecto
  "",           // 5: En mí y en los demás,
  "perfecto",   // 6: Persigo lo perfecto
  "",           // 7: Para poder amar.
  "consumo",    // 8: Me consumo en mi fuego,
  "piedad",     // 9: ¡Señor, piedad, piedad!  (agranda las dos apariciones)
  "",           // 10: De amor me estoy muriendo,
  "amar"        // 11: ¡Pero no puedo amar!
};

// Cantidad total de versos
const int totalVersos = 12;

// Tiempo (en milisegundos) que se muestra cada verso.
// Arranca en 2500 como valor inicial, pero se recalcula todo el tiempo
// según la posición del potenciómetro.
int tiempoEspera = 2500;

// setup() se ejecuta UNA sola vez, al encender o resetear la placa
void setup() {
  Serial.begin(9600); // Inicia la comunicación serial a 9600 baudios

  // Intenta inicializar la pantalla
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("Error al iniciar la pantalla OLED"));
    for (;;); // Detiene el programa si la pantalla no arrancó
  }

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE); // Color del texto (blanco = encendido en OLED monocroma)
  // No fijamos un setTextSize único acá, porque cada palabra
  // puede usar tamaño 1 (normal) o 2 (agrandada/"gritada")
}

// loop() se ejecuta UNA Y OTRA VEZ, sin parar
void loop() {
  for (int i = 0; i < totalVersos; i++) {

    int valorPot = analogRead(POT_PIN);
    // Lee el voltaje en el pin A0 y lo traduce a un número entre 0 y 1023
    // (resolución de 10 bits, la que trae por defecto el Uno R4 WiFi)

    tiempoEspera = map(valorPot, 0, 1023, 4000, 200);
    // Traduce el rango del potenciómetro (0 a 1023) a un rango de milisegundos.
    // Pote al mínimo -> 4000ms (lento). Pote al máximo -> 200ms (rápido).
    // Si lo querés al revés, invertís el 4000 y el 200.

    mostrarVerso(versosPantalla[i], palabraGrande[i]); // Muestra en la OLED la versión sin tildes
    Serial.println(misVersos[i]);                      // Imprime por Serial la versión completa con tildes

    Serial.print("Tiempo de espera actual (ms): "); // Para monitorear el valor mientras se prueba
    Serial.println(tiempoEspera);

    delay(tiempoEspera); // Espera el tiempo calculado antes de pasar al siguiente verso
  }
  // Al terminar el for (mostró los 12 versos), loop() arranca de nuevo desde el principio
}

// Función auxiliar que limpia una palabra para poder compararla.
// - Se queda solo con las letras (isalpha), descartando comas, puntos, ¡ !
// - Convierte todo a minúscula (tolower)
// Ej: "Piedad," -> "piedad"    "amar!" -> "amar"
void limpiarPalabra(char *origen, char *destino) {
  int j = 0;
  for (int i = 0; origen[i] != '\0'; i++) {
    if (isalpha(origen[i])) {
      destino[j++] = tolower(origen[i]);
    }
  }
  destino[j] = '\0'; // cerramos el string con el caracter nulo
}

// Función que dibuja un verso palabra por palabra, agrandando la palabra
// indicada en "palabraObjetivo" (si el verso tiene una para agrandar)
void mostrarVerso(char *verso, char *palabraObjetivo) {
  display.clearDisplay(); // Borra el contenido anterior del buffer

  char copia[40];
  strcpy(copia, verso); // strtok() modifica el string original, por eso usamos una copia

  int x = 0; // posición horizontal donde se dibujará la próxima palabra
  int y = 0; // posición vertical de la línea actual (0 = arriba, 16 = abajo)

  char *palabra = strtok(copia, " ");
  // strtok separa el string en "tokens" (palabras) usando el espacio como separador.
  // La primera llamada lleva el string a trocear; las siguientes usan NULL.

  while (palabra != NULL) {
    char limpia[20];
    limpiarPalabra(palabra, limpia); // versión sin signos y en minúscula, para comparar

    // Si la palabra objetivo no está vacía y coincide con esta palabra, se agranda
    int tamano = (strlen(palabraObjetivo) > 0 && strcmp(limpia, palabraObjetivo) == 0) ? 2 : 1;

    // Ancho aproximado en píxeles: la fuente por defecto usa 6px por caracter en tamaño 1,
    // y ese ancho se multiplica por el tamaño de letra elegido
    int anchoPalabra = strlen(palabra) * 6 * tamano;
    int anchoEspacio = 6 * tamano; // ancho aproximado de un espacio, también escalado

    // Si la palabra no entra en lo que queda de la línea (128px de ancho), saltamos de línea
    if (x + anchoPalabra > SCREEN_WIDTH) {
      x = 0;
      y = 16; // la segunda línea arranca 16px más abajo (deja lugar a palabras grandes)
    }

    display.setTextSize(tamano);   // 1 = tamaño normal, 2 = tamaño "gritado" (el doble)
    display.setCursor(x, y);       // ubicamos dónde va a empezar a dibujarse la palabra
    display.print(palabra);        // dibujamos la palabra en el buffer (con su puntuación original)

    x += anchoPalabra + anchoEspacio; // corremos el cursor horizontal para la próxima palabra

    palabra = strtok(NULL, " "); // pedimos la siguiente palabra del mismo verso
  }

  display.display(); // recién acá se envían todos los cambios al panel físico
}
