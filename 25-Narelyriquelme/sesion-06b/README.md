
# Sesión 06b

## Apuntes sesión

### ¿Qué es una clase?

Una clase es una **variable más compleja**. Una variable normal guarda un solo dato (un `int`, un `float`). Una clase, en cambio, junta en un mismo paquete varias variables y también funciones.

```cpp
class MyClass {
public:
    int myNum;
    int posicion;
    int cantidadML;
    float temperatura;
    bool existencia;

    void abrir();
    void cerrar();
};
```

- **`class MyClass`**: el nombre de la clase. Todo lo que va entre las llaves le pertenece.
- **`public:`**: significa que lo de adentro se puede usar desde afuera de la clase. Este semestre **solo vamos a usar `public`**.
- **Variables (atributos)**: `myNum`, `posicion`, `cantidadML`, `temperatura`, `existencia`. Son los datos que describen a la cosa y pueden ser de distintos tipos (`int`, `float`, `bool`).
- **Funciones (métodos)**: `abrir()` y `cerrar()`. Son lo que la cosa sabe hacer.


---

### ¿Para qué sirve?

Sirve para **agrupar todo lo que describe una cosa en un solo lugar**. Sin clases, tendría que andar con variables sueltas (`posicion1`, `temperatura1`, `posicion2`, `temperatura2`...) y se vuelve un desorden cuando hay más de una cosa parecida.

Con una clase escribo la descripción **una sola vez** y después la reutilizo las veces que quiera.

Ejemplo pensando en algo físico, como una botella o una válvula:

- Lo que **tiene**: una posición, una cantidad de mililitros, una temperatura, si existe o no → variables.
- Lo que **hace**: abrirse, cerrarse → funciones.

---

### Clase y objeto

- Las clases son **moldes**. Son como el cortador de galletas: define la forma, pero no es una galleta.
- Cuando se usan, ese molde se convierte en el **objeto**. El objeto sí es la galleta: una copia concreta, con sus propios valores.
- Como la clase es un molde, permite **propagar** todo lo que tiene adentro (variables y funciones) a cada objeto que se cree con ella.

Un solo molde puede hacer muchos objetos, y cada uno guarda sus propios valores sin pisar a los demás:

```cpp
MyClass elDeMati;      // objeto 1
MyClass elDeNarely;    // objeto 2
```

Flujo: clase (molde) → se usa → objeto (cosa concreta)

---

### El punto para acceder

El **punto (`.`)** sirve para acceder a lo que hay dentro de la clase/objeto. Se lee como "de este objeto, esta variable".

```cpp
elDeMati.cantidadML = 500;
```

- Lo de la izquierda es el objeto (`elDeMati`).
- Lo de la derecha es la variable de adentro a la que quiero llegar (`cantidadML`).
- Con `= 500` le asigno un valor.

Con las funciones funciona igual:

```cpp
elDeMati.abrir();
```

Como cada objeto tiene sus propios datos, cambiar `elDeMati.cantidadML` no cambia `elDeNarely.cantidadML`.

---

### Valores por defecto

Se pueden definir los valores "por defecto", o sea, **con qué valor parte una variable apenas se crea**.

```cpp
int posicion = 0;
```


### Constructor

- El **constructor es una función**, pero una especial: se ejecuta sola **en el momento en que se crea el objeto**.
- Va y toma la información necesaria para armar **de manera automática** lo que le pedimos.
- **El nombre del constructor es el mismo de la clase.**

```cpp
class MyClass {
public:
    int myNum;
    int posicion;
    int cantidadML;

    // constructor
    MyClass();
};
```

- No lleva tipo de retorno (ni siquiera `void`).
- Sirve para dejar el objeto listo desde el inicio, por ejemplo dándole sus valores iniciales, sin tener que asignarlos uno por uno cada vez.

Flujo: creo el objeto → se llama al constructor → queda armado con sus valores iniciales

---

### Resumen rápido

| Concepto | Qué es | Para qué sirve |
|---|---|---|
| **Clase** | Molde con variables y funciones | Describir una cosa una sola vez |
| **Objeto** | Lo que sale del molde | Tener cosas concretas con sus propios datos |
| **Punto (`.`)** | Operador de acceso | Llegar a lo que hay dentro del objeto |
| **Valor por defecto** | Valor inicial de una variable | Que parta ordenada |
| **Constructor** | Función con el nombre de la clase | Armar el objeto automáticamente al crearlo |


## Encargos

## Lectura
