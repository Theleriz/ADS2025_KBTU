#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <cstdint>
using namespace std;
using ll = long long;

const int MAX_N = 2002;
const ll MOD1 = 1000000007;
const ll MOD2 = 1000000009;
const ll P1 = 31;
const ll P2 = 37;


vector<ll> h1(MAX_N, 0), h2(MAX_N, 0);
vector<ll> p1(MAX_N, 1), p2(MAX_N, 1);


pair<ll, ll> getHash(int l, int r) {
    ll hash1 = (h1[r] - h1[l] * p1[r - l]) % MOD1;
    if (hash1 < 0) hash1 += MOD1;

    ll hash2 = (h2[r] - h2[l] * p2[r - l]) % MOD2;
    if (hash2 < 0) hash2 += MOD2;

    return make_pair(hash1, hash2);
}

void solve() {
    string s;
    cin >> s;

    int n = s.size();
    unordered_set<unsigned long long> substrHashes;


    for (int i = 0; i < n; i++) {
        h1[i + 1] = (h1[i] * P1 + (s[i] - 'a' + 1)) % MOD1;
        h2[i + 1] = (h2[i] * P2 + (s[i] - 'a' + 1)) % MOD2;
    }

    for (int len = 1; len <= n; len++) {
        for (int start = 0; start + len <= n; start++) {
            pair<ll, ll> p = getHash(start, start + len);
            unsigned long long combinedHash = ((unsigned long long)p.first << 32) | ((unsigned long long)p.second);
            substrHashes.insert(combinedHash);
        }
    }

    cout << substrHashes.size() << endl;
}

int main() {
    for (int i = 1; i < MAX_N; i++) {
        p1[i] = (p1[i - 1] * P1) % MOD1;
        p2[i] = (p2[i - 1] * P2) % MOD2;
    }

    solve();

    return 0;
}
