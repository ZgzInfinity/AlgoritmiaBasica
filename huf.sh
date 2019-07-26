#!/bin/bash

#----------------------------------
# Autores:
# Jose Maria Vallejo Puyal
# 720004
# Rubén Rodríguez Esteban
# NIP: 737215
#----------------------------------


#Script para llevar a cabo la ejecucion del programa huf

# Comprobar el numero de parametros
if [ $# -ne 2 ]
then
    echo "Numero incorrecto de parametros"
    echo "Se necesitan 2 parametros para ejecutar"
    echo "Flag de compresion o descompresion (-c|-d) "
    echo "Nombre del fichero a comprimir o descomprimir (debe estar en el directorio ficheros)"
    exit 1
fi

# Lanzar una terminal con la ejecucion del programa y sus parametros
gnome-terminal "./huf $1  $2"
