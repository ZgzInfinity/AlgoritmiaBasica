#include <iostream>
#include <cstring>
#include "Huffman.h"
#include "CarFrec.h"
#include "ArbolTrie.h"
#include "Heap.h"


const int UMBRAL = 51;
const int MAX_FICHERO_NOMBRE = 100;

/*
 * Pre: <<nombreFichero>> es un fichero de caracteres y <<numCfrecs>> es un vector vacio
 *      que puede no tiene almacenado ningun dato de tipo calFrec
 * Post: Si la lectura del fichero de caracteres <<nombreFichero>> se ha efectuado correctamente
 *       ha guardado en las primeras componentes del vector <<numCfrecs>> el numero de veces
 *       que aparece cada caracter distinto en el fichero junto con el propio caracter.
 *       En caso contrario ha informado mediante un error por pantalla de la innacesibilidad
 *       del fichero <<nombreFichero>>
 */
void frecuenciasPorCaracter(const char nombreFichero[], int frecsPorChar[]){
	int codAscii;
	// Creacion del flujo de lectura
	ifstream f;
	// Asociacion del flujo al fichero
	f.open(nombreFichero);
	if (f.is_open()){
		// Flujo asociado a fichero correctamente
		char c;
		// lectura del primer caracter del fichero
		c = f.get();
		while (!f.eof()){
			// mientras no acaba el fichero
			codAscii = int(c);
			frecsPorChar[codAscii]++;
			// lectura de un nuevo caracter del fichero
			c = f.get();
		}
		// Cierre del flujo de lectura asociado al fichero
		f.close();
	}
	else {
		// Error en la asociacion del flujo al fichero
		cerr << "El fichero de " << nombreFichero << " no se ha podido leer " << endl;
	}
}


int main(){
	
	const char fichero[] = "frecuencias.txt";
	int frecsPorChar[MAX_CARACTERES];
	
	for (int i = 0; i < MAX_CARACTERES; i++){
		frecsPorChar[i] = 0;
	}
	
	frecuenciasPorCaracter(fichero, frecsPorChar);
	
	// Mostrar caracteres leidos
	for (int i = 0; i < MAX_CARACTERES; i++){
		if (frecsPorChar[i] > 0){
			cout << char(i) << frecsPorChar[i] << endl;
		}
	}
	
	carFrec ca;
	ArbolTrie a;
	Heap h;
	crearVacio(h);
	
	cout << "El monticulo tiene " << numElementos(h) << " elementos" << endl;
	
	rellenar(h, frecsPorChar);
	
	int total = numElementos(h);
	cout << "El monticulo tiene " << total << " elementos" << endl;
	
	
	for (int i = 1; i <= total; i++){
		a = consultar(h, i);
		ca = obtenerCarFrec(a);
		cout << i << " C: " << ca.getCaracter() << " F: " << ca.getFrecuencia() << endl;
	}
	
	ArbolTrie huff;
	Huffman hF;
	generaHuffman(h, huff, hF);
	
	string codigos[MAX_CARACTERES];
	
	for(int k = 0; k < 256 ; k++){
		codigos[k]= "-";
	}
	
	codificador(codigos, huff, "", hF);
	
	for(int j = 0; j < 256; j++){
		if(codigos[j]!= "-")
		cout << "El codigo de " << (char)j << " es: " << codigos[j] << endl;
	}


	
	cout << "Fin del programa " << endl;
	
	return 0;
	
}
