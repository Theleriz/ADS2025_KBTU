#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

void buildTree(vector<int>& sorted, vector<int>& result, int left, int right) {
    if (left > right) return;
    
    int mid = left + (right - left) / 2;
    result.push_back(sorted[mid]);
    
    buildTree(sorted, result, left, mid - 1);
    buildTree(sorted, result, mid + 1, right);
}

int main() {
    int N;
    cin >> N;
    
    int size = pow(2, N) - 1;
    vector<int> arr(size);
    
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    

    sort(arr.begin(), arr.end());
    
    vector<int> result;
    buildTree(arr, result, 0, size - 1);
    

    for (int i = 0; i < size; i++) {
        cout << result[i];
        if (i < size - 1) cout << " ";
    }
}