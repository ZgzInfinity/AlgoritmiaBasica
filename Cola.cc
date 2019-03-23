

#include <fstream>
#include "Cola.h"
#include "ArbolTrie.h"

using namespace std;


/*
 * Pre: <<h>> es una cola de tuplas <caracter, frecuencia>>
 * Post: Se han eliminado todas las tuplas <caracter, frecuencia> de <<h>>
 *       de manera que ha quedado vacio o directamente se ha creado una cola vacia
 */
void crear(Cola& h){
	h.arboles.clear();
}

/*
 * Pre: <<h>> es una cola de tuplas <caracter, frecuencia>
 * Post: Ha devuelto el numero de elementos de la cola <<h>>
 */
int numElementos(const Cola& h){
	return h.arboles.size();
}


/*
 * Pre: A=X1 y B=X2
 * Post: A=X2 y B=X1
 */
void permutar (ArbolTrie& uno, ArbolTrie& otro){
	ArbolTrie aux = uno;
	uno = otro;
	otro = aux;
}

ArbolTrie primero(const Cola& h){
	return h.arboles.front();
}

/*
 * Pre: <<h>> es una cola de tuplas de tipo <caracter, frecuencia>
 *      y <<cF>> es la nueva tupla <caracter, frecuencia> que se desea incorporar
 *      a la cola
 * Post: Se ha incorporado a la cola <<h>> la nueva tupla <<cF>>
 */
void insertarArbol(Cola& h, ArbolTrie& a){
	h.arboles.push_back(a);
}


/*
 * Pre: <<h>> es una cola de tuplas <caracter, frecuencia>
 *      e <<i>> es un entero positivo menor o igual que el total
 *      de elementos de la cola <<h>>
 * Post: Ha devuelto la tupla <caracter, frecuencia> de la cola <<h>> situada
 *      en la posicion <<i>>
 */
ArbolTrie consultarArbol(Cola& h, int i){
	return h.arboles.at(i);
}




/*
 * Pre: <<h>> es una cola de tuplas <caracter, frecuencia>
 *      e <<i>> es un entero positivo menor o igual que el total
 *      de elementos de la cola <<h>>
 * Post: Ha devuelto la tupla <caracter, frecuencia> de la cola <<h>> situada
 *       en la posicion <<i>>
 */
void eliminarPrimerArbol(Cola& h){
	h.arboles.erase(h.arboles.begin());
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
		ArbolTrie arbol = consultarArbol(h, indice);
		carFrec tupla = obtenerCarFrec(arbol);
		if (tupla.getCaracter() == c){
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

	carFrec tuplaI, tuplaJ;
	// calculo del punto medio del vector
	medio = (prim + ult) / 2;

	ArbolTrie arbol = consultarArbol(h, medio);
	carFrec tupla = obtenerCarFrec(arbol);

	frecPivot = tupla.getFrecuencia();
	// separacion de los fragmentos a ordenar
	i = prim;
	j = ult;

	while (i <= j){
		// particion del vector de dos fragmentos
		ArbolTrie arbolI = consultarArbol(h, i);
		tuplaI = obtenerCarFrec(arbolI);
		while (tuplaI.getFrecuencia() > frecPivot){
			// separacion de los caracteres con mayor frecuencia que la del pivote
			i++;
			arbolI = consultarArbol(h, i);
			tuplaI = obtenerCarFrec(arbolI);
		}

		ArbolTrie arbolJ = consultarArbol(h, j);
		tuplaJ = obtenerCarFrec(arbolJ);
		while (tuplaJ.getFrecuencia() < frecPivot){
			// separacion de los caracteres con menor frecuencia que la del pivote
			j--;
			arbolJ = consultarArbol(h, j);
			tuplaJ = obtenerCarFrec(arbolJ);
		}

		if (i <= j){
			// se cruzan los valores
			// permutar los valores del vector
			permutar(h.arboles.at(i), h.arboles.at(j));
			i++;
			j--;
		}
	}
	// llamada recursiva a la funcion para llevar a cabo de las
	// restantes subparticiones del vector
	ArbolTrie arbolPrim = consultarArbol(h, prim);
	carFrec tuplaPrim = obtenerCarFrec(arbolPrim);

	if (tuplaPrim.getFrecuencia() < tuplaJ.getFrecuencia()){
		quicksort(h, prim, j);
	}

	ArbolTrie arbolUlt = consultarArbol(h, ult);
	carFrec tuplaUlt = obtenerCarFrec(arbolUlt);

	if (tuplaI.getFrecuencia() < tuplaUlt.getFrecuencia()){
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
				ArbolTrie a = consultarArbol(h, indice);
				carFrec nC = obtenerCarFrec(a);
				nC.incrementaFrecuencia();
				asignarArbolCarFrec(a, nC);
				h.arboles.at(indice) = a;
			}
			else {
				// el caracter nuevo leido no existe en el vector
				// hay que registralo
				carFrec nuevoCarFrec = carFrec(c, 1);
				ArbolTrie nuevoArbol;
				crearArbol(nuevoArbol, nuevoCarFrec);

				// incorporar el nuevo caracter al vector
				insertarArbol(h, nuevoArbol);
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
