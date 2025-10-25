#include <iostream>
#include <deque>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t > 0){
        int n;
        cin >> n;

        deque<int> nums;

        for(int k = n; k >= 1; k--){
            nums.push_front(k);
            int r = k % nums.size(); //вычисляем кол-во сдвигов
            while (r--){
                nums.push_front(nums.back());
                nums.pop_back();
            }
        }
        for( int num:nums) cout << num << " ";
        cout << endl;

        t--;
        
    }
}

