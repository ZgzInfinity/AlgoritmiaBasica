#include "Huffman.h"

using namespace std;


/*
 * Pre: <<c>> es una cola de prioridades o monticulo donde se almacenan todos los
 *      caracteres y sus correspondientes frecuencias de caracteres ordenados por
 *      orden decreciente de frecuencia. <<a>> es un trie en cuyos nodos residen los
 *      caracteres y sus correspondientes frecuencias
 * Post: <<h>> es el resultado de aplicar el algoritmo de codificacion Huffman de tal forma
 *        que a los caracteres con mayor valor de frecuencia se les ha asignado un codigo de
 *        compresion menor y a los digitos de mayor frecuencia un codigo mayor, garantizando
 *        asi un tamanyo de fichero comprimido menor
 */
void generaHuffman(Heap& c, ArbolTrie& a, Huffman& h){
	// Obtener primer elmentos del monticulo
    ArbolTrie pri = min(c);
	// Eliminar el primer elemento del monticulo
    eliminarMin(c);
	// Obtener el nuevo primer elemento del monticulo
    ArbolTrie segundo = min(c);
	// Eliminar el nuevo primer elemento del monticulo
    eliminarMin(c);
	// Si quedan elementos
    if(numElementos(c)>0){
		// Crear un nuevo nodo uniendo los otros dos
        ArbolTrie aux;
        unir(pri, segundo, aux);
		// Insertar el nuevo formado en la cola de prioridades
        anyadir(c,aux);
        generaHuffman(c, a, h);
    }
	else{
		// Crear un nuevo nodo uniendo los otros dos
        unir(pri, segundo, a);
    }
}



/*
 * Pre:  <<codigos>> es un vector de caracteres de con capacidad
 *       para 256 caracteres, <<a>> es el trie que almacena en cada uno de sus
 *       nodos un caracter presente en el fichero junto con su correspondiente
 *       frecuencia, <<h>> SOBRA y <<codigo>> es un frgamento de codificacion
 *       del caracter actual apuntado por la raiz del arbol <<a>>
 * Post: Ha guardado en cada una de las componentes del vector <<codigos>>
 *       la codificacion binaria a cada caracter presente en el fichero
 *
 *       Ejemplo:
 *       A = 0
 *       B = 101
 *       C = 100
 *       D = 111
 *       E = 1101
 *       F = 1100
 *
 *       ............
 *
 */
void codificador(string codigos[],const ArbolTrie& a, string codigo){
    // Comprobar que el nodo actual es hoja
    if(esHoja(a)){
        // Obtencion del caracter con su frecuencia
        carFrec c = obtenerCarFrec(a);
        // Guardar el codigo del caracter
        codigos[(int)c.getCaracter()]=codigo;
    }
    else{
        // Si el nodo no es hoja se inserta en la codificacion del caracter
        // un 0 para ir al hijo izuierdo y un 1 para ir al hijo derecho
        string codigoIzq = codigo + "0";
        string codigoDer = codigo + "1";
        // Llamadas recursivas
        codificador(codigos,obtenerArbolIzquierdo(a),codigoIzq);
        codificador(codigos,obtenerArbolDerecho(a),codigoDer);
    }
}



void descifra(string nombre){
    ifstream f(nombre, ios::binary | ios::in);
    char c;
    while (f.get(c))
    {
        for (int i = 7; i >= 0; i--){
            int a =  ((c >> i) & 1);
            cout<<a;
            //Recorrer el arbol y descifrar las letras
        }
    }
}


/*
 * Pre:  <<ficheroEntrada>> es un fichero de texto que almacena
 *       caracteres tanto especiales como alfanumericos
 * Post: Si el fichero se ha abierto correctamente ha leido su contenido
 *       caracter a caracter guardando la representacion binaria de cada
 *       uno en el vector <<contenidoFichero>>
 */
void leerFichero(string ficheroEntrada, string& contenidoFichero, string codigos[]){
    // Flujo de lectura asociado al fichero
    ifstream f;
    // Apertura del fichero de texto
    f.open(ficheroEntrada);
    if (f.is_open()){
      // Si el fichero se abre correctamente

      // Leer el fichero caracter a caracter
      char c;
      f.get(c);

      // Mientras queden caracteres por leer
      while (!f.eof()){
          // Guardar la codificacion binario del caracter leido
          contenidoFichero += codigos[(int)c];

          // Leer el siguiente caracter
          f.get(c);
      }
      // Cierre del flujo de lectura
      f.close();
    }
    else {
      // El fichero no se abre correctamente
      cerr << "Error al abir el fichero " << ficheroEntrada << endl;
    }
}



