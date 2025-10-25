#include <iostream>
#include <vector>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;

    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

void bt_insert(Node* &root,int val){
    if(root == nullptr){
        root = new Node(val);
        return;
    } else {
        if(val < root -> data) bt_insert(root-> left, val);
        else bt_insert(root->right,val);
    }
}

int cnt[5005], max_lvl = 0;
void sum_sum(Node* root, int lvl){
    if(root == nullptr) return;
    cnt[lvl] += root->data;
    sum_sum(root->left, lvl+1);
    sum_sum(root->right, lvl+1);
    max_lvl = max(max_lvl, lvl);
}

int main(){
    int n,x;
    Node* root = NULL;

    cin >> n;
    for(int i = 1; i <= n; i++) cin >> x, bt_insert(root,x);

    sum_sum(root, 0);

    cout << max_lvl +1 << '\n';
    for(int i = 0; i <= max_lvl; i++) cout << cnt[i] << ' ';
    return 0;
}