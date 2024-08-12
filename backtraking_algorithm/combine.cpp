#include <iostream>
#include <vector>
#include <string>
using namespace std;

void backtracking(int n, int k, int startIndex, vector<int>& path, vector<vector<int>>& result){
    if(path.size() == k){
        result.push_back(path);
        return;
    }
    for(int i = startIndex; i <= n - (k - path.size()) + 1; i++){
        path.push_back(i);
        backtracking(n, k, i+1, path, result);
        path.pop_back();
    }
}

vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> result;
    vector<int> path;
    int startIndex = 1;
    backtracking(n, k, startIndex, path, result);
    return result;
}

int main() {
    int n = 4;
    int k = 2;
    vector<vector<int>> result = combine(n, k);
    for(int i = 0; i < result.size(); i++){
        cout << result[i][0] << " " << result[i][1] << endl;
    }
    return 0;
}