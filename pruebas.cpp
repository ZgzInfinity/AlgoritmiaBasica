#include <iostream>
#include <cstring>
#include "Huffman.h"
#include "CarFrec.h"
#include "ArbolTrie.h"
#include "Heap.h"


const int UMBRAL = 51;
const int MAX_FICHERO_NOMBRE = 100;

/*
 * Pre: <<nombreFichero>> es un fichero de caracteres y <<numCfrecs>> es un vector vacio
 *      que puede no tiene almacenado ningun dato de tipo calFrec
 * Post: Si la lectura del fichero de caracteres <<nombreFichero>> se ha efectuado correctamente
 *       ha guardado en las primeras componentes del vector <<numCfrecs>> el numero de veces
 *       que aparece cada caracter distinto en el fichero junto con el propio caracter.
 *       En caso contrario ha informado mediante un error por pantalla de la innacesibilidad
 *       del fichero <<nombreFichero>>
 */
void frecuenciasPorCaracter(const char nombreFichero[], int frecsPorChar[]){
	int codAscii;
	// Creacion del flujo de lectura
	ifstream f;
	// Asociacion del flujo al fichero
	f.open(nombreFichero);
	if (f.is_open()){
		// Flujo asociado a fichero correctamente
		char c;
		// lectura del primer caracter del fichero
		c = f.get();
		while (!f.eof()){
			// mientras no acaba el fichero
			codAscii = int(c);
			frecsPorChar[codAscii]++;
			// lectura de un nuevo caracter del fichero
			c = f.get();
		}
		// Cierre del flujo de lectura asociado al fichero
		f.close();
	}
	else {
		// Error en la asociacion del flujo al fichero
		cerr << "El fichero de " << nombreFichero << " no se ha podido leer " << endl;
	}
}

string rellenar(string s, int numCeros){
	for(int i = 0; i < numCeros ; i++){
		s = s + "0"; 
	}
	return s;
}

void comprimir(string nombre, string codigos[]){
	ifstream f(nombre);
	string nSal = nombre +".bin";
    ofstream sal(nSal);
	char c;
	string s = "";
	int aux=0;
	int numBytes = 0;
	int caracteres;
	string sub;
	int ascii;
    while (f.get(c))
    {
		numBytes++;
        s = s + codigos[(int)c];
		if(s.length()%8==0){
			 caracteres = s.length()/8;
			 cout << "la String es: " << s << endl;
			for(int i = 0; i < caracteres; i++){
				sub = s.substr(i*8,8);
				cout << "La substring es : " << sub << endl;
				ascii = std::stoi(sub, nullptr, 2);
				sal << (char)ascii;
			}
			s = "";
		}
    }
	if(s.length()>0){
		caracteres = s.length()/8;
		cout << "Quedan por escribir " << caracteres << " y sobran " << s.length()%8; 
		int i=0;
		cout << "La ultima string que no es multiplo de 8 vale: " << s << endl;
		while(i < caracteres){
				sub = s.substr(i*8,8);
				cout << "La substring es : " << sub << endl;
				ascii = std::stoi(sub, nullptr, 2);
				sal << (char)ascii;
				i++;
		}

		if(s.length()%8 != 0){
			sub = s.substr(i*8, s.length()%8);
			cout << "La ultima string vale :" << sub << endl; 
			ascii = std::stoi(rellenar(sub,8-s.length()), nullptr, 2);
			cout << "La string rellenada vale: " << rellenar(sub,8-s.length()) << endl;
			sal << (char)ascii;

		}
	}

	cout << "Al final se han escrito " << numBytes << " Bytes." << endl;


}


int main(){
	const char fichero[] = "frecuencias.txt";
	int frecsPorChar[MAX_CARACTERES];
	
	for (int i = 0; i < MAX_CARACTERES; i++){
		frecsPorChar[i] = 0;
	}
	
	frecuenciasPorCaracter(fichero, frecsPorChar);
	
	// Mostrar caracteres leidos
	for (int i = 0; i < MAX_CARACTERES; i++){
		if (frecsPorChar[i] > 0){
			cout << char(i) << frecsPorChar[i] << endl;
		}
	}
	
	carFrec ca;
	ArbolTrie a;
	Heap h;
	crearVacio(h);
	
	cout << "El monticulo tiene " << numElementos(h) << " elementos" << endl;
	
	rellenar(h, frecsPorChar);
	
	int total = numElementos(h);
	cout << "El monticulo tiene " << total << " elementos" << endl;
	
	
	for (int i = 1; i <= total; i++){
		a = consultar(h, i);
		ca = obtenerCarFrec(a);
		cout << i << " C: " << ca.getCaracter() << " F: " << ca.getFrecuencia() << endl;
	}
	
	ArbolTrie huff;
	Huffman hF;
	generaHuffman(h, huff, hF);
	
	string codigos[MAX_CARACTERES];
	
	for(int k = 0; k < 256 ; k++){
		codigos[k]= "-";
	}
	
	codificador(codigos, huff, "", hF);
	
	for(int j = 0; j < 256; j++){
		if(codigos[j]!= "-")
		cout << "El codigo de " << (char)j << " es: " << codigos[j] << endl;
	}

	comprimir("frecuencias.txt", codigos);

	
	cout << "Fin del programa " << endl;
	
	return 0;
	
}
