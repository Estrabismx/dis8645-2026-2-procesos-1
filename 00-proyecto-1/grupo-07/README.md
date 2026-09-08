# Proyecto-1 / grupo-07

Fecha entrega: 2026-09-11

## Integrantes:

Emilia Contreras / [hazzaily](https://github.com/hazzaily) 

Monserrat Paredes / [Monserrat-Paredes](https://github.com/Monserrat-Paredes) 

Katalina Riquelme / [riyakatalinaa](https://github.com/riyakatalinaa) 



---


## Poetisa escogida → **Alfonsina Storni**

Esta poetisa argentina nacida en 1892 en Suiza es uno de los íconos de la literatura posmodernista. Con una infancia difícil y con carencias y luego una vida con recurrentes enfermedades, su poesía está impregnada de lucha, audacia, amor y una reivindicación del género femenino. Algunos de sus poemas a resaltar son: ¡Adiós!, Alma desnuda, La caricia perdida, Razones y paisajes de amor, Queja, Tu dulzura, Dolor y Frente al mar.

Toda su obra refleja dramatismo, lucha y una audacia inusual para la época. Su temática es, sobre todo, amorosa, feminista y profunda, en donde se refleja un carácter singular, marcado muchas veces por la neurosis.

Su muerte, continúa la huella de su transgresora personalidad. Su trágico suicidio, en las aguas de la playa "La Perla", de Mar del Plata, el 25 de octubre de 1938, le permitió huir de una penosa enfermedad oncológica (crecimiento descontrolado y la multiplicación rápida de células anormales) y de la soledad que la invadía.

Información sacada de → https://www.poemas-del-alma.com/alfonsina-storni.htm#block-bio

## Licencia asociada a Alfonsina Storni

**Alfonsina Storni** nació en Suiza el 22 de Mayo de 1892 y murió el 25 de Octubre de 1938. Información rescatada de [Wikipedia](https://es.wikipedia.org/wiki/Alfonsina_Storni)

Y según la legislación Argentina [Ley 11723](https://www.argentina.gob.ar/normativa/nacional/42755/actualizacion?utm_source=chatgpt.com) después de 70 años del 01 de Enero del año siguiente la muerte de una persona, su obra se se vuelve de dominio público pagante, lo que significa que podría estar sujeta a que determinados usos de obras en dominio público pueden estar sujetos a declaración y al pago de un arancel ante el Fondo Nacional de las Artes. 

Para nuestra suerte, los 70 años se cumplieron en 2009, y la misma ley nos exenta de pagos debido a que en el artículo 36 nos dice que:

```
"Sin embargo, será lícita y estará exenta del pago de derechos de autor y de los intérpretes que establece el artículo 56, la representación, la ejecución y la recitación de obras literarias o artísticas ya publicadas, en actos públicos organizados por establecimientos de enseñanza, vinculados con el cumplimiento de sus fines educativos, planes y programas de estudio, siempre que el espectáculo no sea difundido fuera del lugar donde se realice y la concurrencia y la actuación de los intérpretes sea gratuita."
```

Así que podemos utilizar sus poemas con fines educativos.

## Poema escogido

Queja

Señor, mi queja es ésta,

Tú me comprenderás;

De amor me estoy muriendo,

Pero no puedo amar.

Persigo lo perfecto

En mí y en los demás,

Persigo lo perfecto

Para poder amar.

Me consumo en mi fuego,

¡Señor, piedad, piedad!

De amor me estoy muriendo,

¡Pero no puedo amar!.

Poema sacado de → https://www.cultura.gob.ar/9-poemas-imprescindibles-de-alfonsina-storni-8463/


### Análisis:

El poema expresa un conflicto interno entre el deseo de amar y la incapacidad de hacerlo. Ella se siente “muriendo de amor”, pero al mismo tiempo no logra entregarse emocionalmente porque busca constantemente la perfección, tanto en ella misma como en los demás.

Expresa un amor frustrado y posiblemente no correspondido, pero principalmente muestra un conflicto interno: el deseo de amar, pero su búsqueda de la perfección le impide entregarse al amor.

---

## Bill of Materials

|Componente|Cantidad|Precio|Link|
|---|---|---|---|
|Arduino UNO R4 WIFI|1|$32.990|<https://mcielectronics.cl/shop/product/arduino-uno-r4-minima/>|
|Pantalla LCD Oled 0,91" I2C|1|$3.990|<https://afel.cl/products/pantalla-lcd-oled-0-91?_pos=1&_sid=f1b122119&_ss=r>|
|Protoboard|1|$1.500|<https://afel.cl/products/mini-protoboard-400-puntos>|
|LEDS|3|$70|<https://afel.cl/products/diodo-led-5mm-ultrabrillante-rojo?_pos=10&_sid=9ca2bb29d&_ss=r>|
|Kit resistencias|3|$4.990|<https://afel.cl/products/kit-600-resistencias-1-4w-30-valores?_pos=1&_sid=aa6abbe0f&_ss=r>|
|cables|7|$1.000|<https://afel.cl/products/pack-20-cables-de-conexion-macho-macho>|
|Potenciómetro B10k|1|$500|<https://afel.cl/products/potenciometro-10k-ohm>|


---

## ¿Qué queremos que pase? (texto)

- Poner al comienzo el nombre de la poetisa Alfonsina Storni
- Cambio de dirección 1: Dirección inicial del texto (arriba hacia abajo)
- Cambio de dirección 2: de izquierda a derecha
- Que la velocidad del texto cambie según la perilla del potenciómetro (verso por verso).
- A través de un botón, tener la posibilidad de presionarlo y que se inviertan los colores mostrando las palabras claves representativas (palabras intensas).
- Que a ciertas palabras del poema se les pueda bajar o subir la opacidad con el potenciómetro.
- perfeccionismo = control = pausar/reanudar (botón)
- Cada palabra intensa que aparezca se encenderan leds rojos


## Paso a paso de que queremos que suceda

- Lo primero en proyectarse en la pantalla es el nombre de la poetisa "Alfonsina Storni"
- Se despliega la animación inicial con el nombre del poema "Queja"
- El poema comienza a proyectarse y avanza verso por verso de manera interactiva a medida que el usuario gira la perilla del potenciometro
- Al llegar a versos con palabras claves representativas (palabras intensas), el tamaño de la tipografía es mas grande que el resto del verso, para simular un efecto de "grito", esto hace que se enciendan 3 leds para intensificar estas palabras claves
- Despues de la primera estrofa, la pantalla reproduce una animación visual de un corazón roto expandiendose por la pantalla
- Entre medio de las dos primeras estrofas, la pantalla reproduce una animación visual de fuego subiendo de abajo hacia arriba



## Proceso código y registro (resumen)


El proyecto evolucionó progresivamente desde la reproducción de un poema en el monitor serial hacia una experiencia visual e interactiva, incorporando jerarquía tipográfica, control manual y animaciones vinculadas al contenido emocional de la obra.


## Evolución del proyecto

| Versión | Fecha | Etapa | Cambios principales | Objetivo |
|:---:|:---:|---|---|---|
| **Código 1** | 28 ago. | Poema base | Reproducción del poema en el **Serial Monitor**, mediante un loop. Código base modificado a partir del código entregado por el profesor. | Crear la primera versión funcional del poema. |
| **Código 2** | 1 sept. | Pantalla OLED | Se incorpora una pantalla **OLED 0,91" I2C**. El poema comienza a visualizarse físicamente y los versos cambian automáticamente cada 2 segundos. | Llevar el poema desde el monitor serial a una interfaz física. |
| **Código 3** | 2 sept. | Jerarquía visual | Se destacan determinadas **palabras clave e intensas** del poema mediante un tamaño mayor, mientras el resto mantiene un tamaño normal. | Representar visualmente la intensidad emocional del poema. |
| **Código 4** | 3 sept. | Interacción | Se incorpora un **potenciómetro** para controlar manualmente el avance de los versos, reemplazando el avance automático. | Dar al usuario control sobre el ritmo del poema. |
| **Código 4.2** | 3 sept. | Refinamiento visual | Se agrega el **nombre de la poetisa**, se centra y alinea el texto y se establece una jerarquía tipográfica: palabras clave de **16 px** y texto normal de **8 px**. | Mejorar la composición y legibilidad en pantalla. |
| **Código 5** | 4 sept. | Optimización | Se detectan problemas de espacio en pantalla. Se reduce la cantidad de palabras destacadas para asegurar que todos los versos sean visibles correctamente. | Adaptar definitivamente el poema al formato de la pantalla OLED. |
| **Código 5.2** | 4 sept. | Prueba de animación | Se incorpora una primera animación. El resultado no se adapta correctamente a las dimensiones de la pantalla. | Explorar la incorporación de movimiento y detectar limitaciones técnicas. |
| **Código 6** | 7 sept. | **Animación 1🎬** | Animación del título **“Queja”**, utilizada como introducción al poema. | Introducir visualmente la obra. |
| **Código 7** | 7 sept. | **Animación 2💔** | Animación de un **corazón roto**, vinculada al verso sobre la imposibilidad de amar. | Reforzar visualmente el significado emocional del poema. |
| **Código 8** | 7 sept. | **Animación 3 🔥** | Animación de **fuego**, relacionada con el verso donde la protagonista expresa que “se consume”. | Representar visualmente la intensidad y el consumo emocional. |




## Palabras claves representativas 

Como grupo decidimos destacar la parte emocional del poema, identificamos **palabras claves representativas** de mayor intensidad que actúan como puntos de mayor tensión.

Si bien todo el poema transmite una emoción constante, las **palabras claves** las representamos en un tamaño tipográfico más grande al resto del verso. Esta variación de escala busca simular visualmente la sensación de un **grito**, evitando el uso de mayúsculas para mantener la estética y ritmo del poema.

Como se puede apreciar en la imagen, las palabras subrayadas son las **palabras claves** que van en un tamaño mayor

![Captura de pantalla poema con palabras representativas](./imagenes/palabrasrepresentativas.png)

## Animaciones

Animación 1: después del nombre de la poetisa de Alfonsina Storni, titulo "Queja"

**imagen de la animación**

Animación 2: después de la primera estrofa, corazón roto

**imagen de la animación**


Animación 3: después de la segunda estrofa, fueguito

**imagen de la animación**

## Roles

- **Emilia:** encargada de las animaciones y sus respectivos códigos
- **Monserrat:** encargada de los códigos
- **Katalina:** encargada de registro en github
