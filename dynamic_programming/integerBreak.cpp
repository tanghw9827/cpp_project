#include<iostream>
#include<vector>

using namespace std;

int integerBreak(int n){
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= i/2; j++){
            dp[i] = max(dp[i], max(j * dp[i-j], j*(i-j)));
        }
    }
    return dp[n];
}

int main(){
    int n;
    cin >> n;
    int result = integerBreak(n);
    cout << result << endl;
    return 0;
}