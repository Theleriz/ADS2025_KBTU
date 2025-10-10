#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    int data;
    int count;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        this->count = 1;
        left = right = nullptr;
    }
};

class BST {
public:
    Node* root;
    
    BST() {
        root = nullptr;
    }
    
    Node* insert(Node* node, int val) {
        if (node == nullptr)
            return new Node(val);

        if (val < node->data)
            node->left = insert(node->left, val);
        else if (val > node->data)
            node->right = insert(node->right, val);
        else
            node->count++;
        return node;
    }

    void push(int data){
        root = insert(this->root, data);
    }

    int cnt(Node* node, int val) {
        if (node == nullptr)
            return 0;
        if (val < node->data)
            return cnt(node->left, val);
        else if (val > node->data)
            return cnt(node->right, val);
        else
            return node->count;
    }

    Node* remove(Node* node, int val) {
        if (node == nullptr)
            return nullptr;

        if (val < node->data)
            node->left = remove(node->left, val);
        else if (val > node->data)
            node->right = remove(node->right, val);
        else {
            if (node->count > 1) {
                node->count--;
                return node;
            }

            if (node->left == nullptr) {
                Node* rightChild = node->right;
                delete node;
                return rightChild;
            } else if (node->right == nullptr) {
                Node* leftChild = node->left;
                delete node;
                return leftChild;
            } else {
                Node* successor = node->right;
                while (successor->left != nullptr)
                    successor = successor->left;

                node->data = successor->data;
                node->count = successor->count;

                successor->count = 1;
                node->right = remove(node->right, successor->data);
            }
        }
        return node;
    }
    
    void remove(int val) {
        root = remove(root, val);
    }
    
    int cnt(int val) {
        return cnt(root, val);
    }
};

int main(){
    int n;
    cin >> n;
    BST tree;
    string q;
    int q1;
    
    for(int i = 0; i < n; i++){
        cin >> q >> q1;

        if(q == "insert"){
            tree.push(q1);
        }
        else if(q == "delete"){
            tree.remove(q1);  
        }
        else if(q == "cnt"){
            cout << tree.cnt(q1) << endl;
        }
    }
    return 0; 
}