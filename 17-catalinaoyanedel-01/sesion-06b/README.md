# sesion-06b
viernes 25 de septiembre

## apuntes sesión
### código trabajado en clases
```cpp
// copia y pega ese archivo
// ojo que esta entre <>
// este archivo esta en un lugar lejano
// que tiene que ver con C
#include <stdio.h>
// este otro esta entre ""
// entre "" es literalmente
// en ese lugar
// en este caso
// al lado de este archivo
// hay una carpeta pico/
// y adentro esta stdlib.h
#include "pico/stdlib.h"


// mi propia funcion
// tipo nombre
// parentesis murcielagos
// diseno top-down
int prueba() {
  int x = 3;
  int y = 6;
  int resultado = x * y;
  return resultado;
}


// funcion main()
// es de tipo int
// las int cuando corren
// retornan un entero
int main() {
  // esta funcion
  // inicializa raspico
  stdio_init_all();
  while (true) {
    // printf("Hello, Wokwi!\n");
    // convertir de int a chars
    printf("%d\n", prueba());
    sleep_ms(250);
  }
}
```

### charla - rodrigo torres
- trabaja mecánicamente
- cuando hay que exponer algo, dividirlo en 3, para cambiar algo solo hacerlo dentro del primer tercio idealmente
- aprender de las experiencias, errores, apagar incendios, resolver
- siempre hacer las cosas a prueba de gente estúpida
- sacar muchas fotos de cada proyecto
- una pieza tiene parámetros, no hay que casarse con ellas
- me gusta que son como manos esqueléticas
- me encantó la conversación de las manos y la frase de víctor jara: "mis manos son lo único que tengo, mis manos son mi amor y mi sustento". siempre he pensado que sin manos no soy nada y eso le dio mucho sentido a ese pensamiento.
- la invención de morel: recomendación de libro
- sus obras funcionan a través de sistemas de poleas diseñadas antes en dibujos, sistemas de diseño !
- probar cosas con otras personas y tomar nota
- me gustan las series de obras temáticas, obsesionarse, volverse experto en un tema
- puentes h: forma de controlar motores
- me pasa con estas charlas que si veo este tipo de obras desde fuera, se me hacen imposibles, por lo tanto agradezco estas instancias donde se muestra el proceso detrás, con una persona que admite todas las pruebas y errores detrás de grandes piezas finales, así he logrado entender que (casi) todo es posible por más difícil que sea.
- método de diseño: hacer muchas tarjetas con estudios de diversas opciones
- cuando uno es profesional hay que hacer cosas que dan lata

### mini clases de clases
#### Class C++
https://www.w3schools.com/cpp/cpp_classes.asp

```cpp
// si es publica 
// luego se puede cambiar el valor
// todo deberia tener ;
// menos las funciones

class Termo {
  public:
    bool existencia;
    int posicion;
    int cantidadML;
    float temperature;

    void abrir ();
    void cerrar ();
};
``` 

las clases son moldes que permiten propagar comportamientos, y el resultado de eso es un objeto, por eso se llama programación en base a objetos

#### Constructores
- metodo especial 
- se llama exactamente igual que la clase
- no estoy entendiendo mucho, ampliaremos después, se vienen cositas
  
## encargos
### profundizar en Constructores

"en programación orientada a objetos (POO), **un constructor es una subrutina cuya misión es inicializar un objeto de una clase. en el constructor se asignan los valores iniciales del nuevo objeto**.

se utiliza para crear tablas de clases virtuales y poder así desarrollar el polimorfismo, una de las herramientas de la programación orientada a objetos. al utilizar un constructor, el compilador determina cual de los objetos va a responder al mensaje (virtual) que hemos creado. tiene un tipo de acceso, un nombre y un paréntesis."


fuentes:

- https://es.wikipedia.org/wiki/Constructor_(informática)
- https://learn.microsoft.com/es-es/cpp/cpp/constructors-cpp?view=msvc-170

## lectura
