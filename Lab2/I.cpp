#include <iostream>
#include <list>
#include <string>
using namespace std;

int main(){
    list<string> arr;
    string command;
    while (cin >> command)
    {
        if(command == "exit"){
            cout << "goodbye" << endl;
            break;
        }
        if(command == "add_front"){
            string bookName;
            cin >> bookName;
            arr.push_front(bookName);
            cout << "ok" << endl;
        }
        if(command == "add_back"){
            string bookName;
            cin >> bookName;
            arr.push_back(bookName);
            cout << "ok" << endl;
        }
        if(command == "erase_front"){
            if(!arr.empty()){
                cout << arr.front() << endl;
                arr.pop_front();
            }
            else{
                cout << "error" << endl;
            } 
        }
        if(command == "erase_back"){
            if(!arr.empty()){
                cout << arr.back() << endl;
                arr.pop_back();
            }
            else{
                cout << "error" << endl;
            } 
        }
        if(command == "front"){
            if(!arr.empty()){
                cout << arr.front() << endl;
            }
            else{
                cout << "error" << endl;
            } 
        }
        if(command == "back"){
            if(!arr.empty()){
                cout << arr.back() << endl;
            }
            else{
                cout << "error" << endl;
            }
        }
        if(command == "clear"){
            arr.clear();
            cout << "ok" << endl;
        }
    }
    

}