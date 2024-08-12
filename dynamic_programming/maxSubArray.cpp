#include <iostream>
#include <vector>
#include <string>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 0);
    dp[0] = nums[0];
    int result = dp[0];
    for(int i = 1; i < n; i++){
        dp[i] = max(nums[i], dp[i-1] + nums[i]);
        if (dp[i] > result) result = dp[i];
    }
    return result;
}

int main() {
    vector<int> nums = {1};
    int result = maxSubArray(nums);
    cout << result << endl;
    return 0;
}