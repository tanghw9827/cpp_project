#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<climits>
#include<memory>

using namespace std;

struct Node{
    int x, g;
    shared_ptr<Node> parent;
    Node(int x, int g, shared_ptr<Node> parent = nullptr): x(x), g(g), parent(parent){}
};

struct cmp{
    bool operator()(shared_ptr<Node>& n1, shared_ptr<Node>& n2){
        return n1->g > n2->g;
    }
};

void dijkstra(vector<vector<int>>& grid, int startNode, int endNode, int& result){
    priority_queue<shared_ptr<Node>, vector<shared_ptr<Node>>, cmp> pq;
    unordered_map<int, bool> visited;
    pq.push(make_shared<Node>(startNode, 0));
    while(!pq.empty()){
        shared_ptr<Node> node = pq.top();
        pq.pop();
        if(node->x == endNode){
            result = node->g;
            break;
        }
        if(visited[node->x]) continue;
        visited[node->x] = true;
        for(int i = 1; i < grid[node->x].size(); i++){
            if(grid[node->x][i] != INT_MAX && !visited[i]){
                pq.push(make_shared<Node>(i, node->g + grid[node->x][i], node));
            }
        }
    }

}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n + 1, vector<int>(n + 1, INT_MAX));
    int s, t, w;
    for(int i = 0; i < m; i++){
        cin >> s >> t >> w;
        grid[s][t] = w;
    }
    int startNode = 1;
    int endNode = n;
    int result = 0;
    dijkstra(grid, startNode, endNode, result);
    cout << result << endl;
    return 0;
}