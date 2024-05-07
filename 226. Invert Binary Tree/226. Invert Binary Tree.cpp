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
    TreeNode* invertTree(TreeNode* root) {
        // Lambda func to recursively traverse the tree in a depth-first manner and invert it
        function<void(TreeNode*)> dfs = [&](TreeNode* node) {
            // If the node is nullm ret immediately as there is nothing to invert
            if (!node) {
                return;
            }

            // Swap the left and right children of the current node
            swap(node->left, node->right);

            // Invert the left subtree
            dfs(node->left);

            // Invert the right subtree
            dfs(node->right);
        };

        // Start dfs from the root to invert the entrie tree
        dfs(root);

        return root;
    }
};