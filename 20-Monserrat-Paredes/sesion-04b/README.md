# sesion-04b → 04/09

## apuntes sesión

Llego misaa nos hablo de su viaje y las cosas locas que hizo de pura experimentación y nos trajo dulcees.

fotoo dulces 

![dulces](./imagenes/dulces.jpg)

Nos mostro esta pagina para general poemas con diferentes palabras

https://misaaaaaa.github.io/code-switching-poetry/

frase: si no puedes con ellos, confundelos (misaa).

seguir avanzando en proyecto-01 :) → ver animaciones → en proyecto-01 solo poner links de los códigos.

PROBLEMA del código 4.2: En los versos del poema en la linea 95 en pantalla se ve así:

"piedad", // 10: ¡Señor, piedad, piedad! (agranda las dos apariciones) → se corta por espacio en pantalla, al ser 2 palabras de mayor tamaño

deberia aparecer:

```cpp
// agrandar las palabras “Piedad, piedad!” 
  "¡Señor, piedad, piedad!",
```

SOLUCIÓN → dejar solo un "piedad" por espacio en pantalla 

```cpp
// agrandar las palabras “piedad!” 
  "¡Señor, piedad, piedad!",
```

Agregar un verso extra al principio, ahora son 13 versos y en la parte  del verso  11 solo se tiene que agrandar la palabra “piedad!”, se tendria que ver asi:    

"Alfonsina Storni",

// agrandar la palabra “queja” 

"Senor, mi queja es esta,",

"Tu me comprenderas",

// agrandar la palabra “muriendo” 

 "De amor me estoy muriendo,",
 
 "Pero no puedo amar.",


// agrandar la palabra “persigo” 

 "Persigo lo perfecto",
 
 "En mi y en los demas,",
 
// agrandar la palabra “perfecto” 

 "Persigo lo perfecto",
 
 "Para poder amar.",


// agrandar la palabra “consumo” 

 "Me consumo en mi fuego,",
 
// agrandar la palabra “piedad!”

 "Senor, piedad, piedad!",
 
 "De amor me estoy muriendo,",
 
// agrandar la palabra “amar!” 

 "Pero no puedo amar!"

 ---
 
### Código 5 → 04/09

