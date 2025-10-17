#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    priority_queue<long long, vector<long long>, greater<long long>> minHeap;
    
    for (int i = 0; i < n; i++) {
        long long d;
        cin >> d;
        minHeap.push(d);
    }
    
    int operations = 0;
    
    while (minHeap.size() >= 2 && minHeap.top() < m) {
        long long smallest = minHeap.top();
        minHeap.pop();
        long long secondSmallest = minHeap.top();
        minHeap.pop();

        if (secondSmallest == 0 && smallest == 0) {
            operations = -1;
            break;
        }

        long long newDensity = smallest + 2 * secondSmallest;
        minHeap.push(newDensity);
        operations++;

        if (operations > 2 * n) {
            operations = -1;
            break;
        }
    }

    if (operations != -1 && minHeap.top() < m) {
        operations = -1;
    }
    
    cout << operations << endl;

}