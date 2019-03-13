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

const int MAX_FICHERO_NOMBRE = 100;


/*
 * Pre: <<numCfrecs>> es un vector de datos de tipo "carFrec" que
 *      y <<c>> es un caracter concreto
 * Post: Si existe una tupla en el vector <<numCfrecs>> cuyo caracter es 
 *       igual al caracter <<c>> devuelve el indice de esa tupla en el vector.
 *       En caso contrario se ha limitado a devolver un numero negativo
 */
int encontrarCaracter( vector <carFrec>& numCfrecs, char& c){
	// control de deteccion de tupla deseada
	bool encontrado = false;
	// posicion del vector a analizar
	int indice = 0;
	// iterador para recorrer el vector
	vector<carFrec>::iterator it = numCfrecs.begin();
	while (!encontrado && it != numCfrecs.end()){
		// tupla con caracter igual a <<c>> todavia no
		// encontrada
		if ((*it).getCaracter() == c){
			// El caracter de la tupla marcada por el iterador 
			// coincide con el caracter buscado 
			// se detiene la busqueda
			encontrado = true;
		}
		else {
			// El caracter de la tupla marcada por el iterador 
			// no coincide con el caracter buscado 
			// se prosigue la busqueda
			it++;
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
 * Pre: <<nombreFichero>> es un fichero de caracteres y <<numCfrecs>> es un vector vacio 
 *      que puede no tiene almacenado ningun dato de tipo calFrec
 * Post: Si la lectura del fichero de caracteres <<nombreFichero>> se ha efectuado correctamente
 *       ha guardado en las primeras componentes del vector <<numCfrecs>> el numero de veces 
 *       que aparece cada caracter distinto en el fichero junto con el propio caracter. 
 *       En caso contrario ha informado mediante un error por pantalla de la innacesibilidad 
 *       del fichero <<nombreFichero>>
 */
void frecuenciasPorCaracter(const char nombreFichero[], vector <carFrec>& numCfrecs){
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
			indice = encontrarCaracter(numCfrecs, c);
			if (indice != -1){
				// el caracter ya existe
				// incremento de la frecuencia
				numCfrecs.at(indice).incrementaFrecuencia();
			}
			else {
				// el caracter nuevo leido no existe en el vector
				// hay que registralo
				carFrec nuevoCarFrec = carFrec(c, 1);
				// incorporar el nuevo caracter al vector
				numCfrecs.push_back(nuevoCarFrec);
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



/*
 * Programa que reune un conjunto de pruebas básicas
 * para poder probar el funcionamiento del TAD CarFrec
 */
 
int main(){
	// Variables para almacenar el caracter y la frecuencia
	char c;
	int f;
	int res;
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
	
	// Prubas del TAD carFrec
	for (int i = 0; i < int(numCarFrecs.size()); i++){
		cout << "El caracter de la tupla " << i << " es " << numCarFrecs[i].getCaracter() << endl;
		cout << "La frecuencia de la tupla " << i << " es " << numCarFrecs[i].getFrecuencia() << endl;
	}
	
	// pruebas de encontrarCaracter
	for (int i = 0; i < numCf; i++){
		cout << "Introduzca un caracter : " << flush;
		cin >> c;
		res = encontrarCaracter(numCarFrecs, c);
		if (res > -1){
			cout << "El caracter " << c << " encuentra en la posicion " << res << endl;
		} 
		else {
			cout << "EL caracter " << c << " no figura en el vector " << endl;
		}
	}
	
	// pruebas de frecuenciasPorCaracter
	// fichero ejemplo para comprobar la lectura 
	const char fichero[MAX_FICHERO_NOMBRE] = "frecuencias.txt";
	// limpieza del vector
	numCarFrecs.clear();
	
	cout << "Leyendo fichero " << fichero << endl;
	// rellenado con los nuevos caracteres
	frecuenciasPorCaracter(fichero, numCarFrecs);
	
	cout << "Fin del programa " << endl;
	
	// Fin de la ejecucion del programa
	return 0;
}