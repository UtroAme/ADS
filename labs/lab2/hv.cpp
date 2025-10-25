#include <bits/stdc++.h>
using namespace std;

int main(){
    int x;
    vector<int> nums;
    while(cin >> x){
        nums.push_back(x);
    }

    sort(nums.begin(), nums.end());
    for(int i : nums){
        cout << i << " ";
    }
    cout << nums.size() << endl;
    return 0;
}