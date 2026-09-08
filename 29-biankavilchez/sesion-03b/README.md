# sesion-03b

## apuntes sesión

- Poesía computacional / generativa: **Ramsey Nasser**, **Allison Parrish**, **Nick Montfort**

- Documentación oficial:
  
  - [String Object – Arduino Docs](https://docs.arduino.cc/language-reference/en/variables/data-types/stringObject/)
  - [StringCharacters – ejemplo built-in](https://docs.arduino.cc/built-in-examples/strings/StringCharacters/)
  - [String (char array) – Arduino Docs](https://docs.arduino.cc/language-reference/en/variables/data-types/string/)


### string vs char array

un string es una secuencia que tiene más de un carácter.

programar en C++ pensando en que funcione en cualquier lado, sin usar las funciones propias de Arduino — Arduino creó sus propias funciones sobre C++.

- **String** (con mayúscula) es una **clase**: cuando algo empieza con mayúscula, es una clase.(Se usa recién después de la clase 18) 
  - Ejemplo: `String thisString = String(13);`
    
  - Regla: no se anticipa cuánto va a medir  hay que anticipar el tamaño.
    
  - Funciones 
    - `charAt()` → da la posición de un carácter
    - `setCharAt()` → permite configurar/cambiar un carácter dentro del string (ej. en la posición 4, cambiarlo por `n`)

- **string minúscula / char array**: no es una clase compleja, es una estructura más ficticia:
  
  - Es un **arreglo de caracteres**
  - Una constante de caracteres entre **comillas dobles** (ej. `"aaron"`) es un char array
  - Una **constante de un solo carácter** va entre **comillas simples** (ej. `'a'`)
    
  - Regla: comillas **simples** si es **uno**, comillas **dobles** cuando son **varios**
  - `[]` permite declarar un arreglo, definiendo qué tan grande es:
```cpp
    char Str4[] = "arduino";
    char Str5[8] = "arduino";
    char Str6[15] = "Arduino";
```
### arreglos (arrays)

```cpp
int edades[5];
edades = {32, 15, 25, 100, 200}; // el 5 queda implícito por la cantidad de elementos
```

```cpp
// declaracion de arreglo de enteros
// que se llama edades
int edades[3] = { 37, 22, 24 };

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.print(edades[0]);
  Serial.print(", ");
  Serial.print(edades[1]);
  Serial.print(", ");
  Serial.println(edades[2]);
}
```

```cpp
// con 6 posiciones para "aaron" funcionó, con 5 no
char nombre[6] = "aaron";

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.print(nombre[0]);
  Serial.print(nombre[1]);
  Serial.print(nombre[2]);
  Serial.print(nombre[3]);
  Serial.println(nombre[4]);
}
```

### para un poema 

> Un poemario es un arreglo de páginas.
> Una página es un arreglo de líneas.
> Una línea es un arreglo de caracteres.

```cpp
char *misVersos; // arreglo de arreglos
```

cada carácter tiene, a su vez, un valor **ASCII** detrás.

### Recorrer arreglos con `for`

un arreglo se puede recorrer de forma estratégica. Dentro del `for` hay tres partes:
- **inicio**: `int i = 0`
- **condición de parada**: `i < 5`
- **qué hago después de cada iteración**: `i++`

```cpp
for (int i = 0; i < 5; i++) {
  // i++ → lo que sea que valga i, vale uno más
}
```
## encargos

encargo-03b:

1. apuntes personales de String, string, array, con bibliografia y con pantallazos de resultados, y dudas textuales.
3. subir código a su bitácora ordenado con el formato de backticks a continuación, del proyecto hasta ahora.
5. definir y escribir el corpus a usar: autora, poemas, licencias, poblarlo en la carpeta 00-proyecto-1

### avance del proyecto: 

### poemas 

- primer poema propuesto: "cine", de victoria ramírez mansilla — no se pudo usar por derechos de autor, pero ayudó a conceptualizar decisiones del proyecto.
- poema final: soneto XXII, de elizabeth barrett browning (traducción al español).

### poema descartado (por derechos)

cine — victoria ramírez mansilla

> luces bajas y escaleras de lava negra
> me toman la mano y es una mano áspera
> casi todas las manos de mujer son suaves
> el deseo se me presenta como una cuenca
> acomodo las palmas y ellas se adaptan
> a las cosas que sospecho amar
> me dejo llevar por el cordel
> apenas logro concentrarme en la historia
> mi pecho es un instrumento de viento
> demasiado distante
> quiero decir que admiro la manera
> en que el cuello sostiene su cabeza
> quiero decir que entiendo
> la entrega de la fracción
> de la fracción de la fracción.

no lo podemos ocupar por los derechos, pero nos ayudó a conceptualizar decisiones del poema:

el poema habla del encuentro de dos personas, en un cine.
  
- surgieron ideas que se van a mantener:
  
hablar de la aceleración y relacionarla con el tiempo: con el potenciómetro vamos a medir qué tan rápido va avanzando el poema.

dos personas se conectan para crear algo que funcione, como si una dependiera de la otra. mantenemos la idea de que al presionar un botón, se genera una acción incompleta; al presionar dos, se puede visualizar la acción completa.
  
estructura conceptual del poema: dos personas se encuentran → aparece la intimidad → comienzan a mezclarse sus percepciones → la experiencia se fragmenta → quedan pequeños rastros.


### flujo de funcionamiento del proyecto

1. inicia el arduino.
2. el texto avanzará de manera continua hasta que se presionen los botones o se manipule el potenciómetro.
3. en caso de presionarse solo un botón, el texto se congela y no sigue avanzando hasta que se deje de presionar.
4. si son los 2 botones, se detiene el texto y desaparece.
5. mientras esto ocurre, se consulta en qué sección del texto se encuentra.
6. en base a la sección del texto mostrado, se visualizará una palabra clave.
7. al dejar de presionar un botón, vuelve a ocurrir el punto 3.
8. si se sueltan ambos botones, desaparece la palabra.
9. luego continúa avanzando el texto desde el mismo punto en el que quedó.
10. en caso de ser manipulado el potenciómetro, se modificará la velocidad del texto (mientras más lejos del centro, más rápido el cambio).
11. si se rota hacia la derecha, avanza de manera normal, solo variando la velocidad.
12. si se rota hacia la izquierda, retrocede el texto, según qué tan lejos del centro esté.


### poema final

soneto XXII — elizabeth barrett browning (traducción)

> cuando están nuestras almas frente a frente, mudas, erguidas, fuertes, ya muy próximas, y sus alas se encienden al tocarse, ¿qué podemos temer en este mundo, qué anhelos no podrán satisfacerse? piensa que si ascendemos a la altura acudirán los ángeles queriendo romper con su voz áurea y perfecta nuestro amado silencio. no, es mejor, amor mío, quedarnos en la tierra, donde el afán absurdo de los hombres a las almas más puras les concede un lugar donde amarse en esta vida, cercado por la muerte y las tinieblas.

### código: arreglo de versos

```cpp
char *versosPoema[] = {
  "cuando nuestras dos almas se eleven, firmes y fuertes,",
  "frente a frente, en silencio, acercándose más y más,",
  "hasta que las alas que se alargan estallan en fuego",
  "en cada punta curva ¿qué mal amargo",
  "puede hacernos la tierra, que no debiéramos",
  "quedarnos aquí, contentos? piénsalo. al subir más alto,",
  "los ángeles nos oprimirían y aspirarían",
  "a dejar caer algún áureo orbe de canto perfecto",
  "en nuestro hondo, querido silencio. quedémonos",
  "mejor en la tierra, amado mío, donde los ánimos",
  "contrarios e injustos de los hombres retroceden",
  "y aíslan a los espíritus puros, y permiten",
  "un lugar donde estar y amar por un día,",
  "con la oscuridad y la hora de la muerte rodeándolo."
};
```

## lectura

