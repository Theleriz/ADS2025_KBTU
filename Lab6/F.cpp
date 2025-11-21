#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <iomanip>
#include <algorithm>

using namespace std;

map<string, double> gpa_map = {
    {"A+", 4.00}, {"A", 3.75}, {"B+", 3.50}, {"B", 3.00},
    {"C+", 2.50}, {"C", 2.00}, {"D+", 1.50}, {"D", 1.00}, {"F", 0.00}
};

struct Student {
    string lastname, firstname;
    double gpa;
};

int main() {
    int n;
    cin >> n;
    vector<Student> students;

    for (int i = 0; i < n; ++i) {
        string last, first;
        int m;
        cin >> last >> first >> m;
        double total = 0, credits = 0;
        for (int j = 0; j < m; ++j) {
            string grade;
            int credit;
            cin >> grade >> credit;
            total += gpa_map[grade] * credit;
            credits += credit;
        }
        students.push_back({last, first, total / credits});
    }

    sort(students.begin(), students.end(), [](const Student &a, const Student &b) {
        if (a.gpa != b.gpa) return a.gpa < b.gpa;
        if (a.lastname != b.lastname) return a.lastname < b.lastname;
        return a.firstname < b.firstname;
    });

    for (const auto &s : students)
        cout << s.lastname << " " << s.firstname << " " << fixed << setprecision(3) << s.gpa << "\n";

}
