#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <memory>

using namespace std;

struct Point2D {
    int x;
    int y;

    Point2D(int x = 0, int y = 0) : x(x), y(y) {}

    bool operator==(const Point2D& other) const {
        return x == other.x && y == other.y;
    }
};

struct GridMap {
    vector<vector<int>> grid_map;
    int width;
    int height;
    float resolution;
    float origin_x;
    float origin_y;

    GridMap(float map_width, float map_height, float res, float origin_x, float origin_y)
        : resolution(res), origin_x(origin_x), origin_y(origin_y) {
        width = static_cast<int>(map_width / resolution);
        height = static_cast<int>(map_height / resolution);
        grid_map = vector<vector<int>>(height, vector<int>(width, 0));
    }

    bool isValid(int x, int y) const {
        return x >= 0 && x < width && y >= 0 && y < height && grid_map[y][x] == 0;
    }
};

struct Node {
    Point2D point;
    float g;  // cost from start node
    float h;  // heuristic to end node
    float f;  // total cost
    Node* parent;

    Node(Point2D pt, float g_cost, float h_cost, Node* parent = nullptr)
        : point(pt), g(g_cost), h(h_cost), f(g_cost + h_cost), parent(parent) {}
};

struct CompareNode {
    bool operator()(Node* n1, Node* n2) {
        return n1->f > n2->f;
    }
};

float heuristic(const Point2D& a, const Point2D& b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

vector<Point2D> reconstructPath(Node* node) {
    vector<Point2D> path;
    while (node) {
        path.push_back(node->point);
        node = node->parent;
    }
    reverse(path.begin(), path.end());
    return path;
}

vector<Point2D> AStar(const GridMap& gridmap, Point2D start_pt, Point2D end_pt) {
    priority_queue<Node*, vector<Node*>, CompareNode> openSet;
    vector<vector<bool>> closedSet(gridmap.height, vector<bool>(gridmap.width, false));

    Node* startNode = new Node(start_pt, 0, heuristic(start_pt, end_pt));
    openSet.push(startNode);

    const vector<Point2D> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    while (!openSet.empty()) {
        Node* current = openSet.top();
        openSet.pop();

        if (current->point == end_pt) {
            return reconstructPath(current);
        }

        closedSet[current->point.y][current->point.x] = true;

        for (const auto& dir : directions) {
            Point2D neighbor(current->point.x + dir.x, current->point.y + dir.y);
            if (gridmap.isValid(neighbor.x, neighbor.y) && !closedSet[neighbor.y][neighbor.x]) {
                float tentative_g = current->g + 1;
                Node* neighborNode = new Node(neighbor, tentative_g, heuristic(neighbor, end_pt), current);
                openSet.push(neighborNode);
            }
        }
    }
    return {};  
}

int main() {
    float map_width, map_height, resolution;
    cin >> map_width >> map_height >> resolution;

    float origin_x = 0.0f, origin_y = 0.0f;
    GridMap gridmap(map_width, map_height, resolution, origin_x, origin_y);

    for (int i = 0; i < gridmap.height; ++i) {
        for (int j = 0; j < gridmap.width; ++j) {
            cin >> gridmap.grid_map[i][j];
        }
    }

    Point2D start_pt, end_pt;
    cin >> start_pt.x >> start_pt.y >> end_pt.x >> end_pt.y;

    vector<Point2D> path = AStar(gridmap, start_pt, end_pt);

    if (path.empty()) {
        cout << "No path found" << endl;
    } else {
        for (const auto& pt : path) {
            cout << "(" << pt.x << ", " << pt.y << ")" << endl;
        }
    }
    return 0;
}