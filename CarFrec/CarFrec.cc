/*
 * ***********************************************
 * Asignatura : Algoritmia basica ****************
 * Autores : Rubén Rodríguez Esteban 737215 ******
 *           José María Vallejo Puyal 720044 *****
 * Fecha : 13-3-19 *******************************
 * ***********************************************
 */
 
/*
 * Fichero de implementacion del modulo carFrec
 */
 
#include "CarFrec.h"

/*
 * Pre: <<c>> es un caracter y <<f>> es el total de veces que 
 *      aparece escrito en un fichero, es decir, su frecuencia:
 * Post: Devuelve una tupla <<carFrec>> donde el valor del caracter
 *       es igual a <<c>> y el valor de su frecuencia es igual a <<f>>
 */
carFrec::carFrec(char c, int f){
	caracter = c;
	frecuencia = f;
}

/*
 * Pre: ---
 * Post: Ha devuelto el valor del caracter 
 */
char carFrec::getCaracter(){
	return caracter;
}      

/*
 * Pre: ---
 * Post: Ha devuelto el valor de la frecuencia  
 */ 
int carFrec::getFreecuencia(){
	return frecuencia;
}      