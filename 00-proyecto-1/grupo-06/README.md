# Proyecto 01

![imagenes](./imagenes/poema-puerto-adelante.gif)

**Integrantes:**

*Antonia Loch (antoloch)*

*Anais Marschhausen (anaisbmg)*

*Hugo Montoya (hugosantos)*

*Carla Nuñez (ccarlabelenn)*

*Natalia Pilar (szmada)*

## Descripción de proyecto 

**"Irse y no volver..."** nació como nuestra primera aproximación a la programación dentro del taller, el desafío era elegir un poema y encontrar la forma de traducirlo a un objeto físico e interactivo, usando código. Elegimos un fragmento de Puerto adelante, de Alejandra Pizarnik, y detrás de esa elección hubo que resolver, cómo convertir un verso en algo programable.

El proyecto corre en un Arduino Uno R4 WiFi y despliega el poema en una pantalla OLED SSD1306 (128x32, I2C), controlado por un potenciómetro y un botón pulsador. Técnicamente, el código está organizado como una máquina de estados `(enum ModoOperacion)` que alterna entre dos formas de recorrer el poema: un modo manual, donde `analogRead()` sobre el potenciómetro se mapea matemáticamente a 7 páginas del texto `(valor * NUM_PAGINAS / 1024)`, y un modo demo, donde cada verso avanza solo según duraciones propias definidas en un arreglo `(DURACIONES_PAGINA)`.

Todo el temporizado del programa, el cambio de página, la animación del texto y los cuadros del barco se maneja sin usar `delay()`, mediante el patrón de timing no bloqueante basado en `millis()`, lo que permite que el botón y el potenciómetro sigan respondiendo en todo momento. El botón, además, pasa por una rutina de debounce por software para filtrar el rebote eléctrico y detectar una sola pulsación real.

El efecto visual más particular es el texto ondulando letra por letra, como si flotara sobre el mar, se logra dibujando cada carácter por separado y desplazándolo verticalmente con una función seno desfasada según su posición `(sin(fase + i * 0.65))`, donde fase avanza con el tiempo para que la ola nunca se detenga. La animación final del barco, en cambio, no usa gráficos vectoriales: son 4 bitmaps monocromos codificados y almacenados en memoria flash `(PROGMEM)` para no saturar la RAM del microcontrolador.

> Este proyecto fue el primer lugar donde entendimos que programar también es una forma de leer e interpretar un texto.

