#include <iostream>
using namespace std;

class Node {
    public: 
    int data;
    Node *next;
    Node *prev;

    Node() {
        data = 0;
        next = NULL;
        prev = NULL;
    }
    Node(int data){
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

    void insertFront(int data){
     Node *newNode = new Node(data);
     if (head != NULL){
        newNode -> next = head;
        head->prev = newNode;
     } else {
        tail = newNode;
     }
     head = newNode;
     }   


    void insertBack (int data){
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
    int n, temp, num;
    DoublyLinkedList dll;
    temp = 0;
    cin >> n;
    while(n > 0){
        cin >> num;
        if(temp % 2 == 0){
            dll.insertBack(num);
        }
        temp++;
        n--;
    }

    dll.printList();
}