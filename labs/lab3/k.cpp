#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<long long> prefix(n+1,0);
    for(int i = 0; i < n; i++){
        prefix[i+1] = prefix[i] + a[i];
    }

    int minLenght = INT_MAX;
    for(int i = 0; i<n; i++){
        long long target = prefix[i+1]-k;

        int low = 0, high = i+1;
        int best_j = -1;

        while (low <= high){
            int mid = (low+high)/2;
            if(prefix[mid] <= target){
                best_j = mid;
                low = mid +1;
            } else {
                high = mid -1;
            }
        }
        if (best_j != -1){
            minLenght = min(minLenght, i - best_j+1);
        }
    }
    cout << minLenght << endl;
}
//idk 