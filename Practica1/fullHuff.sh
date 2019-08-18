#!/bin/bash

#----------------------------------
# Autores:
# Jose Maria Vallejo Puyal
# 720004
# Rubén Rodríguez Esteban
# NIP: 737215
#----------------------------------

# Ejecutar la compresion y descompresion para cada uno de los ficheros
# del directorio Ficheros

#Ruta del fichero completa
fichero="Ficheros/$1"

# Verificación de la existencia del fichero que contiene la lista de ficheros
# de prueba
if [ ! -e $fichero ]
then
    echo "El fichero que almacena la lista de ficheros de prueba no existe"
    exit 1
fi


# Bucle de lectura del fichero que contiene la lista de ficheros de prueba
while read ficheroLeido
do
    echo "Analisis del fichero $ficheroLeido"
    # Invocar al script huf.sh para que lleve a cabo la compresion y la
    # descompresion del fichero

    # Ejecucion de la compresion del fichero
    gnome-terminal -e "./huf -c  $ficheroLeido"

    # Dormir dos segundos la ejecucion del script
    sleep 2

    # Ejecucion de la descompresion del fichero
    gnome-terminal -e "./huf -d  $ficheroLeido"

done < $1
