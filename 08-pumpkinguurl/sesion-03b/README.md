# sesion-03b

## apuntes sesión
c++ (85) esta escrito sobre c (72)

como hacer strings en Arduino 

Arduino sirve para empezar pero luego lo vamos a abandonar

no programar en Arduino

si una palabra tiene la primera letra mayúscula es pq es una clase

las clases las veremos dsp del receso

formas de crear stirngs en Arduino

string secuencia de caracteres

string  entre comillas dobles

versión particular de un carácter con comillas simples 

las comillas se usan para encerrar txto

en c++ las dobles son para palabras 

los caracteres como constructo de datos se usan comillas simples

String thisString = String(13)

(tipo de variable) (nombre) = (en ese lugar hazme un string donde quepan 13 caracteres)

se le puede agregar el valor directo que medirá y también escribir la palabra y el programa las contará

charAt() me puedes decir cual es el carácter que esta en …

setCharAt() configurar el charAt

el texto se puede escribir de dos formas String()  pero también puedes decir existen caracteres y puedes hacer un arreglo de caracteres, se puede hacer arreglo de lo que sea

array of type char and null-terminate it

arreglo tiene que ver con conexión/arreglo floral

[] corchete implica arreglo

adentro va el tamaño del arreglo

no se permiten ampliaciones

si pones 8, son 8

char palabrita[8] = "Arduino"; 

en la palabrita va cualquier nombre

las mayúsculas se usan en las clases, no usar en otra cosa que no sea clase si no lo amerita

la cantidad se puede poner explícita (la cantidad exacta( o implícitamente (cuéntalos tu)

puedes poner una o la otra o las dos
```cpp

//declaración de arreglo de enteros
//que se llama edades
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
serial.print los ordena hacia el lado

serial.println hacía abajo

de la cantidad total de letras que tenga la palabra hay que colocar uno más que será el carácter que indica que termina la palabra

```cpp

// bah que raro
// con 5 no funciono
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

se pude hacer arreglo de arreglos

poemario arreglo de paginas

paginas arreglo de líneas

líneas arreglo de caracteres

los sueños del profe no caben en un Excel, el crea su propio Excel. Tenemos que crear nuestros propios Excel

asterisco - profundidad de programación, muy duro

nos permite hacer un arreglo de arreglos y dejas de preocuparnos de cuanto mide

```cpp

// un poemario
// es un arreglo de paginas
// una pagina es un arreglo de lineas
// una linea es un arreglo de caracteres

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

char para c++

```cpp

// un poemario
// es un arreglo de paginas
// una pagina es un arreglo de lineas
// una linea es un arreglo de caracteres

char *misVersos[] = {
  "Mami, no te haga' de rogar",
  "No me gustaría perder el tiempo",
  "Que tenemo' pa' poderte tocar",
  "Y estás con otro, esa mierda no lo entiendo, yeah",
  "Que te lo juro, no eres nada pa' mí, te lo juro, ah",
};


void setup() {
  Serial.begin(9600);
}

void loop() {

  // recorrer el arreglo
  // for es para recorrer conjuntos
  // adentro tiene 3 mini lineas
  // inicio de los tiempos
  // oye pero cuando paro
  // que hago despues de cada iteracion
  for (int i = 0; i < 5; i++) {
    Serial.println(misVersos[i]);
  }
}
```

hacer que corra primero en el computador después en la pantalla

si el potenciómetro esta entre {x,y} muéstrame el verso 0

si esta entre {a,b} muéstrame el verso 1
…
 


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

