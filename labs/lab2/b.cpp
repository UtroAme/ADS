

#include <iostream>
#include <vector>
using namespace std;

class Node {
    public: 
    string data;
    Node *next;
    Node *prev;

    Node() {
        data = "";
        next = NULL;
        prev = NULL;
    }
    Node(string data){
        this -> data = data;
        this -> next = NULL;
        this -> prev = NULL;
    }
};

class DoublyLinkedList {
    public:
    Node *head;
    Node *tail;

    DoublyLinkedList(){
        head = NULL;
        tail = NULL;
    }

    void insertFront(string data){
     Node *newNode = new Node(data);
     if (head != NULL){
        newNode -> next = head;
        head->prev = newNode;
     } else {
        tail = newNode;
     }
     head = newNode;
     }   


    void insertBack (string data){
        Node *newNode = new Node(data);
        if(tail != NULL ){
            tail -> next = newNode;
            newNode->prev = tail;
        } else {
            head = newNode;
        }
        tail = newNode;
    }
    void popFront (){
        Node *temp = head;
        head = head -> next;
        if (head != NULL){
            head->prev = NULL;
        } else {
            tail = NULL;
        }
        delete temp;
    }
    void printList(){
        Node *temp = head;
        while(temp != NULL){
            cout << temp -> data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main(){
    int n,k;
    string s;
    cin >> n >> k;
    DoublyLinkedList dll;
    while(n != 0){
        cin >> s;
        dll.insertBack(s);
        n--;
    }
    while(k != 0){
        dll.insertBack(dll.head->data);
        dll.popFront();
        k--;
    }
    dll.printList();
}

