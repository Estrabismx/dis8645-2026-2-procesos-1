# sesion-04b

## apuntes sesión

Trabajo en clases este día, para avanzar lo que más podemos de la solemne 1

Principalmente avanzamos en el uso y botón y potenciómetro. Nos ayudaron y guiaron bastante para ello. 

En primer lugar en el breadboard, donde nos recomentaron anclar el GND a un sector del breadboard que fuese amplio, como son las lineas externas de este, para así tener disponible la conexión a tierra en mayor cantidad y nos quedasemos sin espacios para conectar. Lo mismo hicimos con el V5. 

Con eso solucionamos muchas cosas que no teniamos en mente.

--------------------------------------------------------

Por otra parte, vimos como conectar y dar uso a un botón, partiendo por saber que tenemos que usar las patitas en diagonal para conectar los cables al botón.

El botón se conecta al sector digital del arduino, escogiendo un espacio que será declarado posteriormente en el código, en nuestro caso el digital 3. Ese espacio lo declaramos por medio de un INT, int patitaBoton = 3. y uno de lectura, int lecturaBoton = 0. Luego, en el setup colocaremos las función: pinMode(patitaBoton, INPUT) declararlo como input y para recibir la información. y finalmente en loop: lecturaBoton = digitalRead(patitaBoton); para comenzar la lectura en bucle.

Teniendo todo eso, el arduino nos entregaba la información sobre si el botón está presionado(1) o no(0). 

A partir de eso podemos crear intervenciones por medio del botón para nuestro trabajo.

-------------------------------------------------------

durante la clase seguimos editando el código, nos dieron algunas ideas con un paso a paso y trabajamos en ello.



## encargos

## lectura
