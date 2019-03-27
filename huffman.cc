#include "ArbolTrie.h"
#include "Cola.h"
#include <iostream>
#include <cstring>
#include <vector>
#include <fstream>
#include <bitset>
#include "CarFrec.h"

using namespace std;

void generaHuffman(Cola& c, ArbolTrie& huffman){
    ArbolTrie pri = primero(c);
    eliminarPrimerArbol(c);
    ArbolTrie segundo = primero(c);
    eliminarPrimerArbol(c);
    if(numElementos(c)>=2){    
        ArbolTrie aux;
        unir(pri, segundo, aux);
        insertarArbol(c,aux); //Insertar debe dvolver el vector ordenado
        generaHuffman(c,huffman);
    }else{
        unir(pri, segundo, huffman);
    }
}

//Codificador con enteros
void codificadorEnt(int codigos[],const ArbolTrie& a,int codigo, int num){
    if(esHoja(a)){
        carFrec c = obtenerCarFrec(a);
        codigos[c.getCaracter()]=codigo;
    }else{
        int codigoIzq = codigo*2;
        int codigoDer = codigo*2 + 1;
        codificadorEnt(codigos,obtenerArbolIzquierdo(a),codigoIzq,num+1);
        codificadorEnt(codigos,obtenerArbolDerecho(a),codigoDer,num+1);
    }
}


//Codificador con string 
void codificador(string codigos[],const ArbolTrie& a,string codigo){
    if(esHoja(a)){
        carFrec c = obtenerCarFrec(a);
        codigos[c.getCaracter()]=codigo;
    }else{
        string codigoIzq = codigo + "0";
        string codigoDer = codigo + "1";
        codificador(codigos,obtenerArbolIzquierdo(a),codigoIzq);
        codificador(codigos,obtenerArbolDerecho(a),codigoDer);
    }
}


void descifra(string nombre){
    ifstream f(nombre, ios::binary | ios::in);
    char c;
    while (f.get(c))
    {
        for (int i = 7; i >= 0; i--){
            int a =  ((c >> i) & 1);
            cout<<a;
            //Recorrer el arbol y descifrar las letras
        }
    }
}

void comprimir(string nombre){
    string cod[256];
    ArbolTrie a;
    int posicion;
    //Obtener el huffman
    //codificador(cod,a,"0");
    string nSal = nombre +".bin";
    ofstream sal(nSal); 
    cod[65]="10";
    cod[66]="01";
    cod[67]="00";
    cod[68]="11";
    ifstream in;
    string s="";
    in.open(nombre);
    char c;
    while (in.get(c))
    {
        s = s + cod[(int)c]; 
    }
    //Parsear de 8 en 8 la cadena en un buclle y escribitlo
    int i = std::stoi(s, nullptr, 2);    
    sal << (char)i;
}

/*
int main(){ 
    //comprimir("pru");
    descifra("pru.bin");
    return 0;
}
*/


