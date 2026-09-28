# sesion-06a

## apuntes sesión


Variables y tipos de datos


Explicaron que `int` vendría siendo una variable. Como metáfora: si vas al súper tienes que pensar **cómo y dónde llevarte lo que compraste**.

Si compras un chicle, lo puedes llevar en el bolsillo. Pero si compras una tabla de tres metros de madera, necesitas un flete sí o sí (o una camioneta, obvio).

¿Podrías llevarte el chicle en un flete? Sí, pero sería ineficiente. De la misma manera, tenemos que elegir el tipo de dato según lo que necesitamos guardar.



### `int`

`int` funciona con números antes y después del cero.

Por ejemplo:

```cpp
int edad = 23;
```

También existe `uint`, que mueve el cero al inicio, por lo que solamente permite aumentar.

La idea es elegir el tipo de dato que corresponde según lo que necesitamos guardar, para no utilizar más espacio del necesario.



### `bool`

`bool` es un tipo de dato muy pequeño.

Aaron lo comparó con **el bolsillo dentro del bolsillo del jeans** jiji

Sirve para valores que pueden ser solamente dos opciones 0 1, como:

```cpp
bool hambre = true;
bool durmiendo = false;
```



### `char`

`char` sirve para guardar un carácter.


## Datos, variables y funciones


Las **clases siempre van con mayúscula**.


Podemos pensar en:


* **Datos / variables / atributos** → lo que tiene una cosa.
  
* **`()` acciones / funciones / métodos** → lo que se puede hacer con esos datos.


Por ejemplo, una persona puede tener atributos y métodos.


### Matías


**Atributos**

* `float` → piti, porque es un porcentaje.
* 
* Le cuesta pronunciar algunas palabras.


**Métodos**

* Ponerse los lentes.

### Blossom

**Atributos**

* Manicurista.
* Tengo rulos en el pelo. Esto podría ser `float`, en porcentaje, porque hay veces que tengo los rulos menos definidos o más definidos.
* Cumplo años en octubre.


**Métodos**

* Hacer las uñas.
* Leo en la Kindle.
* Voy a clase.

## Clases e herencia

La **herencia** nos permite decir que existen clases que tienen características de una clase superior.

Por ejemplo, `Poodle` puede ser una clase y su superclase puede ser `Perrite`, porque todos los poodles son perritos.

```cpp
class Perrite {
    bool hambre = true;
    bool durmiendo = true;
    int pelaje = #000000;

    Comer()
    Dormir()
}
```

Entonces:

```cpp
class Poodle {
    superclass Perrite();

    ladrar()
}
```

`Poodle` hereda todo lo que tiene `Perrite` y sigue siendo una clase.

Por ejemplo:

```cpp
Poodle copito;
```

Acá `Poodle` es la **clase** y `copito` es una **instancia** de esa clase.

Si `Perrite` sabe hacer algo, como ladrar, `Poodle` también puede hacerlo porque heredó esas características.



### Clase vs. instancia

**Clase:** es como el modelo o definición.

**Instancia:** es un objeto creado a partir de esa clase.

```cpp
Poodle copito;
```

`Poodle` → clase.

`copito` → instancia.



## `for` y objetos

También vimos que podemos recorrer un conjunto de objetos:

```cpp
for (perrite in perrites) {
    perrite.ladrar()
}
```

La idea es que el `for` recorra los perritos y ejecute la acción correspondiente para cada uno.



## Cómo describir un objeto

Hay que saber **qué cosas necesitamos detallar y cuáles no**, dependiendo de lo que queramos hacer con el objeto.

No necesitamos describir absolutamente todo: tenemos que elegir los datos y acciones que sean útiles para lo que estamos construyendo.



# Raspberry Pi y placas

Hablamos de **Raspberry Pi** y de cómo los profes están intentando hacer sus propias placas porque saldrían mucho más baratas.

Nos mostraron mini placas de Mateo que están hechas solamente con lo necesario para su proyecto.

