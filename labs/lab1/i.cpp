#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main(){
    int n, cnt;
    string str;
    cin >> n >> str;
    cnt = 0;

    //делим их по индексу(порядок выбора)
    queue<int> S, K;
    for (int i = 0; i < str.size(); i++){
        if(str[i] == 'S') S.push(i);
        else K.push(i);
    }

    //если индекс меньше значит голосовал раньше
    while(!S.empty() && !K.empty()){
        int idS = S.front(); S.pop();
        int idK = K.front(); K.pop();

        if(idS < idK) S.push(idS + n); //+n переносит в новый раунд
        else K.push(idK + n);
    }

    if(S.empty()) cout << "KATSURAGI";
    else cout << "SAKAYANAGI";

    return 0;
}