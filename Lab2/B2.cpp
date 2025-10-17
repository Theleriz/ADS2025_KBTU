#include <iostream>
#include <string>
using namespace std;

class Node {
    public:
    string data;
    Node *next, *prev;

    Node(string data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
    string getData(){
        return this->data;
    }
};

class LinkedList {
    public:
    Node *tail, *front;
    
    LinkedList() {
        tail = NULL;
        front = NULL;
    }

    void push_back(string data) {
        Node *node = new Node(data);
        if (tail == NULL) {
            tail = node;
            front = node;
        } else {
            node->prev = tail;
            tail->next = node;
            tail = node;
        }
    }

    void push_front(string data) {
        Node *node = new Node(data);
        if (front == NULL) {
            tail = node;
            front = node;
        } else {
            front->prev = node;
            node->next = front;
            front = node;
        }
    }

    void pop_back() {
        if (tail != NULL) {
            tail = tail->prev;
            if (tail != NULL)
                tail->next = NULL;
            else 
                front = NULL;
        }
    }

    void pop_front() {
        if (front != NULL) {
            front = front->next;
            if (front != NULL)
                front->prev = NULL;
            else
                tail = NULL;
        }
    }

    void shift(int k){
        int currentIndex = 0;
        auto currentNode = front;
        auto prevHeadCopy = front;
        auto postTail = front;
        while (currentIndex != k)
        {
            if(currentIndex == k - 1){
                postTail = currentNode;
            }
            currentNode = currentNode->next;
            currentIndex++;
        }
        
        this->front = currentNode;
        this->tail->next = prevHeadCopy;
        tail = postTail;
        
    }

};

int main(){
    int n;
    int shift;
    cin >> n >> shift;
    LinkedList lst;

    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        lst.push_back(s);
    }

    lst.shift(shift);
    auto currenNode = lst.front;
    for(int i = 0; i < n; i++){
        string tmp = currenNode->getData();
        cout << tmp << " ";
        currenNode = currenNode->next;
    }
    cout << endl;
    auto s = lst.tail->getData();
    cout << s;
}