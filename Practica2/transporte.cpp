/*
 * ***********************************************
 * Asignatura : Algoritmia basica ****************
 * Autores : Rubén Rodríguez Esteban 737215 ******
 *           José María Vallejo Puyal 720044 *****
 * Fecha : 14-8-19 *******************************
 * ***********************************************
 */

#include <iostream>
#include <fstream>
#include <ctime>
#include "Nodo/Nodo.h"
#include "Heap/HeapImplementor.h"
#include "Pedido/Pedido.h"


using namespace std;


const int MAX_PARAMETROS = 3;
const int MAX_PEDIDOS = 22;


/*
 * Pre: <<ficheroPruebas>> es un fichero de texto que guarda datos de
 *      diferentes instancias del problema de transporte a resolver
 * Post: Si el fichero de texto <<ficheroPruebas>> ha podido abrirse
 *       sin problemas ha creado y dejado abierto un flujo de lectura 
 *       asocaido a ese fichero <<f>> y ha mostrado un mensaje 
 *       informando de la apertura correcta. En caso contrario ha mostrado 
 *       el error de apertura del fichero de texto <<ficheroPruebas>>
 */
void abrirFicheroPruebas(const char ficheroPruebas[], ifstream& f){
    // Apertura del flujo de lectura asociado al fichero
    f.open(ficheroPruebas);
    if (f.is_open()){
      // El fichero se ha abierto sin problemas
      cout << " El fichero de texto de pruebas " << ficheroPruebas
           << " se ha podido abrir correctamente" << endl;
    }
    else {
      // El fichero no ha podido abrirse
      cerr << " El fichero de texto de pruebas " << ficheroPruebas
           << " no se ha podido abrir correctamente" << endl;
    }
}



/*
 * Pre: <<ficheroResultados>> es un fichero vacio que destinado a
 *      guardar los resultados obtenidos de las diferentes instancias
 *      del problema de transporte a resolver
 * Post: Si el fichero de texto <<ficheroResultados>> ha podido abrirse
 *       sin problemas ha creado y dejado abierto un flujo de escritura 
 *       asociado a ese fichero <<f>> y ha mostrado un mensaje infornado 
 *       de la apertura correcta. En caso contrario ha mostrado el error 
 *       de apertura del fichero de texto <<ficheroResultados>>
 */
void abrirFicheroResultados(const char ficheroResultados[], ofstream& f){
    // Apertura del flujo de lectura asociado al fichero en modo append
    f.open(ficheroResultados);
    if (f.is_open()){
      // El fichero se ha abierto sin problemas
      cout << " El fichero de texto de resultados " << ficheroResultados
           << " se ha podido abrir correctamente" << endl;
    }
    else {
      // El fichero no ha podido abrirse
      cerr << " El fichero de texto de resultados " << ficheroResultados
           << " no se ha podido abrir correctamente" << endl;
    }
} 



/*
 * Pre: <<f>> es un flujo de escritura asociado al fichero de resultados que
 *      escribe a, razon de una por línea, el beneficio obtenido y el tiempo de
 *      ejecucion del bloque actual del problema, <<beneficio>> y <<segundos>>
 *      respectivamente
 * Post: Ha anyadido una nueva linea al final del fichero en la que el beneficio
 *       obtenido en el bloque actual del problema es <<beneficio>> y el tiempo
 *       de ejecucion es igual a <<segundos>>
 */
void escribirResultados(ofstream& f, const int beneficio, const float segundos){
  // Escritura del beneficio obtenido y del tiempo de ejecucion del bloque en una nueva linea
  f << beneficio << " " << segundos << endl;
}


/*
 * Pre: <<problemasHechos>> es el identificador de instancia de problema actual a resolver.
 *      <<capacidadTren>> es la capacidad del tren para el nuevo problema a encontrar soluciom
 *      <<estacionFinal>> es la estacion de fin de linea para el tren en el nuevo problema y
 *      1 <= <<estacionFinal>> 1<= 7; <<numPedidos>> es el numero de pedidos
 *      recolectados para el nuevo problema y 1 <= numPedidos <= 22.
 * Post: Ha mostrado por pantalla los datos del nuevo problema de transporte a resolver con
 *       el siguiente formato:
 * 
 *       NUEVA INSTANCIA DEL PROBLEMA 
 *      ============================== 
 *      Capacidad del tren: <<capacidadTren>> pasajeros
 *      Estacion de fin de linea: <<estacionFinal>> es la ultima estacion
 *      Pedidos recolectados: << numPedidos>> pedidos
 * 
 */
