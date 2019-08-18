/*
 * ***********************************************
 * Asignatura : Algoritmia basica ****************
 * Autores : Rubén Rodríguez Esteban 737215 ******
 *           José María Vallejo Puyal 720044 *****
 * Fecha : 14-8-19 *******************************
 * ***********************************************
 */

/*
 * Fichero de implementacion Nodo.cc del modulo Nodo
 */

#include "Nodo.h"
#include <iostream>

/*
 * Pre: ---
 * Post: Devuelve un dato que representa un Nodo con un dato <<dato>>, un
 *       subNodo izquierdo <<izq>> y un subNodo derecho <<der>>
 */
void crearNodo(Nodo& a, const int numPasajerosTren, const int nEstaciones, int nPedidos){
	// Coste estimado
	a.coste_estimado = 0;
	// Beneficio parcial
	a.beneficioParcial = 0;
	// Pedido actual procesado 
	a.pedidoProcesado = -1;
	// Total de pasajeros del tren
	a.numPasajerosTren = numPasajerosTren;
	// Numero de estaciones del problema
	a.nEstaciones = nEstaciones;
	// Total de pedidos recolectados 
	a.nPedidos = nPedidos;
	// Iniciar las componentes a cero del vector de estaciones 
	for (int i = 0; i < MAX_ESTACIONES; i++){
		a.estaciones[i] = 0;
	}
}


/*
 * Pre: ---
 * Post: Devuelve el coste_estimado  
 */
int coste_estimado(const Nodo& a){
	return a.coste_estimado;
}


/*
 * Pre: ---
 * Post: Devuelve el total de pasajeros del tren
 */
int numPasajerosTren(const Nodo& a){
	return a.numPasajerosTren;
}


/*
 * Pre: ---
 * Post: Devuelve el total de estaciones 
 */
int nEstaciones(const Nodo& a){
	return a.nEstaciones;
}


/*
 * Pre: ---
 * Post: Devuelve el total de pedidos recolectados
 */
int nPedidos(const Nodo& a){
	return a.nPedidos;
}


/*
 * Pre: ---
 * Post: Devuelve el pedido procesado 
 */
int pedidoProcesado(const Nodo& a){
	return a.pedidoProcesado;
}


/*
 * Pre: ---
 * Post: Devuelve el beneficio parcial 
 */
int beneficioParcial(const Nodo& a){
	return a.beneficioParcial;
}


/*
 * Pre: <<hijoIzquierdo>> es el nodo del monticulo con el minimo coste
 * Post: Ha duplicado la informacion de <<hijoIzquierdo>> en el nodo <<hijoDerecho
 *       y ha aumentado en una unidad el numero de pedidos de de hijoDerecho
 */
void copiarInfoNodo(Nodo& hijoBueno, Nodo& hijoMalo, Pedido pedidos[], const int totalPedidos){
	// Incremento del pedido actual procesado
	hijoMalo.pedidoProcesado++;
	
	// Copia de la informacion 
	hijoBueno.numPasajerosTren = hijoMalo.numPasajerosTren;
	hijoBueno.nEstaciones = hijoMalo.nEstaciones;
	hijoBueno.beneficioParcial = hijoMalo.beneficioParcial;
	hijoBueno.pedidoProcesado = hijoMalo.pedidoProcesado - 1;
	hijoBueno.nPedidos = hijoMalo.nPedidos;
	hijoMalo.coste_estimado = calcularCosteEstimado(hijoMalo, pedidos, totalPedidos);
	// Copia de los datos de las estaciones
	for (int i = 0; i < MAX_ESTACIONES; i++){
		hijoBueno.estaciones[i] = hijoMalo.estaciones[i];
	}
}



/*
 * Pre: <<n>> es un nodo actual del problema; <pedidos>> es una tabla que almacena
 *      el total de pedidos del problema y <<nPedidos>> es el numero de pedidos del problema
 * Post: Ha devuelto <<true>> si y solo si desde la estacion desde la estacion inicial
 *       del problema almacenada en el nodo <<n>> hasta la estacion final tambien guardada
 *       en el nodo <<n>> se pueden subir todos los pasajeros que estan las diferentes
 *       estaciones comprendidas entre la inicial y la final. En caso contrario 
 *       ha devuelto <<false>>
 */
