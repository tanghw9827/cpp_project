#include <iostream>
#include <vector>
#include <string>
using namespace std;

int canJump(vector<int>& nums) {
    int n = nums.size();
    if (n < 2) return 0;
    int result = 0;
    int curEnd = 0;
    int maxReach = 0;
    for(int i = 0; i < n -1; i++){
        maxReach = max(maxReach, i + nums[i]);
        if(i == curEnd){
            result++;
            curEnd = maxReach;
            if(curEnd >= n-1){
                return result;
            }
        }
    }
    return result;
}

int main() {
    vector<int> nums = {2,3,1,1,4};
    int result = canJump(nums);
    cout << result << endl;
    return 0;
}