void presentarDatosProblema(const int problemasHechos, const int capacidadTren, const int estacionFinal, const int numPedidos){
	// Muestreo del menu con los datos de la nueva instancia de problema a resolver
	cout << "  " << problemasHechos + 1 << " INSTANCIA DEL PROBLEMA " << endl;
	cout << " ============================== " << endl;
	cout << " Capacidad del tren: " << capacidadTren << " pasajeros" << endl;
	cout << " Estacion de fin de linea: " << estacionFinal << " es la ultima estacion" << endl;
	cout << " Pedidos recolectados: " << numPedidos << " pedidos" << endl << endl;
}



/*
 * Pre: <<f>> es flujo de lectura asociado a un fichero de texto organizado
 *      en bloques: cada bloque es una instancia diferente del problema.
 *      La primera linea de cada bloque tiene tres enteros: la capacidad n
 *      del  tren, el numero m (maximo 7)  de  la  estacion  final  de  lınea
 *      y  el  numero  de pedidos total p (maximo 22). Las p lıneas siguientes
 *      representan los pedidos. Para cada pedido hay tres enteros: estacion de
 *      salida, estacion de llegada y numero de pasajeros.
 *      El bloque final de fichero esta compuesto por una unica lınea con los
 *      tres enteros igual a cero.
 * Post: Si la apertura del fichero se ha hecho sin problemas ha llevado
 *       a cabo la lectura de la primera linea de un bloque correspondiente a
 *       una instancia del problema y ha creado un nodo raiz del arbol con los
 *       datos iniciales del problema y ha devuelto <<true>>. En caso contario
 *       muestra un mensaje por pantalla que informa del final del fichero y
 *       devuelve <<false>>
 */
void crearInstanciaProblema(ifstream& f, int& capacidadTren, int& estacionFinal, int& numPedidos, const int problemasHechos, bool& fin){
	// Lectura de la capacidad del tren
	f >> capacidadTren;
	// Si se ha podido leer correctamente se lee el resto de los datos
	if (!f.eof()){
		// Lectura de la estacion de final de linea del tren y
		// del numero de pedidos solicitados
		f >> estacionFinal >> numPedidos;
		// Si no es la ultima linea se presenta la nueva instancia del problema
		if (capacidadTren == 0 && estacionFinal == 0 && numPedidos == 0){
			// Fin del fichero ya detectado
			fin = true;
		}
		else {
			// Presenta los datos de la nueva instancia del problema por pantalla
			presentarDatosProblema(problemasHechos, capacidadTren, estacionFinal, numPedidos);
			fin = false;
		}
	}
	else {
		// Fin de fichero de prubas
		cout << "El fichero de pruebas ya ha sido leido por completo" << endl;
		fin = true;
	}
}



/*
 * Pre: <<nodos>> es un monticulo que contiene el nodo raiz de la instancia 
 *      de problema a resolver; <<pedidos>> es una tabla de <<MAX_PEDIDOS>> 
 *      componentes con capacidad para guardar todos los pedidos recolectados
 *      del problema y <<nPedidos>> es el numero de pedidos recolectados del problema
 * Post: Ha devuelto el maximo ingreso que se puede obtener en la instancia del 
 *       problema empleando la estrategia de ramificacion y poda
 */
