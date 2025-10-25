#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,q;
    cin >> n >> q;
    int arr[n];

    for(int i = 0; i< n; i++){
        cin >> arr[i];
    }

    for(int i = 0; i<q; i++){
        int l1,r1, l2,r2;
        cin >> l1 >> r1 >> l2 >> r2;

        int cnt = 0;
        for(int k = 0; k < n;k++){
            if((l1 <= arr[k] && arr[k] <= r1) || (l2 <= arr[k] && arr[k] <= r2)) cnt++;
        }
        cout << cnt << "\n";
    }
}