#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 定义二叉树节点
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* createTree(const vector<int>& nodes, int& index) {
    if (index >= nodes.size() || nodes[index] == -1) {
        index++;
        return nullptr;
    }
    
    TreeNode* root = new TreeNode(nodes[index++]);
    root->left = createTree(nodes, index);
    root->right = createTree(nodes, index);
    return root;
}

vector<int> robTree(TreeNode* root){
    if(root == nullptr) return {0, 0};
    vector<int> left = robTree(root->left);
    vector<int> right = robTree(root->right);
    int value0 = max(left[0], left[1]) + max(right[0], right[1]);
    int value1 = root->val + left[0] + right[0];
    return {value0, value1};
}

int rob(TreeNode* root) {
    vector<int> result = robTree(root);
    return max(result[0], result[1]);
}

int main()
{
    vector<int> nums = {3, 2, 3, -1, 3, -1, 1};
    int start = 0;
    TreeNode* root = createTree(nums, start);
    int result = rob(root);
    cout << result << endl;
    return 0;
}