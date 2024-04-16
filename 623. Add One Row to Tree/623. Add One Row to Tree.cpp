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
private:
    // Variables - Value to be added && depth at which to add the new row
    int _targetValue;
    int _targetDepth;

    // Recursively traverse the tree to find the proper insertion depth
    void dfs(TreeNode* node, int currentDepth) {

        // BASECASE: if the node is null, stop recursion
        if (!node) {
            return;
        }

        // When the target depth is reached, insert new nodes with _targetValue
        if (currentDepth == _targetDepth - 1) {
            // Insert new left/right nodes between the current node and its children
            TreeNode* newLeftNode = new TreeNode(_targetValue, node->left, nullptr);
            TreeNode* newRightNode = new TreeNode(_targetValue, nullptr, node->right);

            // Update the current nodes children to point to the new nodes
            node->left = newLeftNode;
            node->right = newRightNode;

            return;
        }
        // If not at the target depth yet, keep going deeper into the tree
        dfs(node->left, currentDepth + 1);
        dfs(node->right, currentDepth + 1);
    }

public:
    // @brief function to add one row to the tree at a given depth with the given value
    TreeNode* addOneRow(TreeNode* root, int value, int depth) {

        // If the depth is 1 , create a new node with the given value and make the existing tree its right
        if (depth == 1) {
            return new TreeNode(value, root, nullptr);
        }

        // Set class variables to use in recursive calls
        _targetValue = value;
        _targetDepth = depth;

        // Start the DFS
        dfs(root, 1);

        return root;
    }
};