/*
 * ***********************************************
 * Asignatura : Algoritmia basica ****************
 * Autores : Rubén Rodríguez Esteban 737215 ******
 *           José María Vallejo Puyal 720044 *****
 * Fecha : 14-8-19 *******************************
 * ***********************************************
 */

/*
 * Fichero de interfaz Nodo.h del modulo Nodo
 */


#ifndef Nodo_H
#define Nodo_H

#include "../Pedido/Pedido.h"

const int MAX_ESTACIONES = 7;
const int BENEFICIO_MINIMO = 0;

struct Nodo {
	// Estructura interna del tipo de dato Nodo
	private:
		// ingreso estimado 
		int coste_estimado;
		// Total de pasajeros del tren
		int numPasajerosTren;
		// Vector con las estaciones disponibles de la linea
		int estaciones[MAX_ESTACIONES];
		// Numero de pedidos recolectados
		int pedidoProcesado;
		// Numero de estaciones del problema
		int nEstaciones;
		// Beneficio parcialmente acumulado
		int beneficioParcial;
		// Numero de pedidos del problema
		int nPedidos;
		
	// Coleccion de metodos para trabajar con el TAD Nodo
	public:
		/*
		 * Pre: ---
		 * Post: Devuelve un dato que representa un Nodo con un dato <<dato>>, un
		 *       subNodo izquierdo <<izq>> y un subNodo derecho <<der>>
		 */
		friend void crearNodo(Nodo& a, const int numPasajerosTren, const int nEstaciones, const int nPedidos);
		
		
		/*
		 * Pre: ---
		 * Post: Devuelve el coste_estimado hasta el momento
		 */
		friend int coste_estimado(const Nodo& a);
		
		
		/*
		 * Pre: ---
		 * Post: Devuelve el total de pasajeros del tren
		 */
		friend int numPasajerosTren(const Nodo& a);
		
		
		/*
		 * Pre: ---
		 * Post: Devuelve el total de estaciones
		 */
		friend int nEstaciones(const Nodo& a);
		
		
		/*
		 * Pre: ---
		 * Post: Devuelve el total de pedidos
		 */
		friend int nPedidos(const Nodo& a);
		
		
		/*
		 * Pre: ---
		 * Post: Devuelve el pedido procesado actualmente
		 */
		friend int pedidoProcesado(const Nodo& a);
		
		
		/*
		 * Pre: ---
		 * Post: Devuelve el beneficio parcial 
		 */
		friend int beneficioParcial(const Nodo& a);
		
		
		/*
		 * Pre: <<n>> es un nodo del problema que guarda en su tabla <<estaciones>>
		 *      el numero de pasajeros que quieren subirse en cada estacion del trayecto
		 *      y <<nuevasEstaciones>> es una tabla de <<MAX_ESTACIONES>> vacia
		 * Post: Ha copiado en la tabla <<nuevasEstaciones>> las componentes de la
		 *       tabla <<estaciones>> del nodo <<n>>
		 */
		friend void copiarEstaciones(Nodo& n, int nuevasEstaciones[]);
		
		
		/*
		 * Pre: <<n>> es un nodo actual del problema; <pedidos>> es una tabla que almacena
		 *      el total de pedidos del problema y <<nPedidos>> es el numero de pedidos del problema
		 * Post: Ha devuelto <<true>> si y solo si desde la estacion desde la estacion inicial
		 *       del problema almacenada en el nodo <<n>> hasta la estacion final tambien guardada
		 *       en el nodo <<n>> se pueden subir todos los pasajeros que estan las diferentes
		 *       estaciones comprendidas entre la inicial y la final. En caso contrario 
		 *       ha devuelto <<false>>
		 */
		friend bool puedenSubirPasajeros(Nodo& n, Pedido p, Pedido pedidos[], const int nPedidos);
		
		
		/*
		 * Pre: <<hijoIzquierdo>> es el nodo del monticulo con el minimo coste
		 * Post: Ha duplicado la informacion de <<hijoIzquierdo>> en el nodo <<hijoDerecho
		 *       y ha aumentado en una unidad el numero de pedidos de de hijoDerecho
		 */
		friend 	void copiarInfoNodo(Nodo& hijoBueno, Nodo& hijoMalo, Pedido pedidos[], const int nPedidos);
		
		
		/*
		 * Pre: La tabla <<estaciones>> es una tabla de <<MAX_ESTACIONES>> componentes
		 *      que almacena los pasajeros que desean subirse en cada estacion del trayecto;
		 *      <<inf>> y <<sup>> son dos indices de la tabla y 0 <= <<inf>> <= MAX_ESTACIONES 
		 *      y 0 <= <<sup>> <= MAX_ESTACIONES y <<inf>> <= <<sup>>
		 * Post: Ha devuelto el indice de la tabla <<estaciones>> correspondiente a la estacion
		 *       donde se han registrado mas pasajeros candidatos a subirse al tren
		 * 
		 */
		friend int estacionMasSolicitada(const int estaciones[], int inf, int sup);
		
		
		/*
		 * Pre: <<beneficio>> es la maxima ganacia obtenida en el problema; <<Uminima>> es el
		 *      valor de la funcion de poda actual; <<n>> es un nodo actual del problema;
		 *      <<nPedidos>> es el numero total de pedidos del problema y <<pedidos>> es una tabla
		 *      de <<MAX_PEDIDOS>> componentes que guarda todos los pedidos del problema
		 * Post: Ha devuelto <<true>> si y solo si el nodo <<n>> se va a meter en el monticulo de 
		 *       nodos como candidatoo ya que el coste(n) <= U(n) y ademas el coste(n) no supera 
		 *       a la nueva cota. En caso contrario ha devuelto <<false>>
		 */
		friend bool calcularCosteCota(int& beneficio, double& Uminima, Nodo& n, const int nPedidos, Pedido pedidos[]);
		
		
		/*
		 * Pre: <<n>> es un nodo de la instancia actual del problema; <<pedidos>> es
		 *      una tabla de <<MAX_PEDIDOS>> componentes que almacena todos los 
		 *      pedidos de la instancia del problema y <<nPedidos>> es el numero de 
		 *      pedidos del problema>>
		 * Post: Ha devuelto el coste estimado del nodo actual del problema <<n>>
		 */
		friend double calcularCosteEstimado(Nodo& n, Pedido pedidos[], const int nPedidos);
		
		
		/*
		 * Pre: <<n>> es un nodo de la instancia actual del problema; <<pedidos>> es
		 *      una tabla de <<MAX_PEDIDOS>> componentes que almacena todos los 
		 *      pedidos de la instancia del problema y <<nPedidos>> es el numero de 
		 *      pedidos del problema>>
		 * Post: Ha devuelto la nueva mejor cota del nodo
		 */
		friend int nuevaMejorCota(Nodo& n, Pedido pedidos[], const int nPedidos);
		
		
		/*
		 * Sobrecarga de los operadores para trabajar con  objetos de tipo Pedido
		 */
		 
		 
		/*
		 * Pre: ---
		 * Post: Ha devuelto <<true>> si y solo si <<n1>> es 
		 *       menor que <<n2>>. En caso contrario ha devuelto <<false>>
		 */
		friend bool operator <(const Nodo& n1, const Nodo& n2);
		
		
		/*
		 * Pre: ---
		 * Post: Ha devuelto <<true>> si y solo si <<n1>> es 
		 *       mayor que <<n2>>. En caso contrario ha devuelto <<false>>
		 */
		friend bool operator >(const Nodo& n1, const Nodo& n2);
		
		
		/*
		 * Pre: ---
		 * Post: Ha devuelto <<true>> si y solo si <<n1>> es 
		 *       mayor o igual que <<n2>>. En caso contrario ha devuelto <<false>>
		 */
		friend bool operator >=(const Nodo& n1, const Nodo& n2);
		
		
		/*
		 * Pre: ---
		 * Post: Ha devuelto <<true>> si y solo si <<n1>> es 
		 *       menor o igual que <<n2>>. En caso contrario ha devuelto <<false>>
		 */
		friend bool operator <=(const Nodo& n1, const Nodo& n2);
		
		
};

#endif
