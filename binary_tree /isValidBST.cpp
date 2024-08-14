#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

// 定义二叉树节点的结构体
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // 中序遍历函数，将节点值存入 result 向量
    void traversal(TreeNode* cur, vector<int>& result){
        if(cur == nullptr) return;
        traversal(cur->left, result);
        result.push_back(cur->val);
        traversal(cur->right, result);
    }

    // 验证是否为合法的二叉搜索树
    bool isValidBST(TreeNode* root) {
        vector<int> result;
        traversal(root, result);
        
        // 输出中序遍历结果以便调试
        cout << "Inorder traversal result: ";
        for(int val : result) {
            cout << val << " ";
        }
        cout << endl;

        // 检查是否有序
        bool isSorted = is_sorted(result.begin(), result.end(), [](int a, int b){ return a <= b; });

        // 输出排序检查结果以便调试
        cout << "Is sorted: " << (isSorted ? "true" : "false") << endl;

        return isSorted;
    }
};

// 简单的测试用例
int main() {
    // 创建一个简单的二叉树
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);

    Solution sol;
    bool result = sol.isValidBST(root);

    cout << "Is valid BST: " << (result ? "true" : "false") << endl;

    // 释放内存
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
