# sesion-07a

## apuntes sesión
En una clase puede haber más de un constructor pero con distintos parámetros.
Los valores se pueden cambiar con métodos

```cpp
Class Termo {
  // palabra clave public
  // la usaremos este semestre
  public:
    // atributos de la clase
    // (variables internas) 
    bool existencia = true;
    bool abierto = false;
    int posicion = 0;
    int cantidadML;
    float temperatura = 100.0;
    int rodamientos = 5;
```

Se define la clase termo y luego le damos unos atributos, como por ejemplo que la existencia del termo es verdad o que su posición inicial es 0.

No siempre hace falta darle un valor al hacer una variable, existen otros métodos, Aarón en la línea 16 "int cantidadML;" no le ha dado ningún valor.
"main" significa todo el programa.
/n es el equivalente de ln, es decir que haga print en una nueva linea.
Else se traduce a en otro caso, si el if no es verdad, en el otro caso: else.
while(true) es como el void loop, es decir que funciona como un bucle infinito.
Los floats no son perfectos, son una aproximación (los floats son números con decimales.) Por ejemplo si tu escribe 100 - 0,3 no te va a dar 99,03 te va a dar un número como: 99,03542. Esto se debe a que los ordenadores son binarios y no tienen decimales por eso aproxima al calcular un float. Por eso es mejor no trabajar con floats.
Double es un float con mayor resolución, lee más decimales que un float normal.

Un long es como un int pero con un número más largo, es decir es un int que contiene más bits.

Es mejor no usar delay o sleep, sobretodo en proyectos con sensores, ya que durante ese tiempo no se leen los sensores.

Botones:
Todos los botones tienen un atributo que se llama presionado.

```cpp
//Creamos una clase que se llama botón
Class Boton{

//definimos atributos
bool presionado = 0;
bool normalAbierto = true;
//Uint permite que el valor siempre sea mayor a 0
Uint duracionpresionado = 0;
//Como no puedo presionar un botón negativa veces, pongo U
Uint patita;
Uint vecesPresionado = 0;

//Ahora hacemos constructores, aquí se van a usar () {}
Boton (int nuevaPatita){
patita = nuevaPatita;

}
```

Métodos: 
Los métodos pueden conversar entre ellos

void leer();
void acrualizar();

Primero hay que definir las cosas y luego hacer cosas con ellas, el segundo proyecto va a consistir más en código y definir.

Se crean diferntes archivos.
main.cpp
diagram.json
Boton.h
Boton.cpp 
y cada uno tiene su función al igual que en una página web hay un archivo que es la programación de la interfaz y otro donde se controla la base de datos.


## encargos

1. usar el ejemplo base visto en clases <https://wokwi.com/projects/476507507193136129>, agregar un segundo botón en la simulación de hardware, agregar una segunda instancia de la clase Boton, agregarle un atributo y un método a la clase Boton, y hacer que el segundo botón haga algo diferente al primero.
2. descargar todos los archivos de wokwi, descomprimir el archivo.zip y subir esa carpeta a tu repositorio en esta sesión.

## lectura
La pregunta de "¿quien controla el código?" iba haciendose cada vez más grande a medida que avanzaba el tiempo.
Hoy en día los grupos de hackers están prácticamente en toda Europa y Estados Unidos, de hecho el Chaos Computer Club se expandió hasta Francia y en España cada vez iba haciendose notar más.

En Francia el líder de La Quadrature du Net era un chivato y tuvieron que intervenir por ello.

Por otra parte en Estados Unidos era como si los hackers se hubieran comercializado a diferencia de Europa, creando Defcon por ejemplo.

Según Andy aunque no le gustaba admitirlo el Chaos Computer Club alemán era líder. Pero el lo veía de la siguiente manera:

"We don't like leaders. We like progress and people making cooperation. I like the idea rather, that we provide spaces where things can happen".
"Alwats act in a way where you widen the options to act"

Entonces la escritora llega a Chaos Computer Club, este año se encuentra en una antigua fábrica de tejas de terracota. CCC es la myor sede de hackers de Europa. 
Se habían organizado como si fuese un circuito electrico todo estaba bien decorado y organizado para los hackers, incluso tenían puestos de comida.
Lo más curioso era un lema que seguían los hackers y que estaba escrito en muchas carpas:

"Sed excelentes el uno con el otro." Esta frase sacada de una película de Keanu Reeves describía muy bien la atmosfera y la camadería que había en ese evento donde todos se trataban con respeto y lo mejor posible el uno al otro para que todo funcionase en orden.
