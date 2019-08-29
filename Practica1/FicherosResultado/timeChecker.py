
#-----------------------------------
# Autores:
# Ruben Rodriguez Esteban - 737215
# Jose Maria Vallejo Puyal - 720004
#-----------------------------------

# Numero total de problemas resueltos por los algoritmos 
NUM_PROBLEMAS = 8000


# Fichero de resultados obtenidos por el algoritmo de ramificacion y poda
descriptorFicheroResulPoda = open("resultados.txt")


# Fichero de resultados obtenidos por el algoritmo de fuerza bruta
descriptorFicheroResulBruta = open("resultadosFB.txt") 


# Numero de instancia de problema 
problemasResueltos = 0

# Numero  de veces que es mas rapido el algoritmo de ramificacion y poda
vecesRapidoPoda = 0

# Mientras que qeden problemas por leer
while(problemasResueltos != NUM_PROBLEMAS):
 
	# Lectura de una linea de resultados del fichero de poda
	lineaResulPoda = descriptorFicheroResulPoda.readline()

	# Lectura de una linea de resultados del fichero de poda
	lineaResulBruta = descriptorFicheroResulBruta.readline()
	
	# Fragmentacion de la linea leida del fichero de resultados de poda en sus campos
	fragMentadoResulPoda = lineaResulPoda.split()
	
	# Extraccion del tiempo de ejecucion
	tiempoEjecucionPoda = fragMentadoResulPoda[1]
	
	# Fragmentacion de la linea leida del fichero de resultados de bruta en sus campos
	fragMentadoResulBruta = lineaResulBruta.split()
		
	# Extraccion del tiempo de ejecucion
	tiempoEjecucionBruta = fragMentadoResulBruta[1]
	
	# Comparacion de tiempos de ambos algoritmos
	if float(tiempoEjecucionPoda) < float(tiempoEjecucionBruta):
		# El algoritmo de ramificacion y poda fue mas rapido
		# Incremento del contador
		vecesRapidoPoda = vecesRapidoPoda + 1
		
	# Incremento del numero de problemas leidos
	problemasResueltos = problemasResueltos + 1
	
# Muestro del total de problemas revisados
print "Total de problemas leidos: " ,problemasResueltos
print "Total de casos en los que ramificacion y poda es mas rapido que fuerza bruta: " ,vecesRapidoPoda

# Cierre del descriptor del fichero de pruebas
descriptorFicheroResulPoda.close()
# Cierre del descriptor del fichero de resultados 
descriptorFicheroResulBruta.close()