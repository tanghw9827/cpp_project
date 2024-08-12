#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

int numSquares(int n)
{
    vector<int> nums;
    for (int i = 1; i * i <= n; i++)
    {
        nums.push_back(i * i);
    }
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = nums[i]; j <= n; j++)
        {
            if (dp[j - nums[i]] != INT_MAX)
            {
                dp[j] = min(dp[j - nums[i]] + 1, dp[j]);
            }
        }
    }
    if (dp[n] == INT_MAX)
        return -1;
    return dp[n];
}

int main()
{
    int n = 12;
    int result = numSquares(n);
    cout << result << endl;
    return 0;
}