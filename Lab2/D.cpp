#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

vector<int>findMode(const vector<int> &arr){
    vector<int>result;
    if(arr.empty()) return result;

    unordered_map<int, int> freqMap;
    int modeFreq = 0;
    
    for(int i = 0; i < arr.size(); i++){
        int numb = arr[i];
        int currentFreq = ++freqMap[numb];
        if(currentFreq > modeFreq){
            modeFreq = currentFreq;
            result.clear();
            result.push_back(numb);
        }
        else if(currentFreq == modeFreq){
            bool found = false;
            for(int item : result){
                if(item == numb){
                    found = true;
                    break;
                }
            }
            if(!found){
                result.push_back(numb);
            }
        }
    }
    return result;
}


int main(){
    int n;
    cin >> n;
    vector<int> arr;
    for(int i = 0; i < n; i++){
        int tmp;cin >> tmp; arr.push_back(tmp);
    }
    
    vector<int>modes = findMode(arr);

    sort(modes.begin(), modes.end(), [](int a, int b){return a > b;});
    for(int item : modes){
        cout << item << " ";
    }
}