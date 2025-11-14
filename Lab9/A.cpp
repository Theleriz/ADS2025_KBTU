#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> prefix_function(const string &s) {
    int n = s.size();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j]) pi[i] = j + 1;
    }
    return pi;
}

int main() {
    string A, B;
    cin >> A >> B;

    if (A.find(B) != string::npos) {
        cout << 1 << endl;
        return 0;
    }

    int lenA = A.size();
    int lenB = B.size();

    vector<int> pi = prefix_function(B);


    int j = 0;
    int reps = 1;
    int max_reps = (lenB + lenA - 1) / lenA + 2; // safe upper bound

    for (int pos = 0; pos < lenA * max_reps; pos++) {
        char c = A[pos % lenA];
        while (j > 0 && c != B[j])
            j = pi[j - 1];
        if (c == B[j])
            j++;
        if (j == lenB) {

            int total_len = pos + 1;
            int min_reps = (total_len + lenA - 1) / lenA;
            cout << min_reps << endl;
        }
    }

    cout << -1 << endl;

}