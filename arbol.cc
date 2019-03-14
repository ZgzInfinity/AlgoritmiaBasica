#include "arbol.h"
#include "CarFrec/CarFrec.h"

//#include

Arbol::Arbol(Nodo* e){
    raiz=e;
}

Arbol::~Arbol(){
    //Hacerlo
}

//Pasar como a el que tenega mayor frecuencia
Nodo Arbol::unir(Nodo* a, Nodo* b){
    Nodo* u;
    u->izq= a;
    u->der= b;
    int frecuencia = a->e.getFrecuencia()+ b->e.getFrecuencia();
    u->e= carFrec('y',frecuencia);
    return *u;
}

int main(){
    Nodo n;
    Nodo n2;
    carFrec c= carFrec('a',20);
    n.e=c;
    carFrec c2= carFrec('b',40);
    n2.e=c2;
    printf("n frecuencia =%d y caracter= %c",n.e.getFrecuencia(),n.e.getCaracter());
    Arbol a = Arbol(&n);
    Nodo h= a.unir(&n,&n2);
    printf("n frecuencia =%d y caracter= %c",h.e.getFrecuencia(),h.e.getCaracter());

    
}
