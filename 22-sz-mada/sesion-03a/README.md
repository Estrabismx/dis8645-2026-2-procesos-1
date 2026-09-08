# sesion-03a

2026.08.25

## apuntes sesión

misaaaa vuelve la próxima semana yipee

---

Aarón nos entregó protoboards de 400 puntos, una por cada integrante del grupo (en nuestro caso, 3 protoboards). También recibimos cuatro? botones táctiles, cables, un lector? adaptador? microSD, y una pantalla OLED de 0.91in

![Protoboards](./imagenes/protoboards.jpg)

![Botones táctiles](./imagenes/botones.jpg)

![Cables](./imagenes/cables-h.jpg)

![Cables](./imagenes/cables-m.jpg)

![Lector MicroSD](./imagenes/lector-microsd.jpg)

![Pantalla OLED 0.91in](./imagenes/pantalla-oled.jpg)

SDA = señal de datos

SCK/SCL = señal de clock

---

En Arduino IDE instalamos la biblioteca de SSD1306 de Adafruit

![Adafruit SSD1306](./imagenes/arduino-ssd1306.png)

```#define``` sirve para poner un término en palabras seguido por un valor numérico, el cual será automáticamente "traducido" a lo largo del código; meaning si dice ```#define SCREEN_WIDTH 128```, puedo escribir SCREEN_WIDTH múltiples veces a lo largo del código, e internamente siempre se va a "traducir" a 128

SCL bigger #, SDA smaller one duh.

## lectura

Me llama mucho la atención la frase

> Being is "always already" a question of emobodied perception in the world because being begins on the material ground of anonymous and depersonalized sensation

Existir ya implica percibir y experimentar el mundo desde nuestro cuerpo, lo que me hace pensar "¿hasta qué punto nuestra forma de entender la realidad depende de las herramientas que usamos para medirla?" Si cada vez usamos más tecnología para interpretar lo que vemos, oímos o sentimos, podría esa tecnología terminar cambiando nuestra percepción de la realidad?

La filosofía de la tecnología de Heidegger: la distinción entre la tecnología entendida como una herramienta, y la *techné* (crear, revelar, o hacer aparecer algo). Crear no es simplemente fabricar algo desde cero, sino perimitir que algo llegue a manifestarse eg. Una semilla que se convierte en árbol
