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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        TreeNode* cur = root;

        while (cur || !stk.empty()) {
            //if cur is nullptr, it's ok, because it will later be stk.top()

            while (cur) {
                stk.push(cur);
                cur = cur->left;
            }
            cur = stk.top(); stk.pop();
            res.push_back(cur->val);

            //it's fine if cur->right is nullptr
            cur = cur->right;
        }

        return res;
    }
};
