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
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> stk;

        long long last = LLONG_MIN;
        TreeNode* cur = root;

        while (!stk.empty() || cur) {
            while (cur) {
                stk.push(cur);
                cur = cur->left;
            }

            cur = stk.top(); stk.pop();

            if (cur->val <= last) return false;
            last = cur->val;

            cur = cur->right;
        }

        return true;
    }
};