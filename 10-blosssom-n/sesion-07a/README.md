# sesion-07a

## apuntes sesión

## encargos

1. usar el ejemplo base visto en clases <https://wokwi.com/projects/476507507193136129>, agregar un segundo botón en la simulación de hardware, agregar una segunda instancia de la clase Boton, agregarle un atributo y un método a la clase Boton, y hacer que el segundo botón haga algo diferente al primero.
2. descargar todos los archivos de wokwi, descomprimir el archivo.zip y subir esa carpeta a tu repositorio en esta sesión.



## ¿Qué hice?

El primer botón ya venía hecho en el ejemplo que vimos con el profe, así que partí desde ese código y trabajé sobre él.

El encargo era agregar un segundo botón en la simulación, crear una segunda instancia de la clase Boton, agregarle un atributo y un método a la clase, y hacer que este segundo botón hiciera algo diferente al primero.



### Segundo botón

Primero agregué una segunda instancia:

```cpp
Boton miSegundoBoton(8);
```

El miPrimerBoton(7) ya estaba en el código del profe, así que yo solamente agregué el segundo y lo conecté a otra patita.

Después hice que los dos botones se leyeran dentro del while:

```cpp
miPrimerBoton.leer();
miSegundoBoton.leer();
```

Así cada uno puede saber si está presionado.



### Atributo nuevo

En Boton.h agregué:

```cpp
int cantidadPresiones = 0;
```

Esto sirve para guardar la cantidad de presiones que ha contado el segundo botón.

Al principio parte en 0 y después va aumentando.



### Método nuevo

También agregué:

```cpp
void contarPresion();
```

Y en Boton.cpp hice que ese método sumara uno:

```cpp
void Boton::contarPresion() {

  Boton::cantidadPresiones = Boton::cantidadPresiones + 1;

}
```

O sea, cada vez que se llama a contarPresion(), cantidadPresiones aumenta en 1.

### ¿Qué hace diferente el segundo botón?

El primer botón mantiene lo que ya hacía el ejemplo del profe: cuando está presionado, muestra un mensaje.

El segundo botón, en cambio, cuenta sus presiones y muestra ese número en el monitor serial:

```cpp
if (miSegundoBoton.presionado) {

  miSegundoBoton.contarPresion();

  printf("soy el segundo boton\n");

  printf(
    "me han contado %d presiones\n",
    miSegundoBoton.cantidadPresiones
  );

}
```

Entonces si lo presiono, aparece algo como:

```text
soy el segundo boton
me han contado 1 presiones
```

Y si sigue detectando que está presionado, el número continúa aumentando.

El segundo botón funciona de una manera distinta al primero. Como el programa revisa el estado del botón cada 500 ms, tenemos que mantenerlo presionado para que lo vaya detectando. Mientras sigue presionado, el método contarPresion() aumenta cantidadPresiones.

### Simulación

En diagram.json agregué el segundo botón y otro resistor.

Quedó:

```text
primer botón → GP7
segundo botón → GP8
```

También dejé el segundo botón de otro color para poder distinguirlo en la simulación.

### En resumen

Partí con el botón que ya había hecho el profe y lo usé como base.

Después agregué:

```text
segundo botón
↓
segunda instancia de Boton
↓
nuevo atributo: cantidadPresiones
↓
nuevo método: contarPresion()
```

Y así los dos botones siguen siendo objetos de la misma clase Boton, pero el segundo tiene una función distinta.

## lectura

### (PAG 60-75)

En estas páginas siguen apareciendo ejemplos de poesía hecha con computadores, pero ahora se habla harto de programas que toman palabras o fragmentos y los van mezclando para crear textos nuevos.
Me llamó la atención que algunos programas funcionan con reglas súper específicas. Por ejemplo, pueden elegir palabras de distintas categorías y después combinarlas para formar poemas. También aparecen obras que usan el azar, donde el resultado depende de las combinaciones que haga el programa.
Después aparece John Cage, que usa el azar como parte del proceso creativo, incluso usando métodos como el I Ching. También se habla de otros autores que trabajan con programas para cortar, ordenar o cambiar textos que ya existían.
Otra cosa que aparece es que algunos programas permiten que el usuario modifique las palabras o las bases de datos, entonces no siempre el resultado es exactamente el mismo. Hay varios ejemplos donde los textos terminan siendo medio raros o difíciles de entender, pero justamente esa es parte de la idea.

#### citas

“its pieces become more abstract and challenging to read in any conventional sense” (p. 69)


“words, phrases, sentences, and other linguistic elements are treated like the tones or intervals of scales” (p. 71)
