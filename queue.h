#ifndef queue_h
#define queue_h

#include "queue.h"
#include <string>
#include <iostream>

#include "node.h"

using namespace std;

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue();
    ~Queue();
    bool isEmpty() const;
    void enqueue(string data);
    std::string dequeue();
    void display();
};





void Queue::enqueue(std::string data) {
    Node* newNode = new Node(data);
    if (rear == nullptr) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

string Queue::dequeue() {
    if (isEmpty()) {
        return "";
    }

    Node* temp = front;
    string value = temp->data;
    front = front->next;
    delete temp;

    if (front == nullptr) {
        rear = nullptr;
    }

    return value;
}

void Queue::display() {
    Node* temp = front;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Queue::Queue() : front(nullptr), rear(nullptr) {}

Queue::~Queue() {
    while (!isEmpty()) {
        dequeue();
    }
}

bool Queue::isEmpty() const{ 
    return front == nullptr;
    
}



#endif // QUEUE_H