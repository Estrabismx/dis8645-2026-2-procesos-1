# sesion-06a
Hola profe Aarón,Misa, Emi y Sebas. Espero que se encuentren bien cuando estén leyendo por aquí!

Hoy vimos: 
1. Objetivo de la clase
2. Variables y sus tipos
3. Clases
4. Atributos
5. Métodos
6. Función vs. método
7. Clase e instancia
8. Superclass
9. Arrays
10. El for
11. Ejercicio: la clase `Estudiante`
12. Reglas de escritura
13. int main
14. Materia y energía
15. Sumary

# apuntes sesión

## 1. Objetivo de la clase

En clase vimos algo nuevo: **agrupar datos y acciones dentro de una misma cosa** (un objeto).

> **Cómo entenderlo:** Un perro real, no lo describes solo con datos ("tiene hambre", "tiene pelaje"), también con lo que puede hacer ("ladra", "come", "duerme"). Una clase junta ambas cosas en un solo paquete.

---

## 2. Variables y sus tipos

Una **variable** guarda un dato. Es como un contenedor, y el **tipo** define qué se puede guardar dentro.

| Tipo | Guarda | Ejemplo | Imagen mental |
|---|---|---|---|
| `bool` | Solo `true` o `false` | `bool caminar = true;` | Un interruptor (prendido/apagado) |
| `int` | Números enteros | `int cantidad = 3;` | Una **escalera**: 1 → 2 → 3, sin nada en medio |
| `float` | Números con decimales | `float valor = 1.5;` | Una **rampa**: entre 1.0 y 2.0 hay infinitos valores |
| `uint` | Enteros sin signo negativo | `0, 1, 2, 3...` | Una escalera que solo sube desde cero: no existe el `-1` |

**Para qué sirve cada uno:** `bool` sirve para "se cumple / no se cumple" o "presente / ausente". `int` para contar cosas (3 manzanas). `float` para medir (1.5 metros). `uint` cuando un número negativo no tiene sentido (por ejemplo, una cantidad de personas).

---

## 3. Clases

Una `class` **no es una variable**. Es una forma de juntar:

- **datos** (lo que algo *tiene* o *es*)
- **acciones** (lo que algo *puede hacer*)

```cpp
class Estudiante {

};
```

**Reglas de nombre:**
- Empieza con **mayúscula**: `Estudiante`, `Perrito`, `Poodle`.
- Se escribe en **singular**. Es *un* estudiante, no "estudiantes", porque es el molde de uno.

---

## 4. Atributos

Los **atributos** son los datos que están *dentro* de una clase. Responden: ¿qué tiene?, ¿cómo es?, ¿en qué estado está?

```cpp
class Perrito {

    bool hambre;
    bool durmiendo;
    int pelaje;

};
```

**`hambre`, `durmiendo` y `pelaje` son atributos.**

> **Ojo con la terminología:** una variable que vive dentro de una clase se llama **atributo**. Es lo mismo que una variable, pero con otro nombre porque pertenece a una clase.
>
> `datos → variables → atributos (cuando están dentro de una clase)`

---

## 5. Métodos

Los **métodos** son las **acciones** que puede hacer algo: `comer()`, `dormir()`, `ladrar()`.

**Truco para distinguirlos de los atributos:**

- **Sustantivos / características → atributos** (hambre, pelaje)
- **Verbos / `acciones → métodos`** (comer, ladrar)

---

## 6. Función vs. método

Una **función** es un bloque de código con un nombre y una serie de instrucciones. Se reconoce porque lleva `()`.

```cpp
void ladrar() {

}
```

Cuando esa función está **dentro de una clase**, se llama **método**.

```cpp
class Perrito {

    void ladrar() {

    }

};
```

Una función también puede **recibir datos** (se ponen entre los paréntesis):

```cpp
void ladrar(int volumen, int frecuencia) {

}
```

`volumen` y `frecuencia` son los datos que la función necesita para hacer su trabajo.

