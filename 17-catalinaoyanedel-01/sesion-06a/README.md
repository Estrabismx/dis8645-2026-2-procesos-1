# sesion-06a
martes 22 de septiembre

## apuntes sesión
- botón: bool estado = 1 o 2
- u int duracionPresionado
- por qué hay que categorizar primero?
- son como los bolsillos: bool bolsillo pequeño, int bolsillo grande
- escalera: int, rampa: float
- int: datos enteros
- float: se parecen a los int pero son necesarios para ciertos cálculos
- u int: unsigned integer
- array: arreglos []

la meta de este semestre es construir Clases

### ejemplos Clases
```cpp
class Estudiante
```

- palabras que son datos que le hemos llamado variables
- palabras con paréntesis que son funciones, que en humano son acciones
- los datos: variables se llaman **atributos** y las acciones: funciones se llaman **métodos**
- materia y energía

```cpp
class Perrite

// atributos
bool hambre = true;
bool durmiendo = true;
pelaje = #000000;

// metodos
ladrar ();
comer ();
jugar();
portarseMal ();
ladrar (int volumen, int frecuencia);
```

```cpp
class Poodle {
superclass Perrite ();

bool molestando = true;
}
```
- herencia: esta Clase hereda todo lo que tiene la otra.
- plan z hagamos un asado

#### ejemplo:

| Clase | Instancia |
| --- | --- |
| Poodle | copito |

Poodle pelusa;

```cpp
Perrites

perrites =
{ copito,
  pelusa,
}
```

```cpp
perrito.ladrar();
```

#### ejercicio

```cpp
// ejercicio para caracterizarme

// atributos
bool descansada = false;
bool hidratada = true;
char[] miPerrita = 'pelusa';

// metodos
tomarTe();
dormir(calidad);

```
- dentro de los métodos se puede agregar entre paréntesis un parámetro para especificar.
______________________________

## post-break
### ejercicio
- buscar un objeto
- buscar las categorías de Aristóteles
- _*recomendación libro: tímidos radicales, autor que escribe su propia constitución, reflexionar sobre cómo se pueden crear mundos con las palabras, por lo tanto, también en la programación_

_Vista de IA de Google:_

De acuerdo con Aristóteles, todo lo que existe y se puede nombrar pertenece a una de estas diez categorías:

- **Sustancia (ousia):** Lo que existe en sí mismo y no en otro (por ejemplo, un hombre, un caballo). Es el sujeto fundamental sobre el cual recaen las demás.
- **Cantidad (poson):** La magnitud, el número o la medida de la sustancia (por ejemplo, dos metros, tres kilos).
- **Cualidad (poion):** Las características, propiedades o atributos de la sustancia (por ejemplo, blanco, caliente, inteligente).
- **Relación (pros ti):** La conexión o referencia de una sustancia con otra (por ejemplo, doble, mayor, padre).
- **Lugar (pou):** La ubicación o sitio espacial donde se encuentra el objeto (por ejemplo, en la plaza, en casa).
- **Tiempo (pote):** El momento o duración temporal en que ocurre algo (por ejemplo, ayer, el año pasado).
- **Posición / Situación (keisthai):** La postura o disposición espacial de las partes del cuerpo (por ejemplo, sentado, acostado).
- **Posesión / Hábito (echein):** Lo que la sustancia tiene o porta externamente (por ejemplo, calzado, armado).
- **Acción (poiein):** Lo que la sustancia hace, el cambio que produce en otro (por ejemplo, cortar, quemar).
- **Pasión (paschein):** Lo que la sustancia padece o recibe de otro (por ejemplo, ser cortado, ser calentado)

recordatorio de anotar las horas que uno se dedica a trabajar en algo ! 

- rasperry pi pico 2w
- el chip que lo controla es el **rp2040**
- kicanvas: visor de circuito
- usar wokwi como simulador para la rasperry > starter templates > Blink
- Pico SDK Examples: ejemplos más crudos
  
## encargos
a partir de las definiciones que leí anteriormente, elegí como mi objeto mi termo con tecito que suelo andar trayendo, así que estas son sus categoría:

- sustancia: el termo
- cantidad: 800ml
- cualidad: blanco, metálico, térmico
- relación: contenedor de mi té (respecto a mi)
- lugar: en mi escritorio
- tiempo: ahora mismo / jueves 24 de sept. 11:45pm
- posición: vertical
- posesión: líquido
- acción: mantener un líquido caliente o frío el mayor tiempo posible
- pasión: ser llenado y transportado

## corrección encargo
- lugar: en la mesa en la que me encuentre
- un litro es un decimetro cúbico
- lamentablemente mi termo es inerte así que puede que esas no sean sus pasiones...
- la pasión puede entenderse como las alteraciones que sufre una sustancia
- know-how: lo práctico 
- know-what: lo que se aprende en la universidad, lo teórico

## lectura
