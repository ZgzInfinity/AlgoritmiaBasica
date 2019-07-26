#include <iostream>
#include <cstring>
#include "Huffman/Huffman.h"
#include "CarFrec/CarFrec.h"
#include "ArbolTrie/ArbolTrie.h"
#include "Heap/Heap.h"


int main(){

	ArbolTrie a;
	string codigos[MAX_CARACTERES];
	iniciarCodificaciones(codigos);
  comprimir("frecuencias.txt");
	construirArbolDeFichero("arbolfrecuencias.txt",a);

	// Codificacion de caracteres con codigos binarios
	codificador(codigos,a,"");

  // QUITAR ESTA MIERDA
	// Muestreo de los codigos binarios obtenidos
	for(int j = 0; j < 256; j++){
		if(codigos[j]!= "-")
		cout << "El codigo de " << (char)j << " es: " << codigos[j] << endl;
	}

	descifra("frecuencias.bin", a);

  return 0;
}
