// Control de motor vibratorio JQ24-35E360 vía HW-517
// Entrada de comandos por Monitor Serie

const uint8_t MOTOR_PIN = 9;
int currentDuty = 0;

void printHelp() {
  Serial.println(F("\n--- CONTROL DE MOTOR VIBRATORIO ---"));
  Serial.println(F("Comandos:"));
  Serial.println(F("  0 a 255 : Ajusta el valor PWM directamente"));
  Serial.println(F("  s       : Detiene el motor (PWM = 0)"));
  Serial.println(F("  m       : Potencia máxima (PWM = 255)"));
  Serial.println(F("  p       : Ejecuta una secuencia de pulsos (alerta)"));
  Serial.println(F("  ?       : Muestra este menú"));
  Serial.println(F("-----------------------------------\n"));
}

void setup() {
  pinMode(MOTOR_PIN, OUTPUT);
  analogWrite(MOTOR_PIN, 0);

  Serial.begin(115200);
  // Espera a que el puerto USB nativo del R4 se enlace (máximo 3 s)
  while (!Serial && millis() < 3000);

  printHelp();
  Serial.print(F("Estado: Apagado (0/255)\n> "));
}

void loop() {
  if (Serial.available() > 0) {
    char firstChar = Serial.peek();

    if (isDigit(firstChar)) {
      int value = Serial.parseInt();
      currentDuty = constrain(value, 0, 255);
      analogWrite(MOTOR_PIN, currentDuty);

      Serial.print(F("PWM fijado en: "));
      Serial.print(currentDuty);
      Serial.print(F(" ("));
      Serial.print((currentDuty * 100) / 255);
      Serial.println(F("%)"));
    } 
    else {
      char cmd = Serial.read();
      
      if (cmd == '\n' || cmd == '\r' || cmd == ' ') return;

      switch (cmd) {
        case 's':
        case 'S':
          currentDuty = 0;
          analogWrite(MOTOR_PIN, 0);
          Serial.println(F("Motor detenido (0%)"));
          break;
        case 'm':
        case 'M':
          currentDuty = 255;
          analogWrite(MOTOR_PIN, 255);
          Serial.println(F("Potencia máxima (100%)"));
          break;
        case 'p':
        case 'P':
          Serial.println(F("Disparando patrón de alerta..."));
          for (int i = 0; i < 3; i++) {
            analogWrite(MOTOR_PIN, 220);
            delay(120);
            analogWrite(MOTOR_PIN, 0);
            delay(80);
          }
          analogWrite(MOTOR_PIN, currentDuty); 
          Serial.println(F("Patrón finalizado"));
          break;
        case '?':
        case 'h':
        case 'H':
          printHelp();
          break;
        default:
          Serial.print(F("Comando no reconocido: '"));
          Serial.print(cmd);
          Serial.println(F("'. Escribe '?' para ver las opciones."));
          break;
      }
    }
    while (Serial.available() > 0 && (Serial.peek() == '\n' || Serial.peek() == '\r')) {
      Serial.read();
    }
    Serial.print(F("> "));
  }

