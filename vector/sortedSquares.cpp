class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result(nums.size(), 0);
        int left = 0;
        int right = nums.size()-1;
        int i = nums.size()-1;
        while(left <= right){
            if(nums[left]* nums[left] >= nums[right]*nums[right]){
                result[i--] = nums[left]* nums[left];
                left++;
            }else{
                result[i--] = nums[right]* nums[right];
                right--;
            }
        }
        return result;
    }
};