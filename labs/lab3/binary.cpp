#include <bits/stdc++.h>
using namespace std;
int binarySearch(vector<int> a, int x){
    int low = 0, hight = a.size()-1;
    int mid = (low + hight);
    if (x == a[mid]) return mid;
    if (x > a[mid]) low = mid;
    else hight = mid;
    return -1;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int x;
    cin >> x;
    cout << binarySearch(a, x);
}
