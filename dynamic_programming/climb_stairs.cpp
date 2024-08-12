#include<iostream>
#include<vector>

using namespace std;

int climbStairs(int n){
    vector<int> dp(n+1, 0);
    if(n < 2) return n;
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i <= n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

int main(){
    int n;
    cin >> n; 
    int result = climbStairs(n);
    cout << result << endl;
    return 0;
}