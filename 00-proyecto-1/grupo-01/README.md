# proyecto-01

## Licencia 

Esta obra y su documentación están bajo una [Licencia Creative Commons Atribución-CompartirIgual 4.0 Internacional](https://creativecommons.org/licenses/by-sa/4.0/).

© 2026 [Dayana Pañitrur, Camila Ramírez, Bianka Vilchez]

<br>

## Poema

El poema elegido fue: $\textcolor{red}{When\ Our\ Two\ Souls\ Up\}$ 

Por: $\textcolor{red}{Elizabeth\ Barrett\ Browning\}$

Data del año [RELLENAR CON INFO Y CONTEXTO XFA xd]

Elizabeth Barret Browning nació en el año 1806 en Inglaterra. Reconocida por su reputación literaria, en una época en la cuál era poco frecuente que las mujeres fueran más reconocidas que los hombres en muchos contextos, pero por sobre todo en el ámbito académico, por las normas morales que existían sobre el rol de la mujer, Elizabeth estaba casada con Robert Browning, quién también era poeta. Su familia tenía una situación económica privilegiada, pero ella discrepaba con la mayoría de las ideas colonialistas que tenían, en contra de la esclavización que ellos mismos efectuaban y que les generaba el gran poder económico que tenían.

La obra de Elizabeth que elegimos se llama Soneto 22 y es parte de la colección *Sonetos del portugués*. Que data entre 1845 y 1846.

Según la *Academia de Poetas Americanos* el poema se encuentra en dominio público.

Interpretamos el poema como la intención de rehusarse a la muerte por la causa del amor. Desprenderse de lo terrenal implicaría dejar de sentir y vivir el amor romántico como se vive día a día, para someter amor al cielo y a la eternidad, lugar en el que ya no sería permitido el estar con su ser amado.

<br>

### Poema original  

<br>

When our two souls stand up erect and strong,

Face to face, silent, drawing nigh and nigher,

Until the lengthening wings break into fire

At either curvèd point,—what bitter wrong

Can the earth do to us, that we should not long

Be here contented? Think. In mounting higher,

The angels would press on us and aspire

To drop some golden orb of perfect song

Into our deep, dear silence. Let us stay

Rather on earth, Belovèd,—where the unfit

Contrarious moods of men recoil away

And isolate pure spirits, and permit

A place to stand and love in for a day,

With darkness and the death-hour rounding it.

<br>

> **Aviso de Dominio Público:** El material _When Our Two Souls Up_ utilizado en este repositorio se encuentra en el dominio público. Ha sido identificado como libre de restricciones bajo los derechos de autor (PDM 1.0).

<br>

<br>

### Poema traducido

<br>

**Cuando nuestras dos almas se eleven**

<br>

Cuando nuestras dos almas se eleven, firmes y fuertes,

frente a frente, en silencio, acercándose más y más, 

hasta que las alas que se alargan estallan en fuego 

en cada punta curva ¿qué mal amargo 

puede hacernos la tierra, que no debiéramos 

quedarnos aquí, contentos? Piénsalo. Al subir más alto, 

los ángeles nos oprimirían y aspirarían 

a dejar caer algún áureo orbe de canto perfecto

en nuestro hondo, querido silencio. Quedémonos

mejor en la tierra, Amado mío, donde los ánimos

contrarios e injustos de los hombres retroceden

y aíslan a los espíritus puros, y permiten

un lugar donde estar y amar por un día,

con la oscuridad y la hora de la muerte rodeándolo.

<br> 

> Traducción elaborada por Dayana Pañitrur, Camila Ramírez y Bianka Vilchez (2026).
>
> Distribuido bajo la licencia CC BY-SA 4.0. Para ver una copia de esta licencia, visita https://creativecommons.org/licenses/by-sa/4.0/

<br>

---

## Bill of materials

| Componente | Cantidad | Link de compra |
| :--- | :---: | ---: |
| Arduino UNO R4 Wifi | 1 | Dato 3 |
| Pantalla LCD Azul 16x02 | 1 | Dato 3 |
| Potenciómetro lineal (valor) | 1 | Dato 3 |
| Botón (tipo) | 2 | Dato 3 |

### Pantalla LCD Azul 16X02

A diferencia de la mayoría de los grupos decidimos utilizar esta pantalla, debido a su mayor tamaño y por su configuración, ya que está pensada para solo mostrar texto, es más sencillo, sumado que posee un controlador estandarizado. Pero todo eso lo veremos ahora con las caracterisiticas de esta pantalla

![display](./imagenes/lcd-1602.webp)

> Directamente desde [Afel](https://afel.cl/products/pantalla-lcd-azul-16x02)

#### Caracteristicas

- **Formato** 16 caracteres por 2 lineas

- **Voltaje funcionamiento** 5V

- **Controlador** SPLC780D1 o compatible con HD44780

- **Retroiluminación (Backlight)** LED de color azul con caracteres blancos.

- **Interfaz** Paralela, configurable para operación de 4 bits u 8 bits.

- **Tipo de Pantalla** STN (Super-twisted Nematic) de tipo negativo.

<br>

## Código

### Coreografía

1.Inicia el Arduino

2.El texto avanzará de manera continua hasta que se presionen los botones o se manipule el potenciómetro 

3.En caso de ser solo 1, el texto se congela y no sigue avanzando hasta que se deje de presionar

4.Si son los 2 botones, se detiene el texto y desaparece

5.Mientras esto ocurre, se consulta en qué sección del texto se encuentra

6.En base a la sección del texto mostrado, se visualizará una palabra clave

7.Al dejar de presionar un botón, vuelve a ocurrir el punto 3

8.Si se sueltan ambos botones, desaparece la palabra

9.Luego continúa avanzando el texto desde el mismo punto en el que quedó

10.En caso de ser manipulado el potenciómetro, se modificará la velocidad del texto (mientras más lejos del centro, más rápido el cambio)

11.Si se rota hacia la derecha avanza de manera normal solo variando la velocidad

12.Si se rota hacia la izquierda retrocede el texto, según qué tan lejos del centro esté

<br>

Además de esto realizamos el primer diagrama de flujo relacionado al funcionamiento del código

![Diagrama](./imagenes/esquema.jpg)

> Bastante básico en relación a la complejidad que posee el código

<br>

![Diagrama](./imagenes/esquema.png)

> Ahora podemos entender de mejor manera el funcionamiento del código

<br>

![Grafico](./imagenes/grafico.png)

> Grafico que muestra la relación del potenciómetro con la velocidad del poema

<br>

## Arduino

Conexión representada en Tinkercad

[![Tinkercad](./imagenes/sc-12.png)](https://youtu.be/ZCfgRzy07II)

>Link de [YouTube](https://youtu.be/ZCfgRzy07II)

![Tinkercad](./imagenes/dis8645-2026.jpg)

<br>

## Proceso

### Etapa inicial

- chao poema de victoria Ramírez 

- por copyright (xd)

- buscar alguna solución

- Encontrar poema

- Traducir poema

- Acreditar licencia

- Conceptualizar

### Pseudo código

- Hacer listado de pasos

- Ponerse en situaciones que podrían entrar en conflicto (del código, no nosotras xd)

- Realizar esquema / hacer pruebas

- definir variables

- definir posibles funciones

### Codi-Gooooo

- Realizar un test funcionamiento del inicio (licencia, nombre y autora del poema)

```cpp

// adjuntar codigo con fallo inicial

```

![Tinkercad](./imagenes/sc-09.png)

![Tinkercad](./imagenes/sc-10.png)

> Explicar que fallo (todo ocurre en parelelo y sin un desfase, se pelean por quien se muestra en la pantalla)
>
> Mencionar elementos claves del código, funciones, variables, etc
>
> > set.display(0,0) por ejemplo

```cpp

// codigo con inicio listo

```

> Explicar que se solucionó, que cambiamos y que mantuvimos (el porque)

- Agregamos la parte que visualiza el poema de manera completa

  
```cpp

// codigo con poema (el que genero la daya)

```
> hablar de que elementos podemos entender que aparecen y porque, mencionar que instrucciones se le dieron a la ia, agregar prompt
>
> mencionar como pensamos agregar la siguiente función y que conflictos podriamos tener el código

- Agregar pote

```cpp

// codigo pote xd

```
> que cambio, genero algun error?, existe algun valor que queramos editar
>
> mencionar ejercicio en clase que fue utilizado como base

- agregar botones (solo congelar)

```cpp
// codigo botones solo congelar xddd
```
> que se le pidió a la ia, que sabemos de lo que se generó, algo que solucionar??

- agregar botones (palabra clave)

- codigo final
