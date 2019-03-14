#ifndef _ARBOL_H_
#define _ARBOL_H_


//Includes
#include "CarFrec/CarFrec.h"
#include <cstring>
#include <string.h>
#include <iostream>


using namespace std;
struct Nodo{
            carFrec e;
            Nodo* izq;
            Nodo* der;
        };

class Arbol{
    private:       
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