bool puedenSubirPasajeros(Nodo& n, Pedido p, Pedido pedidos[], const int nPedidos){
	// Incrementar el numero de pedidos procesados
	n.pedidoProcesado++;
	// Control de subida de los pasajeros
	bool pasajerosArriba = true;
	// Indices de las estaciones en las que se suben y bajan
	// los pasajeros del pedido <<p>>
	int estacionInicial = estacionSalida(p);
	int estacionFinal = estacionLlegada(p);
	int i = estacionInicial;
	// Recorrido de los pasajeros que se suben en las paradas intermedias
	while (i < estacionFinal && pasajerosArriba){
		// Mientras queden paradas por inspeccionar y puedan subir mas pasajeros
		// Incrementar el numero de pasajeros que se suben en la i-esima estacion
		// si es posible sin sobrepasar la capacidad del tren
		n.estaciones[i] += numPasajeros(p);
		pasajerosArriba = n.estaciones[i] <= numPasajerosTren(n);
		// Incremento de la estacion a procesar
		i++;
	}
	// Si no se excede la capacidad del tren se registra el beneficio
	if (pasajerosArriba){
		// Beneficio aceptado
		n.beneficioParcial += beneficioTransito(p);
		n.coste_estimado = calcularCosteEstimado(n, pedidos, nPedidos);
	}
	return pasajerosArriba;
}


/*
 * Pre: <<n>> es un nodo del problema que guarda en su tabla <<estaciones>>
 *      el numero de pasajeros que quieren subirse en cada estacion del trayecto
 *      y <<nuevasEstaciones>> es una tabla de <<MAX_ESTACIONES>> vacia
 * Post: Ha copiado en la tabla <<nuevasEstaciones>> las componentes de la
 *       tabla <<estaciones>> del nodo <<n>>
 */
void copiarEstaciones(Nodo& n, int nuevasEstaciones[]){
	for (int i = 0; i <MAX_ESTACIONES; i++){
		nuevasEstaciones[i] = n.estaciones[i];
	}
}


/*
 * Pre: La tabla <<estaciones>> es una tabla de <<MAX_ESTACIONES>> componentes
 *      que almacena los pasajeros que desean subirse en cada estacion del trayecto;
 *      <<inf>> y <<sup>> son dos indices de la tabla y 0 <= <<inf>> <= MAX_ESTACIONES 
 *      y 0 <= <<sup>> <= MAX_ESTACIONES y <<inf>> <= <<sup>>
 * Post: Ha devuelto el indice de la tabla <<estaciones>> correspondiente a la estacion
 *       donde se han registrado mas pasajeros candidatos a subirse al tren
 * 
 */
int estacionMasSolicitada(const int estaciones[], int inf, int sup){
	// Maximo numero de personas inicial
	int pasajerosCandidatos = estaciones[inf];
	// Indice de la estacion donde van a subir mas pasajeros
	int maxIndiceEstacion = inf;
	// Recorrido de las paradas desde el origen al destino
	for (int i = inf; i < sup; i++){
		// Determinar si en la i-esima estacion suben mas pasajeros
		if (estaciones[i] > pasajerosCandidatos){
			// Actualizar el indice de la estacion
			maxIndiceEstacion = i;
			// Guardar el nuevo maximo de pasajeros
			pasajerosCandidatos = estaciones[i];
		}
	}
	// Retorno del resultado
	return maxIndiceEstacion;
}


/*
 * Pre: <<beneficio>> es la maxima ganacia obtenida en el problema; <<Uminima>> es el
 *      valor de la funcion de poda actual; <<n>> es un nodo actual del problema;
 *      <<nPedidos>> es el numero total de pedidos del problema y <<pedidos>> es una tabla
 *      de <<MAX_PEDIDOS>> componentes que guarda todos los pedidos del problema
 * Post: Ha devuelto <<true>> si y solo si el nodo <<n>> se va a meter en el monticulo de 
 *       nodos como candidatoo ya que el coste(n) <= U(n) y ademas el coste(n) no supera 
 *       a la nueva cota. En caso contrario ha devuelto <<false>>
 */
bool calcularCosteCota(int& beneficio, double& Uminima, Nodo& n, const int nPedidos, Pedido pedidos[]){
	// Obtencion del coste estimado del nodo n
	double coste = coste_estimado(n);
	// Control de apilacion del nodo en el monticulo
	bool apilarEnMonticulo = false;
	// Comparar el valor del coste con la cota
	if (Uminima >= coste){
		// Actualizar el valor de la cota
		int nuevaCota = nuevaMejorCota(n, pedidos, nPedidos);
		// Control de si el nodo actual es interno o es hoja
		if (coste == nuevaCota || n.pedidoProcesado == nPedidos - 1){
			// El nodo es una hoja
			int nuevoBeneficio = BENEFICIO_MINIMO - coste;
			// Calcular la diferencia de beneficios y actualizar si es menor
			if (nuevoBeneficio > beneficio){
				// Actualizacion del beneficio
				beneficio = nuevoBeneficio;
			}
		}
		else {
			// El nodo se mete en el monticulo
			apilarEnMonticulo = true;
		}
		// Determinar si se debe actualizar la cota
		if (nuevaCota < Uminima){
			// Actualizar el valor de U
			Uminima = nuevaCota;
		}
	}
	// Retorno del resultado
	return apilarEnMonticulo;
}


