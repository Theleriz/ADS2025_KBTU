#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<string> words;
    for(int i = 0; i < n; i++){
        string t; cin >> t; words.push_back(t); 
    }

    for(int i = k; i < n; i++){
        cout << words[i] << " ";
    }
    for(int i = 0; i < k; i++){
        cout << words[i] << " ";
    }
}