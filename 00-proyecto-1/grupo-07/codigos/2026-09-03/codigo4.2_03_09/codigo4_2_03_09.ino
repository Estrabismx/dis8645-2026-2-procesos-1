// ================================================================
// Poema "Queja" de Alfonsina Storni
// Sketch para mostrar el poema en pantalla OLED 0,91" I2C (128x32)
// usando Adafruit_GFX + Adafruit_SSD1306
// - Palabras clave se muestran más grandes (efecto "grito")
// - El potenciómetro B10K controla directamente EN QUÉ VERSO estás
// - El texto se dibuja centrado horizontal y verticalmente
// - Las palabras grandes quedan centradas respecto a la línea
//   central de las palabras chicas (ya no alineadas por la base)
// - Interlineado configurable, y el bloque siempre se reacomoda
//   para entrar en la pantalla, sin importar cuántas líneas use
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

// NUEVO: cantidad de espacio extra (en píxeles) entre línea y línea.
// Subí este número si querés todavía más separación entre renglones.
#define INTERLINEADO 4

// NUEVO: máximo de líneas que puede llegar a usar un verso.
// Con este valor el código funciona igual para versos cortos (1 línea)
// o más largos (2 o 3 líneas), sin tener que tocar nada más.
#define MAX_LINEAS 3

// Creamos el objeto "display" que representa nuestra pantalla física
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Arreglo con los versos ORIGINALES (con tildes), usados
// para imprimir el poema completo y correcto en el Monitor Serie
char *misVersos[] = {
  "Alfonsina Storni,",
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
  "Alfonsina Storni",
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
char *palabraGrande[] = {
  "",           // 0: Alfonsina Storni,
  "queja",      // 1: Señor, mi queja es ésta,
  "",           // 2: Tú me comprenderás
  "muriendo",   // 3: De amor me estoy muriendo,
  "",           // 4: Pero no puedo amar.
  "persigo",    // 5: Persigo lo perfecto
  "",           // 6: En mí y en los demás,
  "perfecto",   // 7: Persigo lo perfecto
  "",           // 8: Para poder amar.
  "consumo",    // 9: Me consumo en mi fuego,
  "piedad",     // 10: ¡Señor, piedad, piedad!  (agranda las dos apariciones)
  "",           // 11: De amor me estoy muriendo,
  "amar"        // 12: ¡Pero no puedo amar!
};

// Cantidad total de versos
const int totalVersos = 13;

// Guarda qué verso se mostró la última vez, para no redibujar
// la pantalla si el potenciómetro no cambió de verso (evita parpadeo)
int indiceAnterior = -1; // -1 fuerza a que la primera vuelta del loop sí dibuje algo

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
}

// loop() se ejecuta UNA Y OTRA VEZ, sin parar
void loop() {

  int valorPot = analogRead(POT_PIN);
  // Lee la posición actual del potenciómetro: un número entre 0 y 1023

  int indiceActual = map(valorPot, 0, 1023, 0, totalVersos - 1);
  // Traducimos esa posición al índice del verso correspondiente (0 a 12).

  if (indiceActual != indiceAnterior) {
    // Solo actualizamos la pantalla si el verso correspondiente CAMBIÓ
    mostrarVerso(versosPantalla[indiceActual], palabraGrande[indiceActual]);
    Serial.println(misVersos[indiceActual]); // Verso completo (con tildes) por Serial
    indiceAnterior = indiceActual;
  }

  delay(20); // pequeña pausa para no saturar el procesador leyendo el potenciómetro
}

// Función auxiliar que limpia una palabra para poder compararla.
// Se queda solo con las letras y las pasa a minúscula.
// Ej: "Piedad," -> "piedad"    "amar!" -> "amar"
void limpiarPalabra(char *origen, char *destino) {
  int j = 0;
  for (int i = 0; origen[i] != '\0'; i++) {
    if (isalpha(origen[i])) {
      destino[j++] = tolower(origen[i]);
    }
  }
  destino[j] = '\0';
}

