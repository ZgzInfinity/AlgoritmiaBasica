/*
 * ***********************************************
 * Asignatura : Algoritmia basica ****************
 * Autores : Rubén Rodríguez Esteban 737215 ******
 *           José María Vallejo Puyal 720044 *****
 * Fecha : 25-3-19 *******************************
 * ***********************************************
 */

/*
 * Fichero de interfaz del modulo Huffman
 */

#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <iostream>
#include <cstring>
#include <fstream>
#include "../Preliminar/Preliminar.h"
#include "../CarFrec/CarFrec.h"
#include "../Heap/Heap.h"
#include "../ArbolTrie/ArbolTrie.h"


using namespace std;


const int BASE = 2;
const int TAMANYO_BYTE = 8;


struct Huffman{
	private:
		int codigo;
		int digitos;
	public:
		/*
		 * Pre: <<c>> es una cola de arboles hojas en los que se guardan
		 *       tuplas <caracter, valor> ordenadas por orden decreciente de
		 *		frecuencias
		 * Post: El arbol <<huffman>> es el arbol de codificacion Huffman que guarda un
		 *       codigo libre de prefijos optimo para <<c>>
		 */
		friend void generaHuffman(Heap& c, ArbolTrie& huffman, Huffman& h);


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
		friend void codificador(string codigos[],const ArbolTrie& a, string codigo);




		/*
		 * Pre: <<ficheroEntrada>> es un fichero de texto que almacena
		 *      caracteres tanto especiales como alfanumericos
		 * Post: <<ficheroSalida>> es un fichero comprimido binario que almacena
		 *       de forma comprimida la secuencia de caracteres guardada en el fichero
		 *       denominado <<ficheroEntrada>> empleando como mecanismo de compresion
		 *		   los codigos Huffman
		 */
		friend void comprimir(string ficheroEntrada, Huffman& h);



		/*
		 * Pre:  <<ficheroEntrada>> es un fichero de texto que almacena
		 *       caracteres tanto especiales como alfanumericos
		 * Post: Si el fichero se ha abierto correctamente ha leido su contenido
		 *       caracter a caracter guardando la representacion binaria de cada
		 *       uno en el vector <<contenidoFichero>>. En caso contrario ha
		 *       mostrado por salida estandar el error de apertura.
		 */
		friend void leerFichero(string ficheroEntrada, string& contenidoFichero, string codigos[]);




		/*
		 * Pre:  <<contenido>> es una secuencia que almacena un conjunto
		 *       de caracteres representados con su codificacion binaria
		 *       caracteres tanto especiales como alfanumericos
		 * Post: Si el fichero <<ficheroSalida>> se ha creado correctamente ha
		 *       volcado el contenido almacenado en <<contenido>>
		 *       comprimido. En caso contrario ha mostrado por salida estandar el
		 *       error de apertura.
		 */
		friend void escribirFichero(const string contenido, string ficheroSalida);
};


#endif
