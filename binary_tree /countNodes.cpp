/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// 1. 递归法
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root == nullptr) return 0;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};

// 2.迭代法
class Solution {
public:
    int countNodes(TreeNode* root) {
        int result = 0;
        if (root == nullptr) return result;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; i++) {
                TreeNode* cur = que.front();
                que.pop();
                result++;
                if (cur->left)
                    que.push(cur->left);
                if (cur->right)
                    que.push(cur->right);
            }
        }
        return result;
    }
};