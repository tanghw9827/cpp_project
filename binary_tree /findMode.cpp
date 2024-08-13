/**
 * Definition for a binary arr node.
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
    void traversal(TreeNode* cur, vector<int>& vec) {
        if (cur == nullptr)
            return;
        traversal(cur->left, vec);
        vec.push_back(cur->val);
        traversal(cur->right, vec);
    }
    vector<int> findMode(TreeNode* root) {
        vector<int> vec;
        traversal(root, vec);
        vector<int> result;
        int maxcount = 0;
        int curcount = 1;
        for (int i = 1; i <= vec.size(); i++) {
            if (i < vec.size() && vec[i] == vec[i - 1]) {
                curcount++;
            } else {
                if (curcount > maxcount) {
                    result.clear();
                    result.push_back(vec[i - 1]);
                    maxcount = curcount;
                } else if (curcount == maxcount) {
                    result.push_back(vec[i - 1]);
                }
                curcount = 1;
            }
        }
        return result;
    }
};