#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class BST {
public:
    Node* root;
    BST() {
        root = nullptr;
    }

    void push(int val){
        root = insert(root, val);
    }

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

    Node* search(Node* node, int data) {
        if (node == nullptr || node->data == data)
            return node;
        
        if (data < node->data)
            return search(node->left, data);
        else
            return search(node->right, data);
    }
};

void preOrder(Node* node) {
    if (node == nullptr)
        return;
    cout << node->data << " ";
    preOrder(node->left);
    preOrder(node->right);
}

int main(){
    int n, target;
    cin >> n;
    BST tree;
    
    for(int i = 0; i < n; i++){
        int tmp; cin >> tmp; tree.push(tmp);
    }
    cin >> target;

    Node* node = tree.search(tree.root, target);
    preOrder(node);
    
    return 0;
}