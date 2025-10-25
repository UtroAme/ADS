#include <iostream>
#include <string>
using namespace std;

bool isVowel(char c){
    return (c == 'a' || c == 'o' || c == 'i' || c == 'e' || c == 'u');
}

bool cmp(char a, char b){
    bool ok1 = isVowel(a);
    bool ok2 = isVowel(b);

    if (ok1 != ok2) return ok1;
    return a<b;
}

//ручная сортировка с quicksort
void quickSort (string &s, int left, int right){
    if(left >= right) return;

    char pivot = s[(left + right)/2];
    int i = left, j = right;

    while (i <= j){
        while(cmp(s[i],pivot)) i++;
        while(cmp(pivot,s[j])) j--;

        if(i <= j){
            swap(s[i],s[j]);
            i++;
            j--;
        }
    }
    quickSort(s,left,j);
    quickSort(s,i,right);
}

int main(){
    int n;
    string s;

    cin >> n >> s;
    //sort(s.begin(),s.end(), cmp); #include <algorithm>
    //ручная сортировка с quicksort
    quickSort(s,0,s.length()-1);

    cout << s;
    return 0;
    

}