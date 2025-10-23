#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> matrix[i][j];
        }
    }

    for (int j = 0; j < m; ++j) {
        vector<int> col;
        for (int i = 0; i < n; ++i) {
            col.push_back(matrix[i][j]);
        }
        sort(col.rbegin(), col.rend());
        for (int i = 0; i < n; ++i) {
            matrix[i][j] = col[i];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (j > 0) cout << " ";
            cout << matrix[i][j];
        }
        cout << endl;
    }
}