#include <iostream>
#include <vector>
using namespace std;

// Проверка на простоту
bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) { // оптимизация до sqrt(n)
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n; 

    vector<int> primes;         
    vector<int> superPrimes;     

    int number = 2;
    while ((int)superPrimes.size() < n) {
        if (isPrime(number)) {
            primes.push_back(number);
            int index = primes.size(); 
            if (isPrime(index)) { 
                superPrimes.push_back(number);
            }
        }
        number++;
    }

    cout << superPrimes[n - 1];
}
