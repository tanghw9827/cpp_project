#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

int combinationSum4(vector<int> &nums, int target)
{
    vector<int> dp(target + 1, 0);
    dp[0] = 1;
    for (int j = 0; j <= target; j++)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            if (j >= nums[i] && dp[j] < INT_MAX - dp[j - nums[i]])
            {
                dp[j] += dp[j - nums[i]];
            }
        }
    }
    return dp[target];
}

int main()
{
    int target = 4;
    vector<int> nums = {1, 2, 3};
    int result = combinationSum4(nums, target);
    cout << result << endl;
    return 0;
}