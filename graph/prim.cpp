#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>
using namespace std;

void prim(const vector<vector<int>> &grid, int startNode, int &result) {
    // 使用优先队列存储边，按边权值排序 <权值, 节点>
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    unordered_map<int, bool> visited; // 记录哪些节点已加入MST
    pq.push({0, startNode}); // 将起始节点加入队列，权值为0

    while (!pq.empty()) {
        // 获取当前优先级队列中权值最小的边
        auto [weight, u] = pq.top();
        pq.pop();

        // 如果节点u已经被访问过，跳过
        if (visited[u]) continue;

        // 将节点u标记为已访问
        visited[u] = true;
        result += weight; // 累加权值

        // 更新与节点u相连的所有未访问节点的边
        for (int v = 1; v <= grid.size() - 1; v++) {
            if (grid[u][v] != INT_MAX && !visited[v]) {
                pq.push({grid[u][v], v});
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n + 1, vector<int>(n + 1, INT_MAX));
    int s, t, w;
    for (int i = 0; i < m; i++) {
        cin >> s >> t >> w;
        grid[s][t] = w;
        grid[t][s] = w;
    }
    int startNode = 1;
    int result = 0;
    prim(grid, startNode, result);
    cout << result << endl;
    return 0;
}
