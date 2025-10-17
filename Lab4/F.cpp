#include <iostream>
#include <queue>
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
public:
    Node* root;
    BST() {
        root = nullptr;
    }

    void insert(int val) {
        root = insertRecursive(root, val);
    }

    Node* insertRecursive(Node* node, int val) {
        if (node == nullptr) {
            return new Node(val);
        }
        
        if (val < node->data) {
            node->left = insertRecursive(node->left, val);
        } else {
            node->right = insertRecursive(node->right, val);
        }
        
        return node;
    }
};

int main() {
    queue<Node*> q;
    int n;
    int answer = 0;
    cin >> n;
    BST tree;
    
    for(int i = 0; i < n; i++) {
        int tmp; 
        cin >> tmp; 
        tree.insert(tmp);
    }

    if (tree.root == nullptr) {
        cout << 0;
        return 0;
    }

    auto treeRoot = tree.root;
    q.push(treeRoot);
    
    while (!q.empty()) {
        auto curRoot = q.front();
        q.pop();
        
        if(curRoot->left != nullptr) q.push(curRoot->left);
        if(curRoot->right != nullptr) q.push(curRoot->right);

        if((curRoot->left != nullptr) && (curRoot->right != nullptr)) {
            answer++;
        }
    }
    
    cout << answer;
}