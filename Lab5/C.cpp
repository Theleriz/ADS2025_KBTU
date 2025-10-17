#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    priority_queue<int> maxHeap;
    for (int i = 0; i < n; ++i) {
        int seats;
        cin >> seats;
        maxHeap.push(seats);
    }

    long long total = 0;
    for (int i = 0; i < x; ++i) {
        int price = maxHeap.top();
        maxHeap.pop();
        total += price;
        if (price > 1) {
            maxHeap.push(price - 1);
        }
    }

    cout << total << endl;
}