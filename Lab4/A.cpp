#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int data){
        this->data = data;
        left = right = nullptr;
    }
};

TreeNode* insert(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

bool followsPath(TreeNode* root, const string& path) {
    TreeNode* curr = root;
    for (char dir : path) {
        if (dir == 'L') {
            if (!curr->left) return false;
            curr = curr->left;
        } else if (dir == 'R') {
            if (!curr->right) return false;
            curr = curr->right;
        }
    }
    return true;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> keys(N);
    for (int i = 0; i < N; ++i) {
        cin >> keys[i];
    }

    TreeNode* root = nullptr;
    for (int key : keys) {
        root = insert(root, key);
    }

    for (int i = 0; i < M; ++i) {
        string path;
        cin >> path;
        if (followsPath(root, path)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}