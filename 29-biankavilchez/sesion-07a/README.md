# sesion-07a

## apuntes sesión


### antes de programar

- primero se hace la interfaz.
- después se arma un diagrama de flujo, con las cosas bien definidas y en orden. recién ahí se escribe el código.


- **clase:** el molde general. ejemplo: `perro`.
- **instancia:** un objeto concreto hecho con ese molde. ejemplo: `copito`.
- se pueden crear varias instancias de la misma clase, cada una con sus valores internos distintos. por ejemplo, dos termos: uno con 500 ml y otro con 350 ml, cada uno con su propia temperatura.

### estructura macro de una clase

la regla general es esta:

```cpp
class Nombre {
  public:
    // atributos: variables internas (int, bool, float...)

    // constructor: se llama igual que la clase
    Nombre(...) {
    }

    // métodos: lo que la clase sabe hacer
    void abrir(...);
    void cerrar(...);
};   // ojo: la clase termina con punto y coma
```

- el nombre de la clase empieza con mayúscula.
- `public:` es una palabra clave que vamos a usar todo el semestre.
- los **atributos** son las variables de la clase.
- los **métodos** son sus funciones.


1. `class` + nombre de la clase
2. atributos / variables de la clase
3. método constructor
4. métodos

### ejemplo: clase `Termo`

```cpp
// declaración de la clase Termo
class Termo {
  public:
    // atributos de la clase (variables internas)
    bool existencia = true;
    bool abierto = false;
    int posicion = 0;
    int cantidadML;
    float temperatura = 100.0;
    int rodamientos = 5;

    // método constructor, con un parámetro: cuantosML
    Termo(int cuantosML) {
      cantidadML = cuantosML;
    }

    // método enfriar
    void enfriar() {
      while (true) {
        temperatura = temperatura - 0.7;
        sleep_ms(1000);   // pausa: se actualiza cada un segundo
      }
    }
};
```

### sobre el constructor

- se ejecuta al crear la instancia y deja los valores iniciales.
- una misma clase puede tener **más de un constructor** (con distintos parámetros).

### sobre `enfriar()` y el `while (true)`

- `while (true)` significa "mientras esto sea verdad, hazlo". como `true` siempre es verdadero, el ciclo no termina nunca.
- eso congela el programa en esa tarea: no pasa a ninguna otra, porque algo ocurre para siempre. es una decisión de diseño.
- en cada vuelta toma la temperatura y le resta 0.7.

### `if` / `else`

`else` es "en cualquier otro caso". sirve para decidir entre dos opciones:

```cpp
if (elDeCata.abierto) {
  printf("el termo de cata está abierto\n");
} else {
  printf("el termo de cata está cerrado\n");
}
```

así el programa imprime que el termo de cata está abierto o cerrado, según el valor de su atributo.

### imprimir con `printf`

revisando el código de ejemplo de la semana pasada, aparece esto:

```cpp
printf("hola mundo\n");
```

antes de cerrar las comillas está `\n`, que corresponde a un salto de línea. cumple una función parecida a `Serial.println()` en arduino ide, que también baja a la línea siguiente después de imprimir.

#### `%d`

 `%d` es un número entero

 `%.xf`: añadir decimales


### `float` vs `double`

- `float`: aproximación, de menor resolución.
- `double`: mayor rango y precisión.

## ejemplo: clase `Boton`

```cpp
class Boton {
  public:
    // atributos
    bool presionado = false;          // sí o no, según si se presionó
    bool normalAbierto = true;
    int duracionPresionado = 0;       // en ms
    unsigned int patita;              // unsigned: entero que no puede ser negativo
    unsigned int vecesPresionado = 0;
    char nombre[10];                  // ej: "pausa", "reproducir"

    // constructor: define la patita
    Boton(int nuevaPatita) {
      patita = nuevaPatita;
    }

    // métodos
    void leer();
    void actualizar();
};
```

### el constructor


```cpp
Boton(int nuevaPatita) {
  patita = nuevaPatita;
}
```

### instancias

```cpp
Boton pausa(GP1);
Boton reproducir(GP3);
Boton aparecer(GP30);
```

cada botón es una instancia distinta.

## archivos

- `.ino` (arduino) vs `.cpp` (c++): en c++ se separa en dos archivos, uno corto y uno largo.
- `main.cpp`: el programa principal.
- `Boton.h` (header, encabezado): es el resumen de la clase. muestra todo lo que se puede leer y usar de los botones:




## encargos

1. usar el ejemplo base visto en clases <https://wokwi.com/projects/476507507193136129>, agregar un segundo botón en la simulación de hardware, agregar una segunda instancia de la clase Boton, agregarle un atributo y un método a la clase Boton, y hacer que el segundo botón haga algo diferente al primero.
2. descargar todos los archivos de wokwi, descomprimir el archivo.zip y subir esa carpeta a tu repositorio en esta sesión.

## lectura
