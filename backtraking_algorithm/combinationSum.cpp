#include <iostream>
#include <vector>
#include <string>
using namespace std;

    void backtracking(vector<int>& candidates, int target, int startIndex, int& sum, vector<int>& path,
                      vector<vector<int>>& result) {
        if (sum > target) {
            return;
        }           
        if (sum == target) {
            result.push_back(path);
            return;
        }
        for (int i = startIndex; i < candidates.size();  i++) {
            path.push_back(candidates[i]);
            sum += candidates[i];
            backtracking(candidates, target, i, sum, path, result);
            sum -= candidates[i];
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> path;
        int startIndex = 0;
        int sum = 0;
        backtracking(candidates, target, startIndex, sum, path, result);
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