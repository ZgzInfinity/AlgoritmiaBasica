/*
 * ***********************************************
 * Asignatura : Algoritmia basica ****************
 * Autores : Rubén Rodríguez Esteban 737215 ******
 *           José María Vallejo Puyal 720044 *****
 * Fecha : 16-3-19 *******************************
 * ***********************************************
 */

#include "ArbolTrie.h"


/*
 * Pre: <<e>> es una tupla <carater, frecuencia>
 * Post: Ha creado un arbol de manera que el campo <<dato>> del arbol nuevo
 *       toma el valor de <<e>>, el campo <<frecuencia>> toma el valor de la frecuencia de <<e>>
 *       y los punteros a los subarboles izquuierdo y derecho son nulos
 */
void crearArbol(ArbolTrie& a, carFrec& e){
	ArbolTrie::Nodo* aux = new ArbolTrie::Nodo;
	aux->dato = e;
	aux->frecuencia = 0;
	aux->der = nullptr;
	aux->izq = nullptr;
	a.raiz = aux;
}


/*
 * Pre: <<a>> es un arbol de tuplas <caracter, frecuencia> y
 *      <<frecuencia>> indica la frecuencia de caracteres a asignar
 * Post: Ha asignado al caracter recogido en el arbol <<a>> la frecuencia
 *       <<frecuencia>>
 */
void asignarFrecuencia(ArbolTrie& a, const int& frecuencia){
	ArbolTrie::Nodo* aux = a.raiz;
	aux->frecuencia = frecuencia;
}


/*
 * Pre: <<a>> y <<aIzq>> son dos arboles que almacenan tuplas <caracter, frecuencia>>
 * Post: Ha asignado <<aIzq>> como subarbol izquierdo de <<a>>
 */
void asignarArbolIzquierdo(ArbolTrie& a, const ArbolTrie& aIzq){
	ArbolTrie::Nodo* aux = a.raiz;
	aux->izq = aIzq.raiz;
}


/*
 * Pre: <<a>> y <<aDer>> son dos arboles que almacenan tuplas <caracter, frecuencia>>
 * Post: Ha asignado <<aDer>> como subarbol derecho de <<a>>
 */
void asignarArbolDerecho(ArbolTrie& a, const ArbolTrie& aDer){
	ArbolTrie::Nodo* aux = a.raiz;
	aux->der = aDer.raiz;
}


/*
 * Pre: <<a>> es un arbol que almacena una tupla <caracter, valor> y
 *      <<cF>> es una tupla <caracter, valor> libre
 * Post: Ha reemplazado la tupla <caracter, valor> almacenada en <<a>> por
 *       la tupla <<cF>>
 */
void asignarArbolCarFrec(ArbolTrie& a, const carFrec& cF){
	a.raiz->dato = cF;
}



/*
 * Pre: <<a>> es un arbol que almacena tuplas <caracter, frecuencia>>
 * Post: Ha devuelto la frecuencia del arbol <<a>>
 */
int obtenerArbolFrecuencia(const ArbolTrie& a){
	return a.raiz->frecuencia;
}


/*
 * Pre: <<a>> es un arbol que almacena una tupla <caracter, frecuencia>
 * Post: Ha devuelto la tupla <caracter, valor> asociada al arbol <<a>>
 */
carFrec obtenerCarFrec(const ArbolTrie& a){
	return a.raiz->dato;
}


/*
 * Pre: <<a>> es un arbol que almacena tuplas <caracter, frecuencia>>
 * Post: Ha devuelto el subarbol izquierdo de <<a>>
 */
ArbolTrie obtenerArbolIzquierdo(const ArbolTrie& a){
	ArbolTrie aF;
	ArbolTrie::Nodo* aux = a.raiz;
	aF.raiz = aux->izq;
	return aF;
}


/*
 * Pre: <<a>> es un arbol que almacena tuplas <caracter, frecuencia>>
 * Post: Ha devuelto el subarbol derecho de <<a>>
 */
