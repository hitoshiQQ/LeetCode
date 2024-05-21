class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        return dfs(nums, 0, 0);
    }

private:
    int dfs(const vector<int>& nums, int j, int xors) {
        if (j == nums.size()) {
            return xors;
        }

        const int x = dfs(nums, j + 1, xors);
        const int y = dfs(nums, j + 1, nums[j] ^ xors);
        return x + y;
    }
};