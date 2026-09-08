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

void setup() {
  lcd.begin(16, 2); //define el tamaño de la pantalla

  // --- PANTALLA 1: textoInicialCC / Creative Commons BY - SA --- 

  lcd.setCursor(0, 0); //define la seccion superior de la pantalla
  for(int i = 0; i < 16 && textoInicialCC[i] != '\0'; i++) {
    lcd.print(textoInicialCC[i]);
  }
  lcd.setCursor(0, 1); //define la seccion inferior de la pantalla
  lcd.print(textoInicialCC + 16); 
  
  delay(4000); 
  lcd.clear();


  // --- PANTALLA 2: Carrusel de textoInicialB en la fila inferior (0, 1) ---
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
        lcd.print(' '); // Rellena con espacios en blanco cuando se acaba el texto
      }
    }
    
    // Si estamos en el primer cuadro (pos = 0), hacemos una pausa más larga
    // para que el usuario pueda empezar a leer antes de que se mueva.
    if (pos == 0) {
      delay(2000); 
    } else {
      delay(350); // Velocidad del carrusel (350ms por letra)
    }
  }
  
  lcd.clear();


  // --- PANTALLA 3: textoInicialC ---
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
  // Se comienza a visualizar el poema como una sola línea de texto 
  // que avanza, tal y como lo hace un carrete de película
  // al finalizar el poema, vuelve a reproducirse desde el inicio

  int totalVersos = sizeof(versosPoema) / sizeof(versosPoema[0]);

  for (int v = 0; v < totalVersos; v++) {
    int largoVerso = strlen(versosPoema[v]);
    int pasosTotales = (largoVerso > 16) ? (largoVerso - 16 + 3) : 0;

    for (int pos = 0; pos <= pasosTotales; pos++) {
      lcd.setCursor(0, 0);

      for (int i = 0; i < 16; i++) {
        if (pos + i < largoVerso) {
          lcd.print(versosPoema[v][pos + i]);
        } else {
          lcd.print(' ');
        }
      }

      if (pos == 0) {
        delay(1500);
      } else {
        delay(300);
      }
    }
    delay(800);
    lcd.clear();
  }
}