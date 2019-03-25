#include <ArbolTrie.h>
#include <Cola.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <fstream>

using namespace std;

void generaHuffman(Cola& c, ArbolTrie& huffman){
    ArbolTrie primero = primero(c);
    eliminarPrimerArbol(c);
    ArbolTrie segundo = primero(c);
    eliminarPrimerArbol(c);
    if(numElementos(c)>=2){    
        ArbolTrie aux;
        unir(primero, segundo, aux);
        insertarArbol(c,aux); //Insertar debe dvolver el vector ordenado
        generaHuffman(c,huffman);
    }else{
        unir(primero, segundo, huffman);
    }
}

//Codificador con enteros
void codificadorEnt(int codigos[], ArbolTrie& a,int codigo, int num){
    if(esHoja(a)){
        CarFrec c = obtenerCarFrec(a);
        codigos[c.getCaracter()]=codigo;
    }else{
        int codigoIzq = codigo*2;
        int codigoDer = codigo*2 + 1;
        codificadorEnt(codigos,obtenerArbolIzquierdo(a),codigoIzq,num+1);
        codificadorEnt(codigos,obtenerArbolDerecho(a),codigoDer,num+1);
    }
}


//Codificador con string 
void codificador(string codigos[], ArbolTrie& a,string codigo){
    if(esHoja(a)){
        CarFrec c = obtenerCarFrec(a);
        codigos[c.getCaracter()]=codigo;
    }else{
        string codigoIzq = codigo + "0";
        string codigoDer = codigo + "1";
        codificador(codigos,obtenerArbolIzquierdo(a),codigIzq);
        codificador(codigos,obtenerArbolDerecho(a),codigDer);
    }
}

void comprimir(char in[], char out[], int codigos[]){
    //leer cada caracter y
    string total = "";

    //en el bucle
    total = total + codigos[(int)caracter];

    if(total.size()%32 == 0){
        //escribir en el fichero destino los enteros ya codificadis
        int i_bin = std::stoi (str_bin,nullptr,2); 
        total.clear();
    }


    //saliendo del bucle
    //codificar lo que falte con int i_bin = std::stoi (str_bin,nullptr,2); 





}

