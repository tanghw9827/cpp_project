#include <iostream>
#include <vector>
#include <string>
using namespace std;

int lengthOfLIS(vector<int>& nums) {
    int result = 1;
    int n = nums.size();
    vector<int> dp(n, 1);
    for(int j = 0; j < n; j++){
        for(int i = 0; i < j; i++){
            if(nums[j] > nums[i]){
                dp[j] = max(dp[j], dp[i] + 1);
            }
        }
        if (dp[j] > result) result = dp[j];
    }
    return result;
}

int main() {
    vector<int> nums = {10,9,2,5,3,7,101,18};
    int result = lengthOfLIS(nums);
    cout << result << endl;
    return 0;
}