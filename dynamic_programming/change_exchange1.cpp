#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

int coinChange(int n, vector<int> &coins)
{
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 0; i < coins.size(); i++)
    {
        for (int j = coins[i]; j <= n; j++)
        {
            if (dp[j - coins[i]] != INT_MAX)
            {
                dp[j] = min(dp[j - coins[i]] + 1, dp[j]);
            }
        }
    }
    if (dp[n] == INT_MAX) return -1;
    return dp[n];
}

int main()
{
    int n = 11;
    vector<int> coins = {1, 2, 5};
    int result = coinChange(n, coins);
    cout << result << endl;
    return 0;
}