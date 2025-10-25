#include <bits/stdc++.h>
using namespace std;
bool binarySearch(vector<int> a, int x){
    int low = 0, hight = a.size()-1;
    while(low <= hight){
    int mid = (low + hight)/2;
    if (x == a[mid]) return true;
    if (x > a[mid]) low = mid+1;
    else hight = mid-1;
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int x;
    cin >> x;

    if (binarySearch(a, x)) cout << "Yes";
    else cout << "No";
}