int ramificacionPodaMinimoCoste(Heap<Nodo>& nodos, Pedido pedidos[], int nPedidos){
	// Control de restriccion del problema
	bool puedenSubir = false;
	// Control para determinar si un nuevo nodo es prometedor
	bool esPrometedor = false;
	// Beneficio del nodo mas prometedor
	int mejorBeneficioCandidato = 0, siguientePedido = 0;
	// Valor minimo de la cota para poder podar
	double Uminima = 0;
	while (!esVacio(nodos)){
		// Mientras que en el monticulo queden nodos del arbol
		Nodo* hijoMalo = new Nodo;
		Nodo* hijoBueno = new Nodo;
		// Obtencion del Arbol con el minimo coste 
		hijoMalo = min(nodos);
		// Eliminacion el primer nodo del monticulo
		eliminarMin(nodos);
		// Duplicar el posible nodo hijo candidato con
		// toda la informacion 
		copiarInfoNodo(*hijoBueno, *hijoMalo, pedidos, nPedidos);
		// Siguiente pedido a procesar
		siguientePedido = pedidoProcesado(*hijoMalo);
		// Determinar si se pueden subir todos los pasajeros de la siguiente estacion
		puedenSubir = puedenSubirPasajeros(*hijoBueno, pedidos[siguientePedido], pedidos , nPedidos);
		if (puedenSubir){
			// Obtener los nuevos valores U(hijoBueno) y c(hijoBueno)
			esPrometedor = calcularCosteCota(mejorBeneficioCandidato, Uminima, *hijoBueno, nPedidos, pedidos);
			// Si el nodo es prometedor se apila en el monticulo
			if (esPrometedor){
				// Apilar en el monticulo porque el coste(hijoBueno) <= U(hijoBueno) y ademas
				// el coste no supera a la nueva cota
				anyadir(nodos, hijoBueno);
			}
		}
		else {
			// Se desecha el nodo poque coste(hijoBueno) > U(hijoBueno)
			delete hijoBueno;
		}
		// Obtener los nuevos valores U(hijoMalo) y coste(hijoMalo) y ver si es prometedor
		esPrometedor = calcularCosteCota(mejorBeneficioCandidato, Uminima, *hijoMalo, nPedidos, pedidos);
		if (esPrometedor){
			// Apilar en el monticulo porque el coste(hijoMalo) <= U(hijoMalo) y ademas
			// el coste no supera a la nueva cota
			anyadir(nodos, hijoMalo);
		}
		else {
			// Se desecha el nodo poque coste(hijoMalo) > U(hijoMalo)
			hijoMalo = nullptr;
		}
	}
	// Retorno del mejor beneficio obtenido
	return mejorBeneficioCandidato;
}



/*
 * Pre: <<pedidosOrdenados>> es un monticulo de pedidos vacio; <<numPedidoa>> almcaena el 
 *      numero de pedidos del problema y 0 <= <<numPedidos>> <= 22 y <<f>> es un flujo de
 *      lectura asociado a un fichero de texto con la estrctura sintactica del enunciado
 * Post: Ha copiado los <<numPedidos>> pedidos presentes en la instancia actual del problema
 *       en el monticulo <<pedidosOrdenados>> ordenandolos por prioridad de beneficio de 
 *      transito (precio de billete)
 */
void leerPedidosRecolectados(Heap<Pedido>& pedidosOrdenados, const int numPedidos, ifstream& f){
	// Datos del pedido a almacear
	int estacionSalida, estacionLlegada, numPasajeros;
	// Lectura de los pedidos recolectados
	for (int i = 0; i < numPedidos; i++){
		// lectura del i-ésimo pedido
		f >> estacionSalida >> estacionLlegada >> numPasajeros;
		// Creacion del i-esimo pedido con los datos leidos
		Pedido *p = new Pedido;
		crearPedido(p, estacionSalida, estacionLlegada, numPasajeros);
		// Guardar el i-esimo pedido en el monticulo
		anyadir(pedidosOrdenados, p);
	}
}



/*
 * Pre: <<pedidosOrdenados>> es un monticulo de pedidos vacio que almcaena el 
 *      numero de pedidos del problema y <<pedidos>> es una tabla vacia 
 *      de MAX_PEDIDOS componentes con capacidad para almacenar todos los 
 *      pedidos presentes en el monticulo
 * Post: Ha vaciado los pedidos del monticulo <<pedidosOrdenados>> y los
 *       copiado en la tabla <<pedidos>> por orden de beneficio de 
 *       transito (precio de billete)
 */
void copiarPedidos(Heap<Pedido>& pedidosOrdenados, Pedido pedidos[]){
	// Numero de elementos del monticulo de pedidos
	int dimInicial = numElementos(pedidosOrdenados);
	// Para cada uno de los elementos del monticulo
	for (int i = 0; i < dimInicial; i++){
		// Obtencion del primer pedido
		Pedido* pedidoMinimo = min(pedidosOrdenados);
		// Eliminar primer elemento del monticulo
		eliminarMin(pedidosOrdenados);
		// Incorporar el pedido al vector de pedidos
		pedidos[i] = *pedidoMinimo;
	}
}



