#include <iostream>
using namespace std;

bool isPrime(int number){
    bool answer = true;
    for(int i = 2; i < number; i++){
        if(number % i == 0){
            answer = false;
            break;
        }
    }
    return answer;
}

int main(){
    cout << "hello world" << endl;
    bool ans = isPrime(5);
    if (ans){
        cout << "yes";
    }
    else{
        cout << "no";
    }

} 