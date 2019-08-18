#include <iostream>
#include <cstring>
#include <ctime>
#include <cstdio>
#include "Huffman/Huffman.h"
#include "CarFrec/CarFrec.h"
#include "ArbolTrie/ArbolTrie.h"
#include "Heap/Heap.h"

const int PARAMETROS_INVOCACION = 3;

int main(int argc, char* argv[]){

	// Alarmas para medir el tiempo de ejecucion del programa
	clock_t t_ini, t_fin;

	// Segundos que va a tardar en ejecutarse el programa
  double secs = 0;

	// Comprobar el numero de parametros del programa
	if (argc != PARAMETROS_INVOCACION){
		// Numero de parametros incorrectos
		cerr << " Invocar como:" << endl;
	  cerr << " huf <-c|-d> <nombre de fichero>" << endl;
	  cerr << " <-c|-d>: modo de ejecucion: -c => compresion | -d => descompresion" << endl;
	  cerr << " <nombre de fichero>: fichero a comprimir o descomprimir" << endl;
	}
	else {
		// El numero de parametros es correcto
		string ficheroTrabajo = "Ficheros/";
		ficheroTrabajo += argv[2];

		// Control del flag de ejecucion
		if (strcmp(argv[1], "-c") == 0){
			// Modo compresion de fichero

			// Poner alarma inicial
			t_ini = clock();

			// Ejecutar la compresion del fichero pasado como parametro
			comprimir(ficheroTrabajo);

			// Poner la alarma final
			t_fin = clock();

			// Mostrar el tiempo de ejecucion del programa
			secs = (double)(t_fin - t_ini) / CLOCKS_PER_SEC;
		}
		else if (strcmp(argv[1], "-d") == 0){
			// Modo descompresion de fichero

			// Poner alarma inicial
			t_ini = clock();

			// Ejecutar la descompresion del fichero pasado como parametro
			descomprimir(ficheroTrabajo);

			// Poner la alarma final
			t_fin = clock();

			// Mostrar el tiempo de ejecucion del programa
			secs = (double)(t_fin - t_ini) / CLOCKS_PER_SEC;
		}
		else {
			// Flag desconocido
			cerr << "El flag es desconocido. Se esperaba -d o -c" << endl;
		}
		// Mostrar tiempo de ejecucion del programa en milisegundos
		printf("El fichero %s se ha tardado en descomprimir %.16g milisegundos \n",  argv[2], secs * 1000.0);
	}
	// Fin de la ejecucion del programa
  return 0;
}
