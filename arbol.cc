#include "arbol.h"

//#include

Arbol::Arbol(Nodo* e){
    raiz=e;
}

Arbol::~Arbol(){
    //Hacerlo
}

//Pasar como a el que tenega mayor frecuencia
Arbol::Nodo Arbol::unir(Nodo* a, Nodo* b){
    Arbol::Nodo* union = new Arbol::Nodo;
    union.izq= a;
    union.der= b;
    union.e.frecuencia = a.frecuencia + b.frecuencia;
    return union;
}
