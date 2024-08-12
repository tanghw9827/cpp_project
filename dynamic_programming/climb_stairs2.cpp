#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

int combinationSum4(int n, int m)
{
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int j = 0; j <= n; j++)
    {
        for (int i = 1; i <= m; i++)
        {
            if (j >= i && dp[j] < INT_MAX - dp[j - i])
            {
                dp[j] += dp[j - i];
            }
        }
    }
    return dp[n];
}

int main()
{
    int n, m;
    cin >> n >> m;
    int result = combinationSum4(n, m);
    cout << result << endl;
    return 0;
}