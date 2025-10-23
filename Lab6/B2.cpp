#include <iostream> 
#include <algorithm> 
#include <vector> 
using namespace std; 

void quickSort(vector<int> &s, int left, int right) {
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

    if (left < j) quickSort(s, left, j);
    if (i < right) quickSort(s, i, right);
}

vector<int> findElements(vector<int>& arr1, vector<int>& arr2) 
{ 
    vector<int> result; 

    quickSort(arr1, 0, arr1.size() - 1); 
    quickSort(arr2, 0, arr2.size() - 1); 

    int pointer1 = 0; 
    int pointer2 = 0; 

    while (pointer1 < arr1.size() && pointer2 < arr2.size()) { 
        if (arr1[pointer1] == arr2[pointer2]) { 
            result.push_back(arr1[pointer1]); 
            pointer1++; 
            pointer2++; 
        } 
        else if (arr1[pointer1] < arr2[pointer2]) { 
            pointer1++; 
        } 
        else { 
            pointer2++; 
        } 
    } 

    return result; 
} 

int main() 
{ 
    int n, m;
    cin >> n >> m;
    vector<int> first(n), second(m);

    if(n != 0 && m != 0){
        for(int i = 0; i < n; i++){
        cin >> first[i];
        }

        for(int i = 0; i < m; i++){
            cin >> second[i];
        }

        vector<int> result = findElements(first, second);
        for(int i = 0; i < result.size(); i++){
            cout << result[i] << " ";
        }
    }
    else {
        cout << endl;
    }

}