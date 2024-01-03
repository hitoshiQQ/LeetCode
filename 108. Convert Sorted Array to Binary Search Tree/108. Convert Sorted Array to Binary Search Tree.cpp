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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return func(nums, 0, nums.size() - 1);
    }

private:
    TreeNode* func(const vector<int>& nums, int l, int r) {
        if (l > r) {
            return nullptr;
        }

        const int m = (l + r) / 2;
        return new TreeNode(nums[m], func(nums, l, m - 1), func(nums, m + 1, r));
    }

};