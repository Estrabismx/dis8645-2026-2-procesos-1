# sesion-04b

## apuntes sesión

![texto](./imagenes/boceto.jpeg)

Llegamos y como no teníamos las cosas, partimos viendo el diseño de la caja. Pensamos cómo acomodar todo y también cómo extender la conexión de la pantalla. Todo suena lindo ahora antes de hacerlo, pero HAY QUE HACERLO.

Para el diseño pensamos poner la pantalla, debajo los tres botones y a un lado el potenciómetro. Queremos que la parte de arriba sea una tabla de picar, haciendo alusión al poema.

El profe nos dio la idea de hacer un botón con la acción de chop, o sea, que el cuchillo al tocar la tabla de picar haga la acción. Para esto toda la conexión tiene que ser metálica (con cables). El código queda tal cual porque esto estaría reemplazando un botón, así que ahora tenemos que descubrir cómo hacer que funcione en la práctica.

También pensamos si sacar el botón repeat, porque ya tenemos play y pause y así alivianamos un poco la carga. El problema era que no sabíamos si el botón solo pasa electricidad cuando lo apretamos o si queda pasando todo el rato. Si era lo primero, lo dejábamos; si era lo segundo, había que alivianar.

Al final confirmamos que los botones solo pasan electricidad cuando los presionamos y que además consumen muy poco, así que podemos dejar los tres. También confirmamos que podemos tener los botones de play y pause y además el sistema del cuchillo + tabla, haciendo que cumplan la misma función. Así, si la tabla no nos resulta, igual tenemos la opción de hacer pasar el poema con los botones.

ELECTRICIDAD

LED = Light Emitting Diode

Es básicamente un diodo que cuando conduce corriente prende una luz.

La resistencia sirve para limitar cuántos electrones pasan. Por eso, mientras más grande sea la resistencia, menos electrones pasan.

Las resistencias se pueden usar para distintas cosas, pero sigue siendo el mismo componente.

Cortocircuito = cuando juntamos positivo y negativo sin control!!

Voltaje es la diferencia de qué tan + o - está un punto respecto del otro.

Podemos pensarlo como un caudal: la cantidad de electrones que están pasando corresponde a la corriente (I).

Entonces la resistencia funciona como una limitadora de corriente.

Los cables tienen casi cero resistencia, por eso necesitamos resistencias cuando corresponde.

LEY DE OHM

La relación entre corriente, voltaje y resistencia es:

I = V / R

y también:

V = I · R

BOTÓN / SEÑAL

Cuando hablamos de un botón podemos mirar el cambio entre un estado y otro.

Rising edge → 0 → 1

Es cuando sube de apagado a prendido.

Falling edge → 1 → 0

Es cuando baja de prendido a apagado.

Por eso podemos tener:

```cpp
int ledActual;
int ledAnterior;
```

Esto sirve para comparar lo que está pasando ahora con lo que estaba pasando antes.

PULL DOWN

La resistencia de 10K pull down sirve para mantener el estado en 0 cuando el botón no está presionado.

Cuando apretamos el botón:

→ pasa a 5V / 1

Entonces el botón apagado queda como una resistencia infinita ∞.

USB

USB → pasa siempre 5V.

En cambio:

USB-C → pasa lo que el Arduino necesita.

O sea, el USB-C no tiene un voltaje propio fijo como el USB.

ESTADOS DEL BOTÓN

Podemos pensar los estados del botón mirando antes y después:

00 = apagado
No estaba apretado y sigue sin estarlo.

01 = se prendió
Estaba apagado y ahora se apretó.

11 = sigue apretado
Ya estaba apretado y sigue así, pero no hará nada a menos que nosotros configuremos que haga algo en ese estado.

10 = se apagó
Estaba apretado y ahora dejó de estarlo.

## encargos

## lectura
