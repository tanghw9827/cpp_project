#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>

using namespace std;

void bfs(const vector<vector<int>>& grid, int i, int j, vector<vector<int>>& visited, vector<vector<int>>& directions, int& count, int mark) {
    queue<pair<int, int>> que;
    que.push({i, j});
    visited[i][j] = mark;
    count++;
    while (!que.empty()) {
        pair<int, int> p = que.front();
        que.pop();
        for (auto direction : directions) {
            int new_i = p.first + direction[0];
            int new_j = p.second + direction[1];
            if (new_i >= 0 && new_i < grid.size() && new_j >= 0 && new_j < grid[0].size() && !visited[new_i][new_j] && grid[new_i][new_j] == 1) {
                que.push({new_i, new_j});
                visited[new_i][new_j] = mark;
                count++;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<vector<int>> visited(n, vector<int>(n, 0));
    unordered_map<int, int> mp;
    int mark = 1;
    bool isAllGrid = true;
    int count;

    // 标记每个连通分量，并记录其大小
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 0) {
                isAllGrid = false;
            }
            if (!visited[i][j] && grid[i][j] == 1) {
                count = 0;
                bfs(grid, i, j, visited, directions, count, mark);
                mp[mark++] = count;
            }
        }
    }

    if (isAllGrid) {
        cout << n * n << endl; // 如果都是陆地，返回全面积
        return 0; 
    }

    int result = 0;

    // 遍历每个 0，尝试将其变成 1，并计算可能的最大连通区域
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 0) {
                int temp = 1;
                unordered_map<int, int> mp1;
                for (auto direction : directions) {
                    int new_i = i + direction[0];
                    int new_j = j + direction[1];
                    if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < n && grid[new_i][new_j] == 1) {
                        mp1[visited[new_i][new_j]]++;
                    }
                }
                for (auto it : mp1) {
                    temp += mp[it.first];
                }
                result = max(result, temp);
            }
        }
    }

    cout << result << endl;
    return 0;
}
