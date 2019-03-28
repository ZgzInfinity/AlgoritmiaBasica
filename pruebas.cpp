#include <iostream>
#include <cstring>
#include "Cola.h"
#include "CarFrec.h"
#include "ArbolTrie.h"
#include "Heap.h"

const int UMBRAL = 51;
const int MAX_FICHERO_NOMBRE = 100;

int main(){
	const char fichero[MAX_FICHERO_NOMBRE] = "frecuencias.txt";
	// limpieza del vector
	Heap c;
	crearVacio(c);
	
	cout << "Leyendo fichero " << fichero << endl;
	// rellenado con los nuevos caracteres
	// frecuenciasPorCaracter(fichero, c);
	
	int total = numElementos(c);
	cout << "La cantidad inicial de elementos del monticulo es " << total << endl << endl;
	
	int capacidad;
	cout << "Introduzca la cantidad de elementos del monticulo " << flush;
	cin >> capacidad;
	
	// Variables para probar el monticulo
	ArbolTrie a;
	carFrec ca;
	
	int frec;
	char car;
	
	
	// no repetir caracteres para la prueba
	for (int i = 0; i < capacidad; i++){
		// pedir caracter al usuario
		cout << "Introduzca el caracter " << flush;
		cin >> car;
		// pedir frecuencia al usuario
		cout << "Introduzca la frecuencia " << flush;
		cin >> frec;
		
		// generar carFrec
		ca = carFrec(car, frec);
		// crea rArbol con nuevo carFrec
		crearArbol(a, ca);
		
		// añadir al monticulo el nuevo arbol
		anyadir(c, a);
	}
	
	cout << "El monticulo esta lleno " << endl;
	
	total = numElementos(c);
	cout << "Ahora hay en el monticulo " << total << " elementos " << endl;
	
	for (int i = 1; i < total; i++){
		a = consultar(c, i);
		ca = obtenerCarFrec(a);
		cout << i << " C: " << ca.getCaracter() << " F: " << ca.getFrecuencia() << endl;
	}
	
	cout << "Fin del programa " << endl;
	return 0;
	
}
