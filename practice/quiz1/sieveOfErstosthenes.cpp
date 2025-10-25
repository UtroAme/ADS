#include <bits./stdc++.h>
using namespace std;
//prime num O(n*sqrt(n)) time and O(1) space

vector<int> sieve(int n){
    vector<bool> prime(n+1, true);
    for(int p = 2; p * p<= n; p++){
        if(prime[p] == true){
            for(int i = p*p; i <=n; i+=p) prime[i] = false;
        }
    }

    vector<int> res;
    for(int p=2; p <= n; p++){
        if (prime[p]){
            res.push_back(p);
        }
    }
    return res;
}

int main(){
    int n;
    cin >> n;
    vector<int> res = sieve(n);
    for(auto ele : res){
        cout << ele << " ";
    }
    return 0;
}