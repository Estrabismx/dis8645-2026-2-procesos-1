# sesion-04a

## apuntes sesión

En esta sesión estuve algo desconectada la verdad, debido a la presión que traia esta semana al tener solemnes teoricas

Eso no quita que no se haya avanzado.

<br>

Nos enfocamos en coordinar el trabajo para optimizar el flujo de trabajo.

Dentro de esto se logró poder mostrar el visualizar el poema en la pantalla, sumado a al texto inicial que ya teniamos.

[![video](./imagenes/vid03.png)](https://youtube.com/shorts/GtjCxBL5BN4)

Despues de poder realizar este avance coordinamos y definimos algunos elementos claves que se necesitan para poder continuar

Lo primero fue hacer un bosquejo rapido de un diagrama o esquema que visualice el como se organiza el código

![esquema](./imagenes/esquema.jpg)

Este bosquejo algo simple lo complementamos con un documento de Google en el que llenamos y editamos constantemente de información, puede que no este del todo organizada. Pero tener un espacio para _croquear_ ideas siempre es bienvenido

[Google Docs](https://docs.google.com/document/d/1TkxkQKpXDaEGLvpUC6IY6PuDvOUBj7Xw5MtOkGehuNY/edit?usp=sharing)

<br>

Además, se nos eneseño un elemento que estuve ojeando en algunos proyectos de Arduino

```cpp

#include <biblioteca.h>

```

Esta línea nos indica que se hace un llamado a una bibliteca (se caracterizan por la extensión _.h_).

> Es importante diferencia biblioteca de librería
>
> En una librería se rige la transacción de dinero, en cambio en una biblioteca no existe un beneficio económico
>
>> biblioteca = library =/= libreria

Y una biblioteca en este contexto consta de un conjunto de código que uno puede adjuntar. Un ejemplo de esto es buscar una receta de berlines, se nos enseña a hacer la masa y cocinar, pero el relleno es una receta anexa que se menciona, más no se define. Esto tiene la finalidad de poder optimizar y disminuir la cantidad de líneas de código existente. En simples palabras es oficio digital

El avance en clase fue ese por mi parte, ha sido una semana intensa, independiente de ser día martes la verdad

## encargos

Como grupo definimos encargos internos.

En estos me encargue de completar la documentación de proyecto-01. Además de esto investigue y trate de analizar una lógica para implementar un potenciómetro

---

### Potenciómetro

Para poder implementarlo considere el ejemplo que vimos hace algunas sesiones.

El plan es conectar el pin 2 de un pote en A0, es decir, poder tener una lectura de este elemento

La idea es que según el valor asignado (el cual ya sabemos que van de 0 a 1023) poder relacionarlo a 2 acciones: avanzar y retroceder

Por lo que:

- Si el valor de lectura del pote es < 512, el texto debe avanzar

- Si el valor de lectura del pote es => 511, el texto debe retroceder

- En ambos casos, la velocidad de desplazamiento debe aumentar según nos alejemos de los valores mencionados

## lectura

Se repite el tópico expuesto antes, he estado muy cansada, por lo que he leído no es mucho

- Complex Number Calculator

En lo poco que leí del capítulo nos plantea una situación que ha sido una constante, la necesidad de calcular y resolver operaciones matemáticas. 

En este caso, utilizando la matemática booleana mediante el uso de tubos de vacio, los antepasados de los transistores

Siguiendo con esta línea, me hace pensar en como los negociones poseen calculadoras bastante básicas, pero con más poder de procesamiento que las computadoras que llevaron al hombre a la luna. En ese tiempo las máquinas de calcular no eran lo suficiente avanzadas como para optimizar los flujos de trabajo.

Hoy en día damos por hecho que la electrónica que nos rodean es bastante simple, pero esta a avanzado a pasos agintados, este libro me ha dado especial atención a como esto a ocurrido