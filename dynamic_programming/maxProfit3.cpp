#include <iostream>
#include <vector>
#include <string>
using namespace std;

int maxProfit(vector<int> &prices, int count)
{
    int n = prices.size();
    int m = 2 * count + 1;
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for (int j = 1; j < m; j += 2)
    {
        dp[0][j] = -prices[0];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (j % 2)
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] - prices[i]);
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + prices[i]);
            }
        }
    }
    return dp[n-1][m-1];
}

int main()
{
    vector<int> prices = {7, 6, 4, 3, 1};
    int count = 2;
    int result = maxProfit(prices, count);
    cout << result << endl;
    return 0;
}