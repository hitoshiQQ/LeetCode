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
    int sumNumbers(TreeNode* root) {
        int res = 0;
        depthFirstSearch(root, 0, res);
        return res;
    }

private:
    void depthFirstSearch(TreeNode* root, int path, int& res) {
        if (root == nullptr) {
            return;
        }

        if (root->left == nullptr && root->right == nullptr) {
            res += path * 10 + root->val;
            return;
        }

        depthFirstSearch(root->left, path * 10 + root->val, res);
        depthFirstSearch(root->right, path * 10 + root->val, res);
    }

};