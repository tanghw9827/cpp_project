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
class Solution {
public:
    void traversal(TreeNode* cur, string path, vector<string>& result){
        path += to_string(cur->val);
        if(!cur->left && !cur->right){
            result.push_back(path);
            return;
        }
        if (cur->left) traversal(cur->left, path + "->", result);
        if (cur->right) traversal(cur->right, path + "->", result);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        string path;
        if(root == nullptr){
            return result;
        }
        traversal(root, path, result);
        return result;

    }
};