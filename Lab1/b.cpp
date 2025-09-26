#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    bool flag;
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }
    cout << -1 << " ";

    for(int i = 1;i < n;i++){
        flag = true;
        for(int j = i-1;j >= 0;j--){
            if(arr[j] <= arr[i]){
                cout << arr[j] << " ";
                flag = false;
                break;
            }
        }
        if(flag){
            cout << -1 << " ";
        }
        
    }
}