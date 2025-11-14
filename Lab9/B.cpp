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
    string s;
    int K;
    cin >> s >> K;

    string T;
    cin >> T;

    if (s.empty()) {
        cout << "YES" << endl;
    }

    vector<int> pi = prefix_function(s);
    int n = T.size();
    int m = s.size();
    int j = 0; // length of current match
    int count = 0;

    for (int i = 0; i < n; i++) {
        while (j > 0 && T[i] != s[j]) {
            j = pi[j - 1];
        }
        if (T[i] == s[j]) {
            j++;
        }
        if (j == m) {
            count++;
            j = pi[j - 1];
        }
    }

    if (count >= K) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

}