ArbolTrie obtenerArbolDerecho(const ArbolTrie& a){
	ArbolTrie aF;
	ArbolTrie::Nodo* aux = a.raiz;
	aF.raiz = aux->der;
	return aF;
}



/*
 * Pre: <<a>> es un arbol que almacena tuplas <caracter, frecuencia
 * Post: Devuelve <<true>> si y solo si el arbol <<a>> es hoja. En caso
 *       contrario devuelve <<false>>
 */
bool esHoja (const ArbolTrie& a){
	return a.raiz->izq == nullptr && a.raiz->der == nullptr;
}


/*
 * Pre: <<a1>> y <<a2>> son dos arboles que almacenan tuplas <caracter, frecuencia>
 * Post: Ha devuelto un arbol de manera que <<a1>> es el hijo izquierdo del nuevo arbol y
 *       y <<a2>> es el hijo derecho
 */
void unir(ArbolTrie& a1, ArbolTrie& a2, ArbolTrie& arbolFinal){
	ArbolTrie::Nodo* aux;
	aux = new ArbolTrie::Nodo;
	aux->frecuencia = obtenerArbolFrecuencia(a1) + obtenerArbolFrecuencia(a2);
	aux->izq = a1.raiz;
	aux->der = a2.raiz;
	arbolFinal.raiz = aux;
}




/*
 * Pre: <<a>> es un puntero a un nodo que almacena una tupla <caracter, frecuencia>, <<cadena>>
 *      es una secuencia binaria de caracteres que codifica un determinado caracter recogido
 *      en el arbol y ya han sido examinados los <<indice-1>> caracteres de la cadena
 * Post: Ha guardado en <<cB>> el caracter recogido en el arbol <<a>> si el caracter presente en el
 *       indice <<indice>> es igual al carcter nulo. En caso contrario si el caracter es
 *       un cero ha seguido buscando en el subarbol izquierdo de <<a>> y si el caracter es
 *       un uno busca en el subarbol derecho
 */
void decodificarCaracterRec(ArbolTrie a1, ArbolTrie a2, string contenidoFichero, int indice, ofstream& f){
	// Comprobar que el contenido del fichero no ha terminado
	if (indice <= int(contenidoFichero.size() - 1)){
		// Extraccion del bit 0 o 1
		char c = contenidoFichero.at(indice);
		// Determinar si el nodo es o no hoja
		if (!esHoja(a1)){
			// Es nodo interno
			// Incremento del indice de la cadena
			indice++;
			if (c == '0'){
				// El bit leido es un 0 y se busca en el hijo izquierdo
				decodificarCaracterRec(obtenerArbolIzquierdo(a1), a2, contenidoFichero, indice, f);
			}
			else if (c == '1'){
				// El bit leido es un 1 y se busca en el hijo derecho
				decodificarCaracterRec(obtenerArbolDerecho(a1), a2, contenidoFichero, indice, f);
			}
		}
		else {
			// El nodo es una hoja
			// Se extrae la tupla <caracter, frecuencia> guardada en el nodo
			carFrec tupla = obtenerCarFrec(a1);
			// Escritura del caracter en el fichero
			f << tupla.getCaracter();
			decodificarCaracterRec(a2, a2, contenidoFichero, indice, f);
		}
	}
	else {
		// Tratamiento del ultimo caracter del fichero
		// Si es el final del contenido del fichero
		if (indice == int(contenidoFichero.size())){
			// Se extrae la tupla <caracter, frecuencia> guardada en el nodo
			carFrec tupla = obtenerCarFrec(a1);
			// Escritura del ultimo caracter en el fichero
			f << tupla.getCaracter();
		}
	}

}


