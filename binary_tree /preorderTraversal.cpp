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

// 1. 递归解法
class Solution {
public:
    void traversal(TreeNode* cur, vector<int>& result){
        if(cur == nullptr){
            return;
        }
        result.push_back(cur->val);
        traversal(cur->left, result);
        traversal(cur->right,result);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        traversal(root, result);
        return result;
    }
};

// 2. 迭代法
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root == nullptr){
            return result;
        }
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode* cur = st.top();
            st.pop();
            result.push_back(cur->val);
            if(cur->right) st.push(cur->right);
            if(cur->left) st.push(cur->left);  
        }
        return result;
    }
};

// 3. 统一迭代法
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root == nullptr){
            return result;
        }
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode* cur = st.top();
            if(cur != nullptr){
                st.pop();
                if(cur->right) st.push(cur->right);
                if(cur->left) st.push(cur->left);
                st.push(cur);
                st.push(nullptr);
            } else{
                st.pop();
                cur = st.top();
                st.pop();
                result.push_back(cur->val);
            }
        }
        return result;
    }
};