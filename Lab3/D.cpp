#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int countInRange(const vector<int>& sorted_a, int l, int r) {
    auto left = lower_bound(sorted_a.begin(), sorted_a.end(), l);
    auto right = upper_bound(sorted_a.begin(), sorted_a.end(), r);
    return right - left;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, q;
    cin >> n >> q;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<int> sorted_a = a;
    sort(sorted_a.begin(), sorted_a.end());
    
    for (int i = 0; i < q; i++) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        
        int maxL = max(l1, l2);
        int minR = min(r1, r2);
        
        if (maxL <= minR) {
            int count1 = countInRange(sorted_a, l1, r1);
            int count2 = countInRange(sorted_a, l2, r2);
            int overlap = countInRange(sorted_a, maxL, minR);
            cout << count1 + count2 - overlap << "\n";
        } else {
            int count1 = countInRange(sorted_a, l1, r1);
            int count2 = countInRange(sorted_a, l2, r2);
            cout << count1 + count2 << "\n";
        }
    }
    
    return 0;
}