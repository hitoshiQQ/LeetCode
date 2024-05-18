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
    int distributeCoins(TreeNode* root) {
        // This will store the total number of moves needed to balance the coins 
        int total_moves = 0;

        // DFS func computes the number of moves required starting from the leaves up to the root of the tree
        // It returns the excess number of coins that need to be moved from the current node
        function<int(TreeNode*)> dfs = [&](TreeNode* node) -> int {
            // BASE CASE: if the cirrent node is null, ret zero since threre are no coins to move
            if (!node) {
                return 0;
            }

            // Recursive case: solve for left and right subtree
            int left_moves = dfs(node->left);
            int right_moves = dfs(node->right);

            // The number of moves made at the current node is the sum of absolute values of each subtree excess coins
            // Because moves from both left and right need to pass through the current node
            total_moves += abs(left_moves) + abs(right_moves);

            return left_moves + right_moves + node->val - 1;
        };

        // Call the dfs func starting from the root of the tree
        dfs(root);

        return total_moves;
    }
};