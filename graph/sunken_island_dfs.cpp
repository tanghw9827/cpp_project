#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>

using namespace std;

void dfs(const vector<vector<int>> &grid, int i, int j, vector<vector<int>> &visited, vector<vector<int>> &directions, int mark){
    visited[i][j] = mark;
    for(auto direction : directions){
        int new_i = i + direction[0];
        int new_j = j + direction[1];
        if(new_i >= 0 && new_i < grid.size() && new_j >= 0 && new_j < grid[0].size() && !visited[new_i][new_j] && grid[new_i][new_j] == 1){
            dfs(grid, new_i, new_j, visited, directions, mark);
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
    int dummy_mark = 1;
    for(int i = 0; i < n; i++){
        if(grid[i][0] == 1 && !visited[i][0]){
            dfs(grid, i, 0, visited, directions, dummy_mark);
        }
        if(grid[i][m - 1] == 1 && !visited[i][m - 1]){
            dfs(grid, i, m - 1, visited, directions, dummy_mark);
        }
    }
    for(int j = 0; j < m; j++){
        if(grid[0][j] == 1 && !visited[0][j]){
            dfs(grid, 0, j, visited, directions, dummy_mark);
        }
        if(grid[n - 1][j] == 1 && !visited[n - 1][j]){
            dfs(grid, n - 1, j, visited, directions, dummy_mark);
        }
    }
    int mark = 2;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!visited[i][j] && grid[i][j] == 1){
                dfs(grid, i, j, visited, directions, mark);
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(visited[i][j] == 2){
                grid[i][j] = 0;
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}