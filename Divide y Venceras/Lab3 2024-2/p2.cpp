#include <iostream>
#include <fstream>
using namespace std;

void leerDatos(int **&matriz, int &n) {

  ifstream archivo("p2.txt");

  if (!archivo) {
    cerr << "Error al abrir el archivo." << endl;
    return;
  }

  archivo >> n;
  matriz = new int*[n];
  for (int i = 0; i < n; i++) {
    matriz[i] = new int[n];
    for (int j = 0; j < n; j++) {
      archivo >> matriz[i][j];
    }
  }

  archivo.close();
}

int hallarMayorDeFila(int *arr, int ini, int fin) {

  // caso base: cuando el arreglo tiene un solo elemento
  if (ini == fin) {
    return arr[ini];
  }

  // caso recursivo: dividir el arreglo en dos mitades
  int mid = (ini + fin) / 2;

  // cuando se encuentra el mayor en la mitad
  if (arr[mid-1] < arr[mid] && arr[mid+1] < arr[mid])
    return arr[mid];

  // cuando los valores estan en orden ascendente
  if (arr[mid-1] <= arr[mid] && arr[mid] <= arr[mid+1]) {
    return hallarMayorDeFila(arr, mid + 1, fin);
  }
  // cuando los valores estan en orden descendente
  else {
    return hallarMayorDeFila(arr, ini, mid);
  }
}

int hallarMayor(int **matriz, int n) {

  int mayor = 0;

  for (int i=0; i<n; i++) {

    int mayorFila = hallarMayorDeFila(matriz[i], 0, n-1);

    cout << "El mayor elemento de la fila " << i + 1 << " es: " << mayorFila << endl;

    if (mayorFila > mayor) {
      mayor = mayorFila;
    }
  }

  return mayor;
}

int hallarCantidadCeros(int *arr, int ini, int fin) {

  // caso base: cuando el arreglo tiene un solo elemento
  if (ini == fin) {
    return arr[ini] == 0 ? 1 : 0; // Si el elemento es 0, no cuenta como estrato
  }

  // caso recursivo: dividir el arreglo en dos mitades
  int mid = (ini + fin) / 2;

  if (arr[mid] == 0) {

    // cuando los valores estan en orden ascendente
    if (arr[ini] <= arr[mid] && arr[mid] <= arr[fin]) {
      return (mid - ini + 1) + hallarCantidadCeros(arr, mid+1, fin);
    }
    // cuando los valores estan en orden descendente
    else {
      return (fin - mid) + hallarCantidadCeros(arr, ini, mid);
    }
  }
  else {
    if (arr[mid-1] == arr[mid] && arr[mid] == arr[mid+1]) {
      if (arr[ini] <= arr[mid] && arr[mid] <= arr[fin]) {
        return hallarCantidadCeros(arr, ini, mid);
      }
      else {
        return hallarCantidadCeros(arr, mid+1, fin);
      }
    }
    else {
      if (arr[ini] == 0 && arr[fin] > 0)
        return hallarCantidadCeros(arr, ini, mid);
      else
        return hallarCantidadCeros(arr, mid+1, fin);
    }
   
  }
}

int hallarMayorCantidadEstratos(int **matriz, int n) {

  int mayor = 0;

  for (int i=0; i<n; i++) {

    int cantidadEstratos = n - hallarCantidadCeros(matriz[i], 0, n-1);

    cout << "La cantidad de estratos de la fila " << i + 1 << " es: " << cantidadEstratos << endl;

    if (cantidadEstratos > mayor) {
      mayor = cantidadEstratos;
    }
  }

  for (int i=0; i<n; i++) {
    int cantidadEstratos = n - hallarCantidadCeros(matriz[i], 0, n-1);

    if (cantidadEstratos == mayor) {
      cout << "La fila " << i + 1 << " tiene la mayor cantidad de estratos: " << mayor << endl;
    }

  }

  return mayor;
}

int main() {

  int **matriz;
  int n;

  leerDatos(matriz, n);

  // int mayor = hallarMayor(matriz, n);
  // cout << "El mayor elemento de la matriz es: " << mayor << endl;

  int mayorCantidadEstratos = hallarMayorCantidadEstratos(matriz, n);
  cout << "La mayor cantidad de estratos en una fila es: " << mayorCantidadEstratos << endl;



  return 0;
}