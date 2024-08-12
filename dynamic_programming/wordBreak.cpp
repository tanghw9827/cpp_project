#include <iostream>
#include <vector>
#include <string>
#include<unordered_set>
using namespace std;

bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
    int n = s.size();
    vector<bool> dp(n+1, false);
    dp[0] = true;
    for(int j = 0; j <= n; j++){
        for(int i = 0; i < j; i++){
            string word (s.begin() + i, s.begin() + j);
            if(wordSet.find(word) != wordSet.end() && dp[i]){
                dp[j] = true;
            }
        }
    }
    return dp[n];
}

int main() {
    string s = "leecode"; 
    vector<string> wordDict = {"lee", "code"};
    bool result = wordBreak(s, wordDict);
    cout << result << endl;
    return 0;
}