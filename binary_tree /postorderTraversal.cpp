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

// 1. 递归遍历
class Solution {
public:
    void traversal(TreeNode* cur, vector<int>& result) {
        if (cur == nullptr) {
            return;
        }
        traversal(cur->left, result);
        traversal(cur->right, result);
        result.push_back(cur->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        traversal(root, result);
        return result;
    }
};

// 2. 迭代遍历
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) {
            return result;
        }
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode* cur = st.top();
            st.pop();
            result.push_back(cur->val);
            if (cur->left)
                st.push(cur->left);
            if (cur->right)
                st.push(cur->right);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

// 3. 统一迭代遍历
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
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
                st.push(cur);
                st.push(nullptr);
                if(cur->right) st.push(cur->right);
                if(cur->left) st.push(cur->left);
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

