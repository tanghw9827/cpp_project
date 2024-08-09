#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>

using namespace std;

void dfs(const vector<vector<int>> &grid, int i, int j, vector<vector<int>> &visited, vector<vector<int>> &directions, int& count, int mark){
    visited[i][j] = mark;
    count++;
    for(auto direction : directions){
        int new_i = i + direction[0];
        int new_j = j + direction[1];
        if(new_i >= 0 && new_i < grid.size() && new_j >= 0 && new_j < grid[0].size() && !visited[new_i][new_j] && grid[new_i][new_j] == 1){
            dfs(grid, new_i, new_j, visited, directions, count, mark);
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<vector<int>> visited(n, vector<int>(m, 0));
    unordered_map<int, int> mp;
    int mark = 1;
    bool isAllGrid = true;
    int count;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 0){
                isAllGrid = false;
            }
            if(!visited[i][j] && grid[i][j] == 1){
                count = 0;
                dfs(grid, i, j, visited, directions, count, mark);
                mp[mark++] = count;
            }
        }
    }
    if (isAllGrid) {
        cout << n * m << endl; // 如果都是陆地，返回全面积
        return 0; 
    }
    int result = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 0){
                int temp = 1;
                unordered_map<int, int> mp1;
                for(auto direction : directions){
                    int new_i = i + direction[0];
                    int new_j = j + direction[1];
                    if(new_i >= 0 && new_i < n && new_j >= 0 && new_j < m && grid[new_i][new_j] == 1){
                        mp1[visited[new_i][new_j]]++;
                    }
                }
                for(auto it : mp1){
                    temp += mp[it.first];
                }
                result = max(result, temp);
            }
        }
    }
    cout << result << endl;
    return 0;
}