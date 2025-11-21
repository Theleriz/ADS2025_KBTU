#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <iomanip>
#include <algorithm>

using namespace std;

double GPA(const string& grade) {
    if (grade == "A+") return 4.0;
    else if (grade == "A") return 3.75;
    else if (grade == "B+") return 3.5;
    else if (grade == "B") return 3.0;
    else if (grade == "C+") return 2.5;
    else if (grade == "C") return 2.0;
    else if (grade == "D+") return 1.5;
    else if (grade == "D") return 1.0;
    else return 0.0;
}

struct record{
    string lastname;
    string firstname;
    double gpa;
};

bool cmp(const record& a, const record& b) {
    if(a.gpa != b.gpa) {
        return a.gpa < b.gpa;
    }
    if (a.lastname != b.lastname) return a.lastname < b.lastname;
    return a.firstname < b.firstname;
}

void merge(vector<record>& arr, int left, int mid, int right) { 
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<record> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (cmp(L[i], R[j])) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(vector<record>& arr, int left, int right) {
    if (left >= right) return;

    int mid = (left + right) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<record> students;
    for(int i = 0; i < n; i++) {
        string lastname, firstname;
        int predmety;
        cin >> lastname >> firstname >> predmety;

        double totalpoints = 0.0;
        int totalcredits = 0;


        for(int j = 0; j < predmety; j++) {
            string grade;
            int credits;
            cin >> grade >> credits;
            totalpoints += GPA(grade) * credits;
            totalcredits += credits;
        }

        double gpa = totalpoints / totalcredits;
        students.push_back({lastname, firstname, gpa});
    }
    mergeSort(students, 0, students.size() - 1);
    for(auto it = students.begin(); it != students.end(); ++it) {
        cout << it->lastname << " " << it->firstname << " ";
        cout << fixed << setprecision(3) << it->gpa << endl;
    }
}