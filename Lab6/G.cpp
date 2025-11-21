#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Pair {
    string original;
    string current;
};

void insertionSort(vector<Pair>& arr) {
    for (int i = 1; i < arr.size(); ++i) {
        Pair key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j].original > key.original) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int n;
    cin >> n;

    vector<Pair> users;

    for (int i = 0; i < n; ++i) {
        string oldNick, newNick;
        cin >> oldNick >> newNick;

        bool updated = false;
        for (auto& p : users) {
            if (p.current == oldNick) {
                p.current = newNick;
                updated = true;
                break;
            }
        }

        if (!updated) {
            users.push_back({oldNick, newNick});
        }
    }

    insertionSort(users);

    cout << users.size() << endl;
    for (const auto& p : users) {
        cout << p.original << " " << p.current << endl;
    }

}