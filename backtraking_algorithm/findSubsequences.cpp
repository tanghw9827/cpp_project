class Solution {
public:
    void backtracking(vector<int>& nums, int index, vector<int>& path,
                      vector<vector<int>>& result) {
        if (path.size() > 1) {
            result.push_back(path);
        }
        if (index == nums.size()) return;
        unordered_set<int> uset;
        for (int i = index; i < nums.size(); i++) {
            if ((uset.find(nums[i]) != uset.end() ||
                (!path.empty() && nums[i] < path.back()))) {
                continue;
            }
            uset.insert(nums[i]);
            path.push_back(nums[i]);
            backtracking(nums, i + 1, path, result);
            path.pop_back();
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> path;
        backtracking(nums, 0, path, result);
        return result;
    }
};