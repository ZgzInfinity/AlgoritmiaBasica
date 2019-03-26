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


void descifra(string nombre,string destino){
    ifstream f(nombre, ios::binary | ios::in);
    ofstream out(destino);
    char c;
    while (f.get(c))
    {
        for (int i = 7; i >= 0; i--){
            cout << ((c >> i) & 1);
        }
    }
}

void comprimir(string nombre){
    string cod[256];
    ArbolTrie a;
    int posicion;
    //Obtener el huffman
    codificador(cod,a,"0");
    


    //leemos el dato
    //cogemos el codigo
    //hay que tratar los codigos de 8 en 8 para que funcione como chars


    



}
/*void comprimir(char in[], char out[], int codigos[]){
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
    //escribirlo en el fichero 
}*/


int main(){
    /*std::bitset<8> foo;
    foo.set();
    foo[4]=0;
    foo[1]=0;
    ofstream out;
    out.open("prueba.txt");
    unsigned long i = foo.to_ulong(); 
    unsigned char c = static_cast<unsigned char>( i );
    
    out<<c;
    cout << "el caracter es " << c <<"\n";*/
    /*char ca;
    ifstream f;
    f.open("prueba.txt");
    //f.seekg(0);
    if (f.is_open())
    {      
        ca = f.get();
    }
    cout << ca;
    uint8_t result = ca;
    cout << "el numero es es " << result;*/

    
    
    /*string s= "10000000";
    int i = std::stoi(s, nullptr, 2);
    //cout<<(char)i;
    
    out << (char)i;*/
    
    //De aqui para abajo esta todo dpm
    
    string cod[100];
    cod[65]="10";
    cod[66]="01";
    cod[67]="00";
    cod[68]="11";
    
    ifstream in;
    string s="";
    in.open("pru.txt");
    char c;
    while (in.get(c))
    {
        /*for (int i = 7; i >= 0; i--){
            cout << ((c >> i) & 1);
        }*/
        s = s + cod[(int)c]; 
    }

    ofstream out;
    out.open("salida.txt");
    int i = std::stoi(s, nullptr, 2);    
    out << (char)i;


    
    



    return 0;
}



