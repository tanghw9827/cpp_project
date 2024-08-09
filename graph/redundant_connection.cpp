#include <iostream>
#include <vector>

using namespace std;

class UnionFind
{
private:
    vector<int> parent;

public:
    UnionFind(int n)
    {
        parent.resize(n + 1);
        for (int i = 1; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int find(int u)
    {
        return u == parent[u] ? u : parent[u] = find(parent[u]);
    }

    bool isSame(int u, int v)
    {
        return find(u) == find(v);
    }

    void join(int u, int v)
    {
        int root_u = find(u);
        int root_v = find(v);
        if (root_u != root_v)
        {
            parent[root_u] = root_v;
        }
    }
};

void removeEdge(vector<pair<int, int>> &edges, int n, pair<int, int> &result)
{
    UnionFind uf(n);
    for (auto edge : edges)
    {
        if (uf.isSame(edge.first, edge.second))
        {
            result = edge;
        }
        else
        {
            uf.join(edge.first, edge.second);
        }
    }
}

bool isTreeAfterRemove(vector<pair<int, int>> &edges, int n, int index)
{
    UnionFind uf(n);
    for (int i = 0; i < n; i++)
    {
        if (i == index)
        {
            continue;
        }
        if (uf.isSame(edges[i].first, edges[i].second))
        {
            return false;
        }
        uf.join(edges[i].first, edges[i].second);
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> edges(n);
    int u, v;
    for (int i = 0; i < n; i++)
    {
        cin >> u >> v;
        edges[i] = {u, v};
    }
    vector<int> inDegree(n + 1, 0);
    for (auto edge : edges)
    {
        inDegree[edge.second]++;
    }
    vector<int> inDegreeTwo;
    for (int i = n - 1; i >= 0; i--)
    {
        if (inDegree[edges[i].second] == 2)
        {
            inDegreeTwo.push_back(i);
        }
    }
    pair<int, int> result;
    if (inDegreeTwo.empty())
    {
        removeEdge(edges, n, result);
    }
    else
    {
        if (isTreeAfterRemove(edges, n, inDegreeTwo[0]))
        {
            result = edges[inDegreeTwo[0]];
        }
        else
        {
            result = edges[inDegreeTwo[1]];
        }
    }
    cout << result.first << " " << result.second << endl;
    return 0;
}
