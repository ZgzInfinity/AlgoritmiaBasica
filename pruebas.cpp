#include <iostream>
#include <cstring>
#include "Huffman/Huffman.h"
#include "CarFrec/CarFrec.h"
#include "ArbolTrie/ArbolTrie.h"
#include "Heap/Heap.h"


int main(){

		Huffman h;
    comprimir("frecuencias.txt", h);

    return 0;
}
