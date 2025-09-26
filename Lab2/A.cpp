#include <iostream>
#include <vector>
using namespace std;

int main(){
    int size, number;
    cin >> size;
    vector<int> array;
    int answerIndex = -1;
    int distance = 10000000;
    for(int i = 0; i < size; i++){
        int t; cin >> t;array.push_back(t);
    }
    
    cin >> number;
    for(int i = 0; i < size; i++){
        if(abs(array[i] - number) < distance){
            distance = abs(array[i] - number);
            answerIndex = i;
        }
    }

    cout << answerIndex;
}