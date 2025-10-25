#include <iostream>
#include <deque>
using namespace std;

int main(){
    deque<int> B, N;
    int a, cnt;
    cnt = 0;
    for(int i = 0; i < 10; i ++){
        cin >> a;
        if(i < 5) B.push_back(a);
        else N.push_back(a);
    }
    while(cnt < 1000000 && !B.empty() && !N.empty()){
        cnt++;

        int b = B.front(), n = N.front();
        B.pop_front(); N.pop_front();

        if ((b == 0 && n == 9) || (b>n && (b != 9 || n != 0))){
            B.push_back(b);
            B.push_back(n);
        } else {
            N.push_back(b);
            N.push_back(n);
        }
    }
    if(cnt >= 1000000) cout << "blin nuchya";
    else if(B.empty()) cout << "Nursik" << ' ' << cnt;
    else cout << "Boris" << ' ' << cnt;
    return 0;
}