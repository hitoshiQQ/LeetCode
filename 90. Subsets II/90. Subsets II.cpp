class Solution {
public:
    void backtrack(vector<vector<int>>& res, vector<int>& subset, vector<int>& nums, int start) {
        res.push_back(subset);
        for (int j = start; j < nums.size(); j++) {

            if (j > start && nums[j] == nums[j - 1]) {
                continue;
            }
            subset.push_back(nums[j]);
            backtrack(res, subset, nums, j + 1);
            subset.pop_back();
        }
    };

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;

        //sorting here is important!
        sort(nums.begin(), nums.end());
        backtrack(res, cur, nums, 0);

        return res;
    }
};