/*
 * ***********************************************
 * Asignatura : Algoritmia basica ****************
 * Autores : Rubén Rodríguez Esteban 737215 ******
 *           José María Vallejo Puyal 720044 *****
 * Fecha : 13-3-19 *******************************
 * ***********************************************
 */

#ifndef CarFrec_H
#define CarFrec_H

#include <iostream>
#include <cstring>
#include <iomanip>
#include <vector>
#include <iterator>
#include <fstream>

using namespace std;

/*
 * Fichero de interfaz del modulo carFrec
 */
 
class carFrec {
	// Estructura interna del tipo de dato carFrec
	private:
		char caracter;     // valor del caracter 
		int frecuencia;    // total de veces que aparece el caracter 
	public:
		
		/*
		 * Pre: <<c>> es un caracter y <<f>> es el total de veces que 
		 *      aparece escrito en un fichero, es decir, su frecuencia:
		 * Post: Devuelve una tupla <<carFrec>> donde el valor del caracter
		 *       es igual a <<c>> y el valor de su frecuencia es igual a <<f>>
		 */
		carFrec(char c, int f); 

		/*
		 * Pre: ---
		 * Post: Ha asginado el caracter <<c>> como valor del caracter
		 */
		 void asignarCaracter(char c);

		/*
		 * Pre: ---
		 * Post: Incrementado la frecuencia en una unidad
		 */
		 void incrementaFrecuencia();

		/*
		 * Pre: ---
		 * Post: Ha devuelto el valor del caracter 
		 */
		char getCaracter();       

		/*
		 * Pre: ---
		 * Post: Ha devuelto el valor de la frecuencia  
		 */ 
		int getFrecuencia();      
};

#endif