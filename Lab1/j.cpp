#include <iostream>
#include <queue>
using namespace std;

int main(){
    char operation;
    int item;
    deque<int> dq;

    while (cin >> operation){
        if (operation == '+'){
            cin >> item;
            dq.push_front(item);
        }
        else if (operation == '-'){
            cin >> item;
            dq.push_back(item);
        }
        else if (operation == '*') {
            if (dq.empty()) {                
                cout << "error" << endl;
            } else {
                int sum = dq.front() + dq.back();
                dq.pop_front();
                if (!dq.empty()) dq.pop_back();
                cout << sum << endl;
            }
        }
        else if (operation == '!'){
            break;
        }
    }
}
