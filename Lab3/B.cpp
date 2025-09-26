#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

bool canPartition(vector<long long>& a, int k, long long maxSum) {
    int blocks = 1;
    long long currentSum = 0;

    for (long long x : a) {
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

    vector<long long> a(n);
    long long total = 0;
    long long maxVal = 0;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        total += a[i];
        maxVal = max(maxVal, a[i]);
    }

    long long low = maxVal;
    long long high = total;
    long long ans = total;

    while (low <= high) {
        long long mid = low + (high - low) / 2;

        if (canPartition(a, k, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << ans << endl;

    return 0;
}