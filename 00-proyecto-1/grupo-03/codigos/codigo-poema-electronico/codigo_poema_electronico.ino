/* Poema electronico — UNO R4 Minima / ST7789V 240x320 / SSD1306 128x32.
   Instalar: Adafruit GFX, Adafruit ST7735 and ST7789, Adafruit SSD1306
   y Adafruit BusIO. Leer LEEME.md antes de conectar los motores.
   Prototipo: texto y animaciones; no requiere tarjeta SD.
*/
#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>
#include <Adafruit_SSD1306.h>

constexpr uint8_t TFT_CS=10, TFT_DC=8, TFT_RST=7;
constexpr uint8_t POT=A0, BUTTON=2, BUTTON_LED=4;
constexpr uint8_t MOTOR_PINS[3]={3,5,6};
constexpr uint8_t UNUSED_MOTOR_PIN=9;
constexpr bool MOTORS_ENABLED=true; // Tres motores del montaje que el usuario confirma operativo.
constexpr uint8_t MOTOR_POWER=160;   // PWM 0..255; NO sustituye regular la fuente.
constexpr int POT_MIN=0, POT_MAX=1023, POT_DEADBAND=7;
constexpr int NAV_HYSTERESIS=4;
constexpr int END_TOLERANCE=7; // Margen ADC para reconocer los topes fisicos.
constexpr uint8_t SLOT_SCENE[12]={1,2,3,4,5,6,6,6,7,8,9,10};
constexpr uint32_t FRAME_MS=80, FAST_BLINK_DURATION_MS=1800;
constexpr uint32_t LED_NORMAL_MS=500, LED_FAST_MS=100; // Tiempo de cada estado ON/OFF.

Adafruit_ST7789 tft(TFT_CS,TFT_DC,TFT_RST);
Adafruit_SSD1306 oled(128,32,&Wire,-1);
GFXcanvas1 screen(320,240);
GFXcanvas1 wordCanvas(320,32);
uint16_t rgbRow[320];
uint32_t rowHash[240];
uint16_t backgroundColor=ST77XX_BLACK, foregroundColor=ST77XX_WHITE;
uint16_t lastBackground=ST77XX_BLACK, lastForeground=ST77XX_WHITE;
bool paletteChanged=false;
bool sceneVisited[11]={false}, sceneReentered=false;
bool firstFrame=true, oledOK=false, running=false, fatalError=false;
uint8_t scene=0;
uint32_t sceneStart=0, frameAt=0, buttonChanged=0, blinkStart=0;
bool buttonRaw=HIGH, buttonStable=HIGH, pressed=false, fastBlink=false;
bool interactionDone=false, navArmed=false, redraw=true, framePending=false;
int potFiltered=0, potAnchor=0, navSlot=0, revealStage=1, flushRow=0;
uint32_t potSampleAt=0;
bool repeatCycle=false, sweepForward=true, atPotEnd=false;
int endPeak=POT_MAX;

