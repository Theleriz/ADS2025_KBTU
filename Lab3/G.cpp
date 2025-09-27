#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

#define ll long long

bool canDeliver(vector<ll>& arr, ll capacity, int f) {
    ll totalFlights = 0;
    for (int i = 0; i < arr.size(); i++) {
        ll d = arr[i];
        totalFlights += (d + capacity - 1) / capacity;
        if (totalFlights > f) return false;
    }
    return true;
}

int main() {

    int n, f;
    cin >> n >> f;

    vector<ll> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    ll low = 1;
    ll high = *(max_element(arr.begin(), arr.end()));
    ll ans = high;

    while (low <= high) {
        ll mid = low + (high - low) / 2;
        if (canDeliver(arr, mid, f)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << ans;
}