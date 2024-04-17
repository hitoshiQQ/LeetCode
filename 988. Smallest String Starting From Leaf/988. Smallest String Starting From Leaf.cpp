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
    // Holds the lexicographically smallest string from leaf to root
    string smallestLeafString = "";

    // Entry point to find the smallest string from leaf to root
    string smallestFromLeaf(TreeNode* root) {

        // Represents the current path as a string
        string path = "";

        // Start dfs traversal
        dfs(root, path);

        return smallestLeafString;
    }

    // DFS to traverse the tree
    void dfs(TreeNode* node, string& path) {

        // BASECASE: if the current node is NULL, end the recursion
        if (!node) {
            return;
        }

        // Append the current character represented by the node value to the path
        path += 'a' + node->val;

        // Check if it's a leaf node
        if (!node->left && !node->right) {
            // Create a copy of the current path to reverse it
            string pathReversed = path;
            reverse(pathReversed.begin(), pathReversed.end());

            // Set smallestLeaftString to the pathReversed if it's smaller than the current smallestLeafString or if smallestLeafString is empty
            if (smallestLeafString.empty() || pathReversed < smallestLeafString) {
                smallestLeafString = pathReversed;
            }
        }
        // Continue the DFS traveral for both children
        dfs(node->left, path);
        dfs(node->right, path);

        // BACKTRACK: Remove the last character as we return to the previous node
        path.pop_back();
    }
};