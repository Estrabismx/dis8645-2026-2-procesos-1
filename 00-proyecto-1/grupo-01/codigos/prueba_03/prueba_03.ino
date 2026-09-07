#include <LiquidCrystal.h>

// versos del poema
const char *versosPoema[] = {
  "Cuando estan nuestras almas frente a frente,", 
  "mudas, erguidas, fuertes, ya muy proximas,",
  "y sus alas se encienden al tocarse,",
  "en cada punta curva ?que mal amargo",
  "puede hacernos la tierra, que no debiéramos",
  "quedarnos aqui, contentos? Piensalo. Al subir más alto,",
  "los angeles nos oprimirian y aspirarian",
  "a dejar caer algun aureo orbe de canto perfecto",
  "en nuestro hondo, querido silencio. Quedemonos",
  "mejor en la tierra, Amado mio, donde los animos",
  "contrarios e injustos de los hombres retroceden",
  "y aislan a los espiritus puros, y permiten",
  "un lugar donde estar y amar por un dia,",
  "con la oscuridad y la hora de la muerte rodeandolo."
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


// determinar dirección y calcular velocidad
// relacionada al desplazamiento del poema
  int direccion = 0; // variable asociada a si el texto avanza o retrocede
  int pausa = 0;
  int v = 0;
  int pos = 0; // variable que determina la posición del texto


// ----- inicio de funcionamiento ----

void setup() {
  
  Serial.begin(9600);
  lcd.begin(16, 2); //define el tamaño de la pantalla

  // --- texto inicial 1: textoInicialCC / Creative Commons BY - SA --- 

  lcd.setCursor(0, 0); //define la seccion superior de la pantalla
  for(int i = 0; i < 16 && textoInicialCC[i] != '\0'; i++) {
    lcd.print(textoInicialCC[i]);
  }
  lcd.setCursor(0, 1); //define la seccion inferior de la pantalla
  lcd.print(textoInicialCC + 16); 
  
  delay(4000); 
  lcd.clear();


  // --- texto inicial 2: Carrusel de textoInicialB en la fila inferior (0, 0) ---
  int largoB = strlen(textoInicialTitulo); // calculam el largo (35 letras)
  
  // calcula cuántos pasos debe avanzar para mostrarlo todo
  // si el texto es más corto de 16, no se mueve (0 pasos)
  int pasosTotales = (largoB > 16) ? (largoB - 16 + 3) : 0; // +3 para dejar unos espacios al final
  
  for(int pos = 0; pos <= pasosTotales; pos++) {
    lcd.setCursor(0, 0);
    
    // imprime la "ventana" de 16 caracteres
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
      delay(500); // velocidad del carrusel (350ms por letra)
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
 
  // ------ lectura pote --------
  // función para leer el potenciometro 
  // lectura de pin A0
  // conectar pin 2 de pote 
  // lectura va de 0 a 1024
  poteLectura = analogRead(potePatita);

  // division de lectura de pote
  // valor resultante va de 0 a 255
  poteFiltrado = filtrarConDivision(poteLectura, 4);

  // imprimir en el monitor serial el poteFiltrado
  Serial.print("valor filtrado ");
  Serial.println(poteFiltrado);
  // ------- fin lectura pote ---------

if (poteFiltrado >= 135) {
    direccion = 1; // Avanzar
    // Mapea desde 135 (el mínimo para avanzar) hasta 255 (velocidad máxima)
    pausa = map(poteFiltrado, 135, 255, 600, 50); 
  } 
  else if (poteFiltrado <= 120) {
    direccion = -1; // Retroceder
    // Mapea desde 120 (el mínimo para retroceder) hasta 0 (velocidad máxima en reversa)
    pausa = map(poteFiltrado, 120, 0, 600, 50); 
  } 
  else {
    direccion = 0; // Pausa / Zona muerta al centro (valores entre 121 y 134)
    pausa = 200;   // Pequeño delay de espera
  }

  // calcula el verso actual
  int totalVersos = sizeof(versosPoema) / sizeof(versosPoema[0]);
  int largoVerso = strlen(versosPoema[v]);
  int pasosTotales = (largoVerso > 16) ? (largoVerso - 16 + 3) : 0;

  //  imprimir el texto en la pantalla
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