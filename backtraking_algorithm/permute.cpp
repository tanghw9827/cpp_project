class Solution {
public:
    void backtracking(vector<int>& nums, vector<int>& used, vector<int>& path, vector<vector<int>>& result){
        if(path.size() == nums.size()){
            result.push_back(path);
        }
        for(int i = 0; i < nums.size(); i++){
            if(used[i]) continue;
            path.push_back(nums[i]);
            used[i] = true;
            backtracking(nums,used,path,result);
            used[i] = false;
            path.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> path;
        vector<int> used(nums.size(),false);
        backtracking(nums,used,path,result);
        return result;
    }
};