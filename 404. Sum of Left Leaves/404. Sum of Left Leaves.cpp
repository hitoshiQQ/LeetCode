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
    // @brief Depth-First Search - helper function to preform a depth-first search on the binary tree
    // to find sum of left leaves
    int dfs(TreeNode* root, bool isLeft) {

        // BASE CASE: If the current node is NULL, reutrn 0
        if (root == nullptr) {
            return 0;
        }

        // Check if the current node is a leaf node
        if (root->left == nullptr && root->right == nullptr) {
            // if it is a left child, reutrn value : return 0
            return isLeft ? root->val : 0;
        }

        // Recursively sum the values of left leaves from the left and right subtrees
        int leftSum = dfs(root->left, true);
        int rightSum = dfs(root->right, false);

        return leftSum + rightSum;
    }

    // @brief sumOfLeftLeaves - function to calculate the sum of all left leaves in a binary tree
    int sumOfLeftLeaves(TreeNode* root) {

        // Call the depth-first search starting from root
        // Init call isn't a left child. so isLeft is false
        return dfs(root, false);
    }
};