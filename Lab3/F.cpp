#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    
    vector<long long> powers(N);
    for (int i = 0; i < N; i++) {
        cin >> powers[i];
    }
    
    int P;
    cin >> P;
    
    vector<long long> sortedPowers = powers;
    sort(sortedPowers.begin(), sortedPowers.end());
    
    vector<long long> prefixSum(N + 1, 0);
    for (int i = 0; i < N; i++) {
        prefixSum[i + 1] = prefixSum[i] + sortedPowers[i];
    }
    
    for (int i = 0; i < P; i++) {
        long long markPower;
        cin >> markPower;
        
        int count = upper_bound(sortedPowers.begin(), sortedPowers.end(), markPower) - sortedPowers.begin();
        long long sum = prefixSum[count];
        
        cout << count << " " << sum << "\n";
    }
    
    return 0;
}