También me acabo de enterar de que la **proto** es para **prototipos** lol, no sé por qué no sabía eso.



## MicroPython

**MicroPython está prohibido** porque es muy fácil de programar, pero es más difícil para que el chip lo entienda.

Tiene mucha memoria y la memoria es cara.

Nosotros vamos a trabajar con placas que tienen menos memoria, por lo que necesitamos algo más cercano a lo que el chip puede procesar directamente.


## Pico SDK

Vamos a usar la infraestructura de **Pico SDK examples** para ir probando.


## `int main()`

Vamos a tener un:

```cpp
int main()
```

que maneja todo.

La lógica sería algo como:

```text
¿El usuario presionó el botón?
        ↓
       sí
        ↓
   Haz este sonido
```

La idea es que `main` controle lo que ocurre y que las acciones se ejecuten según lo que haga el usuario.


## encargos

legir un objeto. Puede ser cualquier cosa: una mano, un perro, una mascota, una propiedad de, etc.

Buscar a **Aristóteles** y sus categorías.

Analizar el objeto utilizando esas categorías.


**Aristóteles y sus categorías**


Para este ejercicio elegí analizar mi Kindle, porque es un objeto que uso bastante y que puedo describir de distintas formas según las categorías de Aristóteles.


Objeto: mi Kindle


1. Sustancia — ¿qué es?

Es un lector de libros electrónicos.


2. Cantidad — ¿cuánto?

Tengo un Kindle. Es liviano y tiene un tamaño pequeño.


3. Cualidad — ¿cómo es?

Es delgado, rectangular y liviano. Tiene una pantalla de tinta electrónica.


4. Relación — ¿con respecto a qué?

Es mi Kindle y lo relaciono principalmente con los libros que leo.


5. Lugar — ¿dónde está?

Puede estar en mi pieza, en mi cartera, sobre mi velador o en mis manos.


6. Tiempo — ¿cuándo?

Leo en mi Kindle cada vez que tengo un momento libre, aunque sean solo unos minutos. Por ejemplo, en el metro, mientras espero el metro o la micro, o en el auto cuando no voy manejando.


7. Situación — ¿cómo está colocado?

Puede estar vertical cuando estoy leyendo, acostado sobre una mesa o apoyado en la cama.


8. Condición — ¿qué tiene?

Puede tener una funda, libros descargados y batería cargada.


9. Acción — ¿qué hace?

Puede mostrar libros, cambiar de página, guardar mi progreso y cambiar el tamaño de la letra


10. Pasión — ¿qué le ocurre?

Se puede descargar, caer, rayar o actualizar.




aparte, para el martes 07a

Bajar cómo **Instagram nos describe**, pensando en el algoritmo.



## lectura

PAG 44-60

En estas páginas aparecen varios ejemplos de poemas hechos con programación. Básicamente, los programas tienen palabras, frases o estructuras guardadas y después las van combinando para generar diferentes resultados.

Aparece harto la repetición y también la idea de cambiar algunas partes de una misma estructura. Por ejemplo, se puede mantener una frase y cambiar solamente algunas palabras. También aparece el cut-up, que sería tomar partes de un texto y volver a mezclarlas.

Después habla de los slots, que son como espacios dentro de una estructura que el programa va rellenando con diferentes palabras. Esto aparece también en los ejemplos de haikus, donde se mantiene una estructura y van cambiando los elementos.

En general, entendí que el resultado depende bastante de las reglas que tenga el programa y de las palabras que se le hayan dado. O sea, no es que el computador invente todo desde cero.

Citas

“the programming leads to extensive repetition” (p. 45).

“the chance automation of text makes for awkward writing” (p. 54).

Cosas que me quedaron

Me quedó más claro que estos poemas se hacen a partir de cosas que ya están dentro del programa y que después se van mezclando.

También me llamó la atención que algo que parece muy aleatorio igual tiene reglas detrás, porque alguien tuvo que decidir qué palabras podía usar el programa y cómo las iba a combinar.
