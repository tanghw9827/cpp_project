#include <iostream>
#include <vector>
#include <string>
using namespace std;

void backtracking(vector<int>& nums, int startIndex, vector<int>& path, vector<vector<int>>& result){
    result.push_back(path);
    if(startIndex >= nums.size()){
        return;
    }
    for(int i = startIndex; i < nums.size(); i++){
        path.push_back(nums[i]);
        backtracking(nums, i+1, path, result);
        path.pop_back();
    }
}

int main() {
    cout << result << endl;
    return 0;
}