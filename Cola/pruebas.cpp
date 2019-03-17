#include <iostream>
#include <cstring>
#include "Cola.h"

const int MAX_FICHERO_NOMBRE = 100;

int main(){
	const char fichero[MAX_FICHERO_NOMBRE] = "frecuencias.txt";
	// limpieza del vector
	Cola c;
	crear(c);
	
	cout << "Leyendo fichero " << fichero << endl;
	// rellenado con los nuevos caracteres
	frecuenciasPorCaracter(fichero, c);
	
	int total = numElementos(c);
	
	//ordenacion por metodo quicksort
	quicksort(c, 0, total - 1);
	return 0;
}
