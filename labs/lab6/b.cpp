#include <iostream>
using namespace std;

void quicksort(int arr[], int left, int right){
    if (left >= right) return;

    int pivot = arr[(left + right)/2];
    int i = left, j = right;

    while (i <= j){
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;

        if(i <= j){
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    quicksort(arr, left, j);
    quicksort(arr, i, right);
}

int main(){
    int n,m;
    cin >> n >> m;

    int* arr1 = new int[n];
    int* arr2 = new int[m];

    for(int i = 0; i < n; i++){
        cin >> arr1[i];
    }

    for(int i = 0; i < m; i++){
        cin >> arr2[i];
    }

    quicksort(arr1, 0, n-1);
    quicksort(arr2, 0, m-1);

    int i = 0, j = 0;
    while (i < n && j < m){
        if(arr1[i] == arr2[j]){
            cout << arr1[i] << " ";
            i++;
            j++;
        } else if (arr1[i] < arr2[j]){
            i++;
        } else {
            j++;
        }
    }

    delete[] arr1;
    delete[] arr2;
    return 0;
}