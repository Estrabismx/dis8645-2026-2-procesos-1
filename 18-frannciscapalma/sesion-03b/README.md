# sesion-03b

## apuntes sesión

cómo hacer string en arduino con c++?


String: Un string (o cadena de caracteres) es un tipo de dato que representa texto. Se forma al unir letras, números o símbolos dentro de comillas 


Existe una clase que se llama string, hay varias versiones de hacerlo, (cuando algo tiene una clase se usa mayúscula). Ejemplos de String:


-con doble comilla: “texto” secuencia de caracteres
-con comilla simple: ‘t’ esto es para un carácter


A diferencia del tipo básico char (que solo guarda una letra) o de los arreglos de caracteres del lenguaje C, la clase std::string de C++ administra la memoria de forma automática y ofrece funciones útiles para manipular textos con facilidad.  


String: complejo, estructura ficticia
char: existen caracteres y se puede hacer un arreglo


char Str5[8] = “arduino”; //los corchetes significan arreglos. Str5 es el nombre que le pusieron, puede ser por ejemplo: palabrita. 


ejemplo:


´´´cpp
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
´´´
ejemplo de char:


´´´cpp
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


´´´


// un poemario
// es un arreglo de paginas
// una pagina es un arreglo de lineas
// una linea es un arreglo de caracteres




el asterisco es para dejar de preocuparnos cuanto mide el string. La palabra string con mayúscula es propia de arduino y Aarón nos invita a no usarla


Para iterar se usa el for()
//for recorre conjuntos
//adentro tiene 3 mini lineas
// inicio de los tiempos
//oye pero cuando paro
//que hago despues de caditeracion
for (int i = 0; i <5; i++) {
Serial.println(misVersos)[i])
i++ signifa que lo que sea que valga i, sumale uno más


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










// bah que raro
// con 5 no funciono
char nombre[6] = "aaron";


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

