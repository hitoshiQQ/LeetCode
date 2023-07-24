class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();

        int jumps = 0;
        int cur_end = 0;
        int cur_max_reach = 0;

        // stops at n-2 that's because we don't need to jump 
        // if we have reached n-1

        for (int j = 0; j < n - 1; ++j) {
            cur_max_reach = max(cur_max_reach, j + nums[j]);

            if (j == cur_end) {
                cur_end = cur_max_reach;
                ++jumps;
            }
        }
        return jumps;
    }
};