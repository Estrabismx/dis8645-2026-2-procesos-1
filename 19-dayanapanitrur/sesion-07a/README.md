# sesion-07a

## apuntes sesión

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

## encargos

## lectura
