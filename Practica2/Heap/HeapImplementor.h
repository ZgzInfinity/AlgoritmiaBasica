/*
 * ***********************************************
 * Asignatura : Algoritmia basica ****************
 * Autores : Rubén Rodríguez Esteban 737215 ******
 *           José María Vallejo Puyal 720044 *****
 * Fecha : 29-3-19 *******************************
 * ***********************************************
 */


 /*
  * Fichero de implementacion HeapImplementor.h del modulo HeapImplementor
  * Contiene la implementacion de las funciones genericas que trabajan con el
  * TAD Heap definidas en el fichero de interfaz
  */


#include "Heap.h"


/*
 * Pre: ---
 * Post: Ha creado un monticulo de elementos vacio
 */
template <typename T>
void crearVacio(Heap<T>& h){
    h.num = 0;
}


/*
 * Pre: ---
 * Post: Ha devuelto el total de elementos del monticulo
 */
template <typename T>
int numElementos(Heap<T>& h){
	return h.num;
}


/*
 * Pre: <<h>> es un monticulo de elementos y <<n>> es un nuevo elemento
 *      que se desea insertar
 * Post: Ha insertado el elemento <<n>> en el monticulo de elementos <<h>>
 */
template <typename T>
void anyadir(Heap<T>& h, T* n){
	// Guarda el nodo en la ultima posicion del monticulo
	h.datos[h.num] = n;
	// Incremento del numero de elementos del monticulo
	int i = h.num++;
	// Determina si el nuevo elemento hijo es mas prioritario que el padre
	bool debeSubir = *h.datos[i] < *h.datos[(i - 1) / 2];
	while (i > 0 && debeSubir){
		// Permutacion del nodo hijo con el padre
		T * aux = h.datos[i];
		h.datos[i] = h.datos[(i - 1)/ 2];
		h.datos[(i - 1) / 2] = aux;
		
		// Acotacion del valor de i
		i = (i - 1) / 2;
		
		// Comprobar si el nuevo elemento hijo es mas prioritario
		// que su nuevo padre
		debeSubir = *h.datos[i] < *h.datos[(i - 1) / 2];
	}
}


/*
 * Pre: ---
 * Post: Ha eliminado el primer elemento del monticulo <<h>>
 */
template <typename T>
void eliminarMin(Heap<T>& h){
	
	// Decremento del numero de elementos del monticulo
	h.num--;
	// Posicionar el ultimo elemento en la primera posicion
	h.datos[0] = h.datos[h.num];
	// Indice del nodo padre
	int i = 0, j = 1;
	// Control para determinar cuando se debe dejar de
	// hundir el elemento en el monticulo
	bool dejarDeHundir = false;
	while ((2 * i ) + 1 <=h.num && !dejarDeHundir) {
		// Calculo del indice del nodo padre del nodo i
		j = (2 * i) + 1;
		// Comprobar si el elemento j es mas pequeño que su hijo izquierdo
		if ((j + 1) <= h.num && *h.datos[j] > *h.datos[j + 1]){
			// Indice del hijo derecho
			j++;
		}
		// Comprobar si es menor que el hijo derecho
		if(*h.datos[j] >= *h.datos[i]){
			// Se debe salir del bucle porque ya es necesario mirar mas hijos
			dejarDeHundir = true;
		}
		// Control de intercambio de padre e hijo
		if (!dejarDeHundir){
			// Hay que hundir porque el padre es mayor que el hijo
			T * aux = h.datos[j];
			h.datos[j] = h.datos[i];
			h.datos[i] = aux;
		}
		// Reposicionar el indice del padre en la nueva poscion
		i = j;
	}
}


/*
 * Pre: ---
 * Post: Ha devuelto el primer elemento del monticulo <<h>>
 */
template <typename T>
T* min(Heap<T>& h){
    return h.datos[0];
}


/*
 * Pre: ---
 * Post: Ha devuelto <<true>> si y solo si el monticulo <<h>> es vacio.
 *       En caso contrario devuelve <<false>>
 */
template <typename T>
bool esVacio(Heap<T>& h){
    return h.num == 0;
}


