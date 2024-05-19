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
    // Finds all root-to-leaf paths in the binary tree
    vector<string> binaryTreePaths(TreeNode* root) {
        // Scores all the paths from root to leaf
        vector<string> paths;
        // Tracks nodes of the current path
        vector<string> currentPathNodes;

        // DFS to traverse the tree and build paths
        function<void(TreeNode*)> dfs = [&](TreeNode* node) {
            if (!node) {
                // BASE CASE: if the current node is null, ret
                return;
            }

            // Add the current node value to the path
            currentPathNodes.push_back(to_string(node->val));

            // If the current node is a leaf, join the current path and add to paths
            if (!node->left && !node->right) {
                paths.push_back(join(currentPathNodes));
            }
            else {
                // Recursively call dfs on the non-null children
                dfs(node->left);
                dfs(node->right);
            }
            // Backtracking step: remove the current node value from the path
            currentPathNodes.pop_back();
        };

        // Start DFS from the root node
        dfs(root);
        return paths;
    }

    // Helper func to create a string from vector of strings representing nodes
    string join(const vector<string>& tok, const string& sep = "->") {
        string path;
        for (size_t j = 0; j < tok.size(); ++j) {
            if (j > 0) {
                path += sep;
            }
            path += tok[j];
        }
        return path;
    }
};