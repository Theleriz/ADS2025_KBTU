#include <iostream>
#include <vector>
using namespace std;

struct Row {
    vector<int> data;
    int sum;
};

void merge(vector<Row>& arr, int left, int mid, int right, bool(*CMP)(Row, Row)) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<Row> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < L.size() && j < R.size()) {
        if(CMP(L[i], R[i])){ // there put comparator function
            arr[k] = L[i];
            k++;
            i++;
        } else {
            arr[k++] = R[j++];
        }
    }
    while (i < L.size()) arr[k++] = L[i++];
    while (j < R.size()) arr[k++] = R[j++];
}

void mergeSort(vector<Row>& arr, int left, int right, bool (*CMP)(Row, Row)) {
    if (left >= right) return;
    int mid = (left + right) / 2;
    bool(*CMPfunc)(Row, Row); // tmp function to provide function
    CMPfunc = CMP;
    mergeSort(arr, left, mid, CMPfunc);
    mergeSort(arr, mid + 1, right, CMPfunc);
    merge(arr, left, mid, right, CMPfunc);
}

void sort(vector<Row> &array, bool (*CMP)(Row, Row)){
    //function over mergeSort 
    int left = 0;
    int right = array.size() - 1;
    mergeSort(array, left, right, CMP);
}

int main(){
    vector<Row> arr;
    sort(arr, [](Row a, Row b){
        return a.sum > b.sum || (a.sum == b.sum && [](vector<int> &a, vector<int> &b){
            for(unsigned long long i = 0; i < a.size(); i++){
                if(a[i] != b[i]){
                    return a[i] < b[i];
                }
            }
            return false;
        });
    });
}
