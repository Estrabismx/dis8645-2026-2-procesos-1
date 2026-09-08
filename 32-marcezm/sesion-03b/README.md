# sesion-03b
Viernes 28 de Agosto

## apuntes sesión

### String class
Un `String` es una cadena de caracteres, como una seguidilla de mostacillas, donde cada mostacilla sería un carácter.

En C no existían los `String` como tal; en C++ es menos latero trabajar con ellos.

**Recomendación:** hacer el código en C++ de forma más general, no tan específico de Arduino, para aprender realmente el lenguaje.

### Documentación

- [String Object](https://docs.arduino.cc/language-reference/en/variables/data-types/stringObject/)
- [String Characters](https://docs.arduino.cc/built-in-examples/strings/StringCharacters/)
- [String data type](https://docs.arduino.cc/language-reference/en/variables/data-types/string/)
- [int](https://docs.arduino.cc/language-reference/en/variables/data-types/int/)

---

### Caracteres y comillas
- Los **caracteres individuales** se escriben con **comillas simples**: `'A'`
- Cuando aparecen comillas dobles, significa que tenemos un conjunto de caracteres, es decir, un `String`: `"Aaron"`
- Se entenderia asi:
  - `'A'`       → un carácter
  - `"Aaron"`   → varios caracteres / String

¿Cómo hacer Strings en Arduino?
Para palabras o frases se utilizan `"`:

```cpp
String nombre = "Aaron";
```

Con comillas `'` si es solo un carácter:

```cpp
char letra = 'A';
```

###  Crear un Strings
Primero va el tipo de dato, luego el nombre que le coloquemos y después el valor:

```cpp
String thisString = String(13);
```

En este caso:

```cpp
String thisString = String(13);
```

`String(13)` convierte el número `13` en un String: 13 → "13"

También podemos decir que palabras queremos guardar:

```cpp
String comida = "sopaipilla";
```
La idea es que el `String` pueda almacenar la cantidad de caracteres que contiene ese texto.

### Importante sobre String
El `String` es más exigente con la memoria que trabajar directamente con arreglo de caracteres, especialmente cuando el código se hace más grande.

Puede terminar siendo muy pesado y "marear" al código/computador.

Por eso también es importante aprender a trabjar con arreglos de caracteres `(char)`.

### Arreglo de caracteres

Los corchetes `[]` indican que estamos trabajando con arreglo, esto quiere decir que tendremos varios elementos:

```cpp
char Str4[8] = "arduino";
```

- En este caso `char` indica que son caracteres.
-  `[8]` indica que el arreglo tiene 8 posciones.
-  la palabra `arduino` tiene 7 caracteres, pero necesitamos 8 posiciones porque las cadenas de caracteres terminan con `\0`, este carácter indica el final de la cadena.
-  entonces `a → r → d → u → i → n → o → \0` ocupa 8 posiciones.

### Arreglo de enteros
Al principio podríamos hacer:

```cpp
int edadAaron = 37;
int edadSeba = 22;
int edadEmi = 24;
```
pero si tenemos demasiadas personas se vuelve poco práctico.

Por ejemplo, si quiero guardar 36 edades:
```cpp
int edades[36];
```
Esto significa: crear un arreglo llamado edades que tenga espacio para 36 números enteros.

También podemos declararlo y asignarle valores al mismo tiempo:

```cpp
int edades[3] = {37, 22, 24};
```

### Posiciones de un arreglo
Las posiciones de los arreglos comienzan en 0.

Por ejemplo:

```cpp
int edades[3] = {37, 22, 24};
```

tenemos:

```
edades[0] → 37
edades[1] → 22
edades[2] → 24
```
La posición `3` no existe en este arreglo, porque tiene solamente 3 elementos.

### Ejemplo en clases: edades

```cpp
// declaración de arreglo de enteros
// que se llama edades

int edades[3] = {37, 22, 24};

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.print(edades[0]);
  Serial.print(", ");
  Serial.print(edades[1]);
  Serial.print(", ");
  Serial.println(edades[2]);
}
```

El resultado en el monitor serial será:

```
37, 22, 24
```

### Arreglos de nombres
También podemos guardar un nombre utilizando un arreglo de caracteres:

```cpp
char nombre[6] = "aaron";
```

"Con 5 no funcionó", esto ocurre porque `aaron` tiene 5 caracteres, pero necesitamos una posición adicional para el \0.

```
a → a → r → o → n → \0
```

Por eso:

```cpp
char nombre[6] = "aaron";
```

### Acceder a los caracteres individualmente
Cada carácter tiene una posición:

```
nombre[0] → a
nombre[1] → a
nombre[2] → r
nombre[3] → o
nombre[4] → n
```

Ejemplo:

```cpp
void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.print(nombre[0]);
  Serial.print(nombre[1]);
  Serial.print(nombre[2]);
  Serial.print(nombre[3]);
  Serial.println(nombre[4]);
}
```

Resultado:

```
aaron
```

### Un poemario como arreglo
Una forma de entender los arreglos dentro de otros arreglos:

// Un poemario es un arreglo de páginas.
// Una página es un arreglo de líneas.
// Una línea es un arreglo de caracteres.

Es decir:
```
Poemario
   ↓
Páginas
   ↓
Líneas
   ↓
Caracteres
```

### Ejemplo: arreglo de versos

```cpp
char *misVersos[] = {
  "Mami, no te haga' de rogar",
  "No me gustaría perder el tiempo",
  "Que tenemo' pa' poderte tocar",
  "Y estás con otro, esa mierda no lo entiendo, yeah",
  "Que te lo juro, no eres nada pa' mí, te lo juro, ah",};
```

## encargos

encargo-03b:

1. apuntes personales de String, string, array, con bibliografia y con pantallazos de resultados, y dudas textuales.
2. subir código a su bitácora ordenado con el formato de backticks a continuación, del proyecto hasta ahora.
3. definir y escribir el corpus a usar: autora, poemas, licencias, poblarlo en la carpeta 00-proyecto-1

### Poema utilizado

**Autora:** Mary Oliver
**Poema:** Gansos salvajes
**Fragmento escogido:**
```
No tienes que ser buena.
No tienes que recorrer el desierto de rodillas, arrepintiéndote.
Sólo deja que el suave animal de tu cuerpo ame lo que ama.
Háblame del dolor, del tuyo, yo te hablaré del mío.
Mientras tanto, el mundo sigue.
```

### Código ya funcionando
Se hizo de manera muy manual, es decir viendo la parte que ya nos funciono (la parte de texto) se copio y pego, cambiando el verso, con los versos tambien se tuvieron que dividir.

```cpp
void testscrolltext(void) {
  
 display.setTextSize(1); // Draw 2X-scale text
  display.setTextColor(SSD1306_WHITE);

  // primer verso 
  display.setCursor(10, 0);
  display.println(F("No tienes")); // primera linea de texto
  display.setCursor(0, 10);
  display.println(F("que ser buena.")); // segunda linea de texto
 
  display.display();      // Show initial text
  delay(2500);

  // borrar primer verso
  display.clearDisplay();

  // segundo verso parte 1
  display.setCursor(0, 0);
  display.println(F("No tienes que"));
  display.setCursor(0, 10);
  display.println(F("recorrer el"));
  display.setCursor(0, 20);
  display.println(F("desierto de"));

  display.display();
  delay(2500);

  // borrar el segundo verso parte 1
  display.clearDisplay();

  // segundo verso parte 2
  display.setCursor(0, 0);
  display.println(F("rodillas,"));
  display.setCursor(0, 10);
  display.println(F("arrepitiendote."));

  display.display();
  delay(2500);

  // borrar el segundo verso
  display.clearDisplay();

  // tercer verso parte 1
  display.setCursor(0, 0);
  display.println(F("Solo deja que"));
  display.setCursor(0, 10);
  display.println(F("el suave animal"));
  
  display.display();
  delay(2500);

  // borrar tercer verso parte 1
  display.clearDisplay();

  // tercer verso parte 2
  display.setCursor(0, 0);
  display.println(F("de tu cuerpo"));
  display.setCursor(0, 10);
  display.println(F("ame lo que ama."));

  display.display();
  delay(2500);

  // borrar cuarto verso
  display.clearDisplay();

  // cuarto verso parte 1
  display.setCursor(0, 0);
  display.println(F("Hablame del dolor,"));
  display.setCursor(0, 10);
  display.println(F("del tuyo,"));
  display.setCursor(0, 20);
  display.println(F("yo te hablare del mio."));
  
  display.display();
  delay(2500);

  // borrar el cuarto verso
  display.clearDisplay();

  // quiento verso 
  display.setCursor(0, 0);
  display.println(F("Mientras tanto,"));
  display.setCursor(0, 10);
  display.println(F("el mundo sigue."));

  display.display();
  delay(2500);

}
```

Este es el código completo:

```cpp
/**************************************************************************
 This is an example for our Monochrome OLEDs based on SSD1306 drivers

 Pick one up today in the adafruit shop!
 ------> http://www.adafruit.com/category/63_98

 This example is for a 128x32 pixel display using I2C to communicate
 3 pins are required to interface (two I2C and one reset).

 Adafruit invests time and resources providing this open
 source code, please support Adafruit and open-source
 hardware by purchasing products from Adafruit!

 Written by Limor Fried/Ladyada for Adafruit Industries,
 with contributions from the open source community.
 BSD license, check license.txt for more information
 All text above, and the splash screen below must be
 included in any redistribution.
 **************************************************************************/

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
// The pins for I2C are defined by the Wire-library. 
// On an arduino UNO:       A4(SDA), A5(SCL)
// On an arduino MEGA 2560: 20(SDA), 21(SCL)
// On an arduino LEONARDO:   2(SDA),  3(SCL), ...
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define NUMFLAKES     10 // Number of snowflakes in the animation example

#define LOGO_HEIGHT   16
#define LOGO_WIDTH    16
static const unsigned char PROGMEM logo_bmp[] =
{ 0b00000000, 0b11000000,
  0b00000001, 0b11000000,
  0b00000001, 0b11000000,
  0b00000011, 0b11100000,
  0b11110011, 0b11100000,
  0b11111110, 0b11111000,
  0b01111110, 0b11111111,
  0b00110011, 0b10011111,
  0b00011111, 0b11111100,
  0b00001101, 0b01110000,
  0b00011011, 0b10100000,
  0b00111111, 0b11100000,
  0b00111111, 0b11110000,
  0b01111100, 0b11110000,
  0b01110000, 0b01110000,
  0b00000000, 0b00110000 };

void setup() {
  Serial.begin(9600);

  // Wait for display
  delay(500);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  // Show initial display buffer contents on the screen --
  // the library initializes this with an Adafruit splash screen.
  display.display();
  delay(2000); // Pause for 2 seconds

  // Clear the buffer
  display.clearDisplay();

  // Draw a single pixel in white
  display.drawPixel(10, 10, SSD1306_WHITE);

  // Show the display buffer on the screen. You MUST call display() after
  // drawing commands to make them visible on screen!
  display.display();
  delay(2000);
  // display.display() is NOT necessary after every single drawing command,
  // unless that's what you want...rather, you can batch up a bunch of
  // drawing operations and then update the screen all at once by calling
  // display.display(). These examples demonstrate both approaches...

  testscrolltext();    // Draw scrolling text
}

void loop() {
}

void testdrawline() {
  int16_t i;

  display.clearDisplay(); // Clear display buffer

  for(i=0; i<display.width(); i+=4) {
    display.drawLine(0, 0, i, display.height()-1, SSD1306_WHITE);
    display.display(); // Update screen with each newly-drawn line
    delay(1);
  }
  for(i=0; i<display.height(); i+=4) {
    display.drawLine(0, 0, display.width()-1, i, SSD1306_WHITE);
    display.display();
    delay(1);
  }
  delay(250);

  display.clearDisplay();

  for(i=0; i<display.width(); i+=4) {
    display.drawLine(0, display.height()-1, i, 0, SSD1306_WHITE);
    display.display();
    delay(1);
  }
  for(i=display.height()-1; i>=0; i-=4) {
    display.drawLine(0, display.height()-1, display.width()-1, i, SSD1306_WHITE);
    display.display();
    delay(1);
  }
  delay(250);

  display.clearDisplay();

  for(i=display.width()-1; i>=0; i-=4) {
    display.drawLine(display.width()-1, display.height()-1, i, 0, SSD1306_WHITE);
    display.display();
    delay(1);
  }
  for(i=display.height()-1; i>=0; i-=4) {
    display.drawLine(display.width()-1, display.height()-1, 0, i, SSD1306_WHITE);
    display.display();
    delay(1);
  }
  delay(250);

  display.clearDisplay();

  for(i=0; i<display.height(); i+=4) {
    display.drawLine(display.width()-1, 0, 0, i, SSD1306_WHITE);
    display.display();
    delay(1);
  }
  for(i=0; i<display.width(); i+=4) {
    display.drawLine(display.width()-1, 0, i, display.height()-1, SSD1306_WHITE);
    display.display();
    delay(1);
  }

  delay(2000); // Pause for 2 seconds
}

void testdrawrect(void) {
  display.clearDisplay();

  for(int16_t i=0; i<display.height()/2; i+=2) {
    display.drawRect(i, i, display.width()-2*i, display.height()-2*i, SSD1306_WHITE);
    display.display(); // Update screen with each newly-drawn rectangle
    delay(1);
  }

  delay(2000);
}

void testfillrect(void) {
  display.clearDisplay();

  for(int16_t i=0; i<display.height()/2; i+=3) {
    // The INVERSE color is used so rectangles alternate white/black
    display.fillRect(i, i, display.width()-i*2, display.height()-i*2, SSD1306_INVERSE);
    display.display(); // Update screen with each newly-drawn rectangle
    delay(1);
  }

  delay(2000);
}

void testdrawcircle(void) {
  display.clearDisplay();

  for(int16_t i=0; i<max(display.width(),display.height())/2; i+=2) {
    display.drawCircle(display.width()/2, display.height()/2, i, SSD1306_WHITE);
    display.display();
    delay(1);
  }

  delay(2000);
}

void testfillcircle(void) {
  display.clearDisplay();

  for(int16_t i=max(display.width(),display.height())/2; i>0; i-=3) {
    // The INVERSE color is used so circles alternate white/black
    display.fillCircle(display.width() / 2, display.height() / 2, i, SSD1306_INVERSE);
    display.display(); // Update screen with each newly-drawn circle
    delay(1);
  }

  delay(2000);
}

void testdrawroundrect(void) {
  display.clearDisplay();

  for(int16_t i=0; i<display.height()/2-2; i+=2) {
    display.drawRoundRect(i, i, display.width()-2*i, display.height()-2*i,
      display.height()/4, SSD1306_WHITE);
    display.display();
    delay(1);
  }

  delay(2000);
}

void testfillroundrect(void) {
  display.clearDisplay();

  for(int16_t i=0; i<display.height()/2-2; i+=2) {
    // The INVERSE color is used so round-rects alternate white/black
    display.fillRoundRect(i, i, display.width()-2*i, display.height()-2*i,
      display.height()/4, SSD1306_INVERSE);
    display.display();
    delay(1);
  }

  delay(2000);
}

void testdrawtriangle(void) {
  display.clearDisplay();

  for(int16_t i=0; i<max(display.width(),display.height())/2; i+=5) {
    display.drawTriangle(
      display.width()/2  , display.height()/2-i,
      display.width()/2-i, display.height()/2+i,
      display.width()/2+i, display.height()/2+i, SSD1306_WHITE);
    display.display();
    delay(1);
  }

  delay(2000);
}

void testfilltriangle(void) {
  display.clearDisplay();

  for(int16_t i=max(display.width(),display.height())/2; i>0; i-=5) {
    // The INVERSE color is used so triangles alternate white/black
    display.fillTriangle(
      display.width()/2  , display.height()/2-i,
      display.width()/2-i, display.height()/2+i,
      display.width()/2+i, display.height()/2+i, SSD1306_INVERSE);
    display.display();
    delay(1);
  }

  delay(2000);
}

void testdrawchar(void) {
  display.clearDisplay();

  display.setTextSize(1);      // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE); // Draw white text
  display.setCursor(0, 0);     // Start at top-left corner
  display.cp437(true);         // Use full 256 char 'Code Page 437' font

  // Not all the characters will fit on the display. This is normal.
  // Library will draw what it can and the rest will be clipped.
  for(int16_t i=0; i<256; i++) {
    if(i == '\n') display.write(' ');
    else          display.write(i);
  }

  display.display();
  delay(2000);
}

void testdrawstyles(void) {
  display.clearDisplay();

  display.setTextSize(1);             // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE);        // Draw white text
  display.setCursor(0,0);             // Start at top-left corner
  display.println(F("Hello, world!"));

  display.setTextColor(SSD1306_BLACK, SSD1306_WHITE); // Draw 'inverse' text
  display.println(3.141592);

  display.setTextSize(2);             // Draw 2X-scale text
  display.setTextColor(SSD1306_WHITE);
  display.print(F("0x")); display.println(0xDEADBEEF, HEX);

  display.display();
  delay(2000);
}

void testscrolltext(void) {
  
 display.setTextSize(1); // Draw 2X-scale text
  display.setTextColor(SSD1306_WHITE);

  // primer verso 
  display.setCursor(10, 0);
  display.println(F("No tienes")); // primera linea de texto
  display.setCursor(0, 10);
  display.println(F("que ser buena.")); // segunda linea de texto
 
  display.display();      // Show initial text
  delay(2500);

  // borrar primer verso
  display.clearDisplay();

  // segundo verso parte 1
  display.setCursor(0, 0);
  display.println(F("No tienes que"));
  display.setCursor(0, 10);
  display.println(F("recorrer el"));
  display.setCursor(0, 20);
  display.println(F("desierto de"));

  display.display();
  delay(2500);

  // borrar el segundo verso parte 1
  display.clearDisplay();

  // segundo verso parte 2
  display.setCursor(0, 0);
  display.println(F("rodillas,"));
  display.setCursor(0, 10);
  display.println(F("arrepitiendote."));

  display.display();
  delay(2500);

  // borrar el segundo verso
  display.clearDisplay();

  // tercer verso parte 1
  display.setCursor(0, 0);
  display.println(F("Solo deja que"));
  display.setCursor(0, 10);
  display.println(F("el suave animal"));
  
  display.display();
  delay(2500);

  // borrar tercer verso parte 1
  display.clearDisplay();

  // tercer verso parte 2
  display.setCursor(0, 0);
  display.println(F("de tu cuerpo"));
  display.setCursor(0, 10);
  display.println(F("ame lo que ama."));

  display.display();
  delay(2500);

  // borrar cuarto verso
  display.clearDisplay();

  // cuarto verso parte 1
  display.setCursor(0, 0);
  display.println(F("Hablame del dolor,"));
  display.setCursor(0, 10);
  display.println(F("del tuyo,"));
  display.setCursor(0, 20);
  display.println(F("yo te hablare del mio."));
  
  display.display();
  delay(2500);

  // borrar el cuarto verso
  display.clearDisplay();

  // quiento verso 
  display.setCursor(0, 0);
  display.println(F("Mientras tanto,"));
  display.setCursor(0, 10);
  display.println(F("el mundo sigue."));

  display.display();
  delay(2500);

}

#define XPOS   0 // Indexes into the 'icons' array in function below
#define YPOS   1
#define DELTAY 2

void testanimate(const uint8_t *bitmap, uint8_t w, uint8_t h) {
  int8_t f, icons[NUMFLAKES][3];

  // Initialize 'snowflake' positions
  for(f=0; f< NUMFLAKES; f++) {
    icons[f][XPOS]   = random(1 - LOGO_WIDTH, display.width());
    icons[f][YPOS]   = -LOGO_HEIGHT;
    icons[f][DELTAY] = random(1, 6);
    Serial.print(F("x: "));
    Serial.print(icons[f][XPOS], DEC);
    Serial.print(F(" y: "));
    Serial.print(icons[f][YPOS], DEC);
    Serial.print(F(" dy: "));
    Serial.println(icons[f][DELTAY], DEC);
  }

  for(;;) { // Loop forever...
    display.clearDisplay(); // Clear the display buffer

    // Draw each snowflake:
    for(f=0; f< NUMFLAKES; f++) {
      display.drawBitmap(icons[f][XPOS], icons[f][YPOS], bitmap, w, h, SSD1306_WHITE);
    }

    display.display(); // Show the display buffer on the screen
    delay(200);        // Pause for 1/10 second

    // Then update coordinates of each flake...
    for(f=0; f< NUMFLAKES; f++) {
      icons[f][YPOS] += icons[f][DELTAY];
      // If snowflake is off the bottom of the screen...
      if (icons[f][YPOS] >= display.height()) {
        // Reinitialize to a random position, just off the top
        icons[f][XPOS]   = random(1 - LOGO_WIDTH, display.width());
        icons[f][YPOS]   = -LOGO_HEIGHT;
        icons[f][DELTAY] = random(1, 6);
      }
    }
  }
}
```
Funciona pero falta automartizarlo.

### Licencia
El poema está bajo la licencia de copyright, donde todos los derechos están reservados, pero se puede utilizar bajo el concepto legal del uso legítimo, ya que es sin fines de lucro y con propósitos educativos.

```
"Proyecto académico / Fragmento de 'Wild Geese' por Mary Oliver / Uso educativo no comercial" 
© Wild Geese, 1986 Mary Oliver
```