```cpp
// ================================================================
// Poema "Queja" de Alfonsina Storni
// Sketch para mostrar el poema en pantalla OLED 0,91" I2C (128x32)
// usando Adafruit_GFX + Adafruit_SSD1306
// - Palabras clave se muestran más grandes (efecto "grito")
// - El potenciómetro B10K controla directamente EN QUÉ VERSO estás
// - El texto se dibuja centrado horizontal y verticalmente,
//   con interlineado configurable y palabras centradas entre sí
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

// Espacio extra (en píxeles) entre línea y línea
#define INTERLINEADO 4

// Máximo de líneas que puede llegar a usar un verso
#define MAX_LINEAS 3

// Creamos el objeto "display" que representa nuestra pantalla física
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Arreglo con los versos ORIGINALES (con tildes), usados
// para imprimir el poema completo y correcto en el Monitor Serie
char *misVersos[] = {
  "Alfonsina Storni",
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
// Si el valor NO tiene signos de puntuación (ej. "queja"), se compara
// ignorando comas/puntos/exclamaciones de la palabra del verso.
// Si el valor SÍ tiene un signo (ej. "piedad!"), se exige que la palabra
// del verso tenga EXACTAMENTE esa puntuación, para distinguir entre
// dos apariciones de una misma palabra en el mismo verso.
char *palabraGrande[] = {
  "",           // 0: Alfonsina Storni
  "queja",      // 1: Señor, mi queja es ésta,
  "",           // 2: Tú me comprenderás
  "muriendo",   // 3: De amor me estoy muriendo,
  "",           // 4: Pero no puedo amar.
  "persigo",    // 5: Persigo lo perfecto
  "",           // 6: En mí y en los demás,
  "perfecto",   // 7: Persigo lo perfecto
  "",           // 8: Para poder amar.
  "consumo",    // 9: Me consumo en mi fuego,
  "piedad!",    // 10: ¡Señor, piedad, piedad!  (agranda SOLO "piedad!", no "piedad,")
  "",           // 11: De amor me estoy muriendo,
  "amar!"       // 12: ¡Pero no puedo amar!
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

// Función auxiliar: copia una palabra quitando signos de puntuación
// y la convierte a minúscula. Se usa para comparar palabras SIN
// importar su puntuación (ej. "muriendo," -> "muriendo").
void limpiarPalabra(char *origen, char *destino) {
  int j = 0;
  for (int i = 0; origen[i] != '\0'; i++) {
    if (isalpha(origen[i])) {
      destino[j++] = tolower(origen[i]);
    }
  }
  destino[j] = '\0';
}

// Función auxiliar: pasa una palabra a minúscula pero SIN quitarle
// la puntuación. Se usa cuando necesitamos distinguir "piedad," de "piedad!".
void aMinusculasConPuntuacion(char *origen, char *destino) {
  int i = 0;
  for (; origen[i] != '\0'; i++) {
    destino[i] = tolower(origen[i]);
  }
  destino[i] = '\0';
}

// Función auxiliar: revisa si un string tiene algún caracter que
// NO sea letra (por ejemplo una "!"). Sirve para decidir qué tipo
// de comparación usar contra la palabra objetivo.
bool tienePuntuacion(char *texto) {
  for (int i = 0; texto[i] != '\0'; i++) {
    if (!isalpha(texto[i])) return true;
  }
  return false;
}

// Función que dibuja un verso: agranda la palabra indicada, centra todo
// el bloque en la pantalla, agrega interlineado entre renglones, y
// centra verticalmente cada palabra respecto al alto de su línea.
void mostrarVerso(char *verso, char *palabraObjetivo) {
  display.clearDisplay();

  char copia[40];
  strcpy(copia, verso); // strtok() modifica el string original, por eso usamos una copia

  // --- PASE 1: separar el verso en palabras y calcular tamaño y ancho de cada una ---
  char *palabras[10];
  int tamanos[10];
  int anchos[10];
  int cantidadPalabras = 0;

  // Antes de comparar, vemos si la palabra objetivo de este verso
  // exige puntuación exacta (ej. "piedad!") o no (ej. "queja")
  bool exigirPuntuacion = (strlen(palabraObjetivo) > 0) && tienePuntuacion(palabraObjetivo);

  char *token = strtok(copia, " ");
  while (token != NULL && cantidadPalabras < 10) {
    int tam = 1; // por defecto, tamaño normal

    if (strlen(palabraObjetivo) > 0) {
      if (exigirPuntuacion) {
        // Comparación EXACTA (con puntuación incluida), para distinguir
        // por ejemplo "piedad," de "piedad!"
        char tokenMin[20];
        aMinusculasConPuntuacion(token, tokenMin);
        if (strcmp(tokenMin, palabraObjetivo) == 0) tam = 2;
      } else {
        // Comparación ignorando puntuación, como antes
        char limpia[20];
        limpiarPalabra(token, limpia);
        if (strcmp(limpia, palabraObjetivo) == 0) tam = 2;
      }
    }

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

    if (anchoAcumulado + espacioExtra + anchos[i] > SCREEN_WIDTH && lineaActual < MAX_LINEAS - 1) {
      lineaActual++;
      anchoAcumulado = 0;
      espacioExtra = 0;
    }

    lineaDe[i] = lineaActual;
    anchoAcumulado += espacioExtra + anchos[i];
    anchoLinea[lineaActual] = anchoAcumulado;

    int alturaPalabra = 8 * tamanos[i];
    if (alturaPalabra > altoLinea[lineaActual]) {
      altoLinea[lineaActual] = alturaPalabra;
    }
  }

  int numLineas = lineaActual + 1;

  // --- PASE 3: calcular el alto total del bloque, con interlineado incluido ---
  int interlineado = INTERLINEADO;
  int altoTotal = 0;
  for (int l = 0; l < numLineas; l++) altoTotal += altoLinea[l];
  altoTotal += interlineado * (numLineas - 1);

  // Si el bloque no entra en la pantalla, reducimos el interlineado hasta que entre
  while (altoTotal > SCREEN_HEIGHT && interlineado > 0) {
    interlineado--;
    altoTotal = 0;
    for (int l = 0; l < numLineas; l++) altoTotal += altoLinea[l];
    altoTotal += interlineado * (numLineas - 1);
  }

  // --- Centrado vertical del bloque completo ---
  int yInicio = (SCREEN_HEIGHT - altoTotal) / 2;
  if (yInicio < 0) yInicio = 0;

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

  // --- PASE 4: dibujar cada palabra, centrada horizontal y verticalmente ---
  int xActual[MAX_LINEAS];
  for (int l = 0; l < numLineas; l++) xActual[l] = xInicio[l];

  for (int i = 0; i < cantidadPalabras; i++) {
    int linea = lineaDe[i];
    int alturaPalabra = 8 * tamanos[i];

    int centroLinea = topLinea[linea] + (altoLinea[linea] / 2);
    int y = centroLinea - (alturaPalabra / 2);

    display.setTextSize(tamanos[i]);
    display.setCursor(xActual[linea], y);
    display.print(palabras[i]);

    xActual[linea] += anchos[i] + (espacioBase * tamanos[i]);
  }

  display.display();
}
```

Registro gif

![codigo5](./imagenes/codigo5.gif)


Ya se arreglo todo lo anterior y ahora queremos agregar animación mientras la persona interactua con el poema.

la idea es que se vea así:

// agrandar la palabra “perfecto” 

 "Persigo lo perfecto",
 
 "Para poder amar.",


// animación fueguito


// agrandar la palabra “consumo” 

 "Me consumo en mi fuego,",


Que la animación fluya y en ese momento uno no puedo controlar el texto, porque esta corriendo la animación, la idea es que pase solo una vez, que no ser en loop, luego de esto uno puede seguir controlando el poema con el potenciómetro.

La Emilia se encargara de hacer la animación

bitmaps para transformar imagenes a código: <https://tools.stonez56.com/u8g2/getBitmap.php>


## encargos

## lectura

Libro: A New Program for Graphic Design

Autor: David Reinfurt

El libro está dividido en 3 grandes capítulos.

I. T--Y-P-O-G-R-A-P-H-Y

II. G-E-S-T-A-L-T

III. I-N-T-E-R-F-A-C-E

El autor plantea las bases de lo que significa enseñar diseño gráfico hoy. Introduce la idea de que el diseño no se trata de "estilo" o decoración, sino de sistemas, reglas y tecnología aplicadas a la comunicación.
