#include <iostream>
#include <cstring>
#include "Huffman.h"
#include "CarFrec.h"
#include "ArbolTrie.h"
#include "Heap.h"

// Constantes del programa
const int UMBRAL = 51;
const int MAX_FICHERO_NOMBRE = 100;


// /*
//  * Pre: ---
//  * Post: Ha asignado con valor cero todas las componentes del 
//  *       vector <<frecsPorChar>>
//  */
// void iniciarFrecuencias(int frecsPorChar[]){
// 	for (int i = 0; i < MAX_CARACTERES; i++){
// 		frecsPorChar[i] = 0;
// 	}
// }


// /*
//  * Pre: ---
//  * Post: Ha asignado con valor '-' todas las componentes del 
//  *       vector <<frecsPorChar>>
//  */
// void iniciarCodificaciones(string codigos[]){
// 	for(int k = 0; k < 256 ; k++){
// 		codigos[k]= "-";
// 	}
// }

// /*
//  * Pre: <<nombreFichero>> es un fichero de caracteres y <<frescPorChar>> es un vector de 
//  *      enteros vacio destinado a almacenar en cada una de sus componentes las veces que 
//  *      aparece cada caracter del fichero <<nombreFichero>>
//  * Post: Si la lectura del fichero de caracteres <<nombreFichero>> se ha efectuado correctamente
//  *       ha guardado en las componentes del vector <<frecsPorChar>> el numero de veces
//  *       que aparece cada caracter distinto en el fichero. En caso contrario ha informado
//  *       mediante un error por pantalla de la innacesibilidad del fichero <<nombreFichero>>
//  */
// void frecuenciasPorCaracter(const char nombreFichero[], int frecsPorChar[]){
// 	int codAscii;
// 	// Creacion del flujo de lectura
// 	ifstream f;
// 	// Asociacion del flujo al fichero
// 	f.open(nombreFichero);
// 	if (f.is_open()){
// 		// Flujo asociado a fichero correctamente
// 		char c;
// 		// lectura del primer caracter del fichero
// 		c = f.get();
// 		// mientras no acaba el fichero
// 		while (!f.eof()){
// 			// obtencion del codigo ascii del caracter leido
// 			codAscii = int(c);
// 			// incremento de la frecuencia correspondiente
// 			frecsPorChar[codAscii]++;
// 			// lectura de un nuevo caracter del fichero
// 			c = f.get();
// 		}
// 		// Cierre del flujo de lectura asociado al fichero
// 		f.close();
// 	}
// 	else {
// 		// Error en la asociacion del flujo al fichero
// 		cerr << "El fichero de " << nombreFichero << " no se ha podido leer " << endl;
// 	}
// }


/* int main(){
	
	// Fichero de caracteres que se va a proceder a descomprimir
	const char fichero[] = "frecuencias.txt";
	// vector de enteros que almacena la frecuencia de cada caracter
	int frecsPorChar[MAX_CARACTERES];
	
	// iniciar frecuencias iniciales
	iniciarFrecuencias(frecsPorChar);
	
	//calculo de frecuencias 
	frecuenciasPorCaracter(fichero, frecsPorChar);
	
	
	// Creacion del monticulo
	Heap h;
	crearVacio(h);
	
	// Muestreo del estado incial del monticulo
	cout << "El monticulo tiene " << numElementos(h) << " elementos" << endl;
	
	// Rellenado del monticulo 
	rellenar(h, frecsPorChar);
	
	// Muestreo del estado final del monticulo
	int total = numElementos(h);
	cout << "El monticulo tiene " << total << " elementos" << endl;
	
	
	ArbolTrie huff;
	Huffman hF;
	
	// Construccion del arbol de codificacion Huffman
	generaHuffman(h, huff, hF);
	
	// vector de codigos binarios para cada caracter
	string codigos[MAX_CARACTERES];
	
	// Iniciar codificaciones binarias
	iniciarCodificaciones(codigos);
	
	// Codificacion de caracteres con codigos binarios
	codificador(codigos, huff, "", hF);
	
	
	// Muestreo de los codigos binarios obtenidos
	for(int j = 0; j < 256; j++){
		if(codigos[j]!= "-")
		cout << "El codigo de " << (char)j << " es: " << codigos[j] << endl;
	}
	comprimir("frecuencias.txt", hF);

	
	cout << "Fin del programa " << endl;
	
	return 0;
	
}*/


int main(){ 

		Huffman h;
        comprimir("frecuencias.txt", h);

        return 0;
}
