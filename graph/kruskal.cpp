#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class UnionFind{
private:
    vector<int> parent;
    vector<int> n;
public:
    UnionFind(int n){
        parent.resize(n+1);
        for(int i = 1; i <= n; i++){
            parent[i] = i;
        }
    }

    int find(int u){
        return u == parent[u] ? u : parent[u] = find(parent[u]);
    }

    bool isSame(int u, int v){
        return find(u) == find(v);
    }

    void join(int u, int v){
        int root_u = find(u);
        int root_v = find(v);
        if(root_u != root_v){
            parent[root_u] = root_v;
        }
    }
};

// 用于表示图中的边
struct Edge {
    int u, v;    // 边的两个端点
    int weight;  // 边的权值
    Edge(int u, int v, int weight) : u(u), v(v), weight(weight) {}
};

// 自定义比较函数，用于 priority_queue
struct Compare {
    bool operator()(const Edge& a, const Edge& b) {
        return a.weight > b.weight; // 按权值从小到大排序
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    priority_queue<Edge, vector<Edge>, Compare> pq; // 最小堆
    int s, t, w;
    for (int i = 0; i < m; i++) {
        cin >> s >> t >> w;
        pq.emplace(s, t, w);
    }

    UnionFind uf(n);
    int result = 0, edges_used = 0;

    while (!pq.empty() && edges_used < n - 1) {
        Edge currentEdge = pq.top();
        pq.pop();

        if (uf.find(currentEdge.u) != uf.find(currentEdge.v)) {
            uf.join(currentEdge.u, currentEdge.v);
            result += currentEdge.weight;
            edges_used++;
        }
    }

    cout << result << endl;
    return 0;
}
