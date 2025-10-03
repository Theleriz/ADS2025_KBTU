#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    vector<int> targets(t);
    for (int i = 0; i < t; ++i) {
        cin >> targets[i];
    }

    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }

    for (int target : targets) {
        bool found = false;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == target) {
                    cout << i << " " << j << "\n";
                    found = true;
                    break;
                }
            }
            if (found) break;
        }
        if (!found) {
            cout << "-1\n";
        }
    }

    return 0;
}