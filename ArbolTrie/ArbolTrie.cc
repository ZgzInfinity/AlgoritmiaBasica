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


/* OK
 * Pre: <<a>> es un arbol de tuplas <caracter, frecuencia> y
 *      <<frecuencia>> indica la frecuencia de caracteres a asignar
 * Post: Ha asignado al caracter recogido en el arbol <<a>> la frecuencia
 *       <<frecuencia>>
 */
void asignarFrecuencia(ArbolTrie& a, const int& frecuencia){
	ArbolTrie::Nodo* aux = a.raiz;
	aux->frecuencia = frecuencia;
}


/* OK
 * Pre: <<a>> y <<aIzq>> son dos arboles que almacenan tuplas <caracter, frecuencia>>
 * Post: Ha asignado <<aIzq>> como subarbol izquierdo de <<a>>
 */
void asignarArbolIzquierdo(ArbolTrie& a, const ArbolTrie& aIzq){
	ArbolTrie::Nodo* aux = a.raiz;
	aux->izq = aIzq.raiz;
}


/* OK
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


/* OK
 * Pre: <<a>> es un arbol que almacena tuplas <caracter, frecuencia>>
 * Post: Ha devuelto el subarbol izquierdo de <<a>>
 */
ArbolTrie obtenerArbolIzquierdo(const ArbolTrie& a){
	ArbolTrie aF;
	ArbolTrie::Nodo* aux = a.raiz;
	aF.raiz = aux->izq;
	return aF;
}


/* OK
 * Pre: <<a>> es un arbol que almacena tuplas <caracter, frecuencia>>
 * Post: Ha devuelto el subarbol derecho de <<a>>
 */
ArbolTrie obtenerArbolDerecho(const ArbolTrie& a){
	ArbolTrie aF;
	ArbolTrie::Nodo* aux = a.raiz;
	aF.raiz = aux->der;
	return aF;
}



/* OK
 * Pre: <<a>> es un arbol que almacena tuplas <caracter, frecuencia
 * Post: Devuelve <<true>> si y solo si el arbol <<a>> es hoja. En caso
 *       contrario devuelve <<false>>
 */
bool esHoja (const ArbolTrie& a){
	return a.raiz->izq == nullptr && a.raiz->der == nullptr;
}


/* OK
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
void decodificarCaracter(ArbolTrie& a, ArbolTrie::Nodo* raiz, string cadena, int indice, ofstream& nombre){
	if (indice != int(cadena.size() - 1)){
		if (esHoja(a))
		cout << "entro " << endl;
		char c = cadena.at(indice);
		cout << cadena.at(indice) << endl;
		if (c == '0'){
			decodificarCaracter(a->izq,raiz, cadena, indice + 1, nombre);
		}
		else if (c == '1'){
			decodificarCaracter(a->der,raiz, cadena, indice + 1, nombre);
		}
	}
	else {
		nombre << a->dato.getCaracter();
		cout << "el caracter es " << a->dato.getCaracter() << endl;
		decodificarCaracter(raiz,raiz, cadena, indice + 1, nombre);
	}
}


/*
 * Pre: <<a>> es un arbol que almacena tuplas <caracter, frecuencia> y <<cadena>>
 *      es una secuencia binaria de caracteres que codifica un determinado caracter recogido
 *      en el arbol <<a>>
 * Post: Ha devuelto el caracter recogido en el arbol <<a>> correspondiente a la codificacion
 *       de <<cadena>>
 */
void decodificarCaracter(ArbolTrie &a, string cadena, string nombreFichero){
	ofstream f;
	f.open(nombreFichero, ios::app);
	if (f.is_open()){
		decodificarCaracter(a.raiz,a.raiz,cadena, 0, f);
	}
	else {
		cerr << "Error" << endl;
	}
}



/*
 * Pre: <<a>> es un arbol que guarda tuplas <caracter, frecuencia> en
 *      cada uno de sus nodos hoja correspondientes a los caracteres
 *      recogidos en un fichero de texto junto con sus frecuencias de
 *      aparicion y <<f>> es un flujo de escritura asociado a un fichero
 *      de texto donde se ha escrito una parte el arbol codificado,
 *      <<enHijoIzquierdo>> toma valor <<true>> si el nodo apuntado del
 *      arbol <<a>> es nodo hoja y ademas es hijo izquierdo,
 *      <<enHijoDerecho>> toma valor <<true>> si el nodo apuntado del
 *      arbol <<a>> es nodo hoja y ademas es hijo derecho. Si el nodo apuntado
 *      del arbol <<a>> es una hoja ambos toman valor <<false>>
 * Post: Ha volcado en el fichero de texto asociado al flujo de escritura
 *       <<f>> el contenido restante del arbol <<a>>
 *
 */
void guardarArbolEnFicheroRec(ArbolTrie a, ofstream& f, bool enHijoIzquierdo, bool enHijoDerecho){
		// Comprobacion de si el nodo es o no una hoja
		if (!esHoja(a)){
			// Escritura de la frecuencia del nodo y de que es interno
			f << "#";
			// Comprobar el hijo izquierdo del nodo actual
			guardarArbolEnFicheroRec(obtenerArbolIzquierdo(a), f, true, false);

			// Comprobar el hijo el hijo derecho del nodo actual
			guardarArbolEnFicheroRec(obtenerArbolDerecho(a), f, false, true);
		}
		else {
			// El nodo es una hojaArbolTrie::Nodo* a
		    // Obtencion de la tupla <caracter, frecuencia> del nodo
			carFrec c = obtenerCarFrec(a);

			// Obtencion del caracter y la frecuencia de la tupla y del tipo de hijo
			char caracter = c.getCaracter();
			// string tipoHijo;
			// // Comprobar si la hoja es hijo izquierdo o hijo derecho
			// if (enHijoIzquierdo){
			// 	 // La hoja es el hijo izquierdo
			// 	 tipoHijo = "I";
			// }
			// else if (enHijoDerecho){
			// 	// La hoja es el hijo derecho
			// 	tipoHijo = "D";
			// }
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
			guardarArbolEnFicheroRec(a, f, false , false);
		}
		else {
			cerr << "El fichero para guardar el arbol de codificacion "
					 << arbolNombreFichero << " es innacesible" << endl;
		}
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
	// Comprobar si la lectura ha sido efectiva
	if (!f.eof()){
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
        // Llamadas recursivas
        codificador(codigos,obtenerArbolIzquierdo(a),codigoIzq);
        codificador(codigos,obtenerArbolDerecho(a),codigoDer);
    }

}

void descifra(string nombre, ArbolTrie& trie){
    ifstream f(nombre, ios::binary | ios::in);
    char c;
	string total = "";
    while (f.get(c))
    {
        for (int i = 7; i >= 0; i--){
            int a =  ((c >> i) & 1);
            total = total + std::to_string(a);
            //Recorrer el arbol y descifrar las letras
        }		
    }
	cout << "entro a decodificar" << endl;
	decodificarCaracter(trie,total,"va.txt");
	//cout << "el total es " << total;
}