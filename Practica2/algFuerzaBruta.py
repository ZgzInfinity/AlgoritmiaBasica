
#-----------------------------------
# Autores:
# Ruben Rodriguez Esteban - 737215
# Jose Maria Vallejo Puyal - 720004
#-----------------------------------
 
# Biblioteca para medir tiempos de ejecucion
import time

# Constantes 
CLOCKS_PER_SEC = 1000000 

def maximoBeneficio(pedidos, capacidadTren, estaciones):
	# Contador del numero de pedidos atendidos
	j = 0
	# Ganancia obtenida hasta el momento
	ganancia = ganancia = sum(estaciones);
	# Para cada uno de los pedidos
	for pedido in pedidos:
		# Para cada uno de los pedidos de la lista 
		# Copiar la tabla de las estaciones
		nuevasEstaciones = estaciones[:]
		# Incremento del pedido a procesar
		j = j + 1
		# Obtencion del maximo numero de pasajeros que se van a subir durante
		# el trayectoe entre la estacion de salida y la estacion de llegada
		pasajerosDeseanSubir = max(nuevasEstaciones[pedido.get('estacionSalida'):pedido.get('estacionLlegada')])
		# Obtencion de cuantos pasajeros viajan en el tren actualmente
		pasajerosViajando = pedido.get('maxPasajeros')
		# Si pueden subirse todos los pasajeros
		if pasajerosDeseanSubir + pasajerosViajando <= capacidadTren:
		    # Estaciones de inicio y fin del trayecto
			estacionSalida = pedido.get('estacionSalida')
			estacionLlegada = pedido.get('estacionLlegada')
		    # Para cada una de las paradas intermedias del trayecto
			for parada in range(estacionSalida, estacionLlegada):
			    # Incrementar el numero de pasajeros del tren
				nuevasEstaciones[parada] += pasajerosViajando
			# Calcular la nueva ganancia
			ganancia = max(ganancia, sum(nuevasEstaciones))
		# Si aun quedan pedidos por atender
		if j <= len(pedidos):
		    # Comprobar si se puede obtener un mayor beneficio
			ganancia =max(ganancia,  maximoBeneficio(pedidos[j:], capacidadTren, nuevasEstaciones[:]))
	# Retorno de resultado
	return ganancia
			
	
	
def algoritmoFuerzaBruta(conjuntoPedidos, capacidadTren, estacionFinal):
	# Maxima ganancia del problema
	maxGanancia = 0
	# Pedido actualmente procesado
	j = -1
	for pedido in conjuntoPedidos:
		j = j + 1
		# Si todavia quedan pedidos pendientes de leer
		if j < len(conjuntoPedidos):
		    # Creacion de un vector de ceros para las estaciones de <<estacionFinal>> componentes
			listadoEstaciones = [0] * estacionFinal
			# Busqueda de un posible beneficio
			ganancia = maximoBeneficio(conjuntoPedidos[j:], capacidadTren, listadoEstaciones)
			# Si el beneficio es mayor que lo maximo obtenido hasta el momento se actualiza
			if ganancia > maxGanancia:
				# Actualizar la maxima ganancia conseguida
				maxGanancia = ganancia
	# Reotorno del resultado
	return maxGanancia



def finDeFichero(capacidadTren, estacionFinal, numPedidos):
	return capacidadTren == 0 and estacionFinal == 0 and numPedidos == 0

	
def presentarEstadisticas(idProblema, capacidadTren, estacionFinal, numPedidos, ganancia, microsegundos):
	# Presentacion de las estadisticas del problema
	print "  INSTANCIA ",idProblema," DEL PROBLEMA"
	print " =================================="
	print " Capacidad del tren: ", capacidadTren
	print " Estacion de final de linea: ", estacionFinal
	print " Pedidos recolectados: ", numPedidos
	print " Beneficio obtenido: ", ganancia
	print " El tiempo de ejecuon en segundos: " , microsegundos / CLOCKS_PER_SEC
	print " El tiempo de ejecucion en microsegundos: ", microsegundos 
	print 
	print 
	

# Control del final de lectura del fichero
fin = False
	
# Fichero de pruebas donde se encuentran las instancias del problema 
# El fichero se abre en modo lectura
descriptorFicheroPruebas = open("pruebas.txt")

# Fichero de escritura de los resultados obtenidos por el algoritmo de fuerza bruta	
# El fichero se debe abrir con permisos de escritura
descriptorFicheroResultados = open("resultadosFB.txt", "w+") 


# Numero de instancia de problema 
idProblema = 0

# Fichero abierto 
linea = descriptorFicheroPruebas.readline()

# Fragmentacion de la linea en espacios
lineaFragmentada = linea.split()

# Control de final de fichero
fin = finDeFichero(int(lineaFragmentada[0]), int(lineaFragmentada[1]), int(lineaFragmentada[2]))

# Mientras queden lineas por leer
while( not fin): 

	# Incremento del numero de problemas leidos
	idProblema = idProblema + 1
	
	# Guardar la capacidad del tren
	capacidadTren = int(lineaFragmentada[0])
	
	# Almacenar el codigo de estacion de fin de trayecto
	estacionFinal = int(lineaFragmentada[1])
	
	# Guardar el numero total de pedidos
	numPedidos = int(lineaFragmentada[2])
	
	# Creacion de la lista de pedidos vacia
	pedidos = []
	# Lectura de cada cada uno de los pedidos
	for i in range (0, numPedidos):
			# Leer linea de pedido y partir por los espacios
			pedidoLeido = descriptorFicheroPruebas.readline()
			# Particionado del pedido leido
			pedidoFragmentado = pedidoLeido.split()
			# Castear los datos del pedido a enteros 
			pedido = [{'estacionSalida': int(pedidoFragmentado[0]), 'estacionLlegada': int(pedidoFragmentado[1]), 'maxPasajeros': int(pedidoFragmentado[2])}]
			# Concatenar el nuevo pedido a la lista
			pedidos = pedidos + pedido
		
	# Tiempo actual
	tiempoInicial = time.clock()
	
	# Calculo del beneficio de la instancia del problema i-esimo
	beneficio = algoritmoFuerzaBruta(pedidos, capacidadTren, estacionFinal)
	
	# Tiempo actual y calculo de diferencia de tiempo
	tiempoFinal = time.clock()
	tiempo = float (tiempoFinal - tiempoInicial)
	
	# Presentacion de las estadisticas del programa
	presentarEstadisticas(idProblema, capacidadTren, estacionFinal, numPedidos, beneficio, tiempo)
	
	# Precision de 5 decimales
	tiempoAcotado = format(tiempo, '.5f')
	
	# Escribir el beneficio y el tiempo de ejecucion en el fichero de resultados
	descriptorFicheroResultados.write(str(beneficio) + " " + str(tiempoAcotado) + "\n")
	
	# Lectura de una nueva instancia del problema
	linea = descriptorFicheroPruebas.readline()
	
	# Fragmentacion de la linea en espacios
	lineaFragmentada = linea.split()
	
	# Control de final de fichero
	fin = finDeFichero(int(lineaFragmentada[0]), int(lineaFragmentada[1]), int(lineaFragmentada[2]))
	
# Cierre del descriptor del fichero de pruebas
descriptorFicheroPruebas.close()
# Cierre del descriptor del fichero de resultados 
descriptorFicheroResultados.close()
	