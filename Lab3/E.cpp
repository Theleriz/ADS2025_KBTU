#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Rectangle {
    int x1, y1, x2, y2;
};

bool canContain(const vector<Rectangle>& rects, int K, int side) {
    int count = 0;
    for (const auto& rect : rects) {
        if (rect.x2 <= side && rect.y2 <= side) {
            count++;
            if (count >= K) return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, K;
    cin >> N >> K;
    
    vector<Rectangle> rects(N);
    int maxCoord = 0;
    
    for (int i = 0; i < N; i++) {
        cin >> rects[i].x1 >> rects[i].y1 >> rects[i].x2 >> rects[i].y2;
        maxCoord = max(maxCoord, max(rects[i].x2, rects[i].y2));
    }
    
    int left = 0, right = maxCoord;
    int result = maxCoord;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (canContain(rects, K, mid)) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    cout << result << endl;
    
    return 0;
}