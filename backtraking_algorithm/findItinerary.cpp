class Solution {
public:
    void dfs(unordered_map<string, priority_queue<string, vector<string>, greater<string>>>& graph, const string& startNode, vector<string>& result) {
   
        // 只要当前节点还有未访问的邻居，就不断访问
        while (!graph[startNode].empty()) {
            string nextNode = graph[startNode].top();
            graph[startNode].pop();
            dfs(graph, nextNode, result);
        }
        
        // 当没有未访问的邻居时，当前节点添加到结果中
        result.push_back(startNode);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // 构建图
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> graph;
        for (const auto& ticket : tickets) {
            graph[ticket[0]].push(ticket[1]);
        }
        
        vector<string> result;
        string startNode = "JFK";
        
        // 从起始节点开始进行深度优先搜索
        dfs(graph, startNode, result);
        
        // 因为结果是逆序的，所以需要反转
        reverse(result.begin(), result.end());
        return result;
    }
};
