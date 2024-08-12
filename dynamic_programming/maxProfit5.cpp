#include <iostream>
#include <vector>
#include <string>
using namespace std;

int maxProfit(vector<int>& prices, int fee){
    int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, 0));
        dp[0][0] -= prices[0]; 
        for (int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i] - fee);
        }
        return max(dp[n - 1][0], dp[n - 1][1]);
    return dp[n-1][0];
}

int main() {
    vector<int> prices = {1,3,2,8,4,9};
    int fee = 2;
    int result = maxProfit(prices, fee);
    cout << result << endl;
    return 0;
}