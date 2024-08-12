#include <iostream>
#include <vector>
#include <string>
using namespace std;

int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    int result = 1;
    vector<int> dp(n, 1);
    for (int j = 1; j < n; j++)
    {
        if (nums[j] > nums[j-1])
        {
            dp[j] = dp[j - 1] + 1;
        }
        if (dp[j] > result) result = dp[j];
    }
    return result;
}

int main()
{
    vector<int> nums = {1, 3, 5, 4, 7};
    int result = lengthOfLIS(nums);
    cout << result << endl;
    return 0;
}