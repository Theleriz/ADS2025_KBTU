#include <iostream>
#include <vector>
#include <string>
using namespace std;

void quickSortString(vector<int> &s, int left, int right) {
    if (left >= right) return;
    int i = left;
    int j = right;
    int p = s[(left + right) / 2]; 

    while (i <= j) {
        while ((int)s[i] < p) i++;
        while ((int)s[j] > p) j--;
        if (i <= j) {
            swap(s[i], s[j]);
            i++;
            j--;
            
        }
        for(int i = 0; i < s.size(); i++){
            cout << s[i] << " ";
        }
        cout << endl;
    }

    if (left < j) quickSortString(s, left, j);
    if (i < right) quickSortString(s, i, right);
}

int main() {
    vector<int> s{10, 12, 25, 21, 8, 7};
    for(int i = 0; i < s.size(); i++){
            cout << s[i] << " ";
        }
        cout << endl;
    quickSortString(s, 0, s.size() - 1);

}
