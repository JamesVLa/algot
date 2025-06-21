#include <iostream>
using namespace std;

const int N = 30;

// Estructura para almacenar el resultado del intervalo más largo
struct Rango {
    int inicio;   // Día inicial (1-based)
    int fin;      // Día final (1-based)
    int longitud; // Cantidad de días consecutivos
    int peso;     // Peso asociado
};

// a) Leer los datos del paciente
void leerDatos(int *arr) {
    cout << "Ingrese las evaluaciones del paciente día por día, desde el día 1 al día 30:" << endl;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
}

// b) Encontrar el menor peso usando divide y vencerás (O(n log n))
int encontrarMenorPeso(int arr[], int izquierda, int derecha){
	// Caso base: uno Solo
	if(izquierda==derecha)
		return arr[izquierda];
	//Dividir
	int medio = (izquierda + derecha) /2;
	
	// minimo Izquierda
	int minimoIzq = encontrarMenorPeso(arr,izquierda,medio);
	//minimo derecha
	int minimoDer = encontrarMenorPeso(arr,medio+1,derecha);
	
	if(minimoIzq<minimoDer)
		return minimoIzq;
	return minimoDer; 
}

/*
int encontrarMenorPeso(int arr[], int izquierda, int derecha) {
    // Caso base: un solo elemento
    if (izquierda == derecha)
        return arr[izquierda];
    
    // Dividir
    int medio = (izquierda + derecha) / 2;
    
    // Conquistar: encontrar el mínimo en cada mitad
    int minIzquierda = encontrarMenorPeso(arr, izquierda, medio);
    int minDerecha = encontrarMenorPeso(arr, medio + 1, derecha);
    
    // Combinar: devolver el menor
    return min(minIzquierda, minDerecha);
}
*/
/*
Rango encontrarRangoMasLargo(int arr[], int izquierda, int derecha, int menorPeso) {
    Rango resultado = {0, 0, 0, menorPeso};
    if (izquierda == derecha) {
        if (arr[izquierda] == menorPeso) {
            resultado.inicio = izquierda + 1;
            resultado.fin = izquierda + 1;
            resultado.longitud = 1;
        }
        return resultado;
    }
    int medio = (izquierda + derecha) / 2;
    Rango rangoIzquierda = encontrarRangoMasLargo(arr, izquierda, medio, menorPeso);
    Rango rangoDerecha = encontrarRangoMasLargo(arr, medio + 1, derecha, menorPeso);
    Rango rangoCruce = {0, 0, 0, menorPeso};
    if (arr[medio] == menorPeso && arr[medio + 1] == menorPeso) {
        int inicio = medio, fin = medio + 1;
        while (inicio >= izquierda && arr[inicio] == menorPeso)
            inicio--;
        while (fin <= derecha && arr[fin] == menorPeso)
            fin++;
        rangoCruce.inicio = inicio + 2;
        rangoCruce.fin = fin;
        rangoCruce.longitud = fin - inicio - 1;
    }
    if (rangoIzquierda.longitud >= rangoDerecha.longitud && rangoIzquierda.longitud >= rangoCruce.longitud)
        return rangoIzquierda;
    if (rangoDerecha.longitud >= rangoIzquierda.longitud && rangoDerecha.longitud >= rangoCruce.longitud)
        return rangoDerecha;
    return rangoCruce;
}
*/

Rango encontrarRangoMasLargo(int arr[], int izquierda, int derecha, int menorPeso) {
    Rango resultado={0,0,0,menorPeso};
    // Caso Base
	if (izquierda==derecha){
		if(arr[izquierda]==menorPeso){
			resultado.inicio = izquierda + 1;
	        resultado.fin = izquierda + 1;
	        resultado.longitud = 1;
	    }
    	return resultado;
	}
	int medio=(izquierda+derecha)/2;
	// Necesito izquierda y derecha
	Rango RangoIzq=encontrarRangoMasLargo(arr,izquierda,medio,menorPeso);
	Rango RangoDer=encontrarRangoMasLargo(arr,medio+1,derecha,menorPeso);
	//Necesito ver el rango cruce
	Rango RangoCruce={0,0,0,menorPeso};
	if(arr[medio]==arr[medio+1] && arr[medio]==menorPeso){
		int inicio=medio,fin=medio+1;
		while(inicio>=izquierda && arr[inicio]==menorPeso){
			inicio--;
		}
		while(fin<=derecha && arr[fin]==menorPeso){
			fin++;
		}
		RangoCruce.inicio=inicio+2;
		RangoCruce.fin=fin;
		RangoCruce.longitud=fin-inicio-1;
	}
	//COMPARAR LOS 3 RANGOS
	//1 IZQUIERDA GANA
	if(RangoIzq.longitud>=RangoDer.longitud&&RangoIzq.longitud>=RangoCruce.longitud){
		return RangoIzq;
	}
	//2 CRUCE GANA
	if(RangoCruce.longitud>=RangoIzq.longitud&&RangoCruce.longitud>=RangoDer.longitud){
		return RangoCruce;
	}
	//3 DERECHA GANA
	return RangoDer;
	
}

int main() {
    int arr[N];
    
    // Leer datos
    leerDatos(arr);
    
    // Encontrar menor peso
    int menorPeso = encontrarMenorPeso(arr, 0, N-1);
    
    // Encontrar rango más largo con el menor peso
    Rango resultado = encontrarRangoMasLargo(arr, 0, N-1, menorPeso);
    
    // Imprimir resultado
    cout << "El menor peso fue de " << menorPeso << ". ";
    cout << "El rango de días en que lo obtuvo fue del " << resultado.inicio;
    cout << " al " << resultado.fin << "." << endl;
    
    return 0;
}
