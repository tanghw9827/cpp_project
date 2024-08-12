#include<iostream>
#include<vector>
#include<string>
using namespace std;

int findMaxForm(vector<string> strs, int m, int n){
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    int zeroNum, oneNum;
    for(int i = 0; i < strs.size(); i++){
        zeroNum = 0;
        oneNum = 0;
        for(char& c : strs[i]){
            if(c == '0'){
                zeroNum++;
            }
            else{
                oneNum++;
            }
        }
        for(int j = m; j >= zeroNum; j--){
            for(int k = n; k >= oneNum; k--){
                dp[j][k] = max(dp[j][k], dp[j-zeroNum][k-oneNum]+1);
            }
        }
    }
    return dp[m][n];
}

int main(){
    int m = 5, n = 3;
    vector<string> strs = {"10", "0001", "111001", "1", "0"};
    int result = findMaxForm(strs, m, n);
    cout << result << endl;
    return 0;
}
