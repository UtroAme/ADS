#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for(int i = 0; i < n1; i++){
        L[i] = arr[left+i];
    } 
    for(int j = 0; j < n2; j++){
        R[j] = arr[mid+1+j];
    }

    int i = 0 , j = 0;
    int k = left;

    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    //copy the elements if its remain
    while (i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int left, int right){
    if (left >= right) return;

    int mid = left + (right - left)/2;
    mergeSort(arr, left, mid); //devide the arr to subarray
    mergeSort(arr,mid+1,right);
    merge(arr,left,mid,right); // wher arr size is 1 we merge it
}

int main(){
    int n, m, x;
    cin >> n;

    vector<int> arr;
    for(int i = 0; i < n; i++){
        cin >> x;
        arr.push_back(x);
    }
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> x;
        arr.push_back(x);
    }

    mergeSort(arr,0, n+m-1);
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
    
    return 0;

}