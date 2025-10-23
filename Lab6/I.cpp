#include <iostream>
#include <vector>
#include <string>
using namespace std;

void quickSortString(string &s, int left, int right) {
    if (left >= right) return;

    int i = left;
    int j = right;
    int p = (int)s[(left + right) / 2]; 

    while (i <= j) {
        while ((int)s[i] < p) i++;
        while ((int)s[j] > p) j--;
        if (i <= j) {
            char c = s[i];
            s[i] = s[j];
            s[j] = c;
            i++;
            j--;
        }
    }

    if (left < j) quickSortString(s, left, j);
    if (i < right) quickSortString(s, i, right);
}

int main() {
    string s;
    cin >> s;
    quickSortString(s, 0, s.size() - 1);
    cout << s;
}
