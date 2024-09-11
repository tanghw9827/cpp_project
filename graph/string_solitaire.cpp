#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>

using namespace std;

struct Node{
  string node;
  int g;
  Node(string node, int g):node(node),g(g){}
};

struct cmp{
    bool operator()(Node* n1, Node* n2){
        return n1->g > n2->g;
    }
};

bool isValid(string cur, string next){
    if(cur.size() != next.size()){
        return false;
    }
    int diff = 0;
    for(int i = 0; i < cur.size(); i++){
        if(cur[i] != next[i]){
            diff++;
            if (diff > 1) return false;
        }
    }
    return diff == 1;
}

void bfs(unordered_set<string>& grid, string& startNode, string& endNode, int& result){
    priority_queue<Node*, vector<Node*>, cmp> pq;
    unordered_set<string> visited; 
    Node* start = new Node(startNode, 1);
    pq.push(start);
    while(!pq.empty()){
        Node* cur = pq.top();
        pq.pop();
        if(cur->node == endNode){
            result = cur->g;
            return;
        }
        visited.insert(cur->node);
        for(auto& word : grid){
            if(!visited.count(word) && isValid(cur->node, word)){
                Node* next = new Node(word, cur->g + 1);
                pq.push(next);
            }
        }
    }
}

int main(){
    int n;
    cin >> n;
    string startNode, endNode;
    cin >> startNode >> endNode;
    unordered_set<string> grid;
    string node;
    for(int i = 0; i < n; i++){
        cin >> node;
        grid.insert(node);
    }
    grid.insert(startNode);
    grid.insert(endNode);
    int result = 0;
    bfs(grid, startNode, endNode, result);
    cout << result << endl;
    return 0;
}