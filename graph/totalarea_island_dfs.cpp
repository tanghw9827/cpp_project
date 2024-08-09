#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>

using namespace std;

void dfs(const vector<vector<int>> &grid, int i, int j, vector<vector<bool>> &visited, vector<vector<int>> &directions, int &count){
    visited[i][j] = true;
    count++;
    for(auto direction : directions){
        int new_i = i + direction[0];
        int new_j = j + direction[1];
        if(new_i >= 0 && new_i < grid.size() && new_j >= 0 && new_j < grid[0].size() && !visited[new_i][new_j] && grid[new_i][new_j] == 1){
            dfs(grid, new_i, new_j, visited, directions, count);
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
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int dummy_count = 0;
    for(int i = 0; i < n; i++){
        if(grid[i][0] == 1 && !visited[i][0]){
            dfs(grid, i, 0, visited, directions, dummy_count);
        }
        if(grid[i][m - 1] == 1 && !visited[i][m - 1]){
            dfs(grid, i, m - 1, visited, directions, dummy_count);
        }
    }
    for(int j = 0; j < m; j++){
        if(grid[0][j] == 1 && !visited[0][j]){
            dfs(grid, 0, j, visited, directions, dummy_count);
        }
        if(grid[n - 1][j] == 1 && !visited[n - 1][j]){
            dfs(grid, n - 1, j, visited, directions, dummy_count);
        }
    }
    int count;
    int result = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!visited[i][j] && grid[i][j] == 1){
                count = 0;
                dfs(grid, i, j, visited, directions, count);
                result += count;
            }
        }
    }
    cout << result << endl;
    return 0;
}