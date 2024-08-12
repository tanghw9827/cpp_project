#include <iostream>
#include <vector>
#include <string>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    if (n == 0) return 0;
    vector<vector<int>> dp(n, vector<int>(4, 0)); // 0:持有股票 1：保持卖出股票的状态 2： 卖出当天 3：冷冻期
    dp[0][0] = -prices[0];
    for(int i = 1; i < n; i++){
        dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][3] - prices[i], dp[i - 1][1] - prices[i]));
        dp[i][1] = max(dp[i-1][1], dp[i-1][3]);
        dp[i][2] = dp[i-1][0] + prices[i];
        dp[i][3] = dp[i-1][2];
    }
    return max(dp[n - 1][1], max(dp[n - 1][2], dp[n - 1][3]));
}

int main()
{
    vector<int> prices = {1,2,3,0,2};
    int result = maxProfit(prices);
    cout << result << endl;
    return 0;
}