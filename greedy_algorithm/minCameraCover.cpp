#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int traversal(TreeNode *cur, int &result)
{
    // 0 节点无覆盖 1 节点有摄像头 2 节点无覆盖
    if (cur == NULL)
        return 2;
    int left = traversal(cur->left, result); // 左
    int right = traversal(cur->right, result);
    if (left == 2 && right == 2)
        return 0;
    if (left == 0 || right == 0)
    {
        result++;
        return 1;
    }
    if (left == 1 || right == 1)
        return 2;
    return -1;
}

int main()
{
    TreeNode *root = new TreeNode(0);
    root->left = new TreeNode(0);
    root->right = nullptr;
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(0);
    int result = 0;
    if (traversal(root, result) == 0)
    {
        result++;
    }
    cout << result << endl;
    return 0;
}