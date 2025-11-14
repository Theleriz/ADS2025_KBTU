#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> prefix_function(string &s) {
    int n = s.size();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j]) pi[i] = j + 1;
    }
    return pi;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        string s;
        long long k;
        cin >> s >> k;

        if (k == 1) {
            cout << s.size() << '\n';
            continue;
        }

        vector<int> pi = prefix_function(s);
        int len = s.size();
        int overlap = pi[len - 1]; // longest proper prefix-suffix

        long long result = len + (k - 1) * (len - overlap);
        cout << result << '\n';
    }
}