/* 
 * ============================================================================
 * CONTROL DE PANTALLA LCD 16x2 - ARDUINO UNO R4 WIFI
 * Controlador: SPLC780D1 / HD44780
 * ============================================================================
 */

// 1. INCLUSIÓN DE LIBRERÍAS
// Esta librería contiene todas las funciones necesarias para hablar con el controlador de la pantalla.
#include <LiquidCrystal.h>

// 2. CONFIGURACIÓN DE PINES (Variables Editables)
// Aquí definimos a qué pines digitales del Arduino UNO R4 WiFi conectaremos los pines de datos de la LCD.
// Puedes editar estos números si decides conectar los cables en otros pines digitales (ej. cambiar el 12 por un 8).
const int rs = 12; // Pin RS (Register Select) de la LCD conectado al pin 12 del Arduino
const int en = 11; // Pin EN (Enable) de la LCD conectado al pin 11 del Arduino
const int d4 = 5;  // Pin D4 de la LCD conectado al pin 5 del Arduino
const int d5 = 4;  // Pin D5 de la LCD conectado al pin 4 del Arduino
const int d6 = 3;  // Pin D6 de la LCD conectado al pin 3 del Arduino
const int d7 = 2;  // Pin D7 de la LCD conectado al pin 2 del Arduino

// 3. CREACIÓN DEL OBJETO LCD
// Se inicializa la librería pasando como parámetros las variables de los pines que definimos arriba.
// El orden de las variables debe mantenerse estrictamente así: (RS, EN, D4, D5, D6, D7).
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// 4. CONFIGURACIÓN INICIAL (Se ejecuta una sola vez al encender o reiniciar el Arduino)
void setup() {
  
  // lcd.begin(columnas, filas);
  // Esta función le dice al Arduino las dimensiones de tu pantalla. 
  // Editable: Si en el futuro usas una pantalla de 20x4, cambiarías a lcd.begin(20, 4);
  lcd.begin(16, 2);

  // lcd.setCursor(columna, fila);
  // Mueve el cursor donde empezará a escribirse el texto. Ambas posiciones empiezan a contar desde el cero.
  // (0, 0) significa: primera columna (0), primera fila (0).
  lcd.setCursor(0, 0);
  
  // lcd.print("Texto");
  // Imprime el texto directamente en la pantalla a partir de donde dejamos el cursor.
  // Editable: Puedes cambiar "Prueba LCD" por cualquier mensaje (máximo 16 caracteres por fila).
  lcd.print("Prueba LCD");

  // Movemos el cursor a la primera columna (0) de la segunda fila (1).
  lcd.setCursor(0, 1);
  
  // Imprimimos el segundo mensaje.
  lcd.print("Sistema OK");
}

// 5. BUCLE PRINCIPAL (Se ejecuta en ciclo infinito)
void loop() {
  // Como solo queremos mostrar un mensaje estático, dejamos el loop vacío.
  // Aquí es donde agregarías código si quisieras que el texto parpadee, se desplace (scroll)
  // o si quisieras actualizar la pantalla con lecturas de un sensor o de la conexión WiFi.
}