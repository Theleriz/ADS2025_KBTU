#include <iostream>
#include <vector>
using namespace std;

template<typename T>
int partition(vector<T>& vec, int low, int high) {
    T pivot = vec[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (vec[j] > pivot) {
            swap(vec[++i], vec[j]);
        }
    }
    swap(vec[i + 1], vec[high]);
    return i + 1;
}

template<typename T>
void quickSort(vector<T>& vec, int low, int high) {
    if (low < high) {
        int pi = partition(vec, low, high);
        quickSort(vec, low, pi - 1);
        quickSort(vec, pi + 1, high);
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m));

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> matrix[i][j];

    vector<vector<int>> columns(m, vector<int>(n));
    for (int j = 0; j < m; ++j)
        for (int i = 0; i < n; ++i)
            columns[j][i] = matrix[i][j];

    for (int j = 0; j < m; ++j) {
        quickSort(columns[j], 0, n - 1);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            cout << columns[j][i] << " ";
        cout << endl;
    }
}
