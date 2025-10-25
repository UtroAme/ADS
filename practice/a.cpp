#include "iostream"
#include "vector"
using namespace std;

int sum(const vector<int>& nums, int index = 0){
    if (index >= nums.size()) return 0;
    return nums[index] + sum(nums, index + 1);
}
//const vector<int> не копирует вектор сохроняет память
//index отслеживает позицию

int main(){
    vector<int> nums;
    int n;
    cin >> n;
    for ( int i = 0; i < n; i++){
        int a;
        cin >> a;
        nums.push_back(a);
    }
    cout << sum(nums) << endl;
    return 0;
}