#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    string vowels = "";
    string consonants = "";

    for (char c : s) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            vowels += c;
        } else {
            consonants += c;
        }
    }

    sort(vowels.begin(), vowels.end());
    sort(consonants.begin(), consonants.end());

    cout << vowels + consonants << endl;
}