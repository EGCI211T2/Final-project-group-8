#ifndef stack_h
#define stack_h

#include <iostream>

using namespace std;
class Stack {
private:
    std::string* items;
    int top;
    int maxSize;

public:
    Stack(int size);
    ~Stack();
    bool isEmpty();
    bool isFull();
    int  size();
    void push(string data);
    string pop();
};


Stack::Stack(int size) : top(-1), maxSize(size) {
    items = new string[size];
}

int Stack::size()
{
	return maxSize;
}

Stack::~Stack() {
    delete[] items;
}

bool Stack::isEmpty() {
    return top == -1;
}

bool Stack::isFull() {
    return top == maxSize - 1;
}

void Stack::push(std::string data) {
    if (!isFull()) {
        items[++top] = data;
    } else {
        cout << "Stack Overflow" << endl;
    }
}

string Stack::pop() {
    if (!isEmpty()) {
        return items[top--];
    } else {
        cout << "Stack Underflow" << endl;
        return "";
    }
}


#endif // STACK_H