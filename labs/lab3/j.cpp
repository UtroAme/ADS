#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long h;
    cin >> n >> h;
    vector<int> a(n);
    int mx = 0;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    
    long long low = 1, high = mx;
    long long ans = high;
    while(low <= high){
        long long mid = (low + high) /2;
        long long totalHours = 0;

        for (int i  = 0; i < n; i++){
            totalHours += (a[i] + mid - 1)/ mid;
        }

        if(totalHours<= h){
            ans = mid;
            high = mid-1;
        } else {
            low = mid +1;
        }
    }
    cout << ans << endl;
}