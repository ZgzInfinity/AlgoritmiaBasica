#*****************************************************************
# Archivo: Makefile Practica_1
# Author:  Ruben Rodriguez Esteban 737215
#          Jose Maria Vallejo Puyal 720044
# Fecha:   23 de marzo de 2019
# Coms:    Fichero MakeFile para compilar la practica_1   
#          Para compilar y ejecutar seguir estos pasos en terminal
#          1 - Make clean
#          2 - Make
#          3 - ./pruebas      
#          AÑADIR REGLA PARA COMPILAR EN HENDRIX
#*****************************************************************

# Seleccion del compilador
CC=g++

# Expansion de variables
ARBOLTRIE=ArbolTrie
CARFREC=CarFrec
COLA=Heap
PRUEBAS=pruebas

# Flags de compilacion
CPPFLAGS=-O2 -std=c++11 -Wall

# Regla para compilar el programa principal
all: ${PRUEBAS} 

# ARBOLTRIE
# Compilacion
${ARBOLTRIE}.o: ${ARBOLTRIE}.h ${ARBOLTRIE}.cc
	${CC} -c ${CPPFLAGS} ${ARBOLTRIE}.cc

# Linkado
${ARBOLTRIE}: ${CARFREC}.o ${ARBOLTRIE}.o  
	${CC} ${CARFREC}.o ${ARBOLTRIE}.o -o ${ARBOLTRIE}
#-----------------------------------------------------------------

# COLA
# Compilacion
${COLA}.o: ${COLA}.h ${COLA}.cc
	${CC} -c ${CPPFLAGS} ${COLA}.cc

# Linkado
${COLA}: ${CARFREC}.o ${ARBOLTRIE}.o ${COLA}.o
	${CC} ${CARFREC}.o ${ARBOLTRIE}.o ${COLA}.o -o ${COLA}
#----------------------------------------------------------------

# CARFREC
# Compilacion
${CARFREC}.o: ${CARFREC}.h  ${CARFREC}.cc
	${CC} -c ${CARFREC}.cc -o ${CARFREC}.o
#----------------------------------------------------------------

# PRUEBAS
# Compilacion
${PRUEBAS}.o: ${PRUEBAS}.cpp
	${CC} -c ${CPPFLAGS} ${PRUEBAS}.cpp

# Linkado
${PRUEBAS}: ${CARFREC}.o ${ARBOLTRIE}.o ${COLA}.o ${PRUEBAS}.o  
	${CC} ${CARFREC}.o ${ARBOLTRIE}.o ${COLA}.o ${PRUEBAS}.o -o ${PRUEBAS}
#-----------------------------------------------------------

# LIMPIEZA
clean:
	$(RM) ${CARFREC}.o
	$(RM) ${ARBOLTRIE} ${ARBOLTRIE}.o
	$(RM) ${COLA} ${COLA}.o
	$(RM) ${PRUEBAS} ${PRUEBAS}.o
