#include <iostream>
 
using namespace std;
 
struct Node{
    int val;
    Node* next;
    Node(): val(0), next(nullptr) {}
    Node(int x): val(x), next(nullptr) {}
    Node(Node* next): val(0), next(next) {}
    Node(int x, Node* next): val(x), next(next) {}
};
 
Node* insert(Node* head, Node* node, int p){
    if (p == 0) {
        node->next = head;
        return node;
    }
    Node* cur = head;
    for (int i = 0; i < p - 1 && cur; ++i) {
        cur = cur->next;
    }
    if (!cur) return head;
    node->next = cur->next;
    cur->next = node;
    return head;
}
 
Node* remove(Node* head, int p){
    if (!head) return head;
    if (p == 0) {
        Node* new_head = head->next;
        delete head;
        return new_head;
    }
    Node* cur = head;
    for (int i = 0; i < p - 1 && cur->next; ++i) {
        cur = cur->next;
    }
    if (!cur->next) return head;
    Node* to_delete = cur->next;
    cur->next = to_delete->next;
    delete to_delete;
    return head;
}
 
void print(Node* head){
    if (!head) {
        cout << "-1" << endl;
        return;
    }
    Node* cur = head;
    bool first = true;
    while (cur) {
        if (!first) cout << " ";
        cout << cur->val;
        first = false;
        cur = cur->next;
    }
    cout << endl;
}
 
Node* replace(Node* head, int p1, int p2){
    if (p1 == p2) return head;

    Node* removed_node = nullptr;
    if (p1 == 0) {
        removed_node = head;
        head = head->next;
    } else {
        Node* cur = head;
        for (int i = 0; i < p1 - 1; ++i) {
            cur = cur->next;
        }
        removed_node = cur->next;
        cur->next = removed_node->next;
    }

    if (p1 < p2) p2--;

    if (p2 == 0) {
        removed_node->next = head;
        head = removed_node;
    } else {
        Node* cur = head;
        for (int i = 0; i < p2 - 1; ++i) {
            cur = cur->next;
        }
        removed_node->next = cur->next;
        cur->next = removed_node;
    }

    return head;
}
 
Node* reverse(Node* head){
    Node* prev = nullptr;
    Node* cur = head;
    while (cur) {
        Node* next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}
 
Node* cyclic_left(Node* head, int x){
    if (!head || !head->next) return head;

    int n = 0;
    Node* cur = head;
    while (cur) {
        n++;
        cur = cur->next;
    }

    x %= n;
    if (x == 0) return head;

    cur = head;
    for (int i = 0; i < x - 1; ++i) {
        cur = cur->next;
    }

    Node* new_head = cur->next;
    cur->next = nullptr;

    Node* tail = new_head;
    while (tail->next) {
        tail = tail->next;
    }

    tail->next = head;
    return new_head;
}
 
Node* cyclic_right(Node* head, int x){
    if (!head || !head->next) return head;

    int n = 0;
    Node* cur = head;
    while (cur) {
        n++;
        cur = cur->next;
    }

    x %= n;
    if (x == 0) return head;

    cur = head;
    for (int i = 0; i < n - x - 1; ++i) {
        cur = cur->next;
    }

    Node* new_head = cur->next;
    cur->next = nullptr;

    Node* tail = new_head;
    while (tail->next) {
        tail = tail->next;
    }

    tail->next = head;
    return new_head;
}
 
int main(){
    Node* head = nullptr;
    while (true)
    {
        int command; cin >> command;
        if (command == 0){
            break;
        }else if(command == 1){
            int x, p; cin >> x >> p;
            head = insert(head, new Node(x), p);
        }else if (command == 2){
            int p; cin >> p;
            head = remove(head, p);
        }else if (command == 3){
            print(head);
        }else if (command == 4){
            int p1, p2; cin >> p1 >> p2;
            head = replace(head, p1, p2);
        }else if (command == 5){
            head = reverse(head);
        }else if (command == 6){
            int x; cin >> x;
            head = cyclic_left(head, x);
        }else if (command == 7){
            int x; cin >> x;
            head = cyclic_right(head, x);
        }   
    }
    return 0;
}