> **Resumen del vocabulario:** variable ↔ atributo, y función ↔ método. Lo primero es "suelto", lo segundo es "dentro de una clase".

---

## 7. Clase e instancia

- **Clase** = el **molde**
- **Instancia** = una **cosa concreta** creada con ese molde

```text
Poodle          ← clase (el molde)
│
├── Copito      ← instancia
└── Pelusa      ← instancia
```

```cpp
Poodle copito;
Poodle pelusa;
```

Copito y Pelusa son objetos de la clase `Poodle`.

**Lo importante:** la clase define **qué** atributos y métodos existen. Cada instancia después tiene **sus propios valores**. Ambos perros tienen `hambre`, pero Copito puede tener `hambre = true` y Pelusa `hambre = false`.

> **Analogía:** el molde de galletas es la clase. Cada galleta que sale es una instancia. Todas tienen la misma forma, pero cada una puede tener distinto sabor o decoración.

---

## 8. Superclass

Una **superclass** es una clase **más general**. Sirve para ordenar de lo general a lo específico.

`Perro → Poodle → Copito`

- `Perro` → la más general
- `Poodle` → más específica
- `Copito` → la instancia (ya no es clase, es una cosa concreta)

---

## 9. Arrays

Un **array** guarda **varios elementos del mismo tipo** en un solo lugar.

```cpp
Poodle perrites[] = {
    copito,
    pelusa
};
```

- `Poodle` → el tipo de elementos
- `perrites` → el nombre del array
- `copito` y `pelusa` → los elementos

---

## 10. El `for`

El `for` **recorre** los elementos de un array y **repite una acción** por cada uno.

```cpp
for (Poodle perrite : perrites) {
    perrite.ladrar();
}
```

**Se lee así:** "por cada `perrite` dentro de `perrites`, ejecutar `ladrar()`".

Recorre `copito` y luego `pelusa`, **sin tener que escribir la acción una vez por cada perro**. Si tuvieras 100 perros, el código sería igual de corto.

---

## 11. Ejercicio: la clase `Estudiante`

La clase es el molde y cada alumno es una instancia:

```text
Estudiante
│
├── yo
├── estudiante 2
└── estudiante 3
```

### Atributos (cómo es / en qué estado está)

```cpp
class Estudiante {

    bool sentado;
    bool tienePelo;
    bool tieneRulos;

};
```

Todos los estudiantes tienen estos atributos, pero **los valores cambian** según la persona:

```text
sentado = true
tienePelo = true
tieneRulos = true
```

### Métodos (acciones)

Por ejemplo: `ponerseCrema();`

**Regla clave:** los métodos deben tener **relación con los atributos**. Un método puede **leer** o **modificar** un atributo.

Aquí: `ponerseCrema()` → `tieneRulos`

Van **desde los métodos hacia los atributos**:

**método → atributo**

Porque el método **actúa sobre** el atributo. Es el método el que "hace algo" al dato.

### Mi clase

**Atributos:** `misListas` (array), `miedos` (array), `caminar` (bool), `pasarloBien`, `amistades`

```cpp
class Estudiante {

    string misListas[];
    string miedos[];
    bool caminar;
    bool pasarloBien;
    string amistades[];

};
```

**Métodos y a qué atributo apuntan:**

| Método | → Atributo |
|---|---|
| `crearLista()` | `misListas` |
| `crearMiedo()` | `miedos` |
| método de caminar (cambia `caminar` a `true`) | `caminar` |
| método de amistades (agrega amistades) | `amistades` |

Estructura general:

```text
CLASE
│
├── ATRIBUTOS
│   └── datos
│
└── MÉTODOS
    └── acciones
```

---

## 12. Reglas de escritura

| Qué | Cómo empieza | Ejemplos |
|---|---|---|
| **Clases** | Mayúscula | `Perrito`, `Poodle`, `Estudiante` |
| **Atributos, variables y métodos** | minúscula | `hambre`, `pelaje`, `ladrar`, `crearLista` |

