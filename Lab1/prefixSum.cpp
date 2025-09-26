#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> prefixSumArray(n +1 );
    prefixSumArray.push_back(0);

    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        arr.push_back(t);
    }

    for(int i = 0; i < n; i++){
        prefixSumArray[i + 1] = prefixSumArray[i] + arr[i];
        cout << prefixSumArray[i] << " ";
    }

    cout << endl;
    for(int i = 0; i < n + 1; i++){
        cout << prefixSumArray[i] << " ";
    }
}