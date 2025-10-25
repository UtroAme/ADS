#include <iostream>
using namespace std;

class myQueue{
    private: 
    int* arr;
    int front;
    int size;
    int capacity;

    public:
    myQueue(int cap){
        capacity = cap;
        arr = new int[capacity];
        front = 0;
        size = 0;
    }

    //insert
    void enqueue(int x){
        if(size == capacity){
            cout << "Queue is full!" << endl;
            return;
        }
        int rear = (front + size) % capacity;
        arr[rear] = x;
        size++;
    }

    //remove
    int dequeue(){
        if(size == 0){
            cout << "Queue is empty!" << endl;
            return -1;
        }
        int res = arr[front];
        front = (front + 1) % capacity;
        size--;
        return res;
    }

    // Get the rear element
    int getRear(){
        if(size == 0) return -1;
        int rear = (front + size - 1) % capacity;
        return arr[rear];
    }

    int getFront(){
        if(size == 0) return -1;
        return arr[front];
    }
};

int main() {
    myQueue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout << q.getFront() << " " << q.getRear() << endl;
    q.dequeue();
    cout << q.getFront() << " " << q.getRear() << endl;
    q.enqueue(40);
    cout << q.getFront() << " " << q.getRear() << endl;
    return 0;
}