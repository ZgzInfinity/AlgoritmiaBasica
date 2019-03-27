#include <iostream>
#include <cstring>
#include "Cola.h"
#include "CarFrec.h"
#include "ArbolTrie.h"

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
	
	
	ArbolTrie a;
	carFrec ca;
	
	for(int i = 0 ; i < total; i++){
		a = consultarArbol(c,i);
		ca = obtenerCarFrec(a);
		cout <<  "Caracter: "<< ca.getCaracter() << " Frecuencia: "<< ca.getFrecuencia()<< endl; 
	}
	
	//ordenacion por metodo quicksort TRATA ELEMENTOS NO REPETIDOS
	//quicksort(c, 0, total - 1);
	

	// Pruebas de busqueda binaria 
	cout << "La posicion de la freucencia 11 seria " << posicion(c, 11) << endl;
	cout << "La posicion de la frecuencia 8 seria " << posicion(c, 8) << endl;
	cout << "La posicion de la frecuencia 6 seria " << posicion(c, 6) << endl;
	cout << "La posicion de la frecuencia 2 seria " << posicion(c, 2) << endl;
	cout << "La posicion de la frecuencia 0 seria " << posicion(c, 0) << endl;
	
	ca = carFrec('R', 11);
	crearArbol(a, ca);
	anyadirArbol(c, a);
	
	ca = carFrec('H', 8);
	crearArbol(a, ca);
	anyadirArbol(c, a);
	
	ca = carFrec('K', 6);
	crearArbol(a, ca);
	anyadirArbol(c, a);
	
	ca = carFrec('X', 2);
	crearArbol(a, ca);
	anyadirArbol(c, a);
	
	ca = carFrec('Z', 0);
	crearArbol(a, ca);
	anyadirArbol(c, a);
	
	
	
	
	
	
	cout << "Fin del programa " << endl;
	return 0;
	
}
