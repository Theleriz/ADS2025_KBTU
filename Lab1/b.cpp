#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> ages(n);
    for (int i = 0; i < n; ++i) {
        cin >> ages[i];
    }

    stack<long long> stk;
    vector<long long> result(n);

    for (int i = 0; i < n; ++i) {
        while (!stk.empty() && stk.top() >= ages[i]) {
            stk.pop();
        }

        if (stk.empty()) {
            result[i] = -1;
        } else {
            result[i] = stk.top();
        }

        stk.push(ages[i]);
    }

    for (int i = 0; i < n; ++i) {
        if (i > 0) cout << " ";
        cout << result[i];
    }
}