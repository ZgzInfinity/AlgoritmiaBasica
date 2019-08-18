/*
 * ***********************************************
 * Asignatura : Algoritmia basica ****************
 * Autores : Rubén Rodríguez Esteban 737215 ******
 *           José María Vallejo Puyal 720044 *****
 * Fecha : 14-8-19 *******************************
 * ***********************************************
 */

/*
 * Fichero de implementacion Pedido.cc del modulo Pedido
 */

#include "Pedido.h"


/*
 * Pre: ---
 * Post: Devuelve un dato que representa un Pedido con una estacion de salida
 *       igual a <<estacionSalida>>, una estacion de llegada igual a
 *       <<estacionLlegada>> y un numero de pasajeros igual a <<numPasajeros>>
 */
void crearPedido(Pedido* p, const int estacionSalida, const int estacionLlegada, const int numPasajeros){
  p->estacionSalida = estacionSalida;
  p->estacionLlegada = estacionLlegada;
  p->numPasajeros = numPasajeros;
  p->beneficioTransito = (estacionLlegada - estacionSalida) * numPasajeros;
}



/*
 * Pre: ---
 * Post: Ha asignado como identificador de la estacion de salida del
 *       pedido <<p>> el valor <<estacionSalida>>
 */
void estacionSalida(Pedido p, const int estacionSalida){
   p.estacionSalida = estacionSalida;
}


/*
 * Pre: ---
 * Post: Ha asignado como identificador de la estacion de llegada del
 *       pedido <<p>> el valor <<estacionSalida>>
 */
void estacionLlegada(Pedido p, const int estacionLlegada){
   p.estacionLlegada = estacionLlegada;
}


/*
 * Pre: ---
 * Post: Ha asignado como numero de pasajeros del
 *       pedido <<p>> el valor <<estacionSalida>>
 */
void numPasajeros(Pedido p, const int numPasajeros){
   p.numPasajeros = numPasajeros;
}


/*
 * Pre: ---
 * Post: Devuelve el identificador de la estacion de salida
 */
int estacionSalida(const Pedido& p){
   return p.estacionSalida;
}


/*
 * Pre: ---
 * Post: Devuelve el identificador de la estacion de llegada
 */
int estacionLlegada(const Pedido& p){
   return p.estacionLlegada;
}


/*
 * Pre: ---
 * Post: Devuelve el numero de pasajeros del pedido
 */
int numPasajeros(const Pedido& p){
   return p.numPasajeros;
}


/*
 * Pre: ---
 * Post: Devuelve el precio del billete
 */
int beneficioTransito(const Pedido& p){
   return p.beneficioTransito;
}


/*
 * Sobrecarga de los operadores para trabajar con  objetos de tipo Pedido
 */


/*
 * Pre: ---
 * Post: Ha devuelto <<true>> si y solo si <<p1>> es 
 *       igual que <<p2>>. En caso contrario ha devuelto <<false>>
 */
bool operator <(Pedido& p1, Pedido& p2){
	// Casteo del numerador como double para permitir posible division por cero
	return (double)p1.beneficioTransito /p1. numPasajeros > (double)p2.beneficioTransito / p2.numPasajeros;
}



/*
 * Pre: ---
 * Post: Ha devuelto <<true>> si y solo si <<p1>> es 
 *       mayor que <<p2>>. En caso contrario ha devuelto <<false>>
 */
bool operator >(Pedido& p1, Pedido& p2){
	// Casteo del numerador como double para permitir posible division por cero
	return (double) p1.beneficioTransito / p1.numPasajeros < (double)p2.beneficioTransito / p2.numPasajeros;
}



/*
 * Pre: ---
 * * Post: Ha devuelto <<true>> si y solo si <<p1>> es 
 *         mayor o igual que <<p2>>. En caso contrario ha devuelto <<false>>
 */
bool operator >=(Pedido& p1, Pedido& p2){
	// Casteo del numerador como double para permitir posible division por cero
	return (double)p1.beneficioTransito / p1.numPasajeros <= (double)p2.beneficioTransito / p2.numPasajeros;
}



/*
 * Pre: ---
 * Post: Ha devuelto <<true>> si y solo si <<p1>> es 
 *       menor o igual que <<p2>>. En caso contrario ha devuelto <<false>>
 */
bool operator <=(Pedido& p1, Pedido& p2){
	// Casteo del numerador como double para permitir posible division por cero
	return (double)p1.beneficioTransito / p1.numPasajeros >= (double)p2.beneficioTransito / p2.numPasajeros;
}