/*
 * Pre: <<a>> es un arbol que almacena tuplas <caracter, frecuencia> y <<cadena>>
 *      es una secuencia binaria de caracteres que codifica un determinado caracter recogido
 *      en el arbol <<a>>
 * Post: Ha devuelto el caracter recogido en el arbol <<a>> correspondiente a la codificacion
 *       de <<cadena>>
 */
void decodificarCaracter(ArbolTrie a, string contenidoFichero, string nombreFichero){
	// Flujo de escritura asociado al fichero de texto
	ofstream f;
	// Apertura del fichero asociado al flujo
	f.open(nombreFichero);
	if (f.is_open()){
		// Si el fichero se ha abierto correctamente
		decodificarCaracterRec(a, a, contenidoFichero, 0, f);
	}
	else {
		// Error al intentar abrir el fichero
		cerr << "El fichero de decodificacion " << nombreFichero
		     << "no esta accesible" << endl;
	}
}



/*
 * Pre: <<a>> es un arbol que guarda tuplas <caracter, frecuencia> en
 *      cada uno de sus nodos hoja correspondientes a los caracteres
 *      recogidos en un fichero de texto junto con sus frecuencias de
 *      aparicion y <<f>> es un flujo de escritura asociado a un fichero
 *      de texto donde se ha escrito una parte el arbol codificado
 * Post: Ha volcado en el fichero de texto asociado al flujo de escritura
 *       <<f>> el contenido restante del arbol <<a>>
 *
 */
void guardarArbolEnFicheroRec(ArbolTrie a, ofstream& f){
		// Comprobacion de si el nodo es o no una hoja
		if (!esHoja(a)){
			// Escritura de la frecuencia del nodo y de que es interno
			f << "#";
			// Comprobar el hijo izquierdo del nodo actual
			guardarArbolEnFicheroRec(obtenerArbolIzquierdo(a), f);
			// Comprobar el hijo el hijo derecho del nodo actual
			guardarArbolEnFicheroRec(obtenerArbolDerecho(a), f);
		}
		else {
			// El nodo es una hojaArbolTrie::Nodo* a
		  // Obtencion de la tupla <caracter, frecuencia> del nodo
			carFrec c = obtenerCarFrec(a);
			// Obtencion del caracter y la frecuencia de la tupla y del tipo de hijo
			char caracter = c.getCaracter();
			// Escritura de la frecuencia del nodo y de que es interno
			f << caracter;
		}
}





/*
 * Pre: <<a>> es un arbol que guarda tuplas <caracter, frecuencia> en
 *      cada uno de sus nodos hoja correspondientes a los caracteres
 *      recogidos en un fichero de texto junto con sus frecuencias de
 *      aparicion
 * Post: Si se ha podido crear sin ningun problema el fichero de
 *       texto <<arbolNombreFichero>> ha guardado en dicho fichero una
 *       representacion del arbol con la siguiente estructura:
 *
 *       Estructura: explicar
 *
 */
