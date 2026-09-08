# sesion-01b

2026.08.14

## apuntes sesión

No asistí a esta clase, así que estos "apuntes" son basados en lo que entendí según los apuntes de mis compañeros.

---

Las variables tienen tipo, nombre y valor.

Eg.

```cpp
int sz-madaEdad = 25;
```

Se le agrega `const` adelante del tipo para que se transforme en una constante.

Se mencionaron dos variables que yo no conocía previamente: `int8_t` y `uint8_t`. La segunda guarda valores entre 0 a 255; ambas son exactamente 8 bits, o 1 byte.

---

Ahora comienza una introducción a Arduino IDE, instalándolo y descargando¿ un plugin para que el programa sea capaz de leer el Arduino que fue trabajado en clase (Arduino UNO R4 WiFi)

![Instalación plugin](./imagenes/arduino-r4.png)

Este programa funciona por medio de código C++, el cuál viene con una plantilla predeterminada para que uno comience a escribir su código.

![Código predeterminado al iniciar Arduino](./imagenes/arduino-default-code.png)

Como dice la descripción de `void setup()`, en esta sección se escribe todo lo necesario para comenzar a preparar el código (hence: setup). Este se ejecuta una sola vez al encender el Arduino.

```cpp
void setup() {
    // put your setup code here, to run once

}
```

Una vez el setup es ejecutado, Arduino pasa a la siguiente sección, la cual es `void loop()`. Este, como lo dice el nombre, se repite indefinidamente.

```cpp
void loop() {
    // put your main code here, to run repeatedly

}
```

---

Un solo `=` es una asignación de valor, mientras que dos (`==`) es una comparación of sorts. Si digo `age = 22;` estoy estableciendo que `age` es 22, mientras que `age == 22;` está preguntando IF `age` es 22, la respuesta a esto será un boolean (either true or false).

`if` establece una condicional

Eg.

```cpp
if (mesActual == luNacimientoMes) {
    // estoy en el mes de interés

if (diaActual == luNacimientoDia) {
    // estoy en el día de interés
```

Estas funciones se pueden combinar por medio del uso de `&&`, lo cual es la compuerta **AND** (para **OR** y **NOT**, se utiliza `||` y `!` respectivamente)

```cpp
if (mesActual == luNacimientoMes && diaActual == luNacimientoDia) {
    // estoy en mi cumpleaños :]
```

Para indicar qué hacer en caso de que el `if` sea falso, se utiliza `else`.

|operador|meaning|
|-|-|
|==|equals|
|!=|distinto a|
|>|more than|
|<|less than|
|>=|more or equal than|
|<=|less or equal than|

Los números también pueden representarse de manera hexadecimal, which range from 0 to 9, and A to F (hence **hex** code for colours). Desde A a F representan de 10 a 15.

- Fun fact: uno puede contar hasta 31 en una sola mano si se utilizan los dedos para contar en binario

## encargos

encargo01b:

1. tratar de correr un código en el microcontrolador asignado a cada dupla, incluir referentes, citas, comentarios, imágenes, descripciones textuales, y en caso de éxito o fracaso incluir aciertos, preguntas, dramas, atados. recordatorio que estos apuntes son personales, cada persona sube su versión.
2. proponer una función con nombre, tipo, argumentos y uso, que modele algún área de su interés, por ejemplo subirCerro(enBicicleta), tomarMetro(conPaseEscolar), etc. escribir en pseudocódigo los pasos que necesita esa función internamente para que literalmente funcione.
