#include <iostream>
#include <vector>
#include <string>
#include <list>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> arr;
    for(int i = 0; i < n; i++){
        string s; cin >> s; arr.push_back(s);
    }

    list<string> result;

    for(int i = 0; i < n; i++){
        if(i == 0){
            result.push_front(arr[i]);
            continue;
        }
        if(arr[i] != arr[i - 1]){
            result.push_front(arr[i]);
        }
    }
    cout << "All in all: " << result.size() << endl;
    
    cout << "Students:" << endl;
    for(string s : result){
        cout << s << endl;
    }
}