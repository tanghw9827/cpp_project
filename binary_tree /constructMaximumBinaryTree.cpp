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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.size()==0) return nullptr;
        auto iter = max_element(nums.begin(),nums.end());
        TreeNode* root = new TreeNode(*iter);
        vector<int> leftvec(nums.begin(),iter);
        vector<int> rightvec(iter+1,nums.end());
        root->left = constructMaximumBinaryTree(leftvec);
        root->right = constructMaximumBinaryTree(rightvec);
        return root;
    }
};