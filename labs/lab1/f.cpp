#include <iostream>
#include <vector>
using namespace std;
/*http://e-maxx.ru/algo/eratosthenes_sieve Решето Эратосфена*/
int n, cnt;
vector<bool> prime(100005, 1);

int main(){
    
    cin >> n;
    
    prime[0] = prime[1] = 0;
    
    for(int i = 2; i <= 100000; i++){
        if(prime[i])
            if(i * 1ll * i <= 100000)
                for(int j = i * i; j <= 100000; j += i)
                    prime[j] = 0;
    }
    
    for(int i = 2; i <= 100000; i++){
        if(prime[i]) cnt++;
        if(cnt == n){
            cout << i;
            return 0;
        }
    }
    
    return 0;
}