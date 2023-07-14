class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        pair<vector<int>::iterator, vector<int>::iterator> range;

        range = equal_range(nums.begin(), nums.end(), target);
        int target_left = distance(nums.begin(), range.first);

        if (target_left == nums.size() || nums[target_left] != target) {
            return { -1, -1 };
        }

        return { target_left, (int)distance(nums.begin(), range.second) - 1 };
    }
};