#include <iostream>
#include <string>
using namespace std;

void merge(pair<char, int> arr[], int l, int m, int r) {
    
}

void mergeSort(pair<char, int> arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    int cnt[26] = {0};
    for (char c : s) {
        cnt[c - 'a']++;
    }
    
    pair<char, int> arr[26];
    int size = 0;
    
    for (int i = 0; i < 26; i++) {
        if (cnt[i] > 0) {
            arr[size++] = {char('a' + i), cnt[i]};
        }
    }
    
    mergeSort(arr, 0, size - 1);
    
    cout << arr[0].first;

}