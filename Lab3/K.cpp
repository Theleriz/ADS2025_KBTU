#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    ll k;
    cin >> n >> k;

    vector<ll> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    vector<ll> prefix(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefix[i + 1] = prefix[i] + arr[i];
    }

    int low = 1, high = n;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        bool valid = false;

        for (int i = mid; i <= n; i++) {
            ll subarraySum = prefix[i] - prefix[i - mid];
            if (subarraySum >= k) {
                valid = true;
                break;
            }
        }

        if (valid) {
            ans = mid;
            high = mid - 1; 
        } else {
            low = mid + 1;
        }
        //если на отрезке в самом большом значений префиксной суммы нет суммы которая больше чем К то этот отрезок можно отбросить и так перебором можно быстрее пройтись по подмассивам
    }

    cout << ans;
}