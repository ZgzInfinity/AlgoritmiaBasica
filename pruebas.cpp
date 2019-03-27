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
	
	cout<<"1";
	int total = numElementos(c);
	cout<<"2";
	//ordenacion por metodo quicksort
	quicksort(c, 0, total - 1);
	ArbolTrie a;
	carFrec ca;
	cout << "Fallo en el bucle";
	for(int i = 0 ; i < total - 1; i++){
		a = consultarArbol(c,i);
		ca = obtenerCarFrec(a);
		cout <<  "Caracrer: "<< ca.getCaracter() << " Frecuencua: "<< ca.getFrecuencia()<< endl; 
	}
	cout << "Fin del programa " << endl;
	return 0;
	
}
