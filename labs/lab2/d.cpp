#include <iostream>
#include <map>
#include <set>
using namespace std;

// Node class to represent a node of the linked list
class Node {
    public:
    int data;
    Node* next;


    // default constructor
    Node(){
        data = 0;
        next = NULL;
    }

    // parameterised constructor
    Node(int data){
        this-> data = data;
        this-> next = NULL;
    }
};

class linkedList {
    public:
    Node* head;
    Node* tail;

    linkedList(){
        head = tail = NULL;
    }

    void insertBack(int data){
        Node* node = new Node(data);
        if(head == NULL) head = tail = node;
        else {
            tail->next = node;
            tail = node;
        }
    }
};

int main() {
    int n, x;
    cin >> n;

    linkedList list;

    for( int i = 0; i < n; i++){
        cin >> x;
        list.insertBack(x);
    }

    map<int,int> freq;
    Node* cur = list.head;
    while (cur != NULL){
        freq[cur->data]++;
        cur = cur->next;
    }

    int mx = 0;
    for (auto &p : freq) mx = max(mx, p.second);

    set<int> modes;
    for(auto &p : freq){
        if (p.second == mx) modes.insert(p.first);
    }

    for (auto it = modes.rbegin(); it != modes.rend(); it++) cout << *it << " ";
    cout << endl;
    return 0;
}
