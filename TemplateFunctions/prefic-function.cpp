#include <iostream>
#include <vector>
#include <string>

std::vector<int> prefix_function(std::string &s) {
    int n = s.size();
    std::vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j]) pi[i] = j + 1;
    }
    return pi;
}

std::vector<int> test_prefix_function(std::string &image){
    std::vector<int> pi(image.size(), 0);
    int j = 0;
    int i = 1;
    if(image[i] == image[j]){
        pi[i] = j + 1;
        i++;
        j++;
    }
    else if (j == 0){
        pi[i] = 0;
        i++;
    }
    else{
        j = pi[j - 1];
    }

    return pi;
}

int main(){
    std::string s = "abbaabbab";
    std::vector<int> result = test_prefix_function(s);
    for(int i : result){
        std::cout << i << " ";
    }
    return 0;
}
