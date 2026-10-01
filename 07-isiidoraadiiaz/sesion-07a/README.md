# sesion-07a

## apuntes sesión

# 29-09

## Análisis de código

Partimos analizando el código de Wokwi y retomando lo que habíamos visto sobre las clases e instancias.

[Código de Wokwi](https://wokwi.com/projects/476140065507309569)

**TODO PÚBLICO, NO PRIVADO!** Por ahora vamos a trabajar con `public` para poder acceder a nuestros atributos y métodos desde fuera de la clase.

### Clases e instancias

Volvimos a repasar la diferencia entre ambas, porque ahora empezamos a utilizarlas mucho más.

Por ejemplo:

- **Clase:** `Perro`
- **Instancia:** `copito`

Las instancias son como variables que creamos a partir de una clase. O sea, cada una es un objeto independiente, pero tiene las características que definimos en su clase.

Otro ejemplo que vimos fue el de los chilenos JAJJA.

Podríamos crear una clase llamada `Chileno`, que tenga una variable interna llamada `RUT`.

Todos los objetos que creemos a partir de esa clase tendrán el atributo `RUT`, pero cada instancia puede guardar un valor diferente.

## Constructores

El **constructor** es un método especial que se ejecuta cuando creamos una instancia. Sirve para darle sus valores iniciales.

Se escribe con el mismo nombre de la clase y utiliza `()` y `{}`.

Por ejemplo, si tenemos una clase `Termo`, podemos hacer que su constructor reciba la cantidad de mililitros que tendrá inicialmente.

**IMPORTANTE:** dentro de una misma clase puede existir más de un constructor con distintos parámetros.

Esto significa que podemos tener diferentes formas de crear una instancia, dependiendo de la información que queramos entregarle.

## Otras cosas del código

### `while (true)`

```cpp
while (true) {

}
```

Es como el reemplazo del `loop()` que utilizábamos en Arduino.

Como la condición siempre es verdadera, el código que está dentro se repite constantemente.

### `int main()`

El `main` es toda la **maquinaria principal** del programa, por decirlo de alguna manera jajaja.

Es desde donde comienza a ejecutarse nuestro código y donde podemos ir organizando lo que queremos que ocurra.

### ¿Qué significa el punto (`.`)?

Por ejemplo:

```cpp
elDeCata.cantidadML
```

El punto significa que vamos a acceder a algo que está **dentro del objeto**, en este caso, dentro del termo de Cata.

Podemos acceder tanto a sus atributos como a sus métodos.

### `%.1f` y los decimales

También vimos cómo mostrar los números decimales:

```cpp
printf("%.1f grados\n", temperatura);
```

- `%` → indica que vamos a insertar un valor.
- `.1` → significa que queremos mostrar un decimal.
- `f` → corresponde al formato de punto flotante.
- `\n` → hace un salto de línea.

Por ejemplo, si tenemos una temperatura de `72.56`, se mostraría como `72.6 grados`.

**Otra cosa:** los `float` son una aproximación, porque no todos los números decimales se pueden representar de manera completamente exacta en la memoria.

### `sleep` y `delay`

Son parecidos, ambos permiten generar pausas en el código.

PERO hay que intentar no utilizarlos tanto porque son medio noob jejejej.

No es que estén mal, sino que al generar una pausa el programa puede dejar de atender otras acciones mientras espera. Por eso, cuando necesitamos trabajar con varias cosas al mismo tiempo, conviene buscar formas más precisas de controlar los tiempos.

# Nueva clase: `Boton`

Después empezamos a pensar en una clase para nuestros botones.

La idea es que, en vez de crear todas las variables por separado cada vez que necesitemos un botón, podamos tener una clase que reúna sus atributos y métodos.

## Atributos

Primero definimos qué información queremos guardar:

```cpp
class Boton {
public:

    bool presionado = false;
    bool normalmenteAbierto = true;

    int duracionPresionado = 0;
    int patita;

    unsigned int vecesPresionado = 0;

    char nombre[20];

    void leer();
    void actualizar();
};
```

**¿Qué sería cada cosa?**

- `bool presionado` → guarda si el botón está presionado o no (0 o 1).
- `bool normalmenteAbierto` → indica si el botón es normalmente abierto, o sea, si el circuito está abierto cuando no lo presionamos.
- `int duracionPresionado` → cuánto tiempo lleva presionado.
- `int patita` → el número del pin donde está conectado.
- `unsigned int vecesPresionado` → cuenta cuántas veces se ha presionado. Acá tiene sentido usar un entero sin signo porque no podemos presionar un botón -5 veces JAJJA.
- `char nombre[20]` → sirve para guardar el nombre del botón mediante caracteres.

## Constructor

**EL CONSTRUCTOR ES UN MÉTODO.**

Se escribe con el mismo nombre de la clase y utiliza `()` y `{}`.

En este caso nuestra clase se llama `Boton`, así que su constructor también tiene que llamarse `Boton`.

Por ejemplo:

```cpp
Boton(int nuevaPatita) {
    patita = nuevaPatita;
}
```

Acá estamos diciendo que, cuando creemos un botón, tenemos que entregarle la patita donde estará conectado.

Por ejemplo:

```cpp
Boton pausa(A0);
```

Entonces:

- `Boton` → es la clase.
- `pausa` → es la instancia.
- `A0` → es la patita que le estamos entregando al constructor (si está definida en nuestra placa).

Esto nos permite crear distintos botones utilizando la misma clase, pero asignándoles diferentes patitas.

## Métodos

También pensamos en las acciones que podría realizar nuestro botón.

Por ahora tenemos:

```cpp
void leer();
void actualizar();
```

- `leer()` → serviría para leer el estado del botón y saber si está siendo presionado.
- `actualizar()` → permitiría actualizar su información dependiendo de lo que esté ocurriendo.

`void` significa que el método realiza una acción, pero no devuelve un valor.

# Archivos `.h` y `.cpp`

Cuando creemos nuestra clase `Boton` vamos a trabajar con **dos archivos**, uno más corto y otro más largo.

### `.h` — Header (encabezado)

Este archivo funciona como una especie de presentación de nuestra clase.

Acá colocamos los atributos y declaramos los métodos que queremos utilizar, pero sin tener que desarrollar necesariamente todas sus instrucciones.

Por ejemplo:

```cpp
class Boton {
public:

    bool presionado = false;
    int patita;

    Boton(int nuevaPatita);

    void leer();
    void actualizar();
};
```

Es como decir **qué tiene y qué sabe hacer nuestro botón**.

### `.cpp` — La receta

Acá es donde desarrollamos lo que declaramos en el `.h`.

Por ejemplo, si dijimos que nuestro botón tendría un método llamado `leer()`, en el `.cpp` tendríamos que escribir las instrucciones para que realmente pueda hacerlo.

Entonces, para no confundirme:

- **`.h` → encabezado:** presenta qué cosas tiene nuestra clase.
- **`.cpp` → receta:** desarrolla cómo funcionan esas cosas.

### `#include`

También apareció `#include`, que nos permite incorporar otros archivos o bibliotecas a nuestro código.

Por ejemplo:

```cpp
#include "Boton.h"
```

Esto nos permite utilizar las declaraciones de nuestra clase `Boton` desde otro archivo.

# Proyecto 2 y próximo encargo

El proyecto 2 va a tener **MUCHO MÁS CÓDIGO**.

La idea es empezar a tomar las clases que estamos construyendo y utilizarlas para que pasen cosas cool jajaja. Ya no solamente escribir instrucciones sueltas, sino organizar mejor la información y las acciones que queremos que ocurran.

### Encargo para el próximo martes

Tenemos que **complejizar nuestra clase `Boton`**.

- Agregar más botones.
- Pensar en nuevos atributos para nuestros botones.
- Incorporarlos a la clase.
- Seguir trabajando con constructores y métodos.

La idea es que nuestra clase pueda guardar más información y que los botones tengan más posibilidades dentro del proyecto.

## encargos

1. usar el ejemplo base visto en clases <https://wokwi.com/projects/476507507193136129>, agregar un segundo botón en la simulación de hardware, agregar una segunda instancia de la clase Boton, agregarle un atributo y un método a la clase Boton, y hacer que el segundo botón haga algo diferente al primero.
2. descargar todos los archivos de wokwi, descomprimir el archivo.zip y subir esa carpeta a tu repositorio en esta sesión.

## lectura
En estas páginas entendí más que nada que la geometría empezó a organizarse de una forma mucho más técnica, especialmente con los manuales de Monge, que permitían transformar procedimientos complejos en instrucciones que otras personas podían seguir y repetir. Me llamó la atención que esto también impulsó el desarrollo de nuevas máquinas, porque cada vez podían incorporar más conocimientos y realizar operaciones que antes dependían completamente de la persona. Siento que acá el papel del arquitecto también empieza a cambiar, ya no se trata solamente de saber dibujar, sino de entender cómo utilizar estas herramientas para diseñar. Me gustó la comparación con el software, porque muestra que esta forma de trabajar ya existía mucho antes de los computadores.
“Geometric manuals were the concentrated distillations of disciplinary expertise.” - pág. 47
“In a sense, these tools were like custom software applications for each of these specific design problems.” - pág. 53
