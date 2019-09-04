
![alt text](https://i.ibb.co/t4dwPXr/AB-logo-400x400.png)

# Prácticas de Algoritmia Básica 2018-19

## 1 - Práctica 1

La primera práctica de la asignatura ha consistido en desarrollar un compresor huffman para llevar a cabo la compresión de
cualquier tipo de fichero, y de igual modo, su descompresión garantizando que el fichero antes de efectuar la compresión y
el fichero resultante de aplicar la descompresión son idénticos.

### 1.1 - Descripción del algoritmo

El algoritmo de Huffman consiste en la creación de un árbol binario que tiene en cada una de sus hojas los caracteres que 
aparecen en el fichero junto con sus correspondientes frecuencias. El árbol es construido de tal forma que siguiéndolo desde 
la raíz a cada una de sus hojas se obtiene el código Huffman asociado a él. El algoritmo tiene los sigueintes pasos:

  * Se crean varios árboles, uno por cada uno de los símbolos del alfabeto, consistiendo cada uno de los árboles en un nodo sin 
     hijos, y etiquetado cada uno con su símbolo asociado y su frecuencia de aparición. 
     
  * Se toman los dos árboles de menor frecuencia, y se unen creando un nuevo árbol. La etiqueta de la raíz será la suma de las 
     frecuencias de las raíces de los dos árboles que se unen, y cada uno de estos árboles será un hijo del nuevo árbol. También 
     se etiquetan las dos ramas del nuevo árbol: con un 0 la de la izquierda, y con un 1 la de la derecha.
     
  * Se repite el paso 2 hasta que sólo quede un árbol.

De esta forma, dado un determinado código Huffman, se puede obtener a través del árbol de codificación el correspondiente 
caracter que lo representa.

Para obtener el código asociado a un símbolo se debe proceder del siguiente modo se deben seguir los siguientes pasos:

  * Comenzar con un código vacío
  * Iniciar el recorrido del árbol en la hoja asociada al símbolo.
  * Comenzar un recorrido del árbol hacia arriba.
  * Cada vez que se suba un nivel, añadir al código la etiqueta de la rama que se ha recorrido.
  * Tras llegar a la raíz, invertir el código.
  * El resultado es el código Huffman deseado.

Para obtener un símbolo a partir de un código se debe hacer así:

  * Comenzar el recorrido del árbol en la raíz de éste.
  * Extraer el primer símbolo del código a descodificar.
  * Descender por la rama etiquetada con ese símbolo.
  * Volver al paso 2 hasta que se llegue a una hoja, que será el símbolo asociado al código.
  
A continuación se muestra una imagen de un ejemplo de árbol de códigos Huffman

![alt text](https://i.ibb.co/kQQng35/huffman.png)

### 1.3 Ficheros fuente y documentación proporcionada

El código de la práctica se ha llevado a cabo en lenguaje C++ siendo Atom y Visual Studio Code los editores de código fuente 
empleados para su desarrollo. Los archivos de implementación (extensión .cc y .cpp) al igual que los ficheros de interfaz 
(extensión .h) se hallan comentados para facilitar la compresión del código. La memoria de la práctica contiene la información
referente al formato de codificación del árbol y a los tipos abstractos de datos que se han empleado. 

### 1.4 Compilación y ejecución 

Para compilar se deben ejecutar los siguientes comandos:

```
$> make clean
$> make 
```

Para poder ejecutar el compresor se deben ejecutar los siguientes comandos:

```
$> ./huf -c <nombre fichero>
$> ./huf -d <nombre fichero>
```
El primer comando es utilizado para llevar a cabo la compresión del fichero. El flag -c indica el funcionamiento en modo de 
compresión y <nombre fichero> es el nombre del fichero que se desea comprimir. Los ficheros a comprimir deben estar almacenados
en el subdirectorio "/Ficheros" por motivos de diseño. El fichero comprimido tiene un nombre idéntico al orginal pero con 
extensión .huf.
  
El segundo comando es utilizado para llevar a cabo la descompresión del fichero. El flag -d indica el funcionamiento en modo de 
descompresión y <nombre fichero> es el nombre del fichero que se desea descomprimir. Los ficheros a descomprimir deben estar 
almacenados en el subdirectorio "Ficheros". El fichero descomprimido tiene un nombre idéntico al original y es guardado en el
subdirectorio "/FicherosResultado".
  
### 1.5 Pruebas realizadas

Para poder poner a punto el compresor se ha empleado una batería de pruebas compuesta por un conjunto de ficheros de diferentes
tamaños y de diferentes extensiones (.sh, .py, .txt, entre otros). Para poder determinar si el fichero antes de comprimir y el 
descomprimido son idénticos basta con ejecutar el siguiente comando:

```
$> diff /Ficheros/nombreFichero /FicherosResultado/nombreFichero
```

Adicionalmente, en la memoria se ha proporcionado una tabla comparativa donde figuran los ficheros de prueba usados al igual que 
los comprimidos, mostrando sus correspondientes tamaños en bytes y el porcentaje de ratio de compresión. Por útlimo se ha 
proporcionado para cada prueba el tiempo en milisegundos empleado para la compresión y descompresión del fichero.


## 2 - Práctica 2

La segunda práctica ha consistido en dada una compañía fictia llamada O’zbekiston, encargada de gestionar una línea ferroviaria
entre Taskent y la cuidad de Samarcanda, que tiene paradas en las estaciones intermedias. Las estaciones están numeradas
sucesivamente, de 0 (Taskent, estación de inicio de línea) hasta Samarcanda, (estacion final de línea).

La compañía quiere llevar a cabo un experimento para mejorar la capacidad de transportede pasajeros y al mismo tiempo aumentar
los ingresos. Los trenes utilizados en la línea tienen una capacidad máxima de n pasajeros. El precio del billete del viaje
es igual al número de paradas (estaciones) entre la estación de salida y la estación de llegada (incluida la estación de
llegada). Antes de que el tren salga de la estación de Taskent, se recolectan los pedidos de reservas de viaje en todas las  
estaciones de la línea. Un pedido de reservas realizado por una estación i, (i= 0, . . . , m−1) incluye todas las reservas de
viaje de la estación i hasta una estación j(j > i, j= 1, . . . m). En caso de que la compañía no pueda aceptar todos los 
pedidos, debido a las limitacionesde capacidad del tren, la polıtica es aceptar o rechazar completamente los pedidos de 
reserva individuales por estaciones individuales.

El objetivo es diseñar un algoritmo que encuentre el máximo beneficio para la compañía empleando la técnica de ramificación y 
poda (Branch and Bound).

### 2.1 Ficheros fuente y documentación

El código de la práctica se ha llevado a cabo en lenguaje C++ siendo Atom y Visual Studio Code los editores de código fuente 
empleados para su desarrollo. Los archivos de implementación (extensión .cc y .cpp) al igual que los ficheros de interfaz 
(extensión .h) se hallan comentados para facilitar la compresión del código. El planteamiento empleado para resolver el problema
ha sido una estrategia de mínimo coste. 

La memoria de la práctica contiene los datos referentes a la implementación del árbol así como las funciones utilizadas 
para el cálculo del coste c(x), el cálculo del coste estimado c^(x), y el cálculo de la función de poda U(x) para podar los 
nodos del árbol que no llevan a solución factible. Adicionalmentse proporciona detalles acerca de los diferentes tipos 
abstractos de datos empleados para resolver el porblema.

### 2.2 Compilación y ejecución 

Para compilar se deben ejecutar los siguientes comandos:

```
$> make clean
$> make 
```

Para poder ejecutar el programa se debe ejecutar el siguiente comando:

```
$> ./transporte pruebas.txt resultados.txt
```

El fichero "pruebas.txt" es un fichero de entrada que contiene 8000 instancias del problema y el fichero "resultados.txt" es un
fichero de texto que contiene las soluciones para cada uno de esos problemas.

### 2.3 Formato del fichero de entrada

El fichero de texto "pruebas.txt" está organizado en bloques: cada bloque es una instancia diferente del problema. La primera 
ĺınea de cada bloque tiene tres enteros: la capacidad n del tren, el número m (máximo 7) de la estación final de línea y el
número de pedidos total p(máximo 22). Las p líneas siguientes representan los pedidos. Para cada pedido hay tres enteros: 
estación de salida, estación de llegada y número de pasajeros. El bloque final de fichero está compuesto por una unica línea
con los tres enteros igual a cero.

### 2.4 Formato del fichero de salida

El fichero de salida tiene un número de líneas igual al número de bloques del fichero de entrada, excepto el bloque final. Cada
línea incluye dos números: el valor(entero) del máximo ingreso total y el tiempo de ejecución en segundos.

### 2.5 Pruebas realizadas

Para probar el algoritmo de ramificación y poda propuesto se ha empleado el fichero "pruebas.txt", especificado anteriormente.
Adicionalmente se ha verificado si el algoritmo obtiene los resultados correctos y además como de eficiente es para poder 
calcularlos. Para ello se ha diseñado un script en python llamado "fuerzaBruta.py" que calcula las soluciones a las problemas 
pero aplicando una solución de fuerza bruta. La ejecución del algoritmo de fuerza bruta tiene como resultado la creación de un
fichero de texto denominado "resultadosFB.txt" que guarda el beneficio y el tiempo de ejecución de cada problema en segundos.

Para poder comprobar que los beneficios obtenidos por ambos algoritmos son los mismos se ha creado un script en lenguaje shell
llamado "profitChecker.sh" que compara automáticamente los beneficios de ambos ficheros y muestra si hay diferencias.

Para poder comprobar la eficiencia del algoritmo de ramificación y poda se desarrollado un script adicional en python llamado
"timeChecker.py" que compara los tiempos de ejecución, en segundos, de cada algoritmo mostrando en cuántas instancias del
problema ha sido más eficiente el algoritmo de ramificación y poda que el de fuerza bruta.

Finalmente en la memoria se plasma una gráfica comparativa con los resultados de ejecución de tiempo de cada algoritmo donde
se puede observar sin problemas el comportamiento de cada uno.

