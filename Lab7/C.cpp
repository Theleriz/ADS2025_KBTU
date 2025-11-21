#include <iostream> 
#include <algorithm> 
#include <vector> 
using namespace std; 

void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}


void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right) return;

    int mid = (left + right) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

vector<int> findElements(vector<int>& arr1, vector<int>& arr2) 
{ 
    vector<int> result; 

    mergeSort(arr1, 0, arr1.size() - 1); 
    mergeSort(arr2, 0, arr2.size() - 1); 

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
    vector<int> first(n);
    vector<int> second(m);

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