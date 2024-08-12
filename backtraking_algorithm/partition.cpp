#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isPalindrome(string s, int start, int end){
    for(int i = start, j = end; i <= j; i++,j--){
        if(s[i] != s[j]){
            return false;
        }
    }
    return true;
}

void backtracking(string s, int startIndex, vector<string>& path, vector<vector<string>>& result){
    if(startIndex == s.size()){
        result.push_back(path);
        return;
    }
    for(int i = startIndex; i < s.size(); i++){
        if(isPalindrome(s, startIndex, i)){
            path.push_back(s.substr(startIndex, i-startIndex+1));
        }else{
            continue;
        }
        backtracking(s,i+1,path, result);
        path.pop_back();
    }
}

int main() {
    // cout << result << endl;
    return 0;
}