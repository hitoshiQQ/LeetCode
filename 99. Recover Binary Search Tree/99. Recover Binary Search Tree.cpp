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
 Approach: Morris
 */
class Solution {
public:
    void recoverTree(TreeNode* root) {

        TreeNode* pred = nullptr;
        TreeNode* x = nullptr; // first wrong node
        TreeNode* y = nullptr; // second wrong node

        while (root != nullptr) {

            if (root->left != nullptr) {
                TreeNode* mPred = findPredecessor(root);

                if (mPred->right) {
                    // has node already been connected before
                    visit(root, pred, x, y);
                    mPred->right = nullptr; // break connection
                    root = root->right;

                }
                else {
                    mPred->right = root; // connect
                    root = root->left;
                }

            }
            else {
                visit(root, pred, x, y);
                root = root->right;
            }
        }
        swap(x, y);
    }

private:
    TreeNode* findPredecessor(TreeNode* root) {
        TreeNode* pred = root->left;

        while (pred->right && pred->right != root) {
            pred = pred->right;
        }

        return pred;
    }

    void visit(TreeNode*& root, TreeNode*& pred, TreeNode*& x, TreeNode*& y) {
        if (pred && root->val < pred->val) {
            y = root;

            if (x == nullptr) {
                x = pred;
            }
        }
        pred = root;
    }

    void swap(TreeNode* x, TreeNode* y) {
        const int tmp = x->val;
        x->val = y->val;
        y->val = tmp;
    }
};