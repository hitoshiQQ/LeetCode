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
    /**
    * @brief Counts the number of nodes in a complete binary tree
    * @param root - The root node of the binary tree
    * @return The total number of nodes in the tree
    */
    int countNodes(TreeNode* root) {

        // Check if the tree is empty
        if (!root) {
            return 0;
        }

        // Calculate the depth of the left and right subtrees
        int leftDepth = calculateDepth(root->left);
        int rightDepth = calculateDepth(root->right);

        // If the depths are equal, it means the left subtree is complete and we can use the formula
        if (leftDepth == rightDepth) {
            return (1 << leftDepth) + countNodes(root->right);
        }

        // If the depth aren't equal, the right subtree must be complete, and we calc the numb
        return (1 << rightDepth) + countNodes(root->left);
    }

    /**
    * @brief Calculates the depth of the tree following the left child
    * @param node - The node to measure the depth from
    * @return - The depth of the subtree
    */
    int calculateDepth(TreeNode* node) {
        int depth = 0;

        while (node) {
            // Move to the left child and increment the depth count
            node = node->left;
            ++depth;
        }
        return depth;
    }
};