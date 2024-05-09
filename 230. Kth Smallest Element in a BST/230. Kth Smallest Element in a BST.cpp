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

 /**
 * @brief Returns the k-th smallest element in a BST, this is achieved by performing an in-order traversal iteratively,
 *        in-order traversal of a BST yields the nodes in increasing order
 * @param root - Pointer to the root node of the BST
 * @param k - The index (1-indexed) of the smallest element to be found
 * @return The value of the k-th smallest node
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {

        // Init an empty stack that will be used ti perform the in-order traversal
        stack<TreeNode*> stack;

        // Continue tarversing the tree until we have visited all nodes
        while (root || !stack.empty()) {
            // Go left as long as there is a left child
            if (root) {
                // Push the current node onto the stack before moving to left child
                stack.push(root);

                // Move left
                root = root->left;

            }
            else {
                // Process the nodes that don't have a left child anymore
                root = stack.top();

                // Remove the node from the stack
                stack.pop();

                //If have reached the K-th smallestm return it's value
                if (--k == 0) {
                    return root->val;
                }

                // Move to the right child, which will be processed after all its left children
                root = root->right;
            }
        }
        // If we are here, it means the K-th smallest element coludn't be found, ret zero
        // Although in valud BST's with at least K nodes, the func will never reach here
        return 0;
    }
};