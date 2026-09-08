
char *versos[] = {
   "Hope is the thing with",
   "feathers",
   "That perches in the",
   "soul",
   "and sings the tune without the words",
   "and never stops",
   "at all..."

};
void setup() {

  Serial.begin(9600);

  // Inicializar pantalla OLED
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println("SSD1306 allocation failed");
    for (;;);
  }
}

void loop() {
 display.begin(versos);
Serial.println(versos[0]);
Serial.println(versos[1]);
Serial.println(versos[2]);
Serial.println(versos[3]);
Serial.println(versos[4]);
Serial.println(versos[5]);
Serial.println(versos[6]);
Serial.println(versos[7]);

}