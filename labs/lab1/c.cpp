#include <iostream>
#include <string>
using namespace std;

int sizeCheck(string s){
    string ans;
    for(int i = 0; i < s.size(); i ++){
        if(s[i] == '#'){
           ans.pop_back();             
        } else ans += s[i];
    }
    return ans.size();
}

int main(){
    string s, t;
    cin >> s >> t;
    int ans1, ans2;
    ans1 = sizeCheck(s);
    ans2 = sizeCheck(t);
    if(ans1 == ans2) cout << "Yes" ;
    else cout << "No";

    return 0;
}