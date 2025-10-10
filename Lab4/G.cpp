#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BST {
public:
    Node* root;
    
    BST() : root(nullptr) {}
    
    void push(int val) {
        root = insert(root, val);
    }
    
    int getDiameter() {
        return dfs(root).second;
    }

    Node* insert(Node* node, int val) {
        if (!node) return new Node(val);
        
        if (val < node->data) {
            node->left = insert(node->left, val);
        } else if (val > node->data) {
            node->right = insert(node->right, val);
        }
        return node;
    }
    
    pair<int, int> dfs(Node* node) {
        if (!node) return {0, 0}; 
        
        auto left = dfs(node->left);
        auto right = dfs(node->right);
        
        int height = 1 + max(left.first, right.first);
        // Диаметр = количество узлов в самом длинном пути
        int diameter = max({left.second, right.second, left.first + right.first + 1});
        
        return {height, diameter};
    }

    
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    BST tree;
    
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        tree.push(val);
    }
    
    cout << tree.getDiameter() << endl;
}