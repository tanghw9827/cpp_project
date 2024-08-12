#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

    void backtracking(vector<int>& candidates, int target, int startIndex, vector<bool>& used, int& sum, vector<int>& path,
                      vector<vector<int>>& result) {
        if (sum > target) {
            return;
        }           
        if (sum == target) {
            result.push_back(path);
            return;
        }
        for (int i = startIndex; i < candidates.size();  i++) {
            if(i > 0 && candidates[i] == candidates[i-1] && used[i -1] == false){
                continue;
            }
            path.push_back(candidates[i]);
            sum += candidates[i];
            used[i] = true;
            backtracking(candidates, target, i, used, sum, path, result);
            sum -= candidates[i];
            used[i] = false;
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> path;
        int startIndex = 0;
        int sum = 0;
        vector<bool> used(candidates.size(), false);
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, startIndex+1, used, sum, path, result);
        return result;
    }

int main() {
    // int n = 7;
    // int k = 3;
    // vector<vector<int>> result = combine(n, k);
    // for(int i = 0; i < result.size(); i++){
    //     cout << result[i][0] << " " << result[i][1] << endl;
    // }
    return 0;
}