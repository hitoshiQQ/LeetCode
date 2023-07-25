class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        if (nums.size() == 0) {
            return res;
        }
        backTrack(res, nums, 0);
        return res;
    }

    // be sure to copy the nums vector, otherwise the output will be wrong
    void backTrack(vector<vector<int>>& res, vector<int> nums, int start) {

        // base case
        if (start == nums.size()) {
            res.push_back(nums);

        }
        else {
            for (int j = start; j < nums.size(); ++j) {

                // recursive case                
                if (j != start && nums[j] == nums[start]) {
                    continue;
                }
                swap(nums[j], nums[start]);
                backTrack(res, nums, start + 1);
            }
        }
    }
};