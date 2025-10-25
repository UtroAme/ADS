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
    int n;
    cin >> n;

    int* points = new int[n];
    for(int i = 0; i < n; i++){
        cin >> points[i];
    }

    quicksort(points,0,n-1);

    int minDiff = 200000000;
    for(int i = 1; i < n; i++){
        int diff = points[i] - points[i-1];
        if(diff < minDiff) {
            minDiff = diff;
        }
    }

    for (int i = 1; i < n; i++) {
        if (points[i] - points[i - 1] == minDiff) {
            cout << points[i - 1] << " " << points[i] << " ";
        }
    }

    cout << endl;
    delete[] points;
    return 0;
}