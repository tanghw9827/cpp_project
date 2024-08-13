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
    void travelsal (TreeNode* cur, vector<int>& result){
        if(cur == nullptr) return;
        if(cur->left) travelsal(cur->left,result);
        result.push_back(cur->val);
        if(cur->right) travelsal(cur->right,result);
    }
    bool isValidBST(TreeNode* root) {
        vector<int> result;
        if(root == nullptr) return false;
        travelsal(root,result);
        if(result.size()==1) return true;
        for(int i = 1;i<result.size();i++){
            if(result[i] <= result[i-1]){
                return false;
            }
        }
        return true;
    }
};