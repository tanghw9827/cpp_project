#include <iostream>
#include <vector>
#include <string>
using namespace std;

int longestCommonSubsequence(string text1, string text2) {
    int m = text1.size();
    int n = text2.size();
    int result = 0;
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(text1[i-1] == text2[j-1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j-1]);
            }
            if (dp[i][j] > result) result = dp[i][j];
        }
    }
    return result;
}

int main() {
    string text1 = "abcde";
    string text2 = "ace";
    int result = longestCommonSubsequence(text1, text2);
    cout << result << endl;
    return 0;
}