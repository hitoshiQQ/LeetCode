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
    bool evaluateTree(TreeNode* root) {
        // If the root doesn't have a left child, it must be a leaf node
        if (!root->left) {
            return root->val;
        }

        // Recursively evaluate the left subtree
        bool left_res = evaluateTree(root->left);

        // Recursively evaulate the right subtree
        bool right_res = evaluateTree(root->right);

        // If the root's value is 2, perform an OR operation
        // Otherwise, perform an AND operation
        return root->val == 2 ? (left_res || right_res) : (left_res && right_res);
    }
};