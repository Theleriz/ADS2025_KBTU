#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canSteal(const vector<long long>& bags, long long K, int H) {
    long long totalHours = 0;
    for (long long bars : bags) {
        totalHours += (bars + K - 1) / K;
        if (totalHours > H) return false;
    }
    return totalHours <= H;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, H;
    cin >> N >> H;

    vector<long long> bags(N);
    for (int i = 0; i < N; ++i) {
        cin >> bags[i];
    }

    long long low = 1, high = *max_element(bags.begin(), bags.end());
    long long ans = high;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (canSteal(bags, mid, H)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << ans << '\n';
    return 0;
}