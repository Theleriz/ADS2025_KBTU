#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    priority_queue<int> maxHeap;

    for (int i = 0; i < N; ++i) {
        int weight;
        cin >> weight;
        maxHeap.push(weight);
    }

    while (maxHeap.size() > 1) {
        int y = maxHeap.top(); maxHeap.pop(); 
        int x = maxHeap.top(); maxHeap.pop(); 

        if (x != y) {
            maxHeap.push(y - x); 
        }
    }

    if (maxHeap.empty()) {
        cout << 0 << endl;
    } else {
        cout << maxHeap.top() << endl;
    }
}