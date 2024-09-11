#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <memory>
using namespace std;

struct Node {
    int x, y, g;
    Node(int x, int y, int g) : x(x), y(y), g(g) {}
};

struct cmp {
    bool operator()(shared_ptr<Node>& n1, shared_ptr<Node>& n2) {
        return n1->g > n2->g;
    }
};

void dijkstra(vector<vector<char>>& graph, shared_ptr<Node> startNode, shared_ptr<Node> endNode, int& result) {
    int n = graph.size();
    int m = graph[0].size();
    priority_queue<shared_ptr<Node>, vector<shared_ptr<Node>>, cmp> openSet;
    vector<vector<bool>> closeSet(n, vector<bool>(m, false));
    openSet.push(startNode);
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    while(!openSet.empty()){
        shared_ptr<Node> cur = openSet.top();
        openSet.pop();
        if(cur->x == endNode->x && cur->y == endNode->y){
            result = cur->g;
            return;
        }
        if (closeSet[cur->x][cur->y]) continue;
        closeSet[cur->x][cur->y] = true;
        for(auto dir : directions){
            int nx = cur->x + dir[0];
            int ny = cur->y + dir[1];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && !closeSet[nx][ny] && graph[nx][ny] != '*'){
                shared_ptr<Node> node = make_shared<Node>(nx, ny, cur->g + 1);
                openSet.push(node);
            }
        }
    }
    result = -1;
}

int main() {
    int n, m;
    cin >> n >> m;
    int start_x, start_y, end_x, end_y;
    cin >> start_x >> start_y >> end_x >> end_y;
    start_x--;
    start_y--;
    end_x--;
    end_y--;
    vector<vector<char>> graph(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
        }
    }
    shared_ptr<Node> startNode = make_shared<Node>(start_x, start_y, 0);
    shared_ptr<Node> endNode = make_shared<Node>(end_x, end_y, 0); 
    int result = 0;
    dijkstra(graph, startNode, endNode, result);
    cout << result << endl;
    return 0;
}