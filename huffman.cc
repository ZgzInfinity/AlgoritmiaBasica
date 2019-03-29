#include "Huffman.h"


using namespace std;

void generaHuffman(Heap& c, ArbolTrie& huffman, Huffman& h){
    ArbolTrie pri = min(c);
    eliminarMin(c);
    ArbolTrie segundo = min(c);
    eliminarMin(c);
    if(numElementos(c)>0){    
        ArbolTrie aux;
        unir(pri, segundo, aux);
        anyadir(c,aux); //Insertar debe dvolver el vector ordenado
        generaHuffman(c,huffman,h);
    }else{
        unir(pri, segundo, huffman);
    }
}

//Codificador con string CREO QUE ESTA MAL
void codificador(string codigos[],const ArbolTrie& a, string codigo, Huffman& h){
    if(esHoja(a)){
        carFrec c = obtenerCarFrec(a);
        codigos[(int)c.getCaracter()]=codigo;
    }else{
        string codigoIzq = codigo + "0";
        string codigoDer = codigo + "1";
        codificador(codigos,obtenerArbolIzquierdo(a),codigoIzq,h);
        codificador(codigos,obtenerArbolDerecho(a),codigoDer,h);
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



