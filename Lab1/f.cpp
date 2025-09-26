#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int n){
    if (n == 1) return false;
    else{    
        for(int i = 2; i * i <= n; i++){
            if(n % i == 0) return false;
        }
        return true;
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> primeList;

    int index = 2;
    int size = 0;
    while(size < n){
        if(isPrime(index)){
            primeList.push_back(index);
            size++;
        }
        index++;
    }

    
}