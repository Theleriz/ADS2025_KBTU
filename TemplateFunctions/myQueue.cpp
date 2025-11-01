#include <iostream>

template<typename T>
class Node {
public:
    T data;
    Node* next;
    
    Node() {
        this->next = nullptr;
    }
    Node(T data) {
        this->data = data;
        next = nullptr;
    }
};

template<typename T>
class Queue {
public:
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;
    int size = 0;

    void push_back(T data) {
        Node<T>* node = new Node<T>(data);
        if (head == nullptr) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
        size++;
    }

    void pop() {
        if (head == nullptr) return; 
        Node<T>* temp = head;
        head = head->next;
        delete temp;
        size--;
        if (head == nullptr) tail = nullptr;
    }

    T top() {
        if (head == nullptr) throw runtime_error("Queue is empty");
        return head->data;
    }
};

