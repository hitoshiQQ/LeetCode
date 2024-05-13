/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        // Loop until the lowest common ancestor is found
        while (true) {

            // If both P and Q are greater than root, then LCA must be in the right subtree
            if (root->val < min(p->val, q->val)) {
                root = root->right;
            }
            else if (root->val > max(p->val, q->val)) {
                // If both P and Q are less than root, then LCA must be on the left subtree
                root = root->left;

            }
            else {
                return root;
            }
        }
    }
};