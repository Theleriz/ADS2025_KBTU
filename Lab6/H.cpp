#include <iostream>
#include <vector>
#include <string>

using namespace std;

int partition(vector<char>& arr, int low, int high) {
    char pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<char>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    char target;
    cin >> n;
    vector<char> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    cin >> target;

    quickSort(arr, 0, n - 1);

    for (char c : arr) {
        if (c > target) {
            cout << c << "\n";
            return 0;
        }
    }

    cout << arr[0] << "\n";
    return 0;
}
