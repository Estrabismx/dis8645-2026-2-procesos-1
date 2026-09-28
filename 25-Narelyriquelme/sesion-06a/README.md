# sesion-06a

## Apuntes sesión

Clase donde pasamos de guardar datos (variables) a armar estructuras más grandes: las clases.

---

### Variables: el contenedor

**Variable**

- es un contenedor (un espacio en la memoria del computador) donde guardo un dato para usarlo después
- lo importante es el contenedor, no lo que lleva adentro
- se le pone un nombre descriptivo (identificador) para referirme al valor que guarda
- el valor puede cambiar o ser constante

**La metáfora del súper**

- si compro un chicle, me lo llevo en el bolsillo
- si compro una tabla de madera de tres metros, necesito una camioneta o un flete
- podría contratar un flete solo para el chicle, pero sería innecesario
- con los datos pasa lo mismo: hay que elegir un tipo de dato que tenga sentido para lo que quiero guardar, porque usar uno más grande de lo necesario ocupa memoria de más

dato → variable (contenedor en memoria) → lo uso después

---

### Tipos de datos

Los tipos dependen del lenguaje de programación. Estos son los que vimos:

| Tipo | Qué guarda | Cómo lo pienso |
| --- | --- | --- |
| `int` | números enteros (positivos, negativos y el cero) | una escalera: salta de a un escalón |
| `float` | números con decimales | una rampa: lugar de infinita resolución |
| `bool` | `true` o `false` (1 o 0) | presencia / ausencia, sí / no, cabe algo o nada |
| `uint` | enteros sin signo: 0, 1, 2, 3... | la `u` es *unsigned*: se salta los negativos |
| `char` | un solo carácter (`'A'`) | una letra o símbolo, no una palabra completa |
| `string` | palabras y textos | cadena de caracteres |

**uint**

- sirve para cosas que nunca pueden ser negativas, como una duración o una cantidad
- al no usar negativos, aprovecha ese espacio para guardar números positivos más grandes

**El ejemplo del botón**

- `int` → escalera
- `float` → rampa
- `bool estado` → 1 o 0 (presionado o no)
- `uint duracionPresionado` → cuánto tiempo estuvo presionado

---

### Declarar una variable

Siempre hay que declararla: así se reserva un espacio en la memoria para guardar su valor.

1. Elegir un nombre descriptivo: no usar palabras clave del lenguaje, no empezar con número, y usar `_` o notación camello para separar palabras.
2. Especificar el tipo de dato que se va a guardar.
3. Usar `=` para guardar el valor.

```cpp
int edad = 21;
```

- `int` → el tipo de dato
- `edad` → el nombre de la variable
- `21` → el valor

Ojo: `int` no es la variable, es el tipo de dato de la variable.

---

### Clases

**class**

- no es una variable: es una estructura de información, una especie de molde o plantilla
- su nombre empieza con mayúscula y va en singular (`Perrite`, `Estudiante`); si no tiene mayúscula, no es una clase
- define qué atributos y qué métodos va a tener algo

**El mismo concepto con tres nombres**

| | En humano | En programación | Dentro de una clase |
| --- | --- | --- | --- |
| Lo que "tiene" o "es" | datos | variables | **atributos** |
| Lo que hace | acciones | funciones `()` | **métodos** |

- las funciones se reconocen porque llevan paréntesis `()`
- atributos = lo que tiene o es. Métodos = lo que hace

**Clase y objeto**

- la clase es el molde, el objeto (o instancia) es cada cosa concreta que sale de ese molde
- todos los objetos tienen los mismos atributos que define la clase, pero cada uno con sus propios valores
- como un molde de galletas: todas tienen la misma forma, pero cada una puede tener distinto sabor o decoración
- ejemplo: `Poodle copito;` → `Poodle` es la clase y `copito` es una instancia de ella

**Métodos y atributos**

- los métodos son los que leen o modifican los atributos
- en el diagrama, las flechas van desde los métodos hacia los atributos: el método es el que actúa sobre el atributo

**Ejemplo: la clase Perrite**

```cpp
class Perrite {
    // atributos
    bool hambre = true;
    bool durmiendo = true;
    int pelaje = #000000;   // color en hexadecimal (negro)

    // métodos
    comer();
    dormir();
    jugar();
}
```

**El punto `.`**

- sirve para acceder a algo que vive dentro de un objeto
- ejemplo: `copito.ladrar();`

---

### Herencia

- hay clases que tienen una **superclass**: es como una subvariedad de algo
- un Poodle sigue siendo un perrite, así que no tiene sentido volver a escribir todo lo que ya sabemos de `Perrite`

```cpp
class Poodle {
    superclass Perrite();
    bool defensivo = true;
    ladrar();   // chillón
}
```

Perrite (características generales) → Poodle (hereda todo eso + agrega lo suyo)

---

### Lo que el profe marcó como importante

- las mayúsculas
- los puntos
- la herencia

---

## Encargos

### Actividad en clase: 3 atributos y 3 métodos de mí

```cpp
// atributos
bool peloLargo = true;
bool tenerSueño = true;
bool hambre = true;

// métodos
peinarse();
tomarCafe();
comer();
```

### Aristóteles: mi botella de agua

Elegir un objeto y describirlo con las categorías del ser de Aristóteles.

| Categoría | Qué describe | Mi botella de agua |
| --- | --- | --- |
| **Sustancia** | algo interno y propio del ser | una botella de agua, un recipiente para guardar líquido |
| **Cantidad** | discreta o continua | una botella; tiene cuerpo y tapa; capacidad de 1000 ml (1 litro) |
| **Cualidad** | hábito, habilidad, sensible (perceptible), figura, forma | material: plástico libre de BPA. Color: degradado de negro a gris. Forma: cilíndrica y alargada |
| **Relación** | cómo se relaciona con otro objeto | la uso yo; se relaciona con el agua que guarda |
| **Lugar** (ubi) | posición en relación con el entorno | generalmente a mi lado derecho, sobre una mesa o en mi mano |
| **Tiempo** (quando) | posición en relación con el momento en que sucede | la tengo desde principios de agosto |
| **Posición** (situs) | estado de reposo resultante de una acción | suele estar parada sobre una mesa o al costado de la mochila |
| **Posesión** (habitus) | reposo resultante de ser objeto de una acción | tiene agua adentro porque yo la llené; tiene un rayón en la tapa |
| **Acción** | producción de un cambio en otro objeto | guarda y transporta agua, y sirve para que yo tome agua |
| **Pasión / afecto** | recepción de un cambio de otro objeto | se llena, se vacía, se cae, se ensucia, se abolla |

- acción → lo que hace la botella. Pasión → lo que le pasa a la botella

---

## Lectura

- (sin entrada por ahora)
