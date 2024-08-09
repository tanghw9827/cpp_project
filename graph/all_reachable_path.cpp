#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>

using namespace std;

void dfs(const unordered_map<int, list<int>>& adj, int startNode, int endNode, vector<int> &path, vector<vector<int>> &result){
    if(startNode == endNode){
        result.push_back(path);
        return;
    }
    if(adj.find(startNode) != adj.end()){
        for(const auto& node : adj.at(startNode)){
            path.push_back(node);
            dfs(adj, node, endNode, path, result);
            path.pop_back();
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    unordered_map<int, list<int>> adj;
    int s, t;
    for(int i = 0; i < m; i++){
        cin >> s >> t;
        adj[s].push_back(t);
    }
    vector<int> path;
    vector<vector<int>> result;
    int startNode = 1;
    int endNode = n;
    path.push_back(startNode);
    dfs(adj, startNode, endNode, path, result);
    if (result.size() == 0) cout << -1 << endl;
    for(auto path : result){
        for(int i = 0; i < path.size() -1; i++){
            cout << path[i] << " ";
        }
        cout << path[path.size()-1] << endl;
    }
    return 0;
}