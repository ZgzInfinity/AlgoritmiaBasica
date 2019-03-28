#include "Heap.h"


void crearVacio(Heap& h){
    h.num=0;
}


int numElementos(Heap& h){
	return h.num;
}

void anyadir(Heap& h, ArbolTrie& a){
    h.num++;
    h.arboles[h.num]=a;
    int i = h.num;
    bool debeSubir;

    if(i>1){
        debeSubir = obtenerArbolFrecuencia(h.arboles[i]) < obtenerArbolFrecuencia(h.arboles[i/2]);
    }else{
        debeSubir = false;
    }

    while(debeSubir){
        ArbolTrie aux;
        aux = h.arboles[i];
        h.arboles[i]=h.arboles[i/2];
        h.arboles[i/2]=aux;
        i = i/2;
        if(i>1){
            debeSubir = obtenerArbolFrecuencia(h.arboles[i]) < obtenerArbolFrecuencia(h.arboles[i/2]);
        }else{
            debeSubir = false;
        }
    }
}

void eliminarMin(Heap& h){
    int i,j;
    ArbolTrie aux;
    if(h.num>0){
        h.arboles[0]= h.arboles[h.num];
        h.num--;
        i = 1;
        while(i<(h.num/2)){
            if(2*i==h.num || obtenerArbolFrecuencia(h.arboles[2*i]) < obtenerArbolFrecuencia(h.arboles[2*i+1])){
                j= 2*i;
            }else{
                j = 2*i+1;
            }

            if(obtenerArbolFrecuencia(h.arboles[i]) > obtenerArbolFrecuencia(h.arboles[j])){
                aux = h.arboles[i];
                h.arboles[i]= h.arboles[j];
                h.arboles[j]= aux;
                i = j;
            }else{
                i = h.num;
            }
        }
    }
}

ArbolTrie min(Heap& h){
    return h.arboles[1];
}

bool esVacio(Heap& h){
    return h.num == 0;
}

ArbolTrie consultar(Heap& h, const int i){
	return h.arboles[i];
}