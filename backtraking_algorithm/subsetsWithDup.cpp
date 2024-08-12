void backtracking(vector<int>& nums, int startIndex, vector<bool>& used, vector<int>& path, vector<vector<int>>& result){
    result.push_back(path);
    if(startIndex >= nums.size()){
        return;
    }
    for(int i = startIndex; i < nums.size(); i++){
        if(i > 0 && nums[i] == nums[i-1] && used[i-1] == false){
            continue;
        }
        path.push_back(nums[i]);
        used[i] = true;
        backtracking(nums, i+1, used, path, result);
        used[i] = false;
        path.pop_back();
    }
}

sort(nums.begin(), nums.end());