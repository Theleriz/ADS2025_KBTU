#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    cin >> N >> M;
    
    vector<int> blockLines(N);
    for (int i = 0; i < N; i++) {
        cin >> blockLines[i];
    }
    
    vector<int> cumulativeLines(N + 1, 0);
    for (int i = 0; i < N; i++) {
        cumulativeLines[i + 1] = cumulativeLines[i] + blockLines[i];
    }
    
    for (int i = 0; i < M; i++) {
        int mistakeLine;
        cin >> mistakeLine;
        
        int block = upper_bound(cumulativeLines.begin(), cumulativeLines.end(), mistakeLine - 1) - cumulativeLines.begin();
        
        cout << block << "\n";
    }
    
    return 0;
}