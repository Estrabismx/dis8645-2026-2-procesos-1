# sesion-07a

## apuntes sesión

placeholder %d (número "int") es un espacio reservado que se usa dentro de un string para indicar que aquí se inserta el valor de una variable que es un número entero.

\n (salto de línea) un carácter de escape, significa "enter" obligando a que lo que siga se escriba en la línea de abajo.

orden estándar (ordenao):
```
class Nombre {
public:
variables  | int
           | bool
atributos  | char

//constructor
Nombre(...){
}

//método
abrir(...);
cerrar(...);
```
En la misma clase puede haber más de un constructor con los mismos parámetros

el rut es una variable interna
para el registro civil, ser chileno es una clase
```
//mientras esto sea verdad
//hazlo
//practicamente lo mismo que el void(loop) de arduino
while (true)
```
para acceder a las funciones y estados de una clase ocupamos un punto .
ej: elDeCata.cantidadML, esto nos dice cuantos ml tiene el termo de Cata

%.1f | f es float y se agrega si el número tiene parte decimal
el .1 dice: solo dame 1 decimal
```
//hace que el programa pause o detenga su ejecución durante 1 segundo
sleep_ms(1000)
```

```
class Boton{
public:
//u es porque el número nunca será negativo
bool presionado = 0;
bool normalAbierto = true
uint duracionPresionado = 0;
int patita;
uint vecesPresionado = 0;
char[] nombre;

//constructor
//para evitar confusiones
// ojalá cambiar el nombre del parámetro en el constructor
//constructor le da el valor a la patita
Boton (int nuevaPatita) {
patita = nuevaPatita;
}
}
```
## encargos

## lectura
