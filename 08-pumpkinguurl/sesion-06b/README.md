# sesion-06b

## apuntes sesión

wokwi - raspberry pi pico - SDK

```cpp

//copia y pega ese archivo
//ojo que esta entre <>
//este archivo esta recondito, en un lugar lejano
//que tiene que ver con C
//std - standard
//io.h archivo popular
#include <stdio.h>
//este otro esta en ""
//como se hace C dentro de la placa
//"" es literalmente ese lugar
//hay una carpeta pico
//y esta dentro de stdlib.h
#include "pico/stdlib.h"

//mi propia funcion
//tipo nombre parentesis murcielagos
//diseno top-down
//escribir desde el macro y luego el micro
int prueba() {
 int x = 3;
 int y = 6;
 int resultado = x*y;
 return resultado;

}

//funcion main()
//es del tipo int
//las int cuando corren
//retornan un numero entero
int main() {
  //se trabaja aquí adentro
  //esta funcion inicializa raspico
  //prende y apaga los intputs y outputs
  stdio_init_all();
  while (true) {
  //para borrar cosas colocarlo 
  //como comentario
  // printf("Hello, Wokwi!\n");
  //entonces hay que convertir de int a char
  //claudio dijo usa %d cuando quieras reemplazarlo
   //printf("%d",prueba());
   //este tampoco funciono
    //printf(str(prueba()));
   printf("%d\n", prueba());
  //no hemos definido que es prueba
  //entonces no lo reconoce
  //le hace la desconocida
  //hay que presentarselo antes
  //no funciono 


   //no funciono
   //paso algo bello segun aaron

    sleep_ms(250);
  }
}

```

Rodrigo Toro

intereses: tecnología obsoleta, fantasmas, memoria, historia.

Es importante el fracaso.

Aarón: no pueden no llegar.

Buen apagador de incendios.

manos, Discovery kids, haz tu propio automata

mano de cartón con hilos, hacer una versión más pro

hacer variaciones de una cosa

(pensamiento intrusivo) chinos: personas, mall, comida

compren rodamientos

una persona se sentó encima de la escultura que movía los pulgares y lo rompió

hay que hacer las cosas pensando en la gente tonta e intrusa

modulor store Berlín ir si algún día estoy por ahí

Para el próximo proyecto hay que sacar fotos, muchas

hagan colaboraciones 

hacer primero una versión mala luego mejorarla

statement: esto hago y no hago otra cosa

manualidad a la mano

*Y mis manos son lo único que tengo *

*Y mis manos son mi amor y mi sustento *

*Y mis manos son lo único que tengo *

*Son mi amor y mi sustento *

*Víctor Jara*

La invención de morel - recomendación de Rodrigo

me perdí mucho rato.

aplausos espontáneos.

vayan a terapia y coman bien.

---------------------------------------------

c++ Clases

para hacernos todo mas fácil, vamos a hacer todo public

para proteger las variables priv pero no nos importa, no hackear el registro civil.

las funciones no tienen ; después del } pero en las clases hay que colocarlo después de };

las clases son moldes y cuando se usan el resultado son objetos

en las clases hay bob el constructor - constructors función - plantilla que permite crear objetos de forma avanzada

qué hace? es un método automático que se llama cuando se crea un objeto

el constructor no tiene fronteras

método mas importante dentro de una función.

nombre de la clase, nombre de fantasía, valor para que exista.

moldes que permiten propagar comportamiento, son paramétricos 

```cpp

#include <stdio.h>

class Termo {
  public: 
    bool existencia;
    int posicion; 
    int cantidadML;
    float temperatura;

   //constructor (bob)
    Termo(int cuantosML) {
      cantidadML = cuantosML;
    }

    void abrir ();
    void cerrar(); 

 

};

#include "pico/stdlib.h"

int main() {

  stdio_init_all();

//constructor 
//con parametro
//para cuantos ML
  Termo elDeCatalina(800);
  Termo elDeMati(500);

  elDeMati.existencia = true;
  elDeCatalina.existencia = true;


  elDeCatalina.cantidadML = 800;
  elDeMatias.cantidadML = 500; 

//si no esta el punto 
//voy a buscar algo que se llame cant ml
//el . es para llamar
//el contexto

  while (true) {
    printf("Hello, Wokwi!\n");
    sleep_ms(250);
  }
}

```


## encargos
Elijan cualquier objeto

buscar Aristóteles categorías

analizar el objeto según las categorías de Aristóteles

Categorías del ser de Aristóteles

------------------------------------------------------

- Categorías según Arístoteles: sustancia, cantidad, cualidad, relación, tiempo, lugar, posición, estado, acción y pasión.
- Objeto escogido: larva de chinita

------------------------------------------------------

- Sustancia: Tiene un exoesqueleto, órganos, células, es un organismo vivo, por lo tanto, posee materia orgánica.
- Cantidad: Varias, se ponen aproximadamente unos 200 a 500 huevos, por lo que pueden salir varias larvas.
- Cualidad: Tiene el cuerpo alargado y posee protuberancias parecidas a espinas, tiene algunas zonas naranjas y no posee alas.
- Relación: En comparación a las chinitas adultas, estas aún no desarrollan sus alas.
- Tiempo: La etapa larvaria dura entre 12 a 30 días, antes de eso es huevo por unos 4 a 10 días.
- Lugar: Abarca la naturaleza.
- Posición: Se encuentra principalmente en hojas o tallos, parte de las plantas en general.
- Estado: Dependiendo de la que se encuentre, puede estar viva y en movimiento o muerta y estática.
- Acción: Caminar, comer, seguir desarrollándose.
- Pasión: Si se encuentra con una persona miedosa puede ser pisada, soplada, tirada, tomada y dejada en otro lugar, entre otras.

## lectura
