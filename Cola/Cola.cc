/*
 * ***********************************************
 * Asignatura : Algoritmia basica ****************
 * Autores : Rubén Rodríguez Esteban 737215 ******
 *           José María Vallejo Puyal 720044 *****
 * Fecha : 16-3-19 *******************************
 * ***********************************************
 */

#include <fstream>
#include "Cola.h"
#include "../CarFrec/CarFrec.cc"

/*
 * Fichero de implementacion del modulo Cola que trabaja 
 * con datos de tipo CarFrec/CarFrec/CarFrec
 */

using namespace std;


/*
 * Pre: <<h>> es una cola de tuplas <caracter, frecuencia>>
 * Post: Se han eliminado todas las tuplas <caracter, frecuencia> de <<h>> 
 *       de manera que ha quedado vacio o directamente se ha creado una cola vacia
 */
void crear(Cola& h){
	h.numCfrecs.clear();
}

/*
 * Pre: <<h>> es una cola de tuplas <caracter, frecuencia>
 * Post: Ha devuelto el numero de elementos de la cola <<h>>
 */
int numElementos(const Cola& h){
	return h.numCfrecs.size();
}


/*
 * Pre: A=X1 y B=X2
 * Post: A=X2 y B=X1
 */
void permutar (carFrec& uno, carFrec& otro){
	// Creacion de una tupla auxiliar vacia
	carFrec aux = carFrec();
	// Permutacion de tuplas
	aux = uno;
	uno = otro;
	otro = aux;
}


/*
 * Pre: <<h>> es una cola de tuplas de tipo <caracter, frecuencia> 
 *      y <<cF>> es la nueva tupla <caracter, frecuencia> que se desea incorporar
 *      a la cola
 * Post: Se ha incorporado a la cola <<h>> la nueva tupla <<cF>> 
 */
void insertarCarFrec(Cola& h, carFrec cF){
	h.numCfrecs.push_back(cF);
}


/*
 * Pre: <<h>> es una cola de tuplas <caracter, frecuencia> 
 *      e <<i>> es un entero positivo menor o igual que el total
 *      de elementos de la cola <<h>>
 * Post: Ha devuelto la tupla <caracter, frecuencia> de la cola <<h>> situada
 *      en la posicion <<i>>
 */
carFrec consultarCarFrec(Cola& h, int i){
	return h.numCfrecs.at(i);
}



/*
 * Pre: <<numCfrecs>> es un vector de datos de tipo "carFrec" que
 *      y <<c>> es un caracter concreto
 * Post: Si existe una tupla en el vector <<numCfrecs>> cuyo caracter es 
 *       igual al caracter <<c>> devuelve el indice de esa tupla en el vector.
 *       En caso contrario se ha limitado a devolver un numero negativo
 */
int encontrarCaracter(Cola& h, char& c){
	// control de deteccion de tupla deseada
	bool encontrado = false;
	// posicion del vector a analizar
	int indice = 0;
	
	int total = numElementos(h);
	
	// iterador para recorrer el vector
	while (!encontrado && indice < total){
		// tupla con caracter igual a <<c>> todavia no
		// encontrada
		if (consultarCarFrec(h, indice).getCaracter() == c){
			// El caracter de la tupla marcada por el iterador 
			// coincide con el caracter buscado 
			// se detiene la busqueda
			encontrado = true;
		}
		else {
			// El caracter de la tupla marcada por el iterador 
			// no coincide con el caracter buscado 
			// se prosigue la busqueda
			indice++;
		}
	}
	if (encontrado){
		// exito en la busqueda
		// retorno de la posicion en el vector
		return indice;
	}
	else {
		// fracaso en la busqueda
		// devuelve error
		return -1;
	}
}


/*
 * Pre: <<h>> es una cola de tuplas <caracter, frecuencia, <<prim>>
 *      marca la posicion de la primera tupla de la cola <<h>> y 
 *      <<ult>> marca la posicion de la ultima tupla de la cola <<h>>
 * Post: <<h>> es una permutacion de las tuplas <caracter, frecuencia> de manera
 *       que ahora estan ordenadas por orden decriente de frecuencias
 */
void quicksort (Cola& h, int prim, int ult){
	// declaracion de variables
	int medio, i, j, frecPivot;
	// calculo del punto medio del vector
	medio = (prim + ult) / 2;
	frecPivot = consultarCarFrec(h, medio).getFrecuencia();
	// separacion de los fragmentos a ordenar
	i = prim;
	j = ult;
	
	while (i <= j){
		// particion del vector de dos fragmentos
		while (consultarCarFrec(h, i).getFrecuencia() > frecPivot){
			// separacion de los caracteres con mayor frecuencia que la del pivote
			i++;
		}
		while (consultarCarFrec(h, j).getFrecuencia() < frecPivot){
			// separacion de los caracteres con menor frecuencia que la del pivote
			j--;
		}
		if (i <= j){
			// se cruzan los valores
			// permutar los valores del vector
			permutar(h.numCfrecs.at(i), h.numCfrecs.at(j));
			i++;
			j--;
		}
	}
	// llamada recursiva a la funcion para llevar a cabo de las 
	// restantes subparticiones del vector
	if (consultarCarFrec(h, prim).getFrecuencia() < consultarCarFrec(h, j).getFrecuencia()){
		quicksort(h, prim, j);
	}
	if (consultarCarFrec(h, i).getFrecuencia() < consultarCarFrec(h, ult).getFrecuencia()){
		quicksort(h, i, ult);
	}
}


/*
 * Pre: <<nombreFichero>> es un fichero de caracteres y <<numCfrecs>> es un vector vacio 
 *      que puede no tiene almacenado ningun dato de tipo calFrec
 * Post: Si la lectura del fichero de caracteres <<nombreFichero>> se ha efectuado correctamente
 *       ha guardado en las primeras componentes del vector <<numCfrecs>> el numero de veces 
 *       que aparece cada caracter distinto en el fichero junto con el propio caracter. 
 *       En caso contrario ha informado mediante un error por pantalla de la innacesibilidad 
 *       del fichero <<nombreFichero>>
 */
void frecuenciasPorCaracter(const char nombreFichero[], Cola& h){
	// Creacion del flujo de lectura
	ifstream f;
	// Asociacion del flujo al fichero 
	f.open(nombreFichero);
	if (f.is_open()){
		// Flujo asociado a fichero correctamente
		char c;
		// lectura del primer caracter del fichero
		c = f.get();
		int indice;
		while (!f.eof()){
			// mientras no acaba el fichero
			indice = encontrarCaracter(h, c);
			if (indice != -1){
				// el caracter ya existe
				// incremento de la frecuencia
				h.numCfrecs.at(indice).incrementaFrecuencia();
			}
			else {
				// el caracter nuevo leido no existe en el vector
				// hay que registralo
				carFrec nuevoCarFrec = carFrec(c, 1);
				// incorporar el nuevo caracter al vector
				insertarCarFrec(h, nuevoCarFrec);
			}
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