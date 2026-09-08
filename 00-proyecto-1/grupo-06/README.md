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

## Poema

**Sobre el poema**

No incluimos el poema completo por derechos de autor, solo el fragmento que da forma a esta instalación.

> "Irse y no volver... / puerto adelante"
— Alejandra Pizarnik



## Licencia 

Al ser una edición colombiana, buscamos en la Fundación Pública de Colombia sobre la ley de los derechos de autor, [webFundaciónPublica](https://www.funcionpublica.gov.co/eva/gestornormativo/norma.php?i=3431) La ley 23 de 1982 que está en vigencia, los temas son de derechos de autor y dirección nacional de derechos de autor.

> “ARTÍCULO 31.- Es permitido citar a un autor transcribiendo los pasajes necesarios, siempre que éstos no sean tantos y seguidos que razonadamente puedan considerarse como una reproducción simulada y sustancial, que redunde en perjuicio del autor de la obra de donde se toman. En cada cita deberá mencionarse el nombre del autor de la obra citada y el título de dicha obra.” (Departamento Administrativo de la Función Pública, 28 Enero 1982, artículo 31). 

Además buscamos la información de Chile sobre los derechos de autor

[bibliotecaDelCongresoNacionalDeChile](https://www.bcn.cl/leychile/navegar?idNorma=28933) Ley 17336 sobre la propiedad intelectual y derechos de autor de 1970

>  “    Artículo 71 M. Es lícito, sin remunerar ni obtener autorización del autor, reproducir y traducir para fines educacionales, en el marco de la educación formal o autorizada por el Ministerio de Educación, pequeños fragmentos de obras o de obras aisladas de carácter plástico, fotográfico o figurativo, excluidos los textos escolares y los manuales universitarios, cuando tales actos se hagan únicamente para la ilustración de las actividades educativas, en la medida justificada y sin ánimo de lucro, siempre que se trate de obras ya divulgadas y se incluyan el nombre del autor y la fuente, salvo en los casos en que esto resulte imposible. ” (Biblioteca Del Congreso Nacional De Chile, 2 Octubre 1970, artículo 71 M).

En este trabajo utilizaremos un pequeño fragmento del poema Puerto Adelante de Alejandra Pizarnik, como no podemos exponer el poema completo utilizaremos un breve contexto sobre una persona que en una noche tranquila, observa el puerto que desea escapar y desaparecer.
Con el fragmento podemos explicar y complementar la actividad de nuestra solemne 01, por la cual no habrá ganancia monetaria, sin ánimo de lucro. Solo existirá ganancia de conocimiento.


