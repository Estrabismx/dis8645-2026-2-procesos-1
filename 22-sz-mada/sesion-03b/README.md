# sesion-03b

2026.08.28

## apuntes sesión

### Teloneo pre-9:00am

Aarón nos habló sobre temas legales ya que algunos grupos trabajarán con poetas aún vivos, así que sus poemas están sujetos a derechos de copyright. Nos leyó el MIT LICENSE que aparece por default en el repo de github. Alguien mencionó Creative Commons, así que habló de ese tipo? de licencia también

Creative Commons no es **una** licencia, es un **conjunto** de licencias (CC BY, CC BY-SA, y CC BY-ND)

Otras licencias: Anti-capitalist Software License, do What The Fuck you want to Public Licence, GNU General Public License

Copyright por texto?? dura la vida del autor **MÁS** 70 años, luego se convierte en dominio público

Aarón trajo cajas para que cada persona pueda tener sus componentes ordenados en un solo lugar. Dijo que cuando estuviera un grupo completo, cada integrante podía ir a buscar su caja, así que yo no fui lol; pero Emilia?? i think me entregó una.

### Bloque 9:00 - 10:30

Strings (computer science) according to WIkipedia: are typically made up of characters and are often used to store human-readable data such as words or sentences.

[Arduino has C++ strings](https://docs.arduino.cc/language-reference/en/variables/data-types/stringObject/) that are **only valid** for Arduino.

String() construye una instancia de la clase *String*

- string of characters in double quotes ej. ```"wawawa"```
- single constant character in single quote ej. ```'w'```

```cpp
String thisString = String(13);
// String(13) puede reemplazarse por cualquier cosa, ej. "sopaipilla"
```

[Char functions](https://docs.arduino.cc/built-in-examples/strings/StringCharacters/): La función ```charAt()``` returns un carácter en una dada posición, ```setCharAt()``` reemplaza un carácter en una dada posición

[string](https://docs.arduino.cc/language-reference/en/variables/data-types/string/) (ojo! en minúscula): you can use the String data type, or you can make a string out of an array of type char and null-terminate it.

[ ] &larr; implica arreglo, qué va adentro? cuan grande es el arreglo (wat dat mean?)

Ej.

```cpp
char Str1[15] = "arduino";
// "Str1" bad example, mayúsculas para clases, who cares para arreglos
```

```cpp
int edadAaron = 37;
int edadSeba = 22;
int edadEmi = 24;
// awful, too much to rewrite when you have too many variables
```

```cpp
int edades[36];

edades = {
21,
21,
21,
22,
// etc

}
```

Thing i just learned: using just ```serial.print``` prints on the same line, use ```serial.println``` for what i assume is state the end of said line.

```cpp
// declaracion de arreglo de enteros
// que se llama edades
int edades[3] = { 37, 22, 24 };

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.print(edades[0]); // 0 es siempre el primer carácter en coding
  Serial.print(", ");
  Serial.print(edades[1]);
  Serial.print(", ");
  Serial.println(edades[2]);
}
```

```cpp
char nombre = 'a';
// permite un solo carácter

char nombre[6] = "aaron";
// el arreglo permite añadir más carácteres
// always add one more number al arreglo para denotar donde termina or something like that
```

```cpp
char *misVersos[] = {
  "Mami, no te haga' de rogar",
  "No me gustaría perder el tiempo",
  "Que tenemo' pa' poderte tocar",
  "Y estás con otro, esa mierda no lo entiendo, yeah",
  "Que te lo juro, no eres nada pa' mí, te lo juro, ah",};

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println(misVersos[0]);
}
```

[ASCII codes](https://www.ascii-code.com/)

```for()``` es para recorrer conjuntos. you've to state where does it start, when does it stop, and what does it do afterwards

```cpp
for (int i = 0; i < 5; i++) {
    Serial.println(misVersos[i]);
}
```

## encargos

encargo-03b:

1. apuntes personales de String, string, array, con bibliografia y con pantallazos de resultados, y dudas textuales.
2. subir código a su bitácora ordenado con el formato de backticks a continuación, del proyecto hasta ahora.
3. definir y escribir el corpus a usar: autora, poemas, licencias, poblarlo en la carpeta 00-proyecto-1


```cpp
// codigo aqui
// por ejemplo
```

## lectura

