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
    int minDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int res = 0;
        queue<TreeNode*> q {{root}};

        while (!q.empty()) {
            ++res;

            for (int sz = q.size(); sz > 0; --sz) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left == nullptr && node->right == nullptr) {
                    return res;
                }
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
        }
        throw;
    }
};