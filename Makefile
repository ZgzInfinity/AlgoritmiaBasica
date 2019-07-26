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

CARFREC_DIR=CarFrec
PRELIMINAR_DIR=Preliminar
ARBOLTRIE_DIR=ArbolTrie
HEAP_DIR=Heap
HUFFMAN_DIR=Huffman

CARFREC=${CARFREC_DIR}/CarFrec
PRELIMINAR=${PRELIMINAR_DIR}/Preliminar
ARBOLTRIE=${ARBOLTRIE_DIR}/ArbolTrie
HEAP=${HEAP_DIR}/Heap
HUFFMAN=${HUFFMAN_DIR}/Huffman
HUF=huf

# Flags de compilacion
CPPFLAGS=-O2 -std=c++11 -Wall

# Regla para compilar el programa principal
all: ${HUF} 


# CARFREC
# Compilacion
${CARFREC}.o: ${CARFREC}.h  ${CARFREC}.cc
	${CC} -c ${CPPFLAGS} ${CARFREC}.cc -o ${CARFREC}.o
#----------------------------------------------------------------


# PRELIMINAR
# Compilacion
${PRELIMINAR}.o: ${PRELIMINAR}.h  ${PRELIMINAR}.cc
	${CC} -c ${CPPFLAGS} ${PRELIMINAR}.cc -o ${PRELIMINAR}.o
#---------------------------------------------------------------


# ARBOLTRIE
# Compilacion
${ARBOLTRIE}.o: ${ARBOLTRIE}.h ${ARBOLTRIE}.cc
	${CC} -c ${CPPFLAGS} ${ARBOLTRIE}.cc -o ${ARBOLTRIE}.o
#--------------------------------------------------------------

# HEAP
# Compilacion
${HEAP}.o: ${HEAP}.h ${HEAP}.cc
	${CC} -c ${CPPFLAGS} ${HEAP}.cc -o ${HEAP}.o
#--------------------------------------------------------------


# HUFFMAN
# Compilacion
${HUFFMAN}.o: ${HUFFMAN}.h ${HUFFMAN}.cc
	${CC} -c ${CPPFLAGS} ${HUFFMAN}.cc -o ${HUFFMAN}.o
#--------------------------------------------------------------

# PRUEBAS
# Compilacion
${HUF}.o: ${HUF}.cpp
	${CC} -c ${CPPFLAGS} ${HUF}.cpp

# Linkado
${HUF}: ${PRELIMINAR}.o ${HUFFMAN}.o ${CARFREC}.o ${ARBOLTRIE}.o ${HEAP}.o ${HUF}.o  
	${CC} ${PRELIMINAR}.o ${HUFFMAN}.o ${CARFREC}.o ${ARBOLTRIE}.o ${HEAP}.o ${HUF}.o -o ${HUF}
#---------------------------------------------------------------

# LIMPIEZA
clean:
	$(RM) ${CARFREC}.o
	$(RM) ${PRELIMINAR}.o
	$(RM) ${ARBOLTRIE}.o
	$(RM) ${HUFFMAN}.o
	$(RM) ${HEAP}.o
	$(RM) ${HUF} ${HUF}.o
