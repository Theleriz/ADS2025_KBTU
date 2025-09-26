#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
using namespace std;

struct ModeResult {
    list<int> modes;
    int frequency;
};

ModeResult findModesEfficiently(const vector<int>& arr) {
    ModeResult result{{}, 0};
    if (arr.empty()) return result;
    
    unordered_map<int, int> freqMap;
    
    for (int num : arr) {
        int currentFreq = ++freqMap[num];
        
        if (currentFreq > result.frequency) {
            result.frequency = currentFreq;
            result.modes.clear();
            result.modes.push_back(num);
        } else if (currentFreq == result.frequency) {
            // check if we already have this num in frequency table
            bool found = false;
            for (int mode : result.modes) {
                if (mode == num) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                result.modes.push_back(num);
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
        int t; cin >> t; arr.push_back(t);
    }

    ModeResult answer = findModesEfficiently(arr);

    list<int> answerList = answer.modes;
    for(int item : answerList){
        cout << item << " ";
    }
}
