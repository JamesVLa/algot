#include <iostream>
#include <climits>
using namespace std;

void merge(int *arr, int ini, int mid, int end) {

	int p=0,q=0;
	int left_arr_len = mid - ini + 1;
	int right_arr_len = end - mid;
	int left_array[left_arr_len + 1];
	int right_array[right_arr_len + 1];

	for (int i=ini; i<=mid; i++)
		left_array[i-ini] = arr[i];
	left_array[left_arr_len] = INT_MAX;

	for (int i=mid+1; i<=end; i++)
		right_array[i-mid-1] = arr[i];
	right_array[right_arr_len] = INT_MAX;

	for (int m= ini; m<= end; m++)
		if (left_array[p] < right_array[q])
			arr[m] = left_array[p++];
		else
			arr[m] = right_array[q++];

}

void merge_sort(int *arr, int ini, int end){
	if (ini == end) return;
	int mid = (ini + end) / 2;
	merge_sort(arr, ini, mid);
	merge_sort(arr, mid + 1, end);
	merge(arr, ini, mid, end); 
}

int hallarNumero(int *arr, int n) {
  int ant = -1;
  int cont = 1;
  for (int i = 0; i < n; i++) {
    
    if (arr[i] == ant) {
      cont++;
      if (cont == 3) {
        return arr[i];
      }
    } else {
      cont = 1;
    }
    ant = arr[i];
  }
  return -1; // Ningún número se repite 3 veces
}

int main(){
	int arr[] = {01, 06, 03, 04, 05, 06, 03, 07, 05, 04, 03, 01, 07};
	int n = 13;

	merge_sort(arr, 0, n-1);

  int numero = hallarNumero(arr, n);

  cout << "El número que se repite 3 veces es: ";
  if (numero != -1) {
    cout << numero << endl;
  } else {
    cout << "Ningún número se repite 3 veces." << endl;
  }

	return 0;
}