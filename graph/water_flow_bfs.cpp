#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<queue>

using namespace std;

void bfs(const vector<vector<int>> &grid, int i, int j, vector<vector<bool>> &visited, vector<vector<int>> &directions){
    queue<pair<int, int>> que;
    que.push({i, j});
    visited[i][j] = true;
    while(!que.empty()){
        pair<int, int> p = que.front();
        que.pop();
        for(auto direction : directions){
            int new_i = p.first + direction[0];
            int new_j = p.second + direction[1];
            if(new_i >= 0 && new_i < grid.size() && new_j >= 0 && new_j < grid[0].size() && !visited[new_i][new_j] && grid[new_i][new_j] >= grid[p.first ][p.second]){
                que.push({new_i, new_j});
                visited[new_i][new_j] = true;
            }
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
            bfs(grid, i, 0, first_visited, directions);
        }
        if(!second_visited[i][m - 1]){
            bfs(grid, i, m - 1, second_visited, directions);
        }
    }
    for(int j = 0; j < m; j++){
        if(!first_visited[0][j]){
            bfs(grid, 0, j, first_visited, directions);
        }
        if(!second_visited[n - 1][j]){
            bfs(grid, n - 1, j, second_visited, directions);
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