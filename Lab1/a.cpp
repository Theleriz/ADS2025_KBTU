#include <iostream>
#include <deque>
#include <vector>
using namespace std;

void solution(int n){
    vector<int> arr(n);
    
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    deque<int> dq;
    for(int k = 0 ; k < n; k++){
        int num = arr[k];
        dq.push_front(num);

        for(int i = num; i > 1; i--) {
            dq.push_front(i-1);
            for(int j = 1; j < i; j++) {
                int temp = dq.back();
                dq.pop_back();
                dq.push_front(temp);
            }
        }
        for(int i = 0;i < arr[k];i++){
            cout << dq[i]<< " ";
        }
        cout << endl;
        dq.clear();
    }

}
int main() {
    int n;
    cin >> n;

    solution(n);
}