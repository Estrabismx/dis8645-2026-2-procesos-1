# sesion-04a

## apuntes sesión
Empezamos a full con el proyecto 

Seguimos avanzando con el código, nos dimos cuenta que había que usar un potenciometro y un boton 0: así que empezamos a definir que haría cada cosa:

El potenciómetro puede hacer:
turning
tamaño de fuente
brillo
Tenemos cuatro botones, usaremos tres!!
play
pausa
repeat

Entre esas opciones dejamos el play, pausa y repeat, y el potenciómetro va a manejar el tamaño de la fuente.
Para conectar a tierra toda la línea sirve, porque en la electricidad significa que es el mismo punto.
Agregamos las funciones de los botones y el potenciómetro. Aún no sabemos si funciona, estamos intentando conectar los botones primero (difícil).


Hicimos un cambio brusco en el código nos dimos cuenta que era mejor otorgar char a todo el texto para que fuera más fácil de configurar:

y Así es como hemos ido avanzando:

```cpp
/*
 * ---------------------------------------------------------------
 * USAGE NOTICE / FAIR USE - FAIR DEALING
 * ---------------------------------------------------------------
 * The text of the poem "Pepper Sauce" (from the collection
 * "Pepper Seed", 2013) used in this code belongs to its author,
 * Malika Booker.
 *
 * This text is partially reproduced in this project for strictly
 * educational, non-commercial purposes, as part of an academic
 * project at Universidad Diego Portales (UDP). The use is
 * transformative: the poem is reinterpreted through text animations
 * on an OLED display as an installation piece, not reproduced or
 * distributed as a standalone work.
 *
 * No authorship over the original poem text is claimed.
 * All rights to the poem belong to Malika Booker.
 *
 * This project is non-profit and does not seek to substitute
 * for the acquisition or reading of the original work.
 * ---------------------------------------------------------------
 */

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define ANCHO_PANTALLA 128
#define ALTO_PANTALLA 32

Adafruit_SSD1306 display(ANCHO_PANTALLA, ALTO_PANTALLA, &Wire, -1);


// ------------------------------------------------
// CONTROLES
// ------------------------------------------------

#define BOTON_PLAY 2
#define BOTON_STOP 3
#define BOTON_REPEAT 4

#define POTENCIOMETRO A0


bool reproduciendo = false;
bool repetir = false;

int tamanoLetra = 1;


// ------------------------------------------------
// TEXTOS DEL POEMA
// ------------------------------------------------

// PRIMERA ESTROFA

char e1_v1[] = "I pray";
char e1_v2[] = "for that";
char e1_v3[] = "grandmother";
char e1_v4[] = "grinding her teeth";
char e1_v5[] = "one hand pushing in fresh hot peppers, seeds and all";
char e1_v6[] = "turning the handle of that old iron mill";
char e1_v7[] = "squeezing the limes, knowing";
char e1_v8[] = "they will burn and cut raw like acid";

char e1_golpe1[] = "BURN";
char e1_golpe2[] = "CUT";
char e1_golpe3[] = "RAW";
char e1_golpe4[] = "ACID";


// SEGUNDA ESTROFA

char e2_v1[] = "She pours in vinegar and gets Anne to chop five onions";
char e2_v2[] = "with a whole bulb of garlic";
char e2_v3[] = "Chop them up";
char e2_v4[] = "real fine girl";
char e2_v5[] = "you hear?";
char e2_v6[] = "And Anne dicing";
char e2_v7[] = "and crying";
char e2_v8[] = "relieved that no belt has blistered her skin";
char e2_v9[] = "no knife handle smashed down onto her knuckles";
char e2_v10[] = "until they bleed";
char e2_v11[] = "for stealing money from she grandmother purse";


// TERCERA ESTROFA

char e3_v1[] = "I hear she made Anne pour in the oil and vinegar";
char e3_v2[] = "stir up that hot sauce";
char e3_v3[] = "how she hold her down";
char e3_v4[] = "I hear she tied that girl to the bedposts";
char e3_v5[] = "strung her out naked";
char e3_v6[] = "like she there lying on a crucifix";
char e3_v7[] = "I hear she spread she out, then say";
char e3_v8[] = "I go teach you to go and steal from me";
char e3_v9[] = "Miss Lady";


// CUARTA ESTROFA

char e4_warning[] = "WARNING: violence and abuse";
char e4_v1[] = "I hear she scoop that pepper sauce out of a white enamel bowl";
char e4_v2[] = "and pack it deep into she granddaughter's";
char e4_v3[] = "I hear there was one piece of screaming in the house that day";
char e4_golpe[] = "SCREAMING";


// QUINTA ESTROFA

char e5_v1[] = "Anne bawl till she turn hoarse";
char e5_v2[] = "bawl till the hair on the neighbours skin raise up";
char e5_v3[] = "bawl till she start hiss through her teeth";
char e5_v4[] = "bawl till she mouth could make no more sound";
char e5_v5[] = "I hear how she turn raw";
char e5_v6[] = "how that grandmother leave her there all day";


// FINAL

char final_v1[] = "I hear how she couldn't walk or talk for weeks";


// ------------------------------------------------
// FRAME INTRODUCCION
// ------------------------------------------------

char *intro[] = {
  "Poema 1:",
  "Pepper Sauce",
  "Malika Booker",
};

int cantidadLineasIntro = 3;


// ------------------------------------------------
// DECLARACIONES DE FUNCIONES
// ------------------------------------------------

void escribirLetraPorLetra(char *texto, int x, int y, int velocidad);
void moverMolino(char *texto);
void mostrarGolpe(char *texto);

void primeraEstrofa();
void segundaEstrofa();

void leerControles();
void reproducirPoema();


// ------------------------------------------------
// SETUP
// ------------------------------------------------

void setup() {

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    while (true);
  }


  pinMode(BOTON_PLAY, INPUT_PULLUP);
  pinMode(BOTON_STOP, INPUT_PULLUP);
  pinMode(BOTON_REPEAT, INPUT_PULLUP);


  display.setTextColor(SSD1306_WHITE);


  for (int i = 0; i < cantidadLineasIntro; i++) {

    escribirLetraPorLetra(intro[i], 0, 0, 100);

    delay(700);

  }

}


// ------------------------------------------------
// LOOP
// ------------------------------------------------

void loop() {


  leerControles();


  if (reproduciendo == true) {

    reproducirPoema();


    if (repetir == false) {

      reproduciendo = false;

    }

  }

}


// ------------------------------------------------
// FUNCIONES DE ANIMACION
// ------------------------------------------------


void escribirLetraPorLetra(char *texto, int x, int y, int velocidad) {

  display.clearDisplay();
  display.setCursor(x, y);


  for (int i = 0; texto[i] != '\0'; i++) {

    display.print(texto[i]);
    display.display();

    delay(velocidad);

  }

}



void moverMolino(char *texto) {


  for (int x = 128; x >= 0; x--) {

    display.clearDisplay();

    display.setCursor(x, 10);
    display.print(texto);

    display.display();

    delay(30);

  }


  for (int x = 0; x <= 128; x++) {

    display.clearDisplay();

    display.setCursor(x, 10);
    display.print(texto);

    display.display();

    delay(30);

  }

}



void mostrarGolpe(char *texto) {


  display.clearDisplay();

  display.fillScreen(SSD1306_WHITE);

  display.setTextColor(SSD1306_BLACK);

  display.setTextSize(2);

  display.setCursor(10, 10);

  display.print(texto);

  display.display();


  delay(550);


  display.clearDisplay();

  display.setTextColor(SSD1306_WHITE);

  display.setTextSize(1);

  display.display();


  delay(200);

}


// ------------------------------------------------
// ESTROFAS
// ------------------------------------------------


void primeraEstrofa() {

  escribirLetraPorLetra(e1_v1, 0, 0, 150);
  delay(500);

  escribirLetraPorLetra(e1_v2, 0, 0, 150);
  delay(500);

  escribirLetraPorLetra(e1_v3, 0, 0, 150);
  delay(1000);

  escribirLetraPorLetra(e1_v4, 0, 0, 70);
  delay(700);

  escribirLetraPorLetra(e1_v5, 0, 0, 100);
  delay(800);

  moverMolino(e1_v6);
  delay(800);

  escribirLetraPorLetra(e1_v7, 0, 0, 120);
  delay(800);

  escribirLetraPorLetra(e1_v8, 0, 0, 120);
  delay(800);


  mostrarGolpe(e1_golpe1);
  mostrarGolpe(e1_golpe2);
  mostrarGolpe(e1_golpe3);
  mostrarGolpe(e1_golpe4);


  display.clearDisplay();
  display.display();

  delay(2000);

}



void segundaEstrofa() {


  escribirLetraPorLetra(e2_v1, 0, 0, 100);

  delay(800);

}


// ------------------------------------------------
// CONTROLADORES
// ------------------------------------------------


void leerControles() {


  if (digitalRead(BOTON_PLAY) == LOW) {

    reproduciendo = true;

    delay(200);

  }



  if (digitalRead(BOTON_STOP) == LOW) {

    reproduciendo = false;

    display.clearDisplay();
    display.display();

    delay(200);

  }



  if (digitalRead(BOTON_REPEAT) == LOW) {

    repetir = !repetir;

    delay(200);

  }



  int lecturaPot = analogRead(POTENCIOMETRO);


  tamanoLetra = map(lecturaPot, 0, 1023, 1, 3);

}



// ------------------------------------------------
// REPRODUCCION DEL POEMA
// ------------------------------------------------

void reproducirPoema() {

  primeraEstrofa();

  segundaEstrofa();

}
```

## encargos

## lectura
Hasta ahora entiendo que Witt sigue desarrollando la relación entre matemáticas, arquitectura y diseño, pero ahora se enfoca más en cómo estas disciplinas se han ido mezclando gracias a distintas herramientas, métodos y formas de pensar.
También habla de los computadores y cómo estos fueron cambiando la forma de trabajar, porque permiten guardar, organizar, combinar conocimientos y métodos matemáticos.
Aparece también la idea de los “thought collectives”, que entiendo que son como grupos de personas que comparten conocimientos e ideas y van desarrollando nuevas formas de trabajar entre disciplinas.
Me gustó el ejemplo de la casa de cuatro dimensiones, porque aunque es difícil imaginarla, muestra cómo una idea matemática puede llevar a pensar la arquitectura de una manera completamente distinta.

“The architectural thought collectives that drew on mathematical influences were nourished through public exhibitions, science-popularizing books, and direct conversation with mathematicians.”- pág.26

“with the precision of mathematics, design could radically multiply its capacities.”- pág.27
