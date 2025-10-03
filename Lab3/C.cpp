#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, q;
    cin >> n >> q;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    for (int i = 0; i < q; i++) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        
        int count = 0;
        for (int c = 0; c < n; c++) {
            
            if ((l1 <= a[c] && a[c] <= r1) || (l2 <= a[c] && a[c] <= r2)) {
                count++;
            }
        }
        
        cout << count << "\n";
    }
    
    return 0;
}