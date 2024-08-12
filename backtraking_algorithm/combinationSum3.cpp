#include <iostream>
#include <vector>
#include <string>
using namespace std;

void backtracking(int n, int k, int startIndex, int& sum, vector<int>& path, vector<vector<int>>& result){
    if (sum > n) { 
        return; 
    }
    if(path.size() == k && sum == n){
        result.push_back(path);
        return;
    }
    for(int i = startIndex; i <= 9 - (k - path.size()) + 1; i++){
        path.push_back(i);
        sum += i;
        backtracking(n, k, i+1, sum, path, result);
        sum -= i;
        path.pop_back();
    }
}

vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> result;
    vector<int> path;
    int startIndex = 1;
    int sum = 0;
    backtracking(n, k, startIndex, sum, path, result);
    return result;
}

int main() {
    int n = 7;
    int k = 3;
    vector<vector<int>> result = combine(n, k);
    for(int i = 0; i < result.size(); i++){
        cout << result[i][0] << " " << result[i][1] << endl;
    }
    return 0;
}