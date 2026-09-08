# sesion-04a

## apuntes sesión

Archivos Header (`.h`) vs. Archivos Ejecutables (`.cpp`)
Para mantener un código limpio y organizado, la lógica se divide entre declaración y ejecución:
**Archivo Header (`.h`):** Es la cabecera. Anuncia y declara lo que existirá (funciones, variables o clases). Promete qué herramientas va a ofrecer el módulo.
**Archivo de Implementación (`.cpp`):** Es el ejecutable. Contiene el desarrollo real y detallado del código; es la parte que ejecuta la acción ("el que da la orden de correr el programa").

Crear Pestañas / Módulos en Arduino IDE
Cuando un proyecto crece o tiene bloques de código muy largos (por ejemplo, datos hexadecimales, configuraciones complejas o arreglos grandes), es conveniente moverlos a una nueva pestaña para mantener el código principal ordenado:

1. **Crear pestaña:** En el IDE de Arduino, presionar el menú desplegable en la esquina superior derecha (`...` o la flecha de la barra de pestañas).
2. **Nombrar el archivo:** Seleccionar *New Tab* (Nueva Pestaña) y darle un nombre (ejemplo: `mis_datos.h` o `funciones.cpp`).
3. **Mover el código:** Cortar el bloque de código extenso o de configuración y pegarlo en la nueva pestaña.

Vincular los Archivos con `#include`
Para que el archivo principal del programa reconozca y lea el código que se movió a la otra pestaña:

* Usar la directiva `#include` al inicio del archivo principal.
* **Sintaxis:** `#include "nombre_de_tu_pestaña.h"`

> **Dato:** Las comillas dobles `" "` se usan para incluir archivos locales creados por uno mismo dentro de la misma carpeta del proyecto, a diferencia de los símbolos `< >` que se usan para librerías del sistema.

## encargos

## lectura