void guardarArbolEnFichero(ArbolTrie a, const string arbolNombreFichero){
		// Flujo de escritura asociado al fichero
		ofstream f;
		// Apertura del fichero asociado al flujo
		f.open(arbolNombreFichero);
		if (f.is_open()){
			// Si el fichero se ha abierto correctamente
			guardarArbolEnFicheroRec(a, f);
		}
		else {
			cerr << "El fichero para guardar el arbol de codificacion "
					 << arbolNombreFichero << " es innacesible" << endl;
		}
		// Insertar salto de linea
		f << endl;
		// Cierre del flujo asociado al fichero
		f.close();
 }




 /*
  * Pre: <<a>> es un arbol que guarda tuplas <caracter, frecuencia> en
  *      cada uno de sus nodos hoja correspondientes a los caracteres
  *      recogidos en un fichero de texto junto con sus frecuencias de
  *      aparicion y <<f>> es un flujo de escritura asociado a un fichero
  *      de texto que guarda una representacion del contenido con el que debe
	*      contar el arbol <<a>>
  * Post: Ha volcado en el fichero de texto asociado al flujo de escritura
  *       <<f>> el contenido restante del arbol <<a>>
  *
  */
 void construirArbolDeFicheroRec(ArbolTrie& a, ifstream& f){
	// Caracter a leer
	char caracter;
 	// Intento de leer una nueva linea del fichero
  	f.get(caracter);
	// Comprobar si no se ha leido salto de linea
	if (caracter != '\n'){
		// Se ha leido correctamente se crea la tupla
		carFrec c = carFrec();
		crearArbol(a, c);
		if (caracter == '#'){
			// Nodo interno
			// Como el nodo es interno tiene hijos
			// se van a visitar los hijos izquierdo y derecho

		  // Crear el arbolTrie del hijo izquierdo
		  ArbolTrie aIzq;
			construirArbolDeFicheroRec(aIzq, f);
			asignarArbolIzquierdo(a, aIzq);

			// Crear el arbolTrie del hijo derecho
			ArbolTrie aDer;
			construirArbolDeFicheroRec(aDer, f);
		 	asignarArbolDerecho(a, aDer);
		}
		else {
			// Nodo hoja izquierda o derecha
			// Asignar el caracter y su frecuencia de aparicion
			c.setCaracter(caracter);
			asignarArbolCarFrec(a, c);

			// Apuntar los nodos hijos a nil
			a.raiz->der = nullptr;
			a.raiz->izq = nullptr;
		}
	}
 }




/*
 * Pre: <<arbolNombreFichero>> es un fichero de texto que almacena el arbol
 *      de codigos Huffman de un fichero cuyo nombre es igual a <<NombreFichero>>
 * Post: Ha construido en <<a>> un arbol el arbol de codigos Huffman
 *       correspondiente al fichero <<NombreFichero>>
 */
void construirArbolDeFichero(const string arbolNombreFichero, ArbolTrie& a){
	// Flujo de escritura asociado al fichero
	ifstream f;
	// Apertura del fichero asociado al flujo
	f.open(arbolNombreFichero);
	if (f.is_open()){
		// Si el fichero se ha abierto correctamente
		construirArbolDeFicheroRec(a, f);
	}
	else {
		cerr << "El fichero de lectura del arbol de codificacion "
				 << arbolNombreFichero << " es innacesible" << endl;
	}
	// Cierre del flujo asociado al fichero
	f.close();
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
        // Llamadas recursivas al hijo izquierdo y derecho
        codificador(codigos,obtenerArbolIzquierdo(a),codigoIzq);
        codificador(codigos,obtenerArbolDerecho(a),codigoDer);
    }

}



/*
 * Pre: <<nombreFichero>> es el nombre de un fichero comprimido con
 *      extension de archivo .huf y <<a>> es el arbol de codigos huffman
 *      empleado en la codficacion del fichero <<nombreFichero>>
 * Post: Ha devuelto como resultado un fichero descomprimido con el contenido
 *       del del fichero comprimido <<nombreFichero>> empleando para la
 *       descompresion el arbol de codigos Huffman <<a>>
 */
void descifraFichero(string nombreFichero, ArbolTrie& trie){
	// Flujo de lectura asociado al fichero .huf
  ifstream f(nombreFichero, ios::binary);
  char c;
	// Guardado del contenido del fichero
	string total = "";
	// Ignorar la primera linea del fichero porque es el arbol
	f.ignore(MAX_LONG_LINEA, '\n');
	// Leer caracter a caracter el fichero
  while (f.get(c)){
		  // Parsear el contenido en grupos de bytes
      for (int i = 7; i >= 0; i--){
          int a =  ((c >> i) & 1);
          total = total + std::to_string(a);
      }
  }
	// Decodficar el fichero
  string ficheroSalida = nombreFichero.substr(0, nombreFichero.length() - 4) + "salida.txt";
	decodificarCaracter(trie, total, ficheroSalida);
}
