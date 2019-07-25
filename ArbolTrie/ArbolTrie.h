/*
 * ***********************************************
 * Asignatura : Algoritmia basica ****************
 * Autores : Rubén Rodríguez Esteban 737215 ******
 *           José María Vallejo Puyal 720044 *****
 * Fecha : 16-3-19 *******************************
 * ***********************************************
 */

#ifndef ARBOLTRIE_H
#define ARBOLTRIE_H

#include <iostream>
#include <cstring>
#include "../CarFrec/CarFrec.h"

using namespace std;

/*
 * Fichero de interfaz del modulo ArbolTrie
 */

struct ArbolTrie {
	private:
		// Estructura interna del arbol que permite
		// trabajar con nodos 
		struct Nodo {
			int frecuencia;		// suma de las frecuencias totales de los sub-arboles hijos
			carFrec dato;		// tupla <caracter, frecuencia> 
			Nodo* der; 
			Nodo* izq;		// punteros a los subarboles izquierdo y derecho
		};
		
		Nodo* raiz;		// puntero a la raiz del arbol
	public:
		// funciones amigas para poder trabajar fuera de la especificacion

		/*
		 * Pre: <<e>> es una tupla <carater, frecuencia>
		 * Post: Ha creado un arbol de manera que el campo <<dato>> del arbol nuevo
		 *       toma el valor de <<e>>, el campo <<frecuencia>> toma el valor de la frecuencia de <<e>>
		 *       y los punteros a los subarboles izquuierdo y derecho son nulos
		 */
		friend void crearArbol(ArbolTrie& a, carFrec& e);


		/*
		 * Pre: <<a>> es un arbol de tuplas <caracter, frecuencia> y 
		 *      <<frecuencia>> indica la frecuencia de caracteres a asignar
		 * Post: Ha asignado al caracter recogido en el arbol <<a>> la frecuencia 
		 *       <<frecuencia>>
		 */
		 friend void asignarFrecuencia(ArbolTrie& a, const int& frecuencia);


		/*
		 * Pre: <<a>> y <<aIzq>> son dos arboles que almacenan tuplas <caracter, frecuencia>>
		 * Post: Ha asignado <<aIzq>> como subarbol izquierdo de <<a>>
		 */
		friend void asignarArbolIzquierdo(ArbolTrie& a, const ArbolTrie& aIzq);


		/*
		 * Pre: <<a>> y <<aDer>> son dos arboles que almacenan tuplas <caracter, frecuencia>>
		 * Post: Ha asignado <<aDer>> como subarbol derecho de <<a>>
		 */
		friend void asignarArbolDerecho(ArbolTrie& a, const ArbolTrie& aDer);


		/*
		* Pre: <<a>> es un arbol que almacena una tupla <caracter, valor> y 
		*      <<cF>> es una tupla <caracter, valor> libre
		* Post: Ha reemplazado la tupla <caracter, valor> almacenada en <<a>> por
		*       la tupla <<cF>>
		*/
		friend void asignarArbolCarFrec(ArbolTrie& a, const carFrec& cF);
		

		/*
		 * Pre: <<a>> es un arbol que almacena tuplas <caracter, frecuencia>>
		 * Post: Ha devuelto la frecuencia del arbol <<a>>
		 */
		 friend int obtenerArbolFrecuencia(const ArbolTrie& a);


		/*
		 * Pre: <<a>> es un arbol que almacena una tupla <caracter, frecuencia>
		 * Post: Ha devuelto la tupla <caracter, valor> asociada al arbol <<a>>
		 */
		 friend carFrec obtenerCarFrec(const ArbolTrie& a);

		/*
		 * Pre: <<a>> es un arbol que almacena tuplas <caracter, frecuencia>>
		 * Post: Ha devuelto el subarbol izquierdo de <<a>>
		 */
		 friend ArbolTrie obtenerArbolIzquierdo(const ArbolTrie& a);


		/*
		 * Pre: <<a>> es un arbol que almacena tuplas <caracter, frecuencia>>
		 * Post: Ha devuelto el subarbol derecho de <<a>>
		 */
		 friend ArbolTrie obtenerArbolDerecho(const ArbolTrie& a);


		/*
		 * Pre: <<a>> es un arbol que almacena tuplas <caracter, frecuencia
		 * Post: Devuelve <<true>> si y solo si el arbol <<a>> es hoja. En caso
		 *       contrario devuelve <<false>>
		 */
		 friend bool esHoja (const ArbolTrie& a);


		/*
		 * Pre: <<a1>> y <<a2>> son dos arboles que almacenan tuplas <caracter, frecuencia>
		 * Post: Ha devuelto un arbol de manera que <<a1>> es el hijo izquierdo del nuevo arbol y
		 *       y <<a2>> es el hijo derecho
		 */
		friend void unir(ArbolTrie& a1, ArbolTrie& a2, ArbolTrie& arbolFinal);


//		friend ArbolTrie crearArbolHuffman(Cola& c);

		/*
		 * Pre: <<a>> es un puntero a un nodo que almacena una tupla <caracter, frecuencia>, <<cadena>>
		 *      es una secuencia binaria de caracteres que codifica un determinado caracter recogido
		 *      en el arbol y ya han sido examinados los <<indice-1>> caracteres de la cadena 
		 * Post: Ha guardado en <<cB>> el caracter recogido en el arbol <<a>> si el caracter presente en el
		*       indice <<indice>> es igual al carcter nulo. En caso contrario si el caracter es 
		 *       un cero ha seguido buscando en el subarbol izquierdo de <<a>> y si el caracter es
		 *       un uno busca en el subarbol derecho
		 */
		 friend void decodificarCaracter(ArbolTrie::Nodo* a, string cadena, int indice,  char& cB);


		/*
		 * Pre: <<a>> es un arbol que almacena tuplas <caracter, frecuencia> y <<cadena>>
		 *      es una secuencia binaria de caracteres que codifica un determinado caracter recogido
		 *      en el arbol <<a>>
		 * Post: Ha devuelto el caracter recogido en el arbol <<a>> correspondiente a la codificacion 
		 *       de <<cadena>>
		 */
		friend char decodificarCaracter(ArbolTrie &a, string cadena);
		
};

#endif
