#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
    string str;
    cin >> str;

    if(str.empty()) {
        cout << "NO";
        return 0;
    }

    stack<char> st;
    st.push(str[0]);

    for (int i = 1; i < str.size(); i++){
        char current = str[i];
        if(!st.empty() && st.top() == current) st.pop();
        else st.push(current);
    }

    if  (st.empty()) cout << "YES";
    else cout << "NO";

    return 0;
} 
/*доразбирать*/
