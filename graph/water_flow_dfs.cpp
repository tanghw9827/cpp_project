#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>

using namespace std;

void dfs(const vector<vector<int>> &grid, int i, int j, vector<vector<bool>> &visited, vector<vector<int>> &directions){
    visited[i][j] = true;
    for(auto direction : directions){
        int new_i = i + direction[0];
        int new_j = j + direction[1];
        if(new_i >= 0 && new_i < grid.size() && new_j >= 0 && new_j < grid[0].size() && !visited[new_i][new_j] && grid[new_i][new_j] >= grid[i][j]){
            dfs(grid, new_i, new_j, visited, directions);
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
    vector<vector<bool>> first_visited(n, vector<bool>(m, false));
    vector<vector<bool>> second_visited(n, vector<bool>(m, false));
    for(int i = 0; i < n; i++){
        if(!first_visited[i][0]){
            dfs(grid, i, 0, first_visited, directions);
        }
        if(!second_visited[i][m - 1]){
            dfs(grid, i, m - 1, second_visited, directions);
        }
    }
    for(int j = 0; j < m; j++){
        if(!first_visited[0][j]){
            dfs(grid, 0, j, first_visited, directions);
        }
        if(!second_visited[n - 1][j]){
            dfs(grid, n - 1, j, second_visited, directions);
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if( first_visited[i][j] && second_visited[i][j]){
                cout << i << " " << j << endl;
            }
        }
    }
    return 0;
}