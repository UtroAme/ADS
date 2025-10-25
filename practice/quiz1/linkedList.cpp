#include <bits./stdc++.h>
using namespace std;
//basucly use Node

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data= data;
        this->next = NULL;
    }
};

//Traversal linked list
void traverseList(Node* head){
    while(head != NULL){
        cout << head->data;
        if(head->next != NULL) cout << "->";

        head = head->next;
    }
    cout << endl;
}

//Insertion at begin
void insertAtFront(Node*& head, int x){ //&ссылка на лист
    Node* newNode = new Node(x);
    newNode->next = head;
    head = newNode;
}

//insertion at the end
void insertAtEnd(Node*& head, int x){
    Node* newNode = new Node(x);
    if(head == NULL){ //chek if is NULL
         head = newNode;
         return;
    }

    Node* last = head;
    while(last->next != NULL) last = last->next;

    last-> next = newNode;
}

//insert at specific position
void insertPos(Node*& head, int pos, int x){
    if(pos<1) return;
    if(pos == 1){
        Node* newNode = new Node(x);
        newNode-> next = head;
        head = newNode;
        return;
    }

    Node *curr = head;
    for(int i = 1; i <pos-1 && curr != NULL; i++){
        curr = curr -> next;
    }
    if(curr == NULL) return; //if pos > size

    Node *newNode = new Node(x);
    newNode-> next = curr->next;
    curr -> next = newNode;
}

//delete at begin
void deleteHead(Node*& head){
    if(head == NULL) return;
    Node* temp = head;
    head = head->next;
    temp->next = NULL;
    delete temp;
    return;
}

//delete last
void deleteLast(Node*& head){
    if (head == NULL) return;

    if(head->next == NULL){
        delete head;
        return;
    }

    Node *secondLast = head;
    while (secondLast->next->next != NULL){
        secondLast= secondLast->next;
    }
    delete secondLast->next;
    secondLast->next = NULL;
}

//delete at pos
void deletePos(Node*& head, int pos){
    Node* temp = head;

    if(pos == 1){
        head = temp->next;
        delete temp;
        return;
    }

    Node* prev = NULL;
    for(int i = 1; i < pos; i++){
        prev = temp;
        temp = temp->next;
    }

    prev->next = temp->next;
    delete temp;
}

//modify 




int main(){
    //creating nodes
    Node* head = new Node(10); //create a new node as a head

    head->next = new Node(20); // link the second node

    head->next->next = new Node(30); // link the third node

    head->next->next->next = new Node(40);

    //while(head != NULL){ // printing out list
    //    cout << head-> data << " ";
    //    head = head-> next;
   //}

   int x =1;
   insertAtEnd(head, x);
   insertPos(head, 3, 23);
   deleteHead(head);
   deleteLast(head);
   deletePos(head, 2);
   traverseList(head);
}
