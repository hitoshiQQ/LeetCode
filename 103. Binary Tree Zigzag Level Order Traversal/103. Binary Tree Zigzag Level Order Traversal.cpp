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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == NULL) {
            return vector<vector<int>>();
        }

        vector<vector<int>> res;

        queue<TreeNode*> nodesQueue;
        nodesQueue.push(root);
        bool leftToRight = true;

        while (!nodesQueue.empty()) {
            int size = nodesQueue.size();
            vector<int> row(size);

            for (int j = 0; j < size; ++j) {

                TreeNode* node = nodesQueue.front();
                nodesQueue.pop();

                int index = (leftToRight) ? j : (size - 1 - j);

                row[index] = node->val;
                if (node->left) {
                    nodesQueue.push(node->left);
                }

                if (node->right) {
                    nodesQueue.push(node->right);
                }
            }

            leftToRight = !leftToRight;
            res.push_back(row);
        }

        return res;
    }
};