#include <iostream>
#include <string>
#include <stack>
using namespace std;

string solution(string s){
    stack<char> st;
    string resultString;

    for(int i = 0; i < s.size(); i++){
        char c = s[i];

        if(c != '#'){
            st.push(c);
        }else if(!st.empty()){
            st.pop();
        }
    }

    while(!st.empty()){
        resultString.push_back(st.top());
        st.pop();
    }
    return resultString;
}

int main(){
    string s1, s2;
    cin >> s1 >> s2;

    string res1 = solution(s1);
    string res2 = solution(s2);

    if(res1 == res2){
        cout << "Yes";
    }
    else{
        cout << "No";
    }
}