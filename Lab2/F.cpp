#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main() {
    int pos;
    vector<int> arr(1000, -1);
    while (cin >> pos){
        int data; cin >> data; arr[pos] = data;
    }
    list<int> lst;
    
    for(int i = 0; i < 1000; i++){
        if(arr[i]!= -1){
            lst.push_back(arr[i]);
        }
    }

    for(int item : lst){
        cout << item << " ";
    }


}