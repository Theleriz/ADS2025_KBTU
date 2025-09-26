#include <iostream>
using namespace std;


template <typename T>
class Node{
    public:
    T data;
    Node * next;

    Node(T data){
        this->data;
        this-> next = NULL;
    }
};


template <typename T>
class Stack{
    public:
    Node<T> *top;
    int size = 0;

    void push(T data){
        Node *node = new Node(data);
        node->next = top;
        top = node;
        size++;
    }
    
    void pop(){
        if(top != NULL){
            top = node->next;
            size--;
        }
    }
    
    int size(){
        return this->size;
    }

    bool empty(){
        return (this->size == 0);
    }
};

template <typename T>
class list{
    public:
    Node *head;

    list(){
        this->head = NULL;
    }

    void push(T data){
        Node *node = new Node(data);
        
    }

};