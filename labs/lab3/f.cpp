#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, x, q;
    cin >> n;

    vector<int> a(n); //power of enemys
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    sort(a.begin(),a.end());

    vector<long long> prefix(n);
    prefix[0] = a[0];
    for(int i = 1; i < n; i++){
        prefix[i]=prefix[i-1] +a[i];
    }

    cin >> q;
    for(int i = 1; i <= q; i++){
        cin >> x;
        int l = -1, r = n;
        while(l+1 < r){
            int mid = (l+r)/2;
            if(a[mid] <= x) l = mid;
            else r = mid;
        }
        if(l == -1) cout << 0 << " " << 0 << "\n"; 
        else cout << l+1 << " " << prefix[l] << "\n" ;
    }
    return 0;
}