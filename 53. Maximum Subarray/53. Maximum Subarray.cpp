// Dynamic Programming - Kadane's Algorithm
// For each position count max sum, if this position is the last for the interval
class Solution {
public:
    int maxSubArray(const vector<int>& nums) {
        int current_max = nums[0];
        int all_max = nums[0];

        for (int j = 1; j < nums.size(); ++j) {
            current_max = max(current_max + nums[j], nums[j]);
            all_max = max(all_max, current_max);
        }
        return all_max;
    }
};