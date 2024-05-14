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
    /**
    * @brief Find the lowest common ancestor (LCA) of two given nodes in a binary tree
    * @param root - The root node of the binary tree
    * @param p - The first node for which the LCA is to be found
    * @param q -  The second node for which the LCA is to be found
    * @return The LCA of the two nodes
    */
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        // If root is nullptr || root is one of the nodes, then root itself is the LCA
        if (!root || root == p || root == q) {
            return root;
        }

        // Recursively find the LCA in the left subtree
        TreeNode* leftLCA = lowestCommonAncestor(root->left, p, q);

        // Recursively find the LCA in the right subtree
        TreeNode* rightLCA = lowestCommonAncestor(root->right, p, q);

        // If both the left and right subtrees contain one of the nodes each, then the current root is LCA
        if (leftLCA && rightLCA) {
            return root;
        }
        return leftLCA ? leftLCA : rightLCA;
    }
};