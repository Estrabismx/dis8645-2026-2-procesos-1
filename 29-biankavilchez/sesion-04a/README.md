# sesion-04a

## apuntes sesión

## encargos
### los tres estados del poema

1. **versos del poema**: aparecen los versos completos del poema original, constantes en pantalla. su velocidad de avance y retroceso se modifica con el potenciómetro.
2. **segundo poema**: a partir de fragmentos del primer poema se generó un nuevo poema. aparece mientras los dos botones se mantienen presionados por **más de 2 segundos**.
3. **palabra por verso**: son palabras clave de cada verso. aparecen cuando se presionan los dos botones por **menos de 2 segundos**, dentro del rango del verso que se esté mostrando en pantalla.

ejemplo:

| verso completo | palabra clave |
|---|---|
| Cuando nuestras dos almas se eleven, firmes y fuertes, | firme y fuerte |
| frente a frente, en silencio, acercandose mas y mas, | acercándose |
| hasta que las alas que se alargan estallan en fuego | estallan |
| en cada punta curva que mal amargo | en cada |

### variables y arreglos

```cpp
// poema principal, un verso por casilla
char *versosPoema[] = {
  "Cuando nuestras dos almas se eleven, firmes y fuertes,",
  "frente a frente, en silencio, acercandose mas y mas,",
  "hasta que las alas que se alargan estallan en fuego",
  "en cada punta curva que mal amargo",
  "puede hacernos la tierra, que no debieramos",
  "quedarnos aqui, contentos? Piensalo. Al subir mas alto,",
  "los angeles nos oprimirian y aspirarian",
  "a dejar caer algun aureo orbe de canto perfecto",
  "en nuestro hondo, querido silencio. Quedemonos",
  "mejor en la tierra, Amado mio, donde los animos",
  "contrarios e injustos de los hombres retroceden",
  "y aislan a los espiritus puros, y permiten",
  "un lugar donde estar y amar por un dia,",
  "con la oscuridad y la hora de la muerte rodeandolo.",
};
const int cantidadVersos = 14;

// segundo poema: se muestra mientras se mantienen ambos botones (> 2 seg)
char *segundoPoema[] = {
  "firme y fuerte",
  "acercandose",
  "estallan",
  "en cada",
  "tierra",
  "contentos",
  "oprimiran",
  "algun",
  "silencio",
  "amado mio",
  "injusto",
  "y aislan",
  "un lugar",
  "de la muerte",
};

// palabra por verso: aparece con pulsacion corta de ambos botones (<= 2 seg)
char *palabraVerso[] = {
  "firme y fuerte",
  "acercandose",
  "estallan",
  "en cada",
  "tierra",
  "contentos",
  "oprimiran",
  "algun",
  "silencio",
  "amado mio",
  "injusto",
  "aislan",   // nota: sin "y"
  "lugar",    // nota: sin "un"
  "muerte",   // nota: sin "de la"
};
```
## lectura

desde la pag 14 a la 29 

**capítulo 4** — figuras de chladni

**concepto clave:** las figuras de chladni son patrones geométricos que ernst chladni obtuvo hacia 1780, esparciendo arena sobre placas de metal o vidrio y pasando un arco de violín por los bordes.

- la vibración de la placa hace que la arena se acumule en las zonas donde no hay movimiento (líneas nodales)
- esto forma figuras simétricas
- es, literalmente, "ver el sonido" de forma manual y artesanal

**capítulo 5** — (pendiente / no revisado)

trata sobre una demanda judicial y cómo el alterar una imagen puede ser perjudicial. queda pendiente de resumir.


**capítulo 6** — color, tonos de gris y el exponente de lyapunov

el capítulo retoma el sistema de coordenadas anterior y agrega el factor color / tonos de gris a las imágenes.

el color como número, no como decoración

> "el color de cada punto se determina por el valor del exponente de lyapunov λ. si λ es negativo, la trayectoria es periódica... si λ es positivo, las trayectorias cercanas divergen exponencialmente... diferentes valores de λ>0 nos dicen para cuánto tiempo futuro es posible hacer predicciones."

interpretación:

| color | valor de λ | significado |
|---|---|---|
| claro (blanco / gris claro) | λ < 0 | orden — predecible |
| oscuro (negro) | λ > 0 | caos — no predecible |

el color no es decoración: es un número que mide qué tan predecible es el sistema. el autor lo compara con tierra y agua en mapas geográficos — blanco = tierra firme (predecible), negro = mar caótico (impredecible).

 tres formas de crear nuevas imágenes

> "una vez obtenida una imagen, existen varias maneras de obtener nuevas... cambiar las coordenadas, variar ligeramente la función, y sobre todo amplificar sectores... la auto-similitud permite encontrar figuras dentro de figuras ad infinitum."

1. **cambiar un parámetro de la fórmula** (ej. K): con K=0,05 fijo se obtiene una imagen; cambiando a K=0,06 (o graficando a vs b) sale un mundo completamente distinto.
2. **hacer zoom**: cerca del borde entre lo claro y lo oscuro (donde λ=0) la imagen se vuelve infinita — se puede hacer zoom y seguir encontrando más y más formas (auto-similitud).
3. **intervenir la fórmula**: mover levemente un parámetro (ej. α de 0,907 a 0,908) cambia la imagen por completo.

**próximos pasos**

- usar ia para facilitar la lectura de las fórmulas a partir de imágenes del libro
- empezar a analizar imágenes concretas del libro

