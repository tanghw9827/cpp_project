#include <iostream>
#include <vector>
#include <string>
using namespace std;

int minDistance(string word1, string word2) {
    int m = word1.size();
    int n = word2.size();
    vector<vector<uint64_t>> dp(m+1, vector<uint64_t>(n+1, 0));
    for (int i = 0; i <= m; i++) dp[i][0] = i;
    for (int j = 0; j <= n; j++) dp[0][j] = j;
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(word1[i-1] == word2[j-1]){
                dp[i][j] = dp[i - 1][j - 1];
            }else{
                dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1);
            }
        }
    }
    return dp[m][n];
}

int main() {
    string word1 = "leetcode";
    string word2 = "etco";
    int result = minDistance(word1, word2);
    cout << result << endl;
    return 0;
}