# sesion-04a

## apuntes sesión

Investigacion millis, 

EJEMPLO DESDE UN VIDEO, como usar millis o como funciona principalmente para cronometrar tiempos y crear intervalos para las funciones que usemos
```cpp
//unsing long pq es el que tiene mayor capacidad de almacenamiento(32bites) y cuenta hasta por aproximadamente hasta por 49 días. 
//tiempo cuenta desde 0
unsigned long tiempo=0; 
//el tiempo 2 también, lo usaremos para comparar en las funciones
unsigned long tiempo2= 0;
int segundos = 0;
//diferencia a la que llega en cada cuenta, 1000 sería 1 segundo, contará cada 1 segundo
int diferencia = 1000; 

void setup() (
   Serial.begin(9600);
)
//el tiempo es la variable millis, sumando constantemente desde el 0.
void loop() (
    tiempo = millis(); 
//si el primer tiempo es mayor o igual a el tiempo sumado 1 segundo u otra cantidad
if (tiempo >= (tiempo2+diferencia))
{ 
//actualizamos el tiempo2, vuelve a 0¿
   tiempo2 = tiempo; 
//dividido en 1000 para que lo muestre en segundos y no milisegundos
   segundos = tiempo/1000; 
// y nos entrega el texto que queramos cada 1 segundo, en este caso seguido de los segundos que han pasado
   Serial.print(“TEXTO”);
   Serial.println(segundos); //AHORA NO SÉ COMO OCUPARLO AKI PERO BUSCARÉ
// Arreglo con IA para poema
//definimos el poema
const char* poema[] = {
  "Primer verso: En un lugar de la Mancha,",
  "Segundo verso: de cuyo nombre no quiero acordarme,",
  "Tercer verso: no ha mucho tiempo que vivia un hidalgo,",
  "Cuarto verso: de los de lanza en astillero."
};

// Obtenemos la cantidad total de versos
const int totalVersos = sizeof(poema) / sizeof(poema[0]);

// Variables para el control del tiempo con millis()
//mismo tiempo1 con otro nombre
unsigned long tiempoAnterior = 0;
//intervalo de tiempo 
const unsigned long intervalo = 2000;

// Índice para saber qué verso toca imprimir
int versoActual = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
//le colocó esa primera parte a la función¿¿
  unsigned long tiempoActual = millis();

  // Comprobamos si ya transcurrió el tiempo
//lo configuró al revés como una resta en vez de suma
  if (tiempoActual - tiempoAnterior >= intervalo) {
 // Actualizamos la marca de tiempo
    tiempoAnterior = tiempoActual;

    // Verificamos que aún queden versos por mostrar
    //está parte es la necesaria para ocupar el println con los versos
    if (versoActual < totalVersos) {
   //si el verso actual es menor a la cantidad de versos, o sea  no ha terminado el poema
   //entonces se cargará el VersoActual
      Serial.println(poema[versoActual]);
   //++ para que vaya sumando 1 luego de presentar cada verso.
      versoActual++;
    }
  }

  // Aquí el microcontrolador sigue libre para ejecutar otras tareas simultáneas
}
```

## encargos

## lectura
