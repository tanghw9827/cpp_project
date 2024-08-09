#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<climits>
#include<queue>

using namespace std;

void bfs(const vector<vector<int>> &grid, int i, int j, vector<vector<bool>> &visited, vector<vector<int>> &directions, int &count){
    queue<pair<int, int>> que;
    que.push({i, j});
    visited[i][j] = true;
    while(!que.empty()){
        pair<int, int> p = que.front();
        que.pop();
        for(auto direction : directions){
            int new_i = p.first + direction[0];
            int new_j = p.second + direction[1];
            if(new_i >= 0 && new_i < grid.size() && new_j >= 0 && new_j < grid[0].size() && !visited[new_i][new_j] && grid[new_i][new_j] == 1){
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
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int count;
    int result = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!visited[i][j] && grid[i][j] == 1){
                count = 0;
                dfs(grid, i, j, visited, directions, count);
                result = max(result, count);
            }
        }
    }
    cout << result << endl;
    return 0;
}