// Función que dibuja un verso: agranda la palabra indicada, centra todo
// el bloque en la pantalla, agrega interlineado entre renglones, y
// centra verticalmente cada palabra respecto al alto de su línea
// (en vez de alinearlas por la base).
void mostrarVerso(char *verso, char *palabraObjetivo) {
  display.clearDisplay();

  char copia[40];
  strcpy(copia, verso); // strtok() modifica el string original, por eso usamos una copia

  // --- PASE 1: separar el verso en palabras y calcular tamaño y ancho de cada una ---
  char *palabras[10];
  int tamanos[10];
  int anchos[10];
  int cantidadPalabras = 0;

  char *token = strtok(copia, " ");
  while (token != NULL && cantidadPalabras < 10) {
    char limpia[20];
    limpiarPalabra(token, limpia);

    int tam = (strlen(palabraObjetivo) > 0 && strcmp(limpia, palabraObjetivo) == 0) ? 2 : 1;

    palabras[cantidadPalabras] = token;
    tamanos[cantidadPalabras] = tam;
    anchos[cantidadPalabras] = strlen(token) * 6 * tam;
    cantidadPalabras++;

    token = strtok(NULL, " ");
  }

  // --- PASE 2: repartir las palabras en varias líneas (hasta MAX_LINEAS) ---
  int lineaDe[10];
  int anchoLinea[MAX_LINEAS];
  int altoLinea[MAX_LINEAS];
  for (int l = 0; l < MAX_LINEAS; l++) { anchoLinea[l] = 0; altoLinea[l] = 0; }

  int lineaActual = 0;
  int anchoAcumulado = 0;
  const int espacioBase = 6; // ancho de un espacio en blanco a tamaño 1

  for (int i = 0; i < cantidadPalabras; i++) {
    int espacioExtra = (anchoAcumulado > 0) ? (espacioBase * tamanos[i]) : 0;

    // Si la palabra no entra en lo que queda de la línea, pasamos a la siguiente
    // (mientras no nos pasemos del máximo de líneas permitidas)
    if (anchoAcumulado + espacioExtra + anchos[i] > SCREEN_WIDTH && lineaActual < MAX_LINEAS - 1) {
      lineaActual++;
      anchoAcumulado = 0;
      espacioExtra = 0;
    }

    lineaDe[i] = lineaActual;
    anchoAcumulado += espacioExtra + anchos[i];
    anchoLinea[lineaActual] = anchoAcumulado;

    int alturaPalabra = 8 * tamanos[i]; // 8px a tamaño 1, 16px a tamaño 2
    if (alturaPalabra > altoLinea[lineaActual]) {
      altoLinea[lineaActual] = alturaPalabra;
    }
  }

  int numLineas = lineaActual + 1; // cuántas líneas se usaron realmente

  // --- PASE 3: calcular el alto total del bloque, CON interlineado incluido ---
  int interlineado = INTERLINEADO;
  int altoTotal = 0;
  for (int l = 0; l < numLineas; l++) altoTotal += altoLinea[l];
  altoTotal += interlineado * (numLineas - 1); // el espacio extra va ENTRE líneas, no en los bordes

  // NUEVO: si el bloque no entra en la pantalla (verso muy largo con palabra grande),
  // vamos reduciendo el interlineado automáticamente hasta que entre
  while (altoTotal > SCREEN_HEIGHT && interlineado > 0) {
    interlineado--;
    altoTotal = 0;
    for (int l = 0; l < numLineas; l++) altoTotal += altoLinea[l];
    altoTotal += interlineado * (numLineas - 1);
  }

  // --- Centrado vertical del bloque completo ---
  int yInicio = (SCREEN_HEIGHT - altoTotal) / 2;
  if (yInicio < 0) yInicio = 0; // si de última no entra, arrancamos arriba del todo (sin recortar)

  // Calculamos el techo de cada línea, sumando alturas + interlineado de las líneas anteriores
  int topLinea[MAX_LINEAS];
  int acumulado = yInicio;
  for (int l = 0; l < numLineas; l++) {
    topLinea[l] = acumulado;
    acumulado += altoLinea[l] + interlineado;
  }

  // --- Centrado horizontal de cada línea ---
  int xInicio[MAX_LINEAS];
  for (int l = 0; l < numLineas; l++) {
    xInicio[l] = (SCREEN_WIDTH - anchoLinea[l]) / 2;
    if (xInicio[l] < 0) xInicio[l] = 0;
  }

  // --- PASE 4: dibujar cada palabra, centrada horizontal y VERTICALMENTE ---
  int xActual[MAX_LINEAS];
  for (int l = 0; l < numLineas; l++) xActual[l] = xInicio[l];

  for (int i = 0; i < cantidadPalabras; i++) {
    int linea = lineaDe[i];
    int alturaPalabra = 8 * tamanos[i];

    // CAMBIO CLAVE: antes alineábamos por la base (parte de abajo).
    // Ahora centramos cada palabra respecto al CENTRO del renglón:
    // así, una palabra grande queda con su medio a la misma altura
    // que el medio de las palabras chicas de esa misma línea.
    int centroLinea = topLinea[linea] + (altoLinea[linea] / 2);
    int y = centroLinea - (alturaPalabra / 2);

    display.setTextSize(tamanos[i]);
    display.setCursor(xActual[linea], y);
    display.print(palabras[i]);

    xActual[linea] += anchos[i] + (espacioBase * tamanos[i]);
  }

  display.display();
}
