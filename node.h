#ifndef node_h
#define node_h

#include <iostream>
using namespace std;

class Node {
public:
    string data;
    Node* next;

    Node() : data(""), next(nullptr) {}
    Node(string value) : data(value), next(nullptr) {}
};

#endif // NODE_H
