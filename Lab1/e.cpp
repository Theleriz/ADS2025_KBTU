#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> boris, nursik;
    
    for (int i = 0; i < 5; i++) {
        int t; 
        cin >> t;
        boris.push(t);
    }
    for (int i = 0; i < 5; i++) {
        int t; 
        cin >> t;
        nursik.push(t);
    }

    int moves = 0;
    int LIMIT = 1000000;

    while (!boris.empty() && !nursik.empty() && moves < LIMIT) {
        int b = boris.front(); boris.pop();
        int n = nursik.front(); nursik.pop();

        bool borisWins;
        if (b == 0 && n == 9) borisWins = true;    
        else if (b == 9 && n == 0) borisWins = false;  
        else borisWins = (b > n);

        if (borisWins) {
            boris.push(b);
            boris.push(n);
        } else {
            nursik.push(b);
            nursik.push(n);
        }
        moves++;
    }

    if (moves >= LIMIT) {
        cout << "blin nichya";
    } else if (nursik.empty()) {
        cout << "Boris " << moves;
    } else {
        cout << "Nursik " << moves;
    }
}
