#include <iostream>
#include <list>
using namespace std;

int main(){
    int n;
    cin >> n;
    list<int> lst;

    for(int i = 1; i <= n; i++){
        int t;
        cin >> t;
        if(i % 2 != 0){
            lst.push_back(t);
        }else{
            continue;
        }
    }
    for(int a : lst){
        cout << a << " ";
    }

}