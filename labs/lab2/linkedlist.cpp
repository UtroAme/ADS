#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

class LinkedList{
    private:
    Node *head;
    int size;

    public:
    LinkedList() : head(nullptr), size(0) {}

    //add top p position
    Node* insert(int x, int p){
        Node* newNode = new Node(x);

        if(p == 0){
            newNode->next = head;
            head = newNode;
        } else {
            Node* curr = head;
            for(int i = 0; i < p-1; i++){
                curr = curr -> next;
            }
            newNode-> next = curr -> next;
            curr->next = newNode;
        }

        size++;
        return head;
    }

    //delete at p position
    Node* remove(int p){
        if(head == nullptr) return head;

        if(p==0){
            Node* temp = head;
            head=head->next;
            delete temp;
        } else {
            Node* curr = head;
            for(int i = 0; i < p-1; i++){
                curr = curr -> next;
            }
            Node* temp = curr -> next;
            curr->next = temp->next;
            delete temp;
        }
        size --;
        return head;
    }

    //print the list
    void print(){
        if(head == nullptr){
            cout << -1 << endl;
            return;
        }

        Node* curr = head;
        while(curr != nullptr){
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }

    //swap some element
    Node* replace(int p1, int p2){
        if(p1 == p2) return head;

        Node* prev1 = nullptr;
        Node* node1 = head;

        for(int i = 0; i < p1; i++){
            prev1 = node1;
            node1 = node1->next;
        }

        if(prev1 == nullptr){
            head = head->next;
        } else {
            prev1->next = node1->next;
        }

        if(p2 == 0){
            node1->next = head;
            head = node1;
        } else {
            Node* curr = head;
            for(int i = 0; i < p2-1; i++){
                curr = curr->next;
            }
            node1->next = curr->next;
            curr -> next = node1;
        }
        return head;
    }

    Node* reverse(){
        Node* prev = nullptr;
        Node* curr = head;
        Node* next = nullptr;

        while(curr != nullptr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        head = prev;
        return head;
    }

    Node* cyclic_left(int x){
        if (head == nullptr)
    }
}