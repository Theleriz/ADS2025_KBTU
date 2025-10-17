#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        this->data = val;
        left = right = nullptr;
    }
};

class BST {
private:
    Node* root;
    
    Node* insert(Node* node, int val) {
        if (node == nullptr) {
            return new Node(val);
        }
        
        if (val < node->data) {
            node->left = insert(node->left, val);
        } else {
            node->right = insert(node->right, val);
        }
        
        return node;
    }
    
    Node* find(Node* node, int val) {
        if (node == nullptr || node->data == val) {
            return node;
        }
        
        if (val < node->data) {
            return find(node->left, val);
        } else {
            return find(node->right, val);
        }
    }
    
    int subtreeSize(Node* node) {
        if (node == nullptr) {
            return 0;
        }
        
        return 1 + subtreeSize(node->left) + subtreeSize(node->right);
    }

public:
    BST() {
        root = nullptr;
    }
    
    void insert(int val) {
        root = insert(root, val);
    }
    
    int getSubtreeSize(int val) {
        Node* target = find(root, val);
        if (target == nullptr) {
            return 0;
        }
        return subtreeSize(target);
    }
};

int main() {
    int N;
    cin >> N;
    
    BST tree;
    
    for (int i = 0; i < N; i++) {
        int val;
        cin >> val;
        tree.insert(val);
    }
    
    int X;
    cin >> X;
    
    cout << tree.getSubtreeSize(X) << endl;

}