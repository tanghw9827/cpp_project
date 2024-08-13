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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return nullptr;
        
        // 找到了要删除的节点
        if (root->val == key) {
            // 情况1：左右子树都为空
            if (root->left == nullptr && root->right == nullptr) {
                delete root;
                return nullptr;
            }
            // 情况2：左子树为空
            else if (root->left == nullptr) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            // 情况3：右子树为空
            else if (root->right == nullptr) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            // 情况4：左右子树都不为空
            else {
                // 找右子树的最左节点
                TreeNode* cur = root->right;
                while (cur->left != nullptr) {
                    cur = cur->left;
                }
                // 用最左节点的值替换要删除的节点的值
                root->val = cur->val;
                // 删除最左节点
                root->right = deleteNode(root->right, cur->val);
            }
        }
        // 如果key小于当前节点的值，去左子树找
        else if (root->val > key) {
            root->left = deleteNode(root->left, key);
        }
        // 如果key大于当前节点的值，去右子树找
        else {
            root->right = deleteNode(root->right, key);
        }
        return root;
    }
};
