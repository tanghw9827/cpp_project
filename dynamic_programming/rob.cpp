#include <iostream>
#include <vector>
#include <string>
using namespace std;

int rob(vector<int> nums)
{
    int n = nums.size();
    vector<int> dp(n);
    if (n < 2)
        return nums[0];
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for (int i = 2; i < n; i++)
    {
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
    }
    return dp[n - 1];
}

int main()
{
    vector<int> nums = {1, 2, 3, 1};
    int result;
    if (nums.size() == 1)
    {
        result = nums[0];
    }
    else
    {
        result = max(rob(vector<int>(nums.begin(), nums.end() - 1)), rob(vector<int>(nums.begin() + 1, nums.end())));
    }
    cout << result << endl;
    return 0;
}