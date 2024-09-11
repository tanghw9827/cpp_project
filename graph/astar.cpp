#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<climits>
#include<memory>
#include<cmath>
#include<algorithm>

using namespace std;

const int BOARD_SIZE = 1000;

struct Node{
    int x, y;
    double g, h;
    shared_ptr<Node> parent;
    Node(int x, int y, double g, double h, shared_ptr<Node> parent = nullptr): x(x), y(y), g(g), h(h), parent(parent){}
    double getF() const{
        return g + h;
    }
};

struct cmp{
    bool operator()(shared_ptr<Node> a, shared_ptr<Node> b){
        return a->getF() > b->getF();
    }
};

double heuristic(int x1, int y1, int x2, int y2){
    return pow(x1 - x2, 2) + pow(y1 - y2, 2);
}

vector<pair<int, int>> nextNodeGenerator(int x, int y) {
    return {
        {x + 2, y - 1},
        {x - 2, y + 1},
        {x + 1, y - 2},
        {x - 1, y + 2},
        {x - 2, y - 1},
        {x + 2, y + 1},
        {x - 1, y - 2},
        {x + 1, y + 2}
    };
}

void astar(shared_ptr<Node> startNode, shared_ptr<Node> endNode, int& result){
    priority_queue<shared_ptr<Node>, vector<shared_ptr<Node>>, cmp> pq;
    unordered_map<string, bool> visited;
    pq.push(startNode);
    while(!pq.empty()){
        shared_ptr<Node> cur = pq.top();
        pq.pop();
        if(cur->x == endNode->x && cur->y == endNode->y){
            while(cur->parent){
                result++;
                cur = cur->parent;
            }
            return;
        }
        if(visited[to_string(cur->x) + "_" + to_string(cur->y)]){
            continue;
        }
        visited[to_string(cur->x) + "_" + to_string(cur->y)] = true;
        vector<pair<int, int>> nextNodes = nextNodeGenerator(cur->x, cur->y);
        for(auto nextNode: nextNodes){
            if(nextNode.first >= 1 && nextNode.first <= BOARD_SIZE && nextNode.second >= 1 && nextNode.second <= BOARD_SIZE){
                double next_g = cur->g + heuristic(cur->x, cur->y, nextNode.first, nextNode.second);
                double next_h = heuristic(nextNode.first, nextNode.second, endNode->x, endNode->y);
                shared_ptr<Node> next = make_shared<Node>(nextNode.first, nextNode.second, next_g, next_h, cur);
                pq.push(next);
            }
        }
    }
    result = -1;
}

int main(){
    int n;
    cin >> n;
    int x1, y1, x2, y2;
    for(int i = 0; i < n; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        shared_ptr<Node> startNode = make_shared<Node>(x1, y1, 0, heuristic(x1, y1, x2, y2));
        shared_ptr<Node> endNode = make_shared<Node>(x2, y2, 0, 0);
        int result = 0;
        astar(startNode, endNode, result);
        cout << result << endl;
    }
    return 0;
}