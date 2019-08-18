/*
 * ***********************************************
 * Asignatura : Algoritmia basica ****************
 * Autores : Rubén Rodríguez Esteban 737215 ******
 *           José María Vallejo Puyal 720044 *****
 * Fecha : 14-8-19 *******************************
 * ***********************************************
 */

/*
 * Fichero de interfaz Pedido.h del modulo Pedido
 */

#ifndef PEDIDO_H
#define PEDIDO_H

#include <fstream>

using namespace std; 



struct Pedido {
	// Estructura interna del tipo de dato Pedido
	private:
		// Identificador de la estacion de salida del pedido
		int estacionSalida;
		// Identificador de la estacion de llegada del pedido
		int estacionLlegada;
		// NUmero de pasajeros recolectados
		int numPasajeros;
		// Beneficio del transito
		int beneficioTransito;
		
	// Coleccion de metodos auxiliares para trabajar con el TAD Pedido
	public:
		/*
		 * Pre: ---
		 * Post: Devuelve un dato que representa un Pedido con una estacion de salida
		 *       igual a <<estacionSalida>>, una estacion de llegada igual a
		 *       <<estacionLlegada>> y un numero de pasajeros igual a <<numPasajeros>>
		 */
		friend void crearPedido(Pedido* p, const int estacionSalida, const int estacionLlegada, const int numPasajeros);
		
		
		/*
		 * Pre: ---
		 * Post: Ha asignado como identificador de la estacion de salida del
		 *       pedido <<p>> el valor <<estacionSalida>>
		 */
		friend void estacionSalida(Pedido p, const int estacionSalida);
		
		
		/*
		 * Pre: ---
		 * Post: Ha asignado como identificador de la estacion de llegada del
		 *       pedido <<p>> el valor <<estacionLlegada>>
		 */
		friend void estacionLlegada(Pedido p, const int estacionLlegada);
		
		
		/*
		 * Pre: ---
		 * Post: Ha asignado como total de pasajeros recolectados del pedido <<p>> el
		  *      valor <<numPasajeros>>
		 */
		friend void estacionLlegada(Pedido p, const int numPasajeros);
		
		
		/*
		 * Pre: ---
		 * Post: Ha asignado como numero de pasajeros del
		 *       pedido <<p>> el valor <<estacionSalida>>
		 */
		friend void numPasajeros(Pedido p, const int numPasajeros);
		
		
		/*
		 * Pre: ---
		 * Post: Devuelve el identificador de la estacion de salida
		 */
		friend int estacionSalida(const Pedido& p);
		
		
		/*
		 * Pre: ---
		 * Post: Devuelve el identificador de la estacion de llegada
		 */
		friend int estacionLlegada(const Pedido& p);
		
		
		/*
		 * Pre: ---
		 * Post: Devuelve el numero de pasajeros recolectados del pedido
		 */
		friend int numPasajeros(const Pedido& p);
		
		
		/*
		 * Pre: ---
		 * Post: Devuelve el precio del billete
		 */
		friend int beneficioTransito(const Pedido& p);
		
		
		/*
		 * Sobrecarga de los operadores para trabajar con 
		 * objetos de tipo Pedido
		 */
		
		
		/*
		 * Pre: ---
		 * Post: Ha devuelto <<true>> si y solo si <<p1>> es 
		 *       menor que <<p2>>. En caso contrario ha devuelto <<false>>
		 */
		friend bool operator <(Pedido& p1, Pedido& p2);
		
		
		/*
		 * Pre: ---
		 * Post: Ha devuelto <<true>> si y solo si <<p1>> es 
		 *       mayor que <<p2>>. En caso contrario ha devuelto <<false>>
		 */
		friend bool operator >(Pedido& p1, Pedido& p2);
		
		
		/*
		 * Pre: ---
		 * Post: Ha devuelto <<true>> si y solo si <<p1>> es 
		 *       mayor o igual que <<p2>>. En caso contrario 
		 *      ha devuelto <<false>>
		 */
		friend bool operator >=(Pedido& p1, Pedido& p2);
		
		
		/*
		 * Pre: ---
		 * Post: Ha devuelto <<true>> si y solo si <<p1>> es 
		 *       menor o igual que <<p2>>. En caso contrario 
		 *      ha devuelto <<false>>
		 */
		friend bool operator <=(Pedido& p1, Pedido& p2);
		
};


#endif
