#include <iostream>
#include <vector>
using namespace std;

void quickSort(vector<int> &arr, int left, int right) {
    if (left >= right) return;

    int i = left;
    int j = right;
    int p = arr[(left + right) / 2]; 

    while (i <= j) {
        while ((int)arr[i] < p) i++;
        while ((int)arr[j] > p) j--;
        if (i <= j) {
            char c = arr[i];
            arr[i] = arr[j];
            arr[j] = c;
            i++;
            j--;
        }
    }

    if (left < j) quickSort(arr, left, j);
    if (i < right) quickSort(arr, i, right);
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> first(n);
    vector<int> second(m);
    vector<int> result;
    int pointer1 = 0;
    int pointer2 = 0;

    quickSort(first, 0, n - 1);
    quickSort(second, 0, m - 1);

    if(n != 0 && m != 0){
        while (pointer1 < first.size() 
        && pointer2 < second.size()) { 
            if (first[pointer1] == second[pointer2]) { 
                result.push_back(first[pointer1]); 
                pointer1++; 
                pointer2++; 
            } 
            else if (first[pointer1] < second[pointer2]) { 
                
                pointer1++; 
            } 
            else { 
                pointer2++; 
            } 
        }    
        for(int i = 0; i < result.size(); i++){
            cout << result[i] << " ";
        }
    }
    else {
        cout << endl;
    }
}