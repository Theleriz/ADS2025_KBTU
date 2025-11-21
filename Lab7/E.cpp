#include <iostream>
#include <vector>

using namespace std;

struct Row {
    vector<int> data;
    int sum;
};

bool lexCompare(const vector<int>& a, const vector<int>& b) {
    for (unsigned long long i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) {
            return a[i] < b[i];
        }
    }
    return false;
}

void merge(vector<Row>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<Row> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < L.size() && j < R.size()) {
        if (L[i].sum > R[j].sum || (L[i].sum == R[j].sum && lexCompare(L[i].data, R[j].data))) {
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

void mergeSort(vector<Row>& arr, int left, int right) {
    if (left >= right) return;
    int mid = (left + right) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<Row> rows(n);
    
    for (int i = 0; i < n; i++) {
        rows[i].data.resize(m);
        rows[i].sum = 0;
        for (int j = 0; j < m; j++) {
            cin >> rows[i].data[j];
            rows[i].sum += rows[i].data[j];
        }
    }
    
    mergeSort(rows, 0, n - 1, );
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << rows[i].data[j] << " ";
        }
        cout << endl;
    }
}