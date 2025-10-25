#include <iostream>
#include <algorithm>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;

   Node(int data){
    this-> data = data;
    left = NULL;
    right = NULL;
   }
};

Node* build(int a[], int l , int r){
    if(l > r) return NULL;
    int mid = (l+r)/2;
    Node* node = new Node(a[mid]);
    node->left = build(a,l,mid-1);
    node->right = build(a,mid+1, r);
    return node;
}

void print(Node* root){
    if(root == NULL) return;
    cout << root->data << ' ';
    print(root->left);
    print(root->right);
}


int main(){
    int n = 1,t,a[33000];
    cin >> t;

    for(int i = 1; i <= t; i++) n *= 2; n--;
    
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n);

    print(build(a,1,n));

    return 0;
}