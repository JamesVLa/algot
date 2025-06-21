#include <iostream>

using namespace std;

struct Resultado {
    int suma;
    int inicio;
    int fin;
};

Resultado encontrarSumaMinimaCruza(int arr[], int izquierda, int medio, int derecha) {
    int sumaIzq = 0;
    int minSumaIzq = arr[medio];
    int inicioIzq = medio;
    for (int i = medio; i >= izquierda; i--) {
        sumaIzq += arr[i];
        if (sumaIzq < minSumaIzq) {
            minSumaIzq = sumaIzq;
            inicioIzq = i;
        }
    }
    
    int sumaDer = 0;
    int minSumaDer = arr[medio + 1];
    int finDer = medio + 1;
    for (int i = medio + 1; i <= derecha; i++) {
        sumaDer += arr[i];
        if (sumaDer < minSumaDer) {
            minSumaDer = sumaDer;
            finDer = i;
        }
    }
    
    return {minSumaIzq + minSumaDer, inicioIzq, finDer};
}

Resultado encontrarSumaMinima(int arr[], int izquierda, int derecha) {
    if (izquierda == derecha) {
        return {arr[izquierda], izquierda, derecha};
    }
    
    int medio = (izquierda + derecha) / 2;
    
    Resultado resIzq = encontrarSumaMinima(arr, izquierda, medio);
    Resultado resDer = encontrarSumaMinima(arr, medio + 1, derecha);
    Resultado resCruza = encontrarSumaMinimaCruza(arr, izquierda, medio, derecha);
    
    if (resIzq.suma <= resDer.suma && resIzq.suma <= resCruza.suma) {
        return resIzq;
    } else if (resDer.suma <= resIzq.suma && resDer.suma <= resCruza.suma) {
        return resDer;
    } else {
        return resCruza;
    }
}

int main() {
    int n;
    cout << "Ingrese el numero de paquetes: ";
    cin >> n;
    int arr[100];
    cout << "Ingrese las marcas de los paquetes:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    Resultado res = encontrarSumaMinima(arr, 0, n-1);
    cout << "Acumulacion negativa mas alta: " << res.suma << endl;
    cout << "Paquetes: ";
    for (int i = res.inicio; i <= res.fin; i++) {
        cout << i + 1; // 1-based
        if (i < res.fin) cout << ", ";
    }
    cout << endl;
    
    return 0;
}