/*
 * Pre: <<n>> es un nodo de la instancia actual del problema; <<pedidos>> es
 *      una tabla de <<MAX_PEDIDOS>> componentes que almacena todos los 
 *      pedidos de la instancia del problema y <<nPedidos>> es el numero de 
 *      pedidos del problema>>
 * Post: Ha devuelto el coste estimado del nodo actual del problema <<n>>
 */
double calcularCosteEstimado(Nodo& n, Pedido pedidos[], const int nPedidos){
	// Coste actual del nodo 
	int costeActual = n.beneficioParcial;
	// Actualizacion de las estaciones del nuevo nodo
	int nuevasEstaciones[MAX_ESTACIONES];
	copiarEstaciones(n, nuevasEstaciones);
	// Recorrido de los pedidos restantes para calcular
	// el coste estimado
	for (int i = n.pedidoProcesado + 1; i < nPedidos; i++){
		// Obtencion de los pasajeros que van a subirse en la i-esima parada
		int pasajerosCandidatos = numPasajeros(pedidos[i]);
		// Beneficio aportado por el precio del nuevo billete
		// Recorrido de cada una de las paradas pendientes
		for (int j = estacionSalida(pedidos[i]); j < estacionLlegada(pedidos[i]); j++){
			// Determinar si los pasajeros de la j-esima estacion caben en el tren
			if (pasajerosCandidatos > numPasajerosTren(n) - nuevasEstaciones[j]){
				// Actualizar las plazas ocupadas del tren con los nuevos pasajeros
				pasajerosCandidatos = numPasajerosTren(n) - nuevasEstaciones[j];
				nuevasEstaciones[j] += pasajerosCandidatos;
				// Incrementar el coste del nodo
				costeActual += pasajerosCandidatos;
			}
			else {
				// Se excede la capacidad del tren
				nuevasEstaciones[j] += numPasajeros(pedidos[i]);
				// Incrementar el coste del nodo
				costeActual += numPasajeros(pedidos[i]);
			}
		}
	}
	// Retorno del resultado
	return BENEFICIO_MINIMO - costeActual;
}



/*
 * Pre: <<n>> es un nodo de la instancia actual del problema; <<pedidos>> es
 *      una tabla de <<MAX_PEDIDOS>> componentes que almacena todos los 
 *      pedidos de la instancia del problema y <<nPedidos>> es el numero de 
 *      pedidos del problema>>
 * Post: Ha devuelto la nueva mejor cota del nodo
 */
int nuevaMejorCota(Nodo& n, Pedido pedidos[], const int nPedidos){
	// Coste actual del nodo 
	int cotaActual = n.beneficioParcial;
	// Actualizacion de las estaciones del nuevo nodo
	int nuevasEstaciones[MAX_ESTACIONES];
	copiarEstaciones(n, nuevasEstaciones);
	// Recorrido de los pedidos restantes para calcular
	// la nueva mejor cota 
	for (int i = n.pedidoProcesado + 1; i < nPedidos; i++){
		// Calcular el indice de la estacion mas solicitada
		int maxIndiceEstacion = estacionMasSolicitada(nuevasEstaciones, estacionSalida(pedidos[i]), estacionLlegada(pedidos[i]));
		if (numPasajerosTren(n) - nuevasEstaciones[maxIndiceEstacion] >= numPasajeros(pedidos[i])){
			for (int j = estacionSalida(pedidos[i]); j < estacionLlegada(pedidos[i]); j++){
			// Incrementar los pasajeros a subir al tren
			nuevasEstaciones[j] += numPasajeros(pedidos[i]);
			}
			// Incrementar la cota 
			cotaActual += beneficioTransito(pedidos[i]);
		}
	}
	// Retorno de la nueva cota del nodo
	return BENEFICIO_MINIMO - cotaActual;
}


/*
 * Pre: ---
 * Post: Ha devuelto <<true>> si y solo si <<n1>> es 
 *       menor que <<n2>>. En caso contrario ha devuelto <<false>>
 */
bool operator <(const Nodo& n1, const Nodo& n2){
	return n1.coste_estimado < n2.coste_estimado;
}


/*
 * Pre: ---
 * Post: Ha devuelto <<true>> si y solo si <<n1>> es 
 *       mayor que <<n2>>. En caso contrario ha devuelto <<false>>
 */
bool operator >(const Nodo& n1, const Nodo& n2){
	return n1.coste_estimado > n2.coste_estimado;
}


/*
 * Pre: ---
 * Post: Ha devuelto <<true>> si y solo si <<n1>> es 
 *       mayor o igual que <<n2>>. En caso contrario ha devuelto <<false>>
 */
bool operator >=(const Nodo& n1, const Nodo& n2){
	return n1.coste_estimado >= n2.coste_estimado;
}


/*
 * Pre: ---
 * Post: Ha devuelto <<true>> si y solo si <<n1>> es 
 *       menor o igual que <<n2>>. En caso contrario ha devuelto <<false>>
 */
bool operator <=(const Nodo& n1, const Nodo& n2){
	return n1.coste_estimado <= n2.coste_estimado;
}
