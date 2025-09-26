#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
using namespace std;

list<int> fidnMode(const vector<int> &arr){
    list<int> result;
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
