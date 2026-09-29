# sesion-07a

## apuntes sesión

### Código
partimos la clase analizando con mayor profundidad este código de ejemplo

```cpp
// include con <>
// este archivo esta en un que tiene que ver
// con la instalacion general de cpp 
#include <stdio.h>

// include con ""
// esto es literalmente en ese lugar
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

### Programación orientada a objetos 
- **variables:**
```
características, propiedades, estado de un objeto (cambiantes)
almacenan información o dato que identifican a cada objeto
```

- **método - función:**
```
comportamiento u acciones que el objeto puede realizar
modifica atributos o interactúa con otros objetos
envoltorio
conversar entre ellos o con los atributos
```
- **método constructor:**
```
se llama solo una vez
tiene el mismo nombre de la clase pero no tiene ningún tipo de retorno
iniciar objeto, asignando valores requeridos a los atributos 
```
  
```cpp
class Termo {
  // nueva clase llamada Termo
  // palabra clave public
  // la usaremos este semestre
  public:
    // atributos de la clase
    // (variables internas)
    // características o estados que tendrá cada objeto  
    bool existencia = true;
    bool abierto = false;
    int posicion = 0;
    int cantidadML;
    float temperatura = 100.0;
    int rodamientos = 5;

    // metodo constructor
    // con un parametro cuantosML
    // se crea automáticamente
    // parámetro entero + atributo
    Termo(int cuantosML) {
      cantidadML = cuantosML;
    }
    
    // metodos para abrir y cerrar
    // modifican estado de los atributos del termo 
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
```
while (true) -- mientras esto sea verdad, hazlo
else e.o.c "en otro caso"
.% -- place holder 
f -- float, mentira, aproximación, ruido 
int -- verdad
double -- float de mayor resolución
sleep -- delay
main.cpp -- en main está la estructura general
archivos h y archivos cpp, por cada clase 
en el h hay un resumen de todo, una declaración, es más pequeño 
en cpp un archivo grande, donde explica como se hace
```
### Programar un botón
tomar información y filtrarla

describir función

se mantiene en 0

si lo presiono es un leve pestañeo

doble click 

sensor inerte 

orden, diagrama de flujo -- SIEMPRE
```
Boton pausa (GP1);
Boton reproducir (GP3);
Boton apagar (GP30);
```

<https://wokwi.com/projects/476507507193136129>

## encargos
bajar una red social e investigar que piensa esa red de mi, cuál es mi algoritmo

(listar 10 categorías que deciden qué y quién eres)

## lectura
