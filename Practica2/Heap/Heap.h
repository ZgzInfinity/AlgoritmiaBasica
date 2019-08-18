/*
 * ***********************************************
 * Asignatura : Algoritmia basica ****************
 * Autores : Rubén Rodríguez Esteban 737215 ******
 *           José María Vallejo Puyal 720044 *****
 * Fecha : 14-8-19 *******************************
 * ***********************************************
 */

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <cstring>
#include "../Nodo/Nodo.h"

/*
 * Fichero de interfaz del modulo Heap
 */

using namespace std;


const int MAX_NUM_NODOS = 100000;


// Predeclaracion publica del monticulo generico de datos
template <typename T> struct Heap;


/*
 * Predeclaracion de las funciones que trabajan con el TAD monticulo
 * La precondicion y postcondicion de las funciones siguientes se encuentra explicada
 * mas abajo
 */

template <typename T> void crearVacio(Heap<T>& h);
template <typename T> int numElementos(Heap<T>& h);
template <typename T> void anyadir(Heap<T>& h, T* n);
template <typename T> void eliminarMin(Heap<T>& h);
template <typename T> T* min(Heap<T>& h);
template <typename T> bool esVacio(Heap<T>& h);
template <typename T> T* consultar(Heap<T>& h, const int i);
template <typename T> void permutar (T* uno, T* otro);


template <typename T>
struct Heap {
	private:
		// Estructura interna del tipo de dato Heap
		
		// Vector de punteros a datos genericos
		T * datos[MAX_NUM_NODOS];
		// total de nodos del monticulo
		int num;
	
	/*
	 * Metodos que trabajan con el TAD Heap
	 */

	public:
		/*
		 * Pre: ---
		 * Post: Ha creado un monticulo de elementos vacio
		 */
		friend void crearVacio<T>(Heap<T>& h);


		/*
		 * Pre: ---
		 * Post: Ha devuelto el total de elementos del monticulo
		 */
		 friend int numElementos<T>(Heap<T>& h);


		/*
		 * Pre: <<h>> es un monticulo de elementos y <<n>> es un nuevo elemento
		 *      que se desea insertar
		 * Post: Ha insertado el elemento <<n>> en el monticulo <<h>>
		 */
		 friend void anyadir<T>(Heap<T>& h, T* n);


		/*
		 * Pre: ---
		 * Post: Ha eliminado el primer elemento del monticulo <<h>>
		 */
		 friend void eliminarMin<T>(Heap<T>& h);


		/*
		 * Pre: ---
		 * Post: Ha devuelto el primer elemento del monticulo <<h>>
		 */
		 friend T* min<T>(Heap<T>& h);


		/*
		 * Pre: ---
		 * Post: Ha devuelto <<true>> si y solo si el monticulo <<h>> es vacio.
		 *       En caso contrario devuelve <<false>>
		 */
		 friend bool esVacio<T>(Heap<T>& h);

};


#endif
