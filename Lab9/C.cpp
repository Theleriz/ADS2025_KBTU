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
        if (s[i] == s[j]) pi[i] = j+1;
    }
    return pi;
}

int main() {
    string a, b;
    cin >> a >> b;

    if (a.size() != b.size()) {
        cout << -1;
        return 0;
    }

    string combined = b + "#" + a + a;
    vector<int> pi = prefix_function(combined);

    int lenA = a.size();
    int pos = -1;

    
    for (int i = 0; i < (int)pi.size(); i++) {
        if (pi[i] == (int)b.size()) {
            pos = i - 2 * lenA; 
            break;
        }
    }

    if (pos == -1) cout << -1;
    else cout << lenA - pos; 
}