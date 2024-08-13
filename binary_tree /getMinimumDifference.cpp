/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void traversal(TreeNode* cur, vector<int>& result){
        if(cur == nullptr) return;
        traversal(cur->left,result);
        result.push_back(cur->val);
        traversal(cur->right,result);
    }
    int getMinimumDifference(TreeNode* root) {
        vector<int> result;
        traversal(root,result);
        int res = INT_MAX;
        for(int i=1;i<result.size();i++){
            res = res>abs(result[i]-result[i-1])?abs(result[i]-result[i-1]):res;
        }
        return res;
    }
};