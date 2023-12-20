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
    TreeNode* buildTree(vector<int>& P, vector<int>& I) {
        unordered_map<int, int> M;
        for (int j = 0; j < I.size(); j++)
            M[I[j]] = j;
        return splitTree(P, M, 0, 0, I.size() - 1);
    }

private:
    TreeNode* splitTree(vector<int>& P, unordered_map<int, int>& M, int pix, int ileft, int iright) {
        int rval = P[pix], imid = M[rval];
        TreeNode* root = new TreeNode(rval);

        if (imid > ileft) {
            root->left = splitTree(P, M, pix + 1, ileft, imid - 1);
        }
        if (imid < iright) {
            root->right = splitTree(P, M, pix + imid - ileft + 1, imid + 1, iright);
        }

        return root;
    }
};