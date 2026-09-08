#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


char textoInicialA[] = "[PLACEHOLDER] - CC BY-SA 4.0";
char textoInicialB[] = "Cuando nuestras dos almas se eleven";
char textoInicialC[] = "ELIZABETH BARRETT BROWNING";

// ocurre al inicio una sola vez
void setup() {
  Serial.begin(9600);

  lcd.begin(16, 2);
}


//ocurre de manera repetida despues de setup
void loop(){

lcd.setCursor(0, 0);
  lcd.print(textoInicialA); // Imprimir en la primera línea
  
  // 5. Mover el cursor a la segunda línea (columna 0, fila 1)
  lcd.setCursor(0, 1);
  lcd.print(textoInicialB);    // Imprimir en la segunda línea

  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print(textoInicialC);
}