#include <iostream>
#include <deque>
using namespace std;

int main(){
    char c; int a;
    deque<int> dq;
    while(true){
        cin >> c;
        if(c == '+'){ // если + добовляем спереди
            cin >> a;
            dq.push_front(a);
        } 
        else if(c == '-'){ // если - добовляем сзади
            cin >> a;
            dq.push_back(a);
        }
        else if (c == '*'){
            if(dq.size() == 0) cout << "error\n"; //проверка пустой ли он
            else{
                cout << dq.front() + dq.back() << '\n';
                 if(dq.size() >= 2){ 
                    dq.pop_front(); dq.pop_back();
                } else dq.pop_front();
            }
        }
        else break;
    }
    return 0;
}