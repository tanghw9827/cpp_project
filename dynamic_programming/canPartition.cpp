#include<iostream>
#include<vector>

using namespace std;

bool canPartition(vector<int>& nums){
    int target = 0;
    for(int i = 0; i < nums.size(); i++){
        target += nums[i];
    }
    if(target % 2 == 1){
        return false;
    } else{
        target = target / 2;
    }
    vector<int> dp(target+1, 0);
    for(int i = 0; i < nums.size(); i++){
        for(int j = target; j >= nums[i]; j--){
            dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
        }
    }
    return dp[target] == target;
}

int main(){
    vector<int> nums = {1,2,3,5};
    bool result = canPartition(nums);
    cout << result << endl;
    return 0;
}