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
    vector<int> rightSideView(TreeNode* root) {

        // Stores the right side view elements
        vector<int> rightView;

        // If the root is null, return empty vector
        if (!root) {
            return rightView;
        }

        // Queue to perform level oreder traversal
        queue<TreeNode*> nodesQueue;
        nodesQueue.push(root);

        while (!nodesQueue.empty()) {

            // Add the rightmost element of current level to the right view
            rightView.emplace_back(nodesQueue.back()->val);

            // Traverse the current  level
            for (int levelSize = nodesQueue.size(); levelSize > 0; --levelSize) {
                TreeNode* currentNode = nodesQueue.front();
                nodesQueue.pop();

                // If left child exsist, add it to the queue for next level
                if (currentNode->left) {
                    nodesQueue.push(currentNode->left);
                }

                // If right child exsist, add it to the queue for next level
                if (currentNode->right) {
                    nodesQueue.push(currentNode->right);
                }
            }
        }
        return rightView;
    }
};