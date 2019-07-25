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
void decodificarCaracter(ArbolTrie::Nodo* a, string cadena, int indice, char& cB){
	if (indice != int(cadena.size())){
		char c = cadena.at(indice);
		if (c == '0'){
			decodificarCaracter(a->izq, cadena, indice + 1, cB);
		}
		else if (c == '1'){
			decodificarCaracter(a->der, cadena, indice + 1, cB);
		}
	}
	else {
		cB = a->dato.getCaracter();
	}
}


/*
 * Pre: <<a>> es un arbol que almacena tuplas <caracter, frecuencia> y <<cadena>>
 *      es una secuencia binaria de caracteres que codifica un determinado caracter recogido
 *      en el arbol <<a>>
 * Post: Ha devuelto el caracter recogido en el arbol <<a>> correspondiente a la codificacion
 *       de <<cadena>>
 */
char decodificarCaracter(ArbolTrie &a, string cadena){
	char cB;
	decodificarCaracter(a.raiz, cadena, 0, cB);
	return cB;
}
