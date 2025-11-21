#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <cstdint>
using namespace std;
using ll = long long;

const ll MOD1 = 1000000007;
const ll MOD2 = 1000000009;
const ll P1 = 31;
const ll P2 = 37;

pair<vector<ll>, vector<ll>> buildPrefixHash(const string &s, ll mod, ll pw) {
    int n = s.size();
    vector<ll> h(n + 1, 0); 
    vector<ll> p(n + 1, 1); 

    for (int i = 0; i < n; i++) {
        h[i + 1] = (h[i] * pw + (s[i] - 'a' + 1)) % mod;
        p[i + 1] = (p[i] * pw) % mod;
    }

    return make_pair(h, p);
}


ll getHash(const vector<ll> &h, const vector<ll> &p, int l, int r, ll mod) {
    ll res = (h[r] - h[l] * p[r - l]) % mod;
    if (res < 0) res += mod;
    return res;
}

int main() {
    string s;
    int n;
    cin >> s >> n;

    vector<ll> h1, p1, h2, p2;
    pair<vector<ll>, vector<ll>> hp1 = buildPrefixHash(s, MOD1, P1);
    pair<vector<ll>, vector<ll>> hp2 = buildPrefixHash(s, MOD2, P2);
    h1 = hp1.first;
    p1 = hp1.second;
    h2 = hp2.first;
    p2 = hp2.second;

    unordered_map<unsigned long long, int> substringCount;
    int len = s.size();
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j <= len; j++) {
            ll hash1 = getHash(h1, p1, i, j, MOD1);
            ll hash2 = getHash(h2, p2, i, j, MOD2);

            unsigned long long key = ((unsigned long long)hash1 << 32) ^ (unsigned long long)hash2;
            substringCount[key]++;
        }
    }


    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        l--;

        ll hash1 = getHash(h1, p1, l, r, MOD1);
        ll hash2 = getHash(h2, p2, l, r, MOD2);
        unsigned long long key = ((unsigned long long)hash1 << 32) ^ (unsigned long long)hash2;

        cout << substringCount[key] << endl;
    }

    return 0;
}
