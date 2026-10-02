# sesion-07a

## apuntes sesión
una función tiene un int main, dentro de eso está todo lo que ocurre. todo lo que est´fuera, es infraestructura que nos ayuda a que cuando pase int main todo funcione

el if es una pregunta

printf("..")

%d = placeholder (jefe lo hago al tiro), número entero
\n = enter, salto de línea 

```cpp
// estructura típica:
class Nombre {
public:
// int     // variables, atributos
// bools
// char

Nombre (...) { // método constructor 
}
	abrir(...); // métodos en general (funciones en una clase)
	cerrar(...);
};
```

en la misma clase puede haber más de un constructor

while (true) -> mientras es verdad, hazlo. cuando sea falso, para. es como un void loop de arduino pero más crudo.
el main sucede una vez pero nunca va a parar ya que se queda atrapado en un while true.

e.o.c -> en otro caso

_%.1f_

%. -> place holder, aquí va un valor que voy a cambiar

f -> float, para mostrar decimales 
  
.1 -> dame solo un decimal

---

## botones

atributos:

+ bool presionado = 0;
+ bool normallyOpen = true;
+ int patita; // este es buen candidato para constructor
+ Uint vecesPresionado = 0;
+ char [] nombre;

constructor:

```cpp
Boton (~int patita~ nuevaPatita) {
	 patita = ~int patita~ nuevaPatita;
}
```

métodos:

```cpp
void leer();
```

al hacer archivos tendremos:

+ main.cpp
+ Boton.cpp // estos son en el caso del ejemplo
+ Boton.h // ya que tenemos la clase Boton, por eso se llaman así
	// h es de header kkkkkkkk

## encargos

1. usar el ejemplo base visto en clases <https://wokwi.com/projects/476507507193136129>, agregar un segundo botón en la simulación de hardware, agregar una segunda instancia de la clase Boton, agregarle un atributo y un método a la clase Boton, y hacer que el segundo botón haga algo diferente al primero.
2. descargar todos los archivos de wokwi, descomprimir el archivo.zip y subir esa carpeta a tu repositorio en esta sesión.

## lectura
