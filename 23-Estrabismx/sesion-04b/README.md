# sesion-04b

## apuntes sesión

En esta sesión tuvimos 2 instancias:

1. Tuvimos una pequeña revisión grupo a grupo por parte de [@misaaaaaa](https://github.com/misaaaaaa) y [@emiguerra](https://github.com/emiguerra), ya que misaaaaaa volvio luego de un mes en Suiza haciendo una _residencia_ .

    Por lo mismo, revisamos los procesos y oportunidades que se pueden llegar a lograr. Muchas de estas se llegan mediante el trabajo organizado y lo más fundamental, el uso del lenguaje.

Además de hablar sobre como el lenguaje abre puertas, hicimos un pequeño _check list_ sobre el proyecto-1. En este mencionamos nuestro concepto central y como implementamos diversas funciones

Hay que entender que esta máquina que visualiza poemas posee 6 estados:

- **Texto Inicial**: Ocurre una sola vez al inicio y muestra el nombre y licencia del proyecto, además del nombre de la autora y del poema
- **Poema original avanzando**: Se visualiza `versosPoema[]` avanzando de manera ordenada
- **Poema original avanzando**: Se visualiza `versosPoema[]` retrocediendo verso por verso
- **Poema original congelado**:  `versosPoema[]` detiene su desplazamiento y queda estático al presionar un solo botón
- **Palabra clave de cada verso**: Aparece una palabra o frase relacionada al verso que se estaba visualizando. Esta aparecera al presionar 2 botónes de manera simultanea por menos de 2 segundos y durará 3 segundos en pantalla
- **Nuevo poema**: El poema es reemplazado por otro, que está creado a partir de palabras del poema original. Será visible siempre que ambos botónes se activen en simultaneo por más de 2 segundos, desaparece si se deja de presionar uno de los botónes

Luego de explicar el funcionamiento y los tipos de estados, pasamos a la demostración técnica de los avances que llevabamos en ese momento

[![poema](/00-proyecto-1/grupo-01/imagenes/vid03.png)](https://youtube.com/shorts/GtjCxBL5BN4)

En dicho video se aprecia como tenemos impletada la lógica para el funcionamiento de un potenciómetro.

<br>

2.  Una gran parte de la sesión (realmente el día), fue la implementación de 2 botones que cumplan los puntos anteriores. Debido a la complejidad que requería estos elementos, se tuvo que realizar una iteración algo mayor que en otras ocasiones.

    Presentamos los siguientes problemas:

- **No existia detección de uno o los 2 botónes**: Acá existían diversos motivos de estos, por ejemplo

    - Mal conexión del pin de lectura del Arduino al botón
    >En una ocasión no se le indicaron que pines queriamos utilizar para que el código detectara los botónes, por lo que se asignaron de manera "_aleatoria_" (nada es realmente aleatorio con la IA :p) y dificultó identificar el problema hasta que se leyó el código

    - PullUp / PullDown
    > Existio confusión sobre estos conceptos y se asumio que la IA identificó que estabamos configurando una resistencia en modo PullDown. Obviamente esto no fue así, por lo que se edito manualmente esa declaración de variable
    >
    > > A veces es tan satisfactorio decir: "_te lo dije_", pero es importante mantener humildad electrónica en estos contextos, a todos nos puede pasar (he cometido más errores de los que puedo recordar)

    - Erronea colocación pin lectura en protoboard
    > Error de novato y clásico, el pin que debía leer el botón (conectado en el Arduino al mismo lugar que lo indicaba el código), estaba conectado a la nada en la protoboard

<br>

[![error](/00-proyecto-1/grupo-01/imagenes/vid04.png)](https://youtube.com/shorts/WJUcuQjkYJc?feature=share)

<br>

Finalmente nos dedicamos en el resto del día a solucionar temas más ligados a la experiencia de usuario, ya que el texto a ratos no se entendia que cambiaba, las ventanas de tiempo eran muy cortas para activar las acciones y conflictos para que ambos botones se presionen en simultaneo...

## encargos

Nuestro encargo autogestionado fue terminar carcasa y "_sacar las pelusas del código_"

Por obvios motivos de enfocarme en la entrega de [_proyecto1_](/00-proyecto-1/grupo-01/README.md.) no pude extender toda lo que hubiese querido. De igual manera, en el README.md adjuntado se encontrará muchisima información correspondiente al proceso

## lectura
