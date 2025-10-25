#include <iostream>
#include <set>
using namespace std;
//я тупой

class Node{
    public:
    string data;
    Node* next;
    Node* prev;

    Node(){
        data = "";
        next = NULL;
        prev = NULL;
    }

    Node(string data){
        this-> data = data;
        this-> next = NULL;
        this-> prev = NULL;
    }
};


int main(){
    int n, cnt = 1;
    string s;
    cin >> n;

    Node *head = NULL, *tail = NULL;
    for(int i = 0; i < n; i++){
        cin >> s;
        Node* node = new Node(s);
        if(head == NULL) head = tail = node;
        else {
            if(s != tail->data) cnt++;
            tail-> next = node;
            node->prev = tail;
            tail = node;
        }
    }

    cout << "All in all: " << cnt << "\n" << "Students:\n";
    Node* cur = tail;
    while(cur != NULL){
        cout << cur->data << "\n";
        while (cur->prev != NULL && cur->data == cur->prev->data){
            cur = cur->prev;
        }
        cur = cur -> prev;
    }

    return 0;
}