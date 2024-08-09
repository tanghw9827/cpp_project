#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>

using namespace std;

void topoSort(unordered_map<int, vector<int>> &grid, vector<int> &inDegree, int n, vector<int> &path){
    queue<int> q;
    for(int i = 0; i < n; i++){
        if(inDegree[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int node = q.front();
        q.pop();
        path.push_back(node);
        for(auto neighbour: grid[node]){
            inDegree[neighbour]--;
            if(inDegree[neighbour] == 0){
                q.push(neighbour);
            }
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    unordered_map<int, vector<int>> grid;
    vector<int> inDegree(n, 0);
    int s, t;
    for(int i = 0; i < m; i++){
        cin >> s >> t;
        grid[s].push_back(t);
        inDegree[t]++;
    }
    vector<int> path;
    topoSort(grid, inDegree, n, path);
    if(path.size() != n){
        cout << -1;
        return 0;
    }
    for(int i = 0; i < path.size() -1; i++){
        cout << path[i] << " ";
    }
    cout << path[path.size() - 1];
    return 0;
}