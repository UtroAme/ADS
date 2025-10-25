#include <iostream>
using namespace std;
//task F
bool isPrime(int x){
    if(x<2) return false;
    for(int i = 2; i*i <= x; i++){
        if(x%i == 0) return false;
    }
    return true;
}

int main(){
    int n, cnt = 0;
    cin >> n;

    for(int i = 2; i <= 10000; i++){
        if(isPrime(i)) cnt++;
        if(cnt == n){
            cout << i;
            return 0;
        }
    }

    return 0;
}