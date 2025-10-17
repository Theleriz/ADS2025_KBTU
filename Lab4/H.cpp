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
        } else if (val > node->data) {
            node->right = insert(node->right, val);
        }

        
        return node;
    }

    void transformToGST(Node* node, int& sum) {
        if (node == nullptr) return;

        transformToGST(node->right, sum);

        sum += node->data;
        node->data = sum;
        
        transformToGST(node->left, sum);
    }
    
    void inOrder(Node* node, vector<int>& result) {
        if (node == nullptr) return;
        
        inOrder(node->left, result);
        result.push_back(node->data);
        inOrder(node->right, result);
    }

public:
    BST() : root(nullptr) {}
    
    void insert(int val) {
        root = insert(root, val);
    }
    
    void convertToGreaterSumTree() {
        int sum = 0;
        transformToGST(root, sum);
    }
    
    vector<int> getInOrder() {
        vector<int> result;
        inOrder(root, result);
        return result;
    }
};

int main() {
    int n;
    cin >> n;
    
    BST tree;
    
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        tree.insert(val);
    }
    
    tree.convertToGreaterSumTree();

    vector<int> result = tree.getInOrder();
    
    for (size_t i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i != result.size() - 1) {
            cout << " ";
        }
    }
}