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
    void findBottomLeftValueByDFS(TreeNode* root, int depth, int& res, int& height) {
        if (root == NULL) {
            return;
        }

        if (height < depth) {
            height = depth;
            res = root->val;
        }

        findBottomLeftValueByDFS(root->left, depth + 1, res, height);
        findBottomLeftValueByDFS(root->right, depth + 1, res, height);
    }
    int findBottomLeftValue(TreeNode* root) {
        int res, height = -1;
        findBottomLeftValueByDFS(root, 0, res, height);
        return res;
    }
};