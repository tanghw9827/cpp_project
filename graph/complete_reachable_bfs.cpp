#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<list>

using namespace std;

void bfs(const unordered_map<int, list<int>>& grid, const int& startNode, vector<bool>& closeList){
    queue<int> openList;
    openList.push(startNode);
    while(!openList.empty()){
        int current = openList.front();
        openList.pop();
        closeList[current] = true;
        if(grid.find(current) != grid.end()){
            for(const int& nextNode : grid.at(current)){
                if(closeList[nextNode]){
                    continue;
                }
                openList.push(nextNode);
            }
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    unordered_map<int, list<int>> grid;
    int s, t;
    for(int i = 0; i < m; i++){
        cin >> s >> t;
        grid[s].push_back(t);
    }
    vector<bool> closeList(n + 1, false);
    int startNode = 1;
    bfs(grid, startNode, closeList);
    for(int i = 1; i <= n; i++){
        if(!closeList[i]){
            cout << -1 << endl;
            return 0;
        }
    }
    cout << 1 << endl;
    return 0;
}
