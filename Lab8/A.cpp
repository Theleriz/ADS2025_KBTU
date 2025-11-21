#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

using ll = long long;

const ll MOD = 1'000'000'007;

// Хеш-функция для строки
string computeHash(const string& s) {
    ll h = 0, p = 1;
    for (char c : s) {
        h = (h + ((c - 47) * p) % MOD) % MOD;
        p = (p * 11) % MOD;
    }
    return to_string(h);
}

void solve() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> values;
    values.reserve(n * 2);

    unordered_set<string> originalStrings;
    originalStrings.reserve(n * 2);

    string s;
    for (int i = 0; i < n * 2; i++) {
        cin >> s;
        values.push_back(s);
        originalStrings.insert(s);
    }

    int found = 0;

    for (const string& str : values) {
        if (found == n) break;

        string h = computeHash(str);

        if (originalStrings.count(h)) {
            cout << "Hash of string \"" << str << "\" is " << h << endl;
            found++;
        }
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
