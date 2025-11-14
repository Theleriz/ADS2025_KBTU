#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to compute the Prefix Function using an O(N^3) approach
vector<int> prefixFunction(string s) {
    int n = s.length();
    vector<int> pi(n, 0);

    // Iterate through each position in the string
    for (int i = 0; i < n; i++) {
        // Try all possible lengths for the prefix/suffix
        for (int j = 0; j < i; j++) {
            // Check if the substrings are equal
            if (s.substr(0, j + 1) == s.substr(i - j, j + 1)) {
                pi[i] = j + 1; // If equal, update the value at the current position
            }
        }
    }

    // Return the computed Prefix Function
    return pi;
}

// Driver Code
int main() {
    string s = "abcabcabc";
    vector<int> result = prefixFunction(s);

    // Print the Prefix Function values
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}