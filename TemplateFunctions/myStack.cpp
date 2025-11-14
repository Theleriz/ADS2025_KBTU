#include <iostream>
using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node* next;
    
    Node() {
        this->next = nullptr;
    }
    Node(int data) {
        this->data = data;
        next = nullptr;
    }
};

template <typename T>
class Stack{
public:
    Node *top;
    int size = 0;

    Stack(){
        this->top = nullptr;
    }

    bool empty() {
        return (this->size) == 0;
    }

    void push_back(int data){
        Node *node = new Node(data);
        node->next = top;
        top = node;
        size++;
    }

    void pop(int data){
        if((this->size) == 0) return;
        else {
            Node *copy = top;
            top = top->next;
            delete copy;
        }
    }

    int size(){ 
        return this->size;
    }
};
