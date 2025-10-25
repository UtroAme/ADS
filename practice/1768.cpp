// https://leetcode.com/problems/merge-strings-alternately/description/
#include "iostream"
#include "string"
using namespace std;

string MergeString(const string& word1, const string& word2){
    string word;
    word.reserve(word1.size() + word2.size()); //резервируем место что бы не заполнить мусором

    size_t i = 0, j = 0; 
    while (i < word1.size() || j < word2.size()){
        if (i < word1.size()) word += word1[i++];
        if (j < word2.size()) word += word2[j++]; 
    }
    return word;
}

int main(){
    string word1, word2;
    cin >> word1 >> word2;
    cout << MergeString(word1, word2) << endl;
    return 0;
}