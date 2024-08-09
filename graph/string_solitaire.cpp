#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <queue>
#include <memory>

using namespace std;

struct Node
{
    string word;
    shared_ptr<Node> parent;
    Node(string word, shared_ptr<Node> parent = nullptr) : word(word), parent(parent) {}
};

bool isStringValid(const string& word1, const string& word2)
{
    int count = 0;
    for (int i = 0; i < word1.size(); i++)
    {
        if (word1[i] != word2[i])
        {
            count++;
            if (count > 1) return false;
        }
    }
    return count == 1;
}

void bfs(const unordered_set<string>& words, const string& startNode, const string& endNode, int& result)
{
    queue<shared_ptr<Node>> que; 
    unordered_set<string> visited; 
    que.push(make_shared<Node>(startNode)); 
    while (!que.empty()) 
    {
        shared_ptr<Node> node = que.front(); 
        que.pop();

        if (node->word == endNode) 
        {
            while (node)
            {
                result++; 
                node = node->parent; 
            }
            return;
        }

        visited.insert(node->word);

        for (const auto& word : words)
        {
            if (isStringValid(word, node->word) && visited.find(word) == visited.end())
            {
                que.push(make_shared<Node>(word, node)); 
            }
        }
    }
}

int main()
{
    int n;
    cin >> n; 
    string startNode, endNode;
    cin >> startNode >> endNode; 
    unordered_set<string> words; 
    string word;

    for (int i = 0; i < n; i++)
    {
        cin >> word;
        words.insert(word); 
    }

    words.insert(startNode);
    words.insert(endNode);

    int result = 0;
    bfs(words, startNode, endNode, result); 
    cout << result << endl;

    return 0;
}
