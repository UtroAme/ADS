#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int low = 1, high = *max_element(a.begin(), a.end());
    int answer = high;

    while(low <= high){
        int mid = (low + high) / 2;
        long long flights = 0;

        for(int i = 0; i < n; i++){
            flights += (a[i] + (long long)mid - 1)/ mid;
        }
            if (flights <= k){
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
    }
    cout << answer << endl;
}
