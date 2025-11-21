#include <iostream>
#include <vector>
#include <string>
using namespace std;
using ll = long long;

const ll MOD = 1'000'000'007;
const ll P = 31;

vector<ll> buildPrefixHash(const string& s, vector<ll>& p) {
    int n = s.size();
    vector<ll> h(n + 1, 0);
    p.assign(n + 1, 1);

    for (int i = 0; i < n; i++) {
        h[i + 1] = (h[i] * P + (s[i] - 'a' + 1)) % MOD;
        p[i + 1] = (p[i] * P) % MOD;
    }
    return h;
}

ll getHash(const vector<ll>& h, const vector<ll>& p, int l, int r) {
    ll res = (h[r] - h[l] * p[r - l]) % MOD;
    if (res < 0) res += MOD;
    return res;
}


int main() {
    string s1, s2, pattern;
    cin >> s1 >> s2 >> pattern;

    int n = s1.size();
    int m = pattern.size();

    vector<ll> p;

    vector<ll> h1 = buildPrefixHash(s1, p);
    vector<ll> h2 = buildPrefixHash(s2, p);

    ll hashPattern = 0;
    for (char c : pattern) {
        hashPattern = (hashPattern * P + (c - 'a' + 1)) % MOD;
    }

    int count = 0;
    for (int i = 0; i + m <= n; i++) {
        ll h_s1 = getHash(h1, p, i, i + m);
        ll h_s2 = getHash(h2, p, i, i + m);
        if (h_s1 == hashPattern && h_s2 == hashPattern) {
            count++;
        }
    }

    cout << count;

    return 0;
}
