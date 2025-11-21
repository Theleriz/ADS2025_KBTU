#include <iostream>
#include <vector>
#include <string>
using namespace std;
using ll = long long;


int main() {
    ll n;
    cin >> n;

    vector<ll> a(n);
    vector<ll> powers(52, 1); 

    for (int i = 1; i <= 51; i++) {
        powers[i] = powers[i - 1] * 2;
    }


    for (int i = 0; i < n; i++) {
        cin >> a[i];

        ll cur;
        if (i == 0) {

            cur = a[i] + 97;
        } else {
            cur = (a[i] - a[i - 1]) / powers[i] + 97;
        }

        cout << static_cast<char>(cur);
    }

    return 0;
}
