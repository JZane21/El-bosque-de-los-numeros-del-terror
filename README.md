# El-Bosque-De-Los-Numeros-Monstruos
## Objetivo
La finalidad de este proyecto es presentar una aplicaciòn del algorìtmo dijkstra en el mundo de los videojuego. De esta manera, se mostrarà que la teorìa de grafos puede ser implementada para crear un producto decente en el mundo digital.
## Descripcion
Con la ayuda del concepto de la programaciòn orientada a objetos o POO, se construyò un videojuego el cual nos ofrece una jugabilidad basada en la teorìa de grafos, la cual a sido acompañada del algoritmo dijkstra que ayudarà a  encontrar el camino soluciòn màs corto del grafo.
La filosofìa del juego consiste en que el usuario se encuentra atrapado en un laberinto conformado por un grafo, y el deber del jugador consistirà en encontrar el nodo salida de dicho grafo para asì escapar. Sin embargo, se presentaràn nùmeros monstruos los cuales obtaculizaràn la travesìa del jugador, atacandolo en cuanto se encuentren en el mismo nodo.
## Instalaciòn
Para ejecutar el videojuego, se deben seguir los siguientes pasos:

1.- Se debe instalar el compilador de C++, es decir el gcc y el gpp.
### Windows 10
* Para dar inicio a la instalaciòn en Windows, se debe dar click en el siguiente enlace:
https://sourceforge.net/projects/mingw/files/

* Una vez descargado el archivo, se abrirá una automáticamente su Intaller Manager, del cual tenemos que hacer lo siguiente:

![mg1](https://user-images.githubusercontent.com/82000556/168502766-842a0313-8d42-4cad-93a5-e8ef668660db.jpg)

![mg2](https://user-images.githubusercontent.com/82000556/168502784-0559faca-b6ad-4cee-bee7-20fc23b9b64b.jpg)

* Luego de esperar a que se instale todo, tenemos copiar la ruta de la carpeta bin.

* Presionamos la tecla windows y debemos escribir "variables".

* Luego, seleccionamos las siguientes opciones:

![mg3](https://user-images.githubusercontent.com/82000556/168502788-615a89ea-8fc6-4a09-9d1d-2b35bb7d27f1.jpg)

![mg4](https://user-images.githubusercontent.com/82000556/168502810-8a49fc76-fcdd-4188-b52a-9ebb762c8881.jpg)

![mg5](https://user-images.githubusercontent.com/82000556/168502825-163720d8-7a4a-4c73-a6c3-ce9244166f06.jpg)

![mg6](https://user-images.githubusercontent.com/82000556/168502836-8c3bbeb1-9eb2-4db3-8d68-ba2d0e3367ea.jpg)

* Ahora tan solo queda dar en aceptar a las tres ventanas.

2.- Luego, se debe ir al siguiente enlace con el fin de descargar Visual Studio Code: https://code.visualstudio.com/
* Una vez descargado el VSCode, se debe instalar las extensiones que VSCode tiene para C++. Siendo más específicos:

![pf1](https://user-images.githubusercontent.com/82000556/168502855-e3ae36ca-9e59-4068-af69-760a30b27ce0.jpg)

![pf2](https://user-images.githubusercontent.com/82000556/168502875-3239639a-7263-46bd-a252-ac915340cf8d.jpg)

![pf3](https://user-images.githubusercontent.com/82000556/168502883-fb344cc3-904e-41f5-91d7-b62bc0698aea.jpg)

3.- Descargar la carpeta del directorio

4.- Abrir VSCode.

5.- Seleccionar file(Archivo).

6.- Seleccionar Open Folder(abrir carpeta).

7.- Seleccionar la carpeta que se descargò.

8.- Seleccionar el archivo Main.cpp.

9.- Ejecutar el archivo con el boton play que se encuentra en la parte superior derecha.



## Ejecuciòn del programa
Una vez inicializado la ejecuciòn del archivo Main.cpp, se deberà tomar en cuenta lo siguiente para que sea posible interactuar con el programa correctamente.

* Se le aparecerà una introducciòn al programa del cual puede leerlo con calma o directamente saltarlo con la tecla ENTER.

* Usted tendrá la opción de elegir que mapa desea jugar pulsando un número del 1 al 6, pero si no desea jugar, puede pulsar el número 0 para finalizar el juego.

* Se le explicará la dínamica del juego a través de un texto para interactuar con el correctamente.

* Se le mostrará un estado del juego el cual representa el estado de su personaje dentro del juego. Usted tendrá la posibilidad de interactuar con dicho personaje con los siguientes comandos:

(siempre todo en mayúsuclas)
'A Número Posición' para avanzar a una posición específica que se encuentre disponible. El número de la posición a la cual avanzar, se relaciona con el número alfabético al cual usted puede moverse, y esto se clasifica de la siguiente manera:

1.- A 2.- C 3.- Z

Y así sucesivamente, porsupuesto, esto variará en cada momento que nos desplacemos de un nodo a otro.

'D NúmeroPrimo' De esta manera, uno ataca a los números monstruos, pero estos son limitados y se le muestra la cantidad de números primos que usted posee. Y para seleccionarlo, usted debe de escribir el número de la posición en la que se encuentre el número primo.

* Una vez pierda o gane, usted tendrá la opción de volver a jugar o salir del juego.


## Algoritmo

### Dijkstra:
Este algoritmo, nos ayuda a encontrar el camino más corto para moverse de un vértice a otro en un grafo, y este mismo, es usado en la dínamica del juego cuando acabamos con un monstruo y este nos da una parte del camino más corto que debemos seguir para escapar.

Pero a diferencia de un algoritmo de tipo Dijkstra normal, este utiliza arreglos para adquirir datos y construir el grafo como tal, pero a la hora de movilizarnos, utiliza un vector como es debido.
