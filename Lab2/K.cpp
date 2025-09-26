#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int T;
    cin >> T;

    while(T--) {
        int n;
        vector<int> table(26, 0);
        queue<char> dq;
        cin >> n;

        for(int j = 0; j < n; j++) {
            char c;
            cin >> c;
            int cInt = (int)c;

            table[cInt - 97]++; 
            dq.push(c);

            while(!dq.empty() && table[dq.front() - 97] > 1) {
                dq.pop();
            }
            
            if (dq.empty()) {
                cout << -1 << " ";
            } else {
                cout << dq.front() << " ";
            }
        }
        cout << endl;
    }
}