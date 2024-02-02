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
    int maxPathSum(TreeNode* root) {

        int res = INT_MIN;
        maxPathSumDown(root, res);
        return res;
    }

private:
    // return max path sum starting from current root
    // root->val always included

    int maxPathSumDown(TreeNode* root, int& res) {
        if (root == nullptr) {
            return 0;
        }

        const int l = max(0, maxPathSumDown(root->left, res));
        const int r = max(0, maxPathSumDown(root->right, res));

        res = max(res, root->val + l + r);
        return root->val + max(l, r);
    }

};