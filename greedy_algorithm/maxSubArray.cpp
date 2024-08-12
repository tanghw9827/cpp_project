#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

int maxSubArray(vector<int>& nums){
    int result = INT_MIN;
    int count = 0;
    for(int i = 0; i < nums.size(); i++){
        count += nums[i];
        if(count > result){
            result = count;
        }
        if(count <= 0){
            count = 0;
        }
    }
    return result;
}

int main() {
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    int result = maxSubArray(nums);
    cout << result << endl;
    return 0;
}