#include <bits/stdc++.h>
using namespace std;
int lowerBound(vector<long long>& prefix, int x){
    int l = 0, r=prefix.size()-1;
    int ans = -1;
    while(l<=r){
        int mid = (l+r)/2;
        if(prefix[mid] >= x){
            ans = mid;
            r = mid - 1;
        } else {
            l = mid +1;
        }
    }
    return ans+1; 
}

int main() {
    int n,m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<long long> prefix(n);
    prefix[0] = a[0];
    for(int i = 1; i < n; i++){
        prefix[i]=prefix[i-1] +a[i];
    }

    for(int i = 0; i < m; i++){
        int x;
        cin >> x;
        cout << lowerBound(prefix,x) << "\n";
    }
}