/*
 * Pre: Existe un fichero de nombre <<pruebas.txt>> que cuenta con el tipo
 *      de sintaxis mencionado en el guion de la practica que almacena un
 *      total de 8000 instancias del problema de la empresa uzbeka a resolver
 * Post: Ha creado un fichero de texto de nombre <<resultados.txt>> destinado
 *       a almacenar las soluciones encontradas. Ha resuelto cada uno de 
 *       los 8000 escenarios contenidos en el fichero de nombre <<pruebas.txt>> 
 *       obteniendo para cada uno el maximo beneficio que puede conseguir la 
 *       empresa uzbeka empleando la estrategia de ramificacion y poda. Para 
 *       cada uno de los 8000 escenenarios ha escrito en el fichero de nombre
 *       <<resultados.txt>>, a razon de uno por linea el maximo beneficio 
 *       obtenido y el tiempo de ejecucion invertido en segundos para encontrar 
 *       la solucion.
 */ 
int main(int argc, char **argv) {
	// Comprobacion del numero de parametros
	if (argc != MAX_PARAMETROS){
		// Numero de parametros incorrectos
		cerr << " Invocar como:" << endl;
		cerr << " transporte <pruebas.txt> <resultados.txt>" << endl;
		cerr << " <pruebas.txt>: fichero de texto que incluye datos "
			 << " de diferentes instancias del problema" << endl;
		cerr << " <resultados.txt>: fichero de texto que guarda los resultados" << endl;
		// Retorno de error de ejecucion
		return -1;
	}
	else {
		// El numero de parametros es correcto
		// Apertura del fichero de texto con las pruebas
		ifstream f1;
		abrirFicheroPruebas(argv[1], f1);
		// Apertura del fichero de texto con los resultados
		ofstream f2;
		abrirFicheroResultados(argv[2], f2);
		
		// Datos de las instancias de llos problemas a resolver
		int capacidadTren, estacionFinal, numPedidos;
		
		// Nodo raiz del problema
		Nodo a;
		
		// Control de final de lectura de fichero de pruebas
		bool fin;
		
		// Vector de los pedidos de una instancia del problema
		Pedido pedidos[MAX_PEDIDOS];
		
		// Monticulo de los pedidos de la instancia del problema
		
		// Numero de problemas resueltos
		int problemasHechos = 0;
		int beneficioNeto = 0;
		float segundos = 0;
		
		// Creacion de una instancia del problema
		crearInstanciaProblema(f1, capacidadTren, estacionFinal, numPedidos, problemasHechos, fin);
				
		while (!fin){
			// Comrpobar si hay pedidos 
			if (numPedidos > 0){
				// Vaciar el monticulo de nodos
				Heap<Nodo> nodos;
				crearVacio(nodos);
				
				// Vaciar el monticulo de pedidos
				Heap<Pedido> pedidosOrdenados;
				crearVacio(pedidosOrdenados);
				
				// Quedan instancias del problema pendientes de resolver
				crearNodo(a, capacidadTren, estacionFinal, numPedidos);
				
				// Anyadir nodo raiz al monticulo
				anyadir(nodos, &a);
				
				// Lectura de los pedidos del fichero
				leerPedidosRecolectados(pedidosOrdenados, numPedidos, f1);
				
				// Copia de los pedidos por orden 
				copiarPedidos(pedidosOrdenados, pedidos);
				
				// Toma del tiempo actual
				clock_t tiempoInicial = clock();
				
				// Resolucion de la instancia del problema actual
				// empleando la tecnica de ramificacion y poda
				beneficioNeto = ramificacionPodaMinimoCoste(nodos, pedidos, numPedidos);
				
				// Toma del tiempo actual
				clock_t tiempoFinal = clock();
				// Calculo del tiempo de procesador destinado a la ejecucion del problema
				segundos = float (tiempoFinal - tiempoInicial) / CLOCKS_PER_SEC;
			}
			
			if (!fin){
				// Escritura los resultados obtenidos en el fichero de resultados
				// si no ha concluido el fichero 
				escribirResultados(f2, beneficioNeto, segundos);
				// Muestra por pantalla los resultados del problema
				cout << " Beneficio obtenido de: " << beneficioNeto << endl;
				cout << " Tiempo de CPU invertido: " << segundos << endl << endl;
			}
			
			// Incremento del numero de problemas resueltos
			problemasHechos++;
		
			// Lectura de una nueva instancia del problema
			crearInstanciaProblema(f1, capacidadTren, estacionFinal, numPedidos, problemasHechos,fin);
			
			// Iniciar el tiempo y el beneficio para la nueva instancia del problema
			beneficioNeto = 0;
			segundos = 0;
		}
		// Fichero de pruebas concluido
		// Cierre de los flujos asociados a los ficheros de pruebas y resultados
		f1.close();
		f2.close();
		
	}
	
	// Fin de ejecucion del programa
	return 0;
}
