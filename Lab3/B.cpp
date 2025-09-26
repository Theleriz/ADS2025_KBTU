#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

bool solve(vector<ll>& arr, int k, ll maxSum) {
    int blocks = 1;
    long long currentSum = 0;

    for (int i = 0; i < arr.size(); i++) {
        long long x = arr[i];
        if (x > maxSum) return false;

        if (currentSum + x <= maxSum) {
            currentSum += x;
        } else {
            blocks++;
            currentSum = x;
            if (blocks > k) return false;
        }
    }

    return true;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<ll> arr(n);
    ll total = 0;
    ll maxVal = 0;

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        total += arr[i];
        maxVal = max(maxVal, arr[i]);
    }

    ll low = maxVal;
    ll high = total;
    ll ans = total;

    while (low <= high) {
        ll mid = low + (high - low) / 2;

        if (solve(arr, k, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << ans;
}