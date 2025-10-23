#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i];
    }

    sort(points.begin(), points.end());

    long long minDiff = LLONG_MAX;
    for (int i = 0; i < n - 1; ++i) {
        long long diff = points[i + 1] - points[i];
        if (diff < minDiff) {
            minDiff = diff;
        }
    }

    for (int i = 0; i < n - 1; ++i) {
        if (points[i + 1] - points[i] == minDiff) {
            cout << points[i] << " " << points[i + 1] << " ";
        }
    }
}