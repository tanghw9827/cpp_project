#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool canJump(vector<int>& nums){
    int maxReach = 0;
    int n = nums.size();
    for(int i = 0; i < n -1; i++){
        if(i > maxReach){
            return false;
        }
        maxReach = max(maxReach, i + nums[i]);
        if(maxReach >= n -1){
            return true;
        }
    }
    return maxReach >= n-1;
}

int main() {
    vector<int> nums = {3,2,1,0,4};
    bool result = canJump(nums);
    cout << result << endl;
    return 0;
}