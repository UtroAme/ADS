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

int sum = 0;

void travel(Node* &cur){
    if(cur == NULL) return;
    else{
        if(cur->left != NULL && cur->right != NULL) sum++;
        travel(cur->left);
        travel(cur->right);
    }
}


int main(){
    int n, x;
    Node* root = NULL;

    cin >> n;

    for(int i = 0; i < n; i++)cin >> x, bt_insert(root,x);

    travel(root);
    cout <<sum;
    return 0;
}