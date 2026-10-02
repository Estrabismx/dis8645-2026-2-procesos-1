# sesion-06b

## apuntes sesión

> signo % es contextual

### Rodrigo Toro

esta clase vino Rodrigo, el cual nos mostró sus trabajos (fotos y videos), nos habló de ellos, y nos dio consejos. estos fueron mis apuntes:

+ hizo un cuerpo de resina lleno de agua, parece un pulmón 
+ 2013 tenia entrega seminario de titulo, se obsesionó de una idea, hizo una escultura en donde no le funcionó el circuito
+ mano autómata que se arrastra por el suelo, se mueve con un motor. me gusta la terminación en metal y el hecho de que se arrastre de manera lenta, es hipnotizante
+ en una exposición utilizó un vinilo en donde se escuchaba cómo hablaba de una experiencia, el cual alguien debía estar preocupado de estar volviendo a poner la aguja en el lugar cuando terminaba de reproducirse el audio del vinilo, por lo que decidió ralentizar el audio para que dure una hora, cosa que cambió el trabajo de volver a poner la aguja en el lugar a algo más relajado. para dejar de tener que necesitar gente que haga el trabajo de poner la aguja, lo cambió para que lo haga una inteligencia artificial.
+ cualquier método es mejor que ninguno
+ hagan cosas con ruedas y rodamientos

---

### clases

class es una variable pero más compleja. es una super variable.

```cpp
class Termo {
	public:
		bool existencia;
		int posición = 0 ; //si no le digo nada en main, asumirá que la posición está en 0
		int cantidadMl;    // con esto nos ahorramos tener que darle valor a cada uno de estos abajo kkkkkkk
		float temperatura;

	// constructor 
	Termo(int cuantosMl) {
		cantidadMl = cuantosMl;
	}
		
		void abrir();
		void cerrar();
};

int main() {

stdio_init_all();


// constructor con parámetros para cuántos ml
Termo elDeCatalina(800);
Termo elDeMisa(500); // al poner esto nos ahorramos lo comentado debajo

elDeMisa.existencia = true;
elDeCatalina.existencia = true;

// elDeCatalina.cantidadMl = 800;
// elDeMisa.cantidadMl = 500;
```

este ejercicio no funcionó, pero Aarón lo corrigió y quedó de la siguiente forma:

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

el orden de las cosas importa.

---

## lectura: Program Or Be Programmed: Ten Commands for a Digital Age - Douglas Rushkoff

"For some, this means finding other people like themselves for the very first time" creo que esto es lo más lindo del internet! ya que para muchas personas es difícil encontrar a otros que estén pasando lo mismo que ellos, por lo que al ver la falta de representación e identidad en la vida del día a día puede afectar de manera negativa a nivel emocional. la razón por la que me motivé a salir del closet como persona trans fue porque vi a une niñe no binarie en Instagram que estaba haciendo su transición pública! su nombre es Ángel creo(? es una persona no binarie de Chile:)

"Instead of having the students re-create the General Assembly in their classroom, they would do it in an online simulation called Second Life" al leer el nombre del simulador me quedé pensando en si era el mismo juego que se llamaba Second Life, y al buscar en Google creo que si se refiere al mismo. la verdad ahora me sorprende ver esto en un libro ya que si no me equivoco este juego de simulación está ultra funado ya que hay poca regulación dentro de los servers y esto causó que sea un lugar en donde los pedófilos pueden reunirse como "comunidad" y sin correr riesgos. dejo aquí unos links para que vean de lo que hablo (si es que quieren, es horrible asi que si no lo desean ver es entendible):

+ <https://www.infobae.com/2007/05/26/316732-el-lado-mas-oculto-second-life-al-descubierto/>
+ <https://www.researchgate.net/publication/251921004_Combating_Child_Exploitation_in_Second_Life>
+ <https://www.puroperiodismo.cl/adentro-del-infierno-virtual-la-cruzada-de-infugatito-contra-la-pedofilia-en-second-life/> (infugatito es un creador de contenido que ha documentado el lado horrible de Second Life y los códigos que utilizan estas personas para comunicarse de manera menos explícita y así pasar desapercibidos)
