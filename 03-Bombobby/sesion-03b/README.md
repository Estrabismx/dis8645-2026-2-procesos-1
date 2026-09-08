# sesion-03b

## apuntes sesión
(Apuntes completados de forma autónoma tras revisar el material y consultar el contenido de la clase)

C++ y C:** C++ se construyó sobre C.
Arduino como punto de partida:** Sirve para introducir conceptos básicos, pero progresivamente migraremos a C++ puro.
**Uso de Mayúsculas (Convención):** Se reservan principalmente para **Clases** (ej. `String`). Evitar usarlas en variables comunes para no confundir la sintaxis.

Manejo de Cadenas (Strings) y Caracteres
Diferencia esencial entre tipos de comillas:
**Comillas simples (`' '`):** Para un único carácter (ej. `'a'`).
**Comillas dobles (`" "`):** Para secuencias de texto/palabras ("Strings").

Formas de trabajar con texto:
**Objeto `String` (Arduino):**
Sintaxis: `String thisString = String(13);` *(crea un String reservando espacio o convirtiendo el valor)*.
`charAt(index)`: Obtiene el carácter en una posición específica.
`setCharAt(index, char)`: Modifica el carácter en la posición indicada.

**Arreglos de Caracteres (`char array` - C tradicional):**
Un arreglo es una colección finita y de tamaño fijo (se define con corchetes `[]`).
**Terminación nula:** Requiere un carácter nulo (`\0`) al final para indicar el cierre de la cadena.
**Ejemplo explícito:** `char palabrita[8] = "Arduino";` *(ocupa 7 letras + 1 carácter nulo)*.
Se puede definir el tamaño de forma explícita o dejar que el compilador lo infiera automáticamente.

Control de Tiempo: Uso de `millis()`
**Diferencia con `delay()`:** A diferencia de `delay()` (que bloquea la ejecución completa del programa), **`millis()`** devuelve el número de milisegundos transcurridos desde que la placa se inició.
**Aplicación:** Permite realizar tareas simultáneas o no bloqueantes comparando el tiempo actual con un tiempo guardado previo.

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

