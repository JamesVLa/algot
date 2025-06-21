#include <iostream>
using namespace std;

const int MAX_N = 7; // Columnas fijas

struct ResultadoMaximo {
    int potencia;
    int columna;
};

int encontrarMaximoColumna(int arr[][MAX_N], int izquierda, int derecha, int j) {
    if (izquierda == derecha) {
        return arr[izquierda][j];
    }
    int medio = (izquierda + derecha) / 2;
    int maxIzquierda = encontrarMaximoColumna(arr, izquierda, medio, j);
    int maxDerecha = encontrarMaximoColumna(arr, medio + 1, derecha, j);
    return max(maxIzquierda, maxDerecha);
}

ResultadoMaximo encontrarPotenciaYColumna(int arr[][MAX_N], int n, int m) {
    ResultadoMaximo resultado = {0, -1};
    for (int j = 0; j < n; j++) {
        int maxColumna = encontrarMaximoColumna(arr, 0, m-1, j);
        if (maxColumna > resultado.potencia) {
            resultado.potencia = maxColumna;
            resultado.columna = j;
        }
    }
    return resultado;
}

int encontrarFilaMaxima(int arr[][MAX_N], int izquierda, int derecha, int col, int potencia) {
    if (izquierda == derecha) {
        if (arr[izquierda][col] == potencia) {
            return izquierda;
        }
        return -1;
    }
    int medio = (izquierda + derecha) / 2;
    int filaIzquierda = encontrarFilaMaxima(arr, izquierda, medio, col, potencia);
    if (filaIzquierda != -1) {
        return filaIzquierda;
    }
    return encontrarFilaMaxima(arr, medio + 1, derecha, col, potencia);
}

int main() {
    int n, m;
    cout << "Ingrese n y m: ";
    cin >> n >> m;
    int arr[100][MAX_N];
    cout << "Ingrese la matriz:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    cout << "Matriz leída:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    
    ResultadoMaximo res = encontrarPotenciaYColumna(arr, n, m);
    cout << "Potencia maxima: " << res.potencia << ", Columna: " << res.columna << endl;
    
    int fila = encontrarFilaMaxima(arr, 0, m-1, res.columna, res.potencia);
    cout << "Fila del impacto maximo: " << fila << endl;
    
    return 0;
}
