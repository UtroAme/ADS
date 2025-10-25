#include "iostream"
#include "vector"
#include "climits"  // for INT_MAX
#include "cmath"
using namespace std;

int FindClothestNum (vector<int>& nums){
    int mini = INT_MAX; // use 'mini' bc min is algorithm library function

    for (auto i : nums){
        int absI = abs(i); //for reduce abs
        int absMini = abs(mini);
        if(absI < absMini){
            mini = i;
        } else if ( absI == absMini && i > mini){
            mini = i;
        }
    }
    return mini;
}

int main(){
    int n;
    cin >> n;
    
    vector<int> nums;
    for (int i = 0; i < n; i++){
        int a;
        cin >> a;
        nums.push_back(a);
    }
    cout <<  FindClothestNum(nums) << endl;
    return 0;
}