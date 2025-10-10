#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    int level;
    
    Node(int val) {
        this->data = val;
        left = right = nullptr;
        level = 0;
    }
};

class BST {
public:
    Node* root;
    BST() {
        root = nullptr;
    }

    void insert(int val) {
        root = insertRec(root, val);
    }

    Node* insertRec(Node* node, int val) {
        if (node == nullptr) {
            return new Node(val);
        }
        
        if (val < node->data) {
            node->left = insertRec(node->left, val);
        } else {
            node->right = insertRec(node->right, val);
        }
        return node;
    }

    pair<int, vector<long long>> getLevelSums() {
        if (root == nullptr) return {0, {}};
        
        vector<long long> levelSums;
        int maxLevel = 0;
        
        queue<Node*> q;
        root->level = 0;
        q.push(root);
        
        while (!q.empty()) {
            Node* current = q.front();
            q.pop();
            
            if (current->level >= levelSums.size()) {
                levelSums.resize(current->level + 1, 0);
            }
            
            levelSums[current->level] += current->data;

            maxLevel = max(maxLevel, current->level);
            
            if (current->left != nullptr) {
                current->left->level = current->level + 1;
                q.push(current->left);
            }
            if (current->right != nullptr) {
                current->right->level = current->level + 1;
                q.push(current->right);
            }
        }
        
        return {maxLevel + 1, levelSums};
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
    
    auto result = tree.getLevelSums();
    int k = result.first;
    vector<long long> sums = result.second;
    

    cout << k << endl;
    for (int i = 0; i < sums.size(); i++) {
        cout << sums[i];
        if (i < sums.size() - 1) cout << " ";
    }

}