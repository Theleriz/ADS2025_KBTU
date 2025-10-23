#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<int> castToInt(vector<char> &arr){
    vector<int> result;
    for(char c : arr){
        result.push_back((int)c);
    }
    return result;
}

int binSearch(const vector<int> &arr, int target){
    int size = arr.size();
    int left = 0, right = size - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if(arr[mid] == target){
            return mid;
        }
        else if(arr[mid] > target){
            right = mid - 1;
        }
        else if(arr[mid] < target){
            left = mid + 1;
        }
    }
    return -1;

}

int main(){
    int n;
    cin >> n;
    
    vector<char> arr;
    for(int i = 0; i < n; i++){
        char c;
        cin >> c;
        arr.push_back(c);
    }
    char baseChar;

    vector<int> arr2 = castToInt(arr);

    int index = binSearch(arr2, baseChar);

    if (index > -1){
        cout << arr[index + 1];
    }
    else {
        cout << arr[0];    
    }
    

}