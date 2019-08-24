#*****************************************************************
# Archivo: Makefile Practica_2
# Author:  Ruben Rodriguez Esteban 737215
#          Jose Maria Vallejo Puyal 720044
# Fecha:   23 de marzo de 2019
# Coms:    Fichero MakeFile para compilar la practica_2  
#          Para compilar y ejecutar seguir estos pasos en terminal
#          1 - Make clean
#          2 - Make
#          3 - ./transporte pruebas.txt resultado.txt      
#          ANYADIR REGLA PARA COMPILAR EN HENDRIX
#*****************************************************************

# Seleccion del compilador
CC=g++

# Expansion de variables

PEDIDO_DIR=Pedido
HEAP_DIR=Heap
NODO_DIR=Nodo


PEDIDO=${PEDIDO_DIR}/Pedido
NODO=${NODO_DIR}/Nodo
HEAP=${HEAP_DIR}/Heap
HEAP_IMPLEMENTOR=${HEAP_DIR}/HeapImplementor
TRANSPORTE=transporte

# Flags de compilacion
CPPFLAGS=-O2 -std=c++11 -Wall -O3

# Regla para compilar el programa principal
all: ${TRANSPORTE} 


# PEDIDO
# Compilacion
${PEDIDO}.o: ${PEDIDO}.h  ${PEDIDO}.cc
	${CC} -c ${CPPFLAGS} ${PEDIDO}.cc -o ${PEDIDO}.o
#----------------------------------------------------------------


# NODO
# Compilacion
${NODO}.o: ${NODO}.h  ${NODO}.cc
	${CC} -c ${CPPFLAGS} ${NODO}.cc -o ${NODO}.o
#---------------------------------------------------------------


# HEAP
# Compilacion
${HEAP_IMPLEMENTOR}.o: ${HEAP}.h ${HEAP_IMPLEMENTOR}.h
	${CC} -c -x c++ ${CPPFLAGS} ${HEAP_IMPLEMENTOR}.h -o ${HEAP_IMPLEMENTOR}.o
#--------------------------------------------------------------


# TRANSPORTE
# Compilacion
${TRANSPORTE}.o: ${TRANSPORTE}.cpp
	${CC} -c ${CPPFLAGS} ${TRANSPORTE}.cpp

# Linkado
${TRANSPORTE}: ${PEDIDO}.o ${NODO}.o ${HEAP_IMPLEMENTOR}.o ${TRANSPORTE}.o  
	${CC} ${PEDIDO}.o ${NODO}.o ${HEAP_IMPLEMENTOR}.o ${TRANSPORTE}.o -o ${TRANSPORTE}
#---------------------------------------------------------------

# LIMPIEZA
clean:
	$(RM) ${PEDIDO}.o
	$(RM) ${NODO}.o
	$(RM) ${HEAP_IMPLEMENTOR}.o
	$(RM) ${TRANSPORTE} ${TRANSPORTE}.o
