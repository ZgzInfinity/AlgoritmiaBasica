/*
 * ***********************************************
 * Asignatura : Algoritmia basica ****************
 * Autores : Rubén Rodríguez Esteban 737215 ******
 *           José María Vallejo Puyal 720044 *****
 * Fecha : 13-3-19 *******************************
 * ***********************************************
 */

#include "CarFrec.h"
#include <vector>

using namespace std;

/*
 * Programa que reune un conjunto de pruebas básicas
 * para poder probar el funcionamiento del TAD CarFrec
 */
 
int main(){
	// Variables para almacenar el caracter y la frecuencia
	char c;
	int f;
	
	int numCf; // numero de tuplas a crear 
	
	// Peticion del numero de tuplas a crear por el usuario
	cout << "Introduzca el numero de tuplas a crear: " << flush;
	cin >> numCf;
	
	// vector de tuplas de tipo carFrec
	vector <carFrec> numCarFrecs;
	
	// peticion de <<numCF>> tuplas al usuario
	for (int i = 0; i < numCf; i++){
		// Pedir al usuario caracter de tupla i-ésima
		cout << "Introduzca el valor del caracter: " << flush;
		cin >> c;
		
		//Pedir al usuario de tupla i-ésima
		cout << "Introduzca el valor de la frecuencia: " << flush;
		cin >> f;
		
		// Nuevo dato carFrec
		carFrec nuevoCf = carFrec(c ,f);
		
		// Incorporacion de la tupla i-ésima al vector
		numCarFrecs.push_back(nuevoCf);
	}
	
	// Muestreo de las tuplas introducidad por el usuario
	for (int i = 0; i < int(numCarFrecs.size()); i++){
		cout << "El caracter de la tupla " << i << " es " << numCarFrecs[i].getCaracter() << endl;
		cout << "La frecuencia de la tupla " << i << " es " << numCarFrecs[i].getFreecuencia() << endl;
	}
	
	// Fin de la ejecucion del programa
	return 0;
}