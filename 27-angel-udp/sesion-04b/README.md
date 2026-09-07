# sesion-04b

04-09-2026

## apuntes sesión

Sesión 04B

En esta sesión el grupo continuó trabajando en la propuesta del poema y en cómo llevarlo a una experiencia interactiva.

Uno de los aprendizajes fue reconocer las limitaciones del hardware que estamos utilizando, en esoecial al intentar trabajar con dos pantallas y contenido en video.

Debido a estas dificultades y al tiempo disponible para desarrollar el proyecto, se decidió priorizar el uso de imágenes en lugar de videos, dejando el storyboard como una guía para organizar la experiencia visual.

A partir del poema se fueron definiendo distintas formas de representar cada fragmento.

La idea es mostrar las imágenes, las animaciones y los elementos físicos de la instalación que ayuden a transmitir el significado o la interpretación que tenemos de cada parte.

Algunas de las propuestas que se plantearon fueron:

- “Este poema nada puede resolver”: representar lo cotidiano y la vida de las personas mediante fotografías, relacionándolo con la idea de que el arte muchas veces es cuestionado por no tener una utilidad práctica.
- “Adentro del poema, la muerte se consume”: representar la desaparición o desintegración de imágenes, haciendo que estas den paso a las palabras.
- “Porcentaje de pureza mezclado con un poco de sol. Con un poco de hambre”: relacionar esta parte con elementos naturales y cotidianos. Se propuso utilizar letras hechas a mano y mostrarlas progresivamente.
- “Todo acaba aquí” / “Y de pronto no”: aprovechar las dos pantallas para generar una interacción entre ambas, haciendo que el mensaje aparezca primero en una y luego en la otra.
- “Un nuevo servidor, un poema electrónico, un mesías”: utilizar imágenes relacionadas con la tecnología y la transmisión de información, generando una sucesión rápida de imágenes hasta destacar la palabra “MESÍAS”.
- “Poema bajando desde el cielo”: trabajar una interpretación relacionada con lo celestial o bíblico, para posteriormente contrastarla con una representación más caótica.
- “Solo los elegidos contemplan su propia destrucción”: representar la destrucción mediante una reacción física de la instalación. Se descartaron ideas como dañar componentes y se optó por utilizar motores vibratorios, ya que permiten generar una sensación de caos sin destruir el hardware.
- Finalmente, “No, en serio” y la repetición de “Este poema nada puede resolver” permitirían cerrar la experiencia y generar un ciclo o bucle.

Otro cosa importante de la clase fue comenzar a investigar cómo implementar físicamente la vibración.

Se descubrió que el motor no debería conectarse directamente al Arduino para controlar su potencia, por lo que se consideró utilizar un MOSFET mediante el módulo HW-517 V0.0.1. Este módulo permite controlar el motor y recibir la señal desde el Arduino, mientras que el motor utiliza una fuente de alimentación externa.

Las conexiones principales del módulo son:

- OUT+ / OUT-: conexión del motor.
- GND / TRIG-PWM: conexión con el Arduino.
- VIN+ / VIN-: conexión a la fuente de alimentación externa.

También se comenzó a trabajar en un código que permita controlar la intensidad del motor mediante PWM, utilizando valores entre 0 y 255.

Lo que queremos hacer es poder probar diferentes niveles de vibración y colocar después cuál funciona mejor para la experiencia del poema.

Finalmente, quedó pendiente decidir cómo controlar el sistema.

Nos planteamos utilizar botones o un potenciómetro.

Los botones podrían ser una alternativa más ordenada para controlar momentos específicos del poema y facilitar que la experiencia pueda repetirse desde el final. También se planteó la posibilidad de utilizar cuatro motores, para generar una vibración más notoria dentro de la instalación.

Aprendizaje de la sesión

Lo que resalto de esta sesión es que el proyecto consiste en representar visualmente el poema y en buscar una forma de traducir las ideas a diferentes estímulos.

Las limitaciones técnicas también influyen en las decisiones creativas, por lo que tuvimos que priorizar una propuesta que podamos realizar correctamente con el hardware y el tiempo disponible. Además, entendí que elementos físicos como la vibración pueden complementar las imágenes y el texto para hacer que el poema se experimente de una manera más interactiva y no solamente se observe en una pantalla.

Por ahora, los materiales que se están considerando son motores vibratorios, módulos HW-517, una fuente de alimentación externa, Arduino o Raspberry Pi Pico 2 W y botones o un potenciómetro, dependiendo de las pruebas que realicemos.

## encargos

## lectura

La lectura se revisa cada martes así que está puesta en la siguiente sesión (carpeta 05a)