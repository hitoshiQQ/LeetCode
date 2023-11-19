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

 // Recursion && Memorization
class Solution {
public:
    vector<vector<vector<TreeNode*>>> memo;

    void generateTrees(int start, int end) {
        // cout << start << " - " << end << endl;

        if (!memo[start][end].empty()) {
            return;
        }

        if (start > end) {
            memo[start][end] = { nullptr };
            return;
        }

        vector<TreeNode*> trees;
        for (int j = start; j <= end; ++j) {
            generateTrees(start, j - 1);
            vector<TreeNode*>& ltree = memo[start][j - 1];

            generateTrees(j + 1, end);
            vector<TreeNode*>& rtree = memo[j + 1][end];

            // cout << "left: " << ltrees.size() << endl;
            // cout << "right: " << rtrees.size() << endl;

            for (int i = 0; i < ltree.size(); ++i) {
                for (int q = 0; q < rtree.size(); ++q) {
                    TreeNode* root = new TreeNode(j);
                    root->left = ltree[i];
                    root->right = rtree[q];
                    trees.push_back(root);
                }
            }
        }
        if (trees.empty()) trees.push_back(nullptr);
        memo[start][end] = trees;
    }

    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        //[1,n] x [1,n] is valid range
        //but 0 and n+1 are also used for convenience

        memo = vector<vector<vector<TreeNode*>>>(n + 2,
            vector<vector<TreeNode*>>(n + 2));
        generateTrees(1, n);
        return memo[1][n];
    }
};