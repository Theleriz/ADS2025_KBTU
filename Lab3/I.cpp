#include <iostream>
#include <vector>
#define ll long long
using namespace std;

bool binSearch(const vector<ll> &arr, ll target){
    ll size = arr.size();
    ll left = 0, right = size - 1;

    while (left <= right)
    {
        ll mid = left + (right - left) / 2;
        if(arr[mid] == target){
            return true;
        }
        else if(arr[mid] > target){
            right = mid - 1;
        }
        else if(arr[mid] < target){
            left = mid + 1;
        }
    }
    return false;

}

int main(){
    int n;
    cin >> n;
    vector<ll> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    ll target;
    cin >> target;

    if(binSearch(arr, target)){
        cout << "Yes";
    }
    else{
        cout << "No";
    }
}