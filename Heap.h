#ifndef HEAP_H
#define HEAP_H

#include <iterator>
#include <iostream>
#include <cstring>
#include "CarFrec.h"
#include "ArbolTrie.h"


const int MAX_CARACTERES = 256;

using namespace std;

struct Heap {
	private:
		// monticulo de tuplas <caracter, frecuencia> ordenado por frecuencias
		ArbolTrie arboles[MAX_CARACTERES + 1];
        int num;
	public:
	
	    friend void crearVacio(Heap& h);
		
		friend int numElementos(Heap& h);

        friend void anyadir(Heap& h, ArbolTrie& a);

        friend void eliminarMin(Heap& h);

        friend ArbolTrie min(Heap& h);

        friend bool esVacio(Heap& h);
	 
		friend ArbolTrie consultar(Heap& h, const int i);
		
		friend void rellenar(Heap& h, const int frecsPorChar[]);
};


#endif