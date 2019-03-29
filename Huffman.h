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
#include "CarFrec.h"
#include "Heap.h"
#include "ArbolTrie.h"
#include "Cola.h"
#include <vector>
#include <fstream>

using namespace std;

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


		//Codificador con string 
		friend void codificador(string codigos[],const ArbolTrie& a, string codigo, Huffman& h);
		
		/*
		 * Pre: <<ficheroEntrada>> es un fichero de texto que almacena 
		 *      caracteres tanto especiales como alfanumericos
		 * Post: <<ficheroSalida>> es un fichero comprimido binario que almacena
		 *       de forma comprimida la secuencia de caracteres guardada en el fichero
		 *       denominado <<ficheroEntrada>> empleando como mecanismo de compresion 
		 *		 los codigos Huffman
		 */		 
		void comprimir(char in[], char out[], int codigos[]);
};


#endif