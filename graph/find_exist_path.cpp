#include<iostream>
#include<vector>

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

int main(){
    int n, m;
    cin >> n >> m;
    UnionFind uf(n);
    int s, d;
    for(int i = 0; i < m; i++){
        cin >> s >> d;
        uf.join(s, d);
    }
    int source, destination;
    cin >> source >> destination;
    cout << (uf.isSame(source, destination) ? 1 : 0) << endl;

    return 0;
}