uint32_t noise(uint32_t n) {
  n ^= n >> 16; n *= 0x7feb352dUL; n ^= n >> 15;
  n *= 0x846ca68bUL; return n ^ (n >> 16);
}
float progress(uint32_t t,uint32_t start,uint32_t duration) {
  if(t<=start) return 0;
  if(t-start>=duration) return 1;
  return float(t-start)/duration;
}
int letters(const char *s) {
  int n=0; while(*s) { if((uint8_t(*s)&0xc0)!=0x80) ++n; ++s; } return n;
}
// Fuente basica con acentos dibujados: conserva el texto UTF-8 del poema.
void textAt(Adafruit_GFX &g,int x,int y,const char *s,int size=1,uint16_t ink=1) {
  while(*s) {
    uint8_t c=uint8_t(*s++); bool acute=false, tilde=false;
    if(c==0xc3 && *s) {
      uint8_t d=uint8_t(*s++);
      switch(d) {
        case 0xa1:c='a';acute=true;break; case 0xa9:c='e';acute=true;break;
        case 0xad:c='i';acute=true;break; case 0xb3:c='o';acute=true;break;
        case 0xba:c='u';acute=true;break; case 0x81:c='A';acute=true;break;
        case 0x89:c='E';acute=true;break; case 0x8d:c='I';acute=true;break;
        case 0x93:c='O';acute=true;break; case 0x9a:c='U';acute=true;break;
        case 0xb1:c='n';tilde=true;break; default:c='?';break;
      }
    }
    g.drawChar(x,y,c,ink,ink,size);
    if(acute) g.drawLine(x+2*size,y-size,x+3*size,y-2*size,ink);
    if(tilde) g.drawLine(x+size,y-size,x+4*size,y-size,ink);
    x+=6*size;
  }
}
void centered(Adafruit_GFX &g,int y,const char *s,int size=1,uint16_t ink=1) {
  textAt(g,(g.width()-letters(s)*6*size)/2,y,s,size,ink);
}
void eraseNoise(Adafruit_GFX &g,float amount,int x0,int y0,int w,int h,uint16_t ink=0) {
  uint32_t threshold=uint32_t(amount*65535.0f);
  for(int y=y0;y<y0+h;++y) for(int x=x0;x<x0+w;++x)
    if(amount>=1 || (noise(uint32_t(y)*401+x)&65535)<threshold) g.drawPixel(x,y,ink);
}
void collapse(Adafruit_GFX &g,int y,const char *s,int size,float p) {
  wordCanvas.fillScreen(0); textAt(wordCanvas,0,5,s,size);
  int w=letters(s)*6*size, h=8*size+5;
  int cx=g.width()/2, cy=y+h/2;
  for(int sy=0;sy<h;++sy) for(int sx=0;sx<w;++sx) {
    if(wordCanvas.getPixel(sx,sy) && (noise(sy*401+sx)&65535)>=p*65535.0f && p<1)
      g.drawPixel(cx+int((sx-w/2)*(1-p)),cy+int((sy-h/2)*(1-p)),1);
  }
}
void opening(Adafruit_GFX &g,uint32_t t,bool small) {
  if(t<3300) {
    int s=small?1:3;
    centered(g,small?6:85,"Este poema nada",s);
    centered(g,small?19:122,"puede resolver",s);
    if(t>1800) {
      float p=progress(t,1800,1500);
      eraseNoise(g,p,0,0,g.width(),g.height());
      for(int i=0;i<int(p*30);++i) {
        int x=noise(i+19)%g.width(),y=noise(i+77)%(g.height()-8);
        char digit[2]={char('0'+noise(i)%10),0}; textAt(g,x,y,digit);
      }
    }
  } else if(t<9000) {
    int s=small?1:2, cols=g.width()/(6*s), rows=g.height()/(8*s);
    float density=t<6000?progress(t,3300,2700):1-progress(t,6000,3000);
    for(int i=0;i<cols*rows;++i) {
      if((noise(i+3)&65535)<density*65535) {
        char digit[2]={char('0'+noise(i+21)%10),0};
        textAt(g,(i%cols)*6*s,(i/cols)*8*s,digit,s);
      }
    }
  } else centered(g,small?12:108,"sintax error",small?1:3);
}
void stopMotors() {
  for(uint8_t p:MOTOR_PINS) analogWrite(p,0);
  digitalWrite(BUTTON_LED,LOW); fastBlink=false;
}
void enterScene(uint8_t next,uint32_t now) {
  stopMotors(); sceneReentered=sceneVisited[next]; sceneVisited[next]=true;
  scene=next; sceneStart=now;
  interactionDone=false; redraw=true;
  Serial.print("Escena "); Serial.println(scene);
}
void updateButton(uint32_t now) {
  pressed=false; bool r=digitalRead(BUTTON);
  if(r!=buttonRaw) {buttonRaw=r;buttonChanged=now;}
  if(now-buttonChanged>=30 && r!=buttonStable) {
    buttonStable=r; if(r==LOW) pressed=true;
  }
}
void updateHaptics(uint32_t now) {
  if(scene!=8 || !running) { stopMotors(); return; }
  if(pressed) {
    fastBlink=true; blinkStart=now; interactionDone=true;
  }
  if(fastBlink && now-blinkStart>=FAST_BLINK_DURATION_MS) fastBlink=false;
  uint32_t blinkInterval=fastBlink ? LED_FAST_MS : LED_NORMAL_MS;
  uint32_t blinkTime=fastBlink ? now-blinkStart : now-sceneStart;
  digitalWrite(BUTTON_LED,(blinkTime/blinkInterval)%2==0 ? HIGH : LOW);
  for(uint8_t p:MOTOR_PINS)
    analogWrite(p,(buttonStable==LOW && buttonRaw==LOW && MOTORS_ENABLED) ? MOTOR_POWER : 0);
}
void navigate(uint32_t now) {
  if(now-potSampleAt<5) return;
  potSampleAt=now;
  potFiltered=(potFiltered+analogRead(POT))/2;
  bool atEnd=potFiltered<=POT_MIN+END_TOLERANCE || potFiltered>=POT_MAX-END_TOLERANCE;
  if(atEnd!=atPotEnd) {atPotEnd=atEnd;redraw=true;}
  // Iniciar en 1 incluso si el mando estaba en otro punto al encender.
  // Al primer movimiento se adopta su posicion absoluta.
  if(!navArmed) {
    if(abs(potFiltered-potAnchor)<POT_DEADBAND) return;
    navArmed=true;
  }
  int position=constrain(potFiltered,POT_MIN,POT_MAX);
  // Al devolver el mando desde 10, comenzar otro recorrido desde 2.
  // Basta invertir el giro: no exige alcanzar una lectura ADC extrema.
  if(scene==10) {
    if(sweepForward) endPeak=max(endPeak,position);
    else endPeak=min(endPeak,position);
    int retreat=sweepForward ? endPeak-position : position-endPeak;
    if(retreat>=POT_DEADBAND) {
      repeatCycle=true; sweepForward=!sweepForward;
      navSlot=0; revealStage=1; enterScene(2,now); return;
    }
  }
  int count=repeatCycle?11:12;
  int span=POT_MAX-POT_MIN+1;
  int value=position-POT_MIN;
  if(repeatCycle) {
    value=sweepForward ? position-POT_MIN : POT_MAX-position;
  }
  const long scaled=long(value)*count;
  int previous=navSlot;
  while(navSlot<count-1 && scaled>=long(navSlot+1)*span+NAV_HYSTERESIS*count) ++navSlot;
  while(navSlot>0 && scaled<long(navSlot)*span-NAV_HYSTERESIS*count) --navSlot;
  if(navSlot==previous) return;
  int tableSlot=navSlot+(repeatCycle?1:0);
  revealStage=tableSlot>=5 && tableSlot<=7 ? tableSlot-4 : 1;
  uint8_t target=SLOT_SCENE[tableSlot];
  if(target!=scene) {
    enterScene(target,now);
    if(target==10) endPeak=position;
  }
  redraw=true;
}
void render(uint32_t t) {
  screen.fillScreen(0); oled.clearDisplay();
  backgroundColor=ST77XX_BLACK; foregroundColor=ST77XX_WHITE;
  switch(scene) {
    case 1:
      opening(screen,t,false);
      
      
       break;
    case 2: {
      float p=progress(t,1800,4300);
      collapse(screen,60,"Adentro del poema,",2,p);
      collapse(screen,109,"la muerte",3,p); collapse(screen,151,"se consume.",3,p);
      
       break;
    }
    case 3: {
      if(t<8500) {
        centered(screen,34,"Ya, dilo de nuevo",2);
        if(t>=1800 || sceneReentered) {
          centered(screen,87,"El porcentaje de",2);
          centered(screen,115,"pureza mezclado",2);
          centered(screen,143,"con un poco de sol",2);
        }
        // Patron fijo, umbral creciente: cada pixel infectado queda blanco.
        // Tambien invade el contorno y los huecos de las letras hasta fundirlas con el fondo.
        float infection=progress(t,3500,5000);
        eraseNoise(screen,infection,0,0,320,240,1);
      } else if(t<9500) {
        // Un segundo completamente blanco, sin ningun verso.
        screen.fillScreen(1);
      } else {
        backgroundColor=ST77XX_WHITE; foregroundColor=ST77XX_BLACK;
        centered(screen,192,"Con un poco de hambre",2);
        float p=progress(t,10700,2500);
        // Se conserva la desintegracion del hambre sobre el fondo blanco.
        eraseNoise(screen,p,0,188,320,24,0);
      }
      break;
    }
    case 4:
      centered(screen,107,"Todo acaba aquí",3);  break;
    case 5:
      centered(screen,107,"Y de pronto no.",3);  break;
    case 6:
      centered(screen,61,"Un nuevo servidor,",2);
      if(revealStage>=2) centered(screen,105,"un poema electrónico,",2);
      if(revealStage>=3) centered(screen,155,"un mesías.",3);
      break;
    case 7: {
      const char *words[5]={"Poema","bajando","desde","el","cielo"};
      const int xs[5]={82,154,76,148,184};
      const int ys[5]={190,190,216,216,216};
      // Una palabra cada vez; las que llegan se quedan abajo en la TFT.
      for(int i=0;i<5;++i) {
        uint32_t start=uint32_t(i)*1200;
        if(t<start) continue;
        float p=progress(t,start,1100);
        int y=-20+int((ys[i]+20)*p*p);
        textAt(screen,xs[i],y,words[i],2);
      }
      break;
    }
    case 8:
      centered(screen,59,"Solo los elegidos",2);
      centered(screen,95,"contemplan su",2);
      centered(screen,131,"propia destrucción.",2);
      
      
      break;
    case 9: {
      centered(screen,99,"No, en serio",3); int phase=(t/450)%6;
      int count=phase<=3?phase:6-phase;
      for(int i=0;i<count;++i) screen.fillRect(140+i*18,141,5,5,1);
      break;
    }
    case 10:
      centered(screen,81,"Este poema nada",3);
      centered(screen,121,"puede resolver.",3);
        break;
  }
  // La OLED solo muestra la accion correspondiente a la escena actual.
  if(scene==8) {
    centered(oled,12,"Presiona el botón");
  } else if(scene==10 && atPotEnd) {
    centered(oled,7,"Girar potenciómetro");
    centered(oled,21,"hacia el otro lado");
  } else {
    centered(oled,12,"Girar potenciómetro");
  }
}
void present() {
  uint8_t *b=screen.getBuffer();
  // Se envian solo las filas modificadas, sin borrar la TFT entre fotogramas.
  if(!framePending) return;
  int limit=min(flushRow+8,240);
  for(int rowIndex=flushRow;rowIndex<limit;++rowIndex) {
    // Permutacion de filas: evita una frontera de barrido de arriba abajo.
    int y=(rowIndex*73)%240;
    uint32_t hash=2166136261UL;
    for(int i=0;i<40;++i) hash=(hash^b[y*40+i])*16777619UL;
    if(!firstFrame && !paletteChanged && hash==rowHash[y]) continue;
    rowHash[y]=hash;
    for(int x=0;x<320;++x) rgbRow[x]=(b[y*40+x/8]&(0x80>>(x&7)))?foregroundColor:backgroundColor;
    tft.startWrite(); tft.setAddrWindow(0,y,320,1);
    tft.writePixels(rgbRow,320); tft.endWrite();
  }
  flushRow=limit;
  if(flushRow==240) {firstFrame=false;framePending=false;}
}
void setup() {
  Serial.begin(115200); pinMode(BUTTON,INPUT_PULLUP); pinMode(BUTTON_LED,OUTPUT);
  analogReadResolution(10); analogWriteResolution(8);
  pinMode(UNUSED_MOTOR_PIN,OUTPUT); digitalWrite(UNUSED_MOTOR_PIN,LOW);
  for(uint8_t p:MOTOR_PINS) {pinMode(p,OUTPUT);analogWrite(p,0);}
  stopMotors(); potFiltered=potAnchor=analogRead(POT);
  tft.init(240,320); tft.setRotation(1); tft.setSPISpeed(8000000);
  tft.fillScreen(ST77XX_BLACK); Wire.begin();
  // Busca las dos direcciones usuales; begin() por si solo no detecta desconexion.
  uint8_t addr=0;
  for(uint8_t a=0x3c;a<=0x3d;++a) {
    Wire.beginTransmission(a); if(Wire.endTransmission()==0) {addr=a;break;}
  }
  if(addr) oledOK=oled.begin(SSD1306_SWITCHCAPVCC,addr);
  if(!screen.getBuffer() || !wordCanvas.getBuffer() || !oledOK) {
    fatalError=true; tft.setTextColor(ST77XX_WHITE); tft.setTextSize(2);
    tft.setCursor(8,60); tft.println("Revisar OLED / RAM");
    Serial.println("Fallo: OLED I2C o memoria."); return;
  }
  atPotEnd=potFiltered<=POT_MIN+END_TOLERANCE || potFiltered>=POT_MAX-END_TOLERANCE;
  running=true; enterScene(1,millis());
  render(0); oled.display(); paletteChanged=true;
  lastBackground=backgroundColor; lastForeground=foregroundColor;
  framePending=true; flushRow=0; redraw=false;
  present(); frameAt=millis();
}
void loop() {
  if(fatalError) {stopMotors();return;}
  uint32_t now=millis(); updateButton(now);
  navigate(now); updateHaptics(now);
  if(redraw || (!framePending && now-frameAt>=FRAME_MS)) {
    frameAt=now; render(now-sceneStart); oled.display();
    // Si se interrumpe un cambio de paleta, completar la siguiente con todas sus filas.
    paletteChanged=(framePending && paletteChanged) || backgroundColor!=lastBackground || foregroundColor!=lastForeground;
    lastBackground=backgroundColor; lastForeground=foregroundColor;
    framePending=true; flushRow=0; redraw=false;
  }
  // Transferencias cortas para volver a leer mando y boton entre bloques.
  present();
}
