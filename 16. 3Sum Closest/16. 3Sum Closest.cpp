/*
1.Sort && Initialization
2. Find several corresponding numbers
*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int min_diff = INT_MAX;
        int close_sum = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for (int j = 0; j < n - 2; ++j) {
            int i = j + 1, k = n - 1;
            while (i < k) {
                int sum = nums[j] + nums[i] + nums[k];
                if (sum > target) {
                    --k;
                }
                else if (sum < target) {
                    ++i;
                }
                else {
                    return sum;
                }
                int diff = abs(sum - target);
                if (diff < min_diff) {
                    min_diff = diff;
                    close_sum = sum;
                }
            }
        }
        return close_sum;
    }
};