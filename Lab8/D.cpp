#include <iostream>
#include <vector>
#include <string>
using namespace std;
using ll = long long;

static const ll P = 131;     
static const ll MOD = 1e9 + 7; 

pair<vector<ll>, vector<ll>> buildPrefixHash(const string& s) {
    int n = s.size();
    vector<ll> h(n + 1, 0);
    vector<ll> p(n + 1, 1); 

    for (int i = 0; i < n; i++) {
        h[i + 1] = (h[i] * P + (s[i] - 'a' + 1)) % MOD;
        p[i + 1] = (p[i] * P) % MOD;
    }

    return make_pair(h, p);
}

ll getSubstringHash(const vector<ll>& h, const vector<ll>& p, int l, int r) {
    ll hash_value = (h[r] - (h[l] * p[r - l]) % MOD + MOD) % MOD;
    return hash_value;
}

int main() {
    string s;
    int n;

    cin >> s;
    cin >> n;

    string covered(s.size(), '0');
    pair<vector<ll>, vector<ll>> hp = buildPrefixHash(s);
    vector<ll> h = hp.first;
    vector<ll> p = hp.second;


    while (n--) {
        string t;
        cin >> t;

        ll hash_t = 0;
        for (char c : t) {
            hash_t = (hash_t * P + (c - 'a' + 1)) % MOD;
        }

        int m = t.size();
        int len = s.size();

        for (int i = 0; i + m <= len; i++) {
            ll sub_hash = getSubstringHash(h, p, i, i + m);

            if (sub_hash == hash_t) {
                for (int k = i; k < i + m; k++) {
                    covered[k] = '1';
                }
            }
        }
    }
    
    bool flag = true;
    for (char c : covered) {
        if (c == '0') {
            flag = false;
        }
    }
    if(flag){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
    return 0;
}
