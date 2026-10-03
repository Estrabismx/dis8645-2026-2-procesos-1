# sesion-06b

## apuntes sesión

### categorías de aristóteles / hablar del encargo

aristóteles ordena el ser en categorías. sirven para describir un objeto
desde distintos lados, y después se pueden traducir a código.

### acción y pasión / ultimas agregadas de las 10 categorias 

- **acción (poiein):** lo que el sujeto hace, ejercer una fuerza o un cambio
  sobre algo. ej: cortar, correr.
- **pasión (paschein):** lo que el sujeto recibe, sufrir o experimentar un
  cambio provocado por otro. ej: ser cortado, ser quemado.

en programación, las acciones se parecen a los **métodos** (lo que el objeto
hace) y las pasiones a los cambios que le llegan a sus **atributos**.

### posición y lugar

- **posición:** cómo está puesto el objeto (su disposición).
- **lugar:** dónde está. se puede expresar como un vector (x, y, z)
  medido desde un origen. por eso hay que definir dónde están los orígenes:
  sin un punto de partida, las coordenadas no significan nada.

### ejemplo: espejo de bolsillo

- **sustancia:** el espejo de bolsillo como objeto físico.
- **cantidad:** 1 objeto compuesto por 2 partes.
- **cualidad:** superficie lisa y reflectante, marco metálico, exterior
  beige/rosado con dibujos decorativos y detalles brillantes.

#### know-how y know-what

- **know-how (hacer):** saber práctico, el saber que se tiene al fabricar.
- **know-what (teoría):** saber qué es algo, el conocimiento conceptual.

hacer máquinas es bueno porque obliga a juntar los dos: hay que entender la
teoría y también hacer que funcione de verdad.


### apuntes charla 

- **modulor store (alemania):** tienda de materiales para fabricar.
- **discos de 33 rpm:** se reproducen a 33 revoluciones por minuto.
- **la invención de morel:** novela de adolfo bioy casares sobre una máquina
  que reproduce personas.
- **puente h:** circuito que permite controlar motores, sobre todo el
  sentido de giro.
- **máquina de fax:** ejemplo de máquina que transmite imágenes.

###  clases en c++ (clases and objects)

https://www.w3schools.com/cpp/cpp_classes.asp
https://www.w3schools.com/cpp/cpp_constructors.asp

una clase es un molde: describe cómo es algo y qué puede hacer, y después
con ese molde se crean muchos objetos. sirve para propagar un procedimiento.

para usar una clase necesito tres cosas:

1. el **nombre de la clase** (con mayúscula inicial)
2. el **nombre de fantasía** del objeto (ej. `elDeCatalina`)
3. los **parámetros** necesarios para que exista

### ejemplo: la clase termo

```cpp
class Termo {
public:
  // atributos
  bool existencia;
  int posicion;
  int cantidadML;
  float temperatura;

  // constructor
  Termo(int cuantosML) {
    cantidadML = cuantosML;
    existencia = true;
  }

  // métodos
  void abrir();
  void cerrar();
};  // ojo: la clase termina con ;
```

## crear objetos y usar el punto

```cpp
Termo elDeCatalina(800);
Termo elDeMati(500);

elDeCatalina.cantidadML = 800;
elDeMati.existencia = true;
```

el `.` sirve para entrar a un atributo o llamar a un método del objeto.

### constructor

- es un método especial que se llama automáticamente cuando se crea un objeto.
- así los valores quedan por defecto desde el principio, sin tener que
  escribirlos uno por uno después (por ejemplo, `existencia = true`).
- cada clase tiene un constructor, o más de uno.

### diferencia con python

en python sí importan los espacios (la indentación). en c++ no, pero a
cambio hay que cerrar la clase con `;` después de las llaves.

### codigo que funciono 



## encargos

## lectura
