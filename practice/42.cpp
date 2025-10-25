#include "iostream"
#include "vector"
using namespace std;

int len(const vector<int>& a, int index = 0){
    if ( index >= a.size()) return 0;
    return 1 + len(a, index + 1);
}

int main(){
    vector<int> cars = {1, 2, 3, 23, 21};
    cout << len(cars) << endl;
    return 0;
}