/*
 * Pre:  <<contenido>> es una secuencia que almacena un conjunto
 *       de caracteres representados con su codificacion binaria
 *       caracteres tanto especiales como alfanumericos
 * Post: Si el fichero <<ficheroSalida>> se ha creado correctamente ha
 *       volcado el contenido almacenado en <<contenido>>
 *       comprimido. En caso contrario ha mostrado por salida estandar el
 *       error de apertura.
 */
void escribirFichero(const string contenido, string ficheroSalida){
  // Flujo de lectura asociado al fichero
  ofstream f;
  // Apertura del fichero de texto
  f.open(ficheroSalida);
  if (f.is_open()){
    // Si el fichero se abre correctamente

    // Parsear el contenido del fichero para guardalo en grupos de bytes
    int indice = 0;

    //Mientras queden caracteres por leer
    while(indice < int(contenido.length())){
        if((indice - contenido.length() < TAMANYO_BYTE)){
            f << (char)std::stoi(contenido.substr(indice, indice - contenido.length()), nullptr, BASE);
        }
        else{
            std::stoi(contenido.substr(indice, TAMANYO_BYTE), nullptr, BASE);
            f << (char)std::stoi(contenido.substr(indice, TAMANYO_BYTE), nullptr, BASE);
        }
        // Nuevo byte leido
        indice += TAMANYO_BYTE;
    }
    // Cierre del flujo de escritura
    f.close();
  }
  else {
    // El fichero no se abre correctamente
    cerr << "Error al abir el fichero " << ficheroSalida << endl;
  }
}



/*
 * Pre: <<ficheroEntrada>> es un fichero de texto que almacena una secuencia
 *      de caracteres
 * Post: Si el fichero <<ficheroEntrada>> se ha abierto se ha podido leer correctamente
 *       ha almacenado en <<h>> el resultado de aplicar a dicho fichero el
 *       algoritmo de compresion Huffman de modo que a los caracteres con
 *       mayor frecuencia de aparicion se les ha asignado un codigo de compresion
 *       menor y a los caracteres con una frecuencia de aparicion menor se les ha
 *       asignado un codigo de compresion menor
 */
void comprimir(string ficheroEntrada, Huffman& h){
	// Vector de frecuencias de cada caracter
  int frecsPorChar[MAX_CARACTERES];

	// Inicializar la frecuencia de aparicion de cada caracter a cero
  iniciarFrecuencias(frecsPorChar);

  // vector de codigos binarios para cada caracter
  string codigos[MAX_CARACTERES];

  // Iniciar codificaciones binarias
  iniciarCodificaciones(codigos);

	// Contabilizar las frecuencias de cada caracter
  frecuenciasPorCaracter(ficheroEntrada, frecsPorChar);

  // Creacion del monticulo de prioridades
	Heap hp;
	crearVacio(hp);

	// Rellenado del monticulo a partir de las frecuencias de cada caracter
	rellenar(hp, frecsPorChar);

  // Construccion del arbol de codificacion Huffman
	ArbolTrie huff;
	generaHuffman(hp, huff, h);

	// Codificacion de caracteres con codigos binarios
	codificador(codigos, huff, "");

  // QUITAR ESTA MIERDA
	// Muestreo de los codigos binarios obtenidos
	for(int j = 0; j < 256; j++){
		if(codigos[j]!= "-")
		cout << "El codigo de " << (char)j << " es: " << codigos[j] << endl;
	}

	// Nombre del fichero binario codificado de salida
  string ficheroSalida = ficheroEntrada.substr(0, ficheroEntrada.length() - 4) + ".bin";

  // Cadena donde se almacena la informacion del fichero
  string contenidoFichero = "";

  // Leer fichero de texto y guardar su contenido codificado en binario
  leerFichero(ficheroEntrada, contenidoFichero, codigos);

  // Escribir el contenido comprimido en un nuevo fichero
  escribirFichero(contenidoFichero, ficheroSalida);

  // Creacion del fichero donde se guarda el arbol
  string arbolFichero = "arbol" + ficheroEntrada;

  // Generacion del fichero con el arbol comprimido
  guardarArbolEnFichero(huff, arbolFichero);

  // Generacion del nuevo arbol a partir del fichero comprimido
  ArbolTrie nuevoArbolFinal;
  construirArbolDeFichero(arbolFichero, nuevoArbolFinal);
}
