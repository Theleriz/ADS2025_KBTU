#include <iostream>
#include <list>

using namespace std;

int main () {
    int n;
    cin >> n;

    list<int> lst;

    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        lst.push_back(x);
    }

    
    int number, pos;
    cin >> number >> pos;


    if(pos <= lst.size()) {
        auto head = lst.begin();
        advance(head, pos);
        lst.insert(head, number);
    }
    if(pos > lst.size()){
        auto tail = lst.end();
        lst.insert(tail, number);
    }

    for(int item : lst){
        cout << item << " ";
    }
}