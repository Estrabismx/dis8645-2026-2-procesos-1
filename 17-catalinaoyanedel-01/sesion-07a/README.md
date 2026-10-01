# sesion-07a
martes 29 de septiembre

## apuntes sesión
### primer ejemplo
todo lo que está afuera de `int main` es para que haya una infraestructura cuando main tenga que correr

código de ejemplo que realizó Aarón

```cpp
// include con <>
// este archivo esta en un que tiene que ver
// con la instalacion general de cpp 
#include <stdio.h>

// include con ""
// esto es literalmente en ese lguar
// al lado de este archivo
// hay una carpeta pico/
// y adentro esta stdlib.h
#include "pico/stdlib.h"

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


// mi propia funcion
// sintaxis es
// tipo nombre parentesis murcielagos
// diseno top-down
// esta funcion retorna el entero mayor
int cualEsMayor(int x, int y) {

  // si x es mayor o igual a y
  // retorna x
  if (x >= y) {
    return x;
  }
  // en otro caso retorna y
  else {
    return y;
  }
}

// funcion main()
// es de tipo int
// las int cuando corren
// retornan un entero
int main() {
  // esta funcion
  // inicializa raspico
  stdio_init_all();

  // constructor
  // con parametro
  // para cuantosML
  Termo elDeCata(800);
  Termo elDeMati(500);

  while (true) {
   
    // imprimir resultado de
    // cual entero es mayor
    printf("entre 6 y 7, el mayor es: %d\n", cualEsMayor(6, 7));
    // imprimir contenidos de termo de catalina
    printf("termo de cata: %d ml\n", elDeCata.cantidadML);

    if (elDeCata.abierto) {
      printf("el termo de cata esta abierto\n");
    } else {
      printf("el termo de cata esta cerrado\n");
    }

    printf("termo de mati: %.1f grados\n", elDeMati.temperatura);
   
    printf("\n");
    
    // actualizar termos
     
    // si esta abierto, cerrarlo
    // si esta cerrado, abrirlo
    if (elDeCata.abierto) {
      elDeCata.cerrar();
    } else {
      elDeCata.abrir();
    }

    // enfriar el termo de mati
    elDeMati.enfriar();

    // pausa en milisegundos
    sleep_ms(1000);
  }
}
```

línea 86:

```cpp
printf("entre 6 y 7, el mayor es: %d\n", cualEsMayor(6, 7));
```


- colocar `\n` para hacer saltos de línea
- **placeholder** es un espacio vacío para que sea ocupado por un número
- función `int` para saber cuál es mayor

```cpp
int cualEsMayor(int x, int y) {

  // si x es mayor o igual a y
  // retorna x
  if (x >= y) {
    return x;
  }
  // en otro caso retorna y
  else {
    return y;
  }
}
```

- estados de presionar o no presionar, pasar de 0 a 1 o de 1 a 0, lo que es más importante es cuando ese estado cambia

**atributos:**

```cpp
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

**métodos y constructor**

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

**orden del código:**
- atributos
- método constructor
- métodos en general

**private y public**
- depende de la seguridad de los datos
- ahora trabajaremos todo public
- el private tiene que ver con lo que se puede modificar, es una restricción

primero se define el mundo para después usarlo

- con el cuantosML es el parámetro interno de la clase, el nombre no es importante, es temporal para guardarlo, **tiene que ser diferente del del atributo**
- ejemplo: la Clase es Perro y la instancia es Copito
- puede haber en la misma Clase más de un constructor
- el código cuenta con 3 atributos:

```cpp
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
```

- esto se establece también en la línea 21, en los atributos

```cpp
bool abierto = false;
```
- también del método enfriarse se declara en los atributos

```cpp
float temperatura = 100.0;
```

- `while (true)`: mientras sea verdad hazlo, cuando deje de ser verdad para.
- se suele recomendar que no se utilice, puede ser un problema porque puede pegar el código al no pasar otra tarea
- el `while true` funciona como el `void loop` en arduino

```cpp
printf("termo de mati: %.1f grados\n", elDeMati.temperatura);
```

- `float`: punto flotante, tiene decimales
- `%`: placeholder
- `.1`: solo da un decimal

### segundo ejemplo

```cpp
class Boton {

  // atributos
  bool presionado = 0;
  bool normalAbierto = true;
  uint duracionPresionado = 0;
  int patita;
  uint vecesPresionado = 0;
  char [] nombre;

  // constructor
  Boton (int nuevaPatita) {
    patita = nuevaPatita;
  }

  // declaracion metodos
  Boton pausa (GP1);
  Boton reproducir (GP3);
  Boton apagar (GP30);

  // metodos
  void leer ();
  void actualizar ();

}
  

```
- la u que se suma al int es para que no de negativo
- https://github.com/piruetasxyz/Boton
- los métodos pueden conversar entre ellos y los atributos
- main.cpp: nombre archivo
- al hacer clases requiere dos archivos: Boton.h y Boton.cpp
- el cpp hace un archivo mucho mas grande, tiene toda la info, el h solo cierta info (implementación y declaración)
- si no tiene {} es declaración
- https://www.gutenberg.org libros libres de derechos de autor

codigo trabajado:
- https://wokwi.com/projects/476507507193136129

la verdad me perdí en todo así que luego estudiaré y profundizaré

## encargos

1. usar el ejemplo base visto en clases <https://wokwi.com/projects/476507507193136129>, agregar un segundo botón en la simulación de hardware, agregar una segunda instancia de la clase Boton, agregarle un atributo y un método a la clase Boton, y hacer que el segundo botón haga algo diferente al primero.
2. descargar todos los archivos de wokwi, descomprimir el archivo.zip y subir esa carpeta a tu repositorio en esta sesión.

## lectura


