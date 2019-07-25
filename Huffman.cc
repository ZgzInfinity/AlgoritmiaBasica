#include "Huffman.h"

using namespace std;

// Constantes del programa
const int UMBRAL = 51;
const int MAX_FICHERO_NOMBRE = 100;


/*
 * Pre: ---
 * Post: Ha asignado con valor cero todas las componentes del 
 *       vector <<frecsPorChar>>
 */
void iniciarFrecuencias(int frecsPorChar[]){
	for (int i = 0; i < MAX_CARACTERES; i++){
		frecsPorChar[i] = 0;
	}
}


/*
 * Pre: ---
 * Post: Ha asignado con valor '-' todas las componentes del 
 *       vector <<frecsPorChar>>
 */
void iniciarCodificaciones(string codigos[]){
	for(int k = 0; k < 256 ; k++){
		codigos[k]= "-";
	}
}

/*
 * Pre: <<nombreFichero>> es un fichero de caracteres y <<frescPorChar>> es un vector de 
 *      enteros vacio destinado a almacenar en cada una de sus componentes las veces que 
 *      aparece cada caracter del fichero <<nombreFichero>>
 * Post: Si la lectura del fichero de caracteres <<nombreFichero>> se ha efectuado correctamente
 *       ha guardado en las componentes del vector <<frecsPorChar>> el numero de veces
 *       que aparece cada caracter distinto en el fichero. En caso contrario ha informado
 *       mediante un error por pantalla de la innacesibilidad del fichero <<nombreFichero>>
 */
void frecuenciasPorCaracter(string nombreFichero, int frecsPorChar[]){
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
		// mientras no acaba el fichero
		while (!f.eof()){
			// obtencion del codigo ascii del caracter leido
			codAscii = int(c);
			// incremento de la frecuencia correspondiente
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



/*
 * Pre: <<c>> es una cola de prioridades o monticulo donde se almacenan todos los
 *      caracteres y sus correspondientes frecuencias de caracteres ordenados por 
 *      orden decreciente de frecuencia. <<a>> es un trie en cuyos nodos residen los
 *      caracteres y sus correspondientes frecuencias
 * Post: <<h>> es el resultado de aplicar el algoritmo de codificacion Huffman de tal forma
 *        que a los caracteres con mayor valor de frecuencia se les ha asignado un codigo de 
 *        compresion menor y a los digitos de mayor frecuencia un codigo mayor, garantizando
 *        asi un tamanyo de fichero comprimido menor
 */
void generaHuffman(Heap& c, ArbolTrie& a, Huffman& h){
	// Obtener primer elmentos del monticulo
    ArbolTrie pri = min(c);
	// Eliminar el primer elemento del monticulo
    eliminarMin(c);
	// Obtener el nuevo primer elemento del monticulo
    ArbolTrie segundo = min(c);
	// Eliminar el nuevo primer elemento del monticulo
    eliminarMin(c);
	// Si quedan elementos
    if(numElementos(c)>0){  
		// Crear un nuevo nodo uniendo los otros dos 
        ArbolTrie aux;
        unir(pri, segundo, aux);
		// Insertar el nuevo formado en la cola de prioridades
        anyadir(c,aux); 
        generaHuffman(c, a, h);
    }
	else{
		// Crear un nuevo nodo uniendo los otros dos 
        unir(pri, segundo, a);
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

void comprimir(string nombre, Huffman& h){
    int frecsPorChar[MAX_CARACTERES];

    iniciarFrecuencias(frecsPorChar);

    frecuenciasPorCaracter(nombre, frecsPorChar);

    // Creacion del monticulo
	Heap hp;
	crearVacio(hp);
	
	// Rellenado del monticulo 
	rellenar(hp, frecsPorChar);

    int total = numElementos(hp);
	cout << "El monticulo tiene " << total << " elementos" << endl;

    
	ArbolTrie huff;
	
	// Construccion del arbol de codificacion Huffman
	generaHuffman(hp, huff, h);
	
	// vector de codigos binarios para cada caracter
	string codigos[MAX_CARACTERES];
	
	// Iniciar codificaciones binarias
	iniciarCodificaciones(codigos);
	
	// Codificacion de caracteres con codigos binarios
	codificador(codigos, huff, "", h);
	
	
	// Muestreo de los codigos binarios obtenidos
	for(int j = 0; j < 256; j++){
		if(codigos[j]!= "-")
		cout << "El codigo de " << (char)j << " es: " << codigos[j] << endl;
	}


    // string cod[256];
    // ArbolTrie a;
    // int posicion;
    // //Obtener el huffman
    // //codificador(cod,a,"0");
    string nSal = nombre +".bin";
    ofstream sal(nSal); 
    // cod[65]="10";
    // cod[66]="01";
    // cod[67]="00";
    // cod[68]="11";
    ifstream in;
    string s="";
    in.open(nombre);
    char c;
    while (in.get(c))
    {
        s = s + codigos[(int)c]; 
    }
    cout << s << endl;
    int x = 0;
    while(x < s.length()){
        if((x - s.length() < 8)){
            cout << s.substr(x,x - s.length()) << endl;
            sal << (char)std::stoi(s.substr(x,x - s.length()), nullptr, 2);
        }else{
            cout << s.substr(x,8) << endl;
            std::stoi(s.substr(x,8), nullptr, 2);
            sal << (char)std::stoi(s.substr(x,8), nullptr, 2);
        }
        x = x+8;
    }
}



