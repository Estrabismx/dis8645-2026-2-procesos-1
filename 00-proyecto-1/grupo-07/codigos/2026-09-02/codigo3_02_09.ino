// ================================================================
// Poema "Queja" de Alfonsina Storni
// Sketch para mostrar el poema en pantalla OLED 0,91" I2C (128x32)
// usando Adafruit_GFX + Adafruit_SSD1306
// Ahora con palabras "gritadas" (mostradas más grandes)
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

// NUEVO: por cada verso, indicamos qué palabra hay que agrandar.
// Si el string está vacío (""), ese verso se muestra todo en tamaño normal.
// Las palabras van en minúscula y sin signos, porque así las compara limpiarPalabra().
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
  // Nota: ya no fijamos un setTextSize único acá, porque ahora
  // cada palabra puede usar tamaño 1 (normal) o 2 (agrandada/"gritada")
}

// loop() se ejecuta UNA Y OTRA VEZ, sin parar
void loop() {
  for (int i = 0; i < totalVersos; i++) {
    // Le pasamos el verso Y la palabra que hay que agrandar para ese verso
    mostrarVerso(versosPantalla[i], palabraGrande[i]);
    Serial.println(misVersos[i]); // Imprime por Serial la versión completa con tildes
    delay(2500);                  // Espera 2.5 segundos antes del siguiente verso
  }
}

// NUEVO: función auxiliar que limpia una palabra para poder compararla.
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

  // strtok separa el string en "tokens" (palabras) usando el espacio como separador.
  // La primera llamada lleva el string a trocear; las siguientes usan NULL
  // para indicar "seguir troceando el mismo string".
  char *palabra = strtok(copia, " ");

  while (palabra != NULL) {
    char limpia[20];
    limpiarPalabra(palabra, limpia); // versión sin signos y en minúscula, para comparar

    // Si la palabra objetivo no está vacía y coincide con esta palabra, se agranda
    int tamano = (strlen(palabraObjetivo) > 0 && strcmp(limpia, palabraObjetivo) == 0) ? 2 : 1;

    // Ancho aproximado en píxeles: la fuente por defecto usa 6px por caracter en tamaño 1,
    // y ese ancho se multiplica por el tamaño de letra elegido
    int anchoPalabra = strlen(palabra) * 6 * tamano;
    int anchoEspacio = 6 * tamano; // espacio en blanco entre palabras, también escalado

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
