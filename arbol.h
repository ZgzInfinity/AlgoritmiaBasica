#ifndef _ARBOL_H_
#define _ARBOL_H_


//Includes

#include <cstring>
#include <string.h>
#include <iostream>


using namespace std;

class Arbol{
    private:
        struct Nodo{
            Elemento e;
            Nodo* izq;
            Nodo* der;
        };
        Nodo* raiz;
    public:

       Arbol(Nodo* a);
       ~Arbol();
       Nodo unir(Nodo* a, Nodo* b);
       char descifraSecuencia(Arbol a);
       Arbol descifraArbol(string s);
       string cifraArbol(Arbol a);        
};
#endif
