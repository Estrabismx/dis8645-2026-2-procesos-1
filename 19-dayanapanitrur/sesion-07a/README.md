# sesion-07a

## apuntes sesión

###  parte de la clase

En la clase de hoy revisamos esto:

https://wokwi.com/projects/476140065507309569

%d : placeholder

\n salto de línea

Los doble click los podemos programar, al código le importa saber cuando hay un 0 y después un 1 (el presionar) o un 1 y luego un 0 (soltar), algo que para el proyecto 01 tuvimos que realizar con Cami y Bianka con los botones, establecimos por cuantos segundos / milisegundos se debían mantener presionados los botones para que sucedieran cosas.

EL orden son:

- atributos

```cpp

// declaracion de clase Termo
class Termo {
  // palabra clave public
  // la usaremos este semestre
  public:
    // atributos de la clase
    // (variables internas) 
    bool existencia = true;
    bool abierto = false;
    int posicion = 0;
    int cantidadML;
    float temperatura = 100.0;
    int rodamientos = 5;
```

- métodos constructor (funciones dentro de una clase)

```cpp
  // metodo constructor
    // con un parametro cuantosML
    Termo(int cuantosML) {
      cantidadML = cuantosML;
    }
    
    // metodos para abrir y cerrar
    void abrir() {
      abierto = true;
    }
    void cerrar() {
      abierto = false;
    }

    // metodo para enfriar
    void enfriar () {
      temperatura = temperatura - 0.7;
    }

};
```
___

paréntesis:

¿qué es public y que es private? (no caché)

cuando defines una clase defines tambipen que es lo público y lo privado, porque hay veces que algunos datos deben ser protegidos.

aunque, lo público con su lógica interna puede modificar lo privado, pero eso todavía no lo veremos.
___

seguimos con los atributos

son 6 atributos: 

```cpp
* existencia = true;
* bool abierto = false;
* int posicion = 0;
* int cantidadML;
* float temperatura = 100.0;
* int rodamientos = 5;
```

Puede haber dentro de una clase más de un constructor:

Cuando definimos una clase también podemos o NO definir valores, como en:

```cpp
int cantidadML;
```

Porque los ML pueden variar.

```while (true)``` es como el ```void loop``` en nuestro Arduino IDE.

```else``` se traduce comunmente como e.o.c, que es "en otro caso". 

```cpp
class Boton {
//atributos
bool presionado= 0;
bool normalAbierto= true
```
pero también existen los normalmente cerrados, entonces podría quedar así:

```cpp
class Boton {
//atributos
bool presionado= 0;
bool normalCerrado= true
```
que más le importa al botón?

el tiempo que dura presionado este botón

```cpp
class Boton {
//atributos
bool presionado= 0;
bool normalAbierto= true
Uint duracionPresionado= 0;
```

además, debemos programar a que pin de nuestro microcontrolador lo conectamos

```cpp
class Boton {
//atributos
bool presionado= 0;
bool normalAbierto= true
Uint duracionPresionado= 0;
int patita;
```
constructor

```cpp
class Boton {
//atributos
bool presionado= 0;
bool normalAbierto= true
Uint duracionPresionado= 0;
int patita;
Uint vecesPresionado= 0;

//constructor

Boton (int nuevaPatita){
patita= nuevaPatita;
```

Entonces cuando creemos un constructor tenemos que darle un parámetro.

___

### Segunda parte de la clase

Dejamos atrás Arduino.

A continuación veremos los métodos. Esta parte está densa.

```cpp
void leer();
void actualizar();
```
¿que pasó aquí? no definimos qué es leer, ni que es actualizar.

esto es una declaración.

vamos a hacer dos archivos: 

Boton.cpp 

Boton.h (h es *header*) 

en el .h es donde definimos que suceden ciertas cosas.

en el .cpp nos haremos cargo de hacer que esas cosas sucedan.

en el .h comento que haremos sopaipillas

en el .cpp escribiré paso a paso como haremos sopaipillas.

haremos siempre un .h y un .cpp

- Ahora programaremos el botón en https://wokwi.com/pi-pico

en el archivo .h

```cpp
#ifndef BOTON_H
#define BOTON_H


// Boton.h
// declaraciones de la clase Boton


// definir clase Boton
class Boton {

  // todo publico
  // nada de andar privatizando
  public:

  // atributos
  bool presionado = false;

  // constructor
  Boton();

  // metodos
  void presionar();
  void soltar();

};

#endif

```

```#ifndef``` y  ```#endif``` será obligatorio usar.

En el archivo .cpp

```cpp
// Boton.cpp
// implementaciones de la clase

// importar el archivo header
#include "Boton.h"

// constructor
Boton::Boton(int nuevaPatita) {

  // guardar el valor
  Boton::patita = nuevaPatita;

   // inicializar patita
  gpio_init(Boton::patita);
  // la patita es entrada
  gpio_set_dir(Boton::patita, GPIO_IN);
}

void Boton::leer() {
    // leer boton
    Boton::presionado = gpio_get(Boton::patita);
}

// metodos
void Boton::presionar() {
  Boton::presionado = true;
  // queda pendiente calcular
  // cuanto rato lleva presionado
}
  
void Boton::soltar() {
   Boton::presionado = false;
   Boton::duracionPresionado = 0;
}
```

## encargos

https://wokwi.com/projects/476511290925165569

(está en procesoooo)

## lectura
