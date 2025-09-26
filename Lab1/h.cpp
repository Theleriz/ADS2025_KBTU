#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int n){
    vector<int> primeList;
    if (n == 1) return false;
    else{    
        for(int i = 1; i * i < n; i++){
            if(n % i == 0){
                primeList.push_back(i);
            }
        }
        if(primeList.size() == 1){
            return true;
        }
        else{
            return false;
        }
    }
}

int main(){
    int n;
    cin >> n;
    if(isPrime(n)){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
}