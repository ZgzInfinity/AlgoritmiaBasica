#include <iostream>
#include "ArbolTrie.h"


using namespace std;

int main(){
	/*
	// Pruebas de calFrec
	carFrec cF1 = carFrec('a', 34);
	carFrec cF2 = carFrec('b', 58);
	carFrec cF3 = carFrec('c', 67);
	
	// Prubas de crear instancias de arboles
	ArbolTrie a1, a2, a3;
	crearArbol(a1, cF1);
	crearArbol(a2, cF2);
	crearArbol(a3, cF3);
	
	// Prueba de asignar frecuencia;
	asignarFrecuencia(a1, 54);
	
	// Pruebas para asignar arboles izuiqerdos y derechos
	asignarArbolDerecho(a1, a2);
	asignarArbolIzquierdo(a1, a3);
	
	// Prueba para obtener frecuencia del arbol
	int f1 = obtenerArbolFrecuencia(a1);
	
	// Pruebas de devolver arboles izquierdos y derechos
	ArbolTrie a4, a5;
	crearArbol(a4, cF1);
	crearArbol(a5, cF2);
	
	a4 = obtenerArbolIzquierdo(a1);
	a5 = obtenerArbolDerecho(a1);
	
	// Prueba para unir arboles
	ArbolTrie a6 = unir(a4, a5);
	
	// Pruebas de hojas
	if (esHoja(a2)){
		cout << "Es hoja" << endl;
	}
	else {
		cout << "No es hoja" << endl;
	}
	
	
	// Pruebas de hojas
	if (esHoja(a6)){
		cout << "Es hoja" << endl;
	}
	else {
		cout << "No es hoja" << endl;
	}
	
	// Pruebas para crear descifrar caracteres en un arbol
	*/
	
	carFrec cF5 = carFrec('X', 72);
	carFrec cF6 = carFrec('Y', 23);
	carFrec cF7 = carFrec('H', 45);
	carFrec cF8 = carFrec('Z', 89);
	
	// Construccion de un arbol de dos niveles 
	// Pruebas de las decodificaciones
	
	ArbolTrie a7, a8, a9, a10;
	
	crearArbol(a7, cF5);
	crearArbol(a8, cF6);
	crearArbol(a9, cF7);
	crearArbol(a10, cF8);
	
	ArbolTrie a11 = unir(a7, a8);
	ArbolTrie a12 = unir(a9, a10);
	
	ArbolTrie a13 = unir(a11, a12);
	
	char c1 = decodificarCaracter(a13, "00");
	// char c2 = decodificarCaracter(a13, "01");
	// char c3 = decodificarCaracter(a13, "10");
	// char c4 = decodificarCaracter(a13, "11");
	
	cout << c1 << endl;
	//cout << c2 << endl;
	//cout << c3 << endl;
	// cout << c4 << endl;
	
	cout << "Fin del programa de pruebas " << endl;
	return 0;
}