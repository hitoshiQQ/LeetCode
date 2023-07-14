class Solution {
public:
    // we are not going to change the array, we can take a constant reference
    // linear solution
    size_t searchInsert(const vector<int>& nums, int target) {
        size_t j = 0;
        while (j < nums.size() && nums[j] < target) {
            ++j;
        }
        return j;
    }
};