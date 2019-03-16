/*
 * ***********************************************
 * Asignatura : Algoritmia basica ****************
 * Autores : Rubén Rodríguez Esteban 737215 ******
 *           José María Vallejo Puyal 720044 *****
 * Fecha : 16-3-19 *******************************
 * ***********************************************
 */


#ifndef COLA_H
#define COLA_H

#include <iterator>
#include <iostream>
#include <cstring>
#include "../CarFrec/CarFrec.h"

/*
 * Fichero de interfaz del modulo Cola
 */

using namespace std;


struct Cola {
	private:
		// vector de tuplas <caracter, frecuencia> ordenado por frecuencias
		vector <carFrec> numCfrecs;
	public:
	
	/*
	 * Pre: <<h>> es un cola de tuplas <caracter, frecuencia>>
	 * Post: Se han eliminado todas las tuplas <caracter, frecuencia> de <<h>> 
	 *       de manera que ha quedado vacio
	 */
	 friend void crear(Cola& h);


	/*
	 * Pre: <<h>> es un cola de tuplas <caracter, frecuencia>>
	 * Post: Ha devuelto el numero de elementos del cola <<h>>
	 */
	 friend int numElementos(const Cola& h);


	/*
	 * Pre: A=X1 y B=X2
	 * Post: A=X2 y B=X1
	 */
	friend void permutar (carFrec& uno, carFrec& otro);


	/*
	 * Pre: <<h>> es un cola de tuplas de tipo <caracter, frecuencia> 
	 *      y <<cF>> es la nueva tupla <caracter, frecuencia> que se desea incorporar
	 *      al cola
	 * Post: Se puede ha incorporado al cola <<h>> la nueva tupla <<cF>> 
	 */
	 friend void insertarCarFrec(Cola& h, carFrec cF);


	/*
	 * Pre: <<h>> es una cola de tuplas <caracter, frecuencia> 
	 *      e <<i>> es un entero positivo menor o igual que el total
	 *      de elementos de la cola <<h>>
	 * Post: Ha devuelto la tupla <caracter, frecuencia> de la cola <<h>> situada
	 *       en la posicion <<i>>
	 */
	 friend carFrec consultarCarFrec(Cola& h, int i);


	/*
	 * Pre: <<numCfrecs>> es un vector de datos de tipo "carFrec" que
	 *      y <<c>> es un caracter concreto
	 * Post: Si existe una tupla en el vector <<numCfrecs>> cuyo caracter es 
	 *       igual al caracter <<c>> devuelve el indice de esa tupla en el vector.
	 *       En caso contrario se ha limitado a devolver un numero negativo
	 */
	 friend int encontrarCaracter(Cola& h, char& c);

	/*
	 * Pre: <<h>> es una cola de tuplas <caracter, frecuencia, <<prim>>
	 *      marca la posicion de la primera tupla de la cola <<h>> y 
	 *      <<ult>> marca la posicion de la ultima tupla de la cola <<h>>
	 * Post: <<h>> es una permutacion de las tuplas <caracter, frecuencia> de manera
	 *       que ahora estan ordenadas por orden decriente de frecuencias
	 */
	  friend void quicksort(Cola& h, int prim, int ult);


	/*
	 * Pre: <<nombreFichero>> es un fichero de caracteres y <<numCfrecs>> es un vector vacio 
	 *      que puede no tiene almacenado ningun dato de tipo calFrec
	 * Post: Si la lectura del fichero de caracteres <<nombreFichero>> se ha efectuado correctamente
	 *       ha guardado en las primeras componentes del vector <<numCfrecs>> el numero de veces 
	 *       que aparece cada caracter distinto en el fichero junto con el propio caracter. 
	 *       En caso contrario ha informado mediante un error por pantalla de la innacesibilidad 
	 *       del fichero <<nombreFichero>>
	 */
	 friend void frecuenciasPorCaracter(const char nombreFichero[], Cola& c);
};

#endif