#include <LiquidCrystal.h>

// versos del poema
char *versosPoema[] = {
  "Cuando estan nuestras almas frente a frente,", 
  "mudas, erguidas, fuertes, ya muy proximas,",
  "y sus alas se encienden al tocarse,",
  "en cada punta curva ¿qué mal amargo",
  "puede hacernos la tierra, que no debiéramos",
  "quedarnos aquí, contentos? Piénsalo. Al subir más alto,",
  "los ángeles nos oprimirían y aspirarían",
  "a dejar caer algún áureo orbe de canto perfecto",
  "en nuestro hondo, querido silencio. Quedémonos",
  "mejor en la tierra, Amado mío, donde los ánimos",
  "contrarios e injustos de los hombres retroceden",
  "y aíslan a los espíritus puros, y permiten",
  "un lugar donde estar y amar por un día,",
  "con la oscuridad y la hora de la muerte rodeándolo."
};

// corresponde a los pines que utiliza la pantalla 
// pantalla lcd verde 16 x 02 con controlador SPLC780D1 o HD44780
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// texto que se muestra al inciar el dispositivo
const char textoInicialCC[] = "[PLACEHOLDER] - CC BY-SA 4.0"; // licencia de uso, Creative Commons BY-SA 4.0
const char textoInicialTitulo[] = "Cuando nuestras dos almas se eleven"; // titulo del poema
const char textoInicialAutora[] = "Elizabeth Barret Brown"; // autora del poema


//------- variables pote ------
// variables y constantes
// para lectura potenciometro
const int potePatita = A0;
int poteLectura = -1;
int poteFiltrado = -1;

// funcion entera
// para tomar una variable entera original
// y dividirla por otro entero para perder resolucion
int filtrarConDivision(int valor, int divisor) {
  int resultado = valor / divisor;
  return resultado;
}
// ---- fin variables pote -----


// ----- inicio de funcionamiento ----

void setup() {
  
  Serial.begin(9600);
  lcd.begin(16, 2); //define el tamaño de la pantalla

  // --- texto inicial 1: textoInicialCC / Creative Commons BY - SA --- 

  lcd.setCursor(2, 0); //define la seccion superior de la pantalla
  for(int i = 0; i < 16 && textoInicialCC[i] != '\0'; i++) {
    lcd.print(textoInicialCC[i]);
  }
  lcd.setCursor(0, 1); //define la seccion inferior de la pantalla
  lcd.print(textoInicialCC + 16); 
  
  delay(4000); 
  lcd.clear();


  // --- texto inicial 2: Carrusel de textoInicialB en la fila inferior (0, 1) ---
  int largoB = strlen(textoInicialTitulo); // Calculamos el largo (35 letras)
  
  // Calculamos cuántos pasos debe avanzar para mostrarlo todo.
  // Si el texto es más corto de 16, no se mueve (0 pasos).
  int pasosTotales = (largoB > 16) ? (largoB - 16 + 3) : 0; // +3 para dejar unos espacios al final
  
  for(int pos = 0; pos <= pasosTotales; pos++) {
    lcd.setCursor(0, 1);
    
    // Imprimimos la "ventana" de 16 caracteres
    for(int i = 0; i < 16; i++) {
      if (pos + i < largoB) {
        lcd.print(textoInicialTitulo[pos + i]);
      } else {
        lcd.print(' '); // rellena con espacios en blanco cuando se acaba el texto
      }
    }
    
    // si esta en el primer cuadro (pos = 0), hace una pausa más larga
    // para que se pueda empezar a leer antes de que se mueva
    if (pos == 0) {
      delay(2000); 
    } else {
      delay(350); // velocidad del carrusel (350ms por letra)
    }
  }
  
  lcd.clear();


  // --- texto inicial 3: textoInicialC / autora---
  lcd.setCursor(0, 0);
  for(int i = 0; i < 16 && textoInicialAutora[i] != '\0'; i++) {
    lcd.print(textoInicialAutora[i]);
  }
  lcd.setCursor(0, 1);
  lcd.print(textoInicialAutora + 16); 
  
  delay(4000); 
  lcd.clear();
}

void loop() {
  // Variables estáticas para recordar la posición entre cada ciclo del loop
  static int v = 0;
  static int pos = 0;
  
  // ------ lectura pote --------
  poteLectura = analogRead(potePatita);
  poteFiltrado = filtrarConDivision(poteLectura, 4);

  Serial.print("valor filtrado ");
  Serial.println(poteFiltrado);
  // ------- fin lectura pote ---------

  // 1. Determinar dirección y calcular velocidad (pausa del delay)
  int direccion = 0;
  int pausa = 0;

  if (poteFiltrado > 127) {
    direccion = 1; // Avanzar
    // map() convierte el rango del pote (128 a 255) a un delay en milisegundos (ej: 600ms a 50ms)
    // Mientras más cerca del 255, menor es el delay (más rápido)
    pausa = map(poteFiltrado, 128, 255, 600, 50); 
  } else {
    direccion = -1; // Retroceder
    // Mientras más cerca del 0, menor es el delay (más rápido)
    pausa = map(poteFiltrado, 127, 0, 600, 50); 
  }

  // 2. Cálculos del verso actual
  int totalVersos = sizeof(versosPoema) / sizeof(versosPoema[0]);
  int largoVerso = strlen(versosPoema[v]);
  int pasosTotales = (largoVerso > 16) ? (largoVerso - 16 + 3) : 0;

  // 3. Imprimir el texto en la pantalla
  lcd.setCursor(0, 0);
  for (int i = 0; i < 16; i++) {
    if (pos + i < largoVerso && pos + i >= 0) {
      lcd.print(versosPoema[v][pos + i]);
    } else {
      lcd.print(' ');
    }
  }

  // 4. Aplicar la velocidad calculada
  delay(pausa);

  // 5. Actualizar la posición para el siguiente ciclo
  pos += direccion;

  // 6. Lógica para cambiar de verso si llegamos al límite (avanzando o retrocediendo)
  if (pos > pasosTotales) {
    // Si avanza más allá del verso actual, pasa al siguiente
    pos = 0;
    v++;
    if (v >= totalVersos) v = 0; // Vuelve al inicio si terminó el poema
    lcd.clear();
    delay(100); // Pausa visual al cambiar de línea
  } 
  else if (pos < 0) {
    // Si retrocede más allá del inicio, vuelve al verso anterior
    v--;
    if (v < 0) v = totalVersos - 1; // Va al último verso si retrocede desde el inicio
    
    // Recalcula el tamaño del nuevo verso para posicionarse al final de este
    largoVerso = strlen(versosPoema[v]);
    pasosTotales = (largoVerso > 16) ? (largoVerso - 16 + 3) : 0;
    pos = pasosTotales; 
    
    lcd.clear();
    delay(100);
  }
}