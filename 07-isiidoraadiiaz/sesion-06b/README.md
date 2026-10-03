# sesion-06b

## apuntes sesión

# 25-09

## Categorías de Aristóteles

Empezamos viendo las **categorías de Aristóteles**.

**SON 10 OMG:**

1. Sustancia
2. Cantidad
3. Cualidad
4. Relación
5. Lugar
6. Tiempo
7. Posición
8. Posesión
9. Acción
10. Pasión

La idea de trabajar con estas categorías es poder analizar las cosas desde distintos lados y también **descubrir de dónde vienen ciertas formas de describir o entender los objetos**.

No es solamente preguntarse qué es una cosa, sino también cuánto tiene, cómo es, dónde está, qué hace, qué le pasa, etc.

# Invitado: Rodrigo Toro

**UN CAPO!**

Rodrigo Toro trabaja con programación, mecanismos y objetos, pero desde un lado que se acerca mucho a los **autómatas antiguos**.

Mood: **viva la programación no digital** jajaja.

Una de las cosas que me llamó la atención es que su trabajo no depende necesariamente de pantallas o tecnologías digitales para generar movimiento. Hay mucha mecánica, motores, piezas físicas y sistemas que permiten que las obras se muevan.

## Su proceso

Nos mostró cómo sus proyectos han ido cambiando y evolucionando con el tiempo.

No necesariamente hace una obra una vez y queda lista para siempre. Puede existir una **reedición del proyecto**, donde vuelve a trabajar una pieza, cambia cosas y la sigue desarrollando.

O sea, el proyecto también va evolucionando.

## Las manos

Usa mucho **manos** en sus proyectos.

La curiosidad por cómo funcionaban venía desde chico, en parte gracias a cosas que veía en **Discovery Kids jajaja**.

Empezó con la idea de hacer sus propios prototipos, pero fue avanzando hasta llegar a un nivel muchísimo más complejo y preciso.

Y LO MÁS LOCO:

**LOGRA MOVER MANOS.**

Él decía que sentía que algunos movimientos todavía eran toscos, pero desde afuera era como ????? porque realmente consigue reproducir movimientos usando mecanismos.


## Rodamientos siempre rodamientos

Los **rodamientos** son importantes dentro de este tipo de proyectos.

Ayudan a permitir que ciertas piezas puedan moverse o girar de una forma más fluida y con menos fricción.

Entonces, cuando se construyen mecanismos que tienen muchas partes móviles, la manera en que esas partes se conectan importa muchísimo.

## La obra también cambia con el cuerpo

Algo que encontré interesante es que su propia obra tuvo que ir cambiando por cosas que le pasaron físicamente.

Por ejemplo, se **esguinzó un dedo** y después también tuvo problemas en el codo.

Eso hizo que tuviera que cambiar algunas formas de trabajar y, finalmente, esos cambios también terminaron afectando la obra.

Entonces el proyecto no solamente evoluciona por decisiones creativas o técnicas, sino que también puede cambiar por las propias condiciones de quien lo está construyendo.

## Statement

Algo importante dentro de su trabajo es que **no sucumbe completamente a las tecnologías digitales**.

Por lo menos en las piezas que nos presentó, había una intención de seguir trabajando con mecanismos físicos, movimiento, motores y sistemas más mecánicos.

No porque no sepa programar, porque claramente sabe jajaja, sino porque existe una decisión de **no depender solamente de lo digital**.

## *La invención de Morel*

También mencionó **_La invención de Morel_**.

Gran libro según Rodrigo jajaja.

Queda pendiente revisar mejor por qué lo relacionó con su trabajo y qué conexión tiene con las obras que mostró.

## Residencias artísticas

También hablamos de las **residencias artísticas**.

Apunte importantísimo:

**residencias artísticas = manicomnios** JAJJA.

Más allá del comentario, entendí que son espacios donde artistas pueden pasar un tiempo trabajando específicamente en sus proyectos, investigando, probando cosas y desarrollando obras.

# Motores y Puente H

Vimos también el concepto de **Puente H**.

Un Puente H es una forma de **controlar motores**, especialmente cuando queremos controlar hacia qué lado gira un motor.

Por ejemplo, permite hacer que un motor pueda girar:

- hacia un lado;
- hacia el otro.

Esto es súper útil cuando queremos generar movimientos mecánicos controlados.

# `class`

Después volvimos a programación y aparecieron las **clases**.

Una `class` se puede pensar como una variable mucho más compleja, casi como una **súper variable**, porque puede guardar varias características y también acciones dentro de una misma estructura.

Referencia:

[C++ Classes and Objects](https://www.w3schools.com/cpp/cpp_classes.asp)

La clase funciona como una especie de modelo desde donde después podemos crear objetos.

## Ejemplo: un termo

Creamos una clase para representar un **termo**.

```cpp
class Termo {
public:

    bool existencia;
    int posicion;
    int cantidadML;
    float temperatura;

    void abrir();
    void cerrar();
};

## encargos

## lectura
