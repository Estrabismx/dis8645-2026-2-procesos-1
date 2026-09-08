# sesion-03b

## apuntes sesión

# Apuntes — `char`, `String`, `string`, clases y arrays

## Tipos de datos básicos en C++

En C++ existen tipos de datos que vienen integrados directamente en el lenguaje.

Algunos ejemplos son:

```cpp
int numero = 10;
float temperatura = 20.5;
bool encendido = true;
char letra = 'A';
```

Entre ellos, `char` es un **tipo fundamental de C++**.

Por ende no se necesita importar una biblioteca para utilizarlo.

```cpp
char letra = 'A';
```

## Una palabra está formada por varios `char`

Un solo `char` permite guardar:

```cpp
char letra = 'H';
```

Pero una palabra necesita varios caracteres.

Por ejemplo:

```text
Hola
```

está formada por:

```text
'H' 'o' 'l' 'a'
```

Por eso podemos crear un **array de `char`**:

```cpp
char palabra[] = "Hola";
```

Internamente podemos imaginarlo como:

```text
'H' 'o' 'l' 'a' '\0'
```

El carácter:

```cpp
'\0'
```

indica el final de la cadena de caracteres.

## Acceder a los caracteres

Como `palabra` es un array, podemos acceder a cada posición.

```cpp
char palabra[] = "Hola";
```

```text
palabra[0] → 'H'
palabra[1] → 'o'
palabra[2] → 'l'
palabra[3] → 'a'
palabra[4] → '\0'
```

Los arrays empiezan desde la posición `0`.

# `char[]`

Cuando escribimos:

```cpp
char palabra[] = "Hola";
```

estamos creando directamente un **arreglo de caracteres**.

Entonces:

```text
char
↓
un carácter

char[]
↓
varios caracteres
```

Ejemplo:

```cpp
char autora[] = "Mary Oliver";
```

Conceptualmente:

```text
autora[0]  → 'M'
autora[1]  → 'a'
autora[2]  → 'r'
autora[3]  → 'y'
autora[4]  → ' '
autora[5]  → 'O'
...
```

Esto después permite recorrer el nombre letra por letra.







# `String` con mayúscula

En Arduino existe:

```cpp
String
```

con **S mayúscula**.

Ejemplo:

```cpp
String frase = "Hola";
```

`String` permite trabajar fácilmente con cadenas de texto.

Por ejemplo:

```cpp
String nombre = "Mary";

String mensaje = "Hola " + nombre;
```

Resultado:

```text
Hola Mary
```

Pero `String` **no es un tipo fundamental de C++** como:

```cpp
char
int
float
bool
```


## encargos

Perdón por el atraso con los encargos y también por no haber alcanzado a escribir sobre el libro. Esa semana estuve demasiado angustiada y estresada con todo el proceso para entrar a la práctica, y la verdad no pude con todo emocionalmente.

Ahora ya estoy tratando de ponerme al día con lo que me faltaba. Perdón nuevamente por la demora pipipipi ;-(


encargo-03b:

1. apuntes personales de String, string, array, con bibliografia y con pantallazos de resultados, y dudas textuales.
2. subir código a su bitácora ordenado con el formato de backticks a continuación, del proyecto hasta ahora.
3. definir y escribir el corpus a usar: autora, poemas, licencias, poblarlo en la carpeta 00-proyecto-1

### 1. Apuntes personales — `String`, `string` y `array`

#### `String`

`String` con mayúscula es una clase que usamos en Arduino para trabajar con texto de forma más simple.

```cpp
String nombre = "Mary Oliver";
```

Permite hacer:

```cpp
nombre.length();
```

o juntar textos:

```cpp
String saludo = "Hola " + nombre;
```

A diferencia de `char`, `String` no es un tipo básico de C++.

#### `string`

En C++ también existe `string`, pero pertenece a la biblioteca estándar.

```cpp
#include <string>

std::string nombre = "Mary Oliver";
```

Por esto `String` y `string` no son lo mismo. Además C++ diferencia entre mayúsculas y minúsculas.
 
#### `array`

Un array permite guardar varios elementos del mismo tipo dentro de una misma variable:

```cpp
int numeros[] = {1, 2, 3};
```

Las posiciones comienzan desde `0`:

```cpp
numeros[0];
numeros[1];
numeros[2];
```

En nuestro proyecto usamos arrays para organizar los textos del poema:

```cpp
const char* partesVersos[] = {
  "No tienes que ser buena.",
  "Solo deja que el suave animal",
  "Mientras tanto, el mundo sigue."
};
```
(La coma: , le avisa al programa que es más de uno)

También usamos un array de `char`:

```cpp
const char autora[] = "Mary Oliver";
```

Esto permite recorrer el nombre letra por letra:

```cpp
autora[0] // M
autora[1] // a
autora[2] // r
```

### Pruebas

#### Array de `char`

```cpp
char palabra[] = "Hola";

void setup() {
  Serial.begin(9600);

  Serial.println(palabra[0]);
  Serial.println(palabra[1]);
  Serial.println(palabra[2]);
  Serial.println(palabra[3]);
}

void loop() {
}
```

**Resultado:**

```text
H
o
l
a
```

(Agregar pantallazo del Monitor Serial)

## Código del proyecto hasta ahora

Hasta este punto probamos en conjunto el funcionamiento del potenciómetro, botón y LED. El potenciómetro entrega sus valores por el monitor serial y el botón controla el encendido y apagado del LED.
GRACIAS SEBA POR LA AYUDAAAAAA JIJIJIJIIIIII 

```cpp
const int potenciometro = A0;

const int buttonPin = 12; // pushbutton pin 

const int ledPin = 13; // LED pin 

int buttonState = 0;

void setup() {

  pinMode(ledPin, OUTPUT);

  pinMode(buttonPin, INPUT);

  Serial.begin(9600);

}

void loop() {

  int valorPot = analogRead(potenciometro);

  // potenciometro

  Serial.print("Valor Pote: ");

  Serial.println(valorPot);

  // boton y led

  delay(100);

  // read the state of the pushbutton value:

  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:

  if (buttonState == HIGH) {

    // turn LED on:

    digitalWrite(ledPin, HIGH);

    Serial.println("VALOR boton ");

    Serial.println(buttonState);

  } else {

    // turn LED off:

    digitalWrite(ledPin, LOW);

    Serial.println("VALOR boton ");

    Serial.println(buttonState);

  }

}
```

## Corpus del proyecto

### Autora

Mary Oliver

### Poema

Wild Geese / Gansos salvajes

### Fragmentos a utilizar

- No tienes que ser buena.
- No tienes que recorrer el desierto de rodillas, arrepintiéndote.
- Solo deja que el suave animal de tu cuerpo ame lo que ama.
- Háblame del dolor, del tuyo, yo te hablaré del mío.
- Mientras tanto, el mundo sigue.

### Licencia / créditos

Autora: Mary Oliver  
Poema: Wild Geese  
Año: 1986  
Uso: fragmento utilizado para proyecto académico no comercial.


## lectura