Si el nombre tiene varias palabras, cada palabra nueva va con mayúscula pegada (**camelCase**): `pasarloBien`, `crearMiedo`, `misListas`.

**Importante:** para el computador, `Perrito` y `perrito` son **nombres distintos**. Importan las mayúsculas y minúsculas.

---

## 13. `int main()`

`main()` es **donde comienza a ejecutarse el programa**.

```cpp
int main() {

    Poodle copito;

    copito.ladrar();

}
```

Desde `main()` se **crean objetos** y se **ejecutan sus métodos**.

El **punto `.`** significa "accede a algo que pertenece a este objeto":

```cpp
copito.ladrar();   // "copito, ladra"
```

---

## 14. Materia y energía

- **Las cosas → materia**
- **Las cosas que mueven las cosas → energía**

Llevado a programación:

| Idea | En programación |
|---|---|
| La cosa (materia) | **objeto** |
| Lo que la describe | **atributos** (sus datos) |
| Lo que la mueve (energía) | **métodos** (sus acciones) |

---

## 15. Resumen para repasar

- **variable** → guarda un dato
- **`bool`** → `true` o `false`
- **`int`** → entero
- **`float`** → con decimales
- **`uint`** → entero sin negativos
- **class** → agrupa datos y acciones (el molde)
- **atributo** → variable dentro de una clase
- **método** → función dentro de una clase
- **instancia / objeto** → cosa concreta creada desde una clase
- **array** → varios elementos del mismo tipo
- **`for`** → recorre elementos y repite una acción
- **superclass** → clase más general


## encargos
seleccionar un objeto y clasificarlo según las categorías del ser de aristóteles  
[Las 10 categorías del ser](https://es.scribd.com/document/463976784/CATEGORIAS-DEL-SER#google_vignette)

### Objeto escogido: Boleto de entrada al museo de arte precolombino 

![](./imagenes/objeto.jpeg)

#### Sustancia: 
Papel térmico y tinta impresa: celulosa purificada (fibra de madera) y un complejo sistema químico de microcápsulas y resinas reactivas que permiten duplicar la escritura sin usar papel carbón.

#### Cantidad: 
Hay 1 entrada (una factura), con 1 código QR. Sirve para 2 personas, y el total cancelado es $0.

#### Cualidad: 
Se diferencia de otros papeles porque es único: lleva un QR propio, la fecha de compra y los datos del museo, y "puede ser utilizado solamente una vez". Sirve para ingresar al Museo Chileno de Arte Precolombino.

#### Relación:
Es más frágil y desechable que una entrada de plástico o una tarjeta. Comparada con una entrada de pago, esta vale $0 pero habilita lo mismo. Además, está más arrugada y gastada que una entrada nueva.

#### Tiempo: 
Adquirida el 24-09-2026 a las 15:08:06, hace 5 días. Fue en la tarde.

#### Lugar:
Es una hoja angosta y alargada que cabe en una mano; en la foto, entre los dedos de quien la sostiene.

#### Posición:
Está en posición vertical, sostenida por una mano (el pulgar arriba a la izquierda), con un fondo rojo y oscuro detrás.

#### Estado:
Está arrugada, con pliegues marcados y doblada en varios puntos, pero legible y con el QR reconocible. Todavía sirve, aunque ya no está como nueva.

#### Acción:
Fue impresa al emitirse, se dobló y se guardó, y quien la sostiene la exhibió para la foto. Al ingresar al museo, se escanea el QR.

#### Pasión:
Sufrió arrugas, dobleces y desgaste por el uso y el recuerdo. 

# Lectura 
Guys i'm so srry. I have stop reading the book bc it's about exercices, and u have to research by ur own, and it's great..., but I haven't take time apart to do them and learn... 

¿Can I change it for another book, and then after the octber 13, can I go back to the one I have now?
