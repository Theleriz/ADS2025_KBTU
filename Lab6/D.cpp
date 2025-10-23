#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

struct Date {
    int d, m, y;
    string original;
};

bool cmp(const Date& a, const Date& b) {
    if (a.y != b.y) return a.y < b.y;
    if (a.m != b.m) return a.m < b.m;
    return a.d < b.d;
}

int main() {
    int n;
    cin >> n;
    cin.ignore();

    vector<Date> dates(n);
    for (int i = 0; i < n; ++i) {
        string s;
        getline(cin, s);
        dates[i].original = s;

        //parse part
        replace(s.begin(), s.end(), '-', ' ');
        stringstream ss(s);
        ss >> dates[i].d >> dates[i].m >> dates[i].y;
    }

    sort(dates.begin(), dates.end(), cmp);

    for (const Date& d : dates) {
        cout << d.original << '